#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

// RECONSTRUCTED: source ownership.

hkThreadMemory* hkThreadMemory::s_threadMemoryInstance;
hkMemory* hkMemory::s_instance;
u8 hkMeshShape::Members[140];

hkFakeRigidBodyDeactivator hkFakeRigidBodyDeactivator::m_fakeRigidBodyDeactivator;
hkMonitorStream hkMonitorStream::m_instance;
u8 hkWeldingUtility::m_sinCosTable[744];
c8 hkString::s_emptyStringRep[13];
u32 hkCollideTriangleUtil::maskToIndex[16];
u8 hkCollideTriangleUtil::vertexToEdgeLut[5];

hkMemory::hkMemory()
{
}

hkMemory::~hkMemory()
{
}

void hkMemory::replaceInstance(hkMemory* pParam1)
{
}

s32 hkMemory::getAllocatedSize(s32 s32Param1)
{
    return 0;
}

hkBool hkMemory::isOk() const
{
    return hkBool();
}

hkClass::hkClass(const c8* pcParam1,
                 const hkClass* pParam2,
                 s32 s32Param3,
                 const hkClass** pParam4,
                 s32 s32Param5,
                 const hkClassEnum* pParam6,
                 s32 s32Param7,
                 const hkClassMember* pParam8,
                 s32 s32Param9,
                 const void* pvParam10)
{
}

hkUnaryAction::hkUnaryAction(hkEntity* pParam1, u32 u32Param2)
{
}

void hkUnaryAction::entityRemovedCallback(hkEntity* pParam1)
{
}

hkUnaryAction::~hkUnaryAction()
{
}

void hkUnaryAction::getEntities(hkArray<hkEntity*>& rParam1)
{
}

hkMoppCompilerInput::hkMoppCompilerInput()
{
}

f32 hkMoppCompilerInput::getAbsoluteFitToleranceOfTriangles() const
{
    return 0.0f;
}

hkVector4 hkMoppCompilerInput::getAbsoluteFitToleranceOfAxisAlignedTriangles() const
{
    return m_absoluteFitToleranceOfAxisAlignedTriangles;
}

f32 hkMoppCompilerInput::getRelativeFitToleranceOfInternalNodes() const
{
    return 0.0f;
}

f32 hkMoppCompilerInput::getAbsoluteFitToleranceOfInternalNodes() const
{
    return 0.0f;
}

void hkCollisionDispatcher::resetCreationFunctions()
{
}

hkCollisionDispatcher::hkCollisionDispatcher(hkCollisionAgent* (*pParam1)(const hkCdBody&,
                                                                          const hkCdBody&,
                                                                          const hkCollisionInput&,
                                                                          hkContactMgr*),
                                             hkContactMgrFactory* pParam2)
{
}

void hkCollisionDispatcher::setEnableChecks(hkBool sParam1)
{
}

void hkCollisionAgent::invalidateTim(hkCollisionInput& rParam1)
{
}

void hkCollisionAgent::warpTime(f32 f32Param1, f32 f32Param2, hkCollisionInput& rParam3)
{
}

void hkCollisionAgent::removePoint(u16 u16Param1)
{
}

void hkCollisionAgent::commitPotential(u16 u16Param1)
{
}

void hkCollisionAgent::createZombie(u16 u16Param1)
{
}

void hkCollisionDispatcher::disableDebugging()
{
}

hkCollisionDispatcher::~hkCollisionDispatcher()
{
}

void hkCollisionDispatcher::registerCollisionAgent(AgentFuncs& rParam1,
                                                   hkShapeType sParam2,
                                                   hkShapeType sParam3)
{
}

void hkCollisionDispatcher::registerCollisionAgent2(AgentFuncs& rParam1,
                                                    hkShapeType sParam2,
                                                    hkShapeType sParam3)
{
}

void hkCollisionDispatcher::registerAgent3(Agent3Funcs& rParam1,
                                           hkShapeType sParam2,
                                           hkShapeType sParam3)
{
}

