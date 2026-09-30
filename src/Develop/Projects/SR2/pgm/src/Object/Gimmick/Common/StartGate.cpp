#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/StartGate.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/Debug.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Clipper.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOProfile.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCameraMgr.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCamera.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil_PS2.hpp"
#include "usr/local/sega/nn/src/Node/nnnodestatuslist.h"
#include "usr/local/sega/nn/src/Node/nncalcmatrixpalettemotion.h"
#include "usr/local/sega/nn/src/Node/nncalcmatrixpalette.h"
#include "usr/local/sega/nn/src/Material/nnmaterialmotion.h"
#include "usr/local/sega/nn/src/DrawObj/nndrawobjectext.h"

f32 STGATE_DENKI_HIT_SCALE;
f32 STGATE_LINE_Y_OFFSET;
f32 STGATE_MOVELINE_SPOS;
f32 STGATE_DENKI_SUB_FRAME;

namespace {
static f32 CLIP_DISTx2 = 0.0f;
static f32 tof32BonusSpeedTable[10] = {0.25463f,
                                       0.277778f,
                                       0.300926f,
                                       0.324074f,
                                       0.347222f,
                                       0.37037f,
                                       0.393519f,
                                       0.416667f,
                                       0.439815f,
                                       0.462963f};
static f32 tof32BonusAgpTable[10] = {
    10.0f, 15.0f, 20.0f, 25.0f, 30.0f, 35.0f, 40.0f, 45.0f, 50.0f, 55.0f};
static f32 tof32BonusRateTable[10] = {0.0f, 0.0f, 0.0f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f};
} // namespace

void clsStartGate_Obj::createData()
{
}

void clsStartGate_Obj::destroyData()
{
}

void clsStartGate_Obj::setBonus(clsPlayerTask* pcPlayer, u32 u32RaceMSec)
{
}

void clsStartGate_Task::createModel(stcBinInfo& rParam1)
{
}

void clsStartGate_Task::execute()
{
}

