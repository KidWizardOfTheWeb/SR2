#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionPathTarget.hpp"

clsMissionPathTarget_Obj::clsMissionPathTarget_Obj()
{
}

void clsMissionPathTarget_Obj::init()
{
}

void clsMissionPathTarget_Obj::reset()
{
}

void clsMissionPathTarget_Obj::createData()
{
}

void clsMissionPathTarget_Obj::destroyData()
{
}

void clsMissionPathTarget_Obj::calcPathPostural()
{
}

void clsMissionPathTarget_Obj::draw(clsModelType_OB_TX& rcObj,
                                    f32 (*psMtxPal)[4][4],
                                    u32* psNodeStat,
                                    const f32 (*opaNnViewMtx)[4][4],
                                    f32 (*psMtxWork)[4][4],
                                    u32 u32Param6)
{
}

u8 clsMissionPathTarget_Obj::nextSearchPath()
{
    return 0;
}

void clsMissionPathTarget_Obj::main()
{
}

clsMissionPathTarget_Task::clsMissionPathTarget_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsMissionPathTarget_Task,
                                 clsMissionPathTarget_Obj,
                                 clsModelType_OB_TX>(0, 0)
{
}

s32 clsMissionPathTarget_Task::getPathPoint()
{
    return 0;
}

NNS_VECTORFAST* clsMissionPathTarget_Task::getPosVecFastPtr()
{
    return 0;
}

void clsMissionPathTarget_Task::reset()
{
}

void clsMissionPathTarget_Task::execute()
{
}

void clsMissionPathTarget_Task::draw()
{
}

clsMissionPathTarget_Task::~clsMissionPathTarget_Task()
{
}

void clsMissionPathTarget_Task::setMode(u32)
{
}

void clsMissionPathTarget_Task::addMode()
{
}

void clsMissionPathTarget_Task::addMode(u32)
{
}

void clsMissionPathTarget_Task::subMode()
{
}

void clsMissionPathTarget_Task::subMode(u32)
{
}

void clsMissionPathTarget_Task::reinitMode()
{
}

void clsMissionPathTarget_Task::createModel(stcBinInfo& rsBinInfo)
{
}

void clsMissionPathTarget_Task::setSetData(const stcSetDataDetail& rsDetail)
{
}

nspPackId::enm clsMissionPathTarget_Task::getPackId() const
{
    return nspPackId::MISSION_PATH_TARGET_27000;
}