void hkCollisionDispatcher::internalRegisterCollisionAgent(u8 (*pcParam1)[32],
                                                           s32 s32Param2,
                                                           hkShapeType sParam3,
                                                           hkShapeType sParam4,
                                                           hkShapeType sParam5,
                                                           hkShapeType sParam6,
                                                           DebugEntry (*pParam7)[32][32],
                                                           s32 s32Param8)
{
}

void hkCollisionDispatcher::updateHasAlternateType(hkShapeType sParam1,
                                                   hkShapeType sParam2,
                                                   s32 s32Param3)
{
}

void hkCollisionDispatcher::registerAlternateShapeType(hkShapeType sParam1, hkShapeType sParam2)
{
}

void hkCollisionDispatcher::registerContactMgrFactoryWithAll(hkContactMgrFactory* pParam1,
                                                             s32 s32Param2)
{
}

void hkCollisionDispatcher::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

void hkCollisionDispatcher::initCollisionQualityInfo(
    hkCollisionDispatcher::InitCollisionQualityInfo& rParam1)
{
}

u32 hkShapeContainer::getCollisionFilterInfo(u32 u32Param1) const
{
    return 0;
}

s32 hkShapeContainer::getNumChildShapes() const
{
    return 0;
}

const hkShape* hkSingleShapeContainer::getChildShape(u32 u32Param1, c8 (&sParam2)[512]) const
{
    return m_childShape;
}

f32 hkShape::getMaximumProjection(const hkVector4& rParam1) const
{
    return 0.0f;
}

void hkTransformShape::setTransform(const hkTransform& rParam1)
{
}

hkTransformShape::hkTransformShape(const hkShape* pParam1, const hkTransform& rParam2)
    : m_rotation(0.0f, 0.0f, 0.0f, 0.0f)
{
}

void hkTransformShape::getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const
{
}

f32 hkTransformShape::getMaximumProjection(const hkVector4& rParam1) const
{
    return 0.0f;
}

hkBool hkTransformShape::castRayImpl(const hkShapeRayCastInput& rParam1,
                                     hkShapeRayCastOutput& rParam2) const
{
    return hkBool();
}

void hkTransformShape::castRayWithCollector(const hkShapeRayCastInput& rParam1,
                                            const hkCdBody& rParam2,
                                            hkRayHitCollector& rParam3) const
{
}

void hkTransformShape::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

hkShapeContainer* hkTransformShape::getContainer() const
{
    return NULL;
}

hkShapeCollection::hkShapeCollection(hkShapeType sParam1)
{
}

hkBool hkShapeCollection::castRayImpl(const hkShapeRayCastInput& rParam1,
                                      hkShapeRayCastOutput& rParam2) const
{
    return hkBool();
}

void hkShapeCollection::getAabbImpl(const hkTransform& rParam1,
                                    f32 f32Param2,
                                    hkAabb& rParam3) const
{
}

f32 hkShapeCollection::getMaximumProjection(const hkVector4& rParam1) const
{
    return 0.0f;
}

void hkShapeCollection::castRayWithCollector(const hkShapeRayCastInput& rParam1,
                                             const hkCdBody& rParam2,
                                             hkRayHitCollector& rParam3) const
{
}

hkShapeContainer* hkShapeCollection::getContainer() const
{
    return NULL;
}

void hkShapeCollection::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

hkListShape::hkListShape(const hkShape* const* pParam1, s32 s32Param2)
    : hkShapeCollection(HK_SHAPE_LIST)
{
}

hkListShape::~hkListShape()
{
}

void hkListShape::setShapes(const hkShape* const* pParam1, s32 s32Param2, const u32* pParam3)
{
}

hkBool hkListShape::castRayImpl(const hkShapeRayCastInput& rParam1,
                                hkShapeRayCastOutput& rParam2) const
{
    return hkBool();
}

void hkListShape::getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const
{
}

void hkListShape::recalcAabbExtents()
{
}

s32 hkListShape::getNumChildShapes() const
{
    return 0;
}

u32 hkListShape::getFirstKey() const
{
    return 0;
}

