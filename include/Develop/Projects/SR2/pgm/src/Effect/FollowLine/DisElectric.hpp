#ifndef DISELECTRIC_HPP
#define DISELECTRIC_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "usr/local/sega/nn/src/Matrix/nnmatrix.h"

// total size: 0x10C
class clsDisElectric_Task : public clsTask {
public:
    // total size: 0x10
    struct stcParam {
        f32 f32LifeFrame; // offset 0x0, size 0x4
        f32 f32Length;    // offset 0x4, size 0x4
        f32 f32StTu;      // offset 0x8, size 0x4
        s32 s32RotA32;    // offset 0xC, size 0x4
    };

    clsDisElectric_Task(u32 u32View, u32 u32PlayerNo);
    virtual ~clsDisElectric_Task() {}

    f32 m_f32TaFrame;       // offset 0x54, size 0x4
    u32 m_u32ViewNo;        // offset 0x58, size 0x4
    u32 m_u32PlayerNo;      // offset 0x5C, size 0x4
    s16 m_s16Num;           // offset 0x60, size 0x2
    f32 m_f32MaxLifeFrame;  // offset 0x64, size 0x4
    f32 m_f32WaitFrame;     // offset 0x68, size 0x4
    stcParam m_asParam[10]; // offset 0x6C, size 0xA0

    static _NNS_TEXLIST* m_tpsTexList;

    virtual void execute();
    virtual void draw();
};

#endif // DISELECTRIC_HPP
