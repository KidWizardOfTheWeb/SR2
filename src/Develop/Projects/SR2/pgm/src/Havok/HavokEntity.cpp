#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkEntity::hkEntity(const hkShape* pParam1) : hkWorldObject(pParam1, BROAD_PHASE_ENTITY)
{
    m_storageIndex = 0xffff;
    m_simulationIsland = NULL;
    m_deactivator = NULL;
    m_breakOffPartsUtil = NULL;
    m_uid = ~0u;
    m_solverData = 0;
}

hkEntity::hkEntity(hkFinishLoadedObjectFlag sParam1)
    : hkWorldObject(sParam1), m_material(sParam1), m_motion(sParam1)
{
    if (sParam1.m_finishing) {
        switch (m_motion.getType()) {
        case hkMotion::MOTION_SPHERE_INERTIA:
            new (&m_motion) hkSphereMotion(sParam1);
            break;
        case hkMotion::MOTION_SPHERE_STABILIZED:
            new (&m_motion) hkStabilizedSphereMotion(sParam1);
            break;
        case hkMotion::MOTION_BOX_INERTIA:
            new (&m_motion) hkBoxMotion(sParam1);
            break;
        case hkMotion::MOTION_BOX_STABILIZED:
            new (&m_motion) hkStabilizedBoxMotion(sParam1);
            break;
        case hkMotion::MOTION_KEYFRAMED:
            new (&m_motion) hkKeyframedRigidMotion(sParam1);
            break;
        case hkMotion::MOTION_FIXED:
            new (&m_motion) hkFixedRigidMotion(sParam1);
            break;
        case hkMotion::MOTION_THIN_BOX_INERTIA:
            new (&m_motion) hkThinBoxMotion(sParam1);
            break;
        }
    }
}

void hkEntity::calcStatistics(hkStatisticsCollector* pParam1) const
{
    pParam1->beginObject("Entity", 2, this);
    hkWorldObject::calcStatistics(pParam1);
    pParam1->addChildObject("SavedMotion", 4, m_motion.m_savedMotion);
    pParam1->addChildObject("Deactivator", 4, m_deactivator);

    if (!(m_collisionListeners.m_capacityAndFlags & 0x8000)) {
        pParam1->addArray("CollisionListnr",
                          4,
                          m_collisionListeners.m_data,
                          m_collisionListeners.getSize() * sizeof(hkCollisionListener*),
                          m_collisionListeners.getCapacity() * sizeof(hkCollisionListener*));
    }
    if (!(m_activationListeners.m_capacityAndFlags & 0x8000)) {
        pParam1->addArray("ActLstnrPtrs",
                          4,
                          m_activationListeners.m_data,
                          m_activationListeners.getSize() * sizeof(hkEntityActivationListener*),
                          m_activationListeners.getCapacity() *
                              sizeof(hkEntityActivationListener*));
    }
    if (!(m_entityListeners.m_capacityAndFlags & 0x8000)) {
        pParam1->addArray("ListenerPtrs.",
                          4,
                          m_entityListeners.m_data,
                          m_entityListeners.getSize() * sizeof(hkEntityListener*),
                          m_entityListeners.getCapacity() * sizeof(hkEntityListener*));
    }

    pParam1->endObject();
}

hkEntity::~hkEntity()
{
    hkEntityCallbackUtil::fireEntityDeleted(this);
    if (m_deactivator != NULL) {
        m_deactivator->removeReference();
    }
}

void hkEntity::setDeactivator(hkEntityDeactivator* pParam1)
{
    if (pParam1 != NULL) {
        pParam1->addReference();
    }
    if (m_deactivator != NULL) {
        m_deactivator->removeReference();
    }
    m_deactivator = pParam1;
}

void hkEntity::addEntityListener(hkEntityListener* pParam1)
{
    s32 s32Index = m_entityListeners.indexOf(NULL);
    if (s32Index >= 0) {
        m_entityListeners[s32Index] = pParam1;
    } else {
        m_entityListeners.pushBack(pParam1);
    }
}

void hkEntity::removeEntityListener(hkEntityListener* pParam1)
{
    m_entityListeners[m_entityListeners.indexOf(pParam1)] = NULL;
}

void hkEntity::addCollisionListener(hkCollisionListener* pParam1)
{
    s32 s32Index = m_collisionListeners.indexOf(NULL);
    if (s32Index >= 0) {
        m_collisionListeners[s32Index] = pParam1;
    } else {
        m_collisionListeners.pushBack(pParam1);
    }
}

hkBool hkEntity::isActive() const
{
    if (m_simulationIsland == NULL) {
        return hkBool(0);
    }

    hkBool bActive;
    bActive.m_bool = m_simulationIsland->m_active;
    return bActive;
}

