#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage12/St12PathCanoeMotion.hpp"

f32 clsPathCanoeMotion_Obj::tof32ClipSqDist = 0.0f;
u32 clsPathCanoeMotion_Obj::otau32Se_CanoeBreak[2] = {396713, 529833};
u32 clsPathCanoeMotion_Obj::otau32Se_CanoeExp[2] = {462249, 595369};
u32 clsPathCanoeMotion_Obj::otau32Se_CanoeL[2] = {134574, 333230};

void clsPathCanoeMotion_Obj::init()
{
}

void clsPathCanoeMotion_Obj::initParameter()
{
}

void clsPathCanoeMotion_Obj::createData()
{
}

void clsPathCanoeMotion_Obj::reset()
{
}

void clsPathCanoeMotion_Obj::path_main()
{
}

void clsPathCanoeMotion_Obj::requestDrawBreakEffect()
{
}

void clsPathCanoeMotion_Obj::setData()
{
}

void clsPathCanoeMotion_Obj::main()
{
}

u8 clsPathCanoeMotion_Obj::draw(clsModelType_OB_TX_MO& m,
                                f32 (*a)[4][4],
                                u32* b,
                                const f32 (*c)[4][4],
                                f32 (*d)[4][4],
                                u32 e,
                                f32* f)
{
    return 0;
}

void clsPathCanoeMotion_Obj::callbackGravityEvent()
{
}

void clsPathCanoeMotion_Obj::destroyData()
{
}

void clsPathCanoeMotion_Obj::callbackCrashEvent()
{
}

void clsPathCanoeMotion_Obj::contactTriggerEvent(hkContactPoint* p, clsObject* o)
{
}

void clsPathCanoeMotion_Obj::boundAction(clsPlayerTask* p)
{
}

clsPathCanoeMotion_Task::clsPathCanoeMotion_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsPathCanoeMotion_Task,
                                 clsPathCanoeMotion_Obj,
                                 clsModelType_OB_TX_MO>(u32ObjectAreaNum, 0)
{
}

void clsPathCanoeMotion_Task::reset()
{
}

void clsPathCanoeMotion_Task::execute()
{
}

void clsPathCanoeMotion_Task::draw()
{
}
