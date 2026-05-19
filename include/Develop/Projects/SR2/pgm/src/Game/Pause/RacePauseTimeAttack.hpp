#ifndef RACEPAUSETIMEATTACK_HPP
#define RACEPAUSETIMEATTACK_HPP

#include "Develop/Projects/SR2/pgm/src/Game/Pause/BaseRacePause.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/TimeAttack.hpp"

// total size: 0x74
class clsRacePauseTimeAttack_Task : public clsBaseRacePause_Task {
public:
    clsRacePauseTimeAttack_Task(s32 s32PushPausePadNoI,
                                s32& reRacePauseRetI,
                                clsTimeAttack_Task* pcTimeAtkTask,
                                s32 s32Type,
                                s32 s32StageNo);
    virtual ~clsRacePauseTimeAttack_Task() {}

    virtual void execute();
    virtual void draw();

    s32 m_s32StageNo;                    // offset 0x60, size 0x4
    s32 m_s32Type;                       // offset 0x64, size 0x4
    s32 m_s32SubMode;                    // offset 0x68, size 0x4
    s32 m_s32DownMode;                   // offset 0x6C, size 0x4
    clsTimeAttack_Task* m_pcTimeAtkTask; // offset 0x70, size 0x4
};

#endif // RACEPAUSETIMEATTACK_HPP
