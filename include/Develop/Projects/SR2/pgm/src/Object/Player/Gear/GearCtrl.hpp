#ifndef GEARCTRL_HPP
#define GEARCTRL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearChildren.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnEmpty.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnGrind.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnSkate.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"

class clsGear;
class clsInitialBoard;
class clsGearBaseParts;
class clsGearBasePrototype;
class clsPlayerTask;
class clsTask;
struct stcCtrlData;

namespace nspCom {
enum enmComGearChangeType {
    COM_GEAR_CHANGE_TYPE_GRIND = 0,
    COM_GEAR_CHANGE_TYPE_FLY = 1,
    COM_GEAR_CHANGE_TYPE_POWER = 2,
    COM_GEAR_CHANGE_TYPE_AGP = 3,
    COM_GEAR_CHANGE_TYPE_MAX_SPEED = 4,
    COM_GEAR_CHANGE_TYPE_1ST_SPEED = 5,
    GEAR_PARAM_TYPE_MAX = 6,
};
} // namespace nspCom

namespace nspGear {
enum enmGearType {
    GEAR_TYPE_BOARD = 0,
    GEAR_TYPE_BIKE = 1,
    GEAR_TYPE_AIRRIDE = 2,
    GEAR_TYPE_SKATE = 3,
    GEAR_TYPE_WHEEL = 4,
    GEAR_TYPE_SURFING = 5,
    GEAR_TYPE_EMPTY = 6,
    GEAR_PROTOTYPE_MAX = 7,
    GEAR_TYPE_EFFECT_PART = 7,
    GEAR_TYPE_MODEL_PART = 8,
};

enum enmGearCtrl {
    CTRL_UNKNOWN = -1,
    CTRL_DEF_START = 0,
    CTRL_DEF_SNC = 0,
    CTRL_DEF_TLS = 1,
    CTRL_DEF_KNC = 2,
    CTRL_DEF_AMY = 3,
    CTRL_DEF_JET = 4,
    CTRL_DEF_STM = 5,
    CTRL_DEF_WAV = 6,
    CTRL_DEF_EGG = 7,
    CTRL_DEF_CRM = 8,
    CTRL_DEF_RUG = 9,
    CTRL_DEF_SDW = 10,
    CTRL_DEF_BLZ = 11,
    CTRL_DEF_SLV = 12,
    CTRL_DEF_NIT = 13,
    CTRL_DEF_SAM = 14,
    CTRL_DEF_BLY = 15,
    CTRL_EMPTY_GP = 16,
    CTRL_DEF_END = 17,
    CTRL_EMPTY_SH = 17,
    CTRL_SHOOTING_STAR = 18,
    CTRL_FASTER = 19,
    CTRL_FASTEST = 20,
    CTRL_TURBO_STAR = 21,
    CTRL_LIGHT_BOARD = 22,
    CTRL_COVER_S = 23,
    CTRL_COVER_F = 24,
    CTRL_COVER_P = 25,
    CTRL_ADVANTAGE_S = 26,
    CTRL_ADVANTAGE_F = 27,
    CTRL_ADVANTAGE_P = 28,
    CTRL_WIND_STAR = 29,
    CTRL_ROAD_STAR = 30,
    CTRL_AIR_SHIP = 31,
    CTRL_WHEEL_CUSTOM = 32,
    CTRL_OMNI_TEMPOS = 33,
    CTRL_HYPER_DIVE = 34,
    CTRL_GC_BOOSTER = 35,
    CTRL_GC_MASTER = 36,
    CTRL_LEGEND = 37,
    CTRL_SINOBI = 38,
    CTRL_KUNOICHI = 39,
    CTRL_RAILLINKER = 40,
    CTRL_RING_LINKER = 41,
    CTRL_INFLUENTIAL = 42,
    CTRL_G_SHOT = 43,
    CTRL_MASTER_OFF_ROAD = 44,
    CTRL_RESERVE_TANK = 45,
    CTRL_GP_TANK = 46,
    CTRL_CHAOSEMERALD = 47,
    CTRL_THE_CRAZY = 48,
    CTRL_ANGEL_OR_DEVIL = 49,
    CTRL_THROTTLE = 50,
    CTRL_MONEY_CRISIS = 51,
    CTRL_BEGINNER = 52,
    CTRL_BIG_BANG = 53,
    CTRL_GAMBLER = 54,
    CTRL_BINGO_STAR = 55,
    CTRL_WANTED = 56,
    CTRL_HANG_ON = 57,
    CTRL_MAGIC_BROOME = 58,
    CTRL_MAG = 59,
    CTRL_UNTOUCHABLE = 60,
    CTRL_RAINBOW = 61,
    CTRL_WINDCATCHER = 62,
    CTRL_MAX = 63,
};
} // namespace nspGear

enum enmDraw2DGearMode {
    GEAR_DRAW_2D_MODE_OPEN = 0,
    GEAR_DRAW_2D_MODE_CLOSE = 1,
    GEAR_DRAW_2D_MODE_LOCKED = 2,
};

class _Draw2DData {
public:
    enmDraw2DGearMode aeGearMode[3];     // offset 0x0, size 0xC
    enmDraw2DType aeDrawType[3];         // offset 0xC, size 0xC
    nspGear::enmLevel eNextChangeGearLv; // offset 0x18, size 0x4
    nspGear::enmLevel ePrevChangeGearLv; // offset 0x1C, size 0x4
    u8 u8DataNum;                        // offset 0x20, size 0x1
};

