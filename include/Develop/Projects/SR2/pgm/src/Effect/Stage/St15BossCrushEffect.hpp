#ifndef ST15BOSSCRUSHEFFECT_HPP
#define ST15BOSSCRUSHEFFECT_HPP

#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSt15BossCrushEffect_Task : public clsTask {
public:
    clsSt15BossCrushEffect_Task(const f32 (*opsMatrix)[4][4], const NNS_VECTORFAST* opsPosVecFast);
    virtual ~clsSt15BossCrushEffect_Task();
    virtual void execute();
    virtual void draw();

    // Members
    f32 (*m_opsDrawMatrix)[4][4];        // offset 0x54, size 0x4
    NNS_VECTORFAST* m_opsPosVecFast;     // offset 0x58, size 0x4
    clsModelType_OB_TX_MO_MA* m_pcModel; // offset 0x5C, size 0x4
    u8 m_bWhiteOut;                      // offset 0x60, size 0x1
    u8 m_u8NegaNum;                      // offset 0x61, size 0x1
    f32 m_f32MotFrame;                   // offset 0x64, size 0x4
    f32 m_f32MatFrame;                   // offset 0x68, size 0x4
    f32 m_f32WaitFrame;                  // offset 0x6C, size 0x4
    f32 m_f32WhiteWaitFrame;             // offset 0x70, size 0x4
    f32 m_f32NegaWaitFrame;              // offset 0x74, size 0x4
};

#endif
