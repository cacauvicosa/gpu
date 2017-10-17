#include "common.h"
#include <cuda_runtime.h>
#include <stdio.h>

/*
 * This example demonstrates a simple vector sum on the GPU and on the host.
 * sumArraysOnGPU splits the work of the vector sum across CUDA threads on the
 * GPU. A 1D thread block and 1D grid are used. sumArraysOnHost sequentially
 * iterates through vector elements on the host.
 */

void initialDataSingle(float *ip, const int size){
    int i;
    for(i = 0; i < size; i++){
        //ip[i] = i;
	ip[i] = (float)(rand() & 0xFF ) / 10.0f;
    }
    return;
}
void initialDataDouble(float *ip,float *ip2, const int size){
    int i;
    for(i = 0; i < size; i++){
        //ip[i] = i;
	ip2[i] = ip[i] = (float)(rand() & 0xFF ) / 10.0f;
    }
    return;
}
void initialDataTriple(float *ip,float *ip2,float *ip3, const int size){
    for(int i = 0; i < size; i++){
        //ip[i] = i;
	ip3[i] = ip2[i] = ip[i] = (float)(rand() & 0xFF ) / 10.0f;
    }
    return;
}

void initialDataEdge(float *ip,float *ip2,float *ip3, int nx, int ny){
    memset(ip,  0, nx * ny * sizeof(float));
	memset(ip2, 0, nx * ny * sizeof(float));
	memset(ip3, 0, nx * ny * sizeof(float));
	for(int i = 0; i < (nx * ny); i++){
		if(i < nx || i > (nx*ny-nx))
	        ip3[i] = ip2[i] = ip[i] = (float)(rand() & 0xFF ) / 10.0f;
		else if(i% nx == 0){
		    ip3[i] = ip2[i] = ip[i] = (float)(rand() & 0xFF ) / 10.0f;
			ip3[i+nx-1] = ip2[i+nx-1] = ip[i+nx-1] = (float)(rand() & 0xFF ) / 10.0f;
		}
    }
    return;
}
void imprime(float *ip, const int size, int nx){
    int i;
    for(i = 0; i < size; i++){
	if(i%nx==0)
	    printf("\n");
        printf("%.4f\t",ip[i]);
    }
    printf("\n");
    return;
}
void jacobiOnHost(int iter_max, float *matriz, float* host_ref, int dim_x, int dim_y){
    int iter = 0;
    float *ia = matriz;
    float *Anew = host_ref;
    
    for (int k = 0; k < iter_max; ++k) {
	ia = matriz + dim_y;
    	Anew = host_ref + dim_y;
         for( int i = 1; i < dim_x-1; i++) {
            for(int j = 1; j < dim_y-1; j++) {	
		printf("%.4f, %.4f, %.4f, %.4f\n",ia[j+1], ia[j-1], ia[j-dim_y], ia[j+dim_y]);
		Anew[j] = 0.25 * (ia[j+1] + ia[j-1] + ia[j-dim_y] + ia[j+dim_y]);
	    }
	    ia += dim_y;
            Anew += dim_y;
        }
	ia = matriz;
    	Anew = host_ref;
	for(int i = 0; i < (dim_x * dim_y); i++){
            ia[i] = Anew[i];
    	}
        iter++;
    }
	return;
}

// grid 1D block 1D

__global__ void jacobiOnGpuNaive(int iter_max, float *MatA, float *MatC, int dim_x, int dim_y){
    //unsigned int ix = threadIdx.x + blockIdx.x * blockDim.x;
    int iter = 0;
    float *ia = MatA;
    float *Anew = MatC; 
    for (int k = 0; k < iter_max; ++k) {
	ia = MatA + dim_y;
    	Anew = MatC + dim_y;
         for( int i = 1; i < dim_x-1; i++) {
            for(int j = 1; j < dim_y-1; j++) {	
		printf("%.4f, %.4f, %.4f, %.4f\n",ia[j+1], ia[j-1], ia[j-dim_y], ia[j+dim_y]);
		Anew[j] = 0.25 * (ia[j+1] + ia[j-1] + ia[j-dim_y] + ia[j+dim_y]);
	    }
	    ia += dim_y;
            Anew += dim_y;
        }
	ia = MatA;
    	Anew = MatC;
	for(int i = 0; i < (dim_x * dim_y); i++){
            ia[i] = Anew[i];
    	}
        iter++;
    }
}

