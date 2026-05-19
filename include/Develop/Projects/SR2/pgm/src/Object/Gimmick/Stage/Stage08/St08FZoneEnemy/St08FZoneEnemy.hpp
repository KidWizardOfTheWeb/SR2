#ifndef ST08FZONEENEMY_HPP
#define ST08FZONEENEMY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

struct stcPointData;

// total size: 0x100
class clsFZoneEnemy_Obj : public clsRigidBodyGimmickObj {
public:
    // Note: enmMode — DWARF body has GAME_MODE___NONE values; name collision
    // with Game.hpp. Nested to avoid conflict; verify correct body during implementation.
    enum enmMode {
        GAME_MODE___NONE = 0,
        GAME_MODE___ADVERTISE = 1,
        GAME_MODE___TITLE_DEMO = 2,
        GAME_MODE___FREE_RACE = 3,
        GAME_MODE___TIME_ATTACK = 4,
        GAME_MODE___STORY = 5,
        GAME_MODE___WORLD_GP = 6,
        GAME_MODE___MISSION = 7,
        GAME_MODE___TUTORIAL = 8,
        GAME_MODE___SURVIVAL_RELAY = 9,
        GAME_MODE___SURVIVAL_BALL = 10,
        GAME_MODE___SURVIVAL_BATTLE = 11,
        GAME_MODE___EVENT = 12,
        GAME_MODE___CREDIT = 13,
        GAME_MODE___EASY_MENU = 14,
        GAME_MODE___MODEL_VIEWER = 15,
        GAME_MODE___MAX = 16,
    };

    // Note: enmState — DWARF body; name collision with St03Cogwheel.hpp.
    // Nested to avoid conflict; verify correct body during implementation.
    enum enmState {
        STATE_WAIT = 0,
        STATE_MOVE_UFO = 1,
        STATE_RETURN_UFO = 2,
        STATE_END_UFO = 3,
        STATE_FALL = 4,
        STATE_MOVE_PATH = 5,
        STATE_BALL_BREAK = 6,
        STATE_END = 7,
        STATE_STARTWAIT = 8,
    };

    virtual ~clsFZoneEnemy_Obj() {}
    clsFZoneEnemy_Obj() {}

    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST08_FZONE_ENEMY_18060; }
    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void mainCrash();
    virtual void requestDrawBreakEffect();

    void draw(clsModelType_OB_TX_MO& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    void setVelocityAndFrame(f32 f32LengthRate, f32 f32Speed);

    static f32 m_tof32CLIP_DISTx2;

    enmMode m_eMode;                 // offset 0xD0, size 0x4
    enmState m_eState;               // offset 0xD4, size 0x4
    f32 m_f32Speed;                  // offset 0xD8, size 0x4
    f32 m_f32RotX;                   // offset 0xDC, size 0x4
    f32 m_f32AddRotX;                // offset 0xE0, size 0x4
    clsFrameControl m_cFrameControl; // offset 0xE4, size 0x8
    u8 m_u8NowPointNo;               // offset 0xEC, size 0x1
    s8 m_s8AddPoint;                 // offset 0xED, size 0x1
    stcPointData* m_opsPointData;    // offset 0xF0, size 0x4
    u8 m_u8PointNum;                 // offset 0xF4, size 0x1
};

class clsFZoneEnemy_Task : public clsSingleModelGimmick_Task<clsFZoneEnemy_Task,
                                                             clsFZoneEnemy_Obj,
                                                             clsModelType_OB_TX_MO> {
public:
    clsFZoneEnemy_Task(u32 u32Param1) : clsSingleModelGimmick_Task(0, 0) {}
    virtual ~clsFZoneEnemy_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // ST08FZONEENEMY_HPP
