#include <iostream>
#include <omp.h>
#include  <cstdlib>
using namespace std;
#define N 3
#define SIGN(x) (x > 1) ? (short)1 : (short)0
typedef  unsigned long uint64;
typedef unsigned int uint32;

void printBin(uint32 *S0);
short getBit(int idx,uint32 v);
void setBit(int idx, short newV, uint32 *v);
short getDecValue(short v);
void pass(uint32 *S);
bool comp(uint32 *S0, uint32 *S1);
short getBlockIdx(int idx);


int main() {
    short n = 3;
    int equations = 96;
    uint32 transient = 0;
    uint32 period = 0;
    uint32 begin = 0;
    uint32 end = 1<<20;//
    uint32 S0[n],S1[n];

//    short input[equations] = {  1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0,
//                                0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1,
//                                1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0
//                            };
//
//    for (int j = 0; j <equations; j++) {
//        setBit(j,input[j],&S0[getBlockIdx(j)]);
//        setBit(j,input[j],&S1[getBlockIdx(j)]);
//    }


//
//    setBit(6,1,&S0[getBlockIdx(6)]);                       //Obrigatório
//    setBit(6,1,&S1[getBlockIdx(6)]);
//    setBit(7,1,&S0[getBlockIdx(7)]);                       //Obrigatório
//    setBit(7,1,&S1[getBlockIdx(7)]);
//    printf("SO[0] %u, S0[1] %u , S0[2] %u\n",S0[0], S0[1], S0[2]);
#pragma omp parallel private(S0,S1,period,transient) // Cada thread tem seu próprio s0 e s1 para executar a sua parte do for
#pragma omp for schedule(static)
    for (uint32 i = begin; i < end; ++i) {
        //printf("S1[0] %lu, S1[1] %lu , S1[2] %lu\n\n",S1[0], S1[1], S1[2]);
        S0[0] = S1[0] = rand() % 4294967295;
        S0[1] = S1[1] = rand() % 4294967295;
        S0[2] = S1[2] = rand() % 4294967295;
        setBit(0, 1, &S0[getBlockIdx(0)]);      // garante as entradas fixas
        setBit(1, 1, &S0[getBlockIdx(1)]);
        setBit(2, 0, &S0[getBlockIdx(2)]);
        setBit(3, 0, &S0[getBlockIdx(3)]);
        setBit(4, 0, &S0[getBlockIdx(4)]);
        setBit(5, 0, &S0[getBlockIdx(5)]);
        setBit(6, 1, &S0[getBlockIdx(6)]);
        setBit(7, 1, &S0[getBlockIdx(7)]);
        setBit(0, 1, &S1[getBlockIdx(0)]);
        setBit(1, 1, &S1[getBlockIdx(1)]);
        setBit(2, 0, &S1[getBlockIdx(2)]);
        setBit(3, 0, &S1[getBlockIdx(3)]);
        setBit(4, 0, &S1[getBlockIdx(4)]);
        setBit(5, 0, &S1[getBlockIdx(5)]);
        setBit(6, 1, &S1[getBlockIdx(6)]);
        setBit(7, 1, &S1[getBlockIdx(7)]);
        //printf("%d >",S0[0]);
        //printf("SO[0] %lu, S0[1] %lu , S0[2] %lu\n",S0[0], S0[1], S0[2]);
        transient = 0;
        period = 0;
        do{
            pass(S0);
            pass(S0);
            pass(S1);
            transient++;
        }while(!comp(S0,S1));
        do{
            pass(S0);
            period++;
        }while (!comp(S0,S1));
        period--;
        printf("%u %u %u Trans %d Per %d\n",S0[0], S0[1], S0[2],transient,period);
    }
    return 0;
}

