#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

hkThreadMemory* hkThreadMemory::s_threadMemoryInstance;
hkMemory* hkMemory::s_instance;
u8 hkMeshShape::Members[140];

// No-DWARF static member definitions
hkFakeRigidBodyDeactivator hkFakeRigidBodyDeactivator::m_fakeRigidBodyDeactivator;
hkMonitorStream hkMonitorStream::m_instance;
u8 hkWeldingUtility::m_sinCosTable[744];
c8 hkString::s_emptyStringRep[13];
u32 hkCollideTriangleUtil::maskToIndex[16];
u8 hkCollideTriangleUtil::vertexToEdgeLut[5];

clsPfHavokHeap::clsPfHavokHeap(u32 u32AllocateSizeI)
{
}

void* clsPfHavokHeap::HavokSystemMalloc(s32 size, s32 align)
{
    return NULL;
}

void clsPfHavokHeap::HavokSystemFree(void* p)
{
}

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

hkWorldObject::hkWorldObject(hkFinishLoadedObjectFlag sParam1)
{
}

hkWorldObject::hkWorldObject(const hkShape* pParam1, BroadPhaseType sParam2)
{
}

void hkWorldObject::setShape(const hkShape* pParam1)
{
}

void hkWorldObject::addProperty(u32 u32Param1, hkPropertyValue sParam2)
{
}

void hkWorldObject::removeProperty(u32 u32Param1)
{
}

void hkWorldObject::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

void hkWorldObject::addReference()
{
}

void hkWorldObject::removeReference()
{
}

void hkWorldObject::addReferenceAsCriticalOperation()
{
}

hkEntity::hkEntity(const hkShape* pParam1) : m_motion(hkFinishLoadedObjectFlag())
{
}

hkEntity::hkEntity(hkFinishLoadedObjectFlag sParam1) : m_motion(sParam1)
{
}

void hkEntity::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

hkEntity::~hkEntity()
{
}

void hkEntity::setDeactivator(hkEntityDeactivator* pParam1)
{
}

void hkEntity::addEntityListener(hkEntityListener* pParam1)
{
}

void hkEntity::removeEntityListener(hkEntityListener* pParam1)
{
}

void hkEntity::addCollisionListener(hkCollisionListener* pParam1)
{
}

u8 hkEntity::isActive() const
{
    return 0;
}

void hkEntity::activate()
{
}

void hkEntity::deactivate()
{
}

void hkEntity::deallocateInternalArrays()
{
}

void hkPhantom::firePhantomDeleted()
{
}

void hkPhantom::firePhantomRemoved()
{
}

void hkPhantom::firePhantomAdded()
{
}

void hkPhantom::firePhantomShapeSet()
{
}

void hkPhantom::updateBroadPhase(const hkAabb& rParam1)
{
}

void hkPhantom::addPhantomListener(hkPhantomListener* pParam1)
{
}

void hkPhantom::removePhantomListener(hkPhantomListener* pParam1)
{
}

void hkPhantom::addPhantomOverlapListener(hkPhantomOverlapListener* pParam1)
{
}

void hkPhantom::removePhantomOverlapListener(hkPhantomOverlapListener* pParam1)
{
}

hkPhantom::~hkPhantom()
{
}

void hkPhantom::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

void hkPhantom::deallocateInternalArrays()
{
}

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