void hkEntity::activate()
{
    if (isActive().m_bool) {
        return;
    }
    if (m_motion.isFixed().m_bool) {
        return;
    }
    if (m_world == NULL) {
        return;
    }

    m_motion.m_deactivationNumInactiveFrames[0] = 0;
    m_motion.m_deactivationNumInactiveFrames[1] = 0;
    hkWorldOperationUtil::markIslandActive(m_world, m_simulationIsland);

    s32 s32WorldCounter = m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter;
    s32 s32Flag1 =
        m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
    s32 s32Flag0 =
        m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];

    if (static_cast<u32>(s32WorldCounter & 3) < (m_motion.m_deactivationIntegrateCounter & 3)) {
        s32Flag0 = (~s32Flag0) << 14;
    } else {
        s32Flag0 <<= 14;
    }

    s32 s32ShiftedFlag1;
    if (s32WorldCounter < (m_motion.m_deactivationIntegrateCounter & 0xff)) {
        s32ShiftedFlag1 = (~s32Flag1) << 14;
    } else {
        s32ShiftedFlag1 = s32Flag1 << 14;
    }

    m_motion.m_deactivationNumInactiveFrames[0] =
        (m_motion.m_deactivationNumInactiveFrames[0] & 0x3fff) | s32Flag0;
    m_motion.m_deactivationNumInactiveFrames[1] =
        (m_motion.m_deactivationNumInactiveFrames[1] & 0x3fff) | s32ShiftedFlag1;
}

void hkEntity::deactivate()
{
    if (!isActive().m_bool) {
        return;
    }

    if (m_simulationIsland->m_sparseEnabled || m_simulationIsland->m_splitCheckRequested) {
        u32 u32MinDesiredIslandSize = m_world->m_minDesiredIslandSize;
        m_world->m_minDesiredIslandSize = 0;
        m_simulationIsland->m_sparseEnabled = 0;
        m_simulationIsland->m_splitCheckRequested = 1;
        hkWorldOperationUtil::splitSimulationIsland(m_world, m_simulationIsland);
        m_world->m_minDesiredIslandSize = u32MinDesiredIslandSize;
    }

    for (s32 s32Index = 0; s32Index < m_simulationIsland->m_entities.getSize(); ++s32Index) {
        hkEntity* pEntity = m_simulationIsland->m_entities.m_data[s32Index];
        pEntity->m_motion.m_deactivationRefPosition[0].w = 3.40282e38f;
        pEntity->m_motion.m_deactivationRefPosition[1].w = 3.40282e38f;
    }

    hkWorldOperationUtil::markIslandInactive(m_world, m_simulationIsland);
}

void hkEntity::deallocateInternalArrays()
{
    hkArray<CollisionEntry>& rCollisionEntries = m_collidable.m_collisionEntries;
    if (rCollisionEntries.getSize() == 0) {
        rCollisionEntries.clearAndDeallocate();
    }
    if (m_constraintsMaster.getSize() == 0) {
        m_constraintsMaster.clearAndDeallocate();
    }
    if (m_constraintsSlave.getSize() == 0) {
        m_constraintsSlave.clearAndDeallocate();
    }
    if (m_constraintRuntime.getSize() == 0) {
        m_constraintRuntime.clearAndDeallocate();
    }

    hkBool bHasListener(0);
    for (s32 s32Index = 0; s32Index < m_collisionListeners.getSize(); ++s32Index) {
        if (m_collisionListeners.m_data[s32Index] != NULL) {
            bHasListener.m_bool = 1;
            break;
        }
    }
    if (!bHasListener.m_bool) {
        m_collisionListeners.clearAndDeallocate();
    }

    bHasListener.m_bool = 0;
    for (s32 s32Index = 0; s32Index < m_activationListeners.getSize(); ++s32Index) {
        if (m_activationListeners.m_data[s32Index] != NULL) {
            bHasListener.m_bool = 1;
            break;
        }
    }
    if (!bHasListener.m_bool) {
        m_activationListeners.clearAndDeallocate();
    }

    bHasListener.m_bool = 0;
    for (s32 s32Index = 0; s32Index < m_entityListeners.getSize(); ++s32Index) {
        if (m_entityListeners.m_data[s32Index] != NULL) {
            bHasListener.m_bool = 1;
            break;
        }
    }
    if (!bHasListener.m_bool) {
        m_entityListeners.clearAndDeallocate();
    }

    if (m_actions.isEmpty().m_bool) {
        m_actions.clearAndDeallocate();
    }
}

hkMotionState* hkEntity::getMotionState()
{
    return NULL;
}