void checkResult(float *hostRef, float *gpuRef, const int N){
    double epsilon = 1.0E-8;
    bool match = 1;

    for (int i = 0; i < N; i++){
        if (abs(hostRef[i] - gpuRef[i]) > epsilon){
            match = 0;
            printf("host %f gpu %f\n", hostRef[i], gpuRef[i]);
            break;
        }
    }

    if (match)
        printf("Arrays match.\n\n");
    else
        printf("Arrays do not match.\n\n");
}

int main(int argc, char **argv)
{
    printf("%s Starting...\n", argv[0]);

    // set up device
    int dev = 0;
    cudaDeviceProp deviceProp;
    CHECK(cudaGetDeviceProperties(&deviceProp, dev));
    printf("Using Device %d: %s\n", dev, deviceProp.name);
    CHECK(cudaSetDevice(dev));

    // set up data size of matrix
    int iter_max =1;
    int nx = 3;//1 << 14;
    int ny = 5;//1 << 14;

    int nxy = nx * ny;
    int nBytes = nxy * sizeof(float);
    printf("Matrix size: nx %d ny %d\n", nx, ny);

    // malloc host memory
    float *h_Matriz,*hostRef, *gpuRef;
    h_Matriz = (float*)malloc(nBytes);
    hostRef = (float *)malloc(nBytes);
    gpuRef = (float *)malloc(nBytes);

    // initialize data at host side
    double iStart = seconds();
    //initialDataEdge(h_Matriz,hostRef,gpuRef, nx, ny);
	//imprime(h_Matriz, nxy,nx);
	initialDataTriple(h_Matriz,hostRef,gpuRef, nxy);
    double iElaps = seconds() - iStart;
    printf("initialize matrix elapsed %f sec\n", iElaps);
    //imprime(h_Matriz, nxy,nx);

    // Jacobi at host side for result checks
    iStart = seconds();
    jacobiOnHost(iter_max, h_Matriz, hostRef, ny, nx);
    iElaps = seconds() - iStart;
    printf("jacobiOnHost elapsed %f sec\n", iElaps);
    imprime(hostRef, nxy,nx);
    
    // malloc device global memory
    float *d_MatA, *d_MatC;
    CHECK(cudaMalloc((void **)&d_MatA, nBytes));
    CHECK(cudaMalloc((void **)&d_MatC, nBytes));

    // transfer data from host to device
    CHECK(cudaMemcpy(d_MatA, gpuRef, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaMemcpy(d_MatC, gpuRef, nBytes, cudaMemcpyHostToDevice));

    // invoke kernel at host side
    int dimx = 32;//32
    dim3 block(dimx, 1);
    dim3 grid((nx + block.x - 1) / block.x, 1);

    iStart = seconds();
    jacobiOnGpuNaive<<<grid, block>>>(iter_max, d_MatA, d_MatC, nx, ny);
    CHECK(cudaDeviceSynchronize());
    iElaps = seconds() - iStart;
    printf("sumMatrixOnGPU1D <<<(%d,%d), (%d,%d)>>> elapsed %f sec\n", grid.x,
           grid.y,
           block.x, block.y, iElaps);

    // check kernel error
    CHECK(cudaGetLastError());

    // copy kernel result back to host side
    CHECK(cudaMemcpy(gpuRef, d_MatC, nBytes, cudaMemcpyDeviceToHost));
    imprime(gpuRef, nxy,nx);
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