u32 hkListShape::getNextKey(u32 u32Param1) const
{
    return 0;
}

const hkShape* hkListShape::getChildShape(u32 u32Param1, c8 (&sParam2)[512]) const
{
    return NULL;
}

u32 hkListShape::getCollisionFilterInfo(u32 u32Param1) const
{
    return 0;
}

void hkListShape::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

s32 hkListShape::calcSizeForSpu(s32 s32Param1) const
{
    return 0;
}

hkMeshShape::hkMeshShape(f32 f32Param1, s32 s32Param2) : hkShapeCollection(HK_SHAPE_COLLECTION)
{
}

hkMeshShape::hkMeshShape(hkFinishLoadedObjectFlag sParam1) : hkShapeCollection(HK_SHAPE_COLLECTION)
{
}

u32 hkMeshShape::getFirstKey() const
{
    return 0;
}

u32 hkMeshShape::getNextKey(u32 u32Param1) const
{
    return 0;
}

const hkShape* hkMeshShape::getChildShape(u32 u32Param1, c8 (&sParam2)[512]) const
{
    return NULL;
}

u32 hkMeshShape::getCollisionFilterInfo(u32 u32Param1) const
{
    return 0;
}

void hkMeshShape::getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const
{
}

void hkMeshShape::addSubpart(const hkMeshShape::Subpart& rParam1)
{
}

void hkMeshShape::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

hkTypedBroadPhaseDispatcher::hkTypedBroadPhaseDispatcher()
{
}

hkTypedBroadPhaseDispatcher::~hkTypedBroadPhaseDispatcher()
{
}

void hkTypedBroadPhaseDispatcher::addPairs(hkTypedBroadPhaseHandlePair* pParam1,
                                           s32 s32Param2,
                                           const hkCollidableCollidableFilter* pParam3) const
{
}

void hkTypedBroadPhaseDispatcher::removePairs(hkTypedBroadPhaseHandlePair* pParam1,
                                              s32 s32Param2) const
{
}

void hkTypedBroadPhaseDispatcher::removeDuplicates(hkArray<hkBroadPhaseHandlePair>& rParam1,
                                                   hkArray<hkBroadPhaseHandlePair>& rParam2)
{
}

f32 hkConvexShape::getMaximumProjection(const hkVector4& rParam1) const
{
    return 0.0f;
}

void hkConvexShape::castRayWithCollector(const hkShapeRayCastInput& rParam1,
                                         const hkCdBody& rParam2,
                                         hkRayHitCollector& rParam3) const
{
}

void hkConvexShape::weldContactPointImpl(u16* pParam1,
                                         u8& rParam2,
                                         hkVector4& rParam3,
                                         const hkTransform* pParam4,
                                         const hkConvexShape* pParam5,
                                         const hkTransform* pParam6,
                                         hkVector4& rParam7) const
{
}

void hkConvexShape::getCentreImpl(hkVector4& rParam1) const
{
}

hkConvexVerticesShape::hkConvexVerticesShape(hkStridedVertices sParam1,
                                             const hkArray<hkVector4>& rParam2,
                                             f32 f32Param3)
{
}

void hkConvexVerticesShape::getOriginalVertices(hkArray<hkVector4>& rParam1) const
{
}

void hkConvexVerticesShape::copyVertexData(const f32* pParam1, s32 s32Param2, s32 s32Param3)
{
}

void hkConvexVerticesShape::getFirstVertex(hkVector4& rParam1) const
{
}

s32 hkConvexVerticesShape::getNumCollisionSpheresImpl() const
{
    return 0;
}

void hkConvexVerticesShape::getCollisionSpheresImpl(hkSphere* pParam1) const
{
}

void hkConvexVerticesShape::getAabbImpl(const hkTransform& rParam1,
                                        f32 f32Param2,
                                        hkAabb& rParam3) const
{
}

void hkConvexVerticesShape::getSupportingVertexImpl(const hkVector4& rParam1,
                                                    hkCdVertex& rParam2) const
{
}

