#ifndef TUTORIAL2D_HPP
#define TUTORIAL2D_HPP

#include "Develop/Projects/SR2/pgm/src/Game/TutorialRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"

// total size: 0x60
class clsTutorial2D_Task : public clsTask {
public:
    virtual ~clsTutorial2D_Task();
    virtual void execute();
    virtual void draw();

    clsTutorial2D_Task(s32 s32TutorialNoI);
    void drawSubject(s32 s32DrawYI, u32 u32DrawBlackBackI, u32 u32WindowType);

    clsTutorialRace_Task* m_pcTutorialRace_Task; // offset 0x54, size 0x4
    void* m_pv2dTexBuffer;                       // offset 0x58, size 0x4
    u8 m_u8FontPfOffsetNum;                      // offset 0x5C, size 0x1
    s8 m_s8TutorialNo;                           // offset 0x5D, size 0x1
};

#endif
