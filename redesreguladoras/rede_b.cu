#include <iostream>
#include <cuda_runtime.h>
#include <curand.h>
#include <curand_kernel.h>

#define SIGN(x) (x > 1) ? 1 : ((x < -1) ? -1 : x)
#define NUM_STATES (1<<20)
#define NUM_COPYS  (1 << 10)
#define NUM_NOS 96
#define N 3

using namespace std;
typedef unsigned long uint64;

__device__
bool comp(uint64 *S0, uint64 *S1){
    for (int i = 0; i < N; ++i) {
        if(S1[i] != S0[i])
            return false;
    }
    return true;
}

__device__
short getDecValue(short v){
    short vp = 0;
    switch(v){
        case 0:
        case 2: vp = 0;
            break;
        case 1: vp = 1;
            break;
        case 3: vp = -1;
            break;
    }
    return vp;
}

__device__
short get2bit(short idx, uint64 v){
    idx = idx*2;
    return (v >> idx) & 3;
}

__device__
void set2bit(short idx, short newV, uint64 *v){
    uint64 mask = 3;
    idx = idx*2;
    newV = (newV == -1) ? 3 : newV;
    *v &= ~(mask << idx);
    *v |= ((uint64) newV << idx);
}

__device__
short getBlockIdx(short idx){
    idx = idx*2;
    if(idx<64)
        return 0;
    else if(idx>127)
        return 2;
    else
        return 1;
}

