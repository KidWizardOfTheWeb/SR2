#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "usr/local/sce/ee/gcc/ee/lib/libm/wf_sqrt.h"

hkSimpleShapePhantom::hkSimpleShapePhantom(const hkShape* pParam1,
                                           const hkTransform& rParam2,
                                           u32 u32Param3)
    : hkShapePhantom(pParam1, rParam2)
{
    m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = u32Param3;
}

hkSimpleShapePhantom::~hkSimpleShapePhantom()
{
}

s32 hkSimpleShapePhantom::getType() const
{
    return 1;
}

hkSimpleShapePhantom* hkSimpleShapePhantom::clone() const
{
    const hkCollidable* pCollidable = &m_collidable;
    hkSimpleShapePhantom* pPhantom = new (HK_MEMORY_CLASS_PHANTOM)
        hkSimpleShapePhantom(pCollidable->m_shape,
                             m_motionState.m_transform,
                             pCollidable->m_broadPhaseHandle.m_collisionFilterInfo);
    pPhantom->m_overlapListeners = m_overlapListeners;
    pPhantom->m_phantomListeners = m_phantomListeners;
    pPhantom->m_properties = m_properties;
    return pPhantom;
}

void hkSimpleShapePhantom::setPositionAndLinearCast(const hkVector4& rParam1,
                                                    const hkLinearCastInput& rParam2,
                                                    hkCdPointCollector& rParam3,
                                                    hkCdPointCollector* pParam4)
{
    hkTransform& transform = m_motionState.m_transform;
    transform.m_translation = rParam1;

    hkAabb aabb;
    m_collidable.m_shape->getAabbImpl(transform,
                                      rParam2.m_startPointTolerance +
                                          0.5f * m_world->m_collisionInput->m_tolerance,
                                      aabb);

    hkVector4 path;
    path.setSub4(rParam2.m_to, rParam1);

    f32 minX = (0.0f < path.x) ? 0.0f : path.x;
    f32 minY = (0.0f < path.y) ? 0.0f : path.y;
    f32 minZ = (0.0f < path.z) ? 0.0f : path.z;
    f32 minW = (0.0f < path.w) ? 0.0f : path.w;
    f32 maxX = (0.0f <= path.x) ? path.x : 0.0f;
    f32 maxY = (0.0f <= path.y) ? path.y : 0.0f;
    f32 maxZ = (0.0f <= path.z) ? path.z : 0.0f;
    f32 maxW = (0.0f <= path.w) ? path.w : 0.0f;

    aabb.m_min.x += minX;
    aabb.m_min.y += minY;
    aabb.m_min.z += minZ;
    aabb.m_min.w += minW;
    aabb.m_max.x += maxX;
    aabb.m_max.y += maxY;
    aabb.m_max.z += maxZ;
    aabb.m_max.w += maxW;

    updateBroadPhase(aabb);

    hkLinearCastCollisionInput castInput(*m_world->m_collisionInput);
    castInput.m_path = path;
    castInput.m_cachedPathLength = sqrtf(path.x * path.x + path.y * path.y + path.z * path.z);
    castInput.m_maxExtraPenetration = rParam2.m_maxExtraPenetration;
    castInput.m_tolerance = rParam2.m_startPointTolerance;

    hkCollisionDispatcher* pDispatcher = m_world->m_collisionDispatcher;
    for (s32 s32Index = m_collisionDetails.getSize() - 1; s32Index >= 0; --s32Index) {
        hkCollidable* pCollidable = m_collisionDetails.m_data[s32Index].m_collidable;
        u8 u8AgentType =
            pDispatcher->m_agent2Types[m_collidable.m_shape->m_type][pCollidable->m_shape->m_type];
        pDispatcher->m_agent2Func[u8AgentType].m_linearCastFunc(
            m_collidable, *pCollidable, castInput, rParam3, pParam4);
    }
}

void hkSimpleShapePhantom::getClosestPoints(hkCdPointCollector& rParam1,
                                            const hkCollisionInput* pParam2)
{
    if (pParam2 == NULL) {
        pParam2 = m_world->m_collisionInput;
    }

    hkCollisionDispatcher* pDispatcher = pParam2->m_dispatcher;
    for (s32 s32Index = m_collisionDetails.getSize() - 1; s32Index >= 0; --s32Index) {
        hkCollidable* pCollidable = m_collisionDetails.m_data[s32Index].m_collidable;
        u8 u8AgentType =
            pDispatcher->m_agent2Types[m_collidable.m_shape->m_type][pCollidable->m_shape->m_type];
        pDispatcher->m_agent2Func[u8AgentType].m_getClosestPointFunc(
            m_collidable, *pCollidable, *pParam2, rParam1);
    }
}

