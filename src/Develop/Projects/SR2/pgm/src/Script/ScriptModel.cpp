#include "Develop/Projects/SR2/pgm/src/Script/ScriptModel.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

static stcGimickSubParam ScriptBackLineSubParam;

clsScriptModel_Task::clsScriptModel_Task(s32 s32No,
                                         u32 u32Arg0,
                                         u32 u32Arg1,
                                         u32 u32Arg2,
                                         u32 u32Arg3,
                                         clsTask* pcTask,
                                         u8 u8Arg4,
                                         u8 u8Arg5)
    : clsTask(0, 0)
{
}

clsScriptModel_Task::~clsScriptModel_Task()
{
}

void clsScriptModel_Task::dispBackLineEffect(u32 u32Show, s32 s32No)
{
}

void clsScriptModel_Task::clearBackLineEffect(s32 s32No)
{
}

void clsScriptModel_Task::setBackLineEffect(s32 s32No,
                                            u32 u32NodeNo,
                                            s32 s32DataNum,
                                            f32 f32Width,
                                            f32 f32Height,
                                            f32 f32OfsX,
                                            f32 f32OfsY,
                                            f32 f32OfsZ)
{
}

void clsScriptModel_Task::setNodeOffset(u32 u32Arg0, u32 u32Arg1, u32 u32Arg2)
{
}

void clsScriptModel_Task::setWaitFrame(f32 f32Frame)
{
}

void clsScriptModel_Task::getNodePos(NNS_VECTOR* psVec, u32 u32NodeNo, f32 (*ppfMtx)[4][4])
{
}

void clsScriptModel_Task::getNodeMtx(f32 (*ppfMtx0)[4][4], u32 u32NodeNo, f32 (*ppfMtx1)[4][4])
{
}

void clsScriptModel_Task::releaseOldMorpf()
{
}

void clsScriptModel_Task::update()
{
}

void clsScriptModel_Task::executeModel()
{
}

void clsScriptModel_Task::calcMtx(bool bFlag)
{
}

void clsScriptModel_Task::execute()
{
}

void clsScriptModel_Task::drawModel(f32 (*ppfMtx)[4][4])
{
}

void clsScriptModel_Task::draw()
{
}
