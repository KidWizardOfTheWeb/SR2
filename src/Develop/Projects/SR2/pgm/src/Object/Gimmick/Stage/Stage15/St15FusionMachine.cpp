#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15FusionMachine.hpp"

// clsFusionMachine_Task stubs

namespace {
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
    : clsSingleModelGimmick_Task<clsFusionMachine_Task,
                                 clsFusionMachine_Obj,
                                 clsFusionMachineModels>(packId, 0)
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

void clsFusionMachine_Task::draw()
{
}
