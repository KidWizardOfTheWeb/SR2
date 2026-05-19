#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotFall/St05RotFallObject.hpp"

f32 clsRotFall_Object::tof32ClipSqDist = 0.0f;
f32 clsRotFall_Object::t_of32FallHeighTable[14] = {100.0f,
                                                   100.0f,
                                                   100.0f,
                                                   100.0f,
                                                   100.0f,
                                                   100.0f,
                                                   100.0f,
                                                   100.0f,
                                                   100.0f,
                                                   400.0f,
                                                   400.0f,
                                                   400.0f,
                                                   400.0f,
                                                   400.0f};
NNS_VECTOR clsRotFall_Object::t_osScaleVec[3];
f32 clsRotFall_Object::t_f32AppearFrame;
u8 clsRotFall_Object::t_au8ModelTypeTable[14];

void clsRotFall_Object::reset()
{
}

void clsRotFall_Object::main()
{
}

void clsRotFall_Object::draw(clsMultiObTxModels& rcObj,
                             f32 (*psMtxPal)[4][4],
                             u32* psNodeStat,
                             const f32 (*opaNnViewMtx)[4][4],
                             f32 (*psMtxWork)[4][4])
{
}

void clsRotFall_Object::clearAppearFrame()
{
}

void clsRotFall_Object::countAppearFrame()
{
}

void clsRotFall_Object::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsRotFall_Object::requestDrawBreakEffect()
{
}

void clsRotFall_Object::setData()
{
}

void clsRotFall_Object::createData()
{
}

void clsRotFall_Object::destroyData()
{
}
