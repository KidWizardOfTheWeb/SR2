#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkBroadPhaseBorder::hkBroadPhaseBorder(hkWorld* pParam1,
                                       hkWorldCinfo::BroadPhaseBorderBehaviour sParam2)
    : m_world(pParam1), m_behaviour(sParam2)
{
    addReference();
    m_world->addWorldDeletionListener(this);

    const f32 f32MinX = m_world->m_broadPhaseExtents[0].x;
    const f32 f32MinY = m_world->m_broadPhaseExtents[0].y;
    const f32 f32MinZ = m_world->m_broadPhaseExtents[0].z;
    const f32 f32MaxX = m_world->m_broadPhaseExtents[1].x;
    const f32 f32MaxY = m_world->m_broadPhaseExtents[1].y;
    const f32 f32MaxZ = m_world->m_broadPhaseExtents[1].z;
    hkAabb aabb;

    aabb.m_min.set(f32MaxX, f32MinY, f32MinZ, 0.0f);
    aabb.m_max.set(f32MaxX, f32MaxY, f32MaxZ, 0.0f);
    hkAabbPhantom* pPhantom = new (HK_MEMORY_CLASS_PHANTOM) hkAabbPhantom(aabb, 0);
    pPhantom->m_collidable.m_broadPhaseHandle.m_type = hkWorldObject::BROAD_PHASE_BORDER;
    pPhantom->addPhantomOverlapListener(this);
    m_phantoms[0] = pPhantom;
    m_world->addPhantom(pPhantom);

    aabb.m_min.set(f32MinX, f32MinY, f32MinZ, 0.0f);
    aabb.m_max.set(f32MinX, f32MaxY, f32MaxZ, 0.0f);
    pPhantom = new (HK_MEMORY_CLASS_PHANTOM) hkAabbPhantom(aabb, 0);
    pPhantom->m_collidable.m_broadPhaseHandle.m_type = hkWorldObject::BROAD_PHASE_BORDER;
    pPhantom->addPhantomOverlapListener(this);
    m_phantoms[1] = pPhantom;
    m_world->addPhantom(pPhantom);

    aabb.m_min.set(f32MinX, f32MaxY, f32MinZ, 0.0f);
    aabb.m_max.set(f32MaxX, f32MaxY, f32MaxZ, 0.0f);
    pPhantom = new (HK_MEMORY_CLASS_PHANTOM) hkAabbPhantom(aabb, 0);
    pPhantom->m_collidable.m_broadPhaseHandle.m_type = hkWorldObject::BROAD_PHASE_BORDER;
    pPhantom->addPhantomOverlapListener(this);
    m_phantoms[2] = pPhantom;
    m_world->addPhantom(pPhantom);

    aabb.m_min.set(f32MinX, f32MinY, f32MinZ, 0.0f);
    aabb.m_max.set(f32MaxX, f32MinY, f32MaxZ, 0.0f);
    pPhantom = new (HK_MEMORY_CLASS_PHANTOM) hkAabbPhantom(aabb, 0);
    pPhantom->m_collidable.m_broadPhaseHandle.m_type = hkWorldObject::BROAD_PHASE_BORDER;
    pPhantom->addPhantomOverlapListener(this);
    m_phantoms[3] = pPhantom;
    m_world->addPhantom(pPhantom);

    aabb.m_min.set(f32MinX, f32MinY, f32MaxZ, 0.0f);
    aabb.m_max.set(f32MaxX, f32MaxY, f32MaxZ, 0.0f);
    pPhantom = new (HK_MEMORY_CLASS_PHANTOM) hkAabbPhantom(aabb, 0);
    pPhantom->m_collidable.m_broadPhaseHandle.m_type = hkWorldObject::BROAD_PHASE_BORDER;
    pPhantom->addPhantomOverlapListener(this);
    m_phantoms[4] = pPhantom;
    m_world->addPhantom(pPhantom);

    aabb.m_min.set(f32MinX, f32MinY, f32MinZ, 0.0f);
    aabb.m_max.set(f32MaxX, f32MaxY, f32MinZ, 0.0f);
    pPhantom = new (HK_MEMORY_CLASS_PHANTOM) hkAabbPhantom(aabb, 0);
    pPhantom->m_collidable.m_broadPhaseHandle.m_type = hkWorldObject::BROAD_PHASE_BORDER;
    pPhantom->addPhantomOverlapListener(this);
    m_phantoms[5] = pPhantom;
    m_world->addPhantom(pPhantom);
}

hkBroadPhaseBorder::~hkBroadPhaseBorder()
{
    for (s32 s32Index = 0; s32Index < 6; ++s32Index) {
        if (m_phantoms[s32Index] != NULL) {
            m_phantoms[s32Index]->removeReference();
            m_phantoms[s32Index] = NULL;
        }
    }
}

void hkBroadPhaseBorder::collidableAddedCallback(const hkCollidableAddedEvent& rParam1)
{
    hkCollidable* pCollidable = rParam1.m_collidable;
    hkEntity* pEntity = pCollidable->m_broadPhaseHandle.m_type == hkWorldObject::BROAD_PHASE_ENTITY
                            ? static_cast<hkEntity*>(pCollidable->getOwner())
                            : NULL;

    if (pEntity != NULL) {
        maxPositionExceededCallback(pEntity);
    }
}

void hkBroadPhaseBorder::collidableRemovedCallback(const hkCollidableRemovedEvent& rParam1)
{
}

void hkBroadPhaseBorder::maxPositionExceededCallback(hkEntity* pParam1)
{
    switch (m_behaviour) {
    case hkWorldCinfo::BROAD_PHASE_BORDER_REMOVE_ENTITY:
        m_world->removeEntity(pParam1);
        break;
    case hkWorldCinfo::BROAD_PHASE_BORDER_ASSERT:
    case hkWorldCinfo::BROAD_PHASE_BORDER_FIX_ENTITY:
        static_cast<hkRigidBody*>(pParam1)->setMotionType(hkMotion::MOTION_FIXED,
                                                          HK_ENTITY_ACTIVATION_DO_ACTIVATE,
                                                          HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
        break;
    default:
        break;
    }
}
void hkBroadPhaseBorder::worldDeletedCallback(hkWorld* pParam1)
{
    m_world->removeWorldDeletionListener(this);
    removeReference();
}

void hkBroadPhaseBorder::deactivate()
{
    if (m_world != NULL) {
        m_world->removePhantomBatch(m_phantoms, 6);

        for (s32 s32Index = 0; s32Index < 6; ++s32Index) {
            m_phantoms[s32Index]->removePhantomOverlapListener(this);
            m_phantoms[s32Index]->removeReference();
            m_phantoms[s32Index] = NULL;
        }

        worldDeletedCallback(m_world);
        m_world = NULL;
    }
}
