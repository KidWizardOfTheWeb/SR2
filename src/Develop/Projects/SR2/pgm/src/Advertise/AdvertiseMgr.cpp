#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Advertise/Title/Title.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/TextureId.hpp"
#include "Develop/Projects/SR2/pgm/src/SaveLoad/SaveData.hpp"

template <>
void clsBitset<u8>::set(u32 u32Pos, bool bVal)
{
    u8 word = (u32Pos >> 3) & 0xff;
    u8 bitmask = 1 << (u32Pos & 7);

    if (bVal) {
        m_pBuffer[word] |= bitmask;
    } else {
        m_pBuffer[word] &= ~bitmask;
    }
}

// Static member definitions
enmMode clsAdvertiseMgr_Task::m_teSelectedGameMode;
u32 clsAdvertiseMgr_Task::tu32ResidenceTexSize;

clsAdvertiseMgr_Task::clsAdvertiseMgr_Task() : clsTask(0, 0)
{
}

clsAdvertiseMgr_Task::~clsAdvertiseMgr_Task()
{
}

void clsAdvertiseMgr_Task::release()
{
}

void clsAdvertiseMgr_Task::releasePack()
{
}

void clsAdvertiseMgr_Task::releaseSubTexture(u32 u32Param1)
{
}

u8 clsAdvertiseMgr_Task::openRequestFile(u32 u32Param1, u8 u8Param2)
{
    return 0;
}

void clsAdvertiseMgr_Task::requestReadFile(u32 u32Param1)
{
}

u8 clsAdvertiseMgr_Task::jumpMoveSelect()
{
    return 0;
}

void clsAdvertiseMgr_Task::setPackData(stcBinInfo& rParam1)
{
}

void clsAdvertiseMgr_Task::setPackDataSub(u32 u32Param1, stcBinInfo& rParam2)
{
}

void clsAdvertiseMgr_Task::setBGModel(stcBinInfo& rParam1)
{
}

void clsAdvertiseMgr_Task::drawMorphBG()
{
}

void clsAdvertiseMgr_Task::setFlashTexture(u32 u32Param1, stcBinInfo& rParam2)
{
}

void clsAdvertiseMgr_Task::setGearPartsTexture(stcBinInfo& rParam1)
{
}

void clsAdvertiseMgr_Task::setFlashData(u32 u32Param1, stcBinInfo& rParam2)
{
}

void clsAdvertiseMgr_Task::setupFlashData(u32 u32Param1)
{
}

stcFlashData* clsAdvertiseMgr_Task::getFlashData(u32 u32Param1)
{
    return 0;
}

stcSubFlashData* clsAdvertiseMgr_Task::getSubFlashData(u32 u32Param1)
{
    return 0;
}

void clsAdvertiseMgr_Task::setTitlePressButton()
{
}

void clsAdvertiseMgr_Task::setTitleLogo()
{
}

void clsAdvertiseMgr_Task::setModeSelectTutorial()
{
}

void clsAdvertiseMgr_Task::setSelectStageAnime(bool bParam1, bool bParam2)
{
}

void clsAdvertiseMgr_Task::setAddMenu()
{
}

void clsAdvertiseMgr_Task::setEtcMenu()
{
}

void clsAdvertiseMgr_Task::setEntryMotion(
    u32 u32Param1, u8* pParam2, u32* pParam3, u16 u16Param4, u32 u32Param5)
{
}

NNS_MOTION* clsAdvertiseMgr_Task::getEntryMotion(u32 u32Param1, u32 u32Param2)
{
    return 0;
}

void clsAdvertiseMgr_Task::executeFlashData(u32 u32Param1)
{
}

void clsAdvertiseMgr_Task::drawFlashData(u32 u32Param1)
{
}

u8 clsAdvertiseMgr_Task::isFlashData(u32 u32Param1)
{
    return 0;
}

void clsAdvertiseMgr_Task::executeSubFlashData(u32 u32Param1)
{
}

void clsAdvertiseMgr_Task::drawSubFlashData(u32 u32Param1)
{
}

void clsAdvertiseMgr_Task::changeNextGearNo(bool bParam1, stcSendAdv& rParam2, bool bParam3)
{
}

void clsAdvertiseMgr_Task::jumpMode()
{
}

void clsAdvertiseMgr_Task::checkTitleDemo(clsTask* pParam1)
{
}

void clsAdvertiseMgr_Task::execute()
{
}

void clsAdvertiseMgr_Task::drawButtonForFlash()
{
}

void clsAdvertiseMgr_Task::drawFontColor(f32 f32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4)
{
}

void clsAdvertiseMgr_Task::drawDiffFontData(
    u32 u32Param1, u32 u32Param2, s32 s32Param3, s32 s32Param4, s32 s32Param5, f32 f32Param6)
{
}

void clsAdvertiseMgr_Task::drawTutorialStart(bool bParam1)
{
}

u32 clsAdvertiseMgr_Task::callbackOption(void* pvParam1,
                                         u32 u32Param2,
                                         u32 u32Param3,
                                         u32 u32Param4)
{
    return 0;
}

void clsAdvertiseMgr_Task::drawShopModel(u8 u8Param1, f32 f32Param2)
{
}

u8 clsAdvertiseMgr_Task::checkUnLock()
{
    return 0;
}

void clsAdvertiseMgr_Task::drawUnLockWindow(
    s32 s32Param1, s32 s32Param2, s32 s32Param3, s32 s32Param4, u32 u32Param5)
{
}

void clsAdvertiseMgr_Task::drawUnLockInfo(u32 u32Param1,
                                          u32 u32Param2,
                                          s32 s32Param3,
                                          s32 s32Param4,
                                          s32 s32Param5,
                                          s32 s32Param6,
                                          u32 u32Param7)
{
}

void clsAdvertiseMgr_Task::drawUnLock()
{
}

void clsAdvertiseMgr_Task::draw()
{
}

void clsAdvertiseMgr_Task::drawFontData(
    u32 u32Param1, s32 s32Param2, s32 s32Param3, s32 s32Param4, f32 f32Param5)
{
}
