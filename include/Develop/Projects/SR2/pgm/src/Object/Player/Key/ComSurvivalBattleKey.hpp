#ifndef COMSURVIVALBATTLEKEY_HPP
#define COMSURVIVALBATTLEKEY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/ComKey.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x1A0
class clsComSurvivalBattleKey : public clsComKey {
public:
    // Note: enmMode collision with Game.hpp (GAME_MODE___* pParam1) — nested here
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    struct stcRotateData {
        f32 m_f32DotPro;     // offset 0x0, size 0x4
        f32 m_f32RotateRadX; // offset 0x4, size 0x4
        f32 m_f32RotateRadY; // offset 0x8, size 0x4
        s32 m_s32Relesed;    // offset 0xC, size 0x4
    };

    enmMode m_eMode;       // offset 0x190, size 0x4
    f32 m_f32ModeRunFrame; // offset 0x194, size 0x4

    void calcMoveItemBox(NNS_VECTORFAST* pParam1);
    void calcMoveCourse(NNS_VECTORFAST* pParam1);
    void calcRotateTargetPoint(stcRotateData* pParam1, const NNS_VECTORFAST* pParam2);
    void selectModeOddsTable(const s32* pParam1);
    void selectMode();

    virtual ~clsComSurvivalBattleKey() {}
    virtual enmComGearChangeMode getGearChangeMode() const { return GEAR_CHANGE_MODE_RACE; }
    virtual u32 execNull() { return 0; }
    virtual u32 execDamage00() { return 0; }
    virtual u32 execDemo() { return 0; }
    virtual u32 execWalk();
    virtual u32 execIntertia() { return 0; }
    virtual u32 execRun();
    virtual u32 execBrake() { return 0; }
    virtual u32 execFlight() { return 0; }
    virtual u32 execJump() { return 0; }
    virtual u32 execTrick() { return 0; }
    virtual u32 execPath() { return 0; }
    virtual u32 execAttack00() { return 0; }
    virtual u32 execRail() { return 0; }
    virtual u32 execFly() { return 0; }
    virtual u32 execPower() { return 0; }
    virtual u32 execGDive() { return 0; }
    virtual u32 execGCtrlSlide();
    virtual u32 execGCtrlFlight() { return 0; }
    virtual u32 execWheelDrift() { return 0; }
    virtual u32 execFalseStart() { return 0; }
    virtual u32 execDirRegulateRun() { return 0; }
    virtual u32 execTranslationMovePath() { return 0; }
    virtual u32 execReStart() { return 0; }
    virtual u32 execGimmickMove() { return 0; }
    virtual u32 execAttackDamage() { return 0; }
    virtual u8 controlGoalTime(s8 s8Param1);
};

#endif // COMSURVIVALBATTLEKEY_HPP
