#ifndef EESTRUCT_H
#define EESTRUCT_H

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif // EESTRUCT_H

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg)                                          \
    ((unsigned long)(nloop) | ((unsigned long)(eop) << 15) | ((unsigned long)(pre) << 46) |        \
     ((unsigned long)(prim) << 47) | ((unsigned long)(flg) << 58) | ((unsigned long)(nreg) << 60))

#define SCE_VIF1_SET_UNPACK(vuaddr, num, cmd, irq)                                                 \
    ((unsigned int)(vuaddr) | ((unsigned int)(num) << 16) | ((unsigned int)(0x60 | (cmd)) << 24) | \
     ((unsigned int)(irq) << 31))

#define SCE_GS_TRUE (1)
#define SCE_GS_FALSE (0)

#define SCE_GIF_PACKED 0
#define SCE_GIF_REGLIST 1
#define SCE_GIF_IMAGE 2
#define SCE_GIF_PACKED_AD 0x0e

#define PP_NARG(...) PP_NARG_(__VA_ARGS__, PP_RSEQ_N())

#define PP_NARG_(...) PP_ARG_N(__VA_ARGS__)

#define PP_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, N, ...) N

#define PP_RSEQ_N() 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define CAT(a, b) CAT_(a, b)
#define CAT_(a, b) a##b

#define GIF_REGLIST(...) CAT(GIF_REGLIST_, PP_NARG(__VA_ARGS__))(__VA_ARGS__)

#define GIF_REGLIST_1(a0) ((long)(a0) << (0 * 4))

#define GIF_REGLIST_2(a0, a1) ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4))

#define GIF_REGLIST_3(a0, a1, a2)                                                                  \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4))

#define GIF_REGLIST_4(a0, a1, a2, a3)                                                              \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4))

#define GIF_REGLIST_5(a0, a1, a2, a3, a4)                                                          \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4))

#define GIF_REGLIST_6(a0, a1, a2, a3, a4, a5)                                                      \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4))

#define GIF_REGLIST_7(a0, a1, a2, a3, a4, a5, a6)                                                  \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4)) |              \
        ((long)(a6) << (6 * 4))

#define GIF_REGLIST_8(a0, a1, a2, a3, a4, a5, a6, a7)                                              \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4)) |              \
        ((long)(a6) << (6 * 4)) | ((long)(a7) << (7 * 4))

#define GIF_REGLIST_9(a0, a1, a2, a3, a4, a5, a6, a7, a8)                                          \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4)) |              \
        ((long)(a6) << (6 * 4)) | ((long)(a7) << (7 * 4)) | ((long)(a8) << (8 * 4))

#define GIF_REGLIST_10(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9)                                     \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4)) |              \
        ((long)(a6) << (6 * 4)) | ((long)(a7) << (7 * 4)) | ((long)(a8) << (8 * 4)) |              \
        ((long)(a9) << (9 * 4))

#define GIF_REGLIST_11(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)                                \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4)) |              \
        ((long)(a6) << (6 * 4)) | ((long)(a7) << (7 * 4)) | ((long)(a8) << (8 * 4)) |              \
        ((long)(a9) << (9 * 4)) | ((long)(a10) << (10 * 4))

#define GIF_REGLIST_12(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)                           \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4)) |              \
        ((long)(a6) << (6 * 4)) | ((long)(a7) << (7 * 4)) | ((long)(a8) << (8 * 4)) |              \
        ((long)(a9) << (9 * 4)) | ((long)(a10) << (10 * 4)) | ((long)(a11) << (11 * 4))

#define GIF_REGLIST_13(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12)                      \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4)) |              \
        ((long)(a6) << (6 * 4)) | ((long)(a7) << (7 * 4)) | ((long)(a8) << (8 * 4)) |              \
        ((long)(a9) << (9 * 4)) | ((long)(a10) << (10 * 4)) | ((long)(a11) << (11 * 4)) |          \
        ((long)(a12) << (12 * 4))

#define GIF_REGLIST_14(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13)                 \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4)) |              \
        ((long)(a6) << (6 * 4)) | ((long)(a7) << (7 * 4)) | ((long)(a8) << (8 * 4)) |              \
        ((long)(a9) << (9 * 4)) | ((long)(a10) << (10 * 4)) | ((long)(a11) << (11 * 4)) |          \
        ((long)(a12) << (12 * 4)) | ((long)(a13) << (13 * 4))

