#include "Develop/Projects/SR2/pgm/src/Object/Player/Ghost.hpp"

namespace nspNnUtil {
static NNS_VECTORFAST tosZeroVecFast = {0.0f, 0.0f, 0.0f, 1.0f};
}

stcGhostSaveData* clsGhost::t_psSaveBuf;

void clsGhost::restart()
{
}

void* clsGhost::getSaveDataBuff(s32 s32Idx)
{
    return 0;
}

u8 clsGhost::checkGhostDataCrc(const void* pv)
{
    return 0;
}

void clsGhost::setGhostData(void* pv, bool bFlag, const u16* pu16)
{
}

void clsGhost::updateGhostPlayer()
{
}

void clsGhost::execute()
{
}

void clsGhost::draw()
{
}

void clsGhost::setStartFlag(bool bFlag)
{
}

void clsGhost::createGhostSaveBuffer()
{
}

void* clsGhost::getGhostLoadData(u32 u32Idx)
{
    return 0;
}

bool clsGhost::getGhostDownloadFlag(u32 u32Idx)
{
    return false;
}
