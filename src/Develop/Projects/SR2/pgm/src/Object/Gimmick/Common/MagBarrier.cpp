#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/MagBarrier.hpp"

namespace {
static u8 chk__toaf32ScaleTbl_SizeCheck_[1];
static f32 toaf32ScaleTbl[19] = {1.4f,
                                 1.4f,
                                 1.4f,
                                 1.4f,
                                 1.4f,
                                 2.0f,
                                 1.4f,
                                 2.2f,
                                 1.3f,
                                 1.4f,
                                 1.4f,
                                 1.4f,
                                 1.4f,
                                 1.7f,
                                 1.3f,
                                 1.4f,
                                 1.4f,
                                 1.4f,
                                 1.4f};
} // namespace

void clsMagBarrier_Obj::destroyData()
{
}

void clsMagBarrier_Obj::execute()
{
}

clsMagBarrier_Task::clsMagBarrier_Task(const stcSetDataDetail& orsSetDataDetailI)
    : clsSingleModelGimmick_Task<clsMagBarrier_Task, clsMagBarrier_Obj, clsModelType_OB_TX_MO_MA>(0,
                                                                                                  0)
{
}

void clsMagBarrier_Task::reset()
{
}

clsMagBarrier_Obj* clsMagBarrier_Task::getRegistObj(clsPlayerTask* pcPlayer)
{
    return 0;
}

void clsMagBarrier_Task::regist(clsPlayerTask* pcPlayer, bool bInfinity)
{
}

void clsMagBarrier_Task::change(clsPlayerTask* pcPlayer00, clsPlayerTask* pcPlayer01)
{
}

void clsMagBarrier_Task::execute()
{
}

void clsMagBarrier_Task::draw()
{
}
