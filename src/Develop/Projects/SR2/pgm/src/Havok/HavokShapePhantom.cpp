#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

namespace {
// RECONSTRUCTED: queued operation types.
enum PhantomQueuedOperationType {
    PHANTOM_OPERATION_SET_SHAPE = 5,
};

class QueuedSetPhantomShapeOperation : public hkWorldOperation::BaseOperation {
public:
    QueuedSetPhantomShapeOperation(hkPhantom* pPhantom, const hkShape* pShape)
        : hkWorldOperation::BaseOperation(PHANTOM_OPERATION_SET_SHAPE), m_phantom(pPhantom),
          m_shape(pShape)
    {
    }

    hkPhantom* m_phantom;
    const hkShape* m_shape;
};
} // namespace

hkShapePhantom::hkShapePhantom(const hkShape* pParam1, const hkTransform& rParam2)
    : hkPhantom(pParam1)
{
    m_collidable.m_motion = &m_motionState;
    m_motionState.m_transform = rParam2;
}

hkMotionState* hkShapePhantom::getMotionState()
{
    return &m_motionState;
}

void hkShapePhantom::setTransform(const hkTransform& rParam1)
{
    m_motionState.m_transform = rParam1;

    if (m_world != NULL) {
        hkAabb aabb;
        m_collidable.m_shape->getAabbImpl(
            rParam1, 0.5f * m_world->m_collisionInput->m_tolerance, aabb);
        updateBroadPhase(aabb);
    }
}

void hkShapePhantom::setPosition(const hkVector4& rParam1, f32 f32Param2)
{
    m_motionState.m_transform.m_translation = rParam1;

    if (m_world != NULL) {
        hkAabb aabb;
        m_collidable.m_shape->getAabbImpl(m_motionState.m_transform,
                                          f32Param2 + 0.5f * m_world->m_collisionInput->m_tolerance,
                                          aabb);
        updateBroadPhase(aabb);
    }
}

void hkShapePhantom::calcAabb(hkAabb& rParam1)
{
    m_collidable.m_shape->getAabbImpl(
        m_motionState.m_transform, 0.5f * m_world->m_collisionInput->m_tolerance, rParam1);
}

void hkShapePhantom::deallocateInternalArrays()
{
    hkPhantom::deallocateInternalArrays();
}

bool hkShapePhantom::setShape(const hkShape* pParam1)
{
    if (m_world != NULL && m_world->m_criticalOperationsLockCount != 0) {
        QueuedSetPhantomShapeOperation operation(this, pParam1);
        m_world->queueOperation(operation);
        return false;
    }

    if (m_world != NULL) {
        ++m_world->m_criticalOperationsLockCount;
        hkWorldOperationUtil::removePhantomBP(m_world, this);
    }

    pParam1->addReference();
    const hkShape* pOldShape = m_collidable.m_shape;
    if (pOldShape != NULL) {
        pOldShape->removeReference();
    }
    m_collidable.m_shape = pParam1;

    if (m_world != NULL) {
        hkWorldCallbackUtil::firePhantomShapeSet(m_world, this);
    }
    firePhantomShapeSet();

    if (m_world != NULL) {
        hkWorldOperationUtil::addPhantomBP(m_world, this);
        hkWorld* pWorld = m_world;
        if (--pWorld->m_criticalOperationsLockCount == 0 && pWorld->m_pendingOperationsCount != 0 &&
            !pWorld->m_blockExecutingPendingOperations)
        {
            pWorld->internal_executePendingOperations();
        }
    }

    return true;
}

const hkTransform* hkShapePhantom::getTransform() const
{
    return &m_motionState.m_transform;
}
