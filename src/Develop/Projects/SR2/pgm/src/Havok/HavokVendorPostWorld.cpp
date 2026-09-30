#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

// RECONSTRUCTED: source ownership.

hkWorldObject::hkWorldObject(hkFinishLoadedObjectFlag sParam1)
    : m_collidable(sParam1), m_properties(sParam1)
{
    if (sParam1.m_finishing) {
        m_collidable.m_ownerOffset = static_cast<s8>(reinterpret_cast<const c8*>(this) -
                                                     reinterpret_cast<const c8*>(&m_collidable));
    }
}

hkWorldObject::hkWorldObject(const hkShape* pParam1, BroadPhaseType sParam2)
    : m_world(NULL), m_userData(NULL), m_collidable(pParam1, static_cast<s8>(sParam2)), m_name(NULL)
{
    m_collidable.m_ownerOffset = static_cast<s8>(reinterpret_cast<const c8*>(this) -
                                                 reinterpret_cast<const c8*>(&m_collidable));
    if (pParam1 != NULL) {
        pParam1->addReference();
    }
}

bool hkWorldObject::setShape(const hkShape* pParam1)
{
    return true;
}

void hkWorldObject::addProperty(u32 u32Param1, hkPropertyValue sParam2)
{
    for (s32 s32Index = 0; s32Index < m_properties.getSize(); ++s32Index) {
        if (m_properties.m_data[s32Index].m_key == u32Param1) {
            return;
        }
    }

    hkProperty& rProperty = m_properties.expandOne();
    rProperty.m_value = sParam2;
    rProperty.m_key = u32Param1;
}

hkPropertyValue hkWorldObject::removeProperty(u32 u32Param1)
{
    for (s32 s32Index = 0; s32Index < m_properties.getSize(); ++s32Index) {
        if (m_properties.m_data[s32Index].m_key == u32Param1) {
            hkProperty& rProperty = m_properties.m_data[s32Index];
            u_long ulValue = rProperty.m_value.m_data;
            m_properties.removeAtAndCopy(s32Index);
            return hkPropertyValue(ulValue);
        }
    }

    return hkPropertyValue(0);
}

void hkWorldObject::calcStatistics(hkStatisticsCollector* pParam1) const
{
    pParam1->addChildObject("Shape", 1, m_collidable.m_shape);

    if (!(m_collidable.m_collisionEntries.m_capacityAndFlags & 0x80000000)) {
        pParam1->addArray("CollAgtPtr",
                          8,
                          m_collidable.m_collisionEntries.m_data,
                          m_collidable.m_collisionEntries.getSize() * sizeof(CollisionEntry),
                          m_collidable.m_collisionEntries.getCapacity() * sizeof(CollisionEntry));
    }

    if (!(m_properties.m_capacityAndFlags & 0x80000000)) {
        pParam1->addArray("Properties",
                          4,
                          m_properties.m_data,
                          m_properties.getSize() * sizeof(hkProperty),
                          m_properties.getCapacity() * sizeof(hkProperty));
    }
}

void hkWorldObject::addReference()
{
    if (m_memSizeAndFlags != 0) {
        ++m_referenceCount;
    }
}

void hkWorldObject::removeReference()
{
    if (m_memSizeAndFlags != 0) {
        --m_referenceCount;
        if (m_referenceCount == 0) {
            delete this;
        }
    }
}

void hkWorldObject::addReferenceAsCriticalOperation()
{
}

void hkBroadPhaseBorderListener::addCollisionPair(hkTypedBroadPhaseHandlePair& rParam1)
{
}

void hkBroadPhaseBorderListener::removeCollisionPair(hkTypedBroadPhaseHandlePair& rParam1)
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

hkVector4 hk3AxisSweep::MaxVal;

