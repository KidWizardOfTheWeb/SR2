#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

class hkRigidBodyCinfo;

// total size: 0x210
class clsRigidBody : public hkRigidBody {
public:
    static f32 t_of32DefaultLinearDamping;
    static f32 t_of32DefaultAngularDamping;
    static f32 t_of32DefaultMaxLinear;

    clsRigidBody(const hkRigidBodyCinfo& rParam1) : hkRigidBody(rParam1), m_pvCollisionInfo(0) {}
    virtual ~clsRigidBody() {}

    void* m_pvCollisionInfo; // offset 0x200, size 0x4

    void* getCollisionInfo() { return m_pvCollisionInfo; }
    void setRotateQuat(const NNS_QUATERNION* psParam1) {}
    void setCollisionInfo(void* pvParam1) { m_pvCollisionInfo = pvParam1; }
    void setCollisionFilterLight(u32 u32Param1, u32 u32Param2)
    {
        u32 u32FilterInfo = m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
        u32 u32InverseMask = ~u32Param2;
        u32 u32NewBits = u32Param1 & u32Param2;
        u32FilterInfo = static_cast<u32>(u32InverseMask & u32FilterInfo);
        m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = u32NewBits | u32FilterInfo;
        clsHavok::GS()->m_pcWorld->updateCollisionFilterOnEntity(
            this,
            HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
            HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS);
    }
    void setPositionRotate(const NNS_VECTORFAST* psParam1, const NNS_QUATERNION* psParam2) {}
    void setCollisionFilter(u32 u32Param1, u32 u32Param2)
    {
        u32 u32FilterInfo = m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
        u32 u32InverseMask = ~u32Param2;
        u32 u32NewBits = u32Param1 & u32Param2;
        u32FilterInfo = static_cast<u32>(u32InverseMask & u32FilterInfo);
        m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = u32NewBits | u32FilterInfo;
        clsHavok::GS()->m_pcWorld->updateCollisionFilterOnEntity(
            this,
            HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
            HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS);
    }
    void getRotateQuat(NNS_QUATERNION* psParam1) {}
    void getRotateMatrix(NNS_MATRIX* psParam1) {}
    void getPositionVecFast(NNS_VECTORFAST* psParam1) {}
    void setPositionVecFast(const NNS_VECTORFAST* psParam1) {}
    void applyForceFrameSpeedVecFast(const NNS_VECTORFAST* psParam1) {}
    void getPositionRotate(NNS_VECTORFAST* psParam1, NNS_QUATERNION* psParam2) {}
};

extern hkTypeInfo clsRigidBodyTypeInfo;

#endif // RIGIDBODY_HPP
