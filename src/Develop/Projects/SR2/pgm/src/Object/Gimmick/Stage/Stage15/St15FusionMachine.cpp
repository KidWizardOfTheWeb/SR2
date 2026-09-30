#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15FusionMachine.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Clipper.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOProfile.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCameraMgr.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCamera.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnLight.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil_PS2.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NnDraw3d.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15EnergyBullet.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15MeteoriteL.hpp"
#include "usr/local/sega/nn/src/Node/nnnodestatuslist.h"
#include "usr/local/sega/nn/src/Node/nncalcmatrixpalettemotion.h"
#include "usr/local/sega/nn/src/Node/nncalcmatrixlist.h"
#include "usr/local/sega/nn/src/Node/nncalcnodestatuslistinitialpose.h"
#include "usr/local/sega/nn/src/DrawObj/nndrawobjectext.h"
#include "usr/local/sega/nn/src/DrawObj/nndrawobjectinitialposeext.h"
#include "usr/local/sega/nn/src/Print/nnprint.h"

namespace {
static f32 CLIP_DISTx2 = 0.0f;
struct stcParam {
    s8 s8Interval;
    u8 u8TexNo;
    u8 u8StAlpha;
    u8 u8EdAlpha;
    s16 s16NodeNo;
    s16 s16DataNum;
    u32 u32Color;
    f32 f32StTu;
    f32 f32EdTu;
    NNS_VECTORFAST sSizeFast;
    NNS_VECTORFAST sOffsetFast;
};

struct stcGimickSubParam {
    NNS_VECTORFAST sStartFast;
    NNS_VECTORFAST sPowerFast;
};

stcParam asFusionMachineLineParam[2] = {
    {2,
     1,
     200,
     150,
     4,
     5,
     0xE01414FF,
     0.0f,
     1.0f,
     {0.0f, 0.9f, 0.3f, 0.0f},
     {0.0f, -0.7f, 8.5f, 0.0f}},
    {2,
     1,
     200,
     150,
     4,
     5,
     0xE01414FF,
     0.0f,
     1.0f,
     {0.9f, 0.0f, 0.0f, 0.0f},
     {0.0f, -0.7f, 8.5f, 0.0f}},
};

stcGimickSubParam asFusionMachineLineSubParam[1] = {
    {{0.0f, 0.0f, 0.2f, 1.0f}, {0.0f, 0.0f, 0.1f, 1.0f}}};
} // namespace

namespace nspFusionMachine {
static u8 chk__asFusionMachineLineParam_SizeCheck_[1];

static f32 toaf32BlackHoleTime[3] = {450.0f, 430.0f, 400.0f};
static f32 toaf32ReturnDistance[2] = {125.0f, 50.0f};
static f32 toaf32CheckDist[2][2] = {{65.0f, 130.0f}, {70.0f, 85.0f}};
static f32 toaf32ReturnCheckTable[2] = {0.292f, 0.807f};
static f32 toaf32MissionReturnCheckTable[2] = {0.999f, 0.999f};
static f32 toaf32MissionReturnCheckTable5[2] = {0.292f, 0.555f};
static f32 toaf32MissionReturnCheckTable7[2];
static f32 toaf32ReturnRate[2] = {0.465f, 0.973f};
static f32 toaf32AttackCheckTable1[4] = {0.08f, 0.15f, 0.57f, 0.64f};
static f32 toaf32AttackCheckTable2[4] = {0.037f, 0.105f, 0.535f, 0.62f};
static f32 toaf32MissionAttackCheckTable2[8] = {
    0.08f, 0.15f, 0.3f, 0.38f, 0.52f, 0.6f, 0.8f, 0.88f};
static f32 toaf32MissionAttackCheckTable4[12] = {
    0.06f, 0.12f, 0.18f, 0.26f, 0.32f, 0.38f, 0.5f, 0.56f, 0.62f, 0.78f, 0.84f, 0.9f};
static f32 toaf32MissionAttackTargetLR4[12] = {
    9.0f, -9.0f, 9.0f, -9.0f, 9.0f, -9.0f, 11.0f, 11.0f, -11.0f, -11.0f, 11.0f, 11.0f};
static f32 toaf32VanishCheckTable[2] = {0.204f, 0.706f};
static f32 tof32EmergenceCheckTable[2] = {0.234f, 0.736f};
static f32 tof32EmergenceDistTable[2] = {45.4f, 1465.6f};
static f32 tof32EmergenceDistTableSR[2] = {14.8f, 1568.14f};
static f32 toaf32Attack1OffsetX[5];
} // namespace nspFusionMachine