__device__
void pass(uint64 *S) {
    uint64 Sc[N];
    for (int i = 0; i < N; ++i) {
        Sc[i] = S[i];
    }
    set2bit(0,1, &S[getBlockIdx(0)]);
    set2bit(1,1, &S[getBlockIdx(1)]);
    set2bit(2,-1, &S[getBlockIdx(2)]);
    set2bit(3,0, &S[getBlockIdx(3)]);
    set2bit(4,-1, &S[getBlockIdx(4)]);
    set2bit(5,0, &S[getBlockIdx(5)]);
    set2bit(6,1, &S[getBlockIdx(6)]);
    set2bit(7,1, &S[getBlockIdx(7)]);
    set2bit(8,SIGN( + getDecValue(get2bit(34, Sc[getBlockIdx(34)]))), &S[getBlockIdx(8)]);
    set2bit(9,SIGN( + getDecValue(get2bit(0, Sc[getBlockIdx(0)])) + getDecValue(get2bit(71, Sc[getBlockIdx(71)]))), &S[getBlockIdx(9)]);
    set2bit(10,SIGN( + getDecValue(get2bit(43, Sc[getBlockIdx(43)])) + getDecValue(get2bit(60, Sc[getBlockIdx(60)])) + (-1)), &S[getBlockIdx(10)]);
    set2bit(11,SIGN( - (getDecValue(get2bit(2, Sc[getBlockIdx(2)]))) + 1), &S[getBlockIdx(11)]);
    set2bit(12,SIGN( - (getDecValue(get2bit(13, Sc[getBlockIdx(13)]))) + 1), &S[getBlockIdx(12)]);
    set2bit(13,SIGN( + getDecValue(get2bit(14, Sc[getBlockIdx(14)])) + getDecValue(get2bit(26, Sc[getBlockIdx(26)]))), &S[getBlockIdx(13)]);
    set2bit(14,SIGN( + getDecValue(get2bit(1, Sc[getBlockIdx(1)]))), &S[getBlockIdx(14)]);
    set2bit(15,SIGN( + getDecValue(get2bit(2, Sc[getBlockIdx(2)])) - (getDecValue(get2bit(4,Sc[getBlockIdx(4)])))),&S[getBlockIdx(15)]);
    set2bit(16,SIGN( - (getDecValue(get2bit(12, Sc[getBlockIdx(12)]))) + getDecValue(get2bit(14,Sc[getBlockIdx(14)])) + 1),&S[getBlockIdx(16)]);
    set2bit(17,SIGN( + getDecValue(get2bit(16, Sc[getBlockIdx(16)])) + getDecValue(get2bit(78,Sc[getBlockIdx(78)]))),&S[getBlockIdx(17)]);
    set2bit(18,SIGN( + getDecValue(get2bit(17, Sc[getBlockIdx(17)])) - (getDecValue(get2bit(7,Sc[getBlockIdx(7)]))) - (getDecValue(get2bit(92, Sc[getBlockIdx(92)]))) + 1), &S[getBlockIdx(18)]);
    set2bit(19,SIGN( + getDecValue(get2bit(18, Sc[getBlockIdx(18)])) + getDecValue(get2bit(34,Sc[getBlockIdx(34)])) + getDecValue(get2bit(38, Sc[getBlockIdx(38)]))), &S[getBlockIdx(19)]);
    set2bit(20,SIGN( + getDecValue(get2bit(13,Sc[getBlockIdx(13)])) + getDecValue(get2bit(25,Sc[getBlockIdx(25)])) + getDecValue(get2bit(33, Sc[getBlockIdx(33)])) - (getDecValue(get2bit(37,Sc[getBlockIdx(37)]))) - (getDecValue(get2bit(43,Sc[getBlockIdx(43)]))) + getDecValue(get2bit(82,Sc[getBlockIdx(82)]))),&S[getBlockIdx(20)]);
    set2bit(21,SIGN( + getDecValue(get2bit(18,Sc[getBlockIdx(18)])) + getDecValue(get2bit(20,Sc[getBlockIdx(20)])) + getDecValue(get2bit(20, Sc[getBlockIdx(20)])) - (getDecValue(get2bit(76,Sc[getBlockIdx(76)]))) + getDecValue(get2bit(95,Sc[getBlockIdx(95)])) + (-1)),&S[getBlockIdx(21)]);
    set2bit(22,SIGN( + getDecValue(get2bit(13,Sc[getBlockIdx(13)])) + getDecValue(get2bit(16,Sc[getBlockIdx(16)]))), &S[getBlockIdx(22)]);
    set2bit(23,SIGN( + getDecValue(get2bit(22,Sc[getBlockIdx(22)]))), &S[getBlockIdx(23)]);
    set2bit(24,SIGN( + getDecValue(get2bit(19,Sc[getBlockIdx(19)])) + getDecValue(get2bit(23,Sc[getBlockIdx(23)]))),&S[getBlockIdx(24)]);
    set2bit(25,SIGN( + getDecValue(get2bit(18,Sc[getBlockIdx(18)])) + getDecValue(get2bit(19,Sc[getBlockIdx(19)])) + (-1)),&S[getBlockIdx(25)]);
    set2bit(26,SIGN( - (getDecValue(get2bit(43,Sc[getBlockIdx(43)]))) + getDecValue(get2bit(5,Sc[getBlockIdx(5)]))),&S[getBlockIdx(26)]);
    set2bit(27,SIGN( + getDecValue(get2bit(26,Sc[getBlockIdx(26)]))), &S[getBlockIdx(27)]);
    set2bit(28,SIGN( + getDecValue(get2bit(7,Sc[getBlockIdx(7)])) + 1), &S[getBlockIdx(28)]);
    set2bit(29,SIGN( - (getDecValue(get2bit(24,Sc[getBlockIdx(24)]))) - (getDecValue(get2bit(25,Sc[getBlockIdx(25)]))) - (getDecValue(get2bit(27,Sc[getBlockIdx(27)]))) - (getDecValue(get2bit(33,Sc[getBlockIdx(33)]))) + 3),&S[getBlockIdx(29)]);
    set2bit(30,SIGN( + getDecValue(get2bit(28,Sc[getBlockIdx(28)])) + getDecValue(get2bit(29,Sc[getBlockIdx(29)])) + (-1)),&S[getBlockIdx(30)]);
    set2bit(31,SIGN( - (getDecValue(get2bit(30,Sc[getBlockIdx(30)]))) - (getDecValue(get2bit(43,Sc[getBlockIdx(43)]))) + 1),&S[getBlockIdx(31)]);
    set2bit(32,SIGN( - (getDecValue(get2bit(10,Sc[getBlockIdx(10)]))) + getDecValue(get2bit(21,Sc[getBlockIdx(21)])) + getDecValue(get2bit(84,Sc[getBlockIdx(84)]))),&S[getBlockIdx(32)]);
    set2bit(33,SIGN( + getDecValue(get2bit(15,Sc[getBlockIdx(15)])) + getDecValue(get2bit(25,Sc[getBlockIdx(25)])) + getDecValue(get2bit(42,Sc[getBlockIdx(42)])) - (getDecValue(get2bit(72,Sc[getBlockIdx(72)]))) + (-1)),&S[getBlockIdx(33)]);
    set2bit(34,SIGN( + getDecValue(get2bit(4,Sc[getBlockIdx(4)])) + getDecValue(get2bit(33,Sc[getBlockIdx(33)])) - (getDecValue(get2bit(36,Sc[getBlockIdx(36)]))) - (getDecValue(get2bit(36,Sc[getBlockIdx(36)]))) - (getDecValue(get2bit(37,Sc[getBlockIdx(37)]))) + getDecValue(get2bit(38,Sc[getBlockIdx(38)])) - (getDecValue(get2bit(43,Sc[getBlockIdx(43)]))) - (getDecValue(get2bit(69,Sc[getBlockIdx(69)]))) + 2),&S[getBlockIdx(34)]);
    set2bit(35,SIGN( + getDecValue(get2bit(34,Sc[getBlockIdx(34)]))), &S[getBlockIdx(35)]);
    set2bit(36,SIGN( - (getDecValue(get2bit(4,Sc[getBlockIdx(4)]))) - (getDecValue(get2bit(71,Sc[getBlockIdx(71)]))) + 1),&S[getBlockIdx(36)]);
    set2bit(37,SIGN( - (getDecValue(get2bit(4,Sc[getBlockIdx(4)]))) + getDecValue(get2bit(71,Sc[getBlockIdx(71)])) + 1),&S[getBlockIdx(37)]);
    set2bit(38,SIGN( - (getDecValue(get2bit(8,Sc[getBlockIdx(8)]))) + getDecValue(get2bit(39,Sc[getBlockIdx(39)])) + getDecValue(get2bit(6,Sc[getBlockIdx(6)])) - (getDecValue(get2bit(40,Sc[getBlockIdx(40)]))) - (getDecValue(get2bit(63,Sc[getBlockIdx(63)]))) + (-1)),&S[getBlockIdx(38)]);
    set2bit(39,SIGN( + getDecValue(get2bit(21,Sc[getBlockIdx(21)])) + getDecValue(get2bit(23,Sc[getBlockIdx(23)])) - (getDecValue(get2bit(34,Sc[getBlockIdx(34)]))) + getDecValue(get2bit(49,Sc[getBlockIdx(49)])) + getDecValue(get2bit(70,Sc[getBlockIdx(70)])) + getDecValue(get2bit(84,Sc[getBlockIdx(84)])) + getDecValue(get2bit(5,Sc[getBlockIdx(5)])) + (-1)),&S[getBlockIdx(39)]);
    set2bit(40,SIGN( + getDecValue(get2bit(34,Sc[getBlockIdx(34)]))),&S[getBlockIdx(40)]);
    set2bit(41,SIGN( - (getDecValue(get2bit(22,Sc[getBlockIdx(22)]))) - (getDecValue(get2bit(23,Sc[getBlockIdx(23)]))) - (getDecValue(get2bit(24,Sc[getBlockIdx(24)]))) - (getDecValue(get2bit(25,Sc[getBlockIdx(25)]))) + getDecValue(get2bit(34,Sc[getBlockIdx(34)])) + getDecValue(get2bit(43,Sc[getBlockIdx(43)])) + getDecValue(get2bit(72,Sc[getBlockIdx(72)])) + 1),&S[getBlockIdx(41)]);
    set2bit(42,SIGN( - (getDecValue(get2bit(41,Sc[getBlockIdx(41)]))) + 1), &S[getBlockIdx(42)]);
    set2bit(43,SIGN( + getDecValue(get2bit(34,Sc[getBlockIdx(34)])) - (getDecValue(get2bit(44,Sc[getBlockIdx(44)]))) - (getDecValue(get2bit(60,Sc[getBlockIdx(60)]))) + getDecValue(get2bit(88,Sc[getBlockIdx(88)])) + 1),&S[getBlockIdx(43)]);
    set2bit(44,SIGN( + getDecValue(get2bit(21,Sc[getBlockIdx(21)])) + getDecValue(get2bit(21,Sc[getBlockIdx(21)])) - (getDecValue(get2bit(43,Sc[getBlockIdx(43)]))) - (getDecValue(get2bit(45,Sc[getBlockIdx(45)]))) - (getDecValue(get2bit(46,Sc[getBlockIdx(46)])))),&S[getBlockIdx(44)]);
    set2bit(45,SIGN( - (getDecValue(get2bit(34,Sc[getBlockIdx(34)]))) + getDecValue(get2bit(43,Sc[getBlockIdx(43)])) - (getDecValue(get2bit(44,Sc[getBlockIdx(44)]))) + getDecValue(get2bit(68,Sc[getBlockIdx(68)]))),&S[getBlockIdx(45)]);
    set2bit(46,SIGN( - (getDecValue(get2bit(22,Sc[getBlockIdx(22)]))) - (getDecValue(get2bit(24,Sc[getBlockIdx(24)]))) - (getDecValue(get2bit(25,Sc[getBlockIdx(25)]))) - (getDecValue(get2bit(34,Sc[getBlockIdx(34)]))) + 1),&S[getBlockIdx(46)]);
    set2bit(47,SIGN( - (getDecValue(get2bit(43,Sc[getBlockIdx(43)]))) - (getDecValue(get2bit(46,Sc[getBlockIdx(46)]))) + 1),&S[getBlockIdx(47)]);
    set2bit(48,SIGN( - (getDecValue(get2bit(51,Sc[getBlockIdx(51)]))) - (getDecValue(get2bit(52,Sc[getBlockIdx(52)]))) - (getDecValue(get2bit(53,Sc[getBlockIdx(53)]))) - (getDecValue(get2bit(54,Sc[getBlockIdx(54)]))) - (getDecValue(get2bit(60,Sc[getBlockIdx(60)]))) + 2),&S[getBlockIdx(48)]);
    set2bit(49,SIGN( - (getDecValue(get2bit(48,Sc[getBlockIdx(48)]))) - (getDecValue(get2bit(48,Sc[getBlockIdx(48)]))) - (getDecValue(get2bit(51,Sc[getBlockIdx(51)]))) - (getDecValue(get2bit(52,Sc[getBlockIdx(52)]))) + getDecValue(get2bit(49,Sc[getBlockIdx(49)])) + 1),&S[getBlockIdx(49)]);
    set2bit(50,SIGN( + getDecValue(get2bit(16,Sc[getBlockIdx(16)])) + getDecValue(get2bit(38,Sc[getBlockIdx(38)])) + getDecValue(get2bit(49,Sc[getBlockIdx(49)])) + (-3)),&S[getBlockIdx(50)]);
    set2bit(51,SIGN( + getDecValue(get2bit(51,Sc[getBlockIdx(51)])) - (getDecValue(get2bit(48,Sc[getBlockIdx(48)]))) - (getDecValue(get2bit(56,Sc[getBlockIdx(56)]))) - (getDecValue(get2bit(58,Sc[getBlockIdx(58)]))) - (getDecValue(get2bit(59,Sc[getBlockIdx(59)]))) + getDecValue(get2bit(80,Sc[getBlockIdx(80)])) + getDecValue(get2bit(81,Sc[getBlockIdx(81)]))),&S[getBlockIdx(51)]);
    set2bit(52,SIGN( - (getDecValue(get2bit(43,Sc[getBlockIdx(43)]))) - (getDecValue(get2bit(55,Sc[getBlockIdx(55)]))) - (getDecValue(get2bit(56,Sc[getBlockIdx(56)]))) - (getDecValue(get2bit(58,Sc[getBlockIdx(58)]))) - (getDecValue(get2bit(59,Sc[getBlockIdx(59)]))) + 1),&S[getBlockIdx(52)]);
    set2bit(53,SIGN( + getDecValue(get2bit(21,Sc[getBlockIdx(21)])) - (getDecValue(get2bit(29,Sc[getBlockIdx(29)]))) - (getDecValue(get2bit(29,Sc[getBlockIdx(29)]))) + getDecValue(get2bit(38,Sc[getBlockIdx(38)])) - (getDecValue(get2bit(58,Sc[getBlockIdx(58)]))) - (getDecValue(get2bit(59,Sc[getBlockIdx(59)]))) - (getDecValue(get2bit(64,Sc[getBlockIdx(64)]))) - (getDecValue(get2bit(69,Sc[getBlockIdx(69)]))) + getDecValue(get2bit(70,Sc[getBlockIdx(70)])) + getDecValue(get2bit(84,Sc[getBlockIdx(84)])) + getDecValue(get2bit(5,Sc[getBlockIdx(5)]))),&S[getBlockIdx(53)]);
    set2bit(54,SIGN( - (getDecValue(get2bit(48,Sc[getBlockIdx(48)]))) + getDecValue(get2bit(49,Sc[getBlockIdx(49)])) - (getDecValue(get2bit(51,Sc[getBlockIdx(51)]))) - (getDecValue(get2bit(58,Sc[getBlockIdx(58)]))) - (getDecValue(get2bit(59,Sc[getBlockIdx(59)])))),&S[getBlockIdx(54)]);
    set2bit(55,SIGN( - (getDecValue(get2bit(51,Sc[getBlockIdx(51)]))) - (getDecValue(get2bit(52,Sc[getBlockIdx(52)]))) + getDecValue(get2bit(56,Sc[getBlockIdx(56)])) + 1),&S[getBlockIdx(55)]);
    set2bit(56,SIGN( + getDecValue(get2bit(52,Sc[getBlockIdx(52)])) - (getDecValue(get2bit(55,Sc[getBlockIdx(55)])))), &S[getBlockIdx(56)]);
    set2bit(57,SIGN( + getDecValue(get2bit(51,Sc[getBlockIdx(51)])) + getDecValue(get2bit(52,Sc[getBlockIdx(52)])) - (getDecValue(get2bit(55,Sc[getBlockIdx(55)]))) + getDecValue(get2bit(56,Sc[getBlockIdx(56)])) + getDecValue(get2bit(57,Sc[getBlockIdx(57)]))),&S[getBlockIdx(57)]);
    set2bit(58,SIGN( - (getDecValue(get2bit(25,Sc[getBlockIdx(25)]))) + getDecValue(get2bit(34,Sc[getBlockIdx(34)])) - (getDecValue(get2bit(38,Sc[getBlockIdx(38)]))) - (getDecValue(get2bit(51,Sc[getBlockIdx(51)]))) - (getDecValue(get2bit(52,Sc[getBlockIdx(52)]))) - (getDecValue(get2bit(53,Sc[getBlockIdx(53)]))) + getDecValue(get2bit(62,Sc[getBlockIdx(62)])) + 1),&S[getBlockIdx(58)]);
    set2bit(59,SIGN( - (getDecValue(get2bit(25,Sc[getBlockIdx(25)]))) + getDecValue(get2bit(34,Sc[getBlockIdx(34)])) - (getDecValue(get2bit(38,Sc[getBlockIdx(38)]))) + getDecValue(get2bit(43,Sc[getBlockIdx(43)])) + getDecValue(get2bit(62,Sc[getBlockIdx(62)])) - (getDecValue(get2bit(78,Sc[getBlockIdx(78)]))) + 1),&S[getBlockIdx(59)]);
    set2bit(60,SIGN( + getDecValue(get2bit(25,Sc[getBlockIdx(25)])) + getDecValue(get2bit(43,Sc[getBlockIdx(43)])) - (getDecValue(get2bit(50,Sc[getBlockIdx(50)]))) - (getDecValue(get2bit(87,Sc[getBlockIdx(87)]))) + 1),&S[getBlockIdx(60)]);
    set2bit(61,SIGN( + getDecValue(get2bit(3,Sc[getBlockIdx(3)])) + getDecValue(get2bit(8,Sc[getBlockIdx(8)]))),&S[getBlockIdx(61)]);
    set2bit(62,SIGN( + getDecValue(get2bit(61,Sc[getBlockIdx(61)])) + getDecValue(get2bit(85,Sc[getBlockIdx(85)])) + (-1)),&S[getBlockIdx(62)]);
    set2bit(63,SIGN( + getDecValue(get2bit(61,Sc[getBlockIdx(61)]))), &S[getBlockIdx(63)]);
    set2bit(64,SIGN( + getDecValue(get2bit(62,Sc[getBlockIdx(62)])) + getDecValue(get2bit(85,Sc[getBlockIdx(85)]))),&S[getBlockIdx(64)]);
    set2bit(65,SIGN( + getDecValue(get2bit(3,Sc[getBlockIdx(3)]))), &S[getBlockIdx(65)]);
    set2bit(66,SIGN( + getDecValue(get2bit(65,Sc[getBlockIdx(65)]))), &S[getBlockIdx(66)]);
    set2bit(67,SIGN( + getDecValue(get2bit(66,Sc[getBlockIdx(66)]))), &S[getBlockIdx(67)]);
    set2bit(68,SIGN( + getDecValue(get2bit(8,Sc[getBlockIdx(8)]))),&S[getBlockIdx(68)]);
    set2bit(69,SIGN( - (getDecValue(get2bit(25,Sc[getBlockIdx(25)]))) + 2), &S[getBlockIdx(69)]);
    set2bit(70,SIGN( + getDecValue(get2bit(23,Sc[getBlockIdx(23)])) + getDecValue(get2bit(68,Sc[getBlockIdx(68)]))), &S[getBlockIdx(70)]);
    set2bit(71,SIGN( - (getDecValue(get2bit(35,Sc[getBlockIdx(35)]))) - (getDecValue(get2bit(83,Sc[getBlockIdx(83)])))), &S[getBlockIdx(71)]);
    set2bit(72,SIGN( - (getDecValue(get2bit(1,Sc[getBlockIdx(1)]))) + getDecValue(get2bit(11,Sc[getBlockIdx(11)])) + getDecValue(get2bit(34,Sc[getBlockIdx(34)])) + getDecValue(get2bit(87,Sc[getBlockIdx(87)])) + 1),&S[getBlockIdx(72)]);
    set2bit(73,SIGN( - (getDecValue(get2bit(25,Sc[getBlockIdx(25)]))) + getDecValue(get2bit(43,Sc[getBlockIdx(43)])) - (getDecValue(get2bit(44,Sc[getBlockIdx(44)]))) + getDecValue(get2bit(45,Sc[getBlockIdx(45)])) - (getDecValue(get2bit(47,Sc[getBlockIdx(47)]))) + getDecValue(get2bit(66,Sc[getBlockIdx(66)])) + getDecValue(get2bit(67,Sc[getBlockIdx(67)]))),&S[getBlockIdx(73)]);
    set2bit(74,SIGN( + getDecValue(get2bit(73,Sc[getBlockIdx(73)]))), &S[getBlockIdx(74)]);
    set2bit(75,SIGN( + getDecValue(get2bit(66,Sc[getBlockIdx(66)])) + getDecValue(get2bit(74,Sc[getBlockIdx(74)]))),&S[getBlockIdx(75)]);
    set2bit(76,SIGN( - (getDecValue(get2bit(21,Sc[getBlockIdx(21)]))) - (getDecValue(get2bit(32,Sc[getBlockIdx(32)]))) - (getDecValue(get2bit(95,Sc[getBlockIdx(95)]))) + 3),&S[getBlockIdx(76)]);
    set2bit(77,SIGN( + getDecValue(get2bit(25,Sc[getBlockIdx(25)])) + getDecValue(get2bit(34,Sc[getBlockIdx(34)])) + getDecValue(get2bit(38,Sc[getBlockIdx(38)])) + (-1)),&S[getBlockIdx(77)]);
    set2bit(78,SIGN( + getDecValue(get2bit(12,Sc[getBlockIdx(12)])) + getDecValue(get2bit(21,Sc[getBlockIdx(21)])) + getDecValue(get2bit(25,Sc[getBlockIdx(25)])) + getDecValue(get2bit(34,Sc[getBlockIdx(34)])) + getDecValue(get2bit(38,Sc[getBlockIdx(38)])) - (getDecValue(get2bit(43,Sc[getBlockIdx(43)]))) - (getDecValue(get2bit(62,Sc[getBlockIdx(62)]))) - (getDecValue(get2bit(91,Sc[getBlockIdx(91)]))) + (-4)),&S[getBlockIdx(78)]);
    set2bit(79,SIGN( + getDecValue(get2bit(34,Sc[getBlockIdx(34)])) + getDecValue(get2bit(38,Sc[getBlockIdx(38)]))),&S[getBlockIdx(79)]);
    set2bit(80,SIGN( + getDecValue(get2bit(49,Sc[getBlockIdx(49)])) + getDecValue(get2bit(54,Sc[getBlockIdx(54)])) + (-1)),&S[getBlockIdx(80)]);
    set2bit(81,SIGN( + getDecValue(get2bit(55,Sc[getBlockIdx(55)])) + getDecValue(get2bit(57,Sc[getBlockIdx(57)])) + (-1)),&S[getBlockIdx(81)]);
    set2bit(82,SIGN( + getDecValue(get2bit(3,Sc[getBlockIdx(3)]))),&S[getBlockIdx(82)]);
    set2bit(83,SIGN( + getDecValue(get2bit(21,Sc[getBlockIdx(21)])) + getDecValue(get2bit(38,Sc[getBlockIdx(38)])) + getDecValue(get2bit(59, Sc[getBlockIdx(59)]))), &S[getBlockIdx(83)]);
    set2bit(84,SIGN( + getDecValue(get2bit(31,Sc[getBlockIdx(31)])) - (getDecValue(get2bit(82,Sc[getBlockIdx(82)])))), &S[getBlockIdx(84)]);
    set2bit(85,SIGN( - (getDecValue(get2bit(38,Sc[getBlockIdx(38)]))) + 1), &S[getBlockIdx(85)]);
    set2bit(86,SIGN( + getDecValue(get2bit(19,Sc[getBlockIdx(19)])) + getDecValue(get2bit(33,Sc[getBlockIdx(33)]))), &S[getBlockIdx(86)]);
    set2bit(87,SIGN( + getDecValue(get2bit(9,Sc[getBlockIdx(9)]))), &S[getBlockIdx(87)]);
    set2bit(88,SIGN( + getDecValue(get2bit(87,Sc[getBlockIdx(87)]))), &S[getBlockIdx(88)]);
    set2bit(89,SIGN( + getDecValue(get2bit(87,Sc[getBlockIdx(87)]))), &S[getBlockIdx(89)]);
    set2bit(90,SIGN( + getDecValue(get2bit(24,Sc[getBlockIdx(24)])) + getDecValue(get2bit(86,Sc[getBlockIdx(86)]))), &S[getBlockIdx(90)]);
    set2bit(91,SIGN( - (getDecValue(get2bit(90,Sc[getBlockIdx(90)]))) + 1), &S[getBlockIdx(91)]);
    set2bit(92,SIGN( + getDecValue(get2bit(7,Sc[getBlockIdx(7)])) + getDecValue(get2bit(43, Sc[getBlockIdx(43)])) + (-1)), &S[getBlockIdx(92)]);
    set2bit(93,SIGN( + getDecValue(get2bit(34,Sc[getBlockIdx(34)])) + getDecValue(get2bit(38, Sc[getBlockIdx(38)])) + (-1)), &S[getBlockIdx(93)]);
    set2bit(94,SIGN( + getDecValue(get2bit(93,Sc[getBlockIdx(93)]))), &S[getBlockIdx(94)]);
    set2bit(95,SIGN( + getDecValue(get2bit(21,Sc[getBlockIdx(21)])) - (getDecValue(get2bit(29, Sc[getBlockIdx(29)]))) - (getDecValue(get2bit(43,Sc[getBlockIdx(43)]))) + getDecValue(get2bit(61,Sc[getBlockIdx(61)])) + (-1)),&S[getBlockIdx(95)]);
}

