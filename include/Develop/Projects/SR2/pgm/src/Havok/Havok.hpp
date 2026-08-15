#ifndef HAVOK_HPP
#define HAVOK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"

// total size: sizeof(T)
template <class T>
class hkPadSpu {
public:
    T m_storage; // offset 0x0, size sizeof(T)

    T val() const { return m_storage; }
    void operator=(T value) { m_storage = value; }
    operator T() const { return m_storage; }
};

// total size: 0x0
class hkCollisionListener {
public:
};

class hkStatisticsCollector {
public:
};
class hkCollidable;
class hkCollisionDispatcher;
class hkShape;
class hkTransform;

// total size: 0x4
class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};

// total size: 0x8
class hkReferencedObject : public hkBaseObject {
public:
    virtual ~hkReferencedObject() {}
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const {}

    void removeReference() const {}

    u16 m_memSizeAndFlags; // offset 0x4, size 0x2
    s16 m_referenceCount;  // offset 0x6, size 0x2
};

// total size: 0x10
class hkStepInfo {
public:
    hkPadSpu<f32> m_startTime;    // offset 0x0, size 0x4
    hkPadSpu<f32> m_endTime;      // offset 0x4, size 0x4
    hkPadSpu<f32> m_deltaTime;    // offset 0x8, size 0x4
    hkPadSpu<f32> m_invDeltaTime; // offset 0xC, size 0x4
};

// total size: 0x20
class clsStepInfo : public hkStepInfo {
public:
    void set(f32 f32StartTime, f32 f32DeltaTime) {}

    hkPadSpu<f32> m_invDeltaTimeCaret2; // offset 0x10, size 0x4
};

class hkWorld;
class hkClass;

// total size: 0x10
class hkTypeInfo {
public:
    c8* m_typeName;                               // offset 0x0, size 0x4
    void (*m_finishLoadedObjectFunction)(void*);  // offset 0x4, size 0x4
    void (*m_cleanupLoadedObjectFunction)(void*); // offset 0x8, size 0x4
    void* m_vtable;                               // offset 0xC, size 0x4
};

extern hkClass* StaticLinkedClasses[276];
extern hkTypeInfo* StaticLinkedTypeInfos[244];
extern void* (*hkSystemMalloc)(s32, s32);
extern void (*hkSystemFree)(void*);

// total size: 0x30
class FourVectors {
public:
    hkVector4 m_x; // offset 0x0, size 0x10
    hkVector4 m_y; // offset 0x10, size 0x10
    hkVector4 m_z; // offset 0x20, size 0x10
};

// total size: 0x8
class Item {
public:
    s32 m_value; // offset 0x0, size 0x4
    c8* m_name;  // offset 0x4, size 0x4
};

// total size: 0x40
class clsHavok : public clsSingleton<clsHavok> {
public:
    virtual ~clsHavok() {} // vtable at 0x0

    void drawShape(u32 u32ViewNo,
                   const hkShape* pcShape,
                   const hkTransform& rcTransform,
                   u8 u8Alpha);
    void exit();
    void init();
    static clsHavok& createInstance(u32 u32Param1);
    void destroyWorld();
    void createWorld();
    void registerAgents(hkCollisionDispatcher* dis);

    hkWorld* getWorldRef() { return m_pcWorld; }
    clsStepInfo* getStepInfoRef() { return &m_cStepInfo; }
    void* getCollidableUserData(const hkCollidable* pcParam1)
    {
        const u8* pcCollidable = reinterpret_cast<const u8*>(pcParam1);
        const u8* pcCdBody = pcCollidable + *reinterpret_cast<const s8*>(pcCollidable + 0x10);
        return pcCdBody ? *reinterpret_cast<void* const*>(pcCdBody + 0xC) : 0;
    }

    static f32 t_of32WeightTypeGround;
    static f32 t_of32WeightTypeLight;
    static f32 t_of32WeightTypeSuperLight;
    static f32 t_of32WeightTypeMiddle;
    static f32 t_of32WeightTypeSuperMiddle;
    static f32 t_of32WeightTypeHeavy;
    static f32 t_of32WeightTypeSuperHeavy;

    hkWorld* m_pcWorld;                     // offset 0x4, size 0x4
    s8* m_pu8StackBuff;                     // offset 0x8, size 0x4
    hkCollisionListener* m_pcRigidListener; // offset 0xC, size 0x4
    clsStepInfo m_cStepInfo;                // offset 0x10, size 0x20
    s32 m_s32ProcNum;                       // offset 0x30, size 0x4
};

#endif // HAVOK_HPP
