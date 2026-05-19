#ifndef GRAVITYWAVEMOTIONBLURPLAYER_HPP
#define GRAVITYWAVEMOTIONBLURPLAYER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsPlayerTask;

class clsGravityWaveMotionBlurPlayer_Task : public clsTask {
public:
    virtual ~clsGravityWaveMotionBlurPlayer_Task() {}
    virtual void execute();
    virtual void draw();

public:
    f32 m_f32Distance;         // offset 0x54, size 0x4
    u32 m_u32PlayerNo;         // offset 0x58, size 0x4
    clsPlayerTask* m_pcPlayer; // offset 0x5C, size 0x4
};

#endif // GRAVITYWAVEMOTIONBLURPLAYER_HPP
