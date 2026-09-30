#ifndef HAVOK_HPP
#define HAVOK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/hkBaseObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

// total size: 0x20
class clsStepInfo : public hkStepInfo {
public:
    void set(f32 f32StartTime, f32 f32DeltaTime) {}

    hkPadSpu<f32> m_invDeltaTimeCaret2; // offset 0x10, size 0x4
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
    void* getCollidableUserData(const hkCollidable* pcCollidable)
    {
        const hkWorldObject* pcOwner = pcCollidable->getOwner();
        return pcOwner != NULL ? pcOwner->getUserData() : NULL;
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
