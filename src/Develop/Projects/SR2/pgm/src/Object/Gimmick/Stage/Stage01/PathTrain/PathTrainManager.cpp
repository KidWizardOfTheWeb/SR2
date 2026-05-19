#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/PathTrain/PathTrainManager.hpp"

u32 clsPathTrainManager_Obj::otau32Se_TrainHorn[2] = {2734 /* 0xAAE */, 135854 /* 0x212AE */};
u32 clsPathTrainManager_Obj::otau32Se_TrainL[2] = {68270 /* 0x10AAE */, 201390 /* 0x312AE */};

void clsPathTrainThroughCol::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsPathTrainManager_Obj::setData()
{
}

void clsPathTrainManager_Obj::createData()
{
}

void clsPathTrainManager_Obj::destroyData()
{
}

void clsPathTrainManager_Obj::start()
{
}

void clsPathTrainManager_Obj::execute()
{
}

void clsPathTrain_Task::reset()
{
}

void clsPathTrain_Task::createModel(stcBinInfo& rBinInfo)
{
}

void clsPathTrain_Task::execute()
{
}

void clsPathTrain_Task::draw()
{
}

clsPathTrain_Task::clsPathTrain_Task(u32 param)
    : clsBaseGimmickBody<clsPathTrain_Task, clsPathTrainManager_Obj, clsModelType_OB_TX_MO_MA>(0, 0)
{
}

clsPathTrain_Task::~clsPathTrain_Task()
{
}
