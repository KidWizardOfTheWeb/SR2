#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

u8 hkWorld::m_forceMultithreadedSimulation;

hkWorld::~hkWorld()
{
}

void hkWorld::updateCollisionFilterOnWorld(hkUpdateCollisionFilterOnWorldMode sParam1,
                                           hkUpdateCollectionFilterMode sParam2)
{
}

void hkWorld::updateCollisionFilterOnPhantom(hkPhantom* pParam1,
                                             hkUpdateCollectionFilterMode sParam2)
{
}

void hkWorld::updateCollisionFilterOnEntity(hkEntity* pParam1,
                                            hkUpdateCollisionFilterOnEntityMode sParam2,
                                            hkUpdateCollectionFilterMode sParam3)
{
}

hkEntity* hkWorld::addEntity(hkEntity* pParam1, hkEntityActivation sParam2)
{
    return NULL;
}

void hkWorld::addEntityBatch(hkEntity* const* pParam1, s32 s32Param2, hkEntityActivation sParam3)
{
}

hkBool hkWorld::removeEntity(hkEntity* pParam1)
{
    return hkBool(0);
}

void hkWorld::removeEntityBatch(hkEntity* const* pParam1, s32 s32Param2)
{
}

void hkWorld::activateRegion(const hkAabb& rParam1)
{
}

void hkWorld::addConstraint(hkConstraintInstance* pParam1)
{
}

hkBool hkWorld::removeConstraint(hkConstraintInstance* pParam1)
{
    return hkBool(0);
}

void hkWorld::addAction(hkAction* pParam1)
{
}

void hkWorld::removeAction(hkAction* pParam1)
{
}

void hkWorld::removeActionImmediately(hkAction* pParam1)
{
}

hkPhantom* hkWorld::addPhantom(hkPhantom* pParam1)
{
    return NULL;
}

void hkWorld::addPhantomBatch(hkPhantom* const* pParam1, s32 s32Param2)
{
}

void hkWorld::removePhantom(hkPhantom* pParam1)
{
}

void hkWorld::removePhantomBatch(hkPhantom* const* pParam1, s32 s32Param2)
{
}

void hkWorld::addWorldDeletionListener(hkWorldDeletionListener* pParam1)
{
}

void hkWorld::removeWorldDeletionListener(hkWorldDeletionListener* pParam1)
{
}

hkStepResult hkWorld::stepDeltaTime(f32 f32Param1)
{
    return HK_STEP_RESULT_SUCCESS;
}

void hkWorld::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

void hkWorld::checkDeterminism()
{
}

hkWorld::hkWorld(const hkWorldCinfo& rParam1, u32 u32Param2)
{
}

void hkWorld::setCollisionFilter(hkCollisionFilter* pParam1,
                                 hkBool sParam2,
                                 hkUpdateCollisionFilterOnWorldMode sParam3,
                                 hkUpdateCollectionFilterMode sParam4)
{
}

void hkWorld::castRay(const hkWorldRayCastInput& rParam1, hkWorldRayCastOutput& rParam2) const
{
}

void hkWorld::internal_executePendingOperations()
{
    m_pendingOperationsCount = 0;
    m_pendingOperations->executeAllPending();
}

void hkWorld::queueOperation(const hkWorldOperation::BaseOperation& rParam1)
{
    m_pendingOperations->queueOperation(rParam1);
}

s32 hkWorld::getMemUsageForIntegration()
{
    return 0;
}

void hkWorld::lockIslandForConstraintUpdate(hkSimulationIsland* pParam1)
{
}

void hkWorld::unlockIslandForConstraintUpdate(hkSimulationIsland* pParam1)
{
}

hkWorldCinfo::hkWorldCinfo()
{
}

void hkWorldCinfo::setBroadPhaseWorldSize(f32 f32Param1)
{
}

void hkWorldCinfo::setupSolverInfo(hkWorldCinfo::SolverType sParam1)
{
}
