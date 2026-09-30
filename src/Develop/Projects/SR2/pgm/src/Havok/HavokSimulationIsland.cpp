#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkSimulationIsland::hkSimulationIsland(hkWorld* pParam1)
    : m_world(pParam1), m_numConstraints(0), m_dirtyListIndex(0xffff),
      m_highFrequencyDeactivationCounter(0), m_lowFrequencyDeactivationCounter(0),
      m_splitCheckRequested(0), m_sparseEnabled(0), m_actionListCleanupNeeded(0),
      m_allowIslandLocking(0), m_isInActiveIslandsArray(1), m_active(1), m_inIntegrateJob(0),
      m_timeSinceLastHighFrequencyCheck(0.0f), m_timeSinceLastLowFrequencyCheck(0.0f),
      m_timeOfDeactivation(-10.0f)
{
    m_constraintInfo.m_maxSizeOfSchema = 0;
    m_constraintInfo.m_sizeOfSchemas = 0;
    m_constraintInfo.m_numSolverResults = 0;
    m_constraintInfo.m_numSolverElemTemps = 0;
    m_agentTrack.m_bytesUsedInLastSector = sizeof(hkAgentNnSector);
}

hkSimulationIsland::~hkSimulationIsland()
{
}

void hkSimulationIsland::internalAddEntity(hkEntity* pParam1)
{
    pParam1->m_simulationIsland = this;
    pParam1->m_storageIndex = m_entities.getSize();
    m_entities.pushBack(pParam1);
}

void hkSimulationIsland::internalRemoveEntity(hkEntity* pParam1)
{
    m_entities.m_data[pParam1->m_storageIndex] = m_entities.back();
    m_entities.m_data[pParam1->m_storageIndex]->m_storageIndex = pParam1->m_storageIndex;
    --m_entities.m_size;
    pParam1->m_simulationIsland = NULL;
    pParam1->m_storageIndex = 0xffff;
    m_splitCheckRequested = 1;
}

void hkSimulationIsland::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

void hkSimulationIsland::addAction(hkAction* pParam1)
{
    m_actions.pushBack(pParam1);
    pParam1->m_island = this;
}

void hkSimulationIsland::removeAction(hkAction* pParam1)
{
    const s32 s32Index = m_actions.indexOf(pParam1);
    m_actions.m_data[s32Index] = NULL;
    pParam1->m_island = NULL;
    m_splitCheckRequested = 1;
    m_actionListCleanupNeeded = 1;
}

hkBool hkSimulationIsland::isFullyConnected(hkUnionFind& rParam1)
{
    return hkBool();
}

hkBool hkSimulationIsland::shouldDeactivateDeprecated(const hkStepInfo& rParam1)
{
    m_timeSinceLastHighFrequencyCheck += rParam1.m_deltaTime;
    m_timeSinceLastLowFrequencyCheck += rParam1.m_deltaTime;

    const f32 f32LowFrequencyPeriod = m_world->m_lowFrequencyDeactivationPeriod;
    const f32 f32HighFrequencyPeriod = m_world->m_highFrequencyDeactivationPeriod;
    const hkBool sLowFrequencyCheck(m_timeSinceLastLowFrequencyCheck > f32LowFrequencyPeriod);
    const hkBool sHighFrequencyCheck(m_timeSinceLastHighFrequencyCheck > f32HighFrequencyPeriod);

    if (sHighFrequencyCheck) {
        m_timeSinceLastHighFrequencyCheck -= f32HighFrequencyPeriod;
        hkBool sShouldDeactivate(1);
        for (s32 s32Index = 0; s32Index < m_entities.getSize(); ++s32Index) {
            hkEntity* pEntity = m_entities.m_data[s32Index];
            hkRigidBodyDeactivator* pDeactivator =
                static_cast<hkRigidBodyDeactivator*>(pEntity->m_deactivator);
            if (pDeactivator != NULL) {
                if (!pDeactivator->shouldDeactivateHighFrequency(pEntity)) {
                    sShouldDeactivate.m_bool = 0;
                }
            } else {
                sShouldDeactivate.m_bool = 0;
            }
        }
        if (sShouldDeactivate) {
            ++m_highFrequencyDeactivationCounter;
            if (m_highFrequencyDeactivationCounter >= 5) {
                m_highFrequencyDeactivationCounter = 0;
                return hkBool(1);
            }
            return hkBool(0);
        }
        m_highFrequencyDeactivationCounter = 0;
        return hkBool(0);
    }

    if (sLowFrequencyCheck) {
        m_timeSinceLastLowFrequencyCheck -= f32LowFrequencyPeriod;
        hkBool sShouldDeactivate(1);
        for (s32 s32Index = 0; s32Index < m_entities.getSize(); ++s32Index) {
            hkEntity* pEntity = m_entities.m_data[s32Index];
            hkRigidBodyDeactivator* pDeactivator =
                static_cast<hkRigidBodyDeactivator*>(pEntity->m_deactivator);
            if (pDeactivator != NULL) {
                if (!pDeactivator->shouldDeactivateLowFrequency(pEntity)) {
                    sShouldDeactivate.m_bool = 0;
                }
            } else {
                sShouldDeactivate.m_bool = 0;
            }
        }
        if (sShouldDeactivate) {
            ++m_lowFrequencyDeactivationCounter;
            if (m_lowFrequencyDeactivationCounter >= 5) {
                m_lowFrequencyDeactivationCounter = 0;
                return hkBool(1);
            }
            return hkBool(0);
        }
        m_lowFrequencyDeactivationCounter = 0;
    }

    return hkBool(0);
}

void hkSimulationIsland::addConstraintToCriticalLockedIsland(hkConstraintInstance* pParam1)
{
    hkWorldOperationUtil::addConstraintToCriticalLockedIsland(pParam1->m_entities[0]->m_world,
                                                              pParam1);
}

void hkSimulationIsland::removeConstraintFromCriticalLockedIsland(hkConstraintInstance* pParam1)
{
    hkWorldOperationUtil::removeConstraintFromCriticalLockedIsland(pParam1->m_entities[0]->m_world,
                                                                   pParam1);
}

void hkSimulationIsland::addCallbackRequest(hkConstraintInstance* pParam1, s32 s32Param2)
{
    pParam1->m_internal->m_callbackRequest |= s32Param2;
}

void hkSimulationIsland::mergeConstraintInfo(hkSimulationIsland& rParam1)
{
    const s32 s32OtherMaxSchema = rParam1.m_constraintInfo.m_maxSizeOfSchema;
    m_constraintInfo.m_maxSizeOfSchema = s32OtherMaxSchema < m_constraintInfo.m_maxSizeOfSchema
                                             ? m_constraintInfo.m_maxSizeOfSchema
                                             : s32OtherMaxSchema;
    const s32 s32OtherSchemas = rParam1.m_constraintInfo.m_sizeOfSchemas;
    m_constraintInfo.m_sizeOfSchemas += s32OtherSchemas;
    const s32 s32OtherSolverResults = rParam1.m_constraintInfo.m_numSolverResults;
    m_constraintInfo.m_numSolverResults += s32OtherSolverResults;
    const s32 s32OtherSolverElemTemps = rParam1.m_constraintInfo.m_numSolverElemTemps;
    m_constraintInfo.m_numSolverElemTemps += s32OtherSolverElemTemps;
}