inline void clsFusionMachine_Obj::upDateLightData()
{
    clsPfLight& rcLight = clsPfLight::RS();
    NNS_VECTORFAST sVecFast;
    u32 u32Light = m_u32LightNo == 3;

    {
        NNS_MATRIX sMtx;
        nnMakeQuaternionMatrix(&sMtx, &m_sRotQuat);
        nnTransformVectorFast(&sVecFast, &sMtx, &m_asParallelDir[u32Light]);
    }
    rcLight.setParallelDir(m_u32LightNo, sVecFast.x, sVecFast.y, sVecFast.z);

    {
        NNS_MATRIX sMtx;
        nnMakeQuaternionMatrix(&sMtx, &m_sRotQuat);
        nnTransformVectorFast(&sVecFast, &sMtx, &m_asParallelPos[u32Light]);
    }
    rcLight.setParallelPos(m_u32LightNo, sVecFast.x, sVecFast.y, sVecFast.z);

    {
        NNS_MATRIX sMtx;
        nnMakeQuaternionMatrix(&sMtx, &m_sRotQuat);
        nnTransformVectorFast(&sVecFast, &sMtx, &m_asSpecularDir[u32Light]);
    }
    rcLight.setSpecularDir(m_u32LightNo, sVecFast.x, sVecFast.y, sVecFast.z);
}

void clsFusionMachine_Obj::createData()
{
}

void clsFusionMachine_Obj::destroyData()
{
}

clsFusionMachine_Obj::clsFusionMachine_Obj()
{
}

void clsFusionMachine_Obj::setLineParam()
{
}

void clsFusionMachine_Obj::damage()
{
}

s32 clsFusionMachine_Obj::getFirstPlayerNo()
{
    return 0;
}

void clsFusionMachine_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pcOther)
{
}

void clsFusionMachine_Obj::reset()
{
}

void clsFusionMachine_Obj::init()
{
}

void clsFusionMachine_Obj::debugDead()
{
}

void clsFusionMachine_Obj::checkDistortionField()
{
}

clsFusionMachine_Task::clsFusionMachine_Task(u32 packId)
    : clsBaseGimmickBody<clsFusionMachine_Task, clsFusionMachine_Obj, clsFusionMachineModels>(
          packId, 0)
{
}

void clsFusionMachine_Task::reset()
{
}

void clsFusionMachine_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsFusionMachine_Task::execute()
{
}

// RECONSTRUCTED: helper name.
inline void clsFusionMachine_Obj::drawModel(NNS_OBJECT* psObject,
                                            NNS_MOTION* psMotion,
                                            NNS_MATRIX* psMtxPal,
                                            u32* psNodeStat,
                                            const NNS_MATRIX& rsViewMtx)
{
    drawCollision();
    if (m_bDrawFlag) {
        NNS_VECTORFAST sPosVecFast;
        nnCopyVectorFast(&sPosVecFast, &getPositionRef());
        if (getMode() == clsFusionMachine_Obj::MODE_EMERGENCE ||
            getMode() == clsFusionMachine_Obj::MODE_VANISH || m_bEffectFlag)
        {
            f32 f32Count = m_f32Count;
            if (getMode() == clsFusionMachine_Obj::MODE_VANISH) {
                f32Count = 10.0f - f32Count;
            }
            NNS_MATRIX sRotateMtx;
            NNS_VECTORFAST sOffsetVecFast;
            nnMakeRotateZMatrix(&sRotateMtx, static_cast<s32>(182.04444f * (64.0f * m_f32Count)));
            nnTransformVectorFast(&sOffsetVecFast, &sRotateMtx, &nspNnUtil::tosYVecFast);
            sOffsetVecFast.y = 0.0f;
            nnMakeQuaternionMatrix(&sRotateMtx, &getRotQuatRef());
            nnTransformVectorFast(&sOffsetVecFast, &sRotateMtx, &sOffsetVecFast);
            nnScaleAddVectorFast(&sPosVecFast, &sPosVecFast, &sOffsetVecFast, f32Count / 2.0f);
        }
        NNS_MATRIX sMtx;
        nnMakeQuaternionMatrix(&sMtx, &getRotQuatRef());
        switch (getMode()) {
        case clsFusionMachine_Obj::MODE_GDIVE_START_WAIT:
        case clsFusionMachine_Obj::MODE_SOUND_WAIT:
        case clsFusionMachine_Obj::MODE_WAIT:
        case clsFusionMachine_Obj::MODE_VANISH:
        case clsFusionMachine_Obj::MODE_DAMAGE:
        case clsFusionMachine_Obj::MODE_DEAD:
        case clsFusionMachine_Obj::MODE_DEAD_EXPLODE_OUT: {
            NNS_MATRIX sRotateMtx;
            nnMakeRotateYMatrix(&sRotateMtx, 32767);
            nnMultiplyMatrix(&sMtx, &sMtx, &sRotateMtx);
            break;
        }
        }
        nnCopyVectorFastMatrixTranslation(&sMtx, &sPosVecFast);
        nnCopyMatrix(&m_sLineDrawMtx, &sMtx);
        m_enClipRet = clsClipper::RS().check(clsTaskManager::GS()->getCurViewNo(),
                                             *psObject,
                                             sMtx,
                                             getPortalNo(),
                                             CLIP_DISTx2,
                                             NULL);
        if (m_enClipRet < OUT_VISIBLE) {
            m_apcLineTask[0]->subFlg(0x100);
            m_apcLineTask[1]->subFlg(0x100);
            if ((getMode() >= clsFusionMachine_Obj::MODE_GDIVE_START_WAIT &&
                 getMode() < clsFusionMachine_Obj::MODE_VANISH) ||
                getMode() == clsFusionMachine_Obj::MODE_VANISH)
            {
                nnMultiplyMatrix(psMtxPal, &rsViewMtx, &sMtx);
                nnCalcNodeStatusListInitialPose(psNodeStat, psObject, psMtxPal, 1);
                nnDrawObjectInitialPose(psObject, psMtxPal, psNodeStat, 0x80000000, 2);
            } else {
                nnMultiplyMatrix(&sMtx, &rsViewMtx, &sMtx);
                nnCalcMatrixPaletteMotion(psMtxPal,
                                          psNodeStat,
                                          psObject,
                                          psMotion,
                                          m_f32MotionFrame,
                                          &sMtx,
                                          &nspNnUtil::tsNnMtxStack,
                                          GetDrawNodeStatus());
                nnDrawObject(psObject, psMtxPal, psNodeStat, 0x80000000, 2);
            }
        }
    }
}

