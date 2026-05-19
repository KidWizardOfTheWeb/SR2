#include "Develop/Projects/SR2/pgm/src/System/IO/SR2_MemoryCardFile.hpp"

namespace {
static void* m_tpvBannerImage;
static c8 topoc8GameDirName[20] = "BASLUS-21642USER__0";
static c8 topoc8GhostDirName[20] = "BASLUS-21642GHOST00";
static c8* topoc8GameFileName = topoc8GameDirName;
static c8* topoc8GhostFileName = topoc8GhostDirName;
static c8* topoc8BannerFileName = "game.ico";
} // namespace

void* nspMemoryCardFile::m_tpvIconImage[3];
const s8* clsBaseMemoryCardFile::otac8DataTypeName_Debug[3] = {
    (const s8*)"GAMES", (const s8*)"GHOST", (const s8*)"BANNER"};

void nspMemoryCardFile::SetIconImage(u32 u32Param1, void* pvParam2)
{
}

void* nspMemoryCardFile::GetIconImage(u32 u32Param1)
{
    return 0;
}

s32 clsBaseMemoryCardFile::getFileSdkBlock() const
{
    return 0;
}

s32 clsBaseMemoryCardFile::getFileUserBlock() const
{
    return 0;
}

void clsBaseMemoryCardFile::setSaveData(void* pvSaveData)
{
}

clsMemoryCardFile_Games::clsMemoryCardFile_Games()
{
}

void clsMemoryCardFile_Games::setFileName(s32 s32FileNoI, s32 s32Param2)
{
}

clsMemoryCardFile_Ghost::clsMemoryCardFile_Ghost()
{
}

void clsMemoryCardFile_Ghost::setFileName(s32 s32FileNoI, s32 s32StageNoMmI)
{
}

clsMemoryCardFile_Banner::clsMemoryCardFile_Banner()
{
}
