#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotFallGLink/St05RotFallGLinkObject.hpp"

f32 clsRotFallGLink_Object::t_f32OffsetSide;
f32 clsRotFallGLink_Object::t_oaf32FallSpeed[2];
f32 clsRotFallGLink_Object::t_of32FallAccele;
f32 clsRotFallGLink_Object::t_oaf32IntervalFrame[2];
f32 clsRotFallGLink_Object::t_oaf32OffsetSide[2];
NNS_VECTOR clsRotFallGLink_Object::tosCollisionHalfSizeVec;
f32 clsRotFallGLink_Object::tof32ClipSqDist;
clsGravityGimmickParam clsRotFallGLink_Object::t_ocGravityGimmickParam;
f32 clsRotFallGLink_Object::t_sBaseMtx[4][4];
f32 clsRotFallGLink_Object::t_sBaseInvMtx[4][4];
NNS_VECTORFAST clsRotFallGLink_Object::t_sDirVecFast;
s32 clsRotFallGLink_Object::t_s32AppearCount;
f32 clsRotFallGLink_Object::t_f32AppearFrame;
clsGravityGimmickParam* clsRotFallGLink_Object::t_opcGravityGimmickParam;
f32 clsRotFallGLink_Object::t_f32FallSpeed;
f32 clsRotFallGLink_Object::t_f32IntervalFrame;

u8 clsRotFallGLink_Object::draw(NNS_OBJECT* pParam1,
                                f32 (*)[4][4],
                                u32* pParam3,
                                const f32 (*)[4][4],
                                f32 (*)[4][4],
                                u32 u32Param6)
{
    return 0;
}

void clsRotFallGLink_Object::reset()
{
}

void clsRotFallGLink_Object::main()
{
}

void clsRotFallGLink_Object::requestDrawContactEffect(const hkContactPoint* pParam1)
{
}

void clsRotFallGLink_Object::requestDrawBreakEffect()
{
}

void clsRotFallGLink_Object::drawEffect(clsPlayerTask* pParam1)
{
}

void clsRotFallGLink_Object::setData()
{
}

void clsRotFallGLink_Object::createData()
{
}

void clsRotFallGLink_Object::destroyData()
{
}
