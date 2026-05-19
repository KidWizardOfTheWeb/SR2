#ifndef STORY2D_HPP
#define STORY2D_HPP

#include "Develop/Projects/SR2/pgm/src/Game/StoryRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsStory2D_Task : public clsTask {
public:
    clsStory2D_Task();

    virtual ~clsStory2D_Task();
    virtual void execute();
    virtual void draw();

    void drawSubject(s32 s32Param1, u32 u32Param2);

    void* m_pvLoadingTexBuffer;            // offset 0x54, size 0x4
    void* m_pv2dTexBuffer;                 // offset 0x58, size 0x4
    clsStoryRace_Task* m_pcStoryRace_Task; // offset 0x5C, size 0x4
};

#endif // STORY2D_HPP
