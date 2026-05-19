#ifndef SURVIVALRELAYRACE_HPP
#define SURVIVALRELAYRACE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/src/System/SrCamCtrl.hpp"

class clsPlayerTask;

// total size: 0xDB0
class clsSurvivalRelayRace_Task : public clsBaseRace_Task {
public:
    void* m_pvWinLose2DPackBuffer;         // offset 0xCB0, size 0x4
    void* m_pvSurvivalMessage2DPackBuffer; // offset 0xCB4, size 0x4
    u32 m_u32ViewNum;                      // offset 0xCB8, size 0x4
    s32 m_as32MaxLap[2];                   // offset 0xCBC, size 0x8
    s32 m_as32PlayerNo[2];                 // offset 0xCC4, size 0x8
    s32 m_as32NextPlayerNo[2];             // offset 0xCCC, size 0x8
    s32 m_as32TypeNo[2];                   // offset 0xCD4, size 0x8
    u32 m_u32TeamPlayerNum;                // offset 0xCDC, size 0x4
    u32 m_as32WalkRunCount[2];             // offset 0xCE0, size 0x8
    clsTask* m_psParticle;                 // offset 0xCE8, size 0x4
    clsTask* m_psWinLose;                  // offset 0xCEC, size 0x4
    NNS_VECTORFAST m_sPosVecFast[2];       // offset 0xCF0, size 0x20
    NNS_VECTOR m_sRotVecFast[2];           // offset 0xD10, size 0x18
    stcCamFilter m_sStartInFilter;         // offset 0xD28, size 0x3C
    stcCamFilter m_sStartOutFilter;        // offset 0xD64, size 0x3C
    u8 m_abPlayerWinFlag[2];               // offset 0xDA0, size 0x2
    u8 m_bWinDrawFlag;                     // offset 0xDA2, size 0x1
    u8 m_bReplaced;                        // offset 0xDA3, size 0x1

    static u32 m_u32BattleCount;
    static u32 m_au32PlayerWinCount[4];

    clsSurvivalRelayRace_Task(
        s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, const stcSendAdv* p6, void** p7, enmMode p8);
    virtual ~clsSurvivalRelayRace_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void endDemoSetting();
    virtual void start() {}
    virtual void updateRanking();
    virtual u8 packEtc();
    virtual u8 checkGoalPlayer();
    virtual void restart() {}
    virtual void initStartCamMotion();
    virtual void endStartCamMotion();
    virtual void Main() {}
    virtual void requestReadEtc();

    void WalkRanAreaGoesOutPlayer(s32 s32TeamNo);
    void ChangeNextPlayer(s32 p1, s32 p2, s32 p3, s32 p4, bool p5);
    void StartDash(clsPlayerTask* pcNextPlayer);
    void SettingNextPlayer(
        s32 p1, u32 p2, const NNS_VECTORFAST* p3, const NNS_VECTOR* p4, const NNS_VECTOR* p5);

    void setPlayerGear(u32 u32PlayerNum, stcSendAdv* pcSendAdv);

    u32 getTeamPlayerNum() { return m_u32TeamPlayerNum; }
    s32 getPlayerNo(s32 param_1) { return m_as32PlayerNo[param_1]; }
};

#endif // SURVIVALRELAYRACE_HPP
