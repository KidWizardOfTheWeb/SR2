#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04PathCanoe.hpp"

f32 clsPathCanoe_Obj::tof32ClipSqDist;
u32 clsPathCanoe_Obj::otau32Se_CanoeBreak[2];
u32 clsPathCanoe_Obj::otau32Se_CanoeExp[2];
u32 clsPathCanoe_Obj::otau32Se_CanoeL[2];

void clsPathCanoe_Obj::init()
{
}

void clsPathCanoe_Obj::initParameter()
{
}

void clsPathCanoe_Obj::createData()
{
}

void clsPathCanoe_Obj::reset()
{
}

void clsPathCanoe_Obj::path_main()
{
}

void clsPathCanoe_Obj::chackAction(u32 u32Param1)
{
}

void clsPathCanoe_Obj::requestDrawBreakEffect()
{
}

void clsPathCanoe_Obj::setData()
{
}

void clsPathCanoe_Obj::main()
{
}

u8 clsPathCanoe_Obj::draw(clsModelType_OB_TX& rParam1,
                          f32 (*)[4][4],
                          u32* pParam3,
                          const f32 (*)[4][4],
                          f32 (*)[4][4],
                          u32 u32Param6)
{
    return 0;
}

void clsPathCanoe_Obj::callbackGravityEvent()
{
}

void clsPathCanoe_Obj::destroyData()
{
}

void clsPathCanoe_Obj::callbackCrashEvent()
{
}

void clsPathCanoe_Obj::contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2)
{
}

void clsPathCanoe_Obj::boundAction(clsPlayerTask* pParam1)
{
}

clsPathCanoe_Task::clsPathCanoe_Task(u32 packId)
    : clsSingleModelGimmick_Task<clsPathCanoe_Task, clsPathCanoe_Obj, clsModelType_OB_TX>(packId, 0)
{
}

void clsPathCanoe_Task::reset()
{
}

void clsPathCanoe_Task::execute()
{
}

void clsPathCanoe_Task::draw()
{
}
