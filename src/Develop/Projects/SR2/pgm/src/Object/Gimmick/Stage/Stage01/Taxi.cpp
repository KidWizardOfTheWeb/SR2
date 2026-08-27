#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/Taxi.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

namespace {
static clsBackLineEffectTask::stcParam asTaxiLineParam[2];
static stcGimickSubParam asTaxiLineSubParam[2];
static u8 chk__asTaxiLineParam_SizeCheck_[1];
static u8 chk__asTaxiLineSubParam_SizeCheck_[1];
static u8 tou8StageToPathNo[2][2] = {{18, 19}, {12, 13}};
} // namespace

u32 clsTaxi::otau32Se_AirCarL[2] = {199342, 660142};
u32 clsTaxi::otau32Se_TaxiDoor[2] = {199337, 463529};

clsTaxi::clsTaxi()
{
}

clsTaxi::~clsTaxi()
{
}

void clsTaxi::setLineParam(NNS_OBJECT* pcObj)
{
}

void clsTaxi_Obj::init()
{
}

void clsTaxi_Obj::createData()
{
}

void clsTaxi_Obj::destroyData()
{
}

void clsTaxi_Obj::contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2)
{
}

clsTaxi_Task::clsTaxi_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0x18A88)
{
}

void clsTaxi_Task::reset()
{
}

void clsTaxi_Task::execute()
{
}

void clsTaxi_Task::draw()
{
}

clsTaxi_Obj::clsTaxi_Obj()
{
}

clsTaxi_Obj::~clsTaxi_Obj()
{
}

void clsTaxi_Obj::controlPlayer()
{
}

void clsTaxi_Obj::elaseExexuteTaxi(clsTaxi* pTaxi)
{
}

void clsTaxi::destroy()
{
}

void clsTaxi::hideLine()
{
}

void clsTaxi::movePlayer()
{
}

void clsTaxi::draw(clsModelType_OB_TX& rModel,
                   f32 (*psDrawMtx)[4][4],
                   u32* pu32DrawFlag,
                   const f32 (*psGearMtx)[4][4],
                   f32 (*psDrawMtx2)[4][4],
                   u32 u32DrawFlag)
{
}
