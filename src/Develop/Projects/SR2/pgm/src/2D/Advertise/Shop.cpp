#include "Develop/Projects/SR2/pgm/src/2D/Advertise/Shop.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearCtrl.hpp"

namespace {
nspGear::enmGearCtrl oaeShopGear[41] = {
    nspGear::CTRL_TURBO_STAR,   nspGear::CTRL_SHOOTING_STAR,   nspGear::CTRL_BEGINNER,
    nspGear::CTRL_FASTER,       nspGear::CTRL_COVER_S,         nspGear::CTRL_COVER_F,
    nspGear::CTRL_COVER_P,      nspGear::CTRL_LIGHT_BOARD,     nspGear::CTRL_G_SHOT,
    nspGear::CTRL_WHEEL_CUSTOM, nspGear::CTRL_AIR_SHIP,        nspGear::CTRL_GC_BOOSTER,
    nspGear::CTRL_SINOBI,       nspGear::CTRL_FASTEST,         nspGear::CTRL_ADVANTAGE_S,
    nspGear::CTRL_ADVANTAGE_F,  nspGear::CTRL_ADVANTAGE_P,     nspGear::CTRL_RING_LINKER,
    nspGear::CTRL_UNTOUCHABLE,  nspGear::CTRL_MASTER_OFF_ROAD, nspGear::CTRL_WIND_STAR,
    nspGear::CTRL_ROAD_STAR,    nspGear::CTRL_HYPER_DIVE,      nspGear::CTRL_GC_MASTER,
    nspGear::CTRL_LEGEND,       nspGear::CTRL_OMNI_TEMPOS,     nspGear::CTRL_KUNOICHI,
    nspGear::CTRL_RAILLINKER,   nspGear::CTRL_INFLUENTIAL,     nspGear::CTRL_RESERVE_TANK,
    nspGear::CTRL_THE_CRAZY,    nspGear::CTRL_WINDCATCHER,     nspGear::CTRL_GAMBLER,
    nspGear::CTRL_BINGO_STAR,   nspGear::CTRL_WANTED,          nspGear::CTRL_GP_TANK,
    nspGear::CTRL_THROTTLE,     nspGear::CTRL_MONEY_CRISIS,    nspGear::CTRL_BIG_BANG,
    nspGear::CTRL_HANG_ON,      nspGear::CTRL_RAINBOW,
};

nspGear::enmGearCtrl aeShopGear[41];

stcShopDrawData osDrawData = {
    45,  340, 550, 78,    300, 20,  70,  128, 56,  32, 64,  15.0f, 20.0f, 20,    110,
    225, 210, 24,  15.0f, 145, 378, 350, 378, 255, 58, 365, 290,   170,   15.0f,
};
} // namespace

void clsShop_Task::updateGearList()
{
}

void clsShop_Task::execute()
{
}

void clsShop_Task::drawTradeSelect()
{
}

void clsShop_Task::drawGearSelect()
{
}

void clsShop_Task::drawTrade()
{
}

void clsShop_Task::drawInfoWindow(s32 s32X, s32 s32Y, s32 s32W, s32 s32H, u32 u32Color)
{
}

void clsShop_Task::drawInfoName(s32 s32GearNo, f32 f32X, f32 f32Y)
{
}

void clsShop_Task::drawInfoUser(s32 s32GearNo, f32 f32X, f32 f32Y)
{
}

void clsShop_Task::drawInfoRing(s32 s32GearNo, f32 f32X, f32 f32Y)
{
}

void clsShop_Task::drawInfoStatus(s32 s32GearNo, f32 f32X, f32 f32Y)
{
}

void clsShop_Task::drawInfoParts(s32 s32GearNo, f32 f32X, f32 f32Y)
{
}

void clsShop_Task::drawInfoDetails(s32 s32GearNo, f32 f32X, f32 f32Y)
{
}

void clsShop_Task::drawInfoGearBg(s32 s32GearNo, f32 f32X, f32 f32Y)
{
}

void clsShop_Task::drawGearInfo()
{
}

void clsShop_Task::drawRingNum()
{
}

void clsShop_Task::drawMessage()
{
}

void clsShop_Task::draw()
{
}
