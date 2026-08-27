#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/ProductionRobo/ProductionRobo.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

namespace {
static f32 tof32FollowMargin[2] = {-15.0f, -8.0f};
static clsBackLineEffectTask::stcParam asRoboBallLineParam[2] = {
    {2,
     0,
     0xFF,
     0xFF,
     2,
     25,
     0x0000FFFF,
     0.0f,
     1.0f,
     {0.06f, 0.15f, -0.02f, 0.0f},
     {0.26f, 0.02f, 0.1f, 0.0f}},
    {2,
     0,
     0xFF,
     0xFF,
     3,
     25,
     0xE01414FF,
     0.0f,
     1.0f,
     {-0.06f, 0.15f, -0.02f, 0.0f},
     {-0.26f, 0.02f, 0.1f, 0.0f}},
};
static clsBackLineEffectTask::stcParam asRoboStandLineParam[2] = {
    {2,
     0,
     0xFF,
     0xFF,
     4,
     25,
     0x0000FFFF,
     0.0f,
     1.0f,
     {-0.15f, 0.0f, 0.15f, 0.0f},
     {0.23f, 0.04f, 0.01f, 0.0f}},
    {2,
     0,
     0xFF,
     0xFF,
     10,
     25,
     0xE01414FF,
     0.0f,
     1.0f,
     {0.15f, 0.0f, 0.15f, 0.0f},
     {-0.23f, 0.04f, 0.01f, 0.0f}},
};
static stcGimickSubParam asRoboLineSubParam[2] = {
    {{0.1f, 0.0f, 0.0f, 1.0f}, {-0.005f, 0.0f, 0.0f, 1.0f}},
    {{-0.1f, 0.0f, 0.0f, 1.0f}, {0.005f, 0.0f, 0.0f, 1.0f}},
};
static u8 chk__asRoboBallLineParam_SizeCheck_[1];
static u8 chk__asRoboStandLineParam_SizeCheck_[1];
static u8 chk__asRoboLineSubParam_SizeCheck_[1];
} // namespace

u32 clsProductionRobo_Obj::otau32Se_AirCarL[2] = {199342, 660142};
u32 clsProductionRobo_Obj::otau32Se_SirenL[2] = {395950, 594606};

clsProductionRobo_Obj::clsProductionRobo_Obj()
{
}

clsProductionRobo_Obj::~clsProductionRobo_Obj()
{
}

void clsProductionRobo_Obj::setLineParam(NNS_OBJECT* pParam1, NNS_MOTION* pParam2, f32* pParam3)
{
}

void clsProductionRobo_Obj::reset()
{
}

void clsProductionRobo_Obj::start(clsPlayerTask* pParam1)
{
}

void clsProductionRobo_Obj::createData()
{
}

void clsProductionRobo_Obj::destroyData()
{
}

void clsProductionRobo_Obj::stepMotionFrame()
{
}

void clsProductionRobo_Obj::setPosturalCtrl(const NNS_VECTORFAST& rParam1,
                                            f32 f32Param2,
                                            f32 f32Param3)
{
}

void clsProductionRobo_Obj::setReturnPath()
{
}

void clsProductionRobo_Obj::setSurfaceDir(NNS_VECTORFAST& rParam1, NNS_VECTORFAST& rParam2)
{
}

void clsProductionRobo_Obj::checkPlayerRestart()
{
}

void clsProductionRobo_Obj::requestDrawBreakEffect()
{
}

void clsProductionRobo_Obj::callbackGravityEvent()
{
}

void clsProductionRobo_Obj::contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
}

void clsProductionRobo_Obj::main()
{
}

void clsProductionRobo_Obj::draw(clsSecurityRoboModels* pParam1,
                                 f32 (*)[4][4],
                                 u32* pParam3,
                                 const f32 (*)[4][4],
                                 f32 (*)[4][4],
                                 f32 f32Param6)
{
}
