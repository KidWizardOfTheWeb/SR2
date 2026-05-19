#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"

f32 clsHavok::t_of32WeightTypeGround = 0.0f;
f32 clsHavok::t_of32WeightTypeLight = 50.0f;
f32 clsHavok::t_of32WeightTypeSuperLight = 100.0f;
f32 clsHavok::t_of32WeightTypeMiddle = 250.0f;
f32 clsHavok::t_of32WeightTypeSuperMiddle = 500.0f;
f32 clsHavok::t_of32WeightTypeHeavy = 1000.0f;
f32 clsHavok::t_of32WeightTypeSuperHeavy = 2000.0f;
hkClass* StaticLinkedClasses[276];
hkTypeInfo* StaticLinkedTypeInfos[244];
void* (*hkSystemMalloc)(s32, s32);
void (*hkSystemFree)(void*);

void clsHavok::registerAgents(hkCollisionDispatcher* dis)
{
}

void clsHavok::createWorld()
{
}

void clsHavok::destroyWorld()
{
}

clsHavok& clsHavok::createInstance(u32 u32Param1)
{
    return RS();
}

void clsHavok::init()
{
}

void clsHavok::exit()
{
}

void clsHavok::drawShape(u32 u32ViewNo,
                         const hkShape* pcShape,
                         const hkTransform& rcTransform,
                         u8 u8Alpha)
{
}
