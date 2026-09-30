#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

void hkPhantom::firePhantomDeleted()
{
    for (s32 s32Index = m_phantomListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        hkPhantomListener* pListener = m_phantomListeners.m_data[s32Index];
        if (pListener != NULL) {
            pListener->phantomDeletedCallback(this);
        }
    }
}

void hkPhantom::firePhantomRemoved()
{
    for (s32 s32Index = m_phantomListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        hkPhantomListener* pListener = m_phantomListeners.m_data[s32Index];
        if (pListener != NULL) {
            pListener->phantomRemovedCallback(this);
        }
    }

    for (s32 s32Index = m_phantomListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        if (m_phantomListeners.m_data[s32Index] == NULL) {
            m_phantomListeners.removeAtAndCopy(s32Index);
        }
    }
}

void hkPhantom::firePhantomAdded()
{
    for (s32 s32Index = m_phantomListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        hkPhantomListener* pListener = m_phantomListeners.m_data[s32Index];
        if (pListener != NULL) {
            pListener->phantomAddedCallback(this);
        }
    }

    for (s32 s32Index = m_phantomListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        if (m_phantomListeners.m_data[s32Index] == NULL) {
            m_phantomListeners.removeAtAndCopy(s32Index);
        }
    }
}

void hkPhantom::firePhantomShapeSet()
{
    for (s32 s32Index = m_phantomListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        hkPhantomListener* pListener = m_phantomListeners.m_data[s32Index];
        if (pListener != NULL) {
            pListener->phantomShapeSetCallback(this);
        }
    }

    for (s32 s32Index = m_phantomListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        if (m_phantomListeners.m_data[s32Index] == NULL) {
            m_phantomListeners.removeAtAndCopy(s32Index);
        }
    }
}

namespace {
// RECONSTRUCTED: queued operation types.
enum PhantomQueuedOperationType {
    PHANTOM_OPERATION_UPDATE_BROAD_PHASE = 17,
};

class QueuedUpdatePhantomBroadPhaseOperation : public hkWorldOperation::BaseOperation {
public:
    QueuedUpdatePhantomBroadPhaseOperation(hkPhantom* pPhantom, const hkAabb& rAabb)
        : hkWorldOperation::BaseOperation(PHANTOM_OPERATION_UPDATE_BROAD_PHASE),
          m_phantom(pPhantom), m_aabb(&rAabb)
    {
    }

    hkPhantom* m_phantom;
    const hkAabb* m_aabb;
};
} // namespace

void hkPhantom::updateBroadPhase(const hkAabb& rParam1)
{
    if (m_world == NULL) {
        return;
    }

    if (m_world->m_criticalOperationsLockCount +
            m_world->m_criticalOperationsLockCountForPhantoms !=
        0)
    {
        QueuedUpdatePhantomBroadPhaseOperation operation(this, rParam1);
        m_world->queueOperation(operation);
        return;
    }

    m_world->m_criticalOperationsLockCount = m_world->m_criticalOperationsLockCount + 1;

    hkLocalArray<hkBroadPhaseHandlePair> newPairs(m_world->m_broadPhaseUpdateSize);
    hkLocalArray<hkBroadPhaseHandlePair> removedPairs(m_world->m_broadPhaseUpdateSize);

    hkBroadPhaseHandle* pHandle = &m_collidable.m_broadPhaseHandle;
    if (m_world->m_broadPhase->m_criticalSection != NULL) {
        m_world->m_broadPhase->lockImplementation();
    }

    m_world->m_broadPhase->updateAabbs(&pHandle, &rParam1, 1, newPairs, removedPairs);

    if (newPairs.getSize() != 0 || removedPairs.getSize() != 0) {
        hkTypedBroadPhaseDispatcher::removeDuplicates(newPairs, removedPairs);
        m_world->m_broadPhaseDispatcher->removePairs(
            reinterpret_cast<hkTypedBroadPhaseHandlePair*>(removedPairs.m_data),
            removedPairs.getSize());

        const hkCollidableCollidableFilter* pFilter =
            static_cast<const hkCollidableCollidableFilter*>(m_world->m_collisionFilter);
        m_world->m_broadPhaseDispatcher->addPairs(
            reinterpret_cast<hkTypedBroadPhaseHandlePair*>(newPairs.m_data),
            newPairs.getSize(),
            pFilter);

        for (s32 s32Index = m_overlapListeners.getSize() - 1; s32Index >= 0; --s32Index) {
            if (m_overlapListeners.m_data[s32Index] == NULL) {
                m_overlapListeners.removeAtAndCopy(s32Index);
            }
        }
    }

    if (m_world->m_broadPhase->m_criticalSection != NULL) {
        m_world->m_broadPhase->unlockImplementation();
    }

    hkWorld* pWorld = m_world;
    if (--pWorld->m_criticalOperationsLockCount == 0 && pWorld->m_pendingOperationsCount != 0 &&
        !pWorld->m_blockExecutingPendingOperations)
    {
        pWorld->internal_executePendingOperations();
    }
}

