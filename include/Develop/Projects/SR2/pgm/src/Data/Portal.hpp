#ifndef PORTAL_HPP
#define PORTAL_HPP

#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "types.h"

extern c8* ac8NameBool[2];

// total size: 0x4
struct stcPortalBelongType {
    u8 u8Next;    // offset 0x0, size 0x1
    u8 u8Current; // offset 0x1, size 0x1
    u8 u8Back;    // offset 0x2, size 0x1
    u8 u8Paddin;  // offset 0x3, size 0x1
};

// total size: 0x50
struct stcPortalMtx {
    f32 aInvMtx[4][4]; // offset 0x0, size 0x40
    s16 s16LocalSx;    // offset 0x40, size 0x2
    s16 s16LocalSy;    // offset 0x42, size 0x2
    s16 s16LocalSz;    // offset 0x44, size 0x2
    s16 s16LocalEx;    // offset 0x46, size 0x2
    s16 s16LocalEy;    // offset 0x48, size 0x2
    s16 s16LocalEz;    // offset 0x4A, size 0x2
    u8 u8PaddinPS2[4]; // offset 0x4C, size 0x4
};

// total size: 0x1C
// Q2-qualified as clsPortal::stcPortalDetail (MWCC scoping: nest inside clsPortal)
struct stcPortalDetail {
    s16 s16Sx;      // offset 0x0, size 0x2
    s16 s16Sy;      // offset 0x2, size 0x2
    s16 s16Sz;      // offset 0x4, size 0x2
    s16 s16Ex;      // offset 0x6, size 0x2
    s16 s16Ey;      // offset 0x8, size 0x2
    s16 s16Ez;      // offset 0xA, size 0x2
    u8 u8Type;      // offset 0xC, size 0x1
    s8 s8MtxNo;     // offset 0xD, size 0x1
    u8 u8Paddin[2]; // offset 0xE, size 0x2
    s32 a32RotX;    // offset 0x10, size 0x4
    s32 a32RotY;    // offset 0x14, size 0x4
    s32 a32RotZ;    // offset 0x18, size 0x4
};

// total size: 0x8
struct stcPortalBin {
    u16 u16Num;              // offset 0x0, size 0x2
    u8 u8BeginType;          // offset 0x2, size 0x1
    u8 u8EndType;            // offset 0x3, size 0x1
    stcPortalMtx* psMtxHeap; // offset 0x4, size 0x4
    // stcPortalDetail asDetail[] at offset 0x8 (flexible array)
};

// total size: 0x50
class clsPortal {
public:
    enum enmPortalType {
        MAP = 0,
        OBJ = 1,
    };

    struct stcPortalDetail {
        s16 s16Sx;      // offset 0x0, size 0x2
        s16 s16Sy;      // offset 0x2, size 0x2
        s16 s16Sz;      // offset 0x4, size 0x2
        s16 s16Ex;      // offset 0x6, size 0x2
        s16 s16Ey;      // offset 0x8, size 0x2
        s16 s16Ez;      // offset 0xA, size 0x2
        u8 u8Type;      // offset 0xC, size 0x1
        s8 s8MtxNo;     // offset 0xD, size 0x1
        u8 u8Paddin[2]; // offset 0xE, size 0x2
        s32 a32RotX;    // offset 0x10, size 0x4
        s32 a32RotY;    // offset 0x14, size 0x4
        s32 a32RotZ;    // offset 0x18, size 0x4
    };

    virtual ~clsPortal() {}

    u8 changeTypeEx(u8 param_1) const { return 0; }
    u8 check(u32 param_1, u8 param_2) { return 0; }

    void setPortal(u8* pu8BinI, enmPortalType ePortalTypeI);
    u8 getPortal(const NNS_VECTORFAST& rosPosVecFast);
    void update(u32 u32vI, const NNS_VECTOR& orsPosI, bool bReverse);
    c8* getStrEx_Debug(u8 u8TypeI);

    static f32 DOT_PRODUCT_BACK_DEG;

    stcPortalBin* m_psPortalBin;                 // offset 0x4, size 0x4
    stcPortalBelongType m_asPortalBelongType[4]; // offset 0x8, size 0x10
    enmPortalType m_ePortalType;                 // offset 0x18, size 0x4
    u32 m_abEnableFrontBack[4];                  // offset 0x1C, size 0x10
    u32 m_abDisableFrontBack[4];                 // offset 0x2C, size 0x10
    u32 m_abEnableBackIs3[4];                    // offset 0x3C, size 0x10
    u8 m_bReverse;                               // offset 0x4C, size 0x1
};

// total size: 0x6C
class clsPortalEditor_Debug_Task : public clsTask {
public:
    virtual ~clsPortalEditor_Debug_Task();
    virtual void draw();

    clsPortalEditor_Debug_Task(const clsPortal* opcSrcPortalI);
    void savePortalData();
    void drawPortalDetail(const clsPortal::stcPortalDetail& orsDetailI, bool bActiveI);
    void drawLeftList(bool bActiveI, bool bDraw3dI);

    clsPortal* m_opcSrcPortal;       // offset 0x54, size 0x4
    stcPortalBin* m_opsSrcPortalBin; // offset 0x58, size 0x4
    stcPortalBin* m_psPortalHi;      // offset 0x5C, size 0x4
    s32 m_s32ListCursor;             // offset 0x60, size 0x4
    u32 m_u32DetailOperation;        // offset 0x64, size 0x4
    u8 m_bEasyDrawFlag;              // offset 0x68, size 0x1
    u8 m_bChangeFlag;                // offset 0x69, size 0x1
};

#endif // PORTAL_HPP
