#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02PathBee.hpp"

f32 clsPathBee_Obj::m_tof32CLIP_DISTx2 = 0.0f;

void clsPathBee_Obj::init()
{
}

void clsPathBee_Obj::reset()
{
}

void clsPathBee_Obj::createData()
{
}

void clsPathBee_Obj::destroyData()
{
}

void clsPathBee_Obj::setPosturalCtrl(const NNS_VECTORFAST& rsDirVecFast,
                                     f32 f32InterpolateRate,
                                     f32 f32RotZ)
{
}

void clsPathBee_Obj::requestDrawBreakEffect()
{
}

void clsPathBee_Obj::callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1)
{
}

void clsPathBee_Obj::setSurfaceDir(NNS_VECTORFAST& rsVerocityFast, NNS_VECTORFAST& rsDirVecFast)
{
}

void clsPathBee_Obj::setReturnPath()
{
}

void clsPathBee_Obj::callbackGravityEvent()
{
}

void clsPathBee_Obj::main()
{
}

clsPathBee_Task::clsPathBee_Task(u32 u32Param1)
    : clsMultiModelGimmick_Task<clsPathBee_Task, clsPathBee_Obj, clsModelType_OB_TX>(u32Param1, 1)
{
}

void clsPathBee_Task::createModel(stcBinInfo& rsBinInfo)
{
}

void clsPathBee_Task::reset()
{
}

void clsPathBee_Task::execute()
{
}

void clsPathBee_Task::draw()
{
}
