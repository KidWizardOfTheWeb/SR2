#include "Develop/Projects/SR2/pgm/src/2D/Score/BonusPoint2D.hpp"

nspBonusPoint2D::stcBonusPointData nspBonusPoint2D::DrawData1v;
nspBonusPoint2D::stcBonusPointData nspBonusPoint2D::DrawData2v;
nspBonusPoint2D::stcBonusPointData nspBonusPoint2D::DrawData4v;
nspBonusPoint2D::stcBonusPointData* nspBonusPoint2D::opsDrawData;
nspBonusPoint2D::stcEnergyPoint nspBonusPoint2D::asEnergyPoint[4];
f32 nspBonusPoint2D::tf32EnergyFrameMax;
clsBonusPoint2D_Task* nspBonusPoint2D::apcCurentGLinkPoint[5];

void nspBonusPoint2D::setupEnergyPoint()
{
}

clsBonusPoint2D_Task::clsBonusPoint2D_Task(s32 s32Player, u32 u32Type, f32 f32BonusAgp)
    : clsTemporary2D_Task(0, 0)
{
} // [verify params from ASM]

clsBonusPoint2D_Task::~clsBonusPoint2D_Task()
{
}

void clsBonusPoint2D_Task::execute()
{
}

void clsBonusPoint2D_Task::_drawPoint()
{
}

void clsBonusPoint2D_Task::_drawShot()
{
}

void clsBonusPoint2D_Task::draw()
{
}
