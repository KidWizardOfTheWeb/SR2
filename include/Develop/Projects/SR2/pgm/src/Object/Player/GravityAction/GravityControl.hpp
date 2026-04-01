#ifndef GRAVITYCONTROL_HPP
#define GRAVITYCONTROL_HPP

// total size: 0x98
struct stcCommonSetting {
    float f32RebootFrame;                    // 0x00
    float f32BonusAccele;                    // 0x04
    float f32BonusMinSpeed;                  // 0x08
    float f32TrackingRadRate;                // 0x0C
    float f32MinSpeed;                       // 0x10
    float f32MaxSpeed;                       // 0x14
    float f32SlideReadyFrame;                // 0x18
    float f32SlideCancelFrame;               // 0x1C
    float f32SlideLimitFrame;                // 0x20
    float f32SlideChargeFrame;               // 0x24
    float f32SlideSlowDownFrame;             // 0x28
    float f32SlideCurveDecayRate;            // 0x2C
    float f32SlideReadyJumpSpeed;            // 0x30
    signed int s32SlideRotateAcceleFrameX;   // 0x34
    signed int s32SlideRotateAcceleFrameY;   // 0x38
    float f32SlideRotateAcceleRadX;          // 0x3C
    float f32SlideRotateAcceleRadY;          // 0x40
    float f32SlideMaxRotateX;                // 0x44
    float f32SlideMaxRotateY;                // 0x48
    float f32SlideMoveFrame;                 // 0x4C
    float f32TrickReadyFrame;                // 0x50
    float f32TrickCancelFrame;               // 0x54
    float f32TrickLimitFrame;                // 0x58
    float f32TrickChargeFrame;               // 0x5C
    float f32TrickSlowDownFrame;             // 0x60
    signed int s32TrickRotateAcceleFrameX;   // 0x64
    signed int s32TrickRotateAcceleFrameY;   // 0x68
    float f32TrickRotateAcceleRadX;          // 0x6C
    float f32TrickRotateAcceleRadY;          // 0x70
    float f32TrickMaxRotateX;                // 0x74
    float f32TrickMaxRotateY;                // 0x78
    float f32TrickMoveFrame;                 // 0x7C
    float f32TrickLandStiffFrame;            // 0x80
    float f32SlowdownSpeed;                  // 0x84
    float f32SlideGpZeroLimitFrame;          // 0x88
    float f32SlideGpZeroRotateAcceleRadX;    // 0x8C
    float f32TrickGpZeroLimitFrame;          // 0x90
    float f32GCtrlWheelDischargeRate;        // 0x94
};

class clsGravityControl {
public:
    static stcCommonSetting t_sCommonSetting;
};

#endif // GRAVITYCONTROL_HPP
