#include <iostream>
#include <string>
#define SIGN(x) (x > 1) ? 1 : ((x < -1) ? -1 : x)
#define DEBUG 1
#define FLAG 1000

using namespace std;
int main() {
    int terms = 11;
    int equations = 96;
    int functionResult[equations],lastResult[equations], result = 0;
    int function[equations][terms];
    int functionValue[equations] = { 1, 1, -1, 0, -1, 0, 1, 1, -1, 1, 1, 0, 0, 0, 1, 1, -1, -1, -1, 1, 1, 1, 1, -1,
                                     -1, -1, -1, -1, 1, 1, -1, 0, 0, -1, 1, 0, -1, 1, -1, -1, 1, -1, 0, 0, 1,-1, 0, 0,
                                     1, -1, 1, 1, 1, 0, -1, -1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, -1, -1, 1,
                                     0, 1, 0, -1, -1, -1, 1, -1, -1, -1, 1, 1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 0 };

      string functionName[96] = { "thetaMutagen", "thetaGFs", "thetaNutrients", "thetaTNFAlpha", "thetaHypoxia", "thetaGli",
      "thetaMax", "thetaPTEN", "thetaTGFBeta", "thetaDnaDamage", "thetap53_Mdm2", "thetaAMP_ATP", "thetaNF1", "thetaPKC", "thetaRTK",
      "thetaRAGS", "thetaRas", "thetaPI3K", "thetaPIP3", "thetaPDK1", "thetaIKK", "thetaNF_KappaB", "thetaRAF", "thetaERK",
      "thetap90", "thetaAKT", "thetaWNT", "thetaDsh", "thetaAPC", "thetaGSK3", "thetaGSK3_APC", "thetaBeta_cat", "thetaSlug",
      "thetamTOR", "thetaHIF1", "thetaCOX412", "thetaVHL", "thetaPHDs", "thetaMyc_Max", "thetaMyc", "thetaMXI1", "thetaTSC1_TSC2",
      "thetaRHEB", "thetap53", "thetaBcl2", "thetaBAX", "thetaBAD", "thetaBcl_XL", "thetaRb", "thetaE2F", "thetap14",
      "thetaCycA", "thetaCycB", "thetaCycD", "thetaCycE", "thetacdh1", "thetacdc20", "thetaUbcH10", "thetap27", "thetap21",
      "thetaMdm2", "thetaSmad", "thetaSmadMiz1", "thetaSmadE2F", "thetap15", "thetaFADD", "thetaCaspase8", "thetaBak", "thetaJNK",
      "thetaFOXO", "thetaFosJun", "thetaROS", "thetaAMPK", "thetaCytoc_APAF1", "thetaCaspase9", "thetaApoptosis", "thetaE_cadh", "thetaGlut1",
      "thetahTERT", "thetaVEGF", "thetaE2F_CyclinE", "thetacdh1_UbcH10", "thetaTAK1", "thetaGSH", "thetaTCF", "thetaMiz1", "thetap70",
      "thetaATM_ATR", "thetaCHK1_2", "thetaDNARepair", "thetaeEF2K", "thetaeEF2", "thetap53_PTEN", "thetaLDHA", "thetaAcidLactic", "thetaSnail" };

    for (int i = 0; i < equations; i++) {
        for (int j = 0; j < terms; j++) {
            function[i][j] = FLAG;
        }
        lastResult[i] = FLAG;
    }
    function[0][0] = 100;
    function[1][0] = 100;
    function[2][0] = -100;
    function[3][0] = 0;
    function[4][0] = -100;
    function[5][0] = 0;
    function[6][0] = 100;
    function[7][0] = 100;
    function[8][0] = 34;

    function[9][0] = 0;
    function[9][1] = 71;

    function[10][0] = 43;
    function[10][1] = 60;
    function[10][2] = -100;

    function[11][0] = -2;
    function[11][1] = 100;

    function[12][0] = -13;
    function[12][1] = 100;

    function[13][0] = 14;
    function[13][1] = 26;

    function[14][0] = 1;

    function[15][0] = 2;
    function[15][1] = -4;

    function[16][0] = -12;
    function[16][1] = 14;
    function[16][2] = 100;

    function[17][0] = 16;
    function[17][1] = 78;

    function[18][0] = 17;
    function[18][1] = -7;
    function[18][2] = -92;
    function[18][3] = 100;

    function[19][0] = 18;
    function[19][1] = 34;
    function[19][2] = 38;

    function[20][0] = 13;
    function[20][1] = 25;
    function[20][2] = 33;
    function[20][3] = -37;
    function[20][4] = -43;
    function[20][5] = 82;

    function[21][0] = 18;
    function[21][1] = 20;
    function[21][2] = 20;
    function[21][3] = -76;
    function[21][4] = 95;
    function[21][5] = -100;

    function[22][0] = 13;
    function[22][1] = 16;

    function[23][0] = 22;

    function[24][0] = 19;
    function[24][1] = 23;

    function[25][0] = 18;
    function[25][1] = 19;
    function[25][2] = -100;

    function[26][0] = -43;
    function[26][1] = 5;

    function[27][0] = 26;

    function[28][0] = 7;
    function[28][1] = 100;

    function[29][0] = -24;
    function[29][1] = -25;
    function[29][2] = -27;
    function[29][3] = -33;
    function[29][4] = 300;

    function[30][0] = 28;
    function[30][1] = 29;
    function[30][2] = -100;

    function[31][0] = -30;
    function[31][1] = -43;
    function[31][2] = 100;

    function[32][0] = -10;
    function[32][1] = 21;
    function[32][2] = 84;

    function[33][0] = 15;
    function[33][1] = 25;
    function[33][2] = 42;
    function[33][3] = -72;
    function[33][4] = -100;

    function[34][0] = 4;
    function[34][1] = 33;
    function[34][2] = -36;
    function[34][3] = -36;
    function[34][4] = -37;
    function[34][5] = 38;
    function[34][6] = -43;
    function[34][7] = -69;
    function[34][8] = 200;

    function[35][0] = 34;

    function[36][0] = -4;
    function[36][1] = -71;
    function[36][2] = 100;

    function[37][0] = -4;
    function[37][1] = 71;
    function[37][2] = 100;

    function[38][0] = -8;
    function[38][1] = 39;
    function[38][2] = 6;
    function[38][3] = -40;
    function[38][4] = -63;
    function[38][5] = -100;

    function[39][0] = 21;
    function[39][1] = 23;
    function[39][2] = -34;
    function[39][3] = 49;
    function[39][4] = 70;
    function[39][5] = 84;
    function[39][6] = 5;
    function[39][7] = -100;

    function[40][0] = 34;

    function[41][0] = -22;
    function[41][1] = -23;
    function[41][2] = -24;
    function[41][3] = -25;
    function[41][4] = 34;
    function[41][5] = 43;
    function[41][6] = 72;
    function[41][7] = 100;

    function[42][0] = -41;
    function[42][1] = 100;

    function[43][0] = 34;
    function[43][1] = -44;
    function[43][2] = -60;
    function[43][3] = 88;
    function[43][4] = 100;

    function[44][0] = 21;
    function[44][1] = 21;
    function[44][2] = -43;
    function[44][3] = -45;
    function[44][4] = -46;

    function[45][0] = -34;
    function[45][1] = 43;
    function[45][2] = -44;
    function[45][3] = 68;

    function[46][0] = -22;
    function[46][1] = -24;
    function[46][2] = -25;
    function[46][3] = -34;
    function[46][4] = 100;

    function[47][0] = -43;
    function[47][1] = -46;
    function[47][2] = 100;

    function[48][0] = -51;
    function[48][1] = -52;
    function[48][2] = -53;
    function[48][3] = -54;
    function[48][4] = -60;
    function[48][5] = 200;

    function[49][0] = -48;
    function[49][1] = -48;
    function[49][2] = -51;
    function[49][3] = -52;
    function[49][4] = 49;
    function[49][5] = 100;

    function[50][0] = 16;
    function[50][1] = 38;
    function[50][2] = 49;
    function[50][3] = -300;

    function[51][0] = 51;
    function[51][1] = -48;
    function[51][2] = -56;
    function[51][3] = -58;
    function[51][4] = -59;
    function[51][5] = 80;
    function[51][6] = 81;

    function[52][0] = -43;
    function[52][1] = -55;
    function[52][2] = -56;
    function[52][3] = -58;
    function[52][4] = -59;
    function[52][5] = 100;

    function[53][0] = 21;
    function[53][1] = -29;
    function[53][2] = -29;
    function[53][3] = 38;
    function[53][4] = -58;
    function[53][5] = -59;
    function[53][6] = -64;
    function[53][7] = -69;
    function[53][8] = 70;
    function[53][9] = 84;
    function[53][10] = 5;

    function[54][0] = -48;
    function[54][1] = 49;
    function[54][2] = -51;
    function[54][3] = -58;
    function[54][4] = -59;

    function[55][0] = -51;
    function[55][1] = -52;
    function[55][2] = 56;
    function[55][3] = 100;

    function[56][0] = 52;
    function[56][1] = -55;

    function[57][0] = 51;
    function[57][1] = 52;
    function[57][2] = -55;
    function[57][3] = 56;
    function[57][4] = 57;

    function[58][0] = -25;
    function[58][1] = 34;
    function[58][2] = -38;
    function[58][3] = -51;
    function[58][4] = -52;
    function[58][5] = -53;
    function[58][6] = 62;
    function[58][7] = 100;

    function[59][0] = -25;
    function[59][1] = 34;
    function[59][2] = -38;
    function[59][3] = 43;
    function[59][4] = 62;
    function[59][5] = -78;
    function[59][6] = 100;

    function[60][0] = 25;
    function[60][1] = 43;
    function[60][2] = -50;
    function[60][3] = -87;
    function[60][4] = 100;

    function[61][0] = 3;
    function[61][1] = 8;

    function[62][0] = 61;
    function[62][1] = 85;
    function[62][2] = -100;

    function[63][0] = 61;

    function[64][0] = 62;
    function[64][1] = 85;

    function[65][0] = 3;

    function[66][0] = 65;

    function[67][0] = 66;

    function[68][0] = 8;

    function[69][0] = -25;
    function[69][1] = 200;

    function[70][0] = 23;
    function[70][1] = 68;

    function[71][0] = -35;
    function[71][1] = -83;

    function[72][0] = -1;
    function[72][1] = 11;
    function[72][2] = 34;
    function[72][3] = 87;
    function[72][4] = 100;

    function[73][0] = -25;
    function[73][1] = 43;
    function[73][2] = -44;
    function[73][3] = 45;
    function[73][4] = -47;
    function[73][5] = 66;
    function[73][6] = 67;

    function[74][0] = 73;

    function[75][0] = 66;
    function[75][1] = 74;

    function[76][0] = -21;
    function[76][1] = -32;
    function[76][2] = -95;
    function[76][3] = 300;

    function[77][0] = 25;
    function[77][1] = 34;
    function[77][2] = 38;
    function[77][3] = -100;

    function[78][0] = 12;
    function[78][1] = 21;
    function[78][2] = 25;
    function[78][3] = 34;
    function[78][4] = 38;
    function[78][5] = -43;
    function[78][6] = -62;
    function[78][7] = -91;
    function[78][8] = -400;

    function[79][0] = 34;
    function[79][1] = 38;

    function[80][0] = 49;
    function[80][1] = 54;
    function[80][2] = -100;

    function[81][0] = 55;
    function[81][1] = 57;
    function[81][2] = -100;

    function[82][0] = 3;

    function[83][0] = 21;
    function[83][1] = 38;
    function[83][2] = 59;

    function[84][0] = 31;
    function[84][1] = -82;

    function[85][0] = -38;
    function[85][1] = 100;

    function[86][0] = 19;
    function[86][1] = 33;

    function[87][0] = 9;

    function[88][0] = 87;

    function[89][0] = 87;

    function[90][0] = 24;
    function[90][1] = 86;

    function[91][0] = -90;
    function[91][1] = 100;

    function[92][0] = 7;
    function[92][1] = 43;
    function[92][2] = -100;

    function[93][0] = 34;
    function[93][1] = 38;
    function[93][2] = -100;

    function[94][0] = 93;

    function[95][0] = 21;
    function[95][1] = -29;
    function[95][2] = -43;
    function[95][3] = 61;
    function[95][4] = -100;

    for (int i  =  0; i < 6; ++i) {                           //Valores da entrada
        if (function[i][0] >= 100 || function[i][0] <= -100)// mantendo o mesmo valor da entrada no vetor functionResult
            lastResult[i] = functionResult[i] = function[i][0]/100;
        else
            lastResult[i] = functionResult[i] = function[i][0];
    }

    lastResult[6] = functionResult[6] = functionValue[6];                      // valores constantes
    lastResult[7] = functionResult[7] = functionValue[7];


    for (int i = 8; i < equations; i++) {
        result = 0;
        for (int j = 0; j < terms; j++) {
            if(function[i][j] == FLAG)
                break;
            if (function[i][j] >= 100 || function[i][j] <= -100)
                result +=  function[i][j]/100;
            else if(function[i][j] < 0)
                result += (-1) * functionValue[abs(function[i][j])];
            else
                result += functionValue[abs(function[i][j])];
        }
       functionResult[i] = SIGN(result);
    }
    for (int i = 8; i < equations; i++)
        lastResult[i] = functionResult[i];


    if(DEBUG) {
        for (int k = 0; k < equations; k++) {
            cout << functionResult[k] << " ";
        }
        cout << endl;

        for (int i = 8; i < equations; i++) {
            printf("%d depende de ", functionResult[i]); //Printf ou Cout ??
            for (int j  =  0; j < terms; ++j) {
                if (function[i][j]  ==  FLAG)
                    break;
                else {
                    if ((function[i][j] >= 100) || (function[i][j]) <= -100)
                        printf(" %d ", function[i][j] / 100); //Printf ou Cout ??
                    else if (function[i][j] < 0)
                        printf("-%d ", functionValue[abs(function[i][j])]); //Printf ou Cout ??
                    else
                        printf("%d ", functionValue[abs(function[i][j])]); //Printf ou Cout ??
                }
            }
            printf("da equaçao %d \n", i);
        }
    }
    return 0;
}
