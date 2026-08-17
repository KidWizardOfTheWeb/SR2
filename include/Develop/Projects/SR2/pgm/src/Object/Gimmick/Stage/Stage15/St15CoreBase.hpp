#ifndef ST15COREBASE_HPP
#define ST15COREBASE_HPP

#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

class hkRigidBodyCinfo;

// total size: 0x210
class clsRigidBody : public hkRigidBody {
public:
    static f32 t_of32DefaultLinearDamping;
    static f32 t_of32DefaultAngularDamping;
    static f32 t_of32DefaultMaxLinear;

    clsRigidBody(const hkRigidBodyCinfo& rParam1) : hkRigidBody(rParam1) {}
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

// total size: 0x60
class clsCoreBase_Obj : public clsGimmickObj {
public:
    clsCoreBase_Obj() {}
    virtual ~clsCoreBase_Obj() {}

    virtual nspPackId::enm getPackId() const { return nspPackId::ST15_CORE_BASE_25000; }

    enum enmCoreBaseMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    static f32 m_tof32CLIP_DISTx2;

    enmCoreBaseMode m_eCoreBaseMode; // offset 0x50, size 0x4
    u8 m_bDrawFlag;                  // offset 0x54, size 0x1
};

// total size: 0x98
class clsCoreBase_Task : public clsSingleModelGimmick_Task<clsCoreBase_Task,
                                                           clsCoreBase_Obj,
                                                           clsModelType_OB_TX_MO_MA> {
public:
    clsCoreBase_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task<clsCoreBase_Task, clsCoreBase_Obj, clsModelType_OB_TX_MO_MA>(
              u32ObjectAreaNum, 0x18A88)
    {
    }
    virtual ~clsCoreBase_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset() {}

    void setCoreBase();
    void endCoreBase();
};

#endif // ST15COREBASE_HPP