#define GIF_REGLIST_15(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14)            \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4)) |              \
        ((long)(a6) << (6 * 4)) | ((long)(a7) << (7 * 4)) | ((long)(a8) << (8 * 4)) |              \
        ((long)(a9) << (9 * 4)) | ((long)(a10) << (10 * 4)) | ((long)(a11) << (11 * 4)) |          \
        ((long)(a12) << (12 * 4)) | ((long)(a13) << (13 * 4)) | ((long)(a14) << (14 * 4))

#define GIF_REGLIST_16(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)       \
    ((long)(a0) << (0 * 4)) | ((long)(a1) << (1 * 4)) | ((long)(a2) << (2 * 4)) |                  \
        ((long)(a3) << (3 * 4)) | ((long)(a4) << (4 * 4)) | ((long)(a5) << (5 * 4)) |              \
        ((long)(a6) << (6 * 4)) | ((long)(a7) << (7 * 4)) | ((long)(a8) << (8 * 4)) |              \
        ((long)(a9) << (9 * 4)) | ((long)(a10) << (10 * 4)) | ((long)(a11) << (11 * 4)) |          \
        ((long)(a12) << (12 * 4)) | ((long)(a13) << (13 * 4)) | ((long)(a14) << (14 * 4)) |        \
        ((long)(a15) << (15 * 4))

struct sceGsTexflush {
    unsigned long pad00; // offset 0x0, size 0x4
};

struct sceGsFrame {
    unsigned long FBP : 9;    // offset 0x0, size 0x4
    unsigned long pad09 : 7;  // offset 0x0, size 0x4
    unsigned long FBW : 6;    // offset 0x0, size 0x4
    unsigned long pad22 : 2;  // offset 0x0, size 0x4
    unsigned long PSM : 6;    // offset 0x0, size 0x4
    unsigned long pad30 : 2;  // offset 0x0, size 0x4
    unsigned long FBMSK : 32; // offset 0x0, size 0x4
};

struct sceGsZbuf {
    unsigned long ZBP : 9;    // offset 0x0, size 0x4
    unsigned long pad09 : 15; // offset 0x0, size 0x4
    unsigned long PSM : 4;    // offset 0x0, size 0x4
    unsigned long pad28 : 4;  // offset 0x0, size 0x4
    unsigned long ZMSK : 1;   // offset 0x0, size 0x4
    unsigned long pad33 : 31; // offset 0x0, size 0x4
};

struct sceGsXyoffset {
    unsigned long OFX : 16;   // offset 0x0, size 0x4
    unsigned long pad16 : 16; // offset 0x0, size 0x4
    unsigned long OFY : 16;   // offset 0x0, size 0x4
    unsigned long pad48 : 16; // offset 0x0, size 0x4
};

struct sceGsScissor {
    unsigned long SCAX0 : 11; // offset 0x0, size 0x4
    unsigned long pad11 : 5;  // offset 0x0, size 0x4
    unsigned long SCAX1 : 11; // offset 0x0, size 0x4
    unsigned long pad27 : 5;  // offset 0x0, size 0x4
    unsigned long SCAY0 : 11; // offset 0x0, size 0x4
    unsigned long pad43 : 5;  // offset 0x0, size 0x4
    unsigned long SCAY1 : 11; // offset 0x0, size 0x4
    unsigned long pad59 : 5;  // offset 0x0, size 0x4
};

struct sceGsAlpha {
    unsigned long A : 2;      // offset 0x0, size 0x4
    unsigned long B : 2;      // offset 0x0, size 0x4
    unsigned long C : 2;      // offset 0x0, size 0x4
    unsigned long D : 2;      // offset 0x0, size 0x4
    unsigned long pad8 : 24;  // offset 0x0, size 0x4
    unsigned long FIX : 8;    // offset 0x0, size 0x4
    unsigned long pad40 : 24; // offset 0x0, size 0x4
};