void hkConvexVerticesShape::convertVertexIdsToVerticesImpl(const u16* pParam1,
                                                           s32 s32Param2,
                                                           hkCdVertex* pParam3) const
{
}

void hkConvexVerticesShape::getCentreImpl(hkVector4& rParam1) const
{
}

hkBool hkConvexVerticesShape::castRayImpl(const hkShapeRayCastInput& rParam1,
                                          hkShapeRayCastOutput& rParam2) const
{
    return hkBool();
}

const hkArray<hkVector4>& hkConvexVerticesShape::getPlaneEquations() const
{
    return m_planeEquations;
}

void hkConvexVerticesShape::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

hkCapsuleShape::hkCapsuleShape(const hkVector4& rParam1, const hkVector4& rParam2, f32 f32Param3)
{
}

void hkCapsuleShape::getSupportingVertexImpl(const hkVector4& rParam1, hkCdVertex& rParam2) const
{
}

void hkCapsuleShape::convertVertexIdsToVerticesImpl(const u16* pParam1,
                                                    s32 s32Param2,
                                                    hkCdVertex* pParam3) const
{
}

void hkCapsuleShape::getCentreImpl(hkVector4& rParam1) const
{
}

void hkCapsuleShape::getFirstVertex(hkVector4& rParam1) const
{
}

s32 hkCapsuleShape::getNumCollisionSpheresImpl() const
{
    return 0;
}

void hkCapsuleShape::getCollisionSpheresImpl(hkSphere* pParam1) const
{
}

void hkCapsuleShape::getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const
{
}

void hkCapsuleShape::closestInfLineSegInfLineSeg(const hkVector4& rParam1,
                                                 const hkVector4& rParam2,
                                                 const hkVector4& rParam3,
                                                 const hkVector4& rParam4,
                                                 f32& rParam5,
                                                 f32& rParam6,
                                                 f32& rParam7,
                                                 hkVector4& rParam8,
                                                 hkVector4& rParam9)
{
}

void hkCapsuleShape::closestPointLineSeg(const hkVector4& rParam1,
                                         const hkVector4& rParam2,
                                         const hkVector4& rParam3,
                                         hkVector4& rParam4)
{
}

hkBool hkCapsuleShape::castRayImpl(const hkShapeRayCastInput& rParam1,
                                   hkShapeRayCastOutput& rParam2) const
{
    return hkBool();
}

void hkCapsuleShape::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

hkBoxShape::hkBoxShape(const hkVector4& rParam1, f32 f32Param2)
{
}

hkBoxShape::~hkBoxShape()
{
}

void hkBoxShape::setHalfExtents(const hkVector4& rParam1)
{
}

void hkBoxShape::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

void hkBoxShape::getFirstVertex(hkVector4& rParam1) const
{
}

void hkBoxShape::getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const
{
}

void hkBoxShape::getSupportingVertexImpl(const hkVector4& rParam1, hkCdVertex& rParam2) const
{
}

void hkBoxShape::getCentreImpl(hkVector4& rParam1) const
{
}

void hkBoxShape::convertVertexIdsToVerticesImpl(const u16* pParam1,
                                                s32 s32Param2,
                                                hkCdVertex* pParam3) const
{
}

s32 hkBoxShape::getNumCollisionSpheresImpl() const
{
    return 0;
}

void hkBoxShape::getCollisionSpheresImpl(hkSphere* pParam1) const
{
}

hkBool hkBoxShape::castRayImpl(const hkShapeRayCastInput& rParam1,
                               hkShapeRayCastOutput& rParam2) const
{
    return hkBool();
}

void hkSphereShape::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

hkSphereShape::hkSphereShape(f32 f32Param1)
{
}

void hkSphereShape::getSupportingVertexImpl(const hkVector4& rParam1, hkCdVertex& rParam2) const
{
}

void hkSphereShape::convertVertexIdsToVerticesImpl(const u16* pParam1,
                                                   s32 s32Param2,
                                                   hkCdVertex* pParam3) const
{
}

void hkSphereShape::getCentreImpl(hkVector4& rParam1) const
{
}