void clsStartGate_Task::draw()
{
    if (clsDebug::GS()->m_sBitFlag.bDisableDrawStGate) {
        return;
    }
    if (clsOOProfile::GS()->m_bRunning) {
        clsOOProfile::GS()->begin("StartGate Draw");
    }
    switch (m_u8Mode) {
    case 2:
        addMode(nspGlobal::sTask.pcBaseRace->getRaceInfo() != RACE_INFO___INIT);
        break;
    case 3:
        break;
    case 4: {
        u32 u32Num = m_vecGmkObjArray.size();
        for (u32 u32i = 0; u32i < u32Num; ++u32i) {
            clsStartGate_Obj* pcObj = m_vecGmkObjArray.at(u32i);
            if (pcObj->m_u8ExecMode == 0) {
                continue;
            }
            clsStartGateModels& rcModels = clsStartGate_Task::GS()->getModelRef();
            NNS_MATRIX sWorldMtx;
            nnMakeQuaternionMatrix(&sWorldMtx, &pcObj->getRotQuatRef());
            nnCopyVectorFastMatrixTranslation(&sWorldMtx, &pcObj->getPositionRef());
            pcObj->m_enClipRet = clsClipper::RS().check(clsTaskManager::GS()->getCurViewNo(),
                                                        *rcModels.m_cGate.m_psObject,
                                                        sWorldMtx,
                                                        pcObj->getPortalNo(),
                                                        CLIP_DISTx2,
                                                        NULL);
            if (pcObj->m_enClipRet >= OUT_VISIBLE) {
                continue;
            }
            clsBaseRace_Task& rcBaseRace_Task = *nspGlobal::sTask.pcBaseRace;
            clsModelType_OB_TX_MO_MA& rcGate = rcModels.m_cGate;
            clsModelType_OB_TX_MO_MA& rcBlitz = rcModels.m_cBlitz;
            clsModelType_OB_TX& rcLine = rcModels.m_cLine;
            u32* psNodeStat = nspNnUtil::tpsNnNodeStatus;
            NNS_MATRIX* psMtxPal = nspNnUtil::tpsNnMtxPal;
            NNS_MATRIX sMtx;
            nnMultiplyMatrix(
                &sMtx,
                clsPfCameraMgr::GS()->getCamera(clsTaskManager::GS()->getCurViewNo())->getViewMtx(),
                &sWorldMtx);
            f32 f32Frame =
                pcObj->m_af32MtnFrame[0] -
                ((rcBaseRace_Task.getStageNo() == 5 || rcBaseRace_Task.getStageNo() == 13) *
                 (pcObj->m_af32MtnFrame[0] >= rcGate.m_psMatMotion->EndFrame));
            nnSetUpNodeStatusList(psNodeStat, rcGate.m_psObject->nNode, 0);
            nnCalcMatrixPaletteMotion(psMtxPal,
                                      psNodeStat,
                                      rcGate.m_psObject,
                                      rcGate.m_psMotion,
                                      f32Frame,
                                      &sMtx,
                                      &nspNnUtil::tsNnMtxStack,
                                      0);
            nnSetTextureList(rcGate.m_psTexList);
            nnDrawMaterialMotionObject(rcGate.m_psMatMotObj, psMtxPal, psNodeStat, 0x80000000, 0);
            if (pcObj->m_s32EndCnt != 0 &&
                rcBaseRace_Task.getRaceInfo() < RACE_INFO___START_GATE_CHECK)
            {
                NNS_MATRIX sEffectMtx;
                if (rcBaseRace_Task.getRaceInfo() == RACE_INFO___COUNT_DOWN) {
                    f32 f32Frame = rcBaseRace_Task.getClock_CountDown()->getSec() *
                                       clsPfSystem::GS()->getFrameRate() +
                                   rcBaseRace_Task.getClock_CountDown()->getMSec() *
                                       clsPfSystem::GS()->getFrameRate() / 100.0f;
                    f32 f32TotalFrame =
                        rcBaseRace_Task.getCountDownMaxSecond() * clsPfSystem::GS()->getFrameRate();
                    nnTranslateMatrix(&sEffectMtx,
                                      &sMtx,
                                      0.0f,
                                      0.0f,
                                      -1.0f * ((80.0f / f32TotalFrame) * f32Frame));
                    nnScaleMatrix(&sEffectMtx, &sEffectMtx, pcObj->m_f32ScaleLineX, 1.0f, 1.0f);
                    nnSetUpNodeStatusList(psNodeStat, rcLine.m_psObject->nNode, 0);
                    nnCalcMatrixPalette(psMtxPal,
                                        psNodeStat,
                                        rcLine.m_psObject,
                                        &sEffectMtx,
                                        &nspNnUtil::tsNnMtxStack,
                                        0);
                    nnSetTextureList(rcLine.m_psTexList);
                    nnDrawObject(rcLine.m_psObject, psMtxPal, psNodeStat, 0x80000000, 0);
                }
                nnTranslateMatrix(&sEffectMtx, &sMtx, 0.0f, 1.05f, 0.0f);
                nnScaleMatrix(&sEffectMtx,
                              &sEffectMtx,
                              pcObj->m_f32ScaleBlitzX,
                              pcObj->m_f32Scale * pcObj->m_f32ScaleOffset,
                              1.0f);
                nnSetUpNodeStatusList(psNodeStat, rcBlitz.m_psObject->nNode, 0);
                nnSetTextureList(rcBlitz.m_psTexList);
                nnDrawMaterialMotionObject(
                    rcBlitz.m_psMatMotObj, &sEffectMtx, psNodeStat, 0x80000000, 0);
            }
        }
        break;
    }
    }
    if (clsOOProfile::GS()->m_bRunning) {
        clsOOProfile::GS()->end("StartGate Draw");
    }
}