struct sceGsClamp {
    unsigned long WMS : 2;    // offset 0x0, size 0x4
    unsigned long WMT : 2;    // offset 0x0, size 0x4
    unsigned long MINU : 10;  // offset 0x0, size 0x4
    unsigned long MAXU : 10;  // offset 0x0, size 0x4
    unsigned long MINV : 10;  // offset 0x0, size 0x4
    unsigned long MAXV : 10;  // offset 0x0, size 0x4
    unsigned long pad44 : 20; // offset 0x0, size 0x4
};

struct sceGsDimx {
    unsigned long DIMX00 : 3; // offset 0x0, size 0x4
    unsigned long pad00 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX01 : 3; // offset 0x0, size 0x4
    unsigned long pad01 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX02 : 3; // offset 0x0, size 0x4
    unsigned long pad02 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX03 : 3; // offset 0x0, size 0x4
    unsigned long pad03 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX10 : 3; // offset 0x0, size 0x4
    unsigned long pad10 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX11 : 3; // offset 0x0, size 0x4
    unsigned long pad11 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX12 : 3; // offset 0x0, size 0x4
    unsigned long pad12 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX13 : 3; // offset 0x0, size 0x4
    unsigned long pad13 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX20 : 3; // offset 0x0, size 0x4
    unsigned long pad20 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX21 : 3; // offset 0x0, size 0x4
    unsigned long pad21 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX22 : 3; // offset 0x0, size 0x4
    unsigned long pad22 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX23 : 3; // offset 0x0, size 0x4
    unsigned long pad23 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX30 : 3; // offset 0x0, size 0x4
    unsigned long pad30 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX31 : 3; // offset 0x0, size 0x4
    unsigned long pad31 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX32 : 3; // offset 0x0, size 0x4
    unsigned long pad32 : 1;  // offset 0x0, size 0x4
    unsigned long DIMX33 : 3; // offset 0x0, size 0x4
    unsigned long pad33 : 1;  // offset 0x0, size 0x4
};

struct sceGsDthe {
    unsigned long DTHE : 1;   // offset 0x0, size 0x4
    unsigned long pad01 : 63; // offset 0x0, size 0x4
};

struct sceGsFba {
    unsigned long FBA : 1;    // offset 0x0, size 0x4
    unsigned long pad01 : 63; // offset 0x0, size 0x4
};

struct sceGsFogcol {
    unsigned long FCR : 8;    // offset 0x0, size 0x4
    unsigned long FCG : 8;    // offset 0x0, size 0x4
    unsigned long FCB : 8;    // offset 0x0, size 0x4
    unsigned long pad24 : 40; // offset 0x0, size 0x4
};

struct sceGsPrmodecont {
    unsigned long AC : 1;     // offset 0x0, size 0x4
    unsigned long pad01 : 63; // offset 0x0, size 0x4
};

struct sceGsPrmode {
    unsigned long pad00 : 3;  // offset 0x0, size 0x4
    unsigned long IIP : 1;    // offset 0x0, size 0x4
    unsigned long TME : 1;    // offset 0x0, size 0x4
    unsigned long FGE : 1;    // offset 0x0, size 0x4
    unsigned long ABE : 1;    // offset 0x0, size 0x4
    unsigned long AA1 : 1;    // offset 0x0, size 0x4
    unsigned long FST : 1;    // offset 0x0, size 0x4
    unsigned long CTXT : 1;   // offset 0x0, size 0x4
    unsigned long FIX : 1;    // offset 0x0, size 0x4
    unsigned long pad11 : 53; // offset 0x0, size 0x4
};

struct sceGsTest {
    unsigned long ATE : 1;    // offset 0x0, size 0x4
    unsigned long ATST : 3;   // offset 0x0, size 0x4
    unsigned long AREF : 8;   // offset 0x0, size 0x4
    unsigned long AFAIL : 2;  // offset 0x0, size 0x4
    unsigned long DATE : 1;   // offset 0x0, size 0x4
    unsigned long DATM : 1;   // offset 0x0, size 0x4
    unsigned long ZTE : 1;    // offset 0x0, size 0x4
    unsigned long ZTST : 2;   // offset 0x0, size 0x4
    unsigned long pad19 : 45; // offset 0x0, size 0x4
};

