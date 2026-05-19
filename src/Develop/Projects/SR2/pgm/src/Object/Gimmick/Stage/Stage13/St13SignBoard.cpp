#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13SignBoard.hpp"

f32 clsSignBoard_Obj::m_tof32CLIP_DISTx2 = 0.0f;

void clsSignBoard_Obj::init()
{
}

void clsSignBoard_Obj::reset()
{
}

void clsSignBoard_Obj::setData()
{
}

void clsSignBoard_Obj::createData()
{
}

void clsSignBoard_Obj::destroyData()
{
}

void clsSignBoard_Obj::main()
{
}

void clsSignBoard_Obj::draw(clsModelType_OB_TX& rcModel,
                            f32 (*psMtxPal)[4][4],
                            u32* psNodeStat,
                            const f32 (*opaNnViewMtx)[4][4],
                            f32 (*psMtxWork)[4][4],
                            u32 u32ViewNo)
{
}

clsSignBoard_Task::clsSignBoard_Task(u32 param)
    : clsSingleModelGimmick_Task<clsSignBoard_Task, clsSignBoard_Obj, clsModelType_OB_TX>(param, 0)
{
}

void clsSignBoard_Task::reset()
{
}

void clsSignBoard_Task::execute()
{
}

void clsSignBoard_Task::draw()
{
}

clsSignBoard_Obj::clsSignBoard_Obj()
{
}

clsSignBoard_Obj::~clsSignBoard_Obj()
{
}

inline nspPackId::enm clsSignBoard_Obj::getPackId() const
{
    return nspPackId::PUT_GRAVITYOBJ_2100;
}
