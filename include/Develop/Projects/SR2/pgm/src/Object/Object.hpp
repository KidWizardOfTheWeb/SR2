#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "types.h"

// Havok physics forward declarations (hk prefix excluded from scaffold)
class hkContactPoint;
class hkContactPointConfirmedEvent;
class hkContactProcessEvent;
class hkContactPointRemovedEvent;
class hkMatrix3;
class hkRotation;
class hkTransform;

// Havok math types
struct hkVector4 {
    hkVector4() {}
    hkVector4(f32 f32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4)
    {
        set(f32Param1, f32Param2, f32Param3, f32Param4);
    }
    hkVector4(const hkVector4& rParam1) { *this = rParam1; }

    hkVector4& operator=(const hkVector4& rParam1)
    {
        x = rParam1.x;
        y = rParam1.y;
        z = rParam1.z;
        w = rParam1.w;
        return *this;
    }
    f32& operator()(s32 s32Param1) { return (&x)[s32Param1]; }
    f32 operator()(s32 s32Param1) const { return (&x)[s32Param1]; }

    const hkVector4& getQuad() const { return *this; }
    f32 getSimdAt(s32 s32Param1) const { return (&x)[s32Param1]; }
    void set(f32 f32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4)
    {
        x = f32Param1;
        y = f32Param2;
        z = f32Param3;
        w = f32Param4;
    }
    void setZero4() { set(0.0f, 0.0f, 0.0f, 0.0f); }
    void zeroElement(s32 s32Param1) { (&x)[s32Param1] = 0.0f; }
    void add4(const hkVector4& rParam1);
    void mul4(f32 f32Param1);
    void setNeg4(const hkVector4& rParam1);
    f32 dot4(const hkVector4& rParam1) const;
    f32 dot4xyz1(const hkVector4& rParam1) const;
    void addMul4(f32 f32Param1, const hkVector4& rParam2);
    void subMul4(f32 f32Param1, const hkVector4& rParam2);
    void setCross(const hkVector4& rParam1, const hkVector4& rParam2);
    void setTransformedPos(const hkTransform& rParam1, const hkVector4& rParam2);
    void setTransformedInversePos(const hkTransform& rParam1, const hkVector4& rParam2);
    void setRotatedDir(const hkRotation& rParam1, const hkVector4& rParam2);
    void setRotatedInverseDir(const hkRotation& rParam1, const hkVector4& rParam2);
    void setMul3(const hkMatrix3& rParam1, const hkVector4& rParam2);

    f32 x; // offset 0x0, size 0x4
    f32 y; // offset 0x4, size 0x4
    f32 z; // offset 0x8, size 0x4
    f32 w; // offset 0xC, size 0x4
} __attribute__((aligned(16)));

// total size: 0x10
struct stcInfo {
    u8 u8Effect;     // offset 0x0, size 0x1
    u8 u8Attr;       // offset 0x1, size 0x1
    u8 u8Filter;     // offset 0x2, size 0x1
    s8 s8Grip;       // offset 0x3, size 0x1
    u8 u8Union[4];   // offset 0x4, size 0x4
    f32 f32Param;    // offset 0x8, size 0x4
    u32 u32Reserved; // offset 0xC, size 0x4
};

// total size: 0x4
class clsObject {
public:
    enum enmType {
        TYPE_OBJECT = 0,
        TYPE_PLAYER = 1,
        TYPE_GROUND = 2,
        TYPE_THROUGH = 3,
        TYPE_GIMMICK = 4,
        TYPE_GIMMICK_RIGID = 5,
        TYPE_GIMMICK_GLINK = 6,
    };

    virtual ~clsObject() {}
    virtual enmType getObjectType() const { return TYPE_OBJECT; }
    virtual void contactTriggerEvent(hkContactPoint* param_1, clsObject* param_2) {}
    virtual void contactAlwaysEvent(hkContactPoint* param_1, clsObject* param_2) {}
    virtual void contactRemoveEvent(hkContactPoint* param_1, clsObject* param_2) {}
    virtual void contactTriggerCallback(hkContactPointConfirmedEvent& param_1) {}
    virtual void contactAlwaysCallback(hkContactProcessEvent& param_1) {}
    virtual void contactRemoveCallback(hkContactPointRemovedEvent& param_1) {}

    clsObject() {}
};

#endif // OBJECT_HPP
