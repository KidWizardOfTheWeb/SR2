#ifndef HKBASEOBJECT_HPP
#define HKBASEOBJECT_HPP

#include "types.h"
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
    virtual ~hkStatisticsCollector() {}
    virtual void beginObject(const c8* pcName, s32 s32Class, const void* pvObject) = 0;
    virtual void addArray(const c8* pcName,
                          s32 s32Class,
                          const void* pvData,
                          s32 s32UsedBytes,
                          s32 s32AllocatedBytes) = 0;
    virtual void addChildObject(const c8* pcName, s32 s32Class, const void* pvObject) = 0;
    virtual void pushDir(const c8* pcName) = 0;
    virtual void popDir() = 0;
    virtual void endObject() = 0;
};
class hkCollidable;
class hkCollisionDispatcher;
class hkShape;
class hkTransform;

// total size: 0x4
class hkFinishLoadedObjectFlag {
public:
    s32 m_finishing; // offset 0x0, size 0x4
};

// total size: 0x4
class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};

// total size: 0x8
class hkReferencedObject : public hkBaseObject {
public:
    hkReferencedObject() : m_referenceCount(1) {}
    virtual ~hkReferencedObject() {}
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const {}

    static void operator delete(void* pvMemory);

    void addReference() const
    {
        if (m_memSizeAndFlags != 0) {
            ++m_referenceCount;
        }
    }

    void removeReference() const
    {
        if (m_memSizeAndFlags != 0) {
            --m_referenceCount;
            if (m_referenceCount == 0) {
                delete this;
            }
        }
    }

    u16 m_memSizeAndFlags;        // offset 0x4, size 0x2
    mutable s16 m_referenceCount; // offset 0x6, size 0x2
};

// total size: 0x10
class hkStepInfo {
public:
    hkPadSpu<f32> m_startTime;    // offset 0x0, size 0x4
    hkPadSpu<f32> m_endTime;      // offset 0x4, size 0x4
    hkPadSpu<f32> m_deltaTime;    // offset 0x8, size 0x4
    hkPadSpu<f32> m_invDeltaTime; // offset 0xC, size 0x4
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

#endif // HKBASEOBJECT_HPP
