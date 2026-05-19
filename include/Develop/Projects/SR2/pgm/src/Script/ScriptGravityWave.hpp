#ifndef SCRIPTGRAVITYWAVE_HPP
#define SCRIPTGRAVITYWAVE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/GravityWave/PS2_GravityWave.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsScript_Task;

// total size: 0xF0
class clsScriptNega_Task : public clsGravityWave_Task {
public:
    clsScriptNega_Task(u8 u8PriorityType,
                       u8 u8Type,
                       u8 u8rgb,
                       f32 f32Frame,
                       f32 f32SubFrame,
                       f32 f32EndFrame,
                       f32 f32WaitFrame,
                       clsTask* pcTask);
    virtual ~clsScriptNega_Task();
    virtual void execute();
    virtual void draw();
    virtual void reset();

    void codeNega(u8* pu8Ptr, clsScript_Task* pParam2);
    void codeNegaEnd(u8* pu8Ptr, clsScript_Task* pParam2);
    s32 DebugNega(s32 s32xI, s32 s32yI, s32 s32ActiveNoI, s32 s32SpeedI);

    u8 m_u8Type;             // offset 0xD0, size 0x1
    u8 m_u8Rgb;              // offset 0xD1, size 0x1
    f32 m_f32Frame;          // offset 0xD4, size 0x4
    f32 m_f32SubFrame;       // offset 0xD8, size 0x4
    f32 m_f32EndFrame;       // offset 0xDC, size 0x4
    f32 m_f32WaitFrame;      // offset 0xE0, size 0x4
    u8 m_bEndFlg;            // offset 0xE4, size 0x1
    s16 m_s16EndFrame;       // offset 0xE6, size 0x2
    clsTask* m_pcScriptTask; // offset 0xE8, size 0x4

    // total size: 0xF0
};

// total size: 0xE0
class clsScriptWave_Task : public clsGravityWave_Task {
public:
    clsScriptWave_Task(u8 u8Param1, f32 fParam1, f32 fParam2, clsTask* pcTask);
    virtual ~clsScriptWave_Task();
    virtual void execute();
    virtual void draw();

    void codeWave(u8* pu8Ptr, clsScript_Task* pParam2);
    void codeWaveEnd(u8* pu8Ptr, clsScript_Task* pParam2);
    s32 DebugWave(s32 s32Param1, s32 s32Param2, s32 s32Param3, s32 s32Param4);

    f32 m_f32Frame;          // offset 0xD0, size 0x4
    f32 m_f32EndFrame;       // offset 0xD4, size 0x4
    f32 m_f32WaitFrame;      // offset 0xD8, size 0x4
    clsTask* m_pcScriptTask; // offset 0xDC, size 0x4
};

// total size: 0x14
struct stcScriptNega {
    u8 bUsed;          // offset 0x0, size 0x1
    u8 u8TaskPriority; // offset 0x1, size 0x1
    u8 u8Type;         // offset 0x2, size 0x1
    u8 u8rgb;          // offset 0x3, size 0x1
    f32 f32StartFrame; // offset 0x4, size 0x4
    f32 f32SubFrame;   // offset 0x8, size 0x4
    f32 f32EndFrame;   // offset 0xC, size 0x4
    f32 f32WaitFrame;  // offset 0x10, size 0x4
};

// total size: 0xC
struct stcScriptWave {
    u8 u8TaskPriority; // offset 0x0, size 0x1
    f32 f32EndFrame;   // offset 0x4, size 0x4
    f32 f32WaitFrame;  // offset 0x8, size 0x4
};

#endif // SCRIPTGRAVITYWAVE_HPP
