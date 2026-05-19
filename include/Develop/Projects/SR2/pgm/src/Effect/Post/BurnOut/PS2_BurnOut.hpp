#ifndef PS2_BURNOUT_HPP
#define PS2_BURNOUT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x3
struct stcBurnOutSystem {
    u8 u8EraseAlpha;  // offset 0x0, size 0x1
    u8 u8EraseColor;  // offset 0x1, size 0x1
    u8 u8PathDrawNum; // offset 0x2, size 0x1
};

// total size: 0x68
class clsBurnOut_End_Task : public clsTask {
public:
    clsBurnOut_End_Task();
    virtual ~clsBurnOut_End_Task();

    void draw();

    u32 m_u32WY;                             // offset 0x54, size 0x4
    u32 m_u32FBHx16;                         // offset 0x58, size 0x4
    u32 m_u32WY_FBHx16;                      // offset 0x5C, size 0x4
    u64* m_pu64GsPacket_Setting_SpBuf2SpBuf; // offset 0x60, size 0x4
    u64* m_pu64GsPacket_Setting_SpBuf2Fb;    // offset 0x64, size 0x4
};

// total size: 0x58
class clsBurnOut_Begin_Task : public clsTask {
public:
    clsBurnOut_Begin_Task();
    virtual ~clsBurnOut_Begin_Task() {}

    virtual void execute();
    virtual void draw();

    u32 m_u32GsRestPage2; // offset 0x54, size 0x4
};

#endif // PS2_BURNOUT_HPP
