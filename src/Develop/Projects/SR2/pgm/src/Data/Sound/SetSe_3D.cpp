#include "Develop/Projects/SR2/pgm/src/Data/Sound/SetSe_3D.hpp"

static f32 _sDefaultReSpawnFrame = 60.0f;

void* clsSetSe_3D_Task::m_oasRequestArray[42];

clsSetSe_3D_Task::~clsSetSe_3D_Task()
{
}

clsSetSe_3D_Task::clsSetSe_3D_Task(const stcRequestArray& packData)
    : clsTask(0, 0), m_orsRequestArray(const_cast<stcRequestArray&>(packData)),
      m_orf32ReSpawnFrame_default(_sDefaultReSpawnFrame)
{
}

void clsSetSe_3D_Task::execute()
{
}
