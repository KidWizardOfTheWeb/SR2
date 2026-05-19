#ifndef DEBUGDETAIL_HPP
#define DEBUGDETAIL_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OORandom.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "types.h"

class clsSetCamEditor;

// total size: 0x14
struct stcDebugParticleMenu {
    u8 u8Mode;                // offset 0x0, size 0x1
    s32 s32Color;             // offset 0x4, size 0x4
    s32 s32LoadSingleNum;     // offset 0x8, size 0x4
    s32 s32LoadParticleNum;   // offset 0xC, size 0x4
    u8 u8TempPotalSwitch;     // offset 0x10, size 0x1
    u8 u8TempPotalGetPos;     // offset 0x11, size 0x1
    u16 u16TempPotalStopCode; // offset 0x12, size 0x2
};

// total size: 0x10
class clsOOFog {
public:
    virtual void setColor(u32 u32r, u32 u32g, u32 u32b)
    {
        m_u8r = static_cast<u8>(u32r);
        m_u8g = static_cast<u8>(u32g);
        m_u8b = static_cast<u8>(u32b);
    }
    virtual void setColor(u32 u32Color)
    {
        m_u8r = static_cast<u8>(u32Color >> 16);
        m_u8g = static_cast<u8>(u32Color >> 8);
        m_u8b = static_cast<u8>(u32Color);
    }
    virtual void setRange(f32 f32Near, f32 f32Far)
    {
        m_f32Near = f32Near;
        m_f32Far = f32Far;
    }
    virtual u32 getColor() const { return (m_u8r << 16) | (m_u8g << 8) | m_u8b; }
    virtual f32 getRangeNear() const { return m_f32Near; }
    virtual f32 getRangeFar() const { return m_f32Far; }

    u8 getStop() const { return m_bNonStop == 0; }

    f32 m_f32Near; // offset 0x4, size 0x4
    f32 m_f32Far;  // offset 0x8, size 0x4
    u8 m_u8r;      // offset 0xC, size 0x1
    u8 m_u8g;      // offset 0xD, size 0x1
    u8 m_u8b;      // offset 0xE, size 0x1
    u8 m_bNonStop; // offset 0xF, size 0x1
};

// total size: 0x20
class clsPfFog : public clsSingleton<clsPfFog>, public clsOOFog {
public:
    clsPfFog() {}
    virtual ~clsPfFog() {}

    void setColorf_OneTime(f32 f32r, f32 f32g, f32 f32b) const {}
    void setRange_OneTime(f32 f32Near, f32 f32Far) const {}
    void setColorf(f32 f32r, f32 f32g, f32 f32b)
    {
        m_f32r = f32r;
        m_f32g = f32g;
        m_f32b = f32b;
    }
    virtual void setRange(f32 f32Near, f32 f32Far) { clsOOFog::setRange(f32Near, f32Far); }
    virtual void enable() const {}
    virtual void disable() const {}

    f32 m_f32r; // offset 0x14, size 0x4
    f32 m_f32g; // offset 0x18, size 0x4
    f32 m_f32b; // offset 0x1C, size 0x4
};

namespace nspDebugDetail {

extern clsSetCamEditor cSetEdit;

void OutSideChecker(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void GDiveTrain(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void PathRangeEditor(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void ObjPortal(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void MapPortal(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void DataSize(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void Light(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void BgColor(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void Fog(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void Race(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void BlackHoleDebug(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void BossAttackDebug(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void BossDebug(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void BossDisp(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void BurnOut(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void BurnOutSystem(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void Blur(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void Sr2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);

} // namespace nspDebugDetail

#endif // DEBUGDETAIL_HPP