struct sceGsTex2 {
    unsigned long pad00 : 20; // offset 0x0, size 0x4
    unsigned long PSM : 6;    // offset 0x0, size 0x4
    unsigned long pad26 : 11; // offset 0x0, size 0x4
    unsigned long CBP : 14;   // offset 0x0, size 0x4
    unsigned long CPSM : 4;   // offset 0x0, size 0x4
    unsigned long CSM : 1;    // offset 0x0, size 0x4
    unsigned long CSA : 5;    // offset 0x0, size 0x4
    unsigned long CLD : 3;    // offset 0x0, size 0x4
};

struct sceGsTexa {
    unsigned long TA0 : 8;    // offset 0x0, size 0x4
    unsigned long pad08 : 7;  // offset 0x0, size 0x4
    unsigned long AEM : 1;    // offset 0x0, size 0x4
    unsigned long pad16 : 16; // offset 0x0, size 0x4
    unsigned long TA1 : 8;    // offset 0x0, size 0x4
    unsigned long pad40 : 24; // offset 0x0, size 0x4
};

struct sceGsTexclut {
    unsigned long CBW : 6;    // offset 0x0, size 0x4
    unsigned long COU : 6;    // offset 0x0, size 0x4
    unsigned long COV : 10;   // offset 0x0, size 0x4
    unsigned long pad22 : 42; // offset 0x0, size 0x4
};

struct sceGsRgbaq {
    unsigned int R : 8; // offset 0x0, size 0x4
    unsigned int G : 8; // offset 0x0, size 0x4
    unsigned int B : 8; // offset 0x0, size 0x4
    unsigned int A : 8; // offset 0x0, size 0x4
    float Q;            // offset 0x4, size 0x4
};
// total size: 0x10
struct sceGifTag {
    unsigned long NLOOP : 15; // offset 0x0, size 0x4
    unsigned long EOP : 1;    // offset 0x0, size 0x4
    unsigned long pad16 : 16; // offset 0x0, size 0x4
    unsigned long id : 14;    // offset 0x0, size 0x4
    unsigned long PRE : 1;    // offset 0x0, size 0x4
    unsigned long PRIM : 11;  // offset 0x0, size 0x4
    unsigned long FLG : 2;    // offset 0x0, size 0x4
    unsigned long NREG : 4;   // offset 0x0, size 0x4
    unsigned long REGS0 : 4;  // offset 0x8, size 0x4
    unsigned long REGS1 : 4;  // offset 0x8, size 0x4
    unsigned long REGS2 : 4;  // offset 0x8, size 0x4
    unsigned long REGS3 : 4;  // offset 0x8, size 0x4
    unsigned long REGS4 : 4;  // offset 0x8, size 0x4
    unsigned long REGS5 : 4;  // offset 0x8, size 0x4
    unsigned long REGS6 : 4;  // offset 0x8, size 0x4
    unsigned long REGS7 : 4;  // offset 0x8, size 0x4
    unsigned long REGS8 : 4;  // offset 0x8, size 0x4
    unsigned long REGS9 : 4;  // offset 0x8, size 0x4
    unsigned long REGS10 : 4; // offset 0x8, size 0x4
    unsigned long REGS11 : 4; // offset 0x8, size 0x4
    unsigned long REGS12 : 4; // offset 0x8, size 0x4
    unsigned long REGS13 : 4; // offset 0x8, size 0x4
    unsigned long REGS14 : 4; // offset 0x8, size 0x4
    unsigned long REGS15 : 4; // offset 0x8, size 0x4
};

// total size: 0x8
struct sceGsPrim {
    unsigned long PRIM : 3;   // offset 0x0, size 0x4
    unsigned long IIP : 1;    // offset 0x0, size 0x4
    unsigned long TME : 1;    // offset 0x0, size 0x4
    unsigned long FGE : 1;    // offset 0x0, size 0x4
    unsigned long ABE : 1;    // offset 0x0, size 0x4
    unsigned long AA1 : 1;    // offset 0x0, size 0x4
    unsigned long FST : 1;    // offset 0x0, size 0x4
    unsigned long CTXT : 1;   // offset 0x0, size 0x4
    unsigned long FIX : 1;    // offset 0x0, size 0x4
    unsigned long pad11 : 53; // offset 0x0, size 0x4
};

