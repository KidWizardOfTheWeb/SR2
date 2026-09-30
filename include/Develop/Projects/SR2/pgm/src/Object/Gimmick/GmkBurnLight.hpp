#ifndef GMKBURNLIGHT_HPP
#define GMKBURNLIGHT_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFlag.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOProfile.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCameraMgr.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil_PS2.hpp"
#include "usr/local/sega/nn/src/DrawObj/nndrawmultiobjectinitialposeext.h"
#include "usr/local/sega/nn/src/Matrix/nnmatrix.h"
#include "usr/local/sega/nn/src/Node/nncalcnodestatuslistinitialpose.h"
#include "usr/local/sega/nn/src/Node/nnnodestatuslist.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

// total size: 0x6C
template <class T_MODEL>
class clsGmkBurnLight_Task : public clsTask {
public:
    clsGmkBurnLight_Task(T_MODEL& rcGmkModelI, u32 u32ObjectNumI, s32 s32DrawNodeNoI);
    virtual ~clsGmkBurnLight_Task() {}
    virtual void execute() { m_s16DrawNum = 0; }
    virtual void draw();
    void update(NNS_MATRIX& rsMtxWorkI) {}
    void resetDrawNode(NNS_OBJECT& rsObjectI)
    {
        NNS_NODE* psNode = rsObjectI.pNodeList;
        s32 s32NodeNum = rsObjectI.nNode;
        do {
            --s32NodeNum;
            OOClearBit(psNode->fType, 0x10U);
            ++psNode;
        } while (s32NodeNum != 0);

        OOSetBit(rsObjectI.pNodeList[m_s8DrawNodeNo].fType, 0x10U);
    }
    void setDrawNode(NNS_OBJECT& rsObjectI)
    {
        NNS_NODE* psNode = rsObjectI.pNodeList;
        s32 s32NodeNum = rsObjectI.nNode;
        do {
            --s32NodeNum;
            OOSetBit(psNode->fType, 0x10U);
            ++psNode;
        } while (s32NodeNum != 0);

        OOClearBit(rsObjectI.pNodeList[m_s8DrawNodeNo].fType, 0x10U);
    }

    NNS_MATRIX* m_psMtxWork_Mutable; // offset 0x54, size 0x4
    f32* m_pf32MotionFrame;          // offset 0x58, size 0x4
    f32* m_pf32MatMotionFrame;       // offset 0x5C, size 0x4
    T_MODEL& m_rcModel;              // offset 0x60, size 0x4
    s16 m_16ObjectNum;               // offset 0x64, size 0x2
    s16 m_s16DrawNum;                // offset 0x66, size 0x2
    s8 m_s8DrawNodeNo;               // offset 0x68, size 0x1
};

template <class T_MODEL>
clsGmkBurnLight_Task<T_MODEL>::clsGmkBurnLight_Task(T_MODEL& rcGmkModelI,
                                                    u32 u32ObjectNumI,
                                                    s32 s32DrawNodeNoI)
    : clsTask(490010, 5), m_rcModel(rcGmkModelI), m_16ObjectNum(u32ObjectNumI), m_s16DrawNum(0),
      m_s8DrawNodeNo(s32DrawNodeNoI)
{
    m_psMtxWork_Mutable =
        reinterpret_cast<NNS_MATRIX*>((reinterpret_cast<u32>(this) + (sizeof(*this) + 15)) & ~15u);
    m_pf32MotionFrame = reinterpret_cast<f32*>(m_psMtxWork_Mutable + m_16ObjectNum);
    m_pf32MatMotionFrame = m_pf32MotionFrame + m_16ObjectNum;
}

template <>
inline void clsGmkBurnLight_Task<clsModelType_OB_TX>::draw()
{
    NNS_OBJECT* psObject;
    u32* psNodeStat;
    NNS_MATRIX* psMtxPal;
    NNS_MATRIX* opaNnViewMtx;
    NNS_MATRIX* psMtxWork_Hi;
    s32 s32n;

    if (m_s16DrawNum == 0) {
        return;
    }

    OOProfileBegin("GmkBurnLight Draw");

    psObject = m_rcModel.m_psObject;
    setDrawNode(*psObject);

    opaNnViewMtx =
        &clsPfCameraMgr::GS()->getCamera(clsTaskManager::GS()->getCurViewNo())->m_sViewMtx;
    nnSetTextureList(m_rcModel.m_psTexList);
    psMtxWork_Hi = m_psMtxWork_Mutable;

    nspNnUtil::tu32PtrListOffset = 0;
    nspNnUtil::ts32NnMultiObjNum = 0;

    s32n = 0;
    do {
        nspNnUtil::GetMultiDrawBuffer(psObject, &psMtxPal, &psNodeStat);

        nnSetUpNodeStatusList(psNodeStat, psObject->nNode, 0);
        nnMultiplyMatrix(psMtxPal, opaNnViewMtx, psMtxWork_Hi);
        nnCalcNodeStatusListInitialPose(psNodeStat, psObject, psMtxPal, 0);
        ++s32n;
        ++psMtxWork_Hi;
    } while (s32n < m_s16DrawNum);

    if (nspNnUtil::ts32NnMultiObjNum > 0) {
        nnDrawMultiObjectInitialPoseExt(psObject,
                                        nspNnUtil::tppsNnMultiMtxPtrList,
                                        nspNnUtil::tppsNodeStatusPtrList,
                                        0x80000000,
                                        0x80,
                                        nspNnUtil::ts32NnMultiObjNum,
                                        NNE_FALSE);
    }

    resetDrawNode(*psObject);
    m_s16DrawNum = 0;

    OOProfileEnd("GmkBurnLight Draw");
}

#endif // GMKBURNLIGHT_HPP