__global__
void findAttractor(uint64 *attractors, uint32_t *transients, uint32_t *periods, uint32_t numThreads){
    int transient = 0, period = 0;
    uint64 S0[N], S1[N];
    uint32_t thread = blockDim.x * blockIdx.x + threadIdx.x;
    uint32_t step =  NUM_STATES / NUM_COPYS; 
    uint32_t rest =  NUM_STATES % NUM_COPYS;
    uint32_t begin = 0;
    uint32_t end = step - 1;
    
    curandState_t state;
	curand_init(thread, /* the seed controls the sequence of random values that are produced */
              0, /* the sequence number is only important with multiple cores */
              0, /* the offset is how much extra we advance in the sequence for each call, can be 0 */
              &state);
              
    bool flag = true;
    
    if(thread < numThreads){
        if(rest > 0){
            end = end + 1;
            rest = rest - 1;
        }else{
        	flag = false;
        }
        
        
        for(uint32_t i = 0; i < NUM_COPYS;i++){
            if(i == thread) break;
            
			if(rest > 0){
                end = end + 1;
                begin = begin + 1;
                rest = rest - 1;
            }else if(rest == 0 && flag){
                begin = begin + 1;
                flag = 0;
            }
            begin += step;
            end += step;
        }

	    for (int i = begin; i < end; ++i) {
	        S0[0] = S1[0] = thread;
	        int x = curand(&state) % 2;
	        int y = curand(&state) % 2;
	        int x_s = curand(&state) % 2;
	        int y_s = curand(&state) % 2;
	        S0[1] = S1[1] =  (x_s) ? x_s*x : x;// inicializar com rand
	        S0[2] = S1[2] = (y_s) ? y_s*y : y;// inicializar com rand
			set2bit(6, 1, &S0[getBlockIdx(6)]);      //ObrigatÃ³rio **Conferir se esta setando o bit certo**
	    	set2bit(7, 1, &S1[getBlockIdx(7)]);      //ObrigatÃ³rio **Conferir se esta setando o bit certo**
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
	        
	        transients[i] = transient;
	        periods[i]= period;
	        for(int s = 0; s < N; s++){
	            attractors[i * N + s] = S0[s];
	        }
	        //cout << transient << " " << period << std::endl;
	    }
	}	
}

