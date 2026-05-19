#include "Develop/Projects/SR2/pgm/src/Camera/SetCamColli.hpp"
#include "Develop/Projects/SR2/pgm/src/Camera/CameraTbl.hpp"
#include "Develop/Projects/SR2/pgm/src/System/SrCamCtrl.hpp"

namespace nspCamTbl {
u32 oau32SCamStageNum[16] = {40, 45, 30, 32, 29, 49, 12, 21, 32, 28, 23, 24, 21, 35, 14, 22};
u32 oau32SCamLookTargetNum[16] = {24, 28, 19, 14, 17, 34, 12, 19, 15, 15, 17, 17, 19, 23, 12, 14};
u32 oau32SCamVectorNum[16] = {3, 5, 2, 2, 1, 1, 1, 1, 1, 3, 2, 1, 1, 3, 1, 1};
u32 oau32SCamFilterNum[16] = {7, 5, 1, 16, 9, 8, 1, 1, 10, 9, 1, 7, 1, 7, 2, 3};

stcBaseSetCam* sBaseSetCamAll[16];
stcBaseSetCam sBaseSetCamStg00[40];
stcBaseSetCam sBaseSetCamStg01[45];
stcBaseSetCam sBaseSetCamStg02[30];
stcBaseSetCam sBaseSetCamStg03[32];
stcBaseSetCam sBaseSetCamStg04[29];
stcBaseSetCam sBaseSetCamStg05[49];
stcBaseSetCam sBaseSetCamStg06[12];
stcBaseSetCam sBaseSetCamStg07[21];
stcBaseSetCam sBaseSetCamStg08[32];
stcBaseSetCam sBaseSetCamStg09[28];
stcBaseSetCam sBaseSetCamStg10[23];
stcBaseSetCam sBaseSetCamStg11[24];
stcBaseSetCam sBaseSetCamStg12[21];
stcBaseSetCam sBaseSetCamStg13[35];
stcBaseSetCam sBaseSetCamStg14[14];
stcBaseSetCam sBaseSetCamStg15[22];

nspSetCam::stcSCamLookPlayer* sLookTargetSetCamAll[16];
nspSetCam::stcSCamLookPlayer sLookTargetStg00[24];
nspSetCam::stcSCamLookPlayer sLookTargetStg01[28];
nspSetCam::stcSCamLookPlayer sLookTargetStg02[19];
nspSetCam::stcSCamLookPlayer sLookTargetStg03[14];
nspSetCam::stcSCamLookPlayer sLookTargetStg04[17];
nspSetCam::stcSCamLookPlayer sLookTargetStg05[34];
nspSetCam::stcSCamLookPlayer sLookTargetStg06[12];
nspSetCam::stcSCamLookPlayer sLookTargetStg07[19];
nspSetCam::stcSCamLookPlayer sLookTargetStg08[15];
nspSetCam::stcSCamLookPlayer sLookTargetStg09[15];
nspSetCam::stcSCamLookPlayer sLookTargetStg10[17];
nspSetCam::stcSCamLookPlayer sLookTargetStg11[17];
nspSetCam::stcSCamLookPlayer sLookTargetStg12[19];
nspSetCam::stcSCamLookPlayer sLookTargetStg13[23];
nspSetCam::stcSCamLookPlayer sLookTargetStg14[12];
nspSetCam::stcSCamLookPlayer sLookTargetStg15[14];

nspSetCam::stcSCamVector* sVectorSetCamAll[16];
nspSetCam::stcSCamVector sVectorStg00[3];
nspSetCam::stcSCamVector sVectorStg01[5];
nspSetCam::stcSCamVector sVectorStg02[2];
nspSetCam::stcSCamVector sVectorStg03[2];
nspSetCam::stcSCamVector sVectorStg04[1];
nspSetCam::stcSCamVector sVectorStg05[1];
nspSetCam::stcSCamVector sVectorStg06[1];
nspSetCam::stcSCamVector sVectorStg07[1];
nspSetCam::stcSCamVector sVectorStg08[1];
nspSetCam::stcSCamVector sVectorStg09[3];
nspSetCam::stcSCamVector sVectorStg10[2];
nspSetCam::stcSCamVector sVectorStg11[1];
nspSetCam::stcSCamVector sVectorStg12[1];
nspSetCam::stcSCamVector sVectorStg13[3];
nspSetCam::stcSCamVector sVectorStg14[1];
nspSetCam::stcSCamVector sVectorStg15[1];

stcCamFilter* apsFilterSetCamAll[16];
stcCamFilter sCamFilterStg00[7];
stcCamFilter sCamFilterStg01[5];
stcCamFilter sCamFilterStg02[1];
stcCamFilter sCamFilterStg03[16];
stcCamFilter sCamFilterStg04[9];
stcCamFilter sCamFilterStg05[8];
stcCamFilter sCamFilterStg06[1];
stcCamFilter sCamFilterStg07[1];
stcCamFilter sCamFilterStg08[10];
stcCamFilter sCamFilterStg09[9];
stcCamFilter sCamFilterStg10[1];
stcCamFilter sCamFilterStg11[7];
stcCamFilter sCamFilterStg12[1];
stcCamFilter sCamFilterStg13[7];
stcCamFilter sCamFilterStg14[2];
stcCamFilter sCamFilterStg15[3];
} // namespace nspCamTbl

clsSetCamColli_Task::clsSetCamColli_Task() : clsTask(0, 0)
{
}

void clsSetCamColli_Task::execute()
{
}

void clsSetCamColli_Task::draw()
{
}

void clsSetCamColli_Obj::init()
{
}

void clsSetCamColli_Obj::execute()
{
}

void clsSetCamColli_Obj::contactTriggerEvent(clsPlayerTask* pcPlayer)
{
}

void clsSetCamColli_Obj::contactAlwaysEvent(clsPlayerTask* pcPlayer)
{
}

void clsSetCamColli_Obj::contactRemoveEvent(clsPlayerTask* pcPlayer)
{
}

clsSetCamColli_Task::~clsSetCamColli_Task()
{
}
