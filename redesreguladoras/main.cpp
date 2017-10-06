#include <iostream>
#include <string.h>
#include <string>
#define debug 1
using namespace std;
int main() {
    int result[96],sum = 0;
    int equation[96][10];
    int value[96]={1, 1, -1, 0, -1, 0, 1, 1, -1, 1, 1, 0, 0, 0, 1, 1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, 1, 1, -1, 0, 0, -1, 1, 0, -1, 1, -1, -1, 1, -1, 0, 0, 1, -1, 0, 0, 1, -1, 1, 1, 1, 0, -1, -1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, -1, -1, 1, 0, 1, 0, -1, -1, -1, 1, -1, -1, -1, 1, 1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 0};
    string vet[96]={"thetaMutagen", "thetaGFs", "thetaNutrients", "thetaTNFAlpha", "thetaHypoxia", "thetaGli", "thetaMax", "thetaPTEN", "thetaTGFBeta", "thetaDnaDamage", "thetap53_Mdm2", "thetaAMP_ATP", "thetaNF1", "thetaPKC", "thetaRTK", "thetaRAGS", "thetaRas", "thetaPI3K", "thetaPIP3", "thetaPDK1", "thetaIKK", "thetaNF_KappaB", "thetaRAF", "thetaERK", "thetap90", "thetaAKT", "thetaWNT", "thetaDsh", "thetaAPC", "thetaGSK3", "thetaGSK3_APC", "thetaBeta_cat", "thetaSlug", "thetamTOR", "thetaHIF1", "thetaCOX412", "thetaVHL", "thetaPHDs", "thetaMyc_Max", "thetaMyc", "thetaMXI1", "thetaTSC1_TSC2", "thetaRHEB", "thetap53", "thetaBcl2", "thetaBAX", "thetaBAD", "thetaBcl_XL", "thetaRb", "thetaE2F", "thetap14", "thetaCycA", "thetaCycB", "thetaCycD", "thetaCycE", "thetacdh1", "thetacdc20", "thetaUbcH10", "thetap27", "thetap21", "thetaMdm2", "thetaSmad", "thetaSmadMiz1", "thetaSmadE2F", "thetap15", "thetaFADD", "thetaCaspase8", "thetaBak", "thetaJNK", "thetaFOXO", "thetaFosJun", "thetaROS", "thetaAMPK", "thetaCytoc_APAF1", "thetaCaspase9", "thetaApoptosis", "thetaE_cadh", "thetaGlut1", "thetahTERT", "thetaVEGF", "thetaE2F_CyclinE", "thetacdh1_UbcH10", "thetaTAK1", "thetaGSH", "thetaTCF", "thetaMiz1", "thetap70", "thetaATM_ATR", "thetaCHK1_2", "thetaDNARepair", "thetaeEF2K", "thetaeEF2", "thetap53_PTEN", "thetaLDHA", "thetaAcidLactic", "thetaSnail"};

    for (int i = 0; i < 96; ++i) {//flag
        for (int j = 0; j < 10; ++j) {
            equation[i][j]=1000;
        }
    }

    equation[0][0]=100;
    equation[1][0]=100;
    equation[2][0]=-100;
    equation[3][0]=0;
    equation[4][0]=-100;
    equation[5][0]=0;
    equation[6][0]=100;
    equation[7][0]=100;
    equation[8][0]=34;
    equation[9][0]=0;
    equation[9][1]=71;
    equation[10][0]=43;
    equation[10][1]=60;
    equation[10][2]=-100;
    equation[11][0]=-2;
    equation[11][1]=100;
    equation[12][0]=-13;
    equation[12][1]=100;
    equation[13][0]=14;
    equation[13][1]=26;
    equation[14][0]=1;
    equation[15][0]=2;
    equation[15][1]=-4;
    equation[16][0]=-12;
    equation[16][1]=14;
    equation[16][2]=100;
    equation[17][0]=16;
    equation[17][1]=78;
    equation[18][0]=17;
    equation[18][1]=-7;
    equation[18][2]=-92;
    equation[18][3]=100;
    equation[19][0]=18;
    equation[19][1]=34;
    equation[19][2]=38;
    equation[20][0]=13;
    equation[20][1]=25;
    equation[20][2]=33;
    equation[20][3]=-37;
    equation[20][4]=-43;
    equation[20][5]=82;
    equation[21][0]=18;
    equation[21][1]=20;
    equation[21][2]=20;
    equation[21][3]=-76;
    equation[21][4]=95;
    equation[21][5]=-100;
    equation[22][0]=13;
    equation[22][1]=16;
    equation[23][0]=22;
    equation[24][0]=19;
    equation[24][1]=23;
    equation[25][0]=18;
    equation[25][1]=19;
    equation[25][2]=-100;
    equation[26][0]=-43;
    equation[26][1]=5;
    equation[27][0]=26;
    equation[28][0]=7;
    equation[28][1]=100;
    equation[29][0]=-24;
    equation[29][1]=-25;
    equation[29][2]=-27;
    equation[29][3]=-33;
    equation[29][4]=300;
    equation[30][0]=28;
    equation[30][1]=29;
    equation[30][2]=-100;
    equation[31][0]=-30;
    equation[31][1]=-43;
    equation[31][2]=100;
    equation[32][0]=-10;
    equation[32][1]=21;
    equation[32][2]=84;
    equation[33][0]=15;
    equation[33][1]=25;
    equation[33][2]=42;
    equation[33][3]=-72;
    equation[33][4]=-100;
    equation[34][0]=4;
    equation[34][1]=33;
    equation[34][2]=-36;
    equation[34][3]=-36;
    equation[34][4]=-37;
    equation[34][5]=38;
    equation[34][6]=-43;
    equation[34][7]=-69;
    equation[34][8]=200;
    equation[35][0]=34;
    equation[36][0]=-4;
    equation[36][1]=-71;
    equation[36][2]=100;
    equation[37][0]=-4;
    equation[37][1]=71;
    equation[37][2]=100;
    equation[38][0]=-8;
    equation[38][1]=39;
    equation[38][2]=6;
    equation[38][3]=-40;
    equation[38][4]=-63;
    equation[38][5]=-100;
    equation[39][0]=21;
    equation[39][1]=23;
    equation[39][2]=-34;
    equation[39][3]=49;
    equation[39][4]=70;
    equation[39][5]=84;
    equation[39][6]=5;
    equation[39][7]=-100;
    equation[40][0]=34;
    equation[41][0]=-22;
    equation[41][1]=-23;
    equation[41][2]=-24;
    equation[41][3]=-25;
    equation[41][4]=34;
    equation[41][5]=43;
    equation[41][6]=72;
    equation[41][7]=100;
    equation[42][0]=-41;
    equation[42][1]=100;
    equation[43][0]=34;
    equation[43][1]=-44;
    equation[43][2]=-60;
    equation[43][3]=88;
    equation[43][4]=100;
    equation[44][0]=21;
    equation[44][1]=21;
    equation[44][2]=-43;
    equation[44][3]=-45;
    equation[44][4]=-46;
    equation[45][0]=-34;
    equation[45][1]=43;
    equation[45][2]=-44;
    equation[45][3]=68;
    equation[46][0]=-22;
    equation[46][1]=-24;
    equation[46][2]=-25;
    equation[46][3]=-34;
    equation[46][4]=100;
    equation[47][0]=-43;
    equation[47][1]=-46;
    equation[47][2]=100;
    equation[48][0]=-51;
    equation[48][1]=-52;
    equation[48][2]=-53;
    equation[48][3]=-54;
    equation[48][4]=-60;
    equation[48][5]=200;
    equation[49][0]=-48;
    equation[49][1]=-48;
    equation[49][2]=-51;
    equation[49][3]=-52;
    equation[49][4]=49;
    equation[49][5]=100;
    equation[50][0]=16;
    equation[50][1]=38;
    equation[50][2]=49;
    equation[50][3]=-300;
    equation[51][0]=51;
    equation[51][1]=-48;
    equation[51][2]=-56;
    equation[51][3]=-58;
    equation[51][4]=-59;
    equation[51][5]=80;
    equation[51][6]=81;
    equation[52][0]=-43;
    equation[52][1]=-55;
    equation[52][2]=-56;
    equation[52][3]=-58;
    equation[52][4]=-59;
    equation[52][5]=100;
    equation[53][0]=21;
    equation[53][1]=-29;
    equation[53][2]=-29;
    equation[53][3]=38;
    equation[53][4]=-58;
    equation[53][5]=-59;
    equation[53][6]=-64;
    equation[53][7]=-69;
    equation[53][8]=70;
    equation[53][9]=84;
    equation[53][10]=5;
    equation[54][0]=-48;
    equation[54][1]=49;
    equation[54][2]=-51;
    equation[54][3]=-58;
    equation[54][4]=-59;
    equation[55][0]=-51;
    equation[55][1]=-52;
    equation[55][2]=56;
    equation[55][3]=100;
    equation[56][0]=52;
    equation[56][1]=-55;
    equation[57][0]=51;
    equation[57][1]=52;
    equation[57][2]=-55;
    equation[57][3]=56;
    equation[57][4]=57;
    equation[58][0]=-25;
    equation[58][1]=34;
    equation[58][2]=-38;
    equation[58][3]=-51;
    equation[58][4]=-52;
    equation[58][5]=-53;
    equation[58][6]=62;
    equation[58][7]=100;
    equation[59][0]=-25;
    equation[59][1]=34;
    equation[59][2]=-38;
    equation[59][3]=43;
    equation[59][4]=62;
    equation[59][5]=-78;
    equation[59][6]=100;
    equation[60][0]=25;
    equation[60][1]=43;
    equation[60][2]=-50;
    equation[60][3]=-87;
    equation[60][4]=100;
    equation[61][0]=3;
    equation[61][1]=8;
    equation[62][0]=61;
    equation[62][1]=85;
    equation[62][2]=-100;
    equation[63][0]=61;
    equation[64][0]=62;
    equation[64][1]=85;
    equation[65][0]=3;
    equation[66][0]=65;
    equation[67][0]=66;
    equation[68][0]=8;
    equation[69][0]=-25;
    equation[69][1]=200;
    equation[70][0]=23;
    equation[70][1]=68;
    equation[71][0]=-35;
    equation[71][1]=-83;
    equation[72][0]=-1;
    equation[72][1]=11;
    equation[72][2]=34;
    equation[72][3]=87;
    equation[72][4]=100;
    equation[73][0]=-25;
    equation[73][1]=43;
    equation[73][2]=-44;
    equation[73][3]=45;
    equation[73][4]=-47;
    equation[73][5]=66;
    equation[73][6]=67;
    equation[74][0]=73;
    equation[75][0]=66;
    equation[75][1]=74;
    equation[76][0]=-21;
    equation[76][1]=-32;
    equation[76][2]=-95;
    equation[76][3]=300;
    equation[77][0]=25;
    equation[77][1]=34;
    equation[77][2]=38;
    equation[77][3]=-100;
    equation[78][0]=12;
    equation[78][1]=21;
    equation[78][2]=25;
    equation[78][3]=34;
    equation[78][4]=38;
    equation[78][5]=-43;
    equation[78][6]=-62;
    equation[78][7]=-91;
    equation[78][8]=-400;
    equation[79][0]=34;
    equation[79][1]=38;
    equation[80][0]=49;
    equation[80][1]=54;
    equation[80][2]=-100;
    equation[81][0]=55;
    equation[81][1]=57;
    equation[81][2]=-100;
    equation[82][0]=3;
    equation[83][0]=21;
    equation[83][1]=38;
    equation[83][2]=59;
    equation[84][0]=31;
    equation[84][1]=-82;
    equation[85][0]=-38;
    equation[85][1]=100;
    equation[86][0]=19;
    equation[86][1]=33;
    equation[87][0]=9;
    equation[88][0]=87;
    equation[89][0]=87;
    equation[90][0]=24;
    equation[90][1]=86;
    equation[91][0]=-90;
    equation[91][1]=100;
    equation[92][0]=7;
    equation[92][1]=43;
    equation[92][2]=-100;
    equation[93][0]=34;
    equation[93][1]=38;
    equation[93][2]=-100;
    equation[94][0]=93;
    equation[95][0]=21;
    equation[95][1]=-29;
    equation[95][2]=-43;
    equation[95][3]=61;
    equation[95][4]=-100;

    for (int i = 0; i < 6; ++i) {                           //Valores da entrada
        if (equation[i][0] >= 100 || equation[i][0] <= -100)// mantendo o mesmo valor da entrada no vetor result
            result[i] = equation[i][0] / 100;
        else
            result[i] = equation[i][0];
    }
    result[6] = value[6];                      // valores constantes
    result[7] = value[7];

    for (int i = 8; i < 96; ++i) {
        sum = 0;
        for (int j = 0; j < 10; ++j) {
            if(equation[i][j]==1000)
                break;
            if (equation[i][j] >= 100 || equation[i][j] <= -100){
                sum += equation[i][j]/100;
            }else
            {
                if(equation[i][j] < 0)
                    sum += (-1) * value[abs(equation[i][j])];
                else
                    sum += value[abs(equation[i][j])];
            }
        }
        if (sum > 1){
            result[i]=1;
        } else if (sum < -1)
            result[i]=-1;
        else
            result[i]=sum;
    }

    if(debug) {
        for (int k = 0; k < 96; ++k) {
            cout << result[k]<<" ";

        }
        cout<<endl;

        for (int i = 8; i < 96; ++i) {
            printf("%d depende de ", result[i]);
            for (int j = 0; j < 10; ++j) {
                if (equation[i][j] == 1000)
                    break;
                else {
                    if ((equation[i][j] >= 100) || (equation[i][j]) <= -100)
                        printf(" %d ", equation[i][j] / 100);
                    else if (equation[i][j] < 0)
                        printf("-%d ", value[abs(equation[i][j])]);
                    else
                        printf("%d ", value[abs(equation[i][j])]);
                }
            }
            printf("da equaçao %d \n", i);
        }
    }
    return 0;
}