int main() {
	// Error code to check return values for CUDA calls
    cudaError_t err = cudaSuccess;
    // Print the vector length to be used, and compute its size
    size_t numNos = NUM_NOS;
    size_t numState = NUM_STATES;
    size_t size = numNos * numState * sizeof(bool);
    size_t size_transients = numState*sizeof(uint32_t);
    size_t size_periods = numState*sizeof(uint32_t);
    size_t totalBytes = size+size_transients+size_periods;
    size_t kb = totalBytes/(1024);
    size_t mb = kb/(1024);
    size_t gb = mb/(1024);
    printf("Find attractors net %lu nodes in %lu initials states.\n", numNos,numState);
    printf("Memory usage: %lu Gb or %lu Mb or %lu Kb.\n", gb, mb, kb);
    
	uint32_t *h_transients = (uint32_t*)malloc(size_transients);
    // Verifica se houve sucesso na alocação do vetor h_transients
    if (h_transients == NULL){
        fprintf(stderr, "Failed to allocate h_transients!\n");
        exit(EXIT_FAILURE);
    }    
    
    
    uint32_t *h_periods = (uint32_t*)malloc(size_periods);
    // Verifica se houve sucesso na alocação do vetor h_periods
    if (h_periods == NULL){
        fprintf(stderr, "Failed to allocate h_periods!\n");
        exit(EXIT_FAILURE);
    }
    
    
    //Aloca o vetor para a saida no host
    bool *h_attractors = (bool *)malloc(size);
    // Verifica se houve sucesso na alocação do vetor h_attractors
    if (h_attractors == NULL){
        fprintf(stderr, "Failed to allocate h_attractors!\n");
        exit(EXIT_FAILURE);
    }
    
    // Aloca os vetores na GPU (device)
    uint32_t *d_transients = NULL;
    err = cudaMalloc((void **)&d_transients, NUM_STATES * sizeof(uint32_t));

    if (err != cudaSuccess){
        fprintf(stderr, "Failed to allocate d_transients (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
    
    uint32_t *d_periods = NULL;
    err = cudaMalloc((void **)&d_periods, NUM_STATES * sizeof(uint32_t));

    if (err != cudaSuccess){
        fprintf(stderr, "Failed to allocate d_periods (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
    
    bool *d_attractors = NULL;
    err = cudaMalloc((void **)&d_attractors, size);

    if (err != cudaSuccess){
        fprintf(stderr, "Failed to allocate d_attractors (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    // Launch the Vector Add CUDA Kernel
    uint32_t threadsPerBlock = 256;
    uint32_t blocksPerGrid = (NUM_COPYS + threadsPerBlock - 1) / threadsPerBlock;
    printf("CUDA kernel launch with %d blocks of %d threads\n", blocksPerGrid, threadsPerBlock);
    
    findAttractor<<< blocksPerGrid, threadsPerBlock >>>(d_attractors, d_transients, d_periods, NUM_COPYS);
    
    //err = cudaGetLastError();
    //if (err != cudaSuccess){
    //    fprintf(stderr, "Failed to launch findAttractor kernel (error code %s)!\n", cudaGetErrorString(err));
    //    exit(EXIT_FAILURE);
    //}

    // Copy the device result vector in device memory to the host result vector
    // in host memory.
    printf("Copy output data from the CUDA device to the host memory\n");
    
	err = cudaMemcpy(h_transients, d_transients, size_transients, cudaMemcpyDeviceToHost);
    if (err != cudaSuccess){
        fprintf(stderr, "Failed to copy vector d_transients from device to host (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
    
    err = cudaMemcpy(h_periods, d_periods, size_periods, cudaMemcpyDeviceToHost);
    if (err != cudaSuccess){
        fprintf(stderr, "Failed to copy vector d_periods from device to host (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
    
    err = cudaMemcpy(h_attractors, d_attractors, size, cudaMemcpyDeviceToHost);
    if (err != cudaSuccess){
        fprintf(stderr, "Failed to copy vector d_attractors from device to host (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
    /*
    printf("Attractor found:\n");
    for(int i = 0; i < numState; i++){
       for(int j = 0; j < numNos; j++){
          printf("%d",h_attractors[getIndice(numNos,i,j)]);
      }
      printf("\n");
    }
    printf("\n");
    */
    err = cudaFree(d_transients);

    if (err != cudaSuccess){
        fprintf(stderr, "Failed to free device vector d_transients (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
    
    err = cudaFree(d_periods);

    if (err != cudaSuccess){
        fprintf(stderr, "Failed to free device vector d_periods (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
    
    err = cudaFree(d_attractors);

    if (err != cudaSuccess){
        fprintf(stderr, "Failed to free device vector d_attractors (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    // Free host memory
    free(h_transients);
    free(h_periods);
    free(h_attractors);

    // Reset the device and exit
    // cudaDeviceReset causes the driver to clean up all state. While
    // not mandatory in normal operation, it is good practice.  It is also
    // needed to ensure correct operation when the application is being
    // profiled. Calling cudaDeviceReset causes all profile data to be
    // flushed before the application exits
    err = cudaDeviceReset();

    if (err != cudaSuccess){
        fprintf(stderr, "Failed to deinitialize the device! error=%s\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    printf("Done\n");
    return 0;
}
