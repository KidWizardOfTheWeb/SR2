#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkAabbPhantom::hkAabbPhantom(const hkAabb& rParam1, u32 u32Param2)
{
    m_aabb = rParam1;
    m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = u32Param2;
}

hkAabbPhantom::~hkAabbPhantom()
{
}

s32 hkAabbPhantom::getType() const
{
    return 0;
}

hkAabbPhantom* hkAabbPhantom::clone() const
{
    const hkCollidable* pCollidable = &m_collidable;
    hkAabbPhantom* pPhantom = new (HK_MEMORY_CLASS_PHANTOM)
        hkAabbPhantom(m_aabb, pCollidable->m_broadPhaseHandle.m_collisionFilterInfo);
    pPhantom->m_overlapListeners = m_overlapListeners;
    pPhantom->m_phantomListeners = m_phantomListeners;
    pPhantom->m_properties = m_properties;
    return pPhantom;
}

void hkAabbPhantom::calcAabb(hkAabb& rParam1)
{
    rParam1 = m_aabb;
}

void hkAabbPhantom::setAabb(const hkAabb& rParam1)
{
    m_aabb = rParam1;
    updateBroadPhase(m_aabb);
}

hkBool hkAabbPhantom::isOverlappingCollidableAdded(hkCollidable* pParam1)
{
    for (s32 s32Index = 0; s32Index < m_overlappingCollidables.getSize(); ++s32Index) {
        if (m_overlappingCollidables.m_data[s32Index] == pParam1) {
            return hkBool(1);
        }
    }
    return hkBool(0);
}

void hkAabbPhantom::addOverlappingCollidable(hkCollidable* pParam1)
{
    hkCollidableAddedEvent event;
    event.m_object = this;
    event.m_collidable = pParam1;
    event.m_result = 0;

    for (s32 s32Index = m_overlapListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        hkPhantomOverlapListener* pListener = m_overlapListeners.m_data[s32Index];
        if (pListener != NULL) {
            pListener->collidableAddedCallback(event);
        }
    }

    if (event.m_result == 0) {
        m_overlappingCollidables.pushBack(pParam1);
    }
}

void hkAabbPhantom::removeOverlappingCollidable(hkCollidable* pParam1)
{
    s32 s32FoundIndex = m_overlappingCollidables.indexOf(pParam1);

    hkCollidableRemovedEvent event(this, pParam1, hkBool(!(s32FoundIndex < 0)));

    for (s32 s32Index = m_overlapListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        hkPhantomOverlapListener* pListener = m_overlapListeners.m_data[s32Index];
        if (pListener != NULL) {
            pListener->collidableRemovedCallback(event);
        }
    }

    if (s32FoundIndex >= 0) {
        m_overlappingCollidables.removeAt(s32FoundIndex);
    }
}

void hkAabbPhantom::calcStatistics(hkStatisticsCollector* pParam1) const
{
    pParam1->beginObject("AabbPhantom", 2, this);
    hkPhantom::calcStatistics(pParam1);

    if (!(m_overlappingCollidables.m_capacityAndFlags & 0x80000000)) {
        pParam1->addArray("OvrlpCollPtr",
                          8,
                          m_overlappingCollidables.m_data,
                          m_overlappingCollidables.getSize() * sizeof(hkCollidable*),
                          m_overlappingCollidables.getCapacity() * sizeof(hkCollidable*));
    }

    pParam1->endObject();
}

void hkAabbPhantom::deallocateInternalArrays()
{
    if (m_overlappingCollidables.getSize() == 0) {
        m_overlappingCollidables.clearAndDeallocate();
    }
    hkPhantom::deallocateInternalArrays();
}