void hkWorld::removeEntity(hkEntity* pParam1)
{
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

void hkWorld::removeConstraint(hkConstraintInstance* pParam1)
{
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
}

void hkWorld::queueOperation(const hkWorldOperation::BaseOperation& rParam1)
{
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

void hkRigidBody::updateCachedShapeInfo(const hkShape* pParam1, hkVector4& rParam2)
{
}

void hkRigidBody::createDynamicRigidMotion(hkMotion::MotionType sParam1,
                                           const hkVector4& rParam2,
                                           const hkQuaternion& rParam3,
                                           f32 f32Param4,
                                           const hkMatrix3& rParam5,
                                           const hkVector4& rParam6,
                                           f32 f32Param7,
                                           f32 f32Param8,
                                           hkMaxSizeMotion* pParam9)
{
}

hkRigidBody::hkRigidBody(const hkRigidBodyCinfo& rParam1) : hkEntity(rParam1.m_shape)
{
}

hkRigidBody::~hkRigidBody()
{
}

void* hkRigidBody::getMotionState()
{
    return 0;
}

hkRigidBody* hkRigidBody::clone() const
{
    return 0;
}

void hkRigidBody::setShape(const hkShape* pParam1)
{
}

void hkRigidBody::getCinfo(hkRigidBodyCinfo& rParam1) const
{
}

void hkRigidBody::setDeactivator(hkRigidBodyDeactivator* pParam1)
{
}

void hkRigidBody::setMotionType(hkMotion::MotionType sParam1,
                                hkEntityActivation sParam2,
                                hkUpdateCollisionFilterOnEntityMode sParam3)
{
}

void hkRigidBody::setCenterOfMassLocal(const hkVector4& rParam1)
{
}

void hkRigidBody::setDeactivator(hkRigidBodyDeactivator::DeactivatorType sParam1)
{
}

void hkRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody(hkEntity* pParam1)
{
}

void hkRigidBody::setPosition(const hkVector4& rParam1)
{
}

void hkRigidBody::setRotation(const hkQuaternion& rParam1)
{
}

void hkRigidBody::setPositionAndRotation(const hkVector4& rParam1, const hkQuaternion& rParam2)
{
}

void hkRigidBody::setTransform(const hkTransform& rParam1)
{
}

void hkRigidBody::setMass(f32 f32Param1)
{
}

void hkRigidBody::setAngularVelocity(const hkVector4& rParam1)
{
}

const hkVector4& hkRigidBody::getLinearVelocity() const
{
    static hkVector4 sVelocity;
    return sVelocity;
}

void hkRigidBody::setLinearVelocity(const hkVector4& rParam1)
{
}

const hkQuaternion& hkRigidBody::getRotation() const
{
    static hkQuaternion sRotation;
    return sRotation;
}

hkShapePhantom::hkShapePhantom(const hkShape* pParam1, const hkTransform& rParam2)
{
}

hkShapePhantom::~hkShapePhantom()
{
}

void* hkShapePhantom::getMotionState()
{
    return &m_motionState;
}

void hkShapePhantom::setTransform(const hkTransform& rParam1)
{
}

void hkShapePhantom::setPosition(const hkVector4& rParam1, f32 f32Param2)
{
}

void hkShapePhantom::calcAabb(hkAabb& rParam1)
{
}

void hkShapePhantom::deallocateInternalArrays()
{
}

void hkShapePhantom::setShape(const hkShape* pParam1)
{
}

const hkTransform* hkShapePhantom::getTransform() const
{
    return &m_motionState.m_transform;
}

hkSimpleShapePhantom::hkSimpleShapePhantom(const hkShape* pParam1,
                                           const hkTransform& rParam2,
                                           u32 u32Param3)
    : hkShapePhantom(pParam1, rParam2)
{
}

hkSimpleShapePhantom::~hkSimpleShapePhantom()
{
}

s32 hkSimpleShapePhantom::getType() const
{
    return 0;
}

hkSimpleShapePhantom* hkSimpleShapePhantom::clone() const
{
    return 0;
}

void hkSimpleShapePhantom::setPositionAndLinearCast(const hkVector4& rParam1,
                                                    const hkLinearCastInput& rParam2,
                                                    hkCdPointCollector& rParam3,
                                                    hkCdPointCollector* pParam4)
{
}

void hkSimpleShapePhantom::getClosestPoints(hkCdPointCollector& rParam1,
                                            const hkCollisionInput* pParam2)
{
}

void hkSimpleShapePhantom::getPenetrations(hkCdBodyPairCollector& rParam1,
                                           const hkCollisionInput* pParam2)
{
}

u8 hkSimpleShapePhantom::isOverlappingCollidableAdded(hkCollidable* pParam1)
{
    return 0;
}

void hkSimpleShapePhantom::addOverlappingCollidable(hkCollidable* pParam1)
{
}

void hkSimpleShapePhantom::removeOverlappingCollidable(hkCollidable* pParam1)
{
}

void hkSimpleShapePhantom::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

void hkSimpleShapePhantom::deallocateInternalArrays()
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

hkWorldOperationQueue::hkWorldOperationQueue(hkWorld* pParam1)
{
}

hkWorldOperationQueue::~hkWorldOperationQueue()
{
}

void hkWorldOperationQueue::queueOperation(const hkWorldOperation::BaseOperation& rParam1)
{
}

void hkWorldOperationQueue::executeAllPending()
{
}

hkBroadPhaseBorder::hkBroadPhaseBorder(hkWorld* pParam1,
                                       hkWorldCinfo::BroadPhaseBorderBehaviour sParam2)
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

hkRigidBodyCinfo::hkRigidBodyCinfo()
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

hkBroadPhaseBorder::~hkBroadPhaseBorder()
{
}

void hkBroadPhaseBorder::collidableAddedCallback(const hkCollidableAddedEvent& rParam1)
{
}

void hkBroadPhaseBorder::collidableRemovedCallback(const hkCollidableRemovedEvent& rParam1)
{
}

void hkBroadPhaseBorder::maxPositionExceededCallback(hkEntity* pParam1)
{
}

void hkBroadPhaseBorder::worldDeletedCallback(hkWorld* pParam1)
{
}

void hkBroadPhaseBorder::deactivate()
{
}

void hkBroadPhaseBorderListener::addCollisionPair(hkTypedBroadPhaseHandlePair& rParam1)
{
}

void hkBroadPhaseBorderListener::removeCollisionPair(hkTypedBroadPhaseHandlePair& rParam1)
{
}

void hkPhantomBroadPhaseListener::addCollisionPair(hkTypedBroadPhaseHandlePair& rParam1)
{
}

void hkPhantomBroadPhaseListener::removeCollisionPair(hkTypedBroadPhaseHandlePair& rParam1)
{
}

hkEntityEntityBroadPhaseListener::hkEntityEntityBroadPhaseListener(hkWorld* pParam1)
{
}

void hkEntityEntityBroadPhaseListener::addCollisionPair(hkTypedBroadPhaseHandlePair& rParam1)
{
}

void hkEntityEntityBroadPhaseListener::removeCollisionPair(hkTypedBroadPhaseHandlePair& rParam1)
{
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
    return 0;
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
    return 0;
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
    return 0;
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
    return 0;
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

hkVector4 hk3AxisSweep::MaxVal;

hkBroadPhase*

hk3AxisSweep16CreateBroadPhase(const hkVector4& rParam1, const hkVector4& rParam2, s32 s32Param3)

{
    return 0;
}

hkVector4 hkMoppDefaultAssembler::m_directions[26];

hkMoppCodeGenerator::hkMoppCodeGenerator(s32 s32Param1)
{
}

hkMoppCodeGenerator::~hkMoppCodeGenerator()
{
}

void hkMoppCodeGenerator::resize()
{
}

void hkMoppCodeGenerator::compileCode()
{
}

void hkMoppDefaultAssembler::updateParams(const hkMoppAssembler::hkMoppAssemblerParams& rParam1)
{
}

hkMoppDefaultAssembler::hkMoppDefaultAssembler(
    const hkMoppAssembler::hkMoppAssemblerParams& rParam1,
    hkMoppCodeGenerator* pParam2,
    hkMoppMediator* pParam3)
    : hkMoppAssembler()
{
}

hkMoppDefaultAssembler::~hkMoppDefaultAssembler()
{
}

void hkMoppDefaultAssembler::releaseNode(hkMoppTreeNode* pParam1)
{
}

s32 hkMoppDefaultAssembler::shouldAssemble(hkMoppTreeNode* pParam1,
                                           const hkMoppAssemblerNodeInfo& rParam2)
{
    return 0;
}

void hkMoppDefaultAssembler::calcRescaleBits(const hkMoppAssemblerNodeInfo& rParam1,
                                             hkMoppAssemblerNodeInfo& rParam2)
{
}

void hkMoppDefaultAssembler::recalcRescale(const hkMoppAssemblerNodeInfo& rParam1,
                                           hkMoppAssemblerNodeInfo& rParam2,
                                           hkMoppAssemblerRescaleCommand& rParam3)
{
}

void hkMoppDefaultAssembler::preCalcScale(hkMoppTreeNode* pParam1,
                                          const hkMoppAssemblerNodeInfo& rParam2,
                                          hkMoppAssemblerNodeInfo& rParam3)
{
}

void hkMoppDefaultAssembler::fixScale(hkMoppTreeNode* pParam1)
{
}

void hkMoppDefaultAssembler::calcTermCut(hkMoppTreeNode* pParam1, hkMoppAssemblerCutInfo& rParam2)
{
}

void hkMoppDefaultAssembler::preCalcCutPositions(hkMoppTreeNode* pParam1,
                                                 const hkMoppAssemblerCutInfo& rParam2,
                                                 hkMoppAssemblerCutInfo& rParam3)
{
}

void hkMoppDefaultAssembler::initTopDown(hkMoppTreeNode* pParam1,
                                         const hkMoppAssemblerNodeInfo& rParam2,
                                         hkMoppAssemblerNodeInfo& rParam3,
                                         hkMoppAssemblerRescaleCommand& rParam4)
{
}

void hkMoppDefaultAssembler::assemblesubNode(hkMoppTreeNode* pParam1,
                                             const hkMoppAssemblerNodeInfo& rParam2,
                                             hkMoppAssemblerNodeInfo& rParam3)
{
}

void hkMoppDefaultAssembler::calcChunkPoints(hkMoppTreeNode* pParam1,
                                             const hkMoppAssemblerNodeInfo& rParam2,
                                             hkMoppAssemblerNodeInfo& rParam3,
                                             hkArray<u32>& rParam4)
{
}

void hkMoppDefaultAssembler::calcTerminalIdsForChunks(hkMoppTreeNode* pParam1,
                                                      s32 s32Param2,
                                                      s32 s32Param3)
{
}

void hkMoppDefaultAssembler::assembleSubNodeIntoChunks(hkMoppTreeNode* pParam1,
                                                       const hkMoppAssemblerNodeInfo& rParam2,
                                                       hkMoppAssemblerNodeInfo& rParam3,
                                                       s32 s32Param4,
                                                       hkArray<u32>& rParam5)
{
}

void hkMoppDefaultAssembler::calcReoffset(hkMoppTreeNode* pParam1,
                                          const hkMoppAssemblerNodeInfo& rParam2,
                                          hkMoppAssemblerNodeInfo& rParam3)
{
}

void hkMoppDefaultAssembler::addProperty(s32 s32Param1, s32 s32Param2)
{
}

void hkMoppDefaultAssembler::addJumpChunk(s32 s32Param1)
{
}

void hkMoppDefaultAssembler::addDataOffset(s32 s32Param1, s32 s32Param2)
{
}

void hkMoppDefaultAssembler::addRescale(const hkMoppAssemblerRescaleCommand& rParam1)
{
}

void hkMoppDefaultAssembler::addTermIdOffset(u32 u32Param1)
{
}

void hkMoppDefaultAssembler::addCut(const hkMoppTreeNode* pParam1,
                                    const hkMoppAssemblerNodeInfo& rParam2)
{
}

void hkMoppDefaultAssembler::addSplit(
    s32 s32Param1, s32 s32Param2, HK_MOPP_SPLIT_DIRECTIONS eParam3, s32 s32Param4, s32 s32Param5)
{
}

void hkMoppDefaultAssembler::checkAndAddProperties(hkMoppTreeNode* pParam1,
                                                   const hkMoppAssemblerNodeInfo& rParam2,
                                                   hkMoppAssemblerNodeInfo& rParam3)
{
}

void hkMoppDefaultAssembler::addTerminals(hkMoppTreeTerminal* pParam1,
                                          const hkMoppAssemblerNodeInfo& rParam2,
                                          const hkMoppAssemblerNodeInfo& rParam3)
{
}

void hkMoppDefaultAssembler::addJump(u32 u32Param1)
{
}

s32 hkMoppDefaultAssembler::getSplitCode(const hkVector4& rParam1)
{
    return 0;
}

void hkMoppDefaultAssembler::findPlanes(const hkMoppTreeInternalNode* pParam1,
                                        const hkMoppAssemblerNodeInfo& rParam2,
                                        s32& rParam3,
                                        s32& rParam4)
{
}

void hkMoppDefaultAssembler::getScaleInfo(hkMoppTreeNode* pParam1, hkMoppCode::CodeInfo* pParam2)
{
}

void hkMoppDefaultAssembler::assembleCutAndTerminalCommand(hkMoppTreeNode* pParam1,
                                                           const hkMoppAssemblerNodeInfo& rParam2,
                                                           hkMoppAssemblerNodeInfo& rParam3)
{
}

void hkMoppDefaultAssembler::assembleNonTerminalCommand(hkMoppTreeNode* pParam1,
                                                        const hkMoppAssemblerNodeInfo& rParam2,
                                                        hkMoppAssemblerNodeInfo& rParam3,
                                                        hkMoppAssemblerRescaleCommand& rParam4)
{
}

void hkMoppDefaultAssembler::assembleJumpChunkCommand(hkMoppTreeNode* pParam1)
{
}

void hkMoppDefaultAssembler::assemble(hkMoppTreeNode* pParam1,
                                      hkMoppNodeMgr* pParam2,
                                      s32 s32Param3)
{
}

s32 hkMoppDefaultAssembler::getNumSplittingPlaneDirections() const
{
    return 0;
}

const hkVector4* hkMoppDefaultAssembler::getSplittingPlaneDirections() const
{
    return m_directions;
}

s32 hk3AxisSweep::getType() const
{
    return 0;
}

void hk3AxisSweep::convertAabbToInt(const hkAabb& rParam1, hkBroadPhase::hkBpAabb& rParam2) const
{
}

void hk3AxisSweep::beginOverlap(hkBpNode& rParam1,
                                hkBpNode& rParam2,
                                hkArray<hkBroadPhaseHandlePair>& rParam3)
{
}

void hk3AxisSweep::endOverlap(hkBpNode& rParam1,
                              hkBpNode& rParam2,
                              hkArray<hkBroadPhaseHandlePair>& rParam3)
{
}

void hk3AxisSweep::beginOverlapCheckMarker(hkBpMarker* pParam1,
                                           hkBpNode& rParam2,
                                           s32 s32Param3,
                                           hkBpNode& rParam4,
                                           hkArray<hkBroadPhaseHandlePair>& rParam5)
{
}

void hk3AxisSweep::endOverlapCheckMarker(hkBpMarker* pParam1,
                                         hkBpNode& rParam2,
                                         s32 s32Param3,
                                         hkBpNode& rParam4,
                                         hkArray<hkBroadPhaseHandlePair>& rParam5)
{
}

void hk3AxisSweep::updateAabbs(hkBroadPhaseHandle** pParam1,
                               const hkAabb* pParam2,
                               s32 s32Param3,
                               hkArray<hkBroadPhaseHandlePair>& rParam4,
                               hkArray<hkBroadPhaseHandlePair>& rParam5)
{
}

hk3AxisSweep::hk3AxisSweep(const hkVector4& rParam1, const hkVector4& rParam2, s32 s32Param3)
    : hkBroadPhase()
{
}

hk3AxisSweep::~hk3AxisSweep()
{
}

void hk3AxisSweep::hkBpAxis::mergeBatch(
    hkBpNode* pParam1, s32 s32Param2, s32 s32Param3, s32 s32Param4, hkBpEndPoint* pParam5)
{
}

void hk3AxisSweep::hkBpAxis::removeBatch(hkBpNode* pParam1,
                                         s32 s32Param2,
                                         const hkFixedArray<s32>& rParam3)
{
}

void hk3AxisSweep::hkBpAxis::insert(
    hkBpNode* pParam1, s32 s32Param2, u16 u16Param3, u16 u16Param4, u16& rParam5, u16& rParam6)
{
}

void hk3AxisSweep::hkBpAxis::remove(s32 s32Param1, s32 s32Param2)
{
}

void hk3AxisSweep::updateNodesAfterInsert(hkBpNode* pParam1, s32 s32Param2, hkBpNode& rParam3)
{
}

void hk3AxisSweep::updateNodesAfterDelete(hkBpNode* pParam1, s32 s32Param2, hkBpNode& rParam3)
{
}

void hk3AxisSweep::setBitsBasedOnXInterval(
    s32 s32Param1, s32 s32Param2, const hkBpNode& rParam3, u16 u16Param4, u32* pParam5) const
{
}

void hk3AxisSweep::reQuerySingleObject(const hkBroadPhaseHandle* pParam1,
                                       hkArray<hkBroadPhaseHandlePair>& rParam2) const
{
}

void hk3AxisSweep::addObject(hkBroadPhaseHandle* pParam1,
                             const hkAabb& rParam2,
                             hkArray<hkBroadPhaseHandlePair>& rParam3)
{
}

void hk3AxisSweep::removeObject(hkBroadPhaseHandle* pParam1,
                                hkArray<hkBroadPhaseHandlePair>& rParam2)
{
}

void hk3AxisSweep::addObjectBatch(hkArray<hkBroadPhaseHandle*>& rParam1,
                                  hkArray<hkAabb>& rParam2,
                                  hkArray<hkBroadPhaseHandlePair>& rParam3)
{
}

void hk3AxisSweep::removeObjectBatch(hkArray<hkBroadPhaseHandle*>& rParam1,
                                     hkArray<hkBroadPhaseHandlePair>& rParam2)
{
}

s32 hk3AxisSweep::getNumObjects()
{
    return 0;
}

void hk3AxisSweep::getAllAabbs(hkArray<hkAabb>& rParam1)
{
}

void hk3AxisSweep::getAabb(const hkBroadPhaseHandle* pParam1, hkAabb& rParam2) const
{
}

void hk3AxisSweep::getExtents(hkVector4& rParam1, hkVector4& rParam2) const
{
}

hk3AxisSweep::hkBpEndPoint* hk3AxisSweep::hkBpAxis::find(const hkBpEndPoint* pParam1,
                                                         const hkBpEndPoint* pParam2,
                                                         u16 u16Param3) const
{
    return 0;
}

void hk3AxisSweep::queryBatchAabbSub(u32* pParam1,
                                     hkArray<hkBroadPhaseHandlePair>& rParam2,
                                     hkBool sParam3) const
{
}

void hk3AxisSweep::querySingleAabb(const hkAabb& rParam1,
                                   hkArray<hkBroadPhaseHandlePair>& rParam2) const
{
}

s32 hk3AxisSweep::getAabbCacheSize() const
{
    return 0;
}

void hk3AxisSweep::calcAabbCache(const hkAabb& rParam1, c8* pParam2) const
{
}

void hk3AxisSweep::calcAabbCache(const hkArray<hkCollidable*>& rParam1, c8* pParam2) const
{
}

void hk3AxisSweep::calcAabbCacheInternal(const hkArray<const hkBpNode*>& rParam1, c8* pParam2) const
{
}

void hk3AxisSweep::defragment()
{
}

void hk3AxisSweep::castRay(const hkBroadPhase::hkCastRayInput& rParam1,
                           hkBroadPhaseCastCollector* pParam2,
                           s32 s32Param3) const
{
}

void hk3AxisSweep::castAabb(const hkBroadPhase::hkCastAabbInput& rParam1,
                            hkBroadPhaseCastCollector& rParam2) const
{
}

void hk3AxisSweep::getAabbFromNode(const hkBpNode& rParam1, hkAabb& rParam2) const
{
}

void hk3AxisSweep::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

void hk3AxisSweep::shiftAllObjects(const hkVector4& rParam1,
                                   hkVector4& rParam2,
                                   hkArray<hkBroadPhaseHandle*>& rParam3)
{
}

void hk3AxisSweep::shiftBroadPhase(const hkVector4& rParam1,
                                   hkVector4& rParam2,
                                   hkArray<hkBroadPhaseHandle*>& rParam3)
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
}

hkSimulationIsland::hkSimulationIsland(hkWorld* pParam1)
{
}

hkSimulationIsland::~hkSimulationIsland()
{
}

void hkSimulationIsland::internalAddEntity(hkEntity* pParam1)
{
}

void hkSimulationIsland::internalRemoveEntity(hkEntity* pParam1)
{
}

void hkSimulationIsland::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

void hkSimulationIsland::addAction(hkAction* pParam1)
{
}

void hkSimulationIsland::removeAction(hkAction* pParam1)
{
}

hkBool hkSimulationIsland::isFullyConnected(hkUnionFind& rParam1)
{
    return hkBool();
}

hkBool hkSimulationIsland::shouldDeactivateDeprecated(const hkStepInfo& rParam1)
{
    return hkBool();
}

void hkSimulationIsland::addConstraintToCriticalLockedIsland(hkConstraintInstance* pParam1)
{
}

void hkSimulationIsland::removeConstraintFromCriticalLockedIsland(hkConstraintInstance* pParam1)
{
}

void hkSimulationIsland::addCallbackRequest(hkConstraintInstance* pParam1, s32 s32Param2)
{
}

void hkSimulationIsland::mergeConstraintInfo(hkSimulationIsland& rParam1)
{
}

hkMotion::hkMotion(const hkVector4& rParam1, const hkQuaternion& rParam2, bool bParam3)
{
}

void hkMotion::setMass(f32 f32Param1)
{
}

f32 hkMotion::getMass() const
{
    return 0.0f;
}

void hkMotion::setMassInv(f32 f32Param1)
{
}

void hkMotion::setCenterOfMassInLocal(const hkVector4& rParam1)
{
}

void hkMotion::setPosition(const hkVector4& rParam1)
{
}

void hkMotion::setRotation(const hkQuaternion& rParam1)
{
}

void hkMotion::setPositionAndRotation(const hkVector4& rParam1, const hkQuaternion& rParam2)
{
}

void hkMotion::setTransform(const hkTransform& rParam1)
{
}

void hkMotion::setLinearVelocity(const hkVector4& rParam1)
{
}

void hkMotion::setAngularVelocity(const hkVector4& rParam1)
{
}

void hkMotion::applyLinearImpulse(const hkVector4& rParam1)
{
}

void hkMotion::getMotionStateAndVelocitiesAndDeactivationType(hkMotion* pParam1)
{
}

void hkMotion::setDeactivationClass(s32 s32Param1)
{
}

hkKeyframedRigidMotion::hkKeyframedRigidMotion(const hkVector4& rParam1,
                                               const hkQuaternion& rParam2)
    : hkMotion(rParam1, rParam2, false)
{
}

hkKeyframedRigidMotion::~hkKeyframedRigidMotion()
{
}

void hkKeyframedRigidMotion::setMass(f32 f32Param1)
{
}

void hkKeyframedRigidMotion::setMassInv(f32 f32Param1)
{
}

void hkKeyframedRigidMotion::getInertiaLocal(hkMatrix3& rParam1) const
{
}

void hkKeyframedRigidMotion::getInertiaWorld(hkMatrix3& rParam1) const
{
}

void hkKeyframedRigidMotion::setInertiaLocal(const hkMatrix3& rParam1)
{
}

void hkKeyframedRigidMotion::setInertiaInvLocal(const hkMatrix3& rParam1)
{
}

void hkKeyframedRigidMotion::getInertiaInvLocal(hkMatrix3& rParam1) const
{
}

void hkKeyframedRigidMotion::getInertiaInvWorld(hkMatrix3& rParam1) const
{
}

void hkKeyframedRigidMotion::applyLinearImpulse(const hkVector4& rParam1)
{
}

void hkKeyframedRigidMotion::applyPointImpulse(const hkVector4& rParam1, const hkVector4& rParam2)
{
}

void hkKeyframedRigidMotion::applyAngularImpulse(const hkVector4& rParam1)
{
}

void hkKeyframedRigidMotion::applyForce(f32 f32Param1, const hkVector4& rParam2)
{
}

void hkKeyframedRigidMotion::applyForce(f32 f32Param1,
                                        const hkVector4& rParam2,
                                        const hkVector4& rParam3)
{
}

void hkKeyframedRigidMotion::applyTorque(f32 f32Param1, const hkVector4& rParam2)
{
}

void hkKeyframedRigidMotion::setStepPosition(f32 f32Param1, f32 f32Param2)
{
}

void hkKeyframedRigidMotion::setStoredMotion(hkMaxSizeMotion* pParam1)
{
}

f32 hkKeyframedRigidMotion::getWeight() const
{
    return 0.0f;
}

void hkBridgeConstraintAtom::init(hkConstraintData* pParam1)
{
}

void hkConstraintData::addInstance(hkConstraintInstance* pParam1,
                                   void* pvParam2,
                                   s32 s32Param3) const
{
}

hkSolverResults* hkConstraintData::getSolverResults(void* pvParam1)
{
    return 0;
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
    return 0;
}

void hkConstraintChainInstanceAction::entityRemovedCallback(hkEntity* pParam1)
{
}

void hkConstraintChainInstanceAction::getEntities(hkArray<hkEntity*>& rParam1)
{
}

hkBallSocketChainData::hkBallSocketChainData()
{
}

hkBallSocketChainData::~hkBallSocketChainData()
{
}

s32 hkBallSocketChainData::getType() const
{
    return 0;
}

void hkBallSocketChainData::addConstraintInfoInBodySpace(const hkVector4& rParam1,
                                                         const hkVector4& rParam2)
{
}

void hkBallSocketChainData::getConstraintInfo(hkConstraintData::ConstraintInfo& rParam1) const
{
}

void hkBallSocketChainData::getRuntimeInfo(hkBool sParam1,
                                           hkConstraintData::RuntimeInfo& rParam2) const
{
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
}

hkSolverResults* hkSimpleContactConstraintData::getSolverResults(void* pvParam1)
{
    return 0;
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
}

void* hkThreadMemory::allocate(s32 s32Param1, HK_MEMORY_CLASS sParam2)
{
    return 0;
}

void hkThreadMemory::deallocate(void* pvParam1)
{
}

void* hkThreadMemory::alignedAllocate(s32 s32Param1, s32 s32Param2, HK_MEMORY_CLASS sParam3)
{
    return 0;
}

void hkThreadMemory::alignedDeallocate(void* pvParam1)
{
}

void* hkThreadMemory::allocateChunk(s32 s32Param1, HK_MEMORY_CLASS sParam2)
{
    return 0;
}

void hkThreadMemory::deallocateChunk(void* pvParam1, s32 s32Param2, HK_MEMORY_CLASS sParam3)
{
}

void* hkThreadMemory::onStackOverflow(s32 s32Param1)
{
    return 0;
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

hkAabbPhantom::hkAabbPhantom(const hkAabb& rParam1, u32 u32Param2)
{
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
    return 0;
}

void hkAabbPhantom::calcAabb(hkAabb& rParam1)
{
}

void hkAabbPhantom::setAabb(const hkAabb& rParam1)
{
}

hkBool hkAabbPhantom::isOverlappingCollidableAdded(hkCollidable* pParam1)
{
    return hkBool();
}

void hkAabbPhantom::addOverlappingCollidable(hkCollidable* pParam1)
{
}

void hkAabbPhantom::removeOverlappingCollidable(hkCollidable* pParam1)
{
}

void hkAabbPhantom::calcStatistics(hkStatisticsCollector* pParam1) const
{
}

void hkAabbPhantom::deallocateInternalArrays()
{
}

hkSimulation::hkSimulation(hkWorld* pParam1)
{
}

hkSimulation::~hkSimulation()
{
}

hkStepResult hkSimulation::integrate(f32 f32Param1)
{
    return HK_STEP_RESULT_SUCCESS;
}

hkStepResult hkSimulation::collide()
{
    return HK_STEP_RESULT_SUCCESS;
}

hkStepResult hkSimulation::reCollideAfterStepFailure()
{
    return HK_STEP_RESULT_SUCCESS;
}

f32 hkSimulation::snapSimulateTimeAndGetTimeToAdvanceTo()
{
    return 0.0f;
}

hkStepResult hkSimulation::advanceTime()
{
    return HK_STEP_RESULT_SUCCESS;
}

hkStepResult hkSimulation::stepDeltaTime(f32 f32Param1)
{
    return HK_STEP_RESULT_SUCCESS;
}

hkStepResult
hkSimulation::collideEntitiesBroadPhaseDiscrete(hkEntity** pParam1, s32 s32Param2, hkWorld* pParam3)
{
    return HK_STEP_RESULT_SUCCESS;
}

hkStepResult hkSimulation::collideInternal(const hkStepInfo& rParam1)
{
    return HK_STEP_RESULT_SUCCESS;
}

hkStepResult hkSimulation::integrateInternal(const hkStepInfo& rParam1)
{
    return HK_STEP_RESULT_SUCCESS;
}

void hkSimulation::applyActions()
{
}

void hkSimulation::collideEntitiesDiscrete(hkEntity** pParam1,
                                           s32 s32Param2,
                                           hkWorld* pParam3,
                                           const hkStepInfo& rParam4,
                                           hkSimulation::FindContacts sParam5)
{
}

void hkSimulation::collideEntitiesNarrowPhaseDiscrete(hkEntity** pParam1,
                                                      s32 s32Param2,
                                                      const hkProcessCollisionInput& rParam3,
                                                      hkSimulation::FindContacts sParam4)
{
}

void hkSimulation::processAgentCollideDiscrete(hkAgentNnEntry* pParam1,
                                               const hkProcessCollisionInput& rParam2,
                                               hkProcessCollisionOutput& rParam3)
{
}

void hkSimulation::resetCollisionInformationForEntities(hkEntity** pParam1,
                                                        s32 s32Param2,
                                                        hkWorld* pParam3,
                                                        hkBool sParam4)
{
}

void hkSimulation::processAgentResetCollisionInformation(hkAgentNnEntry* pParam1,
                                                         const hkProcessCollisionInput& rParam2,
                                                         hkProcessCollisionOutput& rParam3)
{
}

void hkSimulation::processAgentsOfEntities(
    hkEntity** pParam1,
    s32 s32Param2,
    const hkProcessCollisionInput& rParam3,
    void (hkSimulation::*pvParam4)(hkAgentNnEntry*,
                                   const hkProcessCollisionInput&,
                                   hkProcessCollisionOutput&),
    hkSimulation::FindContacts sParam5)
{
}

void hkSimulation::reintegrateAndRecollideEntities(hkEntity** pParam1,
                                                   s32 s32Param2,
                                                   hkWorld* pParam3,
                                                   s32 s32Param4)
{
}

void InternalInertiaTensorComputer::compProjectionIntegrals(const hkVector4* psParam1)
{
}

void InternalInertiaTensorComputer::compFaceIntegrals(const hkVector4* psParam1,
                                                      const hkVector4& rsParam2)
{
}

void InternalInertiaTensorComputer::compVolumeIntegrals(const hkGeometry* pcParam1,
                                                        const hkVector4& rsParam2)
{
}

void InternalInertiaTensorComputer::computeInertialTensorInternal(f32 f32Param1,
                                                                  f32 f32Param2,
                                                                  hkVector4& rsParam3,
                                                                  hkMatrix3& rcParam4)
{
}

void InternalInertiaTensorComputer::compGeometryAabb(const hkVector4* psParam1,
                                                     s32 s32Param2,
                                                     hkVector4& rsParam3,
                                                     hkVector4& rsParam4)
{
}
