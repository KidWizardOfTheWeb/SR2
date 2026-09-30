#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokMath.hpp"

enum enmRet {
    VISIBLE_CLIP = 0,
    VISIBLE = 1,
    OUT_VISIBLE = 2,
    OUT_PORTAL = 3,
    OUT_FAR = 4,
};

class hkContactPoint;
class hkContactPointConfirmedEvent;
class hkContactProcessEvent;
class hkContactPointRemovedEvent;
class hkMatrix3;
class hkRotation;
class hkTransform;

// Havok math types
struct hkQuadReal {
    f32 x, y, z, w;
} __attribute__((aligned(16)));

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
    const f32& operator()(s32 s32Param1) const { return (&x)[s32Param1]; }

    hkQuadReal& getQuad() { return *reinterpret_cast<hkQuadReal*>(this); }
    const hkQuadReal& getQuad() const { return *reinterpret_cast<const hkQuadReal*>(this); }
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
    // RECONSTRUCTED: accessor names.
    void setAbs4(const hkVector4& value)
    {
        x = hkMath::fabs(value.x);
        y = hkMath::fabs(value.y);
        z = hkMath::fabs(value.z);
        w = hkMath::fabs(value.w);
    }
    s32 compareEqual4(const hkVector4& value) const
    {
        return ((x == value.x) ? 8 : 0) | ((y == value.y) ? 4 : 0) | ((z == value.z) ? 2 : 0) |
               ((w == value.w) ? 1 : 0);
    }
    s32 compareLessThan4(const hkVector4& value) const
    {
        return ((x < value.x) ? 8 : 0) | ((y < value.y) ? 4 : 0) | ((z < value.z) ? 2 : 0) |
               ((w < value.w) ? 1 : 0);
    }
    void setSub4(const hkVector4& rParam1, const hkVector4& rParam2)
    {
        x = rParam1.x - rParam2.x;
        y = rParam1.y - rParam2.y;
        z = rParam1.z - rParam2.z;
        w = rParam1.w - rParam2.w;
    }
    void setAdd4(const hkVector4& rParam1, const hkVector4& rParam2)
    {
        x = rParam1.x + rParam2.x;
        y = rParam1.y + rParam2.y;
        z = rParam1.z + rParam2.z;
        w = rParam1.w + rParam2.w;
    }
    void sub4(const hkVector4& rParam1)
    {
        x -= rParam1.x;
        y -= rParam1.y;
        z -= rParam1.z;
        w -= rParam1.w;
    }
    void add4(const hkVector4& rParam1)
    {
        x += rParam1.x;
        y += rParam1.y;
        z += rParam1.z;
        w += rParam1.w;
    }
    void mul4(f32 f32Scale)
    {
        x *= f32Scale;
        y *= f32Scale;
        z *= f32Scale;
        w *= f32Scale;
    }
    void mul4(const hkVector4& value)
    {
        x *= value.x;
        y *= value.y;
        z *= value.z;
        w *= value.w;
    }
    void setNeg4(const hkVector4& rParam1)
    {
        x = -rParam1.x;
        y = -rParam1.y;
        z = -rParam1.z;
        w = -rParam1.w;
    }
    f32 dot4(const hkVector4& rParam1) const
    {
        return x * rParam1.x + y * rParam1.y + z * rParam1.z + w * rParam1.w;
    }
    f32 dot4xyz1(const hkVector4& rParam1) const
    {
        return x * rParam1.x + y * rParam1.y + z * rParam1.z + w;
    }
    void addMul4(f32 f32Param1, const hkVector4& rParam2)
    {
        x += f32Param1 * rParam2.x;
        y += f32Param1 * rParam2.y;
        z += f32Param1 * rParam2.z;
        w += f32Param1 * rParam2.w;
    }
    void subMul4(f32 f32Param1, const hkVector4& rParam2)
    {
        x -= f32Param1 * rParam2.x;
        y -= f32Param1 * rParam2.y;
        z -= f32Param1 * rParam2.z;
        w -= f32Param1 * rParam2.w;
    }
    void setCross(const hkVector4& rParam1, const hkVector4& rParam2)
    {
        f32 f32X = rParam1.y * rParam2.z - rParam1.z * rParam2.y;
        f32 f32Y = rParam1.z * rParam2.x - rParam1.x * rParam2.z;
        f32 f32Z = rParam1.x * rParam2.y - rParam1.y * rParam2.x;
        x = f32X;
        y = f32Y;
        z = f32Z;
        w = 0.0f;
    }
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
