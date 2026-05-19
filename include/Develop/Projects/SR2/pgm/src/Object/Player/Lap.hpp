#ifndef LAP_HPP
#define LAP_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/MissionRace.hpp"

class clsPlayerTask;

class clsLap {
public:
    virtual ~clsLap();

    virtual void update();
    virtual void reset();
    virtual void copyLapNum(const clsLap& rLap);

    void initFirstAllocate(u32 u32Arg);
    void startLap();
    void updateMaxLap();
    void setComGoal();
    void setRecordTime(u8 u8Arg, u32 u32Arg);
    void copyPlayerLapTime(clsPlayerTask* pcPlayer);

    u32 getTotalMsecTime() const;
    void getTotalTime(stcRecord& rRecord) const;
    s32 getMaxLapNo() const { return m_s32MaxLap; }

    // Members
    u32 m_u32GoalNum;                  // offset 0x4, size 0x4
    clsPlayerTask* m_pcPlayer;         // offset 0x8, size 0x4
    stcRecord* m_pasLapTime;           // offset 0xC, size 0x4
    stcRecord m_sRecord;               // offset 0x10, size 0x4
    stcRecord m_sTimeAttackRecord;     // offset 0x14, size 0x4
    stcRecord m_sTimeAttackTime;       // offset 0x18, size 0x4
    u32 m_u32LastLapTimeMSec;          // offset 0x1C, size 0x4
    s32 m_s32Lap;                      // offset 0x20, size 0x4
    s32 m_s32OldLap;                   // offset 0x24, size 0x4
    s32 m_s32LapNum;                   // offset 0x28, size 0x4
    s32 m_s32LapOld;                   // offset 0x2C, size 0x4
    s32 m_s32DefLap;                   // offset 0x30, size 0x4
    f32* m_paf32OldGoalLineDotProduct; // offset 0x34, size 0x4
    f32 m_f32RankingPoint;             // offset 0x38, size 0x4
    s32 m_s32MaxLap;                   // offset 0x3C, size 0x4
};

#endif // LAP_HPP