// total size: 0x8
struct sceGsBitbltbuf {
    unsigned long SBP : 14;  // offset 0x0, size 0x4
    unsigned long pad14 : 2; // offset 0x0, size 0x4
    unsigned long SBW : 6;   // offset 0x0, size 0x4
    unsigned long pad22 : 2; // offset 0x0, size 0x4
    unsigned long SPSM : 6;  // offset 0x0, size 0x4
    unsigned long pad30 : 2; // offset 0x0, size 0x4
    unsigned long DBP : 14;  // offset 0x0, size 0x4
    unsigned long pad46 : 2; // offset 0x0, size 0x4
    unsigned long DBW : 6;   // offset 0x0, size 0x4
    unsigned long pad54 : 2; // offset 0x0, size 0x4
    unsigned long DPSM : 6;  // offset 0x0, size 0x4
    unsigned long pad62 : 2; // offset 0x0, size 0x4
};

// total size: 0x8
struct sceGsXyz {
    unsigned long X : 16; // offset 0x0, size 0x4
    unsigned long Y : 16; // offset 0x0, size 0x4
    unsigned long Z : 32; // offset 0x0, size 0x4
};

// total size: 0x60
struct sceGsClear {
    struct sceGsTest testa;  // offset 0x0, size 0x8
    signed long testaaddr;   // offset 0x8, size 0x4
    struct sceGsPrim prim;   // offset 0x10, size 0x8
    signed long primaddr;    // offset 0x18, size 0x4
    struct sceGsRgbaq rgbaq; // offset 0x20, size 0x8
    signed long rgbaqaddr;   // offset 0x28, size 0x4
    struct sceGsXyz xyz2a;   // offset 0x30, size 0x8
    signed long xyz2aaddr;   // offset 0x38, size 0x4
    struct sceGsXyz xyz2b;   // offset 0x40, size 0x8
    signed long xyz2baddr;   // offset 0x48, size 0x4
    struct sceGsTest testb;  // offset 0x50, size 0x8
    signed long testbaddr;   // offset 0x58, size 0x4
};

// total size: 0x8
struct tGS_BGCOLOR {
    unsigned int R : 8;  // offset 0x0, size 0x4
    unsigned int G : 8;  // offset 0x0, size 0x4
    unsigned int B : 8;  // offset 0x0, size 0x4
    unsigned int p0 : 8; // offset 0x0, size 0x4
    unsigned int p1;     // offset 0x4, size 0x4
};

// total size: 0x8
struct tGS_DISPFB2 {
    unsigned int FBP : 9;  // offset 0x0, size 0x4
    unsigned int FBW : 6;  // offset 0x0, size 0x4
    unsigned int PSM : 5;  // offset 0x0, size 0x4
    unsigned int p0 : 12;  // offset 0x0, size 0x4
    unsigned int DBX : 11; // offset 0x4, size 0x4
    unsigned int DBY : 11; // offset 0x4, size 0x4
    unsigned int p1 : 10;  // offset 0x4, size 0x4
};

// total size: 0x8
struct tGS_DISPLAY2 {
    unsigned int DX : 12;  // offset 0x0, size 0x4
    unsigned int DY : 11;  // offset 0x0, size 0x4
    unsigned int MAGH : 4; // offset 0x0, size 0x4
    unsigned int MAGV : 2; // offset 0x0, size 0x4
    unsigned int p0 : 3;   // offset 0x0, size 0x4
    unsigned int DW : 12;  // offset 0x4, size 0x4
    unsigned int DH : 11;  // offset 0x4, size 0x4
    unsigned int p1 : 9;   // offset 0x4, size 0x4
};

// total size: 0x8
struct tGS_PMODE {
    unsigned int EN1 : 1;   // offset 0x0, size 0x4
    unsigned int EN2 : 1;   // offset 0x0, size 0x4
    unsigned int CRTMD : 3; // offset 0x0, size 0x4
    unsigned int MMOD : 1;  // offset 0x0, size 0x4
    unsigned int AMOD : 1;  // offset 0x0, size 0x4
    unsigned int SLBG : 1;  // offset 0x0, size 0x4
    unsigned int ALP : 8;   // offset 0x0, size 0x4
    unsigned int p0 : 16;   // offset 0x0, size 0x4
    unsigned int p1;        // offset 0x4, size 0x4
};

