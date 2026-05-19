#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/ComAI.hpp"

static u8 chk__clsComAI_t_pfExecAI_SizeCheck_[1];

u32 t_ou32ComEstimateMaxPoint;
f32 t_of32ComMaxSpeed;
f32 t_of32ComMinSpeed;
f32 t_of32ComAvgSpeed;
f32 t_of32ComAddAccele;
f32 t_of32ComSubAccele;
f32 t_of32ComDecAccele;
f32 t_of32ComDelayMinSpeed;
u32 t_ou32ComShortTime;
s32 t_os32ComFreeAddSub;
f32 t_of32ComChangeSpeed;
f32 t_of32ComMaxSpeed_2;
f32 t_of32ComMinSpeed_2;
f32 t_of32St13BunkiStartFrameA;
f32 t_of32St13BunkiEndFrameA;
f32 t_of32St13BunkiStartFrameB;
f32 t_of32St13BunkiEndFrameB;
f32 t_of32St13BunkiLimitFrame;
f32 t_of32St7WallSubTimeFrame;
u32 t_ou32St7WallSubTimeCount;

// Static definitions
u32 clsComAI::t_ou32ComGrindAccessWaitFirst;
u32 clsComAI::t_ou32ComGrindAccessWaitDefault;
u32 clsComAI::t_ou32ComGDiveTryAgpVal;
u32 clsComAI::t_ou32ComGCtrlMaxRestFrame;
u32 clsComAI::t_ou32ComGCtrlHighRestFrame;
u32 clsComAI::t_ou32ComGCtrlMinRestFrame;
u32 clsComAI::t_ou32ComWallRunTrickFrame;
u32 clsComAI::t_ou32ComWallRunGCtrlMaxFrame;
u32 clsComAI::t_ou32ComWheelDriftMaxFrame;
f32 clsComAI::t_of32ComCollisionCheckFrame;
f32 clsComAI::t_of32ComPositionCheck;
f32 clsComAI::t_of32St6SubMainLength;
f32 clsComAI::t_of32St13SubMainLength;
void* clsComAI::t_pfExecAI[15];

void clsComAI::clearData()
{
}

void clsComAI::setPlannedRank(u8 u8Rank)
{
}

void clsComAI::updateTime()
{
}

u8 clsComAI::controlRoundTime()
{
    return 0;
}

u8 clsComAI::controlGoalTime(s8 s8Lever)
{
    return 0;
}

s8 clsComAI::execPrece(s8 s8Reserve)
{
    return 0;
}

s8 clsComAI::execPullOut(s8 s8Reserve)
{
    return 0;
}

s8 clsComAI::execKeep(s8 s8Reserve)
{
    return 0;
}

s8 clsComAI::execDingDong(s8 s8Reserve)
{
    return 0;
}

s8 clsComAI::execCorrection(s8 s8Reserve)
{
    return 0;
}

void clsComAI::DivergenceSt13()
{
}

void clsComAI::updateNextTrickRank()
{
}

f32 clsComAI::getEnableLineAttributeRate(u16 u16LineAttr)
{
    return 0.0f;
}

void clsComAI::selectLine(clsRetPath& rcRetPath, u16 u16PlannedLine)
{
}

void clsComAI::calcPlayerDirectionToPoint(const f32 (*psBaseMtx)[4][4],
                                          const NNS_VECTORFAST* psEndPoint,
                                          f32* pf32AngleDiffX,
                                          f32* pf32AngleDiffY)
{
}

void clsComAI::EstimatePath()
{
}

u8 clsComAI::updateAILine(u32 u32DisableRoot)
{
    return 0;
}

clsComAI::~clsComAI()
{
}
