#ifndef PENDULUMCONTROL_HPP
#define PENDULUMCONTROL_HPP

#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "types.h"

class clsPendulum;

// total size: 0x98
struct stcControlParam {
    f32 f32Force;                // offset 0x0, size 0x4
    u32 u32MaxCounterLevel;      // offset 0x4, size 0x4
    f32 af32CounterAngle[4];     // offset 0x8, size 0x10
    f32 af32MaxAngleVelocity[4]; // offset 0x18, size 0x10
    f32 af32MaxAngle[4][7];      // offset 0x28, size 0x70
};

// total size: 0x20
class clsPendulumControl {
public:
    clsPendulumControl(u8 param_1, const stcControlParam& rsControlParam);
    ~clsPendulumControl() {}

    void update(s8 s8KeyLevelX);
    clsPendulum* getPendulum();
    void draw();

    clsPendulum* m_pcPendulum;         // offset 0x0, size 0x4
    f32 m_f32CounterAngle;             // offset 0x4, size 0x4
    stcControlParam* m_psControlParam; // offset 0x8, size 0x4
    NNS_QUATERNION m_sRotQuat;         // offset 0xC, size 0x10
    u8 m_u8CounterLevel;               // offset 0x1C, size 0x1
};

// total size: 0x28
struct stcPendulum {
    f32 f32MaxAngle;         // offset 0x0, size 0x4
    f32 f32AngularDamping;   // offset 0x4, size 0x4
    f32 f32Mass;             // offset 0x8, size 0x4
    f32 f32CenterMass;       // offset 0xC, size 0x4
    f32 f32Force;            // offset 0x10, size 0x4
    f32 f32CounterAngle;     // offset 0x14, size 0x4
    f32 f32MaxAngleVelocity; // offset 0x18, size 0x4
    f32 f32Angle;            // offset 0x1C, size 0x4
    f32 f32AngleSpeed;       // offset 0x20, size 0x4
    u8 u8CounterLevel;       // offset 0x24, size 0x1
    u8 u8LineNum;            // offset 0x25, size 0x1
    u8 u8EnablePendulum;     // offset 0x26, size 0x1
    u8 u8EnableParam;        // offset 0x27, size 0x1
};

#endif // PENDULUMCONTROL_HPP
