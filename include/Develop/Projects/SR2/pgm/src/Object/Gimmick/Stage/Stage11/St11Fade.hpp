#ifndef ST11FADE_HPP
#define ST11FADE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OODeque.hpp"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "Develop/Projects/SR2/pgm/src/System/ScissorRect.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x20
class clsFadeCircle_Obj {
public:
    enum enmType {
        OUT = 0,
        IN = 1,
        OUT_IN = 2,
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
    clsFadeCircle_Task() : clsTask(700099, 6), m_psPrimArray(NULL)
    {
        m_u32PrimArrayNum = 4;
        m_psPrimArray = new NNS_PRIM2D_PC[m_u32PrimArrayNum];
        memset(m_u8RegistCount, 0, sizeof(m_u8RegistCount));
    }
    virtual ~clsFadeCircle_Task();

    virtual void execute();
    virtual void draw();

    void regist(u32 u32ViewNoI,
                f32 f32EndFrameI,
                clsFadeCircle_Obj::enmType eTypeI,
                u32 u32RgbColI);

    NNS_PRIM2D_PC* m_psPrimArray; // offset 0x58, size 0x4
    u32 m_u32PrimArrayNum;        // offset 0x5C, size 0x4
    u8 m_u8RegistCount[4];        // offset 0x60, size 0x4
    oostd::clsOODeque<clsFadeCircle_Obj*, oostd::clsOOStlAllocator<clsFadeCircle_Obj*> >
        m_dqFadeCircleObj; // offset 0x64, size 0x20
};

inline clsFadeCircle_Task::~clsFadeCircle_Task()
{
    while (!m_dqFadeCircleObj.empty()) {
        delete m_dqFadeCircleObj.front();
        m_dqFadeCircleObj.pop_front();
    }
    // Original calls scalar operator delete for this primitive allocation.
    delete m_psPrimArray;
    m_psPrimArray = NULL;
}

#endif // ST11FADE_HPP
