#include "common.h"
#include <cuda_runtime.h>
#include <stdio.h>

void initialDataTriple(double *ip,double *ip2,double *ip3, unsigned long long int size){
    for(unsigned long long int i = 0; i < size; i++){
        ip3[i] = ip2[i] = ip[i] = (double)i;
        //ip3[i] = ip2[i] = ip[i] = (float)(rand() & 0xFF ) / 10.0f;
    }
    return;
}

void checkResult(double *hostRef, double *gpuRef, unsigned long long int N){
    double epsilon = 1.0E-8;
    bool match = 1;
    for (unsigned long long int i = 0; i < N; i++){
        if (abs(hostRef[i] - gpuRef[i]) > epsilon){
            match = 0;
            printf("host %f gpu %f index %llu\n", hostRef[i], gpuRef[i],i);
            break;
        }
    }
    if (match)
        printf("Arrays match.\n\n");
    else
        printf("Arrays do not match.\n\n");
}

void jacobiOnHost(int iter_max, double *matriz, double* host_ref, int dim_x, int dim_y){
    double *ia = matriz;
    double *Anew = host_ref;
    for (int k = 0; k < iter_max; ++k) {
        ia = matriz + dim_y;
        Anew = host_ref + dim_y;
         for( int i = 1; i < dim_x-1; i++) {
            for(int j = 1; j < dim_y-1; j++) {
              Anew[j] = 0.25 * (ia[j+1] + ia[j-1] + ia[j-dim_y] + ia[j+dim_y]);
            }
            ia += dim_y;
            Anew += dim_y;
        }
        ia = matriz;
        Anew = host_ref;
        for(int i = 0; i < (dim_x * dim_y); i++)
            ia[i] = Anew[i];
    }
    return;
}

// void jacobiOnHost(int num_interacao, double *matrizA, double *matrizB, int num_linhas, int num_colunas){
//   for(int k = 0; k < num_interacao; k++){
//       for(int j = 1; j < (num_colunas-1); j++){
//         for(int i = 1; i < (num_linhas-1); i++){
//           matrizA[i * num_colunas + j] = 0.25f * (matrizB[(i-1) * num_colunas + j] + matrizB[(i+1) * num_colunas + j] + matrizB[ i * num_colunas + (j-1)] + 
//             matrizB[ i * num_colunas + (j+1)]);
//         }
//       }
//       double* trocaMatriz = matrizB;
//       matrizB = matrizA;
//       matrizA = trocaMatriz;
//   }
// }

// grid 2D block 2D
__global__ void jacobiOnGpuNaive2D(double *MatA, double *d_MatC, int dim_x, int dim_y,int iter_max){
        unsigned long long int i = blockDim.x * blockIdx.x + threadIdx.x; 
        unsigned long long int j = blockDim.y * blockIdx.y + threadIdx.y; 
        unsigned long long int iPrev = i-1; 
        unsigned long long int iNext = i+1; 
        unsigned long long int jPrev = j-1; 
        unsigned long long int jNext = j+1; 
        unsigned long long int index = i * dim_y + j;
        for (int k = 0; k < iter_max; k++){
        if( i > 0 && j > 0 && i < (dim_x-1) && j <(dim_y-1))
            d_MatC[index] = 0.25f * (MatA[iPrev * dim_y + j] + MatA[iNext* dim_y + j] + MatA[i * dim_y+ jPrev] + MatA[i* dim_y + jNext]);
       __syncthreads();
       if(index<dim_x*dim_y) MatA[index] = d_MatC[index];
    }   
}

int main(int argc, char **argv){
    printf("%s Starting...\n", argv[0]);
    // set up data size of matrix
    int iter_max = 20;
    int nx = 5700;
    int ny = 5700;
    int threadsBlocoX = 32; // x*y <= 1024
    int threadsBlocoY = 32;

    if (argc > 1) ny = nx = atoi(argv[1]);
    if (argc > 2) threadsBlocoX = atoi(argv[2]);
    if (argc > 3) threadsBlocoY = atoi(argv[3]);
    
    unsigned long long int nxy = nx * ny;
    unsigned long long int nBytes = nxy * sizeof(double);
    printf("Matrix size: nx %d ny %d total size %llu\n", nx, ny, nxy);

    // malloc host memory
    double *h_Matriz,*hostRef, *gpuRef;
    h_Matriz = (double*)malloc(nBytes);
    hostRef = (double *)malloc(nBytes);
    gpuRef = (double *)malloc(nBytes);

    // initialize data at host side
    double iStart = seconds();
    initialDataTriple(h_Matriz,hostRef,gpuRef, nxy);
    double iElaps = seconds() - iStart;
    printf("initialize matrix elapsed %f sec\n", iElaps);

    // Jacobi at host side for result checks
    iStart = seconds();
    jacobiOnHost(iter_max, h_Matriz, hostRef, ny, nx);
    iElaps = seconds() - iStart;
    printf("jacobiOnHost elapsed %f sec\n", iElaps);
    
    // malloc device global memory
    double *d_MatA, *d_MatC;
    CHECK(cudaMalloc((void **)&d_MatA, nBytes));
    CHECK(cudaMalloc((void **)&d_MatC, nBytes));

    // transfer data from host to device
    CHECK(cudaMemcpy(d_MatA, gpuRef, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaMemcpy(d_MatC, gpuRef, nBytes, cudaMemcpyHostToDevice));

    // invoke kernel at host side 2D-2D
    dim3 dimBlock(threadsBlocoX, threadsBlocoY);
    dim3 dimGrid(nx/dimBlock.x,ny/dimBlock.y);

    iStart = seconds();
    jacobiOnGpuNaive2D<<<dimGrid, dimBlock>>>(d_MatA, d_MatC, nx, ny,iter_max);
    CHECK(cudaDeviceSynchronize());
    iElaps = seconds() - iStart;
    printf("sumMatrixOnGPU2D <<<(%d,%d), (%d,%d)>>> elapsed %f sec\n", dimGrid.x,dimGrid.y,dimBlock.x, dimBlock.y, iElaps);

    // check kernel error
    CHECK(cudaGetLastError());

    // copy kernel result back to host side
    CHECK(cudaMemcpy(gpuRef, d_MatC, nBytes, cudaMemcpyDeviceToHost));
    
    // check device results
    checkResult(hostRef, gpuRef, nxy);

    // free device global memory
    CHECK(cudaFree(d_MatA));
    CHECK(cudaFree(d_MatC));

    // free host memory
    free(h_Matriz);
    free(hostRef);
    free(gpuRef);

    // reset device
    CHECK(cudaDeviceReset());
    return (0);
}