void pass(uint32 *S) {
    uint32 Sc[N];
    for (int i = 0; i < N; ++i) {
        Sc[i] = S[i];
    }
    setBit(0,1,&S[getBlockIdx(0)]);
    setBit(1,1,&S[getBlockIdx(1)]);
    setBit(2,0,&S[getBlockIdx(2)]);
    setBit(3,0,&S[getBlockIdx(3)]);
    setBit(4,0,&S[getBlockIdx(4)]);
    setBit(5,0,&S[getBlockIdx(5)]);
    setBit(6,1,&S[getBlockIdx(6)]);
    setBit(7,1,&S[getBlockIdx(7)]);
    setBit(8,SIGN( + getDecValue(getBit(34,Sc[getBlockIdx(34)]))),&S[getBlockIdx(8)]);
    setBit(9,SIGN( + getDecValue(getBit(0,Sc[getBlockIdx(0)])) + getDecValue(getBit(71,Sc[getBlockIdx(71)]))),&S[getBlockIdx(9)]);
    setBit(10,SIGN( + getDecValue(getBit(43,Sc[getBlockIdx(43)])) + getDecValue(getBit(60,Sc[getBlockIdx(60)])) + (short)(-1)),&S[getBlockIdx(10)]);
    setBit(11,SIGN( - (getDecValue(getBit(2,Sc[getBlockIdx(2)]))) + (short) 1),&S[getBlockIdx(11)]);
    setBit(12,SIGN( - (getDecValue(getBit(13,Sc[getBlockIdx(13)]))) + (short) 1),&S[getBlockIdx(12)]);
    setBit(13,SIGN( + getDecValue(getBit(14,Sc[getBlockIdx(14)])) + getDecValue(getBit(26,Sc[getBlockIdx(26)]))),&S[getBlockIdx(13)]);
    setBit(14,SIGN( + getDecValue(getBit(1,Sc[getBlockIdx(1)]))),&S[getBlockIdx(14)]);
    setBit(15,SIGN( + getDecValue(getBit(2,Sc[getBlockIdx(2)])) - (getDecValue(getBit(4,Sc[getBlockIdx(4)])))),&S[getBlockIdx(15)]);
    setBit(16,SIGN( - (getDecValue(getBit(12,Sc[getBlockIdx(12)]))) + getDecValue(getBit(14,Sc[getBlockIdx(14)])) + (short) 1),&S[getBlockIdx(16)]);
    setBit(17,SIGN( + getDecValue(getBit(16,Sc[getBlockIdx(16)])) + getDecValue(getBit(78,Sc[getBlockIdx(78)]))),&S[getBlockIdx(17)]);
    setBit(18,SIGN( + getDecValue(getBit(17,Sc[getBlockIdx(17)])) - (getDecValue(getBit(7,Sc[getBlockIdx(7)]))) - (getDecValue(getBit(92,Sc[getBlockIdx(92)]))) + (short) 1),&S[getBlockIdx(18)]);
    setBit(19,SIGN( + getDecValue(getBit(18,Sc[getBlockIdx(18)])) + getDecValue(getBit(34,Sc[getBlockIdx(34)])) + getDecValue(getBit(38,Sc[getBlockIdx(38)]))),&S[getBlockIdx(19)]);
    setBit(20,SIGN( + getDecValue(getBit(13,Sc[getBlockIdx(13)])) + getDecValue(getBit(25,Sc[getBlockIdx(25)])) + getDecValue(getBit(33,Sc[getBlockIdx(33)])) - (getDecValue(getBit(37,Sc[getBlockIdx(37)]))) - (getDecValue(getBit(43,Sc[getBlockIdx(43)]))) + getDecValue(getBit(82,Sc[getBlockIdx(82)]))),&S[getBlockIdx(20)]);
    setBit(21,SIGN( + getDecValue(getBit(18,Sc[getBlockIdx(18)])) + getDecValue(getBit(20,Sc[getBlockIdx(20)])) + getDecValue(getBit(20,Sc[getBlockIdx(20)])) - (getDecValue(getBit(76,Sc[getBlockIdx(76)]))) + getDecValue(getBit(95,Sc[getBlockIdx(95)])) + (short)(-1)),&S[getBlockIdx(21)]);
    setBit(22,SIGN( + getDecValue(getBit(13,Sc[getBlockIdx(13)])) + getDecValue(getBit(16,Sc[getBlockIdx(16)]))),&S[getBlockIdx(22)]);
    setBit(23,SIGN( + getDecValue(getBit(22,Sc[getBlockIdx(22)]))),&S[getBlockIdx(23)]);
    setBit(24,SIGN( + getDecValue(getBit(19,Sc[getBlockIdx(19)])) + getDecValue(getBit(23,Sc[getBlockIdx(23)]))),&S[getBlockIdx(24)]);
    setBit(25,SIGN( + getDecValue(getBit(18,Sc[getBlockIdx(18)])) + getDecValue(getBit(19,Sc[getBlockIdx(19)])) + (short)(-1)),&S[getBlockIdx(25)]);
    setBit(26,SIGN( - (getDecValue(getBit(43,Sc[getBlockIdx(43)]))) + getDecValue(getBit(5,Sc[getBlockIdx(5)]))),&S[getBlockIdx(26)]);
    setBit(27,SIGN( + getDecValue(getBit(26,Sc[getBlockIdx(26)]))),&S[getBlockIdx(27)]);
    setBit(28,SIGN( + getDecValue(getBit(7,Sc[getBlockIdx(7)])) + (short) 1),&S[getBlockIdx(28)]);
    setBit(29,SIGN( - (getDecValue(getBit(24,Sc[getBlockIdx(24)]))) - (getDecValue(getBit(25,Sc[getBlockIdx(25)]))) - (getDecValue(getBit(27,Sc[getBlockIdx(27)]))) - (getDecValue(getBit(33,Sc[getBlockIdx(33)]))) + (short)3),&S[getBlockIdx(29)]);
    setBit(30,SIGN( + getDecValue(getBit(28,Sc[getBlockIdx(28)])) + getDecValue(getBit(29,Sc[getBlockIdx(29)])) + (short)(-1)),&S[getBlockIdx(30)]);
    setBit(31,SIGN( - (getDecValue(getBit(30,Sc[getBlockIdx(30)]))) - (getDecValue(getBit(43,Sc[getBlockIdx(43)]))) + (short) 1),&S[getBlockIdx(31)]);
    setBit(32,SIGN( - (getDecValue(getBit(10,Sc[getBlockIdx(10)]))) + getDecValue(getBit(21,Sc[getBlockIdx(21)])) + getDecValue(getBit(84,Sc[getBlockIdx(84)]))),&S[getBlockIdx(32)]);
    setBit(33,SIGN( + getDecValue(getBit(15,Sc[getBlockIdx(15)])) + getDecValue(getBit(25,Sc[getBlockIdx(25)])) + getDecValue(getBit(42,Sc[getBlockIdx(42)])) - (getDecValue(getBit(72,Sc[getBlockIdx(72)]))) + (short)(-1)),&S[getBlockIdx(33)]);
    setBit(34,SIGN( + getDecValue(getBit(4,Sc[getBlockIdx(4)])) + getDecValue(getBit(33,Sc[getBlockIdx(33)])) - (getDecValue(getBit(36,Sc[getBlockIdx(36)]))) - (getDecValue(getBit(36,Sc[getBlockIdx(36)]))) - (getDecValue(getBit(37,Sc[getBlockIdx(37)]))) + getDecValue(getBit(38,Sc[getBlockIdx(38)])) - (getDecValue(getBit(43,Sc[getBlockIdx(43)]))) - (getDecValue(getBit(69,Sc[getBlockIdx(69)]))) + (short)2),&S[getBlockIdx(34)]);
    setBit(35,SIGN( + getDecValue(getBit(34,Sc[getBlockIdx(34)]))),&S[getBlockIdx(35)]);
    setBit(36,SIGN( - (getDecValue(getBit(4,Sc[getBlockIdx(4)]))) - (getDecValue(getBit(71,Sc[getBlockIdx(71)]))) + (short) 1),&S[getBlockIdx(36)]);
    setBit(37,SIGN( - (getDecValue(getBit(4,Sc[getBlockIdx(4)]))) + getDecValue(getBit(71,Sc[getBlockIdx(71)])) + (short) 1),&S[getBlockIdx(37)]);
    setBit(38,SIGN( - (getDecValue(getBit(8,Sc[getBlockIdx(8)]))) + getDecValue(getBit(39,Sc[getBlockIdx(39)])) + getDecValue(getBit(6,Sc[getBlockIdx(6)])) - (getDecValue(getBit(40,Sc[getBlockIdx(40)]))) - (getDecValue(getBit(63,Sc[getBlockIdx(63)]))) + (short)(-1)),&S[getBlockIdx(38)]);
    setBit(39,SIGN( + getDecValue(getBit(21,Sc[getBlockIdx(21)])) + getDecValue(getBit(23,Sc[getBlockIdx(23)])) - (getDecValue(getBit(34,Sc[getBlockIdx(34)]))) + getDecValue(getBit(49,Sc[getBlockIdx(49)])) + getDecValue(getBit(70,Sc[getBlockIdx(70)])) + getDecValue(getBit(84,Sc[getBlockIdx(84)])) + getDecValue(getBit(5,Sc[getBlockIdx(5)])) + (short)(-1)),&S[getBlockIdx(39)]);
    setBit(40,SIGN( + getDecValue(getBit(34,Sc[getBlockIdx(34)]))),&S[getBlockIdx(40)]);
    setBit(41,SIGN( - (getDecValue(getBit(22,Sc[getBlockIdx(22)]))) - (getDecValue(getBit(23,Sc[getBlockIdx(23)]))) - (getDecValue(getBit(24,Sc[getBlockIdx(24)]))) - (getDecValue(getBit(25,Sc[getBlockIdx(25)]))) + getDecValue(getBit(34,Sc[getBlockIdx(34)])) + getDecValue(getBit(43,Sc[getBlockIdx(43)])) + getDecValue(getBit(72,Sc[getBlockIdx(72)])) + (short) 1),&S[getBlockIdx(41)]);
    setBit(42,SIGN( - (getDecValue(getBit(41,Sc[getBlockIdx(41)]))) + (short) 1),&S[getBlockIdx(42)]);
    setBit(43,SIGN( + getDecValue(getBit(34,Sc[getBlockIdx(34)])) - (getDecValue(getBit(44,Sc[getBlockIdx(44)]))) - (getDecValue(getBit(60,Sc[getBlockIdx(60)]))) + getDecValue(getBit(88,Sc[getBlockIdx(88)])) + (short) 1),&S[getBlockIdx(43)]);
    setBit(44,SIGN( + getDecValue(getBit(21,Sc[getBlockIdx(21)])) + getDecValue(getBit(21,Sc[getBlockIdx(21)])) - (getDecValue(getBit(43,Sc[getBlockIdx(43)]))) - (getDecValue(getBit(45,Sc[getBlockIdx(45)]))) - (getDecValue(getBit(46,Sc[getBlockIdx(46)])))),&S[getBlockIdx(44)]);
    setBit(45,SIGN( - (getDecValue(getBit(34,Sc[getBlockIdx(34)]))) + getDecValue(getBit(43,Sc[getBlockIdx(43)])) - (getDecValue(getBit(44,Sc[getBlockIdx(44)]))) + getDecValue(getBit(68,Sc[getBlockIdx(68)]))),&S[getBlockIdx(45)]);
    setBit(46,SIGN( - (getDecValue(getBit(22,Sc[getBlockIdx(22)]))) - (getDecValue(getBit(24,Sc[getBlockIdx(24)]))) - (getDecValue(getBit(25,Sc[getBlockIdx(25)]))) - (getDecValue(getBit(34,Sc[getBlockIdx(34)]))) + (short) 1),&S[getBlockIdx(46)]);
    setBit(47,SIGN( - (getDecValue(getBit(43,Sc[getBlockIdx(43)]))) - (getDecValue(getBit(46,Sc[getBlockIdx(46)]))) + (short) 1),&S[getBlockIdx(47)]);
    setBit(48,SIGN( - (getDecValue(getBit(51,Sc[getBlockIdx(51)]))) - (getDecValue(getBit(52,Sc[getBlockIdx(52)]))) - (getDecValue(getBit(53,Sc[getBlockIdx(53)]))) - (getDecValue(getBit(54,Sc[getBlockIdx(54)]))) - (getDecValue(getBit(60,Sc[getBlockIdx(60)]))) + (short)2),&S[getBlockIdx(48)]);
    setBit(49,SIGN( - (getDecValue(getBit(48,Sc[getBlockIdx(48)]))) - (getDecValue(getBit(48,Sc[getBlockIdx(48)]))) - (getDecValue(getBit(51,Sc[getBlockIdx(51)]))) - (getDecValue(getBit(52,Sc[getBlockIdx(52)]))) + getDecValue(getBit(49,Sc[getBlockIdx(49)])) + (short) 1),&S[getBlockIdx(49)]);
    setBit(50,SIGN( + getDecValue(getBit(16,Sc[getBlockIdx(16)])) + getDecValue(getBit(38,Sc[getBlockIdx(38)])) + getDecValue(getBit(49,Sc[getBlockIdx(49)])) + (short)(-3)),&S[getBlockIdx(50)]);
    setBit(51,SIGN( + getDecValue(getBit(51,Sc[getBlockIdx(51)])) - (getDecValue(getBit(48,Sc[getBlockIdx(48)]))) - (getDecValue(getBit(56,Sc[getBlockIdx(56)]))) - (getDecValue(getBit(58,Sc[getBlockIdx(58)]))) - (getDecValue(getBit(59,Sc[getBlockIdx(59)]))) + getDecValue(getBit(80,Sc[getBlockIdx(80)])) + getDecValue(getBit(81,Sc[getBlockIdx(81)]))),&S[getBlockIdx(51)]);
    setBit(52,SIGN( - (getDecValue(getBit(43,Sc[getBlockIdx(43)]))) - (getDecValue(getBit(55,Sc[getBlockIdx(55)]))) - (getDecValue(getBit(56,Sc[getBlockIdx(56)]))) - (getDecValue(getBit(58,Sc[getBlockIdx(58)]))) - (getDecValue(getBit(59,Sc[getBlockIdx(59)]))) + (short) 1),&S[getBlockIdx(52)]);
    setBit(53,SIGN( + getDecValue(getBit(21,Sc[getBlockIdx(21)])) - (getDecValue(getBit(29,Sc[getBlockIdx(29)]))) - (getDecValue(getBit(29,Sc[getBlockIdx(29)]))) + getDecValue(getBit(38,Sc[getBlockIdx(38)])) - (getDecValue(getBit(58,Sc[getBlockIdx(58)]))) - (getDecValue(getBit(59,Sc[getBlockIdx(59)]))) - (getDecValue(getBit(64,Sc[getBlockIdx(64)]))) - (getDecValue(getBit(69,Sc[getBlockIdx(69)]))) + getDecValue(getBit(70,Sc[getBlockIdx(70)])) + getDecValue(getBit(84,Sc[getBlockIdx(84)])) + getDecValue(getBit(5,Sc[getBlockIdx(5)]))),&S[getBlockIdx(53)]);
    setBit(54,SIGN( - (getDecValue(getBit(48,Sc[getBlockIdx(48)]))) + getDecValue(getBit(49,Sc[getBlockIdx(49)])) - (getDecValue(getBit(51,Sc[getBlockIdx(51)]))) - (getDecValue(getBit(58,Sc[getBlockIdx(58)]))) - (getDecValue(getBit(59,Sc[getBlockIdx(59)])))),&S[getBlockIdx(54)]);
    setBit(55,SIGN( - (getDecValue(getBit(51,Sc[getBlockIdx(51)]))) - (getDecValue(getBit(52,Sc[getBlockIdx(52)]))) + getDecValue(getBit(56,Sc[getBlockIdx(56)])) + (short) 1),&S[getBlockIdx(55)]);
    setBit(56,SIGN( + getDecValue(getBit(52,Sc[getBlockIdx(52)])) - (getDecValue(getBit(55,Sc[getBlockIdx(55)])))),&S[getBlockIdx(56)]);
    setBit(57,SIGN( + getDecValue(getBit(51,Sc[getBlockIdx(51)])) + getDecValue(getBit(52,Sc[getBlockIdx(52)])) - (getDecValue(getBit(55,Sc[getBlockIdx(55)]))) + getDecValue(getBit(56,Sc[getBlockIdx(56)])) + getDecValue(getBit(57,Sc[getBlockIdx(57)]))),&S[getBlockIdx(57)]);
    setBit(58,SIGN( - (getDecValue(getBit(25,Sc[getBlockIdx(25)]))) + getDecValue(getBit(34,Sc[getBlockIdx(34)])) - (getDecValue(getBit(38,Sc[getBlockIdx(38)]))) - (getDecValue(getBit(51,Sc[getBlockIdx(51)]))) - (getDecValue(getBit(52,Sc[getBlockIdx(52)]))) - (getDecValue(getBit(53,Sc[getBlockIdx(53)]))) + getDecValue(getBit(62,Sc[getBlockIdx(62)])) + (short) 1),&S[getBlockIdx(58)]);
    setBit(59,SIGN( - (getDecValue(getBit(25,Sc[getBlockIdx(25)]))) + getDecValue(getBit(34,Sc[getBlockIdx(34)])) - (getDecValue(getBit(38,Sc[getBlockIdx(38)]))) + getDecValue(getBit(43,Sc[getBlockIdx(43)])) + getDecValue(getBit(62,Sc[getBlockIdx(62)])) - (getDecValue(getBit(78,Sc[getBlockIdx(78)]))) + (short) 1),&S[getBlockIdx(59)]);
    setBit(60,SIGN( + getDecValue(getBit(25,Sc[getBlockIdx(25)])) + getDecValue(getBit(43,Sc[getBlockIdx(43)])) - (getDecValue(getBit(50,Sc[getBlockIdx(50)]))) - (getDecValue(getBit(87,Sc[getBlockIdx(87)]))) + (short) 1),&S[getBlockIdx(60)]);
    setBit(61,SIGN( + getDecValue(getBit(3,Sc[getBlockIdx(3)])) + getDecValue(getBit(8,Sc[getBlockIdx(8)]))),&S[getBlockIdx(61)]);
    setBit(62,SIGN( + getDecValue(getBit(61,Sc[getBlockIdx(61)])) + getDecValue(getBit(85,Sc[getBlockIdx(85)])) + (short)(-1)),&S[getBlockIdx(62)]);
    setBit(63,SIGN( + getDecValue(getBit(61,Sc[getBlockIdx(61)]))),&S[getBlockIdx(63)]);
    setBit(64,SIGN( + getDecValue(getBit(62,Sc[getBlockIdx(62)])) + getDecValue(getBit(85,Sc[getBlockIdx(85)]))),&S[getBlockIdx(64)]);
    setBit(65,SIGN( + getDecValue(getBit(3,Sc[getBlockIdx(3)]))),&S[getBlockIdx(65)]);
    setBit(66,SIGN( + getDecValue(getBit(65,Sc[getBlockIdx(65)]))),&S[getBlockIdx(66)]);
    setBit(67,SIGN( + getDecValue(getBit(66,Sc[getBlockIdx(66)]))),&S[getBlockIdx(67)]);
    setBit(68,SIGN( + getDecValue(getBit(8,Sc[getBlockIdx(8)]))),&S[getBlockIdx(68)]);
    setBit(69,SIGN( - (getDecValue(getBit(25,Sc[getBlockIdx(25)]))) + (short)2),&S[getBlockIdx(69)]);
    setBit(70,SIGN( + getDecValue(getBit(23,Sc[getBlockIdx(23)])) + getDecValue(getBit(68,Sc[getBlockIdx(68)]))),&S[getBlockIdx(70)]);
    setBit(71,SIGN( - (getDecValue(getBit(35,Sc[getBlockIdx(35)]))) - (getDecValue(getBit(83,Sc[getBlockIdx(83)])))),&S[getBlockIdx(71)]);
    setBit(72,SIGN( - (getDecValue(getBit(1,Sc[getBlockIdx(1)]))) + getDecValue(getBit(11,Sc[getBlockIdx(11)])) + getDecValue(getBit(34,Sc[getBlockIdx(34)])) + getDecValue(getBit(87,Sc[getBlockIdx(87)])) + (short) 1),&S[getBlockIdx(72)]);
    setBit(73,SIGN( - (getDecValue(getBit(25,Sc[getBlockIdx(25)]))) + getDecValue(getBit(43,Sc[getBlockIdx(43)])) - (getDecValue(getBit(44,Sc[getBlockIdx(44)]))) + getDecValue(getBit(45,Sc[getBlockIdx(45)])) - (getDecValue(getBit(47,Sc[getBlockIdx(47)]))) + getDecValue(getBit(66,Sc[getBlockIdx(66)])) + getDecValue(getBit(67,Sc[getBlockIdx(67)]))),&S[getBlockIdx(73)]);
    setBit(74,SIGN( + getDecValue(getBit(73,Sc[getBlockIdx(73)]))),&S[getBlockIdx(74)]);
    setBit(75,SIGN( + getDecValue(getBit(66,Sc[getBlockIdx(66)])) + getDecValue(getBit(74,Sc[getBlockIdx(74)]))),&S[getBlockIdx(75)]);
    setBit(76,SIGN( - (getDecValue(getBit(21,Sc[getBlockIdx(21)]))) - (getDecValue(getBit(32,Sc[getBlockIdx(32)]))) - (getDecValue(getBit(95,Sc[getBlockIdx(95)]))) + (short)3),&S[getBlockIdx(76)]);
    setBit(77,SIGN( + getDecValue(getBit(25,Sc[getBlockIdx(25)])) + getDecValue(getBit(34,Sc[getBlockIdx(34)])) + getDecValue(getBit(38,Sc[getBlockIdx(38)])) + (short)(-1)),&S[getBlockIdx(77)]);
    setBit(78,SIGN( + getDecValue(getBit(12,Sc[getBlockIdx(12)])) + getDecValue(getBit(21,Sc[getBlockIdx(21)])) + getDecValue(getBit(25,Sc[getBlockIdx(25)])) + getDecValue(getBit(34,Sc[getBlockIdx(34)])) + getDecValue(getBit(38,Sc[getBlockIdx(38)])) - (getDecValue(getBit(43,Sc[getBlockIdx(43)]))) - (getDecValue(getBit(62,Sc[getBlockIdx(62)]))) - (getDecValue(getBit(91,Sc[getBlockIdx(91)]))) + (short)(-4)),&S[getBlockIdx(78)]);
    setBit(79,SIGN( + getDecValue(getBit(34,Sc[getBlockIdx(34)])) + getDecValue(getBit(38,Sc[getBlockIdx(38)]))),&S[getBlockIdx(79)]);
    setBit(80,SIGN( + getDecValue(getBit(49,Sc[getBlockIdx(49)])) + getDecValue(getBit(54,Sc[getBlockIdx(54)])) + (short)(-1)),&S[getBlockIdx(80)]);
    setBit(81,SIGN( + getDecValue(getBit(55,Sc[getBlockIdx(55)])) + getDecValue(getBit(57,Sc[getBlockIdx(57)])) + (short)(-1)),&S[getBlockIdx(81)]);
    setBit(82,SIGN( + getDecValue(getBit(3,Sc[getBlockIdx(3)]))),&S[getBlockIdx(82)]);
    setBit(83,SIGN( + getDecValue(getBit(21,Sc[getBlockIdx(21)])) + getDecValue(getBit(38,Sc[getBlockIdx(38)])) + getDecValue(getBit(59,Sc[getBlockIdx(59)]))),&S[getBlockIdx(83)]);
    setBit(84,SIGN( + getDecValue(getBit(31,Sc[getBlockIdx(31)])) - (getDecValue(getBit(82,Sc[getBlockIdx(82)])))),&S[getBlockIdx(84)]);
    setBit(85,SIGN( - (getDecValue(getBit(38,Sc[getBlockIdx(38)]))) + (short) 1),&S[getBlockIdx(85)]);
    setBit(86,SIGN( + getDecValue(getBit(19,Sc[getBlockIdx(19)])) + getDecValue(getBit(33,Sc[getBlockIdx(33)]))),&S[getBlockIdx(86)]);
    setBit(87,SIGN( + getDecValue(getBit(9,Sc[getBlockIdx(9)]))),&S[getBlockIdx(87)]);
    setBit(88,SIGN( + getDecValue(getBit(87,Sc[getBlockIdx(87)]))),&S[getBlockIdx(88)]);
    setBit(89,SIGN( + getDecValue(getBit(87,Sc[getBlockIdx(87)]))),&S[getBlockIdx(89)]);
    setBit(90,SIGN( + getDecValue(getBit(24,Sc[getBlockIdx(24)])) + getDecValue(getBit(86,Sc[getBlockIdx(86)]))),&S[getBlockIdx(90)]);
    setBit(91,SIGN( - (getDecValue(getBit(90,Sc[getBlockIdx(90)]))) + (short) 1),&S[getBlockIdx(91)]);
    setBit(92,SIGN( + getDecValue(getBit(7,Sc[getBlockIdx(7)])) + getDecValue(getBit(43,Sc[getBlockIdx(43)])) + (short)(-1)),&S[getBlockIdx(92)]);
    setBit(93,SIGN( + getDecValue(getBit(34,Sc[getBlockIdx(34)])) + getDecValue(getBit(38,Sc[getBlockIdx(38)])) + (short)(-1)),&S[getBlockIdx(93)]);
    setBit(94,SIGN( + getDecValue(getBit(93,Sc[getBlockIdx(93)]))),&S[getBlockIdx(94)]);
    setBit(95,SIGN( + getDecValue(getBit(21,Sc[getBlockIdx(21)])) - (getDecValue(getBit(29,Sc[getBlockIdx(29)]))) - (getDecValue(getBit(43,Sc[getBlockIdx(43)]))) + getDecValue(getBit(61,Sc[getBlockIdx(61)])) + (short)(-1)),&S[getBlockIdx(95)]);
}

bool comp(uint32 *S0, uint32 *S1){
    for (int i = 0; i < N; ++i) {
        if(S1[i] != S0[i])
            return false;
    }
    return true;
}

short getDecValue(short v){
    return v? v:(short)-1;
}

short getBit(int idx,uint32 v){
    idx = idx % 32;
    return (short)((v >> idx) & 1);
}

void setBit(int idx, short newV, uint32 *v){
    idx = idx % 32;
    *v &= ~(1 << idx);
    *v |= ((uint32)newV << idx);
}


short getBlockIdx(int idx){
    if(idx<32)
        return 0;
    else if(idx>63)
        return 2;
    else
        return 1;
}


void printBin(uint32 *S0){
    for (int l = 0; l < 96; ++l) {
        if((l%32) == 0)
            printf("\n");
        printf("%u",getBit(l%32,S0[getBlockIdx(l)]));

    }
}