void hkSphereShape::getFirstVertex(hkVector4& rParam1) const
{
}

void hkSphereShape::getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const
{
}

s32 hkSphereShape::getNumCollisionSpheresImpl() const
{
    return 0;
}

void hkSphereShape::getCollisionSpheresImpl(hkSphere* pParam1) const
{
}

hkBool hkSphereShape::castRayImpl(const hkShapeRayCastInput& rParam1,
                                  hkShapeRayCastOutput& rParam2) const
{
    return hkBool();
}

void hkMultiThreadCheck::disableChecks()
{
    m_threadId = -47;
}

void hkConstraintOwner::addConstraintToCriticalLockedIsland(hkConstraintInstance* pParam1)
{
}

void hkConstraintOwner::removeConstraintFromCriticalLockedIsland(hkConstraintInstance* pParam1)
{
}

void hkConstraintOwner::addCallbackRequest(hkConstraintInstance* pParam1, s32 s32Param2)
{
}

void hkConstraintOwner::checkAccessRw()
{
}

void hkBridgeConstraintAtom_callData(hkConstraintData* pParam1,
                                     const hkConstraintQueryIn& rParam2,
                                     hkConstraintQueryOut& rParam3)
{
    pParam1->buildJacobian(rParam2, rParam3);
}

void hkConstraintData::addInstance(hkConstraintInstance* pParam1,
                                   void* pvParam2,
                                   s32 s32Param3) const
{
}

hkSolverResults* hkConstraintData::getSolverResults(void* pvParam1)
{
    return NULL;
}

void hkConstraintData::getConstraintInfoUtil(const hkConstraintAtom* pParam1,
                                             s32 s32Param2,
                                             hkConstraintData::ConstraintInfo& rParam3)
{
}

void hkAllCdPointCollector::addCdPoint(const hkCdPoint& rParam1)
{
}

void hkAllCdPointCollector::sortHits()
{
}

void hkAllCdBodyPairCollector::addCdBodyPair(const hkCdBody& rParam1, const hkCdBody& rParam2)
{
}

void hkModifierConstraintAtom::addModifierDataToConstraintInfo(hkConstraintInfo& rParam1) const
{
}

void hkModifierConstraintAtom::addAllModifierDataToConstraintInfo(hkModifierConstraintAtom* pParam1,
                                                                  hkConstraintInfo& rParam2)
{
}

hkConstraintInstance::hkConstraintInstance(hkEntity* pParam1,
                                           hkEntity* pParam2,
                                           hkConstraintData* pParam3,
                                           hkConstraintInstance::ConstraintPriority sParam4)
{
}

hkConstraintInstance::hkConstraintInstance(hkConstraintInstance::ConstraintPriority sParam1)
{
}

void hkConstraintInstance::setPriority(hkConstraintInstance::ConstraintPriority sParam1)
{
}

void hkConstraintInstance::entityAddedCallback(hkEntity* pParam1)
{
}

void hkConstraintInstance::entityDeletedCallback(hkEntity* pParam1)
{
}

void hkConstraintInstance::entityRemovedCallback(hkEntity* pParam1)
{
}

hkConstraintInstance::~hkConstraintInstance()
{
}

void hkConstraintInstance::pointNullsToFixedRigidBody()
{
}

hkHingeLimitsData::hkHingeLimitsData()
{
}

void hkHingeLimitsData::setInBodySpace(const hkVector4& rParam1,
                                       const hkVector4& rParam2,
                                       const hkVector4& rParam3,
                                       const hkVector4& rParam4)
{
}

void hkHingeLimitsData::getConstraintInfo(hkConstraintData::ConstraintInfo& rParam1) const
{
}

void hkHingeLimitsData::getRuntimeInfo(hkBool sParam1, hkConstraintData::RuntimeInfo& rParam2) const
{
    rParam2.m_numSolverResults = 3;
    rParam2.m_size = 28;
}

hkBool hkHingeLimitsData::isValid() const
{
    return hkBool();
}

