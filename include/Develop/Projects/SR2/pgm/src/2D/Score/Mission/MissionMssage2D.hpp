#ifndef MISSIONMSSAGE2D_HPP
#define MISSIONMSSAGE2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Screen2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Mission/Mission2D.hpp"

class clsPressStart_Task;

// total size: 0xD4
class clsMissionMessage2D_Task : public clsTask, public clsScreen2D {
public:
    // Note: enuDrawMode has 3 conflicting bodies with same name globally;
    // nested here to avoid redefinition of clsMission2D_Task::enuDrawMode
    enum enuDrawMode {
        DRAW_MODE__COMPLETE = 0,
        DRAW_MODE__FAILED = 1,
        DRAW_MODE__TIME_UP = 2,
        DRAW_MODE__GO = 3,
        DRAW_MODE__FAST_MISSION = 4,
        DRAW_MODE__LOWLOADING = 5,
    };

    virtual ~clsMissionMessage2D_Task() {}
    virtual void execute();
    virtual void draw();

    void drawFastMission();
    void drawNowLoading();
    void mainFastMission();
    void mainGo();
    void mainFailedTimeUp();
    void mainComplete();
    void init();

    stcPos2D* m_opsPosVec;                        // offset 0x94, size 0x4
    u32 m_u32AnmType;                             // offset 0x98, size 0x4
    enuDrawMode m_eDrawModeNo;                    // offset 0x9C, size 0x4
    u8* m_pbEndFlag;                              // offset 0xA0, size 0x4
    s32 m_s32CenterX;                             // offset 0xA4, size 0x4
    s32 m_s32CenterY;                             // offset 0xA8, size 0x4
    f32 m_f32Alpha;                               // offset 0xAC, size 0x4
    f32 m_f32AnmAlpha;                            // offset 0xB0, size 0x4
    f32 m_f32AnmFrame;                            // offset 0xB4, size 0x4
    f32 m_f32MoveX;                               // offset 0xB8, size 0x4
    f32 m_f32MoveY;                               // offset 0xBC, size 0x4
    f32 m_f32Scale;                               // offset 0xC0, size 0x4
    s32 m_s32Count;                               // offset 0xC4, size 0x4
    u32 m_u32ButtonCount;                         // offset 0xC8, size 0x4
    clsMissionRace_Task* m_pcMissionRace;         // offset 0xCC, size 0x4
    clsPressStart_Task* m_pcPressStart2Quit_Task; // offset 0xD0, size 0x4
};

#endif // MISSIONMSSAGE2D_HPP
