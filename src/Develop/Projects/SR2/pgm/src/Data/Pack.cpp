#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Keyboard2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalBall/SurvivalBall2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalBattle/SurvivalBattleMap2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/BackRibbon/BackRibbon.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/DisElectric.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/MiniWave/MiniWave.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/TimeAttack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/DashPanel.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/DashRing.hpp"

namespace nspFly {
static f32 FLYACTION_MIN_PITCH = 5461.0f;
static f32 FLYACTION_MAX_PITCH = 5461.0f;
static f32 FLYACTION_LEFT_RIGHT_ROT = 127.0f;
static f32 FLYACTION_UP_DOWN_ROT = 127.0f;
static f32 FLYACTION_DESCENT_PITCH_GRAVITY = 127.0f;
static f32 FLYACTION_FALL_PITCH_GRAVITY = 9.0f;
static f32 FLYACTION_DEFAULT_PITCH_GRAVITY = 25.0f;
} // namespace nspFly

namespace nspNnModelType {
static u32 BIT_DIV_MAP = 0x40;
static u32 BIT_OBJECT = 0x1;
static u32 BIT_TEXTURE = 0x2;
static u32 BIT_MOTION = 0x4;
static u32 BIT_MATMOTOBJ = 0x8;
static u32 BIT_MORPHOBJ = 0x10;
static u32 BIT_MORPHTARGETLIST = 0x20;
} // namespace nspNnModelType

c8* clsPack::getFileName(nspPackId::enm eTypeIdI, s32 s32No0I, s32 s32No1I, s32 s32No2I)
{
    return 0;
}

void clsPack::loadGearModels(u32 u32DataIdx, stcBinInfo& rsBinInfo)
{
}

void clsPack::Pack2Set(void* pvAddrI, u32 u32Context, clsTask* pcTaskI)
{
}

void clsPack::setPlayerPosition(
    oostd::clsOOVector<stcSetDataDetail*, oostd::clsOOStlAllocator<stcSetDataDetail*> >&
        rvctStarPos)
{
}

void setPlayerPositionOther(clsOOVector& rvctStarPos)

{
}

clsPack::~clsPack()
{
}
