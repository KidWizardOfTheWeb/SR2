#ifndef MOTION_HPP
#define MOTION_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/Node/nncalcmatrixlist.h"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil_PS2.hpp"

// total size: 0x5C
class clsMotion {
public:
    typedef NNS_MATRIX* MtxPalPtr;

    enum enmStatus {
        STATUS_NULL = 0,
        STATUS_END = 1,
        STATUS_STOP = 2,
        STATUS_BLEND = 4,
        STATUS_UNLOOP = 8,
        STATUS_LINK_ONE = 16,
        STATUS_LINK_SYNC = 32,
        STATUS_NEXT_UNLOOP = 64,
        STATUS_NEXT_STOP = 128,
    };

    NNS_OBJECT* m_psObject;      // offset 0x0, size 0x4
    NNS_MATRIX* m_psMtxPal;      // offset 0x4,  size 0x4
    NNS_TRS* m_apsTrs[2];        // offset 0x8, size 0x8
    u32* m_psNodeStatus;         // offset 0x10, size 0x4
    NNS_MOTION* m_psMotion;      // offset 0x14, size 0x4
    NNS_MOTION* m_psLinkMotion;  // offset 0x18, size 0x4
    NNS_MOTION* m_psBlendMotion; // offset 0x1C, size 0x4
    enmStatus m_eStatus;         // offset 0x20, size 0x4
    s32 m_s32CurrentTrsNo;       // offset 0x24, size 0x4
    s32 m_s32CurrentChangeFlag;  // offset 0x28, size 0x4
    f32 m_f32AllFrameRate;       // offset 0x2C, size 0x4
    f32 m_f32FrameRate;          // offset 0x30, size 0x4
    f32 m_f32BlendFrameRate;     // offset 0x34, size 0x4
    f32 m_f32LinkFrameRate;      // offset 0x38, size 0x4
    f32 m_f32Frame;              // offset 0x3C, size 0x4
    f32 m_f32LinkFrame;          // offset 0x40, size 0x4
    f32 m_f32BlendFrame;         // offset 0x44, size 0x4
    f32 m_f32LinkRatio;          // offset 0x48, size 0x4
    f32 m_f32LinkAddRatio;       // offset 0x4C, size 0x4
    f32 m_f32BlendRatio;         // offset 0x50, size 0x4
    f32 m_f32BlendAddRatio;      // offset 0x54, size 0x4

    static f32 m_tf32SystemRate;

    virtual ~clsMotion() {}
    virtual void create(NNS_OBJECT* psObject);
    void release();
    void play(NNS_MOTION* pMotion, f32 fFrame, enmStatus eStatus);
    void playLink(NNS_MOTION* pMotion, f32 fFrame1, f32 fFrame2, enmStatus eStatus);
    void updateTrs();
    void updateFrame();

    void updateMtxPal(NNS_MATRIX* psBaseMtx)
    {
        nnCalcMatrixPaletteMatrixList(m_psMtxPal, m_psObject, nspNnUtil::tpsNnMtxList, psBaseMtx);
    }
    void updateMtxList(NNS_MATRIX* psBaseMtx)
    {
        nnCalcMatrixListTRSList(
            nspNnUtil::tpsNnMtxList, m_psObject, m_apsTrs[m_s32CurrentTrsNo], psBaseMtx);
    }
    NNS_OBJECT* getObjectPtr() const { return m_psObject; }
    NNS_TRS* getTrsOldPtr() { return m_apsTrs[1 - m_s32CurrentTrsNo]; }
    NNS_TRS* getTrsCurrentPtr() { return m_apsTrs[m_s32CurrentTrsNo]; }
    s32 getCurrentChangeFlag() const { return m_s32CurrentChangeFlag; }
    void calcNodeMatrixTRSList(NNS_MATRIX& mtx, s32 iNode, NNS_MATRIX* pMtxPal) {}
    MtxPalPtr getMtxPalPtr() const { return m_psMtxPal; }
};

// total size: 0x10
struct stcPlayTable {
    f32 f32StartFrame;            // offset 0x0, size 0x4
    f32 f32LinkFrame;             // offset 0x4, size 0x4
    clsMotion::enmStatus eStatus; // offset 0x8, size 0x4
    s8 s8MotionNo;                // offset 0xC, size 0x1
    s8 s8MotionType;              // offset 0xD, size 0x1
    u8 au8Reserve[2];             // offset 0xE, size 0x2
};

enum enmPriority {
    PRI_LV_00 = 0,
    PRI_LV_01 = 1,
    PRI_LV_02 = 2,
    PRI_LV_03 = 3,
    PRI_LV_04 = 4,
    PRI_LV_05 = 5,
    PRI_LV_06 = 6,
    PRI_HIGHT = 5,
    PRI_MID_HIGHT = 4,
    PRI_NORMAL = 3,
    PRI_MID_LOW = 2,
    PRI_LOW = 1,
};

// total size: 0x48
struct stcPlayData {
    enmPriority ePriority;   // offset 0x0, size 0x4
    s32 s32TableNo;          // offset 0x4, size 0x4
    stcPlayTable asTable[4]; // offset 0x8, size 0x40
};

#endif // MOTION_HPP
