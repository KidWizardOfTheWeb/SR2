#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearCtrl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GearControlData.hpp"

clsGearCtrl::clsGearCtrl(clsPlayerTask* pcPlayer, nspGear::enmGearCtrl eCtrlNo, u32 u32EquipsGears)
{
}

clsGearCtrl::~clsGearCtrl()
{
}

void clsGearCtrl::createGear()
{
}

void clsGearCtrl::setGearModels()
{
}

void clsGearCtrl::init()
{
}

void clsGearCtrl::copyGearLv(clsGearCtrl* pcPlayerGearCtrl)
{
}

void clsGearCtrl::updatePrfm()
{
}

clsGearBasePrototype* clsGearCtrl::getEquipsPrototypeGear()
{
    return 0;
}

clsGearCtrl::enmCtrlMode clsGearCtrl::_equipsGear(u8 u8GearLevel)
{
    return CTRL_MODE_WALK;
}

void clsGearCtrl::equipsGear(u8 u8GearLevel)
{
}

nspGear::enmLevel clsGearCtrl::calcChageGearLevel()
{
    return nspGear::LV_ERROR;
}

u8 clsGearCtrl::requestGearChange()
{
    return 0;
}

void clsGearCtrl::requestGearChangeForGhost(u8 u8ChangeNo)
{
}

u8 clsGearCtrl::rideGear(u8 u8IsRide,
                         f32 f32LinkFrame,
                         s32 eSuccessActionType,
                         nspMotion::enmMotion eMotion)
{
    return 0;
}

u8 clsGearCtrl::requestGearRide(u8 u8IsRide, f32 f32LinkFrame, s32 eSuccessActionType)
{
    return 0;
}

u8 clsGearCtrl::requestGearRide_AttackAction(u8 u8IsRide, f32 f32LinkFrame, s32 eSuccessActionType)
{
    return 0;
}

u8 clsGearCtrl::requestGearRide_HideActiveGear(u8 u8IsRide,
                                               f32 f32LinkFrame,
                                               s32 eSuccessActionType)
{
    return 0;
}

void clsGearCtrl::cancelGDive()
{
}

void clsGearCtrl::updateAction()
{
}

void clsGearCtrl::draw(const f32 (*psGearMtx)[4][4], u32 u32AddDrawFlagI)
{
}

void clsGearCtrl::controlMotion()
{
}

void clsGearCtrl::playMonumentFlySe()
{
}

void clsGearCtrl::stopMonumentFlySe()
{
}

nspGear::enmLevel clsGearCtrl::searchGearFromGearParamType(nspCom::enmComGearChangeType eType)
{
    return nspGear::LV_ERROR;
}

void clsGearCtrl::registGearChangeEffect(nspGear::enmLevel eLevel, nspGear::enmGearType eOldType)
{
}

void clsGearCtrl::registGearRideEffect(bool bIsRide)
{
}

void clsGearCtrl::behavior()
{
}

void clsGearCtrl::behavior_NodeMtx()
{
}

enmGearType clsGearCtrl::getEquipsGearType()
{
    return GEAR_TYPE_EMPTY;
}

enmMotionType clsGearCtrl::getEquipsGearBaseMotionType()
{
    return MOTION_EMPTY;
}

u8 clsGearCtrl::getEquipsGearFlags() const
{
    return 0;
}

void clsGearCtrl::changeInitGearModel(enmInitBoard eBoard)
{
}

void clsGearCtrl::setUnuseGearLevel(nspGear::enmLevel eLevel)
{
}

clsGearSp1stSpeed::~clsGearSp1stSpeed()
{
}

void clsGearSp1stSpeed::clearChangeActionParam()
{
}

void clsGearSp1stSpeed::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSp1stSpeed::getDraw2DType() const
{
    return TYPE_2D_SP_1ST_SPEED;
}

clsGearSpMaxSpeed::~clsGearSpMaxSpeed()
{
}

void clsGearSpMaxSpeed::eventGearChange()
{
}

void clsGearSpMaxSpeed::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSpMaxSpeed::getDraw2DType() const
{
    return TYPE_2D_SP_MAX_SPEED;
}

clsGearSpAgp::~clsGearSpAgp()
{
}

void clsGearSpAgp::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSpAgp::getDraw2DType() const
{
    return TYPE_2D_SP_AGP;
}

clsGearSpAttackTimeUp::~clsGearSpAttackTimeUp()
{
}

enmDraw2DType clsGearSpAttackTimeUp::getDraw2DType() const
{
    return TYPE_2D_SP_ATTACK_TIME_UP;
}

clsGearSpAllParamUp::~clsGearSpAllParamUp()
{
}

enmDraw2DType clsGearSpAllParamUp::getDraw2DType() const
{
    return TYPE_2D_SP_ALL_PARAM_UP;
}

clsGearSpDurability::~clsGearSpDurability()
{
}

enmDraw2DType clsGearSpDurability::getDraw2DType() const
{
    return TYPE_2D_SP_DURABILITY;
}

clsGearSpGpGetRate::~clsGearSpGpGetRate()
{
}

void clsGearSpGpGetRate::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSpGpGetRate::getDraw2DType() const
{
    return TYPE_2D_SP_GP_GET_RATE;
}

clsGearSpSoundChange::~clsGearSpSoundChange()
{
}

void clsGearSpSoundChange::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSpSoundChange::getDraw2DType() const
{
    return TYPE_2D_SP_SOUND_CHANGE;
}

clsGearSpItemRankUp::~clsGearSpItemRankUp()
{
}

void clsGearSpItemRankUp::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSpItemRankUp::getDraw2DType() const
{
    return TYPE_2D_SP_ITEM_RANK_UP;
}

clsGearSpRingCapacity::~clsGearSpRingCapacity()
{
}

void clsGearSpRingCapacity::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSpRingCapacity::getDraw2DType() const
{
    return TYPE_2D_SP_RING_CAPACITY;
}

clsGearSpAutoWall::~clsGearSpAutoWall()
{
}

void clsGearSpAutoWall::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSpAutoWall::getDraw2DType() const
{
    return TYPE_2D_SP_AUTO_WALL_RUN;
}

clsGearSpGhost::~clsGearSpGhost()
{
}

void clsGearSpGhost::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSpGhost::getDraw2DType() const
{
    return TYPE_2D_SP_GHOST;
}

clsGearSpAddTrick::~clsGearSpAddTrick()
{
}

void clsGearSpAddTrick::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSpAddTrick::getDraw2DType() const
{
    return TYPE_2D_SP_ADD_TRICK;
}

clsGearSpGcSpeed::~clsGearSpGcSpeed()
{
}

void clsGearSpGcSpeed::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag)
{
}

enmDraw2DType clsGearSpGcSpeed::getDraw2DType() const
{
    return TYPE_2D_SP_GC_SPEED;
}

void clsGearCtrl::updateDraw2DData()
{
}

void clsGearCtrl::updateLockFlag()
{
}