// total size: 0x110
class clsGearCtrl {
public:
    enum enmCtrlMode {
        CTRL_MODE_WALK = 0,
        CTRL_MODE_RIDE = 1,
        CTRL_MODE_CHANGE = 2,
        CTRL_MODE_ADD_PARTS = 3,
        CTRL_MODE_GDIVE = 4,
    };

    enum enmActionMode {
        ACTION_MODE_NON = 0,
        ACTION_MODE_GETTING_ON = 1,
        ACTION_MODE_GETTING_OFF = 2,
    };

    enum enmInitBoard {
        INIT_BOARD_CASE = 0,
        INIT_BOARD_GEAR = 1,
    };

    clsGearCtrl(clsPlayerTask* pcPlayer, nspGear::enmGearCtrl eCtrlNo, u32 u32EquipsGears);

    virtual ~clsGearCtrl();

    void setUnuseGearLevel(nspGear::enmLevel eLevel);
    void changeInitGearModel(enmInitBoard eBoard);
    u8 getEquipsGearFlags() const;
    enmMotionType getEquipsGearBaseMotionType();
    enmGearType getEquipsGearType();
    void behavior_NodeMtx();
    void behavior();
    void registGearRideEffect(bool bIsRide);
    void registGearChangeEffect(nspGear::enmLevel eLevel, nspGear::enmGearType eOldType);
    nspGear::enmLevel searchGearFromGearParamType(nspCom::enmComGearChangeType eType);
    void stopMonumentFlySe();
    void playMonumentFlySe();
    void controlMotion();
    void draw(const f32 (*psGearMtx)[4][4], u32 u32AddDrawFlagI);
    void updateAction();
    void updateDraw2DData();
    void updateLockFlag();
    void cancelGDive();
    u8 requestGearRide_HideActiveGear(u8 u8IsRide, f32 f32LinkFrame, s32 eSuccessActionType);
    u8 requestGearRide_AttackAction(u8 u8IsRide, f32 f32LinkFrame, s32 eSuccessActionType);
    u8 requestGearRide(u8 u8IsRide, f32 f32LinkFrame, s32 eSuccessActionType);
    u8 rideGear(u8 u8IsRide,
                f32 f32LinkFrame,
                s32 eSuccessActionType,
                nspMotion::enmMotion eMotion);
    void requestGearChangeForGhost(u8 u8ChangeNo);
    u8 requestGearChange();
    nspGear::enmLevel calcChageGearLevel();
    void equipsGear(u8 u8GearLevel);
    enmCtrlMode _equipsGear(u8 u8GearLevel);
    clsGearBasePrototype* getEquipsPrototypeGear();
    void updatePrfm();
    void copyGearLv(clsGearCtrl* pcPlayerGearCtrl);
    void init();
    void setGearModels();
    void createGear();

    u8 isRide() const { return m_eCtrlMode == CTRL_MODE_RIDE; }
    stcCtrlData* getCtrlData() const { return m_posData; }
    stcAddPrfm* getAddPrfmData() const { return const_cast<stcAddPrfm*>(&m_sAddPrfmData); }
    nspGear::enmGearCtrl getGearCtrlNo() const { return m_eCtrlNo; }

    clsGear* m_apcGear[4];                      // offset 0x4, size 0x10
    clsInitialBoard* m_pcInitBoardGear;         // offset 0x14, size 0x4
    u8 m_abIsAlreadyUsed[4];                    // offset 0x18, size 0x4
    u8 m_abIsLocked[4];                         // offset 0x1C, size 0x4
    f32 m_af32CloseWaitFrame[4];                // offset 0x20, size 0x10
    clsGear* m_apcEquipsGears[5];               // offset 0x30, size 0x14
    clsGear* m_pcOldChangeGear;                 // offset 0x44, size 0x4
    clsGearBaseParts* m_pcOldParts;             // offset 0x48, size 0x4
    clsGearBaseParts* m_pcNewParsGear;          // offset 0x4C, size 0x4
    stcCtrlData* m_posData;                     // offset 0x50, size 0x4
    nspGear::enmGearCtrl m_eCtrlNo;             // offset 0x54, size 0x4
    u32 m_u32InitEquipsGears;                   // offset 0x58, size 0x4
    stcAddPrfm m_sAddPrfmData;                  // offset 0x5C, size 0x6C
    clsPlayerTask* m_pcPlayer;                  // offset 0xC8, size 0x4
    enmCtrlMode m_eCtrlMode;                    // offset 0xCC, size 0x4
    enmActionMode m_eActionMode;                // offset 0xD0, size 0x4
    f32 m_f32DrawAlpha;                         // offset 0xD4, size 0x4
    u8 m_u8MaxGearNum;                          // offset 0xD8, size 0x1
    s8 m_s8RunChannel_ICS;                      // offset 0xD9, size 0x1
    s8 m_s8MonumentFlyChannel_ICS;              // offset 0xDA, size 0x1
    u8 m_bIsPlayMonumentFly;                    // offset 0xDB, size 0x1
    u8 m_bSeWalkFlag;                           // offset 0xDC, size 0x1
    u8 m_bIsDrawActiveGear;                     // offset 0xDD, size 0x1
    u8 m_bIsDrawBurnLight;                      // offset 0xDE, size 0x1
    u32 m_u32EffectType;                        // offset 0xE0, size 0x4
    f32 m_f32EffectFrameEx;                     // offset 0xE4, size 0x4
    _Draw2DData m_sDraw2DData;                  // offset 0xE8, size 0x24
    clsModelType_OB_TX* m_pcInitBoardGearModel; // offset 0x10C, size 0x4
};

#endif // GEARCTRL_HPP