s32 hkHingeLimitsData::getType() const
{
    return 0;
}

hkConstraintChainInstance::hkConstraintChainInstance(hkConstraintChainData* pParam1)
    : hkConstraintInstance(CONSTRAINT_PRIORITY_INVALID)
{
}

void hkConstraintChainInstance::addEntity(hkEntity* pParam1)
{
}

hkConstraintChainInstance::~hkConstraintChainInstance()
{
}

void hkConstraintChainInstance::entityRemovedCallback(hkEntity* pParam1)
{
}

void hkConstraintChainInstanceAction::applyAction(const hkStepInfo& rParam1)
{
}

hkAction* hkConstraintChainInstanceAction::clone(const hkArray<hkEntity*>& rParam1,
                                                 const hkArray<hkPhantom*>& rParam2) const
{
    return NULL;
}

void hkConstraintChainInstanceAction::entityRemovedCallback(hkEntity* pParam1)
{
}

void hkConstraintChainInstanceAction::getEntities(hkArray<hkEntity*>& rParam1)
{
}

hkBallSocketChainData::hkBallSocketChainData()
{
    m_tau = 0.6f;
    m_damping = 1.0f;
    m_cfm = 1.1920929e-8f;
    m_maxErrorDistance = 0.1f;
    m_atoms.m_bridgeAtom.init(this);
}

hkBallSocketChainData::~hkBallSocketChainData()
{
}

s32 hkBallSocketChainData::getType() const
{
    return 101;
}

void hkBallSocketChainData::addConstraintInfoInBodySpace(const hkVector4& rParam1,
                                                         const hkVector4& rParam2)
{
    ConstraintInfo& rInfo = m_infos.expandOne();
    rInfo.m_pivotInA = rParam1;
    rInfo.m_pivotInB = rParam2;
}

void hkBridgeConstraintAtom::init(hkConstraintData* pParam1)
{
    m_constraintData = pParam1;
    m_buildJacobianFunc = hkBridgeConstraintAtom_callData;
}

void hkBallSocketChainData::getConstraintInfo(hkConstraintData::ConstraintInfo& rParam1) const
{
}

void hkBallSocketChainData::getRuntimeInfo(hkBool sParam1,
                                           hkConstraintData::RuntimeInfo& rParam2) const
{
    if (sParam1) {
        rParam2.m_numSolverResults = m_infos.getSize() * 3;
        rParam2.m_size = rParam2.m_numSolverResults * 8;
    } else {
        rParam2.m_numSolverResults = 0;
        rParam2.m_size = 0;
    }
}

void hkBallSocketChainData::buildJacobian(const hkConstraintQueryIn& rParam1,
                                          hkConstraintQueryOut& rParam2)
{
}

void hkSimpleContactConstraintData::allocateContactPoint(hkConstraintOwner& rParam1,
                                                         hkContactPoint** pParam2,
                                                         hkContactPointProperties** pParam3)
{
}

void hkSimpleContactConstraintData::freeContactPoint(hkConstraintOwner& rParam1, u16 u16Param2)
{
}

hkSimpleContactConstraintData::hkSimpleContactConstraintData(hkConstraintInstance* pParam1)
{
}

void hkSimpleContactConstraintData::getConstraintInfo(
    hkConstraintData::ConstraintInfo& rParam1) const
{
}

void hkSimpleContactConstraintData::getRuntimeInfo(hkBool sParam1,
                                                   hkConstraintData::RuntimeInfo& rParam2) const
{
    rParam2.m_size = 0;
    rParam2.m_numSolverResults = 0;
}

hkSolverResults* hkSimpleContactConstraintData::getSolverResults(void* pvParam1)
{
    return NULL;
}

void hkSimpleContactConstraintData::collisionResponseBeginCallback(
    const hkContactPoint& rParam1,
    hkSimpleConstraintInfoInitInput& rParam2,
    hkBodyVelocity& rParam3,
    hkSimpleConstraintInfoInitInput& rParam4,
    hkBodyVelocity& rParam5)
{
}

