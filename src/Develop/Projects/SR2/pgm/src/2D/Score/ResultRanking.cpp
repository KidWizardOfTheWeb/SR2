#include "Develop/Projects/SR2/pgm/src/2D/Score/ResultRanking.hpp"

u8 MAX_USER_BG_ALPHA;

u8 nspResultRanking::MAT_ALPHA_SPEED;
nspResultRanking::stcResultRanking nspResultRanking::osDrawData;

clsResultRanking2D_Task::clsResultRanking2D_Task(u32 u32Flg, bool bPause) : clsTask(0, 0)
{
}

clsResultRanking2D_Task::~clsResultRanking2D_Task()
{
}

void clsResultRanking2D_Task::init()
{
}

u8 clsResultRanking2D_Task::checkWait(stcRankingLine* psLine)
{
    return 0;
}

void clsResultRanking2D_Task::execEnergyLine(stcRankingLine* psLine)
{
}

void clsResultRanking2D_Task::execRanking(stcRankingLine* psLine)
{
}

void clsResultRanking2D_Task::execName(stcRankingLine* psLine)
{
}

void clsResultRanking2D_Task::execTime(stcRankingLine* psLine)
{
}

void clsResultRanking2D_Task::execPoint(stcRankingLine* psLine)
{
}

u8 clsResultRanking2D_Task::setOutMode()
{
    return 0;
}

void clsResultRanking2D_Task::execute()
{
}

void clsResultRanking2D_Task::drawRanking(stcRankingLine* psLine)
{
}

void clsResultRanking2D_Task::drawName(stcRankingLine* psLine)
{
}

void clsResultRanking2D_Task::drawTime(stcRankingLine* psLine)
{
}

void clsResultRanking2D_Task::drawPoint(stcRankingLine* psLine)
{
}

void clsResultRanking2D_Task::drawTrophy(stcRankingLine* psLine)
{
}

void clsResultRanking2D_Task::drawBackMat(stcRankingLine* psLine)
{
}

void clsResultRanking2D_Task::drawRing()
{
}

void clsResultRanking2D_Task::draw()
{
}
