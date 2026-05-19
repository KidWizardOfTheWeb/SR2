#include "Develop/Projects/SR2/pgm/src/Debug/PathRangeEditor.hpp"

u32 ALPHA;
u32 DIV_NUM;

clsPathRangeEditor_Debug_Task::clsPathRangeEditor_Debug_Task(enmPathType ePathTypeI,
                                                             u32 u32Tp,
                                                             s32 s32Flg)
    : clsTask(u32Tp, s32Flg), m_ePathType(ePathTypeI)
{
}

clsPathRangeEditor_Debug_Task::~clsPathRangeEditor_Debug_Task()
{
}

void clsPathRangeEditor_Debug_Task::execute()
{
}

void clsPathRangeEditor_Debug_Task::drawDetail()
{
}

void clsPathRangeEditor_Debug_Task::draw()
{
}
