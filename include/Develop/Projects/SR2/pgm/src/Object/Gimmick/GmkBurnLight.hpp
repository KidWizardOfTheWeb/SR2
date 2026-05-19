#ifndef GMKBURNLIGHT_HPP
#define GMKBURNLIGHT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Object/nnobject.h"

// total size: 0x6C
template <class T_MODEL>
class clsGmkBurnLight_Task : public clsTask {
public:
    clsGmkBurnLight_Task(T_MODEL& rcGmkModelI, u32 u32ObjectNumI, s32 s32DrawNodeNoI)
        : clsTask(0, 0), m_rcModel(rcGmkModelI), m_16ObjectNum(u32ObjectNumI), m_s16DrawNum(0),
          m_s8DrawNodeNo(s32DrawNodeNoI)
    {
    }
    virtual ~clsGmkBurnLight_Task() {}
    virtual void execute() {}
    virtual void draw() {}
    void update(f32 (&rsMtxWorkI)[4][4]) {}
    void resetDrawNode(NNS_OBJECT& rsObjectI) {}
    void setDrawNode(NNS_OBJECT& rsObjectI) {}

    f32 (*m_psMtxWork_Mutable)[4][4]; // offset 0x54, size 0x4
    f32* m_pf32MotionFrame;           // offset 0x58, size 0x4
    f32* m_pf32MatMotionFrame;        // offset 0x5C, size 0x4
    T_MODEL& m_rcModel;               // offset 0x60, size 0x4
    s16 m_16ObjectNum;                // offset 0x64, size 0x2
    s16 m_s16DrawNum;                 // offset 0x66, size 0x2
    s8 m_s8DrawNodeNo;                // offset 0x68, size 0x1
};

#endif // GMKBURNLIGHT_HPP
