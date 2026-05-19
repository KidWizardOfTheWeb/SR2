#include "Develop/Projects/SR2/pgm/src/Game/Pause/BaseRacePause.hpp"

static s32 s_dummyRacePauseRet;

void clsBaseRacePause_Task::stopSound()
{
}

void clsBaseRacePause_Task::playCursor()
{
}

u8 clsBaseRacePause_Task::chkOk()
{
    return 0;
}

u8 clsBaseRacePause_Task::chkCancel()
{
    return 0;
}

void clsBaseRacePause_Task::chkEnd()
{
}

void clsBaseRacePause_Task::setCancel()
{
}

void clsBaseRacePause_Task::execute()
{
}

u8 clsBaseRacePause_Task::checkPadConnect()
{
    return 0;
}

void clsBaseRacePause_Task::drawConnectReport()
{
}

void clsBaseRacePause_Task::draw()
{
}

clsBaseRacePause_Task::clsBaseRacePause_Task()
    : clsTask(0, 0), m_reRacePauseRet(s_dummyRacePauseRet)
{
}
