#ifndef BREAKCONTROL_HPP
#define BREAKCONTROL_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"
#include "types.h"

// total size: 0x30
class clsBreakControl {
public:
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    clsBreakControl() {}
    ~clsBreakControl() {}

    void reset()
    {
        m_s32ContactNum = 0;
        m_eMode = MODE_NONE;
        m_bDraw = 1;
        m_cBreakFrame.m_f32Frame = -2.0f;
        m_cLimitFrame.m_f32Frame = -2.0f;
        m_cRebirthFrame.m_f32Frame = -2.0f;
    }
    u8 isDraw() const { return m_bDraw; }
    void setBreak()
    {
        m_eMode = MODE_BREAK;
        m_bDraw = 0;
    }
    void startRebirth() { m_cRebirthFrame.m_f32Frame = m_cRebirthFrame.m_f32CountFrame; }
    f32 getLimitFrameRate() { return 0.0f; }
    u8 isBreak() const { return m_eMode == 2; }
    u8 isExecute() const { return m_eMode == 1; }
    void setBreakInfo(s32 s32ContactNum,
                      f32 f32ContactFrame,
                      f32 f32LimitFrame,
                      f32 f32RebirthFrame)
    {
    }
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
