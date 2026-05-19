#ifndef COMKEY_HPP
#define COMKEY_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/PlayerKey.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Key/ComAI.hpp"

class clsPlayerTask;

enum enmComGearChangeMode {
    GEAR_CHANGE_MODE_RACE = 0,
    GEAR_CHANGE_MODE_MISSION = 1,
    GEAR_CHANGE_MODE_MAX = 2,
};

// total size: 0x190
class clsComKey : public clsPlayerKey, public clsComAI {
public:
    u16 m_u16GrindJumpLineNo;         // offset 0x150, size 0x2
    s16 m_s16GrindAccessWaitCnt;      // offset 0x152, size 0x2
    u8 m_bIsGrindFirstJump;           // offset 0x154, size 0x1
    u8 m_bIsGDiveTry;                 // offset 0x155, size 0x1
    u8 m_bIsTrickRailLinkTry;         // offset 0x156, size 0x1
    u8 m_bIsStartReverOn;             // offset 0x157, size 0x1
    u8 m_u8OldTrickKey;               // offset 0x158, size 0x1
    s8 m_s8OldCurveLever;             // offset 0x159, size 0x1
    NNS_VECTORFAST m_sOffsetEndPoint; // offset 0x160, size 0x10
    s32 m_s32OffsetSign;              // offset 0x170, size 0x4
    f32 m_f32OffsetPointPos;          // offset 0x174, size 0x4
    u8 m_bIsGCtrlTry;                 // offset 0x178, size 0x1
    NNS_VECTORFAST* m_psGCtrlEndPos;  // offset 0x17C, size 0x4
    s32 m_s32GCtrlRestFrame;          // offset 0x180, size 0x4

    clsComKey(clsPlayerTask* param);
    virtual ~clsComKey();

    virtual void requestRumble(u32 param) {}
    virtual void playSfSe_User(s32 param);
    virtual void playSfSe_Com(s32 param);
    virtual void playSfPadSe(s32 param) {}
    virtual void stopSfPadSe(s32 param) {}
    virtual void reset();
    virtual void updateKey();

    virtual enmComGearChangeMode getGearChangeMode() const { return GEAR_CHANGE_MODE_RACE; }
    virtual u32 execNull() { return 0; }
    virtual u32 execDamage00() { return 0; }
    virtual u32 execDemo();
    virtual u32 execWalk();
    virtual u32 execIntertia() { return 0; }
    virtual u32 execRun();
    virtual u32 execBrake() { return 0; }
    virtual u32 execFlight() { return 0; }
    virtual u32 execJump();
    virtual u32 execTrick();
    virtual u32 execPath() { return 0; }
    virtual u32 execAttack00();
    virtual u32 execRail();
    virtual u32 execFly();
    virtual u32 execPower() { return 0; }
    virtual u32 execGDive();
    virtual u32 execGCtrlSlide();
    virtual u32 execGCtrlFlight();
    virtual u32 execWheelDrift();
    virtual u32 execFalseStart() { return 0; }
    virtual u32 execDirRegulateRun() { return 0; }
    virtual u32 execTranslationMovePath() { return 0; }
    virtual u32 execReStart() { return 0; }
    virtual u32 execGimmickMove() { return 0; }
    virtual u32 execAttackDamage() { return 0; }
    virtual u32 execBoost();
    virtual void preparesNextLineAction();

    static void* t_pfExecAction[];
};

#endif // COMKEY_HPP
