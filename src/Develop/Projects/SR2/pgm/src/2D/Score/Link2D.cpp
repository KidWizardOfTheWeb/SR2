#include "Develop/Projects/SR2/pgm/src/2D/Score/Link2D.hpp"

nspLink2D::stcLinkData nspLink2D::DrawData1v;
nspLink2D::stcLinkData nspLink2D::DrawData2v;
nspLink2D::stcLinkData nspLink2D::DrawData4v;
nspLink2D::stcLinkData* nspLink2D::opsDrawData;
nspLink2D::stcEnergyPoint nspLink2D::asEnergyPoint[4];
f32 nspLink2D::tf32EnergyFrameMax;

void nspLink2D::setupEnergyPoint()
{
}

clsLink2D_Task::clsLink2D_Task(s32 s32PlayerNo, s32 s32Link, const s32* ops32SrcLink)
    : clsTemporary2D_Task(0, 0)
{
} // [verify params from ASM]

clsLink2D_Task::~clsLink2D_Task()
{
}

void clsLink2D_Task::exeAddLine()
{
}

void clsLink2D_Task::execute()
{
}

void clsLink2D_Task::_drawLink()
{
}

void clsLink2D_Task::draw()
{
}
