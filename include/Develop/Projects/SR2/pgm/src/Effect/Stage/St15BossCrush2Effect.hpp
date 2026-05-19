#ifndef ST15BOSSCRUSH2EFFECT_HPP
#define ST15BOSSCRUSH2EFFECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsModelType_OB_TX_MO_MA;

class clsSt15BossCrush2Effect_Task : public clsTask {
public:
    clsSt15BossCrush2Effect_Task(const f32 (*opsMatrix)[4][4]);
    virtual ~clsSt15BossCrush2Effect_Task() {}

    void execute();
    void draw();

    // Members
public:
    f32 (*m_opsDrawMatrix)[4][4];        // offset 0x54, size 0x4
    clsModelType_OB_TX_MO_MA* m_pcModel; // offset 0x58, size 0x4
    f32 m_f32MotFrame;                   // offset 0x5C, size 0x4
    f32 m_f32MatFrame;                   // offset 0x60, size 0x4
};

#endif // ST15BOSSCRUSH2EFFECT_HPP
