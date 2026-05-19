#ifndef ST11FADE_HPP
#define ST11FADE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/MagBarrier.hpp"
#include "Develop/Projects/SR2/pgm/src/System/ScissorRect.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

struct NNS_PRIM2D_PC;

// total size: 0x20
class clsFadeCircle_Obj {
public:
    enum enmType {
        TYPE_NULL = 0,
        TYPE_NORMAL = 1,
        TYPE_GCTRL = 2,
        TYPE_STEEP = 3,
    };

    virtual ~clsFadeCircle_Obj() {}

    void draw();

    f32 m_f32EndFrame;            // offset 0x4, size 0x4
    f32 m_f32LifeFrame;           // offset 0x8, size 0x4
    u32 m_u32RgbCol;              // offset 0xC, size 0x4
    enmType m_eType;              // offset 0x10, size 0x4
    stcScissorRect* m_opsScissor; // offset 0x14, size 0x4
    u32 m_u32ViewNo;              // offset 0x18, size 0x4
    u8 m_bIn_OutIn;               // offset 0x1C, size 0x1
};

// total size: 0x84
class clsFadeCircle_Task : public clsTask, public clsSingleton<clsFadeCircle_Task> {
public:
    clsFadeCircle_Task() : clsTask(0, 0) {}
    virtual ~clsFadeCircle_Task() {}

    virtual void execute();
    virtual void draw();

    void regist(u32 u32ViewNoI,
                f32 f32EndFrameI,
                clsFadeCircle_Obj::enmType eTypeI,
                u32 u32RgbColI);

    NNS_PRIM2D_PC* m_psPrimArray; // offset 0x58, size 0x4
    u32 m_u32PrimArrayNum;        // offset 0x5C, size 0x4
    u8 m_u8RegistCount[4];        // offset 0x60, size 0x4
    clsOODeque m_dqFadeCircleObj; // offset 0x64, size 0x20
};

#endif // ST11FADE_HPP
