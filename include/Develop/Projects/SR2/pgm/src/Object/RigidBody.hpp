#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"

class hkRigidBodyCinfo;

// total size: 0x210
class clsRigidBody : public hkRigidBody {
public:
    static f32 t_of32DefaultLinearDamping;
    static f32 t_of32DefaultAngularDamping;
    static f32 t_of32DefaultMaxLinear;

    clsRigidBody(const hkRigidBodyCinfo& rParam1) : hkRigidBody(rParam1), m_pvCollisionInfo(NULL) {}
    virtual ~clsRigidBody()
    {
        if (m_world != NULL) {
            clsHavok::GS()->m_pcWorld->removeEntity(this);
        }
    }

    void* m_pvCollisionInfo; // offset 0x200, size 0x4

    void* getCollisionInfo() { return m_pvCollisionInfo; }
    void setRotateQuat(const NNS_QUATERNION* psParam1) {}
    void setCollisionInfo(void* pvParam1) { m_pvCollisionInfo = pvParam1; }
    void setCollisionFilterLight(u32 u32Param1, u32 u32Param2)
    {
        u32 u32FilterInfo = m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
        u32 u32InverseMask = ~u32Param2;
        u32 u32NewBits = u32Param1 & u32Param2;
        u32FilterInfo = u32InverseMask & u32FilterInfo;
        m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = u32NewBits | u32FilterInfo;
        clsHavok::GS()->m_pcWorld->updateCollisionFilterOnEntity(
            this,
            HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
            HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS);
    }
    void setPositionRotate(const NNS_VECTORFAST* psParam1, const NNS_QUATERNION* psParam2)
    {
        hkVector4 cPosition(psParam1->x, psParam1->y, psParam1->z, 0.0f);
        hkQuaternion cRotation(psParam2->x, psParam2->y, psParam2->z, psParam2->w);
        setPositionAndRotation(cPosition, cRotation);
    }
    void setCollisionFilter(u32 u32Param1, u32 u32Param2)
    {
        u32 u32FilterInfo = m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
        u32 u32InverseMask = ~u32Param2;
        u32 u32NewBits = u32Param1 & u32Param2;
        u32FilterInfo = u32InverseMask & u32FilterInfo;
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
    void applyForceFrameSpeedVecFast(const NNS_VECTORFAST* psParam1)
    {
        clsHavok* pcHavok = clsHavok::GS();
        hkVector4 cForce(psParam1->x, psParam1->y, psParam1->z, 0.0f);
        f32 f32ForceScale = m_motion.getMass() * pcHavok->m_cStepInfo.m_invDeltaTimeCaret2;
        cForce.mul4(clsPfSystem::GS()->getFrameRateAdd() * f32ForceScale);
        const f32 f32DeltaTime = pcHavok->m_cStepInfo.m_deltaTime;
        activate();
        m_motion.applyForce(f32DeltaTime, cForce);
    }
    void getPositionRotate(NNS_VECTORFAST* psPosition, NNS_QUATERNION* psRotation)
    {
        const hkVector4& rcPosition = m_motion.m_motionState.m_transform.m_translation;
        nnSetUpVectorFast(psPosition, rcPosition.x, rcPosition.y, rcPosition.z);
        const hkVector4& rcRotation = m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec;
        psRotation->x = rcRotation.x;
        psRotation->y = rcRotation.y;
        psRotation->z = rcRotation.z;
        psRotation->w = rcRotation.w;
    }
};

extern hkTypeInfo clsRigidBodyTypeInfo;

#endif // RIGIDBODY_HPP