// total size: 0x8
struct tGS_SMODE2 {
    unsigned int INT : 1;  // offset 0x0, size 0x4
    unsigned int FFMD : 1; // offset 0x0, size 0x4
    unsigned int DPMS : 2; // offset 0x0, size 0x4
    unsigned int p0 : 28;  // offset 0x0, size 0x4
    unsigned int p1;       // offset 0x4, size 0x4
};

// total size: 0x28
struct sceGsDispEnv {
    struct tGS_PMODE pmode;      // offset 0x0, size 0x8
    struct tGS_SMODE2 smode2;    // offset 0x8, size 0x8
    struct tGS_DISPFB2 dispfb;   // offset 0x10, size 0x8
    struct tGS_DISPLAY2 display; // offset 0x18, size 0x8
    struct tGS_BGCOLOR bgcolor;  // offset 0x20, size 0x8
};

// total size: 0x8
struct sceGsColclamp {
    unsigned long CLAMP : 1;  // offset 0x0, size 0x4
    unsigned long pad01 : 63; // offset 0x0, size 0x4
};

// total size: 0x80
struct sceGsDrawEnv1 {
    struct sceGsFrame frame1;          // offset 0x0, size 0x8
    unsigned long frame1addr;          // offset 0x8, size 0x4
    struct sceGsZbuf zbuf1;            // offset 0x10, size 0x8
    signed long zbuf1addr;             // offset 0x18, size 0x4
    struct sceGsXyoffset xyoffset1;    // offset 0x20, size 0x8
    signed long xyoffset1addr;         // offset 0x28, size 0x4
    struct sceGsScissor scissor1;      // offset 0x30, size 0x8
    signed long scissor1addr;          // offset 0x38, size 0x4
    struct sceGsPrmodecont prmodecont; // offset 0x40, size 0x8
    signed long prmodecontaddr;        // offset 0x48, size 0x4
    struct sceGsColclamp colclamp;     // offset 0x50, size 0x8
    signed long colclampaddr;          // offset 0x58, size 0x4
    struct sceGsDthe dthe;             // offset 0x60, size 0x8
    signed long dtheaddr;              // offset 0x68, size 0x4
    struct sceGsTest test1;            // offset 0x70, size 0x8
    signed long test1addr;             // offset 0x78, size 0x4
};

// total size: 0x80
struct sceGsDrawEnv2 {
    struct sceGsFrame frame2;          // offset 0x0, size 0x8
    unsigned long frame2addr;          // offset 0x8, size 0x4
    struct sceGsZbuf zbuf2;            // offset 0x10, size 0x8
    signed long zbuf2addr;             // offset 0x18, size 0x4
    struct sceGsXyoffset xyoffset2;    // offset 0x20, size 0x8
    signed long xyoffset2addr;         // offset 0x28, size 0x4
    struct sceGsScissor scissor2;      // offset 0x30, size 0x8
    signed long scissor2addr;          // offset 0x38, size 0x4
    struct sceGsPrmodecont prmodecont; // offset 0x40, size 0x8
    signed long prmodecontaddr;        // offset 0x48, size 0x4
    struct sceGsColclamp colclamp;     // offset 0x50, size 0x8
    signed long colclampaddr;          // offset 0x58, size 0x4
    struct sceGsDthe dthe;             // offset 0x60, size 0x8
    signed long dtheaddr;              // offset 0x68, size 0x4
    struct sceGsTest test2;            // offset 0x70, size 0x8
    signed long test2addr;             // offset 0x78, size 0x4
};

// total size: 0x330
struct sceGsDBuffDc {
    struct sceGsDispEnv disp[2]; // offset 0x0, size 0x50
    struct sceGifTag giftag0;    // offset 0x50, size 0x10
    struct sceGsDrawEnv1 draw01; // offset 0x60, size 0x80
    struct sceGsDrawEnv2 draw02; // offset 0xE0, size 0x80
    struct sceGsClear clear0;    // offset 0x160, size 0x60
    struct sceGifTag giftag1;    // offset 0x1C0, size 0x10
    struct sceGsDrawEnv1 draw11; // offset 0x1D0, size 0x80
    struct sceGsDrawEnv2 draw12; // offset 0x250, size 0x80
    struct sceGsClear clear1;    // offset 0x2D0, size 0x60
};

#endif /* _EESTRUCT_H_ */
