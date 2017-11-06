#include <iostream>
#include <string>
#include <cuda_runtime.h>

#define SIGN(x) (x > 1) ? 1 : ((x < -1) ? -1 : x)
#define DEBUG 1
#define FLAG 1000

using namespace std;

__global__ void calculateAtractor(const int *R){
    int thetaMutagen = 1;
    int thetaGFs = 1;
    int thetaNutrients = -1;
    int thetaTNFAlpha = 0;
    int thetaHypoxia = -1;
    int thetaGli = 0;
    int thetaMax = 1;
    int thetaPTEN = 1;

    int thetaTGFBeta = 0;
    int thetaDnaDamage = 0;
    int thetap53_Mdm2 = 0;
    int thetaAMP_ATP = 0;
    int thetaNF1 = 0;
    int thetaPKC = 0;
    int thetaRTK = 0;
    int thetaRAGS = 0;
    int thetaRas = 0;
    int thetaPI3K = 0;
    int thetaPIP3 = 0;
    int thetaPDK1 = 0;
    int thetaIKK = 0;
    int thetaNF_KappaB = 0;
    int thetaRAF = 0;
    int thetaERK = 0;
    int thetap90 = 0;
    int thetaAKT = 0;
    int thetaWNT = 0;
    int thetaDsh = 0;
    int thetaAPC = 0;
    int thetaGSK3 = 0;
    int thetaGSK3_APC = 0;
    int thetaBeta_cat = 0;
    int thetaSlug = 0;
    int thetamTOR = 0;
    int thetaHIF1 = 0;
    int thetaCOX412 = 0;
    int thetaVHL = 0;
    int thetaPHDs = 0;
    int thetaMyc_Max = 0;
    int thetaMyc = 0;
    int thetaMXI1 = 0;
    int thetaTSC1_TSC2 = 0;
    int thetaRHEB = 0;
    int thetap53 = 0;
    int thetaBcl2 = 0;
    int thetaBAX = 0;
    int thetaBAD = 0;
    int thetaBcl_XL = 0;
    int thetaRb = 0;
    int thetaE2F = 0;
    int thetap14 = 0;
    int thetaCycA = 0;
    int thetaCycB = 0;
    int thetaCycD = 0;
    int thetaCycE = 0;
    int thetacdh1 = 0;
    int thetacdc20 = 0;
    int thetaUbcH10 = 0;
    int thetap27 = 0;
    int thetap21 = 0;
    int thetaMdm2 = 0;
    int thetaSmad = 0;
    int thetaSmadMiz1 = 0;
    int thetaSmadE2F = 0;
    int thetap15 = 0;
    int thetaFADD = 0;
    int thetaCaspase8 = 0;
    int thetaBak = 0;
    int thetaJNK = 0;
    int thetaFOXO = 0;
    int thetaFosJun = 0;
    int thetaROS = 0;
    int thetaAMPK = 0;
    int thetaCytoc_APAF1 = 0;
    int thetaCaspase9 = 0;
    int thetaApoptosis = 0;
    int thetaE_cadh = 0;
    int thetaGlut1 = 0;
    int thetahTERT = 0;
    int thetaVEGF = 0;
    int thetaE2F_CyclinE = 0;
    int thetacdh1_UbcH10 = 0;
    int thetaTAK1 = 0;
    int thetaGSH = 0;
    int thetaTCF = 0;
    int thetaMiz1 = 0;
    int thetap70 = 0;
    int thetaATM_ATR = 0;
    int thetaCHK1_2 = 0;
    int thetaDNARepair = 0;
    int thetaeEF2K = 0;
    int thetaeEF2 = 0;
    int thetap53_PTEN = 0;
    int thetaLDHA = 0;
    int thetaAcidLactic = 0;
    int thetaSnail = 0;


    thetaTGFBeta = SIGN(  + thetaHIF1 );
    thetaDnaDamage = SIGN(  + thetaMutagen + thetaROS );
    thetap53_Mdm2 = SIGN(  + thetap53 + thetaMdm2 + -1 );
    thetaAMP_ATP = SIGN(  - thetaNutrients + 1 );
    thetaNF1 = SIGN(  - thetaPKC + 1 );
    thetaPKC = SIGN(  + thetaRTK + thetaWNT );
    thetaRTK = SIGN(  + thetaGFs );
    thetaRAGS = SIGN(  + thetaNutrients - thetaHypoxia );
    thetaRas = SIGN(  - thetaNF1 + thetaRTK + 1 );
    thetaPI3K = SIGN(  + thetaRas + thetahTERT );
    thetaPIP3 = SIGN(  + thetaPI3K - thetaPTEN - thetap53_PTEN + 1 );
    thetaPDK1 = SIGN(  + thetaPIP3 + thetaHIF1 + thetaMyc_Max );
    thetaIKK = SIGN(  + thetaPKC + thetaAKT + thetamTOR - thetaPHDs - thetap53 + thetaTAK1 );
    thetaNF_KappaB = SIGN(  + thetaPIP3 + thetaIKK + thetaIKK - thetaE_cadh + thetaSnail + -1 );
    thetaRAF = SIGN(  + thetaPKC + thetaRas );
    thetaERK = SIGN(  + thetaRAF );
    thetap90 = SIGN(  + thetaPDK1 + thetaERK );
    thetaAKT = SIGN(  + thetaPIP3 + thetaPDK1 + -1 );
    thetaWNT = SIGN(  - thetap53 + thetaGli );
    thetaDsh = SIGN(  + thetaWNT );
    thetaAPC = SIGN(  + thetaPTEN + 1 );
    thetaGSK3 = SIGN(  - thetap90 - thetaAKT - thetaDsh - thetamTOR + 3 );
    thetaGSK3_APC = SIGN(  + thetaAPC + thetaGSK3 + -1 );
    thetaBeta_cat = SIGN(  - thetaGSK3_APC - thetap53 + 1 );
    thetaSlug = SIGN(  - thetap53_Mdm2 + thetaNF_KappaB + thetaTCF );
    thetamTOR = SIGN(  + thetaRAGS + thetaAKT + thetaRHEB - thetaAMPK + -1 );
    thetaHIF1 = SIGN(  + thetaHypoxia + thetamTOR - thetaVHL - thetaVHL - thetaPHDs + thetaMyc_Max - thetap53 - thetaFOXO + 2 );
    thetaCOX412 = SIGN(  + thetaHIF1 );
    thetaVHL = SIGN(  - thetaHypoxia - thetaROS + 1 );
    thetaPHDs = SIGN(  - thetaHypoxia + thetaROS + 1 );
    thetaMyc_Max = SIGN(  - thetaTGFBeta + thetaMyc + thetaMax - thetaMXI1 - thetaSmadE2F + -1 );
    thetaMyc = SIGN(  + thetaNF_KappaB + thetaERK - thetaHIF1 + thetaE2F + thetaFosJun + thetaTCF + thetaGli + -1 );
    thetaMXI1 = SIGN(  + thetaHIF1 );
    thetaTSC1_TSC2 = SIGN(  - thetaRAF - thetaERK - thetap90 - thetaAKT + thetaHIF1 + thetap53 + thetaAMPK + 1 );
    thetaRHEB = SIGN(  - thetaTSC1_TSC2 + 1 );
    thetap53 = SIGN(  + thetaHIF1 - thetaBcl2 - thetaMdm2 + thetaCHK1_2 + 1 );
    thetaBcl2 = SIGN(  + thetaNF_KappaB + thetaNF_KappaB - thetap53 - thetaBAX - thetaBAD );
    thetaBAX = SIGN(  - thetaHIF1 + thetap53 - thetaBcl2 + thetaJNK );
    thetaBAD = SIGN(  - thetaRAF - thetap90 - thetaAKT - thetaHIF1 + 1 );
    thetaBcl_XL = SIGN(  - thetap53 - thetaBAD + 1 );
    thetaRb = SIGN(  - thetaCycA - thetaCycB - thetaCycD - thetaCycE - thetaMdm2 + 2 );
    thetaE2F = SIGN(  - thetaRb - thetaRb - thetaCycA - thetaCycB + thetaE2F + 1 );
    thetap14 = SIGN(  + thetaRas + thetaMyc_Max + thetaE2F + -3 );
    thetaCycA = SIGN(  + thetaCycA - thetaRb - thetacdc20 - thetap27 - thetap21 + thetaE2F_CyclinE + thetacdh1_UbcH10 );
    thetaCycB = SIGN(  - thetap53 - thetacdh1 - thetacdc20 - thetap27 - thetap21 + 1 );
    thetaCycD = SIGN(  + thetaNF_KappaB - thetaGSK3 - thetaGSK3 + thetaMyc_Max - thetap27 - thetap21 - thetap15 - thetaFOXO + thetaFosJun + thetaTCF + thetaGli );
    thetaCycE = SIGN(  - thetaRb + thetaE2F - thetaCycA - thetap27 - thetap21 );
    thetacdh1 = SIGN(  - thetaCycA - thetaCycB + thetacdc20 + 1 );
    thetacdc20 = SIGN(  + thetaCycB - thetacdh1 );
    thetaUbcH10 = SIGN(  + thetaCycA + thetaCycB - thetacdh1 + thetacdc20 + thetaUbcH10 );
    thetap27 = SIGN(  - thetaAKT + thetaHIF1 - thetaMyc_Max - thetaCycA - thetaCycB - thetaCycD + thetaSmadMiz1 + 1 );
    thetap21 = SIGN(  - thetaAKT + thetaHIF1 - thetaMyc_Max + thetap53 + thetaSmadMiz1 - thetahTERT + 1 );
    thetaMdm2 = SIGN(  + thetaAKT + thetap53 - thetap14 - thetaATM_ATR + 1 );
    thetaSmad = SIGN(  + thetaTNFAlpha + thetaTGFBeta );
    thetaSmadMiz1 = SIGN(  + thetaSmad + thetaMiz1 + -1 );
    thetaSmadE2F = SIGN(  + thetaSmad );
    thetap15 = SIGN(  + thetaSmadMiz1 + thetaMiz1 );
    thetaFADD = SIGN(  + thetaTNFAlpha );
    thetaCaspase8 = SIGN(  + thetaFADD );
    thetaBak = SIGN(  + thetaCaspase8 );
    thetaJNK = SIGN(  + thetaTGFBeta );
    thetaFOXO = SIGN(  - thetaAKT + 2 );
    thetaFosJun = SIGN(  + thetaERK + thetaJNK );
    thetaROS = SIGN(  - thetaCOX412 - thetaGSH );
    thetaAMPK = SIGN(  - thetaGFs + thetaAMP_ATP + thetaHIF1 + thetaATM_ATR + 1 );
    thetaCytoc_APAF1 = SIGN(  - thetaAKT + thetap53 - thetaBcl2 + thetaBAX - thetaBcl_XL + thetaCaspase8 + thetaBak );
    thetaCaspase9 = SIGN(  + thetaCytoc_APAF1 );
    thetaApoptosis = SIGN(  + thetaCaspase8 + thetaCaspase9 );
    thetaE_cadh = SIGN(  - thetaNF_KappaB - thetaSlug - thetaSnail + 3 );
    thetaGlut1 = SIGN(  + thetaAKT + thetaHIF1 + thetaMyc_Max + -1 );
    thetahTERT = SIGN(  + thetaNF1 + thetaNF_KappaB + thetaAKT + thetaHIF1 + thetaMyc_Max - thetap53 - thetaSmadMiz1 - thetaeEF2 + -4 );
    thetaVEGF = SIGN(  + thetaHIF1 + thetaMyc_Max );
    thetaE2F_CyclinE = SIGN(  + thetaE2F + thetaCycE + -1 );
    thetacdh1_UbcH10 = SIGN(  + thetacdh1 + thetaUbcH10 + -1 );
    thetaTAK1 = SIGN(  + thetaTNFAlpha );
    thetaGSH = SIGN(  + thetaNF_KappaB + thetaMyc_Max + thetap21 );
    thetaTCF = SIGN(  + thetaBeta_cat - thetaTAK1 );
    thetaMiz1 = SIGN(  - thetaMyc_Max + 1 );
    thetap70 = SIGN(  + thetaPDK1 + thetamTOR );
    thetaATM_ATR = SIGN(  + thetaDnaDamage );
    thetaCHK1_2 = SIGN(  + thetaATM_ATR );
    thetaDNARepair = SIGN(  + thetaATM_ATR );
    thetaeEF2K = SIGN(  + thetap90 + thetap70 );
    thetaeEF2 = SIGN(  - thetaeEF2K + 1 );
    thetap53_PTEN = SIGN(  + thetaPTEN + thetap53 + -1 );
    thetaLDHA = SIGN(  + thetaHIF1 + thetaMyc_Max + -1 );
    thetaAcidLactic = SIGN(  + thetaLDHA );
    thetaSnail = SIGN(  + thetaNF_KappaB - thetaGSK3 - thetap53 + thetaSmad + -1 );

    {
        int thetaMutagen = 1;
        int thetaGFs = 1;
        int thetaNutrients = -1;
        int thetaTNFAlpha = 0;
        int thetaHypoxia = -1;
        int thetaGli = 0;
        int thetaMax = 1;
        int thetaPTEN = 1;

        int thetaTGFBeta = 0;
        int thetaDnaDamage = 0;
        int thetap53_Mdm2 = 0;
        int thetaAMP_ATP = 0;
        int thetaNF1 = 0;
        int thetaPKC = 0;
        int thetaRTK = 0;
        int thetaRAGS = 0;
        int thetaRas = 0;
        int thetaPI3K = 0;
        int thetaPIP3 = 0;
        int thetaPDK1 = 0;
        int thetaIKK = 0;
        int thetaNF_KappaB = 0;
        int thetaRAF = 0;
        int thetaERK = 0;
        int thetap90 = 0;
        int thetaAKT = 0;
        int thetaWNT = 0;
        int thetaDsh = 0;
        int thetaAPC = 0;
        int thetaGSK3 = 0;
        int thetaGSK3_APC = 0;
        int thetaBeta_cat = 0;
        int thetaSlug = 0;
        int thetamTOR = 0;
        int thetaHIF1 = 0;
        int thetaCOX412 = 0;
        int thetaVHL = 0;
        int thetaPHDs = 0;
        int thetaMyc_Max = 0;
        int thetaMyc = 0;
        int thetaMXI1 = 0;
        int thetaTSC1_TSC2 = 0;
        int thetaRHEB = 0;
        int thetap53 = 0;
        int thetaBcl2 = 0;
        int thetaBAX = 0;
        int thetaBAD = 0;
        int thetaBcl_XL = 0;
        int thetaRb = 0;
        int thetaE2F = 0;
        int thetap14 = 0;
        int thetaCycA = 0;
        int thetaCycB = 0;
        int thetaCycD = 0;
        int thetaCycE = 0;
        int thetacdh1 = 0;
        int thetacdc20 = 0;
        int thetaUbcH10 = 0;
        int thetap27 = 0;
        int thetap21 = 0;
        int thetaMdm2 = 0;
        int thetaSmad = 0;
        int thetaSmadMiz1 = 0;
        int thetaSmadE2F = 0;
        int thetap15 = 0;
        int thetaFADD = 0;
        int thetaCaspase8 = 0;
        int thetaBak = 0;
        int thetaJNK = 0;
        int thetaFOXO = 0;
        int thetaFosJun = 0;
        int thetaROS = 0;
        int thetaAMPK = 0;
        int thetaCytoc_APAF1 = 0;
        int thetaCaspase9 = 0;
        int thetaApoptosis = 0;
        int thetaE_cadh = 0;
        int thetaGlut1 = 0;
        int thetahTERT = 0;
        int thetaVEGF = 0;
        int thetaE2F_CyclinE = 0;
        int thetacdh1_UbcH10 = 0;
        int thetaTAK1 = 0;
        int thetaGSH = 0;
        int thetaTCF = 0;
        int thetaMiz1 = 0;
        int thetap70 = 0;
        int thetaATM_ATR = 0;
        int thetaCHK1_2 = 0;
        int thetaDNARepair = 0;
        int thetaeEF2K = 0;
        int thetaeEF2 = 0;
        int thetap53_PTEN = 0;
        int thetaLDHA = 0;
        int thetaAcidLactic = 0;
        int thetaSnail = 0;


        for(int i = 0; i < 2; i++){
            thetaTGFBeta = SIGN(  + thetaHIF1 );
            thetaDnaDamage = SIGN(  + thetaMutagen + thetaROS );
            thetap53_Mdm2 = SIGN(  + thetap53 + thetaMdm2 + -1 );
            thetaAMP_ATP = SIGN(  - thetaNutrients + 1 );
            thetaNF1 = SIGN(  - thetaPKC + 1 );
            thetaPKC = SIGN(  + thetaRTK + thetaWNT );
            thetaRTK = SIGN(  + thetaGFs );
            thetaRAGS = SIGN(  + thetaNutrients - thetaHypoxia );
            thetaRas = SIGN(  - thetaNF1 + thetaRTK + 1 );
            thetaPI3K = SIGN(  + thetaRas + thetahTERT );
            thetaPIP3 = SIGN(  + thetaPI3K - thetaPTEN - thetap53_PTEN + 1 );
            thetaPDK1 = SIGN(  + thetaPIP3 + thetaHIF1 + thetaMyc_Max );
            thetaIKK = SIGN(  + thetaPKC + thetaAKT + thetamTOR - thetaPHDs - thetap53 + thetaTAK1 );
            thetaNF_KappaB = SIGN(  + thetaPIP3 + thetaIKK + thetaIKK - thetaE_cadh + thetaSnail + -1 );
            thetaRAF = SIGN(  + thetaPKC + thetaRas );
            thetaERK = SIGN(  + thetaRAF );
            thetap90 = SIGN(  + thetaPDK1 + thetaERK );
            thetaAKT = SIGN(  + thetaPIP3 + thetaPDK1 + -1 );
            thetaWNT = SIGN(  - thetap53 + thetaGli );
            thetaDsh = SIGN(  + thetaWNT );
            thetaAPC = SIGN(  + thetaPTEN + 1 );
            thetaGSK3 = SIGN(  - thetap90 - thetaAKT - thetaDsh - thetamTOR + 3 );
            thetaGSK3_APC = SIGN(  + thetaAPC + thetaGSK3 + -1 );
            thetaBeta_cat = SIGN(  - thetaGSK3_APC - thetap53 + 1 );
            thetaSlug = SIGN(  - thetap53_Mdm2 + thetaNF_KappaB + thetaTCF );
            thetamTOR = SIGN(  + thetaRAGS + thetaAKT + thetaRHEB - thetaAMPK + -1 );
            thetaHIF1 = SIGN(  + thetaHypoxia + thetamTOR - thetaVHL - thetaVHL - thetaPHDs + thetaMyc_Max - thetap53 - thetaFOXO + 2 );
            thetaCOX412 = SIGN(  + thetaHIF1 );
            thetaVHL = SIGN(  - thetaHypoxia - thetaROS + 1 );
            thetaPHDs = SIGN(  - thetaHypoxia + thetaROS + 1 );
            thetaMyc_Max = SIGN(  - thetaTGFBeta + thetaMyc + thetaMax - thetaMXI1 - thetaSmadE2F + -1 );
            thetaMyc = SIGN(  + thetaNF_KappaB + thetaERK - thetaHIF1 + thetaE2F + thetaFosJun + thetaTCF + thetaGli + -1 );
            thetaMXI1 = SIGN(  + thetaHIF1 );
            thetaTSC1_TSC2 = SIGN(  - thetaRAF - thetaERK - thetap90 - thetaAKT + thetaHIF1 + thetap53 + thetaAMPK + 1 );
            thetaRHEB = SIGN(  - thetaTSC1_TSC2 + 1 );
            thetap53 = SIGN(  + thetaHIF1 - thetaBcl2 - thetaMdm2 + thetaCHK1_2 + 1 );
            thetaBcl2 = SIGN(  + thetaNF_KappaB + thetaNF_KappaB - thetap53 - thetaBAX - thetaBAD );
            thetaBAX = SIGN(  - thetaHIF1 + thetap53 - thetaBcl2 + thetaJNK );
            thetaBAD = SIGN(  - thetaRAF - thetap90 - thetaAKT - thetaHIF1 + 1 );
            thetaBcl_XL = SIGN(  - thetap53 - thetaBAD + 1 );
            thetaRb = SIGN(  - thetaCycA - thetaCycB - thetaCycD - thetaCycE - thetaMdm2 + 2 );
            thetaE2F = SIGN(  - thetaRb - thetaRb - thetaCycA - thetaCycB + thetaE2F + 1 );
            thetap14 = SIGN(  + thetaRas + thetaMyc_Max + thetaE2F + -3 );
            thetaCycA = SIGN(  + thetaCycA - thetaRb - thetacdc20 - thetap27 - thetap21 + thetaE2F_CyclinE + thetacdh1_UbcH10 );
            thetaCycB = SIGN(  - thetap53 - thetacdh1 - thetacdc20 - thetap27 - thetap21 + 1 );
            thetaCycD = SIGN(  + thetaNF_KappaB - thetaGSK3 - thetaGSK3 + thetaMyc_Max - thetap27 - thetap21 - thetap15 - thetaFOXO + thetaFosJun + thetaTCF + thetaGli );
            thetaCycE = SIGN(  - thetaRb + thetaE2F - thetaCycA - thetap27 - thetap21 );
            thetacdh1 = SIGN(  - thetaCycA - thetaCycB + thetacdc20 + 1 );
            thetacdc20 = SIGN(  + thetaCycB - thetacdh1 );
            thetaUbcH10 = SIGN(  + thetaCycA + thetaCycB - thetacdh1 + thetacdc20 + thetaUbcH10 );
            thetap27 = SIGN(  - thetaAKT + thetaHIF1 - thetaMyc_Max - thetaCycA - thetaCycB - thetaCycD + thetaSmadMiz1 + 1 );
            thetap21 = SIGN(  - thetaAKT + thetaHIF1 - thetaMyc_Max + thetap53 + thetaSmadMiz1 - thetahTERT + 1 );
            thetaMdm2 = SIGN(  + thetaAKT + thetap53 - thetap14 - thetaATM_ATR + 1 );
            thetaSmad = SIGN(  + thetaTNFAlpha + thetaTGFBeta );
            thetaSmadMiz1 = SIGN(  + thetaSmad + thetaMiz1 + -1 );
            thetaSmadE2F = SIGN(  + thetaSmad );
            thetap15 = SIGN(  + thetaSmadMiz1 + thetaMiz1 );
            thetaFADD = SIGN(  + thetaTNFAlpha );
            thetaCaspase8 = SIGN(  + thetaFADD );
            thetaBak = SIGN(  + thetaCaspase8 );
            thetaJNK = SIGN(  + thetaTGFBeta );
            thetaFOXO = SIGN(  - thetaAKT + 2 );
            thetaFosJun = SIGN(  + thetaERK + thetaJNK );
            thetaROS = SIGN(  - thetaCOX412 - thetaGSH );
            thetaAMPK = SIGN(  - thetaGFs + thetaAMP_ATP + thetaHIF1 + thetaATM_ATR + 1 );
            thetaCytoc_APAF1 = SIGN(  - thetaAKT + thetap53 - thetaBcl2 + thetaBAX - thetaBcl_XL + thetaCaspase8 + thetaBak );
            thetaCaspase9 = SIGN(  + thetaCytoc_APAF1 );
            thetaApoptosis = SIGN(  + thetaCaspase8 + thetaCaspase9 );
            thetaE_cadh = SIGN(  - thetaNF_KappaB - thetaSlug - thetaSnail + 3 );
            thetaGlut1 = SIGN(  + thetaAKT + thetaHIF1 + thetaMyc_Max + -1 );
            thetahTERT = SIGN(  + thetaNF1 + thetaNF_KappaB + thetaAKT + thetaHIF1 + thetaMyc_Max - thetap53 - thetaSmadMiz1 - thetaeEF2 + -4 );
            thetaVEGF = SIGN(  + thetaHIF1 + thetaMyc_Max );
            thetaE2F_CyclinE = SIGN(  + thetaE2F + thetaCycE + -1 );
            thetacdh1_UbcH10 = SIGN(  + thetacdh1 + thetaUbcH10 + -1 );
            thetaTAK1 = SIGN(  + thetaTNFAlpha );
            thetaGSH = SIGN(  + thetaNF_KappaB + thetaMyc_Max + thetap21 );
            thetaTCF = SIGN(  + thetaBeta_cat - thetaTAK1 );
            thetaMiz1 = SIGN(  - thetaMyc_Max + 1 );
            thetap70 = SIGN(  + thetaPDK1 + thetamTOR );
            thetaATM_ATR = SIGN(  + thetaDnaDamage );
            thetaCHK1_2 = SIGN(  + thetaATM_ATR );
            thetaDNARepair = SIGN(  + thetaATM_ATR );
            thetaeEF2K = SIGN(  + thetap90 + thetap70 );
            thetaeEF2 = SIGN(  - thetaeEF2K + 1 );
            thetap53_PTEN = SIGN(  + thetaPTEN + thetap53 + -1 );
            thetaLDHA = SIGN(  + thetaHIF1 + thetaMyc_Max + -1 );
            thetaAcidLactic = SIGN(  + thetaLDHA );
            thetaSnail = SIGN(  + thetaNF_KappaB - thetaGSK3 - thetap53 + thetaSmad + -1 );
        }

        bool x[88];
        int i = 0;
        
        thetaTGFBeta == ::thetaTGFBeta ? x[i++] = true : x[i++] = false;
        thetaDnaDamage  == ::thetaDnaDamage  ? x[i++] = true : x[i++] = false;
        thetap53_Mdm2  == ::thetap53_Mdm2  ? x[i++] = true : x[i++] = false;
        thetaAMP_ATP  == ::thetaAMP_ATP  ? x[i++] = true : x[i++] = false;
        thetaNF1  == ::thetaNF1  ? x[i++] = true : x[i++] = false;
        thetaPKC  == ::thetaPKC  ? x[i++] = true : x[i++] = false;
        thetaRTK  == ::thetaRTK  ? x[i++] = true : x[i++] = false;
        thetaRAGS  == ::thetaRAGS  ? x[i++] = true : x[i++] = false;
        thetaRas  == ::thetaRas  ? x[i++] = true : x[i++] = false;
        thetaPI3K  == ::thetaPI3K  ? x[i++] = true : x[i++] = false;
        thetaPIP3  == ::thetaPIP3  ? x[i++] = true : x[i++] = false;
        thetaPDK1  == ::thetaPDK1  ? x[i++] = true : x[i++] = false;
        thetaIKK  == ::thetaIKK  ? x[i++] = true : x[i++] = false;
        thetaNF_KappaB  == ::thetaNF_KappaB  ? x[i++] = true : x[i++] = false;
        thetaRAF  == ::thetaRAF  ? x[i++] = true : x[i++] = false;
        thetaERK  == ::thetaERK  ? x[i++] = true : x[i++] = false;
        thetap90  == ::thetap90  ? x[i++] = true : x[i++] = false;
        thetaAKT  == ::thetaAKT  ? x[i++] = true : x[i++] = false;
        thetaWNT  == ::thetaWNT  ? x[i++] = true : x[i++] = false;
        thetaDsh  == ::thetaDsh  ? x[i++] = true : x[i++] = false;
        thetaAPC  == ::thetaAPC  ? x[i++] = true : x[i++] = false;
        thetaGSK3  == ::thetaGSK3  ? x[i++] = true : x[i++] = false;
        thetaGSK3_APC  == ::thetaGSK3_APC  ? x[i++] = true : x[i++] = false;
        thetaBeta_cat  == ::thetaBeta_cat  ? x[i++] = true : x[i++] = false;
        thetaSlug  == ::thetaSlug  ? x[i++] = true : x[i++] = false;
        thetamTOR  == ::thetamTOR  ? x[i++] = true : x[i++] = false;
        thetaHIF1  == ::thetaHIF1  ? x[i++] = true : x[i++] = false;
        thetaCOX412  == ::thetaCOX412  ? x[i++] = true : x[i++] = false;
        thetaVHL  == ::thetaVHL  ? x[i++] = true : x[i++] = false;
        thetaPHDs  == ::thetaPHDs  ? x[i++] = true : x[i++] = false;
        thetaMyc_Max  == ::thetaMyc_Max  ? x[i++] = true : x[i++] = false;
        thetaMyc  == ::thetaMyc  ? x[i++] = true : x[i++] = false;
        thetaMXI1  == ::thetaMXI1  ? x[i++] = true : x[i++] = false;
        thetaTSC1_TSC2  == ::thetaTSC1_TSC2  ? x[i++] = true : x[i++] = false;
        thetaRHEB  == ::thetaRHEB  ? x[i++] = true : x[i++] = false;
        thetap53  == ::thetap53  ? x[i++] = true : x[i++] = false;
        thetaBcl2  == ::thetaBcl2  ? x[i++] = true : x[i++] = false;
        thetaBAX  == ::thetaBAX  ? x[i++] = true : x[i++] = false;
        thetaBAD  == ::thetaBAD  ? x[i++] = true : x[i++] = false;
        thetaBcl_XL  == ::thetaBcl_XL  ? x[i++] = true : x[i++] = false;
        thetaRb  == ::thetaRb  ? x[i++] = true : x[i++] = false;
        thetaE2F  == ::thetaE2F  ? x[i++] = true : x[i++] = false;
        thetap14  == ::thetap14  ? x[i++] = true : x[i++] = false;
        thetaCycA  == ::thetaCycA  ? x[i++] = true : x[i++] = false;
        thetaCycB  == ::thetaCycB  ? x[i++] = true : x[i++] = false;
        thetaCycD  == ::thetaCycD  ? x[i++] = true : x[i++] = false;
        thetaCycE  == ::thetaCycE  ? x[i++] = true : x[i++] = false;
        thetacdh1  == ::thetacdh1  ? x[i++] = true : x[i++] = false;
        thetacdc20  == ::thetacdc20  ? x[i++] = true : x[i++] = false;
        thetaUbcH10  == ::thetaUbcH10  ? x[i++] = true : x[i++] = false;
        thetap27  == ::thetap27  ? x[i++] = true : x[i++] = false;
        thetap21  == ::thetap21  ? x[i++] = true : x[i++] = false;
        thetaMdm2  == ::thetaMdm2  ? x[i++] = true : x[i++] = false;
        thetaSmad  == ::thetaSmad  ? x[i++] = true : x[i++] = false;
        thetaSmadMiz1  == ::thetaSmadMiz1  ? x[i++] = true : x[i++] = false;
        thetaSmadE2F  == ::thetaSmadE2F  ? x[i++] = true : x[i++] = false;
        thetap15  == ::thetap15  ? x[i++] = true : x[i++] = false;
        thetaFADD  == ::thetaFADD  ? x[i++] = true : x[i++] = false;
        thetaCaspase8  == ::thetaCaspase8  ? x[i++] = true : x[i++] = false;
        thetaBak  == ::thetaBak  ? x[i++] = true : x[i++] = false;
        thetaJNK  == ::thetaJNK  ? x[i++] = true : x[i++] = false;
        thetaFOXO  == ::thetaFOXO  ? x[i++] = true : x[i++] = false;
        thetaFosJun  == ::thetaFosJun  ? x[i++] = true : x[i++] = false;
        thetaROS  == ::thetaROS  ? x[i++] = true : x[i++] = false;
        thetaAMPK  == ::thetaAMPK  ? x[i++] = true : x[i++] = false;
        thetaCytoc_APAF1  == ::thetaCytoc_APAF1  ? x[i++] = true : x[i++] = false;
        thetaCaspase9  == ::thetaCaspase9  ? x[i++] = true : x[i++] = false;
        thetaApoptosis  == ::thetaApoptosis  ? x[i++] = true : x[i++] = false;
        thetaE_cadh  == ::thetaE_cadh  ? x[i++] = true : x[i++] = false;
        thetaGlut1  == ::thetaGlut1  ? x[i++] = true : x[i++] = false;
        thetahTERT  == ::thetahTERT  ? x[i++] = true : x[i++] = false;
        thetaVEGF  == ::thetaVEGF  ? x[i++] = true : x[i++] = false;
        thetaE2F_CyclinE  == ::thetaE2F_CyclinE  ? x[i++] = true : x[i++] = false;
        thetacdh1_UbcH10  == ::thetacdh1_UbcH10  ? x[i++] = true : x[i++] = false;
        thetaTAK1  == ::thetaTAK1  ? x[i++] = true : x[i++] = false;
        thetaGSH  == ::thetaGSH  ? x[i++] = true : x[i++] = false;
        thetaTCF  == ::thetaTCF  ? x[i++] = true : x[i++] = false;
        thetaMiz1  == ::thetaMiz1  ? x[i++] = true : x[i++] = false;
        thetap70  == ::thetap70  ? x[i++] = true : x[i++] = false;
        thetaATM_ATR  == ::thetaATM_ATR  ? x[i++] = true : x[i++] = false;
        thetaCHK1_2  == ::thetaCHK1_2  ? x[i++] = true : x[i++] = false;
        thetaDNARepair  == ::thetaDNARepair  ? x[i++] = true : x[i++] = false;
        thetaeEF2K  == ::thetaeEF2K  ? x[i++] = true : x[i++] = false;
        thetaeEF2  == ::thetaeEF2  ? x[i++] = true : x[i++] = false;
        thetap53_PTEN  == ::thetap53_PTEN  ? x[i++] = true : x[i++] = false;
        thetaLDHA  == ::thetaLDHA  ? x[i++] = true : x[i++] = false;
        thetaAcidLactic  == ::thetaAcidLactic  ? x[i++] = true : x[i++] = false;
        thetaSnail == ::thetaSnail ?  x[i++] = true : x[i++] = false;
        
        for(int j = 0; j < 88; j++) if(!x[j]) printf("Achei");
    }

}


int main() {
    bool skip = false;
    int terms = 11;
    int equations = 96;
    int functionResult[equations], result = 0;
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
            functionResult[i] = function[i][0]/100;
        else
            functionResult[i] = function[i][0];
    }

    functionResult[6] = functionValue[6];                      // valores constantes
    functionResult[7] = functionValue[7];

    do {
        for (int i = 8; i < equations; i++) {
            result = 0;
            for (int j = 0; j < terms; j++) {
                if (function[i][j] >= FLAG)
                    break;
                if (function[i][j] >= 100 || function[i][j] <= -100)
                    result += function[i][j] / 100;
                else if (function[i][j] < 0)
                    result += (-1) * functionValue[abs(function[i][j])];
                else
                    result += functionValue[abs(function[i][j])];
            }
            functionResult[i] = SIGN(result);
        }
        for (int i = 8; i < equations; i++) {
            if (functionValue[i] != functionResult[i]) {
                if(DEBUG)
                    printf("trocou\n");
                for (int i = 8; i < equations; i++)
                    functionValue[i] = functionResult[i];
                skip = true;
                break;
            }
            skip = false;
        }
    }while(skip);

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