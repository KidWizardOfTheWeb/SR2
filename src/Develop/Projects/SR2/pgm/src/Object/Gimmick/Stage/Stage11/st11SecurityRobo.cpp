#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/st11SecurityRobo.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

namespace {
static stcParam asRoboBallLineParam[2] = {
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
static stcParam asRoboStandLineParam[2] = {
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

clsGravityGimmickParam clsPathSecurityRobo_Obj::t_ocGravityGimmickParam;

void clsPathSecurityRobo_Obj::reset()
{
}

void clsPathSecurityRobo_Obj::start(clsPlayerTask* pcPlayer)
{
}

void clsPathSecurityRobo_Obj::setData()
{
}

void clsPathSecurityRobo_Obj::createData()
{
}

void clsPathSecurityRobo_Obj::destroyData()
{
}

void clsPathSecurityRobo_Obj::stepMotionFrame()
{
}

void clsPathSecurityRobo_Obj::setPosturalCtrl(const struct NNS_VECTORFAST& rsDirVecFast,
                                              f32 f32InterpolateRate,
                                              f32 f32RotZ)
{
}

void clsPathSecurityRobo_Obj::setReturnPath()
{
}

void clsPathSecurityRobo_Obj::setSurfaceDir(struct NNS_VECTORFAST& rsVerocityFast,
                                            struct NNS_VECTORFAST& rsDirVecFast)
{
}

void clsPathSecurityRobo_Obj::checkPlayerRestart()
{
}

void clsPathSecurityRobo_Obj::requestDrawBreakEffect()
{
}

void clsPathSecurityRobo_Obj::callbackGravityEvent()
{
}

void clsPathSecurityRobo_Obj::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
}

void clsPathSecurityRobo_Obj::callbackContactTriggerRigidBody(
    const hkContactPointConfirmedEvent& cEvent)
{
}

void clsPathSecurityRobo_Obj::main()
{
}

void clsPathSecurityRobo_Obj::draw(clsSt11SecurityRoboModels* pcModels,
                                   f32 (*psMtxPal)[4][4],
                                   u32* psNodeStat,
                                   const f32 (*opaNnViewMtx)[4][4],
                                   f32 (*psMtxWork)[4][4],
                                   f32 f32Param)
{
}