void hkSimpleShapePhantom::getPenetrations(hkCdBodyPairCollector& rParam1,
                                           const hkCollisionInput* pParam2)
{
    if (pParam2 == NULL) {
        pParam2 = m_world->m_collisionInput;
    }

    hkCollisionDispatcher* pDispatcher = pParam2->m_dispatcher;
    for (s32 s32Index = m_collisionDetails.getSize() - 1; s32Index >= 0; --s32Index) {
        hkCollidable* pCollidable = m_collisionDetails.m_data[s32Index].m_collidable;
        u8 u8AgentType =
            pDispatcher->m_agent2Types[m_collidable.m_shape->m_type][pCollidable->m_shape->m_type];
        pDispatcher->m_agent2Func[u8AgentType].m_getPenetrationsFunc(
            m_collidable, *pCollidable, *pParam2, rParam1);
        if (rParam1.m_earlyOut) {
            break;
        }
    }
}

hkBool hkSimpleShapePhantom::isOverlappingCollidableAdded(hkCollidable* pParam1)
{
    for (s32 s32Index = 0; s32Index < m_collisionDetails.getSize(); ++s32Index) {
        if (m_collisionDetails.m_data[s32Index].m_collidable == pParam1) {
            return hkBool(1);
        }
    }
    return hkBool(0);
}

void hkSimpleShapePhantom::addOverlappingCollidable(hkCollidable* pParam1)
{
    if (pParam1->m_shape == NULL) {
        return;
    }

    hkCollidableAddedEvent event;
    event.m_collidable = pParam1;
    event.m_object = this;
    event.m_result = 0;

    for (s32 s32Index = m_overlapListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        hkPhantomOverlapListener* pListener = m_overlapListeners.m_data[s32Index];
        if (pListener != NULL) {
            pListener->collidableAddedCallback(event);
        }
    }

    if (event.m_result == 0) {
        m_collisionDetails.expandOne().m_collidable = pParam1;
    }
}

void hkSimpleShapePhantom::removeOverlappingCollidable(hkCollidable* pParam1)
{
    if (pParam1->m_shape == NULL) {
        return;
    }

    for (s32 s32Index = m_collisionDetails.getSize() - 1; s32Index >= 0; --s32Index) {
        if (m_collisionDetails.m_data[s32Index].m_collidable == pParam1) {
            hkCollidableRemovedEvent event(this, pParam1, hkBool(1));
            for (s32 s32Listener = m_overlapListeners.getSize() - 1; s32Listener >= 0;
                 --s32Listener)
            {
                hkPhantomOverlapListener* pListener = m_overlapListeners.m_data[s32Listener];
                if (pListener != NULL) {
                    pListener->collidableRemovedCallback(event);
                }
            }

            m_collisionDetails.removeAt(s32Index);
            return;
        }
    }

    hkCollidableRemovedEvent event(this, pParam1, hkBool(0));
    for (s32 s32Index = m_overlapListeners.getSize() - 1; s32Index >= 0; --s32Index) {
        hkPhantomOverlapListener* pListener = m_overlapListeners.m_data[s32Index];
        if (pListener != NULL) {
            pListener->collidableRemovedCallback(event);
        }
    }
}

void hkSimpleShapePhantom::calcStatistics(hkStatisticsCollector* pParam1) const
{
    pParam1->beginObject("SimplePhantm", 2, this);
    hkPhantom::calcStatistics(pParam1);

    if (!(m_collisionDetails.m_capacityAndFlags & 0x80000000)) {
        pParam1->addArray("OverlapPtr",
                          8,
                          m_collisionDetails.m_data,
                          m_collisionDetails.getSize() * sizeof(hkCollisionDetail),
                          m_collisionDetails.getCapacity() * sizeof(hkCollisionDetail));
    }

    pParam1->endObject();
}

void hkSimpleShapePhantom::deallocateInternalArrays()
{
    if (m_collisionDetails.getSize() == 0) {
        m_collisionDetails.clearAndDeallocate();
    }
    hkShapePhantom::deallocateInternalArrays();
}
