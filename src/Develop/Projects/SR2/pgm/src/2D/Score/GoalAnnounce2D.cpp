#include "Develop/Projects/SR2/pgm/src/2D/Score/GoalAnnounce2D.hpp"

clsGoalAnnounce2D_Task* nspGoalAnnounce2D::pcCurrentTask;

void nspGoalAnnounce2D::initCurrent()
{
    pcCurrentTask = 0;
}

clsGoalAnnounce2D_Task::clsGoalAnnounce2D_Task(s32 s32Rank, u32 u32CharaId)
    : clsTemporary2D_Task(0, 0)
{
}

clsGoalAnnounce2D_Task::~clsGoalAnnounce2D_Task()
{
}

void clsGoalAnnounce2D_Task::execute()
{
}

void clsGoalAnnounce2D_Task::draw()
{
}
