#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15FloatingMeteorite.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

NNS_VECTOR clsFloatingMeteorite_Obj::tosCollisionHalfSizeVec = {2.0f, 2.0f, 2.0f};

namespace nspFloatingMeteorite {
static NNS_VECTORFAST toasTargetTablePosVecFast[4] = {
    {-11.0f, -13.0f, 4.0f, 1.0f},
    {-22.0f, -13.0f, -5.0f, 1.0f},
    {5.0f, 6.0f, 20.0f, 1.0f},
    {8.0f, 9.0f, 3.0f, 1.0f},
};
}

clsGravityGimmickParam clsFloatingMeteorite_Obj::t_ocGravityGimmickParam = {
    .m_of32GCtrlRiseRandDelayFrame = 10.0f,
    .m_of32GCtrlRiseBaseHeight = 6.0f,
    .m_of32GCtrlRiseRandHeight = 10.0f,
    .m_of32GCtrlRiseFrame = 60.0f,
    .m_of32GCtrlFlightTrackRate = 0.5f,
    .m_of32GCtrlMoveSpeed = 25.0f / 27.0f,
    .m_of32GCtrlMoveBaseFrame = 60.0f,
    .m_of32GCtrlMoveRandFrame = 30.0f,
    .m_of32GDiveRiseBaseHeight = 7.0f,
    .m_of32GDiveRiseRandHeight = 1.0f,
    .m_of32GDiveMoveSpeed = 145.0f / 216.0f,
    .m_of32GDiveMoveFrame = 30.0f,
    .m_of32GDiveMoveDist = 30.0f,
    .m_oa32GLinkAdjustRotate = 5461,
    .m_of32GLinkAdjustSlerp = 0.035f,
};

void clsFloatingMeteorite_Obj::requestDrawBreakEffect()
{
}

void clsFloatingMeteorite_Obj::requestDrawContactEffect(const hkContactPoint* pcContact)
{
}

void clsFloatingMeteorite_Obj::setData()
{
}

void clsFloatingMeteorite_Obj::createData()
{
}

void clsFloatingMeteorite_Obj::destroyData()
{
}

clsFloatingMeteorite_Task::clsFloatingMeteorite_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0)
{
}

void clsFloatingMeteorite_Task::reset()
{
}

void clsFloatingMeteorite_Task::execute()
{
}

void clsFloatingMeteorite_Task::draw()
{
}

void clsFloatingMeteorite_Task::attackFloatingMeteorite(u32 u32GroupNo)
{
}

clsFloatingMeteorite_Obj::clsFloatingMeteorite_Obj()
{
}

clsFloatingMeteorite_Obj::~clsFloatingMeteorite_Obj()
{
}

void clsFloatingMeteorite_Obj::reset()
{
}

void clsFloatingMeteorite_Obj::main()
{
}

NNS_VECTOR* clsFloatingMeteorite_Obj::getCollisionHalfSizeVecPtr() const
{
    return &tosCollisionHalfSizeVec;
}