void clsFusionMachine_Task::draw()
{
    if (clsOOProfile::GS()->m_bRunning) {
        clsOOProfile::GS()->begin("Boss Draw");
    }
    clsBaseRace_Task& rcBaseRace_Task = *nspGlobal::sTask.pcBaseRace;
    switch (m_u8Mode) {
    case 2:
        addMode(rcBaseRace_Task.getRaceInfo() != RACE_INFO___INIT);
        break;
    case 3:
        break;
    case 4: {
        if (m_vecGmkObjArray.size() == 0) {
            break;
        }
        clsFusionMachine_Obj* pcObj = m_vecGmkObjArray.at(0);
        u32* psNodeStat = nspNnUtil::tpsNnNodeStatus;
        NNS_MATRIX* psMtxPal = nspNnUtil::tpsNnMtxPal;
        clsFusionMachineModels& rcModels = m_cModel;
        clsPfLight& rcLight = clsPfLight::RS();
        const NNS_MATRIX& rsViewMtx =
            *clsPfCameraMgr::GS()->getCamera(clsTaskManager::GS()->getCurViewNo())->getViewMtx();
        if ((pcObj->m_eFusionMachineMode >= clsFusionMachine_Obj::MODE_GDIVE_START_WAIT) &
            (pcObj->m_eFusionMachineMode < clsFusionMachine_Obj::MODE_EMERGENCE_WAIT))
        {
            if ((1 << clsTaskManager::GS()->getCurViewNo() & pcObj->m_u32MainGroup) == 0) {
                break;
            }
        }
        NNS_MOTION* psMotion;
        if (pcObj->m_bEnableDebug && pcObj->m_s32DebugMotionNo != -1) {
            psMotion = rcModels.m_apsMotion[pcObj->m_s32DebugMotionNo];
        } else {
            psMotion = rcModels.m_apsMotion[pcObj->m_s32MotionNo];
        }
        nnSetUpNodeStatusList(psNodeStat, rcModels.m_cModel.m_psObject->nNode, 0);
        nnSetTextureList(rcModels.m_cModel.m_psTexList);
        rcLight.sendLight(pcObj->m_u32LightNo);
        pcObj->drawModel(rcModels.m_cModel.m_psObject, psMotion, psMtxPal, psNodeStat, rsViewMtx);
        rcLight.sendLight(0);
        switch (pcObj->m_s32AttackOrder) {
        case 1: {
            clsFusionMachineModels& rcModels = getModelRef();
            NNS_MOTION* psMotion = rcModels.m_apsMotion[getObject(0)->getMotionNo()];
            NNS_MATRIX* psMtxList = nspNnUtil::tpsNnMtxList;
            NNS_MATRIX sMtx;
            nnMakeQuaternionMatrix(&sMtx, &getObject(0)->getRotQuatRef());
            nnCopyVectorFastMatrixTranslation(&sMtx, &getObject(0)->getPositionRef());
            nnCalcMatrixListMotion(psMtxList,
                                   rcModels.m_cModel.m_psObject,
                                   psMotion,
                                   getObject(0)->getMotionFrame(),
                                   &sMtx);
            NNS_VECTORFAST sPosVecFast;
            nnTransformVectorFast(&sPosVecFast, &psMtxList[12], &nspNnUtil::tosZeroVecFast);
            clsEnergyBullet_Task::GS()->setEnergyBullet(&sPosVecFast,
                                                        getObject(0)->getOffsetVecFastPtr()->x,
                                                        getObject(0)->getOffsetVecFastPtr()->y);
            break;
        }
        case 2: {
            s32 s32No;
            switch (m_vecGmkObjArray.at(0)->m_s32AttackCount + 1) {
            case 0:
                s32No = -2;
                break;
            case 1:
                s32No = -1;
                break;
            case 2: {
                s32 s32Step = m_vecGmkObjArray.at(0)->m_s8AttackCheckStep;
                s32No = s32Step + ((s32Step == 0) * m_vecGmkObjArray.at(0)->m_s8AttackCheckMax - 1);
                break;
            }
            }
            clsMeteoriteL_Task::GS()->setMeteoriteL(s32No);
            break;
        }
        }
        pcObj->m_s32AttackOrder = 0;
        pcObj->upDateLightData();
        break;
    }
    }
    clsFusionMachine_Obj* pcObj = m_vecGmkObjArray.at(0);
    if (m_bDebugReturnStartRateDisp) {
        f32* opf32Rate = pcObj->m_bEnableDebug ? pcObj->m_af32DebugReturnStartRate
                                               : nspFusionMachine::toaf32ReturnCheckTable;
        for (s32 s32i = 0; s32i < 2; ++s32i) {
            NNS_VECTORFAST sPosVecFast;
            pcObj->m_cPath.getPathPointToRate(opf32Rate[s32i], &sPosVecFast);
            clsPfDraw3d::GS()->renderSphere(clsTaskManager::GS()->getCurViewNo(),
                                            reinterpret_cast<const NNS_VECTOR*>(&sPosVecFast),
                                            10.0f,
                                            0x64d28c64,
                                            16);
        }
    }
    if (m_bDebugReturnEndRateDisp) {
        f32* opf32Rate = pcObj->m_bEnableDebug ? pcObj->m_af32DebugReturnEndRate
                                               : nspFusionMachine::toaf32ReturnRate;
        for (s32 s32i = 0; s32i < 2; ++s32i) {
            NNS_VECTORFAST sPosVecFast;
            pcObj->m_cPath.getPathPointToRate(opf32Rate[s32i], &sPosVecFast);
            clsPfDraw3d::GS()->renderSphere(clsTaskManager::GS()->getCurViewNo(),
                                            reinterpret_cast<const NNS_VECTOR*>(&sPosVecFast),
                                            10.0f,
                                            0x648cd264,
                                            16);
        }
    }
    if (m_bDebugAttackRateDisp) {
        f32* opf32Rate = pcObj->m_bEnableDebug ? pcObj->m_af32DebugAttackRate[m_s32DebugAttackType]
                                               : (m_s32DebugAttackType == 0
                                                      ? nspFusionMachine::toaf32AttackCheckTable1
                                                      : nspFusionMachine::toaf32AttackCheckTable2);
        for (s32 s32i = 0; s32i < 4; ++s32i) {
            NNS_VECTORFAST sPosVecFast;
            // Original advances twice per iteration, reading entries 1, 3, 5 and 7.
            pcObj->m_cPath.getPathPointToRate(*++opf32Rate, &sPosVecFast);
            clsPfDraw3d::GS()->renderSphere(clsTaskManager::GS()->getCurViewNo(),
                                            reinterpret_cast<const NNS_VECTOR*>(&sPosVecFast),
                                            10.0f,
                                            0xd2648c64,
                                            16);
            ++opf32Rate;
        }
    }
    if (m_bDebugPosDisp) {
        NNS_VECTORFAST sPosVecFast;
        nnCopyVectorFast(&sPosVecFast, &pcObj->m_sPosVecFast);
        nnPrint(10, 25, "Pos X = %.3f", sPosVecFast.x);
        nnPrint(10, 26, "Pos Y = %.3f", sPosVecFast.y);
        nnPrint(10, 27, "Pos Z = %.3f", sPosVecFast.z);
    }
    if (clsOOProfile::GS()->m_bRunning) {
        clsOOProfile::GS()->end("Boss Draw");
    }
}
