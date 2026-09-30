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
    NNS_MATRIX aInvMtx; // offset 0x0, size 0x40
    s16 s16LocalSx;     // offset 0x40, size 0x2
    s16 s16LocalSy;     // offset 0x42, size 0x2
    s16 s16LocalSz;     // offset 0x44, size 0x2
    s16 s16LocalEx;     // offset 0x46, size 0x2
    s16 s16LocalEy;     // offset 0x48, size 0x2
    s16 s16LocalEz;     // offset 0x4A, size 0x2
    u8 u8PaddinPS2[4];  // offset 0x4C, size 0x4
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

    u8 changeTypeEx(u8 u8Type) const
    {
        u8Type -= (u8Type > 128) * 64;
        u8Type -= (u8Type > 96) * 32;
        return u8Type;
    }
    u32 check(u32 u32ViewNo, u8 u8Type)
    {
        stcPortalBelongType& rsBelong = m_asPortalBelongType[u32ViewNo];
        u8 u8BaseType = changeTypeEx(u8Type);
        u32 bEnableFrontBack = m_abEnableFrontBack[u32ViewNo];
        u32 bDisableFrontBack = m_abDisableFrontBack[u32ViewNo];
        if (m_abEnableBackIs3[u32ViewNo] && m_bReverse) {
            bEnableFrontBack = 1;
            bDisableFrontBack = 0;
        }
        if (rsBelong.u8Current == u8Type) {
            return 1;
        }
        if (u8BaseType == changeTypeEx(rsBelong.u8Next)) {
            return (m_bReverse & bDisableFrontBack) ? 4 : 2;
        }
        if (u8BaseType == changeTypeEx(rsBelong.u8Back)) {
            return (m_bReverse | bEnableFrontBack) ? 2 : 4;
        }
        if (u8Type == 63) {
            return 0;
        }
        return 4;
    }

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