void hkSimpleContactConstraintData::collisionResponseEndCallback(
    const hkContactPoint& rParam1,
    f32 f32Param2,
    hkSimpleConstraintInfoInitInput& rParam3,
    hkBodyVelocity& rParam4,
    hkSimpleConstraintInfoInitInput& rParam5,
    hkBodyVelocity& rParam6)
{
}

hkBool hkSimpleContactConstraintData::isValid() const
{
    return hkBool();
}

s32 hkSimpleContactConstraintData::getType() const
{
    return 0;
}

hkThreadMemory::hkThreadMemory(hkMemory* pParam1, s32 s32Param2)
{
}

void hkThreadMemory::releaseCachedMemory()
{
}

hkThreadMemory::~hkThreadMemory()
{
}

void hkThreadMemory::removeReference()
{
}

void hkThreadMemory::addReference()
{
}

void hkThreadMemory::onRowEmpty(s32 s32Param1)
{
}

void hkThreadMemory::onRowFull(s32 s32Param1, s32 s32Param2)
{
    s32 s32ElementSize = m_row_to_size_lut[s32Param1];
    s32 s32NumElements;
    FreeList* pFreeList = &m_free_list[s32Param1];
    s32NumElements = pFreeList->m_numElem;
    s32 s32TargetElements = s32Param2 ? 0 : m_maxNumElemsOnFreeList / 2;

    while (s32TargetElements < s32NumElements) {
        s32 s32NumToFree = s32NumElements - s32TargetElements;
        if (s32NumToFree > 4) {
            s32NumToFree = 4;
        }

        void* apvBlocks[4];
        for (s32 s32Index = 0; s32Index < s32NumToFree; ++s32Index) {
            apvBlocks[s32Index] = pFreeList->pop();
        }

        s32NumElements -= s32NumToFree;
        m_memory->deallocateChunkBatch(apvBlocks, s32NumToFree, s32ElementSize);
    }
}

void* hkThreadMemory::allocate(s32 s32Param1, HK_MEMORY_CLASS sParam2)
{
    return NULL;
}

void hkThreadMemory::deallocate(void* pvParam1)
{
}

void* hkThreadMemory::alignedAllocate(s32 s32Param1, s32 s32Param2, HK_MEMORY_CLASS sParam3)
{
    return NULL;
}

void hkThreadMemory::alignedDeallocate(void* pvParam1)
{
}

void* hkThreadMemory::allocateChunk(s32 s32Param1, HK_MEMORY_CLASS sParam2)
{
    return NULL;
}

void hkThreadMemory::deallocateChunk(void* pvParam1, s32 s32Param2, HK_MEMORY_CLASS sParam3)
{
    if (pvParam1 == NULL) {
        return;
    }

    if (s32Param2 < 0x2001 && m_maxNumElemsOnFreeList != 0) {
        s32 s32Row;
        if (s32Param2 < 0x201) {
            s32Row = m_small_size_to_row_lut[s32Param2];
        } else {
            s32Row = m_large_size_to_row_lut[(s32Param2 - 1) >> 10];
        }

        s32* ps32NumElements = &m_free_list[s32Row].m_numElem;
        if (*ps32NumElements >= m_maxNumElemsOnFreeList) {
            onRowFull(s32Row, 0);
        }

        ++*ps32NumElements;
        static_cast<FreeElem*>(pvParam1)->m_next = m_free_list[s32Row].m_head;
        m_free_list[s32Row].m_head = static_cast<FreeElem*>(pvParam1);
    } else {
        m_memory->deallocateChunk(pvParam1, s32Param2, sParam3);
    }
}

void* hkThreadMemory::onStackOverflow(s32 s32Param1)
{
    return NULL;
}

void hkThreadMemory::onStackUnderflow(void* pvParam1)
{
}

void hkThreadMemory::setStackArea(void* pvParam1, s32 s32Param2)
{
}

void hkThreadMemory::replaceInstance(hkThreadMemory* pParam1)
{
}

void hkThreadMemory::init()
{
}

void hkThreadMemory::quit()
{
}