hkBroadPhase* hk3AxisSweep16CreateBroadPhase(const hkVector4& rParam1,
                                             const hkVector4& rParam2,
                                             s32 s32Param3)
{
    return NULL;
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
    return NULL;
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

hkStepResult hkSimulation::collideEntitiesBroadPhaseDiscrete(hkEntity** pParam1,
                                                             s32 s32Param2,
                                                             hkWorld* pParam3)
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

u32 hkVector4Util::packQuaternionIntoInt32(const hkVector4& rQuaternion)
{
    static const f32 magic[4] = {196736.5f, 196736.5f, 196736.5f, 196736.5f};
    static const f32 scale[4] = {
        116.36363220214844f,
        116.36363220214844f,
        116.36363220214844f,
        116.36363220214844f,
    };

    union FloatBits {
        f32 f;
        u32 u;
    };

    FloatBits x;
    FloatBits y;
    FloatBits z;
    FloatBits w;
    x.f = rQuaternion.x * scale[0] + magic[0];
    y.f = rQuaternion.y * scale[1] + magic[1];
    z.f = rQuaternion.z * scale[2] + magic[2];
    w.f = rQuaternion.w * scale[3] + magic[3];

    u32 xy = ((x.u >> 6) & 0xff) | (((y.u >> 6) & 0xff) << 8);
    u32 zw = ((z.u >> 6) & 0xff) | (((w.u >> 6) & 0xff) << 8);
    return xy | (zw << 16);
}

void hkQuaternion::setAxisAngle(const hkVector4& rParam1, f32 f32Param2)
{
}

void hkQuaternion::set(const hkRotation& rParam1)
{
}

void hkMatrix3::transpose()
{
}

void hkMatrix3::setTranspose(const hkMatrix3& rParam1)
{
}

void hkMatrix3::setMul(const hkMatrix3& rParam1, const hkMatrix3& rParam2)
{
}

void hkMatrix3::setMulInverse(const hkMatrix3& rParam1, const hkRotation& rParam2)
{
}

void hkMatrix3::invertSymmetric()
{
}

void hkMatrix3::add(const hkMatrix3& rParam1)
{
}

void hkMatrix3::mul(const hkMatrix3& rParam1)
{
}

void hkMatrix3::mul(f32 f32Param1)
{
}

void hkMatrix3::changeBasis(const hkRotation& rParam1)
{
}

void hkRotation::set(const hkQuaternion& rParam1)
{
}

s32 hkRotation::isOrthonormal(f32 f32Param1) const
{
    return 0;
}

void hkTransform::setInverse(const hkTransform& rParam1)
{
}

void hkTransform::setMul(const hkTransform& rParam1, const hkTransform& rParam2)
{
}

void hkTransform::setMulInverseMul(const hkTransform& rParam1, const hkTransform& rParam2)
{
}

void hkSweptTransform::initSweptTransform(const hkVector4& rParam1, const hkQuaternion& rParam2)
{
}

void hkMotionState::initMotionState(const hkVector4& rParam1, const hkQuaternion& rParam2)
{
}

void* hkBroadPhase::m_defaultCreationFunction;

hkBroadPhase::hkBroadPhase()
{
}

hkBroadPhase::~hkBroadPhase()
{
}

void hkBroadPhase::lockImplementation()
{
}

void hkBroadPhase::unlockImplementation()
{
}

void hkGskCache::initTriangle(const hkConvexShape* pParam1,
                              const hkTriangleShape* pParam2,
                              const hkTransform& rParam3)
{
}

void hkGskCache::init(const hkConvexShape* pParam1,
                      const hkConvexShape* pParam2,
                      const hkTransform& rParam3)
{
}

void hkVector4::setTransformedPos(const hkTransform& rParam1, const hkVector4& rParam2)
{
}

void hkVector4::setTransformedInversePos(const hkTransform& rParam1, const hkVector4& rParam2)
{
}

void hkVector4::setRotatedDir(const hkRotation& rParam1, const hkVector4& rParam2)
{
    const f32 f32X = rParam2.x;
    const f32 f32Y = rParam2.y;
    const f32 f32Z = rParam2.z;
    x = f32X * rParam1.m_col0.x + f32Y * rParam1.m_col1.x + f32Z * rParam1.m_col2.x;
    y = f32X * rParam1.m_col0.y + f32Y * rParam1.m_col1.y + f32Z * rParam1.m_col2.y;
    z = f32X * rParam1.m_col0.z + f32Y * rParam1.m_col1.z + f32Z * rParam1.m_col2.z;
    w = 0.0f;
}

void hkVector4::setRotatedInverseDir(const hkRotation& rParam1, const hkVector4& rParam2)
{
    const f32 f32X = rParam2.x;
    const f32 f32Y = rParam2.y;
    const f32 f32Z = rParam2.z;
    x = f32X * rParam1.m_col0.x + f32Y * rParam1.m_col0.y + f32Z * rParam1.m_col0.z;
    y = f32X * rParam1.m_col1.x + f32Y * rParam1.m_col1.y + f32Z * rParam1.m_col1.z;
    z = f32X * rParam1.m_col2.x + f32Y * rParam1.m_col2.y + f32Z * rParam1.m_col2.z;
    w = 0.0f;
}

hkCharacterProxy::hkCharacterProxy(const hkCharacterProxyCinfo& rParam1)
{
}

void hkCharacterProxy::updateFromCinfo(const hkCharacterProxyCinfo& rParam1)
{
}

hkCharacterProxy::~hkCharacterProxy()
{
}

void hkCharacterProxy::integrateWithCollectors(const hkStepInfo& rParam1,
                                               const hkVector4& rParam2,
                                               hkAllCdPointCollector& rParam3,
                                               hkAllCdPointCollector& rParam4)
{
}

void hkCharacterProxy::moveToLinearCastHitPosition(const hkSimplexSolverOutput& rParam1,
                                                   const hkAllCdPointCollector& rParam2,
                                                   const hkLinearCastInput& rParam3,
                                                   hkVector4& rParam4)
{
}

void hkCharacterProxy::refreshManifold(hkAllCdPointCollector& rParam1)
{
}

void hkCharacterProxy::extractSurfaceConstraintInfo(const hkRootCdPoint& rParam1,
                                                    hkSurfaceConstraintInfo& rParam2,
                                                    f32 f32Param3) const
{
}

void hkCharacterProxy::findSurface(const hkRootCdPoint& rParam1) const
{
}

void hkCharacterProxy::updateManifold(const hkAllCdPointCollector& rParam1,
                                      const hkAllCdPointCollector& rParam2)
{
}

void hkCharacterProxy::applySurfaceInteractions(const hkStepInfo& rParam1, const hkVector4& rParam2)
{
}

const hkVector4& hkCharacterProxy::getPosition() const
{
    static hkVector4 sPosition;
    return sPosition;
}

void hkCharacterProxy::setPosition(const hkVector4& rParam1)
{
}

void hkCharacterProxy::setLinearVelocity(const hkVector4& rParam1)
{
}

hkShapePhantom* hkCharacterProxy::getShapePhantom()
{
    return m_shapePhantom;
}

void hkCharacterProxy::fireConstraintsProcessed(const hkArray<hkRootCdPoint>& rParam1,
                                                hkSimplexSolverInput& rParam2) const
{
}

void hkCharacterProxy::fireContactAdded(const hkRootCdPoint& rParam1) const
{
}

void hkCharacterProxy::fireContactRemoved(const hkRootCdPoint& rParam1) const
{
}

void hkCharacterProxy::entityRemovedCallback(hkEntity* pParam1)
{
}

void hkCharacterProxy::phantomRemovedCallback(hkPhantom* pParam1)
{
}

void hkCharacterProxy::calcStatistics(hkStatisticsCollector* pParam1) const
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
