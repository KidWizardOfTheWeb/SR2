#include "Develop/Projects/SR2/pgm/src/Data/Portal.hpp"

static NNS_PRIM3D_PC tasPrim3D_PC_Polygon[10];
static NNS_VECTORFAST tsDpPosFast = {0.0f, 0.0f, 0.0f, 1.0f};
c8* ac8NameBool[2] = {"NON", "USE"};

f32 clsPortal::DOT_PRODUCT_BACK_DEG = 30.0f;

s32 compare_Type(const clsPortal::stcPortalDetail* pA, const clsPortal::stcPortalDetail* pB)
{
    u8 u8a = pA->u8Type;
    u8 u8b = pB->u8Type;
    u8 a = u8a - ((u8a >= 0x81) << 6);
    u8 b = u8b - ((u8b >= 0x81) << 6);
    s32 result = (u8)(a - ((a >= 0x61) << 5)) - (u8)(b - ((b >= 0x61) << 5));

    if (result == 0) {
        result = u8a - u8b;
    }

    return result;
}

void clsPortal::setPortal(u8* pu8BinI, enmPortalType ePortalTypeI)
{
}

void clsPortal::update(u32 u32vI, const NNS_VECTOR& orsPosI, bool bReverse)
{
}

u8 clsPortal::getPortal(const NNS_VECTORFAST& rosPosVecFast)
{
    return 0;
}

c8* clsPortal::getStrEx_Debug(u8 u8TypeI)
{
    return 0;
}

clsPortalEditor_Debug_Task::clsPortalEditor_Debug_Task(const clsPortal* opcSrcPortalI)
    : clsTask(0, 0)
{
}

clsPortalEditor_Debug_Task::~clsPortalEditor_Debug_Task()
{
}

void clsPortalEditor_Debug_Task::drawLeftList(bool bActiveI, bool bDraw3dI)
{
}

void clsPortalEditor_Debug_Task::drawPortalDetail(const clsPortal::stcPortalDetail& orsDetailI,
                                                  bool bActiveI)
{
}

void clsPortalEditor_Debug_Task::savePortalData()
{
}

void clsPortalEditor_Debug_Task::draw()
{
}
