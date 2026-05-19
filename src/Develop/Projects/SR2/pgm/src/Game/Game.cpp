#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"
#include "Develop/Projects/SR2/pgm/src/SaveLoad/SaveData.hpp"

static u8 chk__clsGameMgr_m_toac8GameModeName_Debug_SizeCheck_[1];

c8* clsGameMgr::m_toac8HbModeName_Debug[2] = {"HEROES", "BABYLON"};
c8* clsGameMgr::m_toac8GameModeName_Debug[16] = {"NONE",
                                                 "ADVERTISE",
                                                 "TITLE_DEMO",
                                                 "FREE_RACE",
                                                 "TIME_ATTACK",
                                                 "STORY",
                                                 "WORLD_GP",
                                                 "MISSION",
                                                 "TUTORIAL",
                                                 "SURVIVAL_RELAY",
                                                 "SURVIVAL_BALL",
                                                 "SURVIVAL_BATTLE",
                                                 "EVENT",
                                                 "CREDIT",
                                                 "EASY_MENU",
                                                 "MODEL_VIEWER"};

namespace {
static stcDetailData otasDetailData[24] = {
    {0, 0}, {4, 0}, {1, 1}, {4, 0}, {0, 1}, {4, 0}, {2, 0}, {4, 0}, {0, 2}, {4, 0}, {1, 2}, {4, 0},
    {0, 3}, {4, 0}, {2, 0}, {4, 0}, {0, 4}, {4, 0}, {1, 6}, {4, 0}, {0, 5}, {4, 0}, {2, 0}, {5, 0}};

static stcDetailRace otasDetailRace[6] = {
    {1,
     1,
     0,
     4,
     {{17, 16}, {16, 16}, {16, 16}, {-1, 2}, {2, 0}, {1, 2}, {3, 16}, {16, 16}, {16, -1}}},
    {3, 4, 0, 1, {{2, 3}, {-1, 0}, {0, 0}, {0, 9}, {1, 0}, {4, 17}, {16, 16}, {16, 16}, {16, -1}}},
    {10, 2, 0, 1, {{2, 3}, {16, 16}, {16, 16}, {-1, 11}, {4, 0}, {1, 2}, {3, -1}, {0, 0}, {0, 0}}},
};
} // namespace

template <>
u8 clsBitset<u8>::get(u32 u32Pos) const
{
    return (m_pBuffer[(u32Pos >> 3) & 0xff] & (u8)(1 << (u32Pos & 7))) != 0;
}

void clsGameMgr::reinit()
{
}

void clsGameMgr::reinitUnlockInfo()
{
}

void clsGameMgr::setSendNextModeData(clsGameMgr::enmMode eNextModeI,
                                     s32 s32StageNoI,
                                     s32 s32PlayerNumI,
                                     s32 s32UserNumI,
                                     const clsGameMgr::stcSendAdv* psSendAdvI,
                                     s32 s32UniqueDataI)
{
}

s32 clsGameMgr::getDefaultLapNum(s32 s32StageNoI) const
{
    return 0;
}

void clsGameMgr::loadStage(nspPackId::enm eTypeIdI, s32 s32No0I, s32 s32No1I)
{
}

void clsGameMgr::tRegistRandomCOM(clsGameMgr::enmMode eModeI,
                                  s32 s32UserNumI,
                                  s32 s32PlayerNumI,
                                  clsGameMgr::stcSendAdv* posSendAdvI,
                                  u32 bGearRandI)
{
}

void clsGameMgr::startResist()
{
}

void clsGameMgr::checkSecretTrickTitle()
{
}

void clsGameMgr::setStoryHint_Option(s8 s8Bool)
{
}

void clsGameMgr::setFreeLap_Option(s8 s8Lap)
{
}

void clsGameMgr::setFreeAgp_Option(s8 s8Agp)
{
}

void clsGameMgr::setFreeHint_Option(s8 s8Bool)
{
}

void clsGameMgr::setTimeAttackGhost_Option(s8 s8Bool)
{
}

void clsGameMgr::setWorldGPHint_Option(s8 s8Bool)
{
}

void clsGameMgr::setRelayLap_Option(s8 s8Lap)
{
}

void clsGameMgr::setRelayAgp_Option(s8 s8Agp)
{
}

void clsGameMgr::setBallLimit_Option(s8 s8Limit)
{
}

void clsGameMgr::setBallPoint_Option(s8 s8Point)
{
}

void clsGameMgr::setBattleMode_Option(s8 s8Mode)
{
}

void clsGameMgr::setBattleHP_Option(s8 s8HitPoint)
{
}

void clsGameMgr::setBattleLimit_Option(s8 s8Limit)
{
}

s32 clsGameMgr::getStoryHint_Option() const
{
    return 0;
}

s32 clsGameMgr::getFreeLap_Option() const
{
    return 0;
}

s32 clsGameMgr::getFreeAgp_Option() const
{
    return 0;
}

s32 clsGameMgr::getFreeHint_Option() const
{
    return 0;
}

s32 clsGameMgr::getTimeAttackGhost_Option() const
{
    return 0;
}

s32 clsGameMgr::getWorldGPHint_Option() const
{
    return 0;
}

s32 clsGameMgr::getRelayLap_Option() const
{
    return 0;
}

s32 clsGameMgr::getRelayAgp_Option() const
{
    return 0;
}

s32 clsGameMgr::getBallLimit_Option() const
{
    return 0;
}

s32 clsGameMgr::getBallPoint_Option() const
{
    return 0;
}

s32 clsGameMgr::getBattleHP_Option() const
{
    return 0;
}

s32 clsGameMgr::getBattleLimit_Option() const
{
    return 0;
}
