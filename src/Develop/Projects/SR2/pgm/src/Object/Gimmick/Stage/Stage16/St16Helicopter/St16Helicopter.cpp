#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage16/St16Helicopter/St16Helicopter.hpp"

namespace nspSt16Helicopter {
static stcPointData tosPoint00[7];
static stcPointData tosPoint01[7];
static stcPointData tosPoint02[7];
static stcPointData tosPoint03[7];
static stcPointData tosPoint04[7];
static stcPointData tosPoint05[7];
static stcPointData tosPoint06[4];
static stcPointData tosPoint07[4];
static stcPointData tosPoint08[7];
static stcPointData tosPoint09[7];
static stcPointData tosPoint10[5];
static stcPointData tosPoint11[7];
static stcPointData tosPoint12[7];
static u8 toau8PointArrayNumTbl[13];
static s8 toas8PointDataTbl[11][3];
static stcPointData* toapsPointTbl[13];
} // namespace nspSt16Helicopter

NNS_PRIM3D_PCT clsHelicopter_Obj::t_asPrim3D_PCT_Polygon[4];
s32 clsHelicopter_Obj::t_s32TryPrim3D_PCT_Num;
f32 clsHelicopter_Obj::t_of32ClipDistx2;
NNS_VECTORFAST clsHelicopter_Obj::t_osLightOffsetPosVecFast;

void clsHelicopter_Obj::reset()
{
}

void clsHelicopter_Obj::setData()
{
}

void clsHelicopter_Obj::createData()
{
}

void clsHelicopter_Obj::destroyData()
{
}

void clsHelicopter_Obj::start()
{
}

void clsHelicopter_Obj::calcDirVecFast()
{
}

void clsHelicopter_Obj::getNextPointRotate(NNS_QUATERNION& rQuat, u32 u32Idx)
{
}

void clsHelicopter_Obj::slowDown(f32 f32Speed)
{
}

void clsHelicopter_Obj::callbackGravityEvent()
{
}

void clsHelicopter_Obj::requestDrawContactEffect(const hkContactPoint* p)
{
}

void clsHelicopter_Obj::requestDrawBreakEffect()
{
}

void clsHelicopter_Obj::main()
{
}

void clsHelicopter_Obj::draw(clsModelType_OB_TX_MO& rModel,
                             f32 (*pMtx)[4][4],
                             u32* pu32Flg,
                             const f32 (*pBaseMtx)[4][4],
                             f32 (*pDstMtx)[4][4],
                             u32 u32Arg1,
                             u32 u32Arg2)
{
}

void clsHelicopter_Manager::setData()
{
}

void clsHelicopter_Manager::createData()
{
}

void clsHelicopter_Manager::destroyData()
{
}

void clsHelicopter_Manager::contactAlwaysEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
}

void clsHelicopter_Manager::draw(clsModelType_OB_TX_MO& rParam1,
                                 f32 (*psMtxPal)[4][4],
                                 u32* pParam3,
                                 const f32 (*opaNnViewMtx)[4][4],
                                 f32 (*psMtxWork)[4][4],
                                 u32 u32Param6)
{
}

clsHelicopter_Task::clsHelicopter_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0)
{
}

void clsHelicopter_Task::reset()
{
}

void clsHelicopter_Task::execute()
{
}

void clsHelicopter_Task::draw()
{
}

clsHelicopter_Manager::clsHelicopter_Manager() : clsPhantomGimmickObject()
{
}

clsHelicopter_Manager::~clsHelicopter_Manager()
{
}

void clsHelicopter_Manager::init()
{
}

nspPackId::enm clsHelicopter_Manager::getPackId() const
{
    return nspPackId::ST16_HELICOPTER_26000;
}

clsHelicopter_Task::~clsHelicopter_Task()
{
}