void hkPhantom::addPhantomListener(hkPhantomListener* pParam1)
{
    m_phantomListeners.pushBack(pParam1);
}

void hkPhantom::removePhantomListener(hkPhantomListener* pParam1)
{
    const s32 s32Index = m_phantomListeners.indexOf(pParam1);
    m_phantomListeners.removeAtAndCopy(s32Index);
}

void hkPhantom::addPhantomOverlapListener(hkPhantomOverlapListener* pParam1)
{
    m_overlapListeners.pushBack(pParam1);
}

void hkPhantom::removePhantomOverlapListener(hkPhantomOverlapListener* pParam1)
{
    const s32 s32Index = m_overlapListeners.indexOf(pParam1);
    m_overlapListeners.removeAtAndCopy(s32Index);
}

hkPhantom::~hkPhantom()
{
    firePhantomDeleted();
}

void hkPhantom::calcStatistics(hkStatisticsCollector* pParam1) const
{
    hkWorldObject::calcStatistics(pParam1);

    if (!(m_overlapListeners.m_capacityAndFlags & 0x80000000)) {
        pParam1->addArray("OvrlapLisPtr",
                          4,
                          m_overlapListeners.m_data,
                          m_overlapListeners.getSize() * sizeof(hkPhantomOverlapListener*),
                          m_overlapListeners.getCapacity() * sizeof(hkPhantomOverlapListener*));
    }
    if (!(m_phantomListeners.m_capacityAndFlags & 0x80000000)) {
        pParam1->addArray("PhantmLisPtr",
                          4,
                          m_phantomListeners.m_data,
                          m_phantomListeners.getSize() * sizeof(hkPhantomListener*),
                          m_phantomListeners.getCapacity() * sizeof(hkPhantomListener*));
    }
}

void hkPhantom::deallocateInternalArrays()
{
    if (m_overlapListeners.getSize() == 0) {
        m_overlapListeners.clearAndDeallocate();
    }
    if (m_phantomListeners.getSize() == 0) {
        m_phantomListeners.clearAndDeallocate();
    }
}

void hkPhantomBroadPhaseListener::addCollisionPair(hkTypedBroadPhaseHandlePair& rParam1)
{
    if (rParam1.m_a->m_type == hkWorldObject::BROAD_PHASE_PHANTOM) {
        hkCollidable* pPhantomCollidable = rParam1.m_a->getOwner();
        hkPhantom* pPhantom = static_cast<hkPhantom*>(pPhantomCollidable->getOwner());
        pPhantom->addOverlappingCollidable(rParam1.m_b->getOwner());
    }

    if (rParam1.m_b->m_type == hkWorldObject::BROAD_PHASE_PHANTOM) {
        hkCollidable* pPhantomCollidable = rParam1.m_b->getOwner();
        hkPhantom* pPhantom = static_cast<hkPhantom*>(pPhantomCollidable->getOwner());
        pPhantom->addOverlappingCollidable(rParam1.m_a->getOwner());
    }
}

void hkPhantomBroadPhaseListener::removeCollisionPair(hkTypedBroadPhaseHandlePair& rParam1)
{
    if (rParam1.m_a->m_type == hkWorldObject::BROAD_PHASE_PHANTOM) {
        hkCollidable* pPhantomCollidable = rParam1.m_a->getOwner();
        hkPhantom* pPhantom = static_cast<hkPhantom*>(pPhantomCollidable->getOwner());
        pPhantom->removeOverlappingCollidable(rParam1.m_b->getOwner());
    }

    if (rParam1.m_b->m_type == hkWorldObject::BROAD_PHASE_PHANTOM) {
        hkCollidable* pPhantomCollidable = rParam1.m_b->getOwner();
        hkPhantom* pPhantom = static_cast<hkPhantom*>(pPhantomCollidable->getOwner());
        pPhantom->removeOverlappingCollidable(rParam1.m_a->getOwner());
    }
}

hkShapePhantom::~hkShapePhantom()
{
}
