#ifndef BREAKCONTROL_HPP
#define BREAKCONTROL_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"
#include "types.h"

#ifndef ENM_MODE_DECLARED
#define ENM_MODE_DECLARED
enum enmMode {
    MODE_NONE = 0,
    MODE_EXECUTE = 1,
    MODE_BREAK = 2,
};
#endif

// total size: 0x30
class clsBreakControl {
public:
    clsBreakControl() {}
    ~clsBreakControl() {}

    u8 isDraw() const { return m_bDraw; }
    void setBreak() {}
    void startRebirth() {}
    f32 getLimitFrameRate() { return 0.0f; }
    u8 isBreak() const { return m_eMode == 2; }
    u8 isExecute() const { return m_eMode == 1; }
    void setBreakInfo(s32 s32Param1, f32 f32Param1, f32 f32Param2, f32 f32Param3) {}
    void start() {}
    void update();

    static f32 t_of32NoRebirthFrame;

    clsFrameControl m_cBreakFrame;   // offset 0x0, size 0x8
    clsFrameControl m_cLimitFrame;   // offset 0x8, size 0x8
    clsFrameControl m_cRebirthFrame; // offset 0x10, size 0x8
    enum enmMode m_eMode;            // offset 0x18, size 0x4
    s32 m_s32ContactNum;             // offset 0x1C, size 0x4
    s32 m_s32BreakContactNum;        // offset 0x20, size 0x4
    u8 m_bDraw;                      // offset 0x24, size 0x1
    s32 m_s32BlinkFrame;             // offset 0x28, size 0x4
    s32 m_s32BlinkInterval;          // offset 0x2C, size 0x4
};

#endif // BREAKCONTROL_HPP
