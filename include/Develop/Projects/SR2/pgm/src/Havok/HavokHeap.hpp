#ifndef HAVOKHEAP_HPP
#define HAVOKHEAP_HPP

#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/hkEnum.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/hkArray.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerMotion.hpp"

class hkEntity;
class hkEntityActivationListener;
class hkEntityDeactivator;
class hkEntityListener;
// total size: 0x4
class hkFinishLoadedObjectFlag {
public:
    s32 m_finishing; // offset 0x0, size 0x4
};
class hkGeometry;
class hkPhantomOverlapListener;
class hkRigidBodyCinfo;
class hkRigidBodyDeactivator {
public:
    enum DeactivatorType { DEACTIVATOR_NEVER = 0 };
};
class hkMatrix3;
class hkMotionState;
class hkAgent3Input;
class hkAgent3ProcessInput;
class hkAgentEntry;
class hkAgentNnEntry;
class hkAction;
class hkBroadPhaseHandlePair;
class hkCdBody;
class hkCdBodyPairCollector;
class hkClassEnum;
class hkClassMember;
class hkCollisionFilter;
class hkCollidableCollidableFilter;
class hkCollisionAgent;
class hkCollisionInput;
class hkConstraintInstance;
class hkConstraintChainInstanceAction;
class hkConstraintData;
class hkConstraintInternal;
class hkModifierConstraintAtom;
class hkConstraintOwner;
class hkContactMgr;
class hkContactMgrFactory;
class hkConvexListFilter;
class hkCdVertex;
class hkLinearCastCollisionInput;
class hkMaxSizeMotion;
class hkMemory;
class hkProcessCollisionInput;
class hkProcessCollisionOutput;
class hkRayHitCollector;
class hkRigidBody;
class hkShape;
class hkShapeContainer;
class hkShapeRayCastOutput;
class hkShapeRayCastInput;
class hkSimulationIsland;
class hkSphere;
class hkTypedBroadPhaseHandlePair;
class hkUnionFind;
class hkWorldMemoryWatchDog;
class hkSpuCollisionCallbackUtil;
class hkBroadPhase;
class hkBroadPhaseBorder;
class hkBroadPhaseBorderListener;
class hkCollisionDispatcher;
class hkCriticalSection;
class hkDebugInfoOnPendingOperationQueues;
class hkEntityEntityBroadPhaseListener;
class hkMultithreadedSimulationJobData;
class hkPhantomBroadPhaseListener;
class hkSimulation;
class hkTypedBroadPhaseDispatcher;
class hkWorldCinfo;
class hkWorldDeletionListener;
class hkWorldMaintenanceMgr;
class hkWorldOperationQueue;
struct hkAabb;
class hkContactPoint;
class hkCollidable;
class hkContactPointMaterial;
class hkContactPointProperties;
class hkSimpleContactConstraintData;
class hkLinkedCollidable;
class hkCollisionAgentConfig;
class hkProcessCollisionData;
class hkConstraintListener;
class hkContactImpulseLimitBreachedListener;
class hkDynamicsContactMgr;
class hkIslandActivationListener;
class hkIslandPostCollideListener;
class hkIslandPostIntegrateListener;
class hkWorldPostCollideListener;
class hkWorldPostIntegrateListener;
class hkWorldPostSimulationListener;

// total size: 0x4
class hkCollidableCollidableFilter {
public:
    virtual ~hkCollidableCollidableFilter() {}
};

// total size: 0x4
class hkShapeCollectionFilter {
public:
    virtual ~hkShapeCollectionFilter() {}
};

// total size: 0x4
class hkRayShapeCollectionFilter {
public:
    virtual ~hkRayShapeCollectionFilter() {}
};

// total size: 0x4
class hkRayCollidableFilter {
public:
    virtual ~hkRayCollidableFilter() {}
};

// total size: 0x4
class GskFlags {
public:
    u8 m_cylinderAgentFlags;    // offset 0x0, size 0x1
    u8 m_enableContactTims;     // offset 0x1, size 0x1
    u8 m_convexListInGskMode;   // offset 0x2, size 0x1
    u8 m_processFunctionCalled; // offset 0x3, size 0x1
};

// total size: 0x4
class UserData {
public:
    union {
        GskFlags m_gskFlags;                  // offset 0x0, size 0x4
        hkCollisionAgent* m_bridgeChildAgent; // offset 0x0, size 0x4
    };
};

// total size: 0xC
class hkGskCache16 : public hkGskCache {};

// dep-only shells — no DWARF layout; minimal bodies for type completeness
class hkMassElement {};
// total size: 0x50
class hkMassProperties {
public:
    f32 m_volume;              // offset 0x0, size 0x4
    f32 m_mass;                // offset 0x4, size 0x4
    hkVector4 m_centerOfMass;  // offset 0x10, size 0x10
    hkMatrix3 m_inertiaTensor; // offset 0x20, size 0x30
};
class hkToiEvent {};
class TriIndices {};
class hkGskOut {};
class hkGskStatus {};
class hkGskManifold {};
// total size: 0xC
class Triangle {
public:
    s32 m_a; // offset 0x0, size 0x4
    s32 m_b; // offset 0x4, size 0x4
    s32 m_c; // offset 0x8, size 0x4
};
class Vertex {};
class hkMoppMeshType {};
class hkMoppScratchArea {};
class hkMoppSplitParams {};
class hkMoppSplitter {};
class hkMoppBasicNode {};
class hkMoppExtent {};
class hkMoppSplittingPlaneDirection {};
class hkMoppCodeReindexedTerminal {};
class hkMoppSplitCostParams {};
class hkContactImpulseLimitBreachedListenerInfo {};
class hkContactPointAddedEvent {};
// total size: 0x24
class hkContactPointConfirmedEvent {
public:
    hkCollidable* m_collidableA;                    // offset 0x0, size 0x4
    hkCollidable* m_collidableB;                    // offset 0x4, size 0x4
    hkEntity* m_callbackFiredFrom;                  // offset 0x8, size 0x4
    hkContactPoint* m_contactPoint;                 // offset 0xC, size 0x4
    hkContactPointMaterial* m_contactPointMaterial; // offset 0x10, size 0x4
    f32 m_rotateNormal;                             // offset 0x14, size 0x4
    f32 m_projectedVelocity;                        // offset 0x18, size 0x4
    hkEnum<s32> m_type;                             // offset 0x1C, size 0x4
    hkSimpleContactConstraintData* m_contactData;   // offset 0x20, size 0x4
};
// total size: 0x1C
class hkContactPointRemovedEvent {
public:
    u16 m_contactPointId;                           // offset 0x0, size 0x2
    hkContactPointMaterial* m_contactPointMaterial; // offset 0x4, size 0x4
    hkEntity* m_entityA;                            // offset 0x8, size 0x4
    hkEntity* m_entityB;                            // offset 0xC, size 0x4
    hkEntity* m_callbackFiredFrom;                  // offset 0x10, size 0x4
    hkDynamicsContactMgr* m_internalContactMgr;     // offset 0x14, size 0x4
    hkConstraintOwner* m_constraintOwner;           // offset 0x18, size 0x4
};
// total size: 0x414
class hkContactProcessEvent {
public:
    hkCollidable* m_collidableA;                             // offset 0x0, size 0x4
    hkCollidable* m_collidableB;                             // offset 0x4, size 0x4
    hkEntity* m_callbackFiredFrom;                           // offset 0x8, size 0x4
    hkProcessCollisionData* m_collisionData;                 // offset 0xC, size 0x4
    hkContactPointProperties* m_contactPointProperties[256]; // offset 0x10, size 0x400
    hkDynamicsContactMgr* m_internalContactMgr;              // offset 0x410, size 0x4
};
class hkMoppAabbCastVirtualMachineQueryFloat {};
class hkMoppAabbCastVirtualMachineQueryInt {};
class hkConstraintSchemaInfo {};
class hkConstraintSolverResources {};
class hkVelocityAccumulator {};
class hkMoppObbVirtualMachineQuery {};
class hkMoppPrimitiveInfo {};
class hkSimpleConstraintUtilCollideParams {};
class hkMoppCompilerPrimitive {};
class hkSimpleContactConstraintAtom {};
class hkAgent1nTrack {};
class SeekWhence {};
class ConstraintViolationInfo {};
class hkToiResourceMgr {};
class hkToiResources {};
// forward-decl-only entries promoted to complete types
// total size: 0x50
class hkAgent3Input {
public:
    hkPadSpu m_bodyA;      // offset 0x0, size 0x4
    hkPadSpu m_bodyB;      // offset 0x4, size 0x4
    hkPadSpu m_input;      // offset 0x8, size 0x4
    hkPadSpu m_contactMgr; // offset 0xC, size 0x4
    hkTransform m_aTb;     // offset 0x10, size 0x40
};
// total size: 0x70
class hkAgent3ProcessInput : public hkAgent3Input {
public:
    hkPadSpu m_distAtT1;                      // offset 0x50, size 0x4
    hkPadSpu m_offsetPpuSectorMinusSpuSector; // offset 0x54, size 0x4
    hkVector4 m_linearTimInfo;                // offset 0x60, size 0x10
};
// total size: 0x8
class hkAgentEntry {
public:
    u8 m_streamCommand;    // offset 0x0, size 0x1
    u8 m_agentType;        // offset 0x1, size 0x1
    u8 m_numContactPoints; // offset 0x2, size 0x1
    u8 m_size;             // offset 0x3, size 0x1
    UserData m_extraData;  // offset 0x4, size 0x4
};
// total size: 0x1C
class hkAgentNnEntry : public hkAgentEntry {
public:
    u16 m_agentIndexOnCollidable[2];     // offset 0x8, size 0x4
    hkContactMgr* m_contactMgr;          // offset 0xC, size 0x4
    u8 m_collisionQualityIndex;          // offset 0x10, size 0x1
    u8 m_forceCollideOntoPpu;            // offset 0x11, size 0x1
    u8 m_padding[2];                     // offset 0x12, size 0x2
    hkLinkedCollidable* m_collidable[2]; // offset 0x14, size 0x8
};
class hkCdVertex {};
// total size: 0x30
class hkCollisionFilter : public hkReferencedObject,
                          public hkCollidableCollidableFilter,
                          public hkShapeCollectionFilter,
                          public hkRayShapeCollectionFilter,
                          public hkRayCollidableFilter {
public:
    virtual ~hkCollisionFilter() {}
    hkEnum<s32> m_type; // offset 0x20, size 0x4
    u32 m_pad[3];       // offset 0x24, size 0xC
};
// total size: 0x14
class hkCollisionInput {
public:
    hkPadSpu m_dispatcher;             // offset 0x0, size 0x4
    hkPadSpu m_tolerance;              // offset 0x4, size 0x4
    hkPadSpu m_filter;                 // offset 0x8, size 0x4
    hkPadSpu m_convexListFilter;       // offset 0xC, size 0x4
    hkPadSpu m_createPredictiveAgents; // offset 0x10, size 0x1
};
// total size: 0xC
class hkContactMgr : public hkReferencedObject {
public:
    enum Type {
        TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR = 0,
        TYPE_REPORT_CONTACT_MGR = 1,
        TYPE_CONVEX_LIST_CONTACT_MGR = 2,
        TYPE_NULL_CONTACT_MGR = 3,
        TYPE_USER_CONTACT_MGR = 4,
        TYPE_MAX = 5,
    };

    virtual ~hkContactMgr() {}
    virtual void cleanup() {}

    Type m_type; // offset 0x8, size 0x4
};
// total size: 0x40
class hkLinearCastCollisionInput : public hkCollisionInput {
public:
    hkVector4 m_path;                 // offset 0x20, size 0x10
    f32 m_maxExtraPenetration;        // offset 0x30, size 0x4
    f32 m_cachedPathLength;           // offset 0x34, size 0x4
    hkCollisionAgentConfig* m_config; // offset 0x38, size 0x4
};
// total size: 0x40
class hkProcessCollisionInput : public hkCollisionInput {
public:
    hkStepInfo m_stepInfo;            // offset 0x20, size 0x10
    hkPadSpu m_collisionQualityInfo;  // offset 0x30, size 0x4
    void* m_dynamicsInfo;             // offset 0x34, size 0x4
    u8 m_enableDeprecatedWelding;     // offset 0x38, size 0x1
    hkCollisionAgentConfig* m_config; // offset 0x3C, size 0x4
};
class hkRayHitCollector {};
// total size: 0x30
class hkShapeRayCastInput {
public:
    hkVector4 m_from;                                       // offset 0x0, size 0x10
    hkVector4 m_to;                                         // offset 0x10, size 0x10
    u32 m_filterInfo;                                       // offset 0x20, size 0x4
    hkRayShapeCollectionFilter* m_rayShapeCollectionFilter; // offset 0x24, size 0x4
};
class hkSphere {};
class hkTypedBroadPhaseHandlePair {};

class hkCollidableAddedEvent {};
class hkCollidableRemovedEvent {};

class hkBroadPhaseCastCollector {
public:
    virtual ~hkBroadPhaseCastCollector() {}
};

// total size: 0x4
class hkBroadPhaseHandle {
public:
    u32 m_id; // offset 0x0, size 0x4
};

// total size: 0xC
class hkTypedBroadPhaseHandle : public hkBroadPhaseHandle {
public:
    s8 m_type;                 // offset 0x4, size 0x1
    s8 m_ownerOffset;          // offset 0x5, size 0x1
    u16 m_objectQualityType;   // offset 0x6, size 0x2
    u32 m_collisionFilterInfo; // offset 0x8, size 0x4
};

class hkBroadPhaseHandlePair {};

// total size: 0x8
class hkCdPointCollector {
public:
    virtual ~hkCdPointCollector() {}

    f32 m_earlyOutDistance; // offset 0x4, size 0x4
};

// total size: 0x10
class hkCdBody {
public:
    hkShape* m_shape;   // offset 0x0, size 0x4
    u32 m_shapeKey;     // offset 0x4, size 0x4
    void* m_motion;     // offset 0x8, size 0x4
    hkCdBody* m_parent; // offset 0xC, size 0x4
};

// total size: 0x20
class hkContactPoint {
public:
    hkVector4* getPosition() { return &m_position; }
    hkVector4* getSeparatingNormal() { return &m_separatingNormal; }

    hkVector4 m_position;         // offset 0x0, size 0x10
    hkVector4 m_separatingNormal; // offset 0x10, size 0x10
};

// total size: 0x30
class hkRootCdPoint {
public:
    hkContactPoint m_contact;        // offset 0x0, size 0x20
    hkCollidable* m_rootCollidableA; // offset 0x20, size 0x4
    u32 m_shapeKeyA;                 // offset 0x24, size 0x4
    hkCollidable* m_rootCollidableB; // offset 0x28, size 0x4
    u32 m_shapeKeyB;                 // offset 0x2C, size 0x4
};

// total size: 0x30
class hkCdPoint {
public:
    hkContactPoint m_contact; // offset 0x0, size 0x20
    hkCdBody& m_cdBodyA;      // offset 0x20, size 0x4
    hkCdBody& m_cdBodyB;      // offset 0x24, size 0x4
};

// total size: 0x1A0
class hkAllCdPointCollector : public hkCdPointCollector {
public:
    hkAllCdPointCollector() {}
    virtual ~hkAllCdPointCollector() {}
    virtual void addCdPoint(const hkCdPoint& rParam1);

    hkInplaceArray<hkRootCdPoint, 8>* getHits() { return &m_hits; }
    void sortHits();

    hkInplaceArray<hkRootCdPoint, 8> m_hits; // offset 0x10, size 0x190
};

class hkFeatureContactPoint {};
class hkFeaturePointCache {};

// total size: 0x24
class hkCollidable : public hkCdBody {
public:
    u32 getCollisionFilterInfo() const { return m_broadPhaseHandle.m_collisionFilterInfo; }
    const s8* getOwner() const { return (const s8*)this + m_ownerOffset; }

    s8 m_ownerOffset;                           // offset 0x10, size 0x1
    u8 m_forceCollideOntoPpu;                   // offset 0x11, size 0x1
    u16 m_shapeSizeOnSpu;                       // offset 0x12, size 0x2
    hkTypedBroadPhaseHandle m_broadPhaseHandle; // offset 0x14, size 0xC
    f32 m_allowedPenetrationDepth;              // offset 0x20, size 0x4
};

// total size: 0x8
class CollisionEntry {
public:
    hkAgentNnEntry* m_agentEntry;  // offset 0x0, size 0x4
    hkLinkedCollidable* m_partner; // offset 0x4, size 0x4
};

// total size: 0x30
class hkLinkedCollidable : public hkCollidable {
public:
    hkArray<CollisionEntry> m_collisionEntries; // offset 0x24, size 0xC
};

// total size: 0xC
class hkMaterial {
public:
    hkEnum<u8> m_responseType; // offset 0x0, size 0x1
    f32 m_friction;            // offset 0x4, size 0x4
    f32 m_restitution;         // offset 0x8, size 0x4
};

// total size: 0x8
class hkSmallArray {
public:
    void* m_data;           // offset 0x0, size 0x4
    u16 m_size;             // offset 0x4, size 0x2
    u16 m_capacityAndFlags; // offset 0x6, size 0x2
};

// total size: 0x8
class SpuCollisionCallback {
public:
    hkSpuCollisionCallbackUtil* m_util; // offset 0x0, size 0x4
    u16 m_capacity;                     // offset 0x4, size 0x2
    u8 m_eventFilter;                   // offset 0x6, size 0x1
    u8 m_userFilter;                    // offset 0x7, size 0x1
};

class hkGeomConvexHullMode {};
class hkGeomConvexHullTolerances {};
class hkGeomConvexHullConfig {};
class hkGeomEdge {};

// total size: 0x18
class hkGeometry {
public:
    hkArray<hkVector4> m_vertices; // offset 0x0, size 0xC
    hkArray<Triangle> m_triangles; // offset 0xC, size 0xC
};

class PlaneAndPoints {};
class WeightedLine {};
class WeightedNeighbour {};
class WrappingLine {};

class hkMoppAssembler {
public:
    class hkMoppAssemblerParams {};

    virtual ~hkMoppAssembler() {}
};

class hkMoppCompilerChunkInfo {};

class hkMoppMediator {
public:
    virtual ~hkMoppMediator() {}
};

class hkMoppCodeGenerator {
public:
    hkMoppCodeGenerator(s32 s32Param1);
    virtual ~hkMoppCodeGenerator();

    void resize();
    void compileCode();
};

// total size: 0x30
class hkMoppCode : public hkReferencedObject {
public:
    // total size: 0x10
    class CodeInfo {
    public:
        hkVector4 m_offset; // offset 0x0, size 0x10
    };

    virtual ~hkMoppCode() {}

    CodeInfo m_info;       // offset 0x10, size 0x10
    hkArray<void*> m_data; // offset 0x20, size 0xC
};

class hkMoppNodeMgr {
public:
    virtual ~hkMoppNodeMgr() {}
};

class hkMoppTreeInternalNode {};
class hkMoppTreeNode {};
class hkMoppTreeTerminal {};
class hkMoppAssemblerCutInfo {};
class hkMoppAssemblerNodeInfo {};
class hkMoppAssemblerRescaleCommand {};

enum HK_MOPP_SPLIT_DIRECTIONS {
    HK_MOPP_SPLIT_DIRECTION_NONE = 0,
};

class hkMoppDefaultAssembler : public hkMoppAssembler {
public:
    hkMoppDefaultAssembler(const hkMoppAssembler::hkMoppAssemblerParams& rParam1,
                           hkMoppCodeGenerator* pParam2,
                           hkMoppMediator* pParam3);
    virtual ~hkMoppDefaultAssembler();

    void updateParams(const hkMoppAssembler::hkMoppAssemblerParams& rParam1);
    void releaseNode(hkMoppTreeNode* pParam1);
    s32 shouldAssemble(hkMoppTreeNode* pParam1, const hkMoppAssemblerNodeInfo& rParam2);
    void calcRescaleBits(const hkMoppAssemblerNodeInfo& rParam1, hkMoppAssemblerNodeInfo& rParam2);
    void recalcRescale(const hkMoppAssemblerNodeInfo& rParam1,
                       hkMoppAssemblerNodeInfo& rParam2,
                       hkMoppAssemblerRescaleCommand& rParam3);
    void preCalcScale(hkMoppTreeNode* pParam1,
                      const hkMoppAssemblerNodeInfo& rParam2,
                      hkMoppAssemblerNodeInfo& rParam3);
    void fixScale(hkMoppTreeNode* pParam1);
    void calcTermCut(hkMoppTreeNode* pParam1, hkMoppAssemblerCutInfo& rParam2);
    void preCalcCutPositions(hkMoppTreeNode* pParam1,
                             const hkMoppAssemblerCutInfo& rParam2,
                             hkMoppAssemblerCutInfo& rParam3);
    void initTopDown(hkMoppTreeNode* pParam1,
                     const hkMoppAssemblerNodeInfo& rParam2,
                     hkMoppAssemblerNodeInfo& rParam3,
                     hkMoppAssemblerRescaleCommand& rParam4);
    void assemblesubNode(hkMoppTreeNode* pParam1,
                         const hkMoppAssemblerNodeInfo& rParam2,
                         hkMoppAssemblerNodeInfo& rParam3);
    void calcChunkPoints(hkMoppTreeNode* pParam1,
                         const hkMoppAssemblerNodeInfo& rParam2,
                         hkMoppAssemblerNodeInfo& rParam3,
                         hkArray<u32>& rParam4);
    void calcTerminalIdsForChunks(hkMoppTreeNode* pParam1, s32 s32Param2, s32 s32Param3);
    void assembleSubNodeIntoChunks(hkMoppTreeNode* pParam1,
                                   const hkMoppAssemblerNodeInfo& rParam2,
                                   hkMoppAssemblerNodeInfo& rParam3,
                                   s32 s32Param4,
                                   hkArray<u32>& rParam5);
    void calcReoffset(hkMoppTreeNode* pParam1,
                      const hkMoppAssemblerNodeInfo& rParam2,
                      hkMoppAssemblerNodeInfo& rParam3);
    void addProperty(s32 s32Param1, s32 s32Param2);
    void addJumpChunk(s32 s32Param1);
    void addDataOffset(s32 s32Param1, s32 s32Param2);
    void addRescale(const hkMoppAssemblerRescaleCommand& rParam1);
    void addTermIdOffset(u32 u32Param1);
    void addCut(const hkMoppTreeNode* pParam1, const hkMoppAssemblerNodeInfo& rParam2);
    void addSplit(s32 s32Param1,
                  s32 s32Param2,
                  HK_MOPP_SPLIT_DIRECTIONS eParam3,
                  s32 s32Param4,
                  s32 s32Param5);
    void checkAndAddProperties(hkMoppTreeNode* pParam1,
                               const hkMoppAssemblerNodeInfo& rParam2,
                               hkMoppAssemblerNodeInfo& rParam3);
    void addTerminals(hkMoppTreeTerminal* pParam1,
                      const hkMoppAssemblerNodeInfo& rParam2,
                      const hkMoppAssemblerNodeInfo& rParam3);
    void addJump(u32 u32Param1);
    s32 getSplitCode(const hkVector4& rParam1);
    void findPlanes(const hkMoppTreeInternalNode* pParam1,
                    const hkMoppAssemblerNodeInfo& rParam2,
                    s32& rParam3,
                    s32& rParam4);
    void getScaleInfo(hkMoppTreeNode* pParam1, hkMoppCode::CodeInfo* pParam2);
    void assembleCutAndTerminalCommand(hkMoppTreeNode* pParam1,
                                       const hkMoppAssemblerNodeInfo& rParam2,
                                       hkMoppAssemblerNodeInfo& rParam3);
    void assembleNonTerminalCommand(hkMoppTreeNode* pParam1,
                                    const hkMoppAssemblerNodeInfo& rParam2,
                                    hkMoppAssemblerNodeInfo& rParam3,
                                    hkMoppAssemblerRescaleCommand& rParam4);
    void assembleJumpChunkCommand(hkMoppTreeNode* pParam1);
    void assemble(hkMoppTreeNode* pParam1, hkMoppNodeMgr* pParam2, s32 s32Param3);
    s32 getNumSplittingPlaneDirections() const;
    const hkVector4* getSplittingPlaneDirections() const;

    static hkVector4 m_directions[26];
};

// total size: 0x1
class hkBool {
public:
    c8 m_bool; // offset 0x0, size 0x1
};

// total size: 0x1
class hkUFloat8 {
public:
    u8 m_value; // offset 0x0, size 0x1
};

// total size: 0x8
class hkSolverResults {
public:
    f32 m_impulseApplied;     // offset 0x0, size 0x4
    f32 m_internalSolverData; // offset 0x4, size 0x4
};

// total size: 0x8
class hkContactPointMaterial {
public:
    void* m_userData;       // offset 0x0, size 0x4
    hkUFloat8 m_friction;   // offset 0x4, size 0x1
    u8 m_restitution;       // offset 0x5, size 0x1
    hkUFloat8 m_maxImpulse; // offset 0x6, size 0x1
    u8 m_flags;             // offset 0x7, size 0x1
};

// total size: 0x14
class hkContactPointProperties : public hkSolverResults, public hkContactPointMaterial {
public:
    f32 m_internalDataA; // offset 0x10, size 0x4
};

// total size: 0x8
class hkContactPointMaterial16 : public hkContactPointMaterial {};

// total size: 0x30
class hkProcessCdPoint {
public:
    hkContactPoint m_contact;  // offset 0x0, size 0x20
    hkPadSpu m_contactPointId; // offset 0x20, size 0x4
};

// total size: 0x40
class ToiInfo {
public:
    hkContactPoint m_contactPoint;       // offset 0x0, size 0x20
    hkPadSpu m_time;                     // offset 0x20, size 0x4
    hkPadSpu m_seperatingVelocity;       // offset 0x24, size 0x4
    hkGskCache16 m_gskCache;             // offset 0x28, size 0xC
    hkContactPointMaterial16 m_material; // offset 0x34, size 0x8
};

// total size: 0x3050
class hkProcessCollisionData {
public:
    hkPadSpu m_firstFreeContactPoint;      // offset 0x0, size 0x4
    hkPadSpu m_constraintOwner;            // offset 0x4, size 0x4
    hkProcessCdPoint m_contactPoints[256]; // offset 0x10, size 0x3000
    ToiInfo m_toi;                         // offset 0x3010, size 0x40
};

// total size: 0x3060
class hkProcessCollisionOutput : public hkProcessCollisionData {
public:
    hkPadSpu m_potentialContacts; // offset 0x3050, size 0x4
};

// total size: 0x8
class hkCdBodyPairCollector {
public:
    virtual ~hkCdBodyPairCollector() {}

    hkBool m_earlyOut; // offset 0x4, size 0x1
};

// total size: 0xC
class hkCollisionAgent : public hkReferencedObject {
public:
    virtual ~hkCollisionAgent() {}
    virtual void updateShapeCollectionFilter(const hkCdBody& rParam1,
                                             const hkCdBody& rParam2,
                                             const hkCollisionInput& rParam3,
                                             hkConstraintOwner& rParam4)
    {
    }
    virtual void invalidateTim(hkCollisionInput& rParam1);
    virtual void warpTime(f32 f32Param1, f32 f32Param2, hkCollisionInput& rParam3);
    virtual void removePoint(u16 u16Param1);
    virtual void commitPotential(u16 u16Param1);
    virtual void createZombie(u16 u16Param1);

    hkContactMgr* m_contactMgr; // offset 0x8, size 0x4
};

class hkConstraintQueryIn {};
class hkConstraintQueryOut {};
class hkSimpleConstraintInfoInitInput {};
class hkBodyVelocity {};

// total size: 0x10
class hkDynamicsContactMgr : public hkContactMgr {
public:
    virtual hkContactPointMaterial* getContactPointProperties(u16 u16Param1) { return 0; }
    virtual void getAllContactPointIds(hkArray<u16>& rParam1) const {}
    virtual ~hkDynamicsContactMgr() {}
    virtual hkContactPoint* getContactPoint(u16 u16Param1) { return 0; }
    virtual void toiCollisionResponseBeginCallback(const hkContactPoint& rParam1,
                                                   hkSimpleConstraintInfoInitInput& rParam2,
                                                   hkBodyVelocity& rParam3,
                                                   hkSimpleConstraintInfoInitInput& rParam4,
                                                   hkBodyVelocity& rParam5)
    {
    }
    virtual void toiCollisionResponseEndCallback(const hkContactPoint& rParam1,
                                                 f32 f32Param2,
                                                 hkSimpleConstraintInfoInitInput& rParam3,
                                                 hkBodyVelocity& rParam4,
                                                 hkSimpleConstraintInfoInitInput& rParam5,
                                                 hkBodyVelocity& rParam6)
    {
    }
    virtual hkConstraintInstance* getConstraintInstance() { return 0; }
    virtual void processToi(hkToiEvent& rParam1, f32 f32Param2, hkArray<hkEntity*>& rParam3) {}

    hkWorld* m_world; // offset 0xC, size 0x4
};

// total size: 0x2
class hkConstraintAtom {
public:
    hkEnum<u16> m_type; // offset 0x0, size 0x2
};

// total size: 0x4
class hk2dAngConstraintAtom : public hkConstraintAtom {
public:
    u8 m_freeRotationAxis; // offset 0x2, size 0x1
};

// total size: 0x10
class hkAngLimitConstraintAtom : public hkConstraintAtom {
public:
    u8 m_isEnabled;               // offset 0x2, size 0x1
    u8 m_limitAxis;               // offset 0x3, size 0x1
    f32 m_minAngle;               // offset 0x4, size 0x4
    f32 m_maxAngle;               // offset 0x8, size 0x4
    f32 m_angularLimitsTauFactor; // offset 0xC, size 0x4
};

// total size: 0x70
class hkSetLocalRotationsConstraintAtom : public hkConstraintAtom {
public:
    hkRotation m_rotationA; // offset 0x10, size 0x30
    hkRotation m_rotationB; // offset 0x40, size 0x30
};

// total size: 0x90
class Atoms {
public:
    hkSetLocalRotationsConstraintAtom m_rotations; // offset 0x0, size 0x70
    hkAngLimitConstraintAtom m_angLimit;           // offset 0x70, size 0x10
    hk2dAngConstraintAtom m_2dAng;                 // offset 0x80, size 0x4
};

// total size: 0xC
class hkBridgeConstraintAtom : public hkConstraintAtom {
public:
    void init(hkConstraintData* pParam1);

    void (*m_buildJacobianFunc)(hkConstraintData* pParam1,
                                hkConstraintQueryIn& rParam2,
                                hkConstraintQueryOut& rParam3); // offset 0x4, size 0x4
    hkConstraintData* m_constraintData;                         // offset 0x8, size 0x4
};

// total size: 0xC
class hkBridgeAtoms {
public:
    hkBridgeConstraintAtom m_bridgeAtom; // offset 0x0, size 0xC
};

// total size: 0x20
struct hkAabb {
    hkAabb() {}
    hkAabb(const hkVector4& rMin, const hkVector4& rMax) : m_min(rMin), m_max(rMax) {}

    hkVector4 m_min; // offset 0x0, size 0x10
    hkVector4 m_max; // offset 0x10, size 0x10
};

template <typename T>
class hkFixedArray {};

class hk3AxisSweep : public hkBroadPhase {
public:
    class hkBpNode {};
    class hkBpMarker {};
    class hkBpEndPoint {};
    class ValueIntPair {};

    class hkBpAxis {
    public:
        hkBpAxis() {}
        ~hkBpAxis() {}

        void mergeBatch(
            hkBpNode* pParam1, s32 s32Param2, s32 s32Param3, s32 s32Param4, hkBpEndPoint* pParam5);
        void removeBatch(hkBpNode* pParam1, s32 s32Param2, const hkFixedArray<s32>& rParam3);
        void insert(hkBpNode* pParam1,
                    s32 s32Param2,
                    u16 u16Param3,
                    u16 u16Param4,
                    u16& rParam5,
                    u16& rParam6);
        void remove(s32 s32Param1, s32 s32Param2);
        hkBpEndPoint*
        find(const hkBpEndPoint* pParam1, const hkBpEndPoint* pParam2, u16 u16Param3) const;
    };

    hk3AxisSweep(const hkVector4& rParam1, const hkVector4& rParam2, s32 s32Param3);
    virtual ~hk3AxisSweep();

    s32 getType() const;
    void convertAabbToInt(const hkAabb& rParam1, hkBroadPhase::hkBpAabb& rParam2) const;
    void
    beginOverlap(hkBpNode& rParam1, hkBpNode& rParam2, hkArray<hkBroadPhaseHandlePair>& rParam3);
    void endOverlap(hkBpNode& rParam1, hkBpNode& rParam2, hkArray<hkBroadPhaseHandlePair>& rParam3);
    void beginOverlapCheckMarker(hkBpMarker* pParam1,
                                 hkBpNode& rParam2,
                                 s32 s32Param3,
                                 hkBpNode& rParam4,
                                 hkArray<hkBroadPhaseHandlePair>& rParam5);
    void endOverlapCheckMarker(hkBpMarker* pParam1,
                               hkBpNode& rParam2,
                               s32 s32Param3,
                               hkBpNode& rParam4,
                               hkArray<hkBroadPhaseHandlePair>& rParam5);
    void updateAabbs(hkBroadPhaseHandle** pParam1,
                     const hkAabb* pParam2,
                     s32 s32Param3,
                     hkArray<hkBroadPhaseHandlePair>& rParam4,
                     hkArray<hkBroadPhaseHandlePair>& rParam5);
    void updateNodesAfterInsert(hkBpNode* pParam1, s32 s32Param2, hkBpNode& rParam3);
    void updateNodesAfterDelete(hkBpNode* pParam1, s32 s32Param2, hkBpNode& rParam3);
    void setBitsBasedOnXInterval(
        s32 s32Param1, s32 s32Param2, const hkBpNode& rParam3, u16 u16Param4, u32* pParam5) const;
    void reQuerySingleObject(const hkBroadPhaseHandle* pParam1,
                             hkArray<hkBroadPhaseHandlePair>& rParam2) const;
    void addObject(hkBroadPhaseHandle* pParam1,
                   const hkAabb& rParam2,
                   hkArray<hkBroadPhaseHandlePair>& rParam3);
    void removeObject(hkBroadPhaseHandle* pParam1, hkArray<hkBroadPhaseHandlePair>& rParam2);
    void addObjectBatch(hkArray<hkBroadPhaseHandle*>& rParam1,
                        hkArray<hkAabb>& rParam2,
                        hkArray<hkBroadPhaseHandlePair>& rParam3);
    void removeObjectBatch(hkArray<hkBroadPhaseHandle*>& rParam1,
                           hkArray<hkBroadPhaseHandlePair>& rParam2);
    s32 getNumObjects();
    void getAllAabbs(hkArray<hkAabb>& rParam1);
    void getAabb(const hkBroadPhaseHandle* pParam1, hkAabb& rParam2) const;
    void getExtents(hkVector4& rParam1, hkVector4& rParam2) const;
    void
    queryBatchAabbSub(u32* pParam1, hkArray<hkBroadPhaseHandlePair>& rParam2, hkBool sParam3) const;
    void querySingleAabb(const hkAabb& rParam1, hkArray<hkBroadPhaseHandlePair>& rParam2) const;
    s32 getAabbCacheSize() const;
    void calcAabbCache(const hkAabb& rParam1, c8* pParam2) const;
    void calcAabbCache(const hkArray<hkCollidable*>& rParam1, c8* pParam2) const;
    void calcAabbCacheInternal(const hkArray<const hkBpNode*>& rParam1, c8* pParam2) const;
    void defragment();
    void castRay(const hkBroadPhase::hkCastRayInput& rParam1,
                 hkBroadPhaseCastCollector* pParam2,
                 s32 s32Param3) const;
    void castAabb(const hkBroadPhase::hkCastAabbInput& rParam1,
                  hkBroadPhaseCastCollector& rParam2) const;
    void getAabbFromNode(const hkBpNode& rParam1, hkAabb& rParam2) const;
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    void shiftAllObjects(const hkVector4& rParam1,
                         hkVector4& rParam2,
                         hkArray<hkBroadPhaseHandle*>& rParam3);
    void shiftBroadPhase(const hkVector4& rParam1,
                         hkVector4& rParam2,
                         hkArray<hkBroadPhaseHandle*>& rParam3);

    static hkVector4 MaxVal;
};

hkBroadPhase*
hk3AxisSweep16CreateBroadPhase(const hkVector4& rParam1, const hkVector4& rParam2, s32 s32Param3);

enum LastProcessingStep {
    INTEGRATE = 0,
    COLLIDE = 1,
};

enum hkStepResult {
    HK_STEP_RESULT_SUCCESS = 0,
    HK_STEP_RESULT_MEMORY_FAILURE_BEFORE_INTEGRATION = 1,
    HK_STEP_RESULT_MEMORY_FAILURE_DURING_COLLIDE = 2,
    HK_STEP_RESULT_MEMORY_FAILURE_DURING_TOI_SOLVE = 3,
};

enum Symmetric {
    IS_SYMMETRIC = 0,
    IS_NOT_SYMMETRIC = 1,
    IS_NOT_SYMMETRIC_AND_FLIPPED = 2,
};

enum hkShapeType {
    HK_SHAPE_INVALID = 0,
    HK_SHAPE_CONVEX = 1,
    HK_FIRST_SHAPE_TYPE = 1,
    HK_SHAPE_COLLECTION = 2,
    HK_SHAPE_SPHERE = 3,
    HK_SHAPE_CYLINDER = 4,
    HK_SHAPE_TRIANGLE = 5,
    HK_SHAPE_BOX = 6,
    HK_SHAPE_CAPSULE = 7,
    HK_SHAPE_CONVEX_VERTICES = 8,
    HK_SHAPE_PACKED_CONVEX_VERTICES = 9,
    HK_SHAPE_LIST = 10,
    HK_SHAPE_MOPP = 11,
    HK_SHAPE_MOPP_EMBEDDED = 12,
    HK_SHAPE_CONVEX_TRANSLATE = 13,
    HK_SHAPE_CONVEX_TRANSFORM = 14,
    HK_SHAPE_EXTENDED_MESH = 15,
    HK_SHAPE_MAX_ID_SPU = 16,
    HK_SHAPE_CONVEX_PIECE = 17,
    HK_SHAPE_MULTI_SPHERE = 18,
    HK_SHAPE_CONVEX_LIST = 19,
    HK_SHAPE_TRIANGLE_COLLECTION = 20,
    HK_SHAPE_BV_TREE = 21,
    HK_SHAPE_MULTI_RAY = 22,
    HK_SHAPE_HEIGHT_FIELD = 23,
    HK_SHAPE_SAMPLED_HEIGHT_FIELD = 24,
    HK_SHAPE_TRI_PATCH = 25,
    HK_SHAPE_SPHERE_REP = 26,
    HK_SHAPE_BV = 27,
    HK_SHAPE_PLANE = 28,
    HK_SHAPE_TRANSFORM = 29,
    HK_SHAPE_PHANTOM_CALLBACK = 30,
    HK_SHAPE_USER0 = 31,
    HK_SHAPE_USER1 = 32,
    HK_SHAPE_USER2 = 33,
    HK_SHAPE_MAX_ID = 34,
    HK_SHAPE_ALL = -1,
};

enum HK_MEMORY_CLASS {
    HK_MEMORY_CLASS_ROOT = 0,
    HK_MEMORY_CLASS_BASE = 1,
    HK_MEMORY_CLASS_COLLIDE = 2,
    HK_MEMORY_CLASS_CONSTRAINT_SOLVER = 3,
    HK_MEMORY_CLASS_DYNAMICS = 4,
    HK_MEMORY_CLASS_EXPORT = 5,
    HK_MEMORY_CLASS_SERIALIZE = 6,
    HK_MEMORY_CLASS_GEOMETRY = 7,
    HK_MEMORY_CLASS_DISPLAY = 8,
    HK_MEMORY_CLASS_MATH = 9,
    HK_MEMORY_CLASS_SCENE_DATA = 10,
    HK_MEMORY_CLASS_VEHICLE = 11,
    HK_MEMORY_CLASS_UTILITIES = 12,
    HK_MEMORY_CLASS_ANIMATION = 13,
    HK_MEMORY_CLASS_BEHAVIOR = 14,
    HK_MEMORY_CLASS_TOOLS = 15,
    HK_MEMORY_CLASS_DEMO_FRAMEWORK = 16,
    HK_MEMORY_CLASS_DEMO = 17,
    HK_MEMORY_CLASS_USER = 18,
    HK_MEMORY_CLASS_BASE_CLASS = 19,
    HK_MEMORY_CLASS_STRING = 20,
    HK_MEMORY_CLASS_ARRAY = 21,
    HK_MEMORY_CLASS_SINGLETON = 22,
    HK_MEMORY_CLASS_SCRATCHPAD = 23,
    HK_MEMORY_CLASS_STREAM = 24,
    HK_MEMORY_CLASS_MONITOR = 25,
    HK_MEMORY_CLASS_MAP = 26,
    HK_MEMORY_CLASS_TREE = 27,
    HK_MEMORY_CLASS_HKCLASS = 28,
    HK_MEMORY_CLASS_AGENT = 29,
    HK_MEMORY_CLASS_ALGORITHM = 30,
    HK_MEMORY_CLASS_BROAD_PHASE = 31,
    HK_MEMORY_CLASS_CONTACT = 32,
    HK_MEMORY_CLASS_DISPATCH = 33,
    HK_MEMORY_CLASS_MANIFOLD = 34,
    HK_MEMORY_CLASS_SHAPE = 35,
    HK_MEMORY_CLASS_COLLIDABLE = 36,
    HK_MEMORY_CLASS_CDINFO = 37,
    HK_MEMORY_CLASS_MOPP = 38,
    HK_MEMORY_CLASS_ACTION = 39,
    HK_MEMORY_CLASS_DYNCOLLIDE = 40,
    HK_MEMORY_CLASS_DEACTIVATOR = 41,
    HK_MEMORY_CLASS_CONSTRAINT = 42,
    HK_MEMORY_CLASS_ENTITY = 43,
    HK_MEMORY_CLASS_MOTION = 44,
    HK_MEMORY_CLASS_WORLD = 45,
    HK_MEMORY_CLASS_RIGID_BODY = 46,
    HK_MEMORY_CLASS_PHANTOM = 47,
    HK_MEMORY_CLASS_SIMISLAND = 48,
    HK_MEMORY_CLASS_CAMERA = 49,
    HK_MEMORY_CLASS_CHARACTER = 50,
    HK_MEMORY_CLASS_VDB = 51,
    HK_MEMORY_CLASS_INERTIA = 52,
    HK_MEMORY_CLASS_ANIM_UNCOMPRESSED = 53,
    HK_MEMORY_CLASS_ANIM_COMPRESSED = 54,
    HK_MEMORY_CLASS_ANIM_DATA = 55,
    HK_MEMORY_CLASS_ANIM_MOTION = 56,
    HK_MEMORY_CLASS_ANIM_RIG = 57,
    HK_MEMORY_CLASS_ANIM_CONTROL = 58,
    HK_MEMORY_CLASS_ANIM_RUNTIME = 59,
    HK_MEMORY_CLASS_ANIM_CACHE = 60,
    HK_MEMORY_CLASS_BEHAVIOR_RUNTIME = 61,
    HK_MEMORY_CLASS_BEHAVIOR_DEMOS = 62,
    HK_MEMORY_CLASS_USER_1 = 63,
    HK_MEMORY_CLASS_USER_2 = 64,
    HK_MEMORY_CLASS_USER_3 = 65,
    HK_MEMORY_CLASS_USER_4 = 66,
    HK_MEMORY_CLASS_PRE_ALLOCATED = 67,
    HK_MEMORY_CLASS_MAX = 68,
};

// total size: 0x14
class BigBlockData {
public:
    hkBool m_available;         // offset 0x0, size 0x1
    s32 m_size;                 // offset 0x4, size 0x4
    void* m_memory;             // offset 0x8, size 0x4
    HK_MEMORY_CLASS m_class;    // offset 0xC, size 0x4
    hkBool m_providedByOutside; // offset 0x10, size 0x1
};

// total size: 0x1C
class hkMemoryStatistics {
public:
    s32 m_numSysAllocs;      // offset 0x0, size 0x4
    s32 m_sysAllocsSize;     // offset 0x4, size 0x4
    s32 m_sysAllocsHighMark; // offset 0x8, size 0x4
    s32 m_numPages;          // offset 0xC, size 0x4
    s32 m_sizeOfPage;        // offset 0x10, size 0x4
    s32 m_pageOverhead;      // offset 0x14, size 0x4
    s32 m_pageMemoryUsed;    // offset 0x18, size 0x4
};

enum MemoryState {
    MEMORY_STATE_OK = 0,
    MEMORY_STATE_OUT_OF_MEMORY = 1,
};

// total size: 0xA30
class hkMemory {
public:
    hkMemory();
    virtual ~hkMemory();
    virtual void reservePagesFromSystemMemory(s32 s32Param1) {}
    virtual void garbageCollectEmptyPages() {}
    virtual void releaseUnusedPagesToSystemMemory() {}
    virtual s32 getAllocatedSize(s32 s32Param1);
    virtual bool isDebugMemory() { return false; }
    virtual hkBool isOk() const;
    virtual void* findBaseAddress(void* pvParam1, s32 s32Param2) { return pvParam1; }
    virtual void lockBlock(void* pvParam1) {}
    virtual void unlockBlock(void* pvParam1) {}

    static hkMemory* s_instance;

    void replaceInstance(hkMemory* pParam1);

    MemoryState m_memoryState;             // offset 0x4, size 0x4
    s32 m_criticalMemoryLimit;             // offset 0x8, size 0x4
    s32 m_referenceCount;                  // offset 0xC, size 0x4
    hkMemoryStatistics m_memoryStatistics; // offset 0x10, size 0x1C
    s32 m_numValidBigBlocks;               // offset 0x2C, size 0x4
    BigBlockData m_bigBlockDataArray[128]; // offset 0x30, size 0xA00
};

// total size: 0x24
class hkClass {
public:
    hkClass(const c8* pcParam1,
            const hkClass* pParam2,
            s32 s32Param3,
            const hkClass** pParam4,
            s32 s32Param5,
            const hkClassEnum* pParam6,
            s32 s32Param7,
            const hkClassMember* pParam8,
            s32 s32Param9,
            const void* pvParam10);

    c8* m_name;                       // offset 0x0, size 0x4
    hkClass* m_parent;                // offset 0x4, size 0x4
    s32 m_objectSize;                 // offset 0x8, size 0x4
    s32 m_numImplementedInterfaces;   // offset 0xC, size 0x4
    hkClassEnum* m_declaredEnums;     // offset 0x10, size 0x4
    s32 m_numDeclaredEnums;           // offset 0x14, size 0x4
    hkClassMember* m_declaredMembers; // offset 0x18, size 0x4
    s32 m_numDeclaredMembers;         // offset 0x1C, size 0x4
    void* m_defaults;                 // offset 0x20, size 0x4
};

namespace hkWorldOperation {
enum BaseOperation {
    BASE_OPERATION_NONE = 0,
};
}

// total size: 0x38
class clsPfHavokHeap : public clsSingleton<clsPfHavokHeap>, public clsOOHeapFragment {
public:
    clsPfHavokHeap(u32 u32AllocateSizeI);
    virtual ~clsPfHavokHeap() {}

    static void* HavokSystemMalloc(s32 size, s32 align);
    static void HavokSystemFree(void* p);
};

// Used by hkWorld::updateCollisionFilterOnPhantom
enum hkUpdateCollectionFilterMode {
    HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS = 0,
    HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS = 1,
};

enum hkEntityActivation {
    HK_ENTITY_ACTIVATION_DO_ACTIVATE = 0,
};

enum hkUpdateCollisionFilterOnWorldMode {
    HK_UPDATE_FILTER_ON_WORLD_FULL_CHECK = 0,
};

enum hkUpdateCollisionFilterOnEntityMode {
    HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK = 0,
};

enum SimulationType {
    SIMULATION_TYPE_INVALID = 0,
    SIMULATION_TYPE_DISCRETE = 1,
    SIMULATION_TYPE_CONTINUOUS = 2,
    SIMULATION_TYPE_MULTITHREADED = 3,
};

// total size: 0x8
class hkPropertyValue {
public:
    u32 m_data; // offset 0x0, size 0x4
};

// total size: 0x10
class hkProperty {
public:
    u32 m_key;               // offset 0x0, size 0x4
    u32 m_alignmentPadding;  // offset 0x4, size 0x4
    hkPropertyValue m_value; // offset 0x8, size 0x8
};

#ifndef HK_WORLD_OBJECT_DECLARED
#define HK_WORLD_OBJECT_DECLARED
class hkWorldObject : public hkReferencedObject {
public:
    enum BroadPhaseType {
        BROAD_PHASE_INVALID = 0,
    };

    hkWorldObject() {}
    hkWorldObject(hkFinishLoadedObjectFlag sParam1);
    hkWorldObject(const hkShape* pParam1, BroadPhaseType sParam2);
    virtual ~hkWorldObject() {}
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual void setShape(const hkShape* pParam1);

    void addProperty(u32 u32Param1, hkPropertyValue sParam2);
    void removeProperty(u32 u32Param1);
    void addReference();
    void removeReference();
    void addReferenceAsCriticalOperation();
    hkLinkedCollidable* getCollidableRw() { return &m_collidable; }
    void* getUserData() const { return m_userData; }

    hkWorld* m_world;                      // offset 0x8, size 0x4
    void* m_userData;                      // offset 0xC, size 0x4
    hkLinkedCollidable m_collidable;       // offset 0x10, size 0x30
    hkMultiThreadCheck m_multiThreadCheck; // offset 0x40, size 0x8
    c8* m_name;                            // offset 0x48, size 0x4
    hkArray<hkProperty> m_properties;      // offset 0x4C, size 0xC
};
#endif

// total size: 0x120
class hkMotion : public hkReferencedObject {
public:
    enum MotionType { MOTION_INVALID = 0 };

    hkMotion(const hkVector4& rParam1, const hkQuaternion& rParam2, bool bParam3);
    hkMotion(hkFinishLoadedObjectFlag) {}
    virtual ~hkMotion() {}
    virtual void setMass(f32 f32Param1);
    virtual void setMassInv(f32 f32Param1);
    virtual void setCenterOfMassInLocal(const hkVector4& rParam1);
    virtual void setPosition(const hkVector4& rParam1);
    virtual void setRotation(const hkQuaternion& rParam1);
    virtual void setPositionAndRotation(const hkVector4& rParam1, const hkQuaternion& rParam2);
    virtual void setTransform(const hkTransform& rParam1);
    virtual void setLinearVelocity(const hkVector4& rParam1);
    virtual void setAngularVelocity(const hkVector4& rParam1);
    virtual void applyLinearImpulse(const hkVector4& rParam1);
    virtual void getMotionStateAndVelocitiesAndDeactivationType(hkMotion* pParam1);

    f32 getMass() const;
    void setDeactivationClass(s32 s32Param1);

    hkEnum<u8> m_type;                      // offset 0x8, size 0x1
    u8 m_deactivationIntegrateCounter;      // offset 0x9, size 0x1
    u16 m_deactivationNumInactiveFrames[2]; // offset 0xA, size 0x4
    hkMotionState m_motionState;            // offset 0x10, size 0xC0
    hkVector4 m_inertiaAndMassInv;          // offset 0xD0, size 0x10
    hkVector4 m_linearVelocity;             // offset 0xE0, size 0x10
    hkVector4 m_angularVelocity;            // offset 0xF0, size 0x10
    hkVector4 m_deactivationRefPosition[2]; // offset 0x100, size 0x20
};

// total size: 0x130
class hkKeyframedRigidMotion : public hkMotion {
public:
    hkKeyframedRigidMotion(const hkVector4& rParam1, const hkQuaternion& rParam2);
    hkKeyframedRigidMotion(hkFinishLoadedObjectFlag sParam1) : hkMotion(sParam1) {}
    virtual ~hkKeyframedRigidMotion();
    virtual void setMass(f32 f32Param1);
    virtual void setMassInv(f32 f32Param1);
    virtual void getInertiaLocal(hkMatrix3& rParam1) const;
    virtual void getInertiaWorld(hkMatrix3& rParam1) const;
    virtual void setInertiaLocal(const hkMatrix3& rParam1);
    virtual void setInertiaInvLocal(const hkMatrix3& rParam1);
    virtual void getInertiaInvLocal(hkMatrix3& rParam1) const;
    virtual void getInertiaInvWorld(hkMatrix3& rParam1) const;
    virtual void applyLinearImpulse(const hkVector4& rParam1);
    virtual void applyPointImpulse(const hkVector4& rParam1, const hkVector4& rParam2);
    virtual void applyAngularImpulse(const hkVector4& rParam1);
    virtual void applyForce(f32 f32Param1, const hkVector4& rParam2);
    virtual void applyForce(f32 f32Param1, const hkVector4& rParam2, const hkVector4& rParam3);
    virtual void applyTorque(f32 f32Param1, const hkVector4& rParam2);
    virtual void setStepPosition(f32 f32Param1, f32 f32Param2);
    virtual void setStoredMotion(hkMaxSizeMotion* pParam1);

    f32 getWeight() const;

    hkMaxSizeMotion* m_savedMotion; // offset 0x120, size 0x4
    s32 m_savedQualityTypeIndex;    // offset 0x124, size 0x4
};

// total size: 0x130
class hkMaxSizeMotion : public hkKeyframedRigidMotion {
public:
    hkMaxSizeMotion(hkFinishLoadedObjectFlag sParam1) : hkKeyframedRigidMotion(sParam1) {}
    virtual ~hkMaxSizeMotion();
};

// total size: 0x200
class hkEntity : public hkWorldObject {
public:
    hkEntity(const hkShape* pParam1);
    hkEntity(hkFinishLoadedObjectFlag sParam1);
    virtual ~hkEntity();
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual void* getMotionState();
    virtual void deallocateInternalArrays();

    void setDeactivator(hkEntityDeactivator* pParam1);
    void addEntityListener(hkEntityListener* pParam1);
    void removeEntityListener(hkEntityListener* pParam1);
    void addCollisionListener(hkCollisionListener* pParam1);
    u8 isActive() const;
    void activate();
    void deactivate();

    hkMaterial m_material;                             // offset 0x58, size 0xC
    void* m_breakOffPartsUtil;                         // offset 0x64, size 0x4
    u32 m_solverData;                                  // offset 0x68, size 0x4
    u16 m_storageIndex;                                // offset 0x6C, size 0x2
    u16 m_processContactCallbackDelay;                 // offset 0x6E, size 0x2
    hkSmallArray m_constraintsMaster;                  // offset 0x70, size 0x8
    hkArray<hkConstraintInstance*> m_constraintsSlave; // offset 0x78, size 0xC
    hkArray<void*> m_constraintRuntime;                // offset 0x84, size 0xC
    hkEntityDeactivator* m_deactivator;                // offset 0x90, size 0x4
    hkSimulationIsland* m_simulationIsland;            // offset 0x94, size 0x4
    s8 m_autoRemoveLevel;                              // offset 0x98, size 0x1
    u32 m_uid;                                         // offset 0x9C, size 0x4
    hkMaxSizeMotion m_motion;                          // offset 0xA0, size 0x130
    hkSmallArray m_collisionListeners;                 // offset 0x1D0, size 0x8
    hkSmallArray m_activationListeners;                // offset 0x1D8, size 0x8
    hkSmallArray m_entityListeners;                    // offset 0x1E0, size 0x8
    hkSmallArray m_actions;                            // offset 0x1E8, size 0x8
    SpuCollisionCallback m_spuCollisionCallback;       // offset 0x1F0, size 0x8
};

// total size: 0x200
class hkRigidBody : public hkEntity {
public:
    hkRigidBody(const hkRigidBodyCinfo& rParam1);
    virtual ~hkRigidBody();
    virtual void setShape(const hkShape* pParam1);
    virtual void* getMotionState();
    virtual hkRigidBody* clone() const;

    void updateCachedShapeInfo(const hkShape* pParam1, hkVector4& rParam2);
    void createDynamicRigidMotion(hkMotion::MotionType sParam1,
                                  const hkVector4& rParam2,
                                  const hkQuaternion& rParam3,
                                  f32 f32Param4,
                                  const hkMatrix3& rParam5,
                                  const hkVector4& rParam6,
                                  f32 f32Param7,
                                  f32 f32Param8,
                                  hkMaxSizeMotion* pParam9);
    void getCinfo(hkRigidBodyCinfo& rParam1) const;
    void setDeactivator(hkRigidBodyDeactivator* pParam1);
    void setMotionType(hkMotion::MotionType sParam1,
                       hkEntityActivation sParam2,
                       hkUpdateCollisionFilterOnEntityMode sParam3);
    void setCenterOfMassLocal(const hkVector4& rParam1);
    void setDeactivator(hkRigidBodyDeactivator::DeactivatorType sParam1);
    void updateBroadphaseAndResetCollisionInformationOfWarpedBody(hkEntity* pParam1);
    void setPosition(const hkVector4& rParam1);
    void setRotation(const hkQuaternion& rParam1);
    void setPositionAndRotation(const hkVector4& rParam1, const hkQuaternion& rParam2);
    void setTransform(const hkTransform& rParam1);
    void setMass(f32 f32Param1);
    void setAngularVelocity(const hkVector4& rParam1);
    const hkVector4& getLinearVelocity() const;
    void setLinearVelocity(const hkVector4& rParam1);
    const hkQuaternion& getRotation() const;
};

#ifndef HK_PHANTOM_CLASSES_DECLARED
#define HK_PHANTOM_CLASSES_DECLARED
class hkPhantom : public hkWorldObject {
public:
    virtual ~hkPhantom();
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual void updateShapeCollectionFilter() {}
    virtual void deallocateInternalArrays();

    void firePhantomDeleted();
    void firePhantomRemoved();
    void firePhantomAdded();
    void firePhantomShapeSet();
    void updateBroadPhase(const hkAabb& rParam1);
    void addPhantomListener(hkPhantomListener* pParam1);
    void removePhantomListener(hkPhantomListener* pParam1);
    void addPhantomOverlapListener(hkPhantomOverlapListener* pParam1);
    void removePhantomOverlapListener(hkPhantomOverlapListener* pParam1);

    hkArray<hkPhantomOverlapListener*> m_overlapListeners; // offset 0x58, size 0xC
    hkArray<hkPhantomListener*> m_phantomListeners;        // offset 0x64, size 0xC
};
// total size: 0x4
class hkCollisionDetail {
public:
    hkCollidable* m_collidable; // offset 0x0, size 0x4
};

// total size: 0x130
class hkShapePhantom : public hkPhantom {
public:
    hkShapePhantom(const hkShape* pParam1, const hkTransform& rParam2);
    virtual ~hkShapePhantom();
    virtual void deallocateInternalArrays();

    void* getMotionState();
    void setTransform(const hkTransform& rParam1);
    void setPosition(const hkVector4& rParam1, f32 f32Param2);
    void calcAabb(hkAabb& rParam1);
    virtual void setShape(const hkShape* pParam1);
    const hkTransform* getTransform() const;

    hkMotionState m_motionState; // offset 0x70, size 0xC0
};
// total size: 0x140
class hkSimpleShapePhantom : public hkShapePhantom {
public:
    hkSimpleShapePhantom(const hkShape* pParam1, const hkTransform& rParam2, u32 u32Param3);
    virtual ~hkSimpleShapePhantom();
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual void deallocateInternalArrays();

    s32 getType() const;
    hkSimpleShapePhantom* clone() const;
    void setPositionAndLinearCast(const hkVector4& rParam1,
                                  const hkLinearCastInput& rParam2,
                                  hkCdPointCollector& rParam3,
                                  hkCdPointCollector* pParam4);
    void getClosestPoints(hkCdPointCollector& rParam1, const hkCollisionInput* pParam2);
    void getPenetrations(hkCdBodyPairCollector& rParam1, const hkCollisionInput* pParam2);
    u8 isOverlappingCollidableAdded(hkCollidable* pParam1);
    void addOverlappingCollidable(hkCollidable* pParam1);
    void removeOverlappingCollidable(hkCollidable* pParam1);

    hkArray<hkCollisionDetail> m_collisionDetails; // offset 0x130, size 0xC
};
#endif

// total size: 0x2
class hkHalf {
public:
    s16 m_value; // offset 0x0, size 0x2
};

// total size: 0x20
class DeactivationInfo {
public:
    f32 m_linearVelocityThresholdInv;     // offset 0x0, size 0x4
    f32 m_angularVelocityThresholdInv;    // offset 0x4, size 0x4
    f32 m_slowObjectVelocityMultiplier;   // offset 0x8, size 0x4
    f32 m_relativeSleepVelocityThreshold; // offset 0xC, size 0x4
    u16 m_stepsToDeactivate;              // offset 0x10, size 0x2
    f32 m_maxDistSqrd[2];                 // offset 0x14, size 0x8
    hkHalf m_maxRotSqrd[2];               // offset 0x1C, size 0x4
};

// total size: 0x140
class hkSolverInfo {
public:
    f32 m_one;                                        // offset 0x0, size 0x4
    f32 m_tau;                                        // offset 0x4, size 0x4
    f32 m_damping;                                    // offset 0x8, size 0x4
    f32 m_frictionTau;                                // offset 0xC, size 0x4
    hkVector4 m_globalAccelerationPerSubStep;         // offset 0x10, size 0x10
    hkVector4 m_globalAccelerationPerStep;            // offset 0x20, size 0x10
    hkVector4 m_integrateVelocityFactor;              // offset 0x30, size 0x10
    hkVector4 m_invIntegrateVelocityFactor;           // offset 0x40, size 0x10
    f32 m_dampDivTau;                                 // offset 0x50, size 0x4
    f32 m_tauDivDamp;                                 // offset 0x54, size 0x4
    f32 m_dampDivFrictionTau;                         // offset 0x58, size 0x4
    f32 m_frictionTauDivDamp;                         // offset 0x5C, size 0x4
    f32 m_contactRestingVelocity;                     // offset 0x60, size 0x4
    DeactivationInfo m_deactivationInfo[6];           // offset 0x64, size 0xC0
    f32 m_deltaTime;                                  // offset 0x124, size 0x4
    f32 m_invDeltaTime;                               // offset 0x128, size 0x4
    s32 m_numSteps;                                   // offset 0x12C, size 0x4
    s32 m_numMicroSteps;                              // offset 0x130, size 0x4
    f32 m_invNumMicroSteps;                           // offset 0x134, size 0x4
    f32 m_invNumSteps;                                // offset 0x138, size 0x4
    hkBool m_forceCoherentConstraintOrderingInSolver; // offset 0x13C, size 0x1
    u8 m_deactivationNumInactiveFramesSelectFlag[2];  // offset 0x13D, size 0x2
    u8 m_deactivationIntegrateCounter;                // offset 0x13F, size 0x1
};

// total size: 0x150
class hkWorldDynamicsStepInfo {
public:
    hkStepInfo m_stepInfo;     // offset 0x0, size 0x10
    hkSolverInfo m_solverInfo; // offset 0x10, size 0x140
};

// total size: 0x20
class hkShapeRayCastCollectorOutput {
public:
    hkVector4 m_normal; // offset 0x0, size 0x10
    f32 m_hitFraction;  // offset 0x10, size 0x4
    s32 m_extraInfo;    // offset 0x14, size 0x4
    s32 m_pad[2];       // offset 0x18, size 0x8
};

// total size: 0x50
class hkShapeRayCastOutput : public hkShapeRayCastCollectorOutput {
public:
    u32 m_shapeKeys[8];  // offset 0x20, size 0x20
    s32 m_shapeKeyIndex; // offset 0x40, size 0x4
};

// total size: 0x30
class hkWorldRayCastInput {
public:
    hkWorldRayCastInput() {}

    hkVector4 m_from;                     // offset 0x0, size 0x10
    hkVector4 m_to;                       // offset 0x10, size 0x10
    hkBool m_enableShapeCollectionFilter; // offset 0x20, size 0x1
    u32 m_filterInfo;                     // offset 0x24, size 0x4
};

// total size: 0x60
class hkWorldRayCastOutput : public hkShapeRayCastOutput {
public:
    hkWorldRayCastOutput() {}

    hkCollidable* m_rootCollidable; // offset 0x50, size 0x4
};

// total size: 0x330
class hkWorld : public hkReferencedObject {
public:
    hkWorld(const hkWorldCinfo& rParam1, u32 u32Param2);
    virtual ~hkWorld();
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;

    void updateCollisionFilterOnWorld(hkUpdateCollisionFilterOnWorldMode sParam1,
                                      hkUpdateCollectionFilterMode sParam2);
    void updateCollisionFilterOnPhantom(hkPhantom* pParam1, hkUpdateCollectionFilterMode sParam2);
    void updateCollisionFilterOnEntity(hkEntity* pParam1,
                                       hkUpdateCollisionFilterOnEntityMode sParam2,
                                       hkUpdateCollectionFilterMode sParam3);
    hkEntity* addEntity(hkEntity* pParam1, hkEntityActivation sParam2);
    void addEntityBatch(hkEntity* const* pParam1, s32 s32Param2, hkEntityActivation sParam3);
    void removeEntity(hkEntity* pParam1);
    void removeEntityBatch(hkEntity* const* pParam1, s32 s32Param2);
    void activateRegion(const hkAabb& rParam1);
    void addConstraint(hkConstraintInstance* pParam1);
    void removeConstraint(hkConstraintInstance* pParam1);
    void addAction(hkAction* pParam1);
    void removeAction(hkAction* pParam1);
    void removeActionImmediately(hkAction* pParam1);
    hkPhantom* addPhantom(hkPhantom* pParam1);
    void addPhantomBatch(hkPhantom* const* pParam1, s32 s32Param2);
    void removePhantom(hkPhantom* pParam1);
    void removePhantomBatch(hkPhantom* const* pParam1, s32 s32Param2);
    void addWorldDeletionListener(hkWorldDeletionListener* pParam1);
    void removeWorldDeletionListener(hkWorldDeletionListener* pParam1);
    hkStepResult stepDeltaTime(f32 f32Param1);
    void checkDeterminism();
    void setCollisionFilter(hkCollisionFilter* pParam1,
                            hkBool sParam2,
                            hkUpdateCollisionFilterOnWorldMode sParam3,
                            hkUpdateCollectionFilterMode sParam4);
    void castRay(const hkWorldRayCastInput& rParam1, hkWorldRayCastOutput& rParam2) const;
    void internal_executePendingOperations();
    void queueOperation(const hkWorldOperation::BaseOperation& rParam1);
    s32 getMemUsageForIntegration();
    void lockIslandForConstraintUpdate(hkSimulationIsland* pParam1);
    void unlockIslandForConstraintUpdate(hkSimulationIsland* pParam1);
    const hkVector4& getGravity() const { return m_gravity; }

    static u8 m_forceMultithreadedSimulation;

    hkSimulation* m_simulation;                                         // offset 0x8, size 0x4
    hkVector4 m_gravity;                                                // offset 0x10, size 0x10
    hkSimulationIsland* m_fixedIsland;                                  // offset 0x20, size 0x4
    hkRigidBody* m_fixedRigidBody;                                      // offset 0x24, size 0x4
    hkArray<hkSimulationIsland*> m_activeSimulationIslands;             // offset 0x28, size 0xC
    hkArray<hkSimulationIsland*> m_inactiveSimulationIslands;           // offset 0x34, size 0xC
    hkArray<hkSimulationIsland*> m_dirtySimulationIslands;              // offset 0x40, size 0xC
    hkWorldMaintenanceMgr* m_maintenanceMgr;                            // offset 0x4C, size 0x4
    hkWorldMemoryWatchDog* m_memoryWatchDog;                            // offset 0x50, size 0x4
    hkBroadPhase* m_broadPhase;                                         // offset 0x54, size 0x4
    hkTypedBroadPhaseDispatcher* m_broadPhaseDispatcher;                // offset 0x58, size 0x4
    hkPhantomBroadPhaseListener* m_phantomBroadPhaseListener;           // offset 0x5C, size 0x4
    hkEntityEntityBroadPhaseListener* m_entityEntityBroadPhaseListener; // offset 0x60, size 0x4
    hkBroadPhaseBorderListener* m_broadPhaseBorderListener;             // offset 0x64, size 0x4
    hkMultithreadedSimulationJobData* m_multithreadedSimulationJobData; // offset 0x68, size 0x4
    hkProcessCollisionInput* m_collisionInput;                          // offset 0x6C, size 0x4
    hkCollisionFilter* m_collisionFilter;                               // offset 0x70, size 0x4
    hkCollisionDispatcher* m_collisionDispatcher;                       // offset 0x74, size 0x4
    hkConvexListFilter* m_convexListFilter;                             // offset 0x78, size 0x4
    hkWorldOperationQueue* m_pendingOperations;                         // offset 0x7C, size 0x4
    s32 m_pendingOperationsCount;                                       // offset 0x80, size 0x4
    s32 m_criticalOperationsLockCount;                                  // offset 0x84, size 0x4
    s32 m_criticalOperationsLockCountForPhantoms;                       // offset 0x88, size 0x4
    hkBool m_blockExecutingPendingOperations;                           // offset 0x8C, size 0x1
    hkBool m_criticalOperationsAllowed;                                 // offset 0x8D, size 0x1
    hkDebugInfoOnPendingOperationQueues* m_pendingOperationQueues;      // offset 0x90, size 0x4
    s32 m_pendingOperationQueueCount;                                   // offset 0x94, size 0x4
    hkMultiThreadCheck m_multiThreadCheck;                              // offset 0x98, size 0x8
    hkBool m_processActionsInSingleThread;                              // offset 0xA0, size 0x1
    u32 m_minDesiredIslandSize;                                         // offset 0xA4, size 0x4
    hkCriticalSection* m_modifyConstraintCriticalSection;               // offset 0xA8, size 0x4
    hkCriticalSection* m_worldLock;                                     // offset 0xAC, size 0x4
    hkCriticalSection* m_islandDirtyListCriticalSection;                // offset 0xB0, size 0x4
    hkCriticalSection* m_propertyMasterLock;                            // offset 0xB4, size 0x4
    hkArray<void*> m_propertyLocks;                                     // offset 0xB8, size 0xC
    hkBool m_wantSimulationIslands;                                     // offset 0xC4, size 0x1
    f32 m_snapCollisionToConvexEdgeThreshold;                           // offset 0xC8, size 0x4
    f32 m_snapCollisionToConcaveEdgeThreshold;                          // offset 0xCC, size 0x4
    hkBool m_enableToiWeldRejection;                                    // offset 0xD0, size 0x1
    hkBool m_wantDeactivation;                                          // offset 0xD1, size 0x1
    hkBool m_wantOldStyleDeactivation;                                  // offset 0xD2, size 0x1
    hkBool m_shouldActivateOnRigidBodyTransformChange;                  // offset 0xD3, size 0x1
    f32 m_highFrequencyDeactivationPeriod;                              // offset 0xD4, size 0x4
    f32 m_lowFrequencyDeactivationPeriod;                               // offset 0xD8, size 0x4
    f32 m_deactivationReferenceDistance;                                // offset 0xDC, size 0x4
    f32 m_toiCollisionResponseRotateNormal;                             // offset 0xE0, size 0x4
    SimulationType m_simulationType;                                    // offset 0xE4, size 0x4
    u32 m_lastEntityUid;                                                // offset 0xE8, size 0x4
    hkArray<hkPhantom*> m_phantoms;                                     // offset 0xEC, size 0xC
    hkArray<hkAction*> m_actionListeners;                               // offset 0xF8, size 0xC
    hkArray<hkEntityListener*> m_entityListeners;                       // offset 0x104, size 0xC
    hkArray<hkPhantomListener*> m_phantomListeners;                     // offset 0x110, size 0xC
    hkArray<hkConstraintListener*> m_constraintListeners;               // offset 0x11C, size 0xC
    hkArray<hkWorldDeletionListener*> m_worldDeletionListeners;         // offset 0x128, size 0xC
    hkArray<hkIslandActivationListener*> m_islandActivationListeners;   // offset 0x134, size 0xC
    hkArray<hkWorldPostSimulationListener*>
        m_worldPostSimulationListeners;                                   // offset 0x140, size 0xC
    hkArray<hkWorldPostIntegrateListener*> m_worldPostIntegrateListeners; // offset 0x14C, size 0xC
    hkArray<hkWorldPostCollideListener*> m_worldPostCollideListeners;     // offset 0x158, size 0xC
    hkArray<hkIslandPostIntegrateListener*>
        m_islandPostIntegrateListeners;                                 // offset 0x164, size 0xC
    hkArray<hkIslandPostCollideListener*> m_islandPostCollideListeners; // offset 0x170, size 0xC
    hkArray<hkCollisionListener*> m_collisionListeners;                 // offset 0x17C, size 0xC
    hkArray<hkContactImpulseLimitBreachedListener*>
        m_contactImpulseLimitBreachedListeners; // offset 0x188, size 0xC
    hkBroadPhaseBorder* m_broadPhaseBorder;     // offset 0x194, size 0x4
    hkWorldDynamicsStepInfo m_dynamicsStepInfo; // offset 0x1A0, size 0x150
    hkVector4 m_broadPhaseExtents[2];           // offset 0x2F0, size 0x20
    s32 m_broadPhaseNumMarkers;                 // offset 0x310, size 0x4
    s32 m_sizeOfToiEventQueue;                  // offset 0x314, size 0x4
    s32 m_broadPhaseQuerySize;                  // offset 0x318, size 0x4
    s32 m_broadPhaseUpdateSize;                 // offset 0x31C, size 0x4
    hkEnum<u8> m_contactPointGeneration;        // offset 0x320, size 0x1
};

// total size: 0xD0
class hkWorldCinfo : public hkReferencedObject {
public:
    enum BroadPhaseBorderBehaviour {
        BROAD_PHASE_BORDER_ASSERT = 0,
    };

    enum ContactPointGeneration { CONTACT_POINT_ACCEPT_ALWAYS = 0 };
    enum SimulationType { SIMULATION_TYPE_INVALID = 0 };
    enum SolverType { SOLVER_TYPE_INVALID = 0 };

    hkWorldCinfo();
    virtual ~hkWorldCinfo() {}

    void setBroadPhaseWorldSize(f32 f32Param1);
    void setupSolverInfo(SolverType sParam1);

    hkVector4 m_gravity;                               // offset 0x10, size 0x10
    s32 m_broadPhaseQuerySize;                         // offset 0x20, size 0x4
    f32 m_contactRestingVelocity;                      // offset 0x24, size 0x4
    hkEnum<u8> m_broadPhaseBorderBehaviour;            // offset 0x28, size 0x1
    hkAabb m_broadPhaseWorldAabb;                      // offset 0x30, size 0x20
    f32 m_collisionTolerance;                          // offset 0x50, size 0x4
    hkCollisionFilter* m_collisionFilter;              // offset 0x54, size 0x4
    hkConvexListFilter* m_convexListFilter;            // offset 0x58, size 0x4
    f32 m_expectedMaxLinearVelocity;                   // offset 0x5C, size 0x4
    s32 m_sizeOfToiEventQueue;                         // offset 0x60, size 0x4
    f32 m_expectedMinPsiDeltaTime;                     // offset 0x64, size 0x4
    hkWorldMemoryWatchDog* m_memoryWatchDog;           // offset 0x68, size 0x4
    s32 m_broadPhaseNumMarkers;                        // offset 0x6C, size 0x4
    hkEnum<u8> m_contactPointGeneration;               // offset 0x70, size 0x1
    f32 m_solverTau;                                   // offset 0x74, size 0x4
    f32 m_solverDamp;                                  // offset 0x78, size 0x4
    s32 m_solverIterations;                            // offset 0x7C, size 0x4
    s32 m_solverMicrosteps;                            // offset 0x80, size 0x4
    hkBool m_forceCoherentConstraintOrderingInSolver;  // offset 0x84, size 0x1
    f32 m_snapCollisionToConvexEdgeThreshold;          // offset 0x88, size 0x4
    f32 m_snapCollisionToConcaveEdgeThreshold;         // offset 0x8C, size 0x4
    hkBool m_enableToiWeldRejection;                   // offset 0x90, size 0x1
    hkBool m_enableDeprecatedWelding;                  // offset 0x91, size 0x1
    f32 m_iterativeLinearCastEarlyOutDistance;         // offset 0x94, size 0x4
    s32 m_iterativeLinearCastMaxIterations;            // offset 0x98, size 0x4
    f32 m_highFrequencyDeactivationPeriod;             // offset 0x9C, size 0x4
    f32 m_lowFrequencyDeactivationPeriod;              // offset 0xA0, size 0x4
    u8 m_deactivationNumInactiveFramesSelectFlag0;     // offset 0xA4, size 0x1
    u8 m_deactivationNumInactiveFramesSelectFlag1;     // offset 0xA5, size 0x1
    u8 m_deactivationIntegrateCounter;                 // offset 0xA6, size 0x1
    hkBool m_shouldActivateOnRigidBodyTransformChange; // offset 0xA7, size 0x1
    hkBool m_wantOldStyleDeactivation;                 // offset 0xA8, size 0x1
    f32 m_deactivationReferenceDistance;               // offset 0xAC, size 0x4
    f32 m_toiCollisionResponseRotateNormal;            // offset 0xB0, size 0x4
    hkBool m_enableDeactivation;                       // offset 0xB4, size 0x1
    hkEnum<u8> m_simulationType;                       // offset 0xB5, size 0x1
    hkBool m_enableSimulationIslands;                  // offset 0xB6, size 0x1
    u32 m_minDesiredIslandSize;                        // offset 0xB8, size 0x4
    hkBool m_processActionsInSingleThread;             // offset 0xBC, size 0x1
    f32 m_frameMarkerPsiSnap;                          // offset 0xC0, size 0x4
};

// total size: 0xC0
class hkRigidBodyCinfo {
public:
    hkRigidBodyCinfo();

    u32 m_collisionFilterInfo;             // offset 0x0, size 0x4
    hkShape* m_shape;                      // offset 0x4, size 0x4
    hkEnum<u8> m_collisionResponse;        // offset 0x8, size 0x1
    u16 m_processContactCallbackDelay;     // offset 0xA, size 0x2
    hkVector4 m_position;                  // offset 0x10, size 0x10
    hkQuaternion m_rotation;               // offset 0x20, size 0x10
    hkVector4 m_linearVelocity;            // offset 0x30, size 0x10
    hkVector4 m_angularVelocity;           // offset 0x40, size 0x10
    hkMatrix3 m_inertiaTensor;             // offset 0x50, size 0x30
    hkVector4 m_centerOfMass;              // offset 0x80, size 0x10
    f32 m_mass;                            // offset 0x90, size 0x4
    f32 m_linearDamping;                   // offset 0x94, size 0x4
    f32 m_angularDamping;                  // offset 0x98, size 0x4
    f32 m_friction;                        // offset 0x9C, size 0x4
    f32 m_restitution;                     // offset 0xA0, size 0x4
    f32 m_maxLinearVelocity;               // offset 0xA4, size 0x4
    f32 m_maxAngularVelocity;              // offset 0xA8, size 0x4
    f32 m_allowedPenetrationDepth;         // offset 0xAC, size 0x4
    hkEnum<u8> m_motionType;               // offset 0xB0, size 0x1
    hkEnum<u8> m_rigidBodyDeactivatorType; // offset 0xB1, size 0x1
    hkEnum<u8> m_solverDeactivation;       // offset 0xB2, size 0x1
    hkEnum<u8> m_qualityType;              // offset 0xB3, size 0x1
    s8 m_autoRemoveLevel;                  // offset 0xB4, size 0x1
    hkBool m_forceCollideOntoPpu;          // offset 0xB5, size 0x1
};

// total size: 0x30
class hkMoppCompilerInput {
public:
    hkMoppCompilerInput();

    f32 getAbsoluteFitToleranceOfTriangles() const;
    hkVector4 getAbsoluteFitToleranceOfAxisAlignedTriangles() const;
    f32 getRelativeFitToleranceOfInternalNodes() const;
    f32 getAbsoluteFitToleranceOfInternalNodes() const;

    hkVector4 m_absoluteFitToleranceOfAxisAlignedTriangles; // offset 0x0, size 0x10
    f32 m_relativeFitToleranceOfInternalNodes;              // offset 0x10, size 0x4
    f32 m_absoluteFitToleranceOfInternalNodes;              // offset 0x14, size 0x4
    f32 m_absoluteFitToleranceOfTriangles;                  // offset 0x18, size 0x4
    hkBool m_useShapeKeys;                                  // offset 0x1C, size 0x1
    hkBool m_enablePrimitiveSplitting;                      // offset 0x1D, size 0x1
    hkBool m_enableChunkSubdivision;                        // offset 0x1E, size 0x1
    hkBool m_enableInterleavedBuilding;                     // offset 0x1F, size 0x1
    hkBool m_cachePrimitiveExtents;                         // offset 0x20, size 0x1
    hkBool m_embedTerminals;                                // offset 0x21, size 0x1
    u8* m_embeddedMaterialIndices;                          // offset 0x24, size 0x4
};

// total size: 0x0
class hkBroadPhaseBorder {
public:
    hkBroadPhaseBorder(hkWorld* pParam1, hkWorldCinfo::BroadPhaseBorderBehaviour sParam2);
    virtual ~hkBroadPhaseBorder();
    virtual void collidableAddedCallback(const hkCollidableAddedEvent& rParam1);
    virtual void collidableRemovedCallback(const hkCollidableRemovedEvent& rParam1);
    virtual void maxPositionExceededCallback(hkEntity* pParam1);
    virtual void worldDeletedCallback(hkWorld* pParam1);
    virtual void deactivate();
};

// total size: 0x0
class hkBroadPhaseBorderListener : public hkReferencedObject {
public:
    virtual ~hkBroadPhaseBorderListener() {}
    virtual void addCollisionPair(hkTypedBroadPhaseHandlePair& rParam1);
    virtual void removeCollisionPair(hkTypedBroadPhaseHandlePair& rParam1);
};

// total size: 0x0
class hkPhantomBroadPhaseListener : public hkReferencedObject {
public:
    virtual ~hkPhantomBroadPhaseListener() {}
    virtual void addCollisionPair(hkTypedBroadPhaseHandlePair& rParam1);
    virtual void removeCollisionPair(hkTypedBroadPhaseHandlePair& rParam1);
};

// total size: 0x0
class hkEntityEntityBroadPhaseListener : public hkReferencedObject {
public:
    hkEntityEntityBroadPhaseListener(hkWorld* pParam1);
    virtual ~hkEntityEntityBroadPhaseListener() {}
    virtual void addCollisionPair(hkTypedBroadPhaseHandlePair& rParam1);
    virtual void removeCollisionPair(hkTypedBroadPhaseHandlePair& rParam1);
};

// total size: 0x0
class hkWorldOperationQueue {
public:
    hkWorldOperationQueue(hkWorld* pParam1);
    ~hkWorldOperationQueue();

    void queueOperation(const hkWorldOperation::BaseOperation& rParam1);
    void executeAllPending();
};

// total size: 0x3C
class hkCollisionQualityInfo {
public:
    f32 m_keepContact;               // offset 0x0, size 0x4
    f32 m_create4dContact;           // offset 0x4, size 0x4
    f32 m_createContact;             // offset 0x8, size 0x4
    f32 m_manifoldTimDistance;       // offset 0xC, size 0x4
    hkBool m_useContinuousPhysics;   // offset 0x10, size 0x1
    f32 m_minSeparation;             // offset 0x14, size 0x4
    f32 m_minExtraSeparation;        // offset 0x18, size 0x4
    f32 m_minSafeDeltaTime;          // offset 0x1C, size 0x4
    f32 m_minAbsoluteSafeDeltaTime;  // offset 0x20, size 0x4
    f32 m_toiSeparation;             // offset 0x24, size 0x4
    f32 m_toiExtraSeparation;        // offset 0x28, size 0x4
    f32 m_toiAccuracy;               // offset 0x2C, size 0x4
    f32 m_maxContraintViolation;     // offset 0x30, size 0x4
    f32 m_minToiDeltaTime;           // offset 0x34, size 0x4
    u16 m_constraintPriority;        // offset 0x38, size 0x2
    hkBool m_enableToiWeldRejection; // offset 0x3A, size 0x1
};

// total size: 0x0
class hkContactMgrFactory {};

// total size: 0x1C60
class hkCollisionDispatcher : public hkReferencedObject {
public:
    class InitCollisionQualityInfo {};

    // total size: 0x30
    class Agent3Funcs {
    public:
        void* (*m_createFunc)(hkAgent3Input& rParam1, hkAgentEntry* pParam2, void* pParam3);
        void (*m_destroyFunc)(hkAgentEntry* pParam1,
                              void* pParam2,
                              hkContactMgr* pParam3,
                              hkConstraintOwner& rParam4,
                              hkCollisionDispatcher* pParam5);
        void* (*m_cleanupFunc)(hkAgentEntry* pParam1,
                               void* pParam2,
                               hkContactMgr* pParam3,
                               hkConstraintOwner& rParam4);
        void (*m_removePointFunc)(hkAgentEntry* pParam1, void* pParam2, u16 u16Param3);
        void (*m_commitPotentialFunc)(hkAgentEntry* pParam1, void* pParam2, u16 u16Param3);
        void (*m_createZombieFunc)(hkAgentEntry* pParam1, void* pParam2, u16 u16Param3);
        void (*m_updateFilterFunc)(hkAgentEntry* pParam1,
                                   void* pParam2,
                                   hkCdBody& rParam3,
                                   hkCdBody& rParam4,
                                   hkCollisionInput& rParam5,
                                   hkContactMgr* pParam6,
                                   hkConstraintOwner& rParam7);
        void (*m_invalidateTimFunc)(hkAgentEntry* pParam1,
                                    void* pParam2,
                                    hkCollisionInput& rParam3);
        void (*m_warpTimeFunc)(hkAgentEntry* pParam1,
                               void* pParam2,
                               f32 f32Param3,
                               f32 f32Param4,
                               hkCollisionInput& rParam5);
        void (*m_sepNormalFunc)(hkAgent3Input& rParam1,
                                hkAgentEntry* pParam2,
                                void* pParam3,
                                hkVector4& rParam4);
        void* (*m_processFunc)(hkAgent3ProcessInput& rParam1,
                               hkAgentEntry* pParam2,
                               void* pParam3,
                               hkVector4* pParam4,
                               hkProcessCollisionOutput& rParam5);
        hkBool m_isPredictive;           // offset 0x2C, size 0x1
        hkBool m_ignoreSymmetricVersion; // offset 0x2D, size 0x1
    };

    // total size: 0x34
    class Agent3FuncsIntern : public Agent3Funcs {
    public:
        Symmetric m_symmetric; // offset 0x30, size 0x4
    };

    // total size: 0x14
    class AgentFuncs {
    public:
        hkCollisionAgent* (*m_createFunc)(hkCdBody& rParam1,
                                          hkCdBody& rParam2,
                                          hkCollisionInput& rParam3,
                                          hkContactMgr* pParam4);
        void (*m_getPenetrationsFunc)(hkCdBody& rParam1,
                                      hkCdBody& rParam2,
                                      hkCollisionInput& rParam3,
                                      hkCdBodyPairCollector& rParam4);
        void (*m_getClosestPointFunc)(hkCdBody& rParam1,
                                      hkCdBody& rParam2,
                                      hkCollisionInput& rParam3,
                                      hkCdPointCollector& rParam4);
        void (*m_linearCastFunc)(hkCdBody& rParam1,
                                 hkCdBody& rParam2,
                                 hkLinearCastCollisionInput& rParam3,
                                 hkCdPointCollector& rParam4,
                                 hkCdPointCollector* pParam5);
        hkBool m_isFlipped;    // offset 0x10, size 0x1
        hkBool m_isPredictive; // offset 0x11, size 0x1
    };

    // total size: 0x3
    class DebugEntry {
    public:
        c8 m_typeA;    // offset 0x0, size 0x1
        c8 m_typeB;    // offset 0x1, size 0x1
        c8 m_priority; // offset 0x2, size 0x1
    };

    hkCollisionDispatcher(hkCollisionAgent* (*pParam1)(const hkCdBody&,
                                                       const hkCdBody&,
                                                       const hkCollisionInput&,
                                                       hkContactMgr*),
                          hkContactMgrFactory* pParam2);
    virtual ~hkCollisionDispatcher();
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;

    void resetCreationFunctions();
    void setEnableChecks(hkBool sParam1);
    void disableDebugging();
    void registerCollisionAgent(hkCollisionDispatcher::AgentFuncs& rParam1,
                                hkShapeType sParam2,
                                hkShapeType sParam3);
    void registerCollisionAgent2(hkCollisionDispatcher::AgentFuncs& rParam1,
                                 hkShapeType sParam2,
                                 hkShapeType sParam3);
    void registerAgent3(hkCollisionDispatcher::Agent3Funcs& rParam1,
                        hkShapeType sParam2,
                        hkShapeType sParam3);
    void internalRegisterCollisionAgent(u8 (*pcParam1)[32],
                                        s32 s32Param2,
                                        hkShapeType sParam3,
                                        hkShapeType sParam4,
                                        hkShapeType sParam5,
                                        hkShapeType sParam6,
                                        DebugEntry (*pParam7)[32][32],
                                        s32 s32Param8);
    void updateHasAlternateType(hkShapeType sParam1, hkShapeType sParam2, s32 s32Param3);
    void registerAlternateShapeType(hkShapeType sParam1, hkShapeType sParam2);
    void registerContactMgrFactoryWithAll(hkContactMgrFactory* pParam1, s32 s32Param2);
    void initCollisionQualityInfo(InitCollisionQualityInfo& rParam1);

    hkCollisionAgent* (*m_defaultCollisionAgent)(hkCdBody& rParam1,
                                                 hkCdBody& rParam2,
                                                 hkCollisionInput& rParam3,
                                                 hkContactMgr* pParam4);
    hkContactMgrFactory* m_contactMgrFactory[8][8];   // offset 0xC, size 0x100
    u32 m_hasAlternateType[32];                       // offset 0x110, size 0x80
    s32 m_numAgent2Types;                             // offset 0x190, size 0x4
    u8 m_agent2Types[32][32];                         // offset 0x1A0, size 0x400
    u8 m_agent2TypesPred[32][32];                     // offset 0x5A0, size 0x400
    AgentFuncs m_agent2Func[64];                      // offset 0x9A0, size 0x500
    s32 m_numAgent3Types;                             // offset 0xEA0, size 0x4
    u8 m_agent3Types[32][32];                         // offset 0xEB0, size 0x400
    u8 m_agent3TypesPred[32][32];                     // offset 0x12B0, size 0x400
    Agent3FuncsIntern m_agent3Func[16];               // offset 0x16B0, size 0x340
    s8 m_collisionQualityTable[9][9];                 // offset 0x19F0, size 0x51
    hkCollisionQualityInfo m_collisionQualityInfo[8]; // offset 0x1A50, size 0x1E0
    hkBool m_collisionAgentRegistered;                // offset 0x1C30, size 0x1
    hkBool m_agent3Registered;                        // offset 0x1C31, size 0x1
    hkBool m_checkEnabled;                            // offset 0x1C32, size 0x1
    hkArray<void*> m_shapeInheritance;                // offset 0x1C34, size 0xC
    DebugEntry (*m_debugAgent2Table)[32][32];         // offset 0x1C40, size 0x4
    DebugEntry (*m_debugAgent2TablePred)[32][32];     // offset 0x1C44, size 0x4
    DebugEntry (*m_debugAgent3Table)[32][32];         // offset 0x1C48, size 0x4
    DebugEntry (*m_debugAgent3TablePred)[32][32];     // offset 0x1C4C, size 0x4
    f32 m_expectedMaxLinearVelocity;                  // offset 0x1C50, size 0x4
    f32 m_expectedMinPsiDeltaTime;                    // offset 0x1C54, size 0x4
};

// total size: 0x4
class hkShapeContainer {
public:
    virtual ~hkShapeContainer() {}
    virtual s32 getNumChildShapes() const;
    virtual u32 getCollisionFilterInfo(u32 u32Param1) const;
    virtual s32 isWeldingEnabled() const { return 1; }
};

// total size: 0x8
class hkSingleShapeContainer : public hkShapeContainer {
public:
    virtual ~hkSingleShapeContainer() {}
    virtual s32 getNumChildShapes() const { return 1; }
    virtual u32 getFirstKey() const { return 0; }
    virtual u32 getNextKey(u32 u32Param1) const { return 0xFFFFFFFF; }
    virtual const hkShape* getChildShape(u32 u32Param1, c8 (&sParam2)[512]) const;

    hkShape* m_childShape; // offset 0x4, size 0x4
};

// total size: 0x10
class hkShape : public hkReferencedObject {
public:
    virtual ~hkShape() {}
    virtual f32 getMaximumProjection(const hkVector4& rParam1) const;
    virtual hkShapeContainer* getContainer() const { return 0; }
    virtual s32 calcSizeForSpu(s32 s32Param1) const { return -1; }

    void* operator new(size_t size) { return 0; }

    u32 m_userData;     // offset 0x8, size 0x4
    hkEnum<u32> m_type; // offset 0xC, size 0x4
};

// total size: 0x70
class hkTransformShape : public hkShape {
public:
    hkTransformShape(const hkShape* pParam1, const hkTransform& rParam2);
    virtual ~hkTransformShape() {}
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual f32 getMaximumProjection(const hkVector4& rParam1) const;
    virtual void castRayWithCollector(const hkShapeRayCastInput& rParam1,
                                      const hkCdBody& rParam2,
                                      hkRayHitCollector& rParam3) const;
    virtual hkShapeContainer* getContainer() const;
    virtual void getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const;
    virtual hkBool castRayImpl(const hkShapeRayCastInput& rParam1,
                               hkShapeRayCastOutput& rParam2) const;

    void setTransform(const hkTransform& rParam1);

    hkSingleShapeContainer m_childShape; // offset 0x10, size 0x8
    hkQuaternion m_rotation;             // offset 0x20, size 0x10
    hkTransform m_transform;             // offset 0x30, size 0x40
};

// total size: 0x18
class hkShapeCollection : public hkShape, public hkShapeContainer {
public:
    hkShapeCollection(hkShapeType sParam1);
    virtual ~hkShapeCollection() {}
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual f32 getMaximumProjection(const hkVector4& rParam1) const;
    virtual void castRayWithCollector(const hkShapeRayCastInput& rParam1,
                                      const hkCdBody& rParam2,
                                      hkRayHitCollector& rParam3) const;
    virtual hkShapeContainer* getContainer() const;
    virtual void getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const;
    virtual hkBool castRayImpl(const hkShapeRayCastInput& rParam1,
                               hkShapeRayCastOutput& rParam2) const;
    virtual s32 isWeldingEnabled() const { return m_disableWelding.m_bool == 0; }

    hkBool m_disableWelding; // offset 0x14, size 0x1
};

// total size: 0x10
class ChildInfo {
public:
    hkShape* m_shape;          // offset 0x0, size 0x4
    u32 m_collisionFilterInfo; // offset 0x4, size 0x4
    s32 m_shapeSize;           // offset 0x8, size 0x4
    s32 m_numChildShapes;      // offset 0xC, size 0x4
};

// total size: 0x70
class hkListShape : public hkShapeCollection {
public:
    hkListShape(const hkShape* const* pParam1, s32 s32Param2);
    virtual ~hkListShape();
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual s32 calcSizeForSpu(s32 s32Param1) const;
    virtual void getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const;
    virtual hkBool castRayImpl(const hkShapeRayCastInput& rParam1,
                               hkShapeRayCastOutput& rParam2) const;
    virtual s32 getNumChildShapes() const;
    virtual u32 getFirstKey() const;
    virtual u32 getNextKey(u32 u32Param1) const;
    virtual u32 getCollisionFilterInfo(u32 u32Param1) const;
    virtual const hkShape* getChildShape(u32 u32Param1, c8 (&sParam2)[512]) const;

    void setShapes(const hkShape* const* pParam1, s32 s32Param2, const u32* pParam3);
    void recalcAabbExtents();

    hkArray<ChildInfo> m_childInfo; // offset 0x18, size 0xC
    hkVector4 m_aabbHalfExtents;    // offset 0x30, size 0x10
    hkVector4 m_aabbCenter;         // offset 0x40, size 0x10
    u32 m_enabledChildren[8];       // offset 0x50, size 0x20
};

class hkMeshMaterial;

// total size: 0x60
class hkMeshShape : public hkShapeCollection {
public:
    // total size: 0x38
    class Subpart {
    public:
        f32* m_vertexBase;                      // offset 0x0, size 0x4
        s32 m_vertexStriding;                   // offset 0x4, size 0x4
        s32 m_numVertices;                      // offset 0x8, size 0x4
        void* m_indexBase;                      // offset 0xC, size 0x4
        hkEnum<u8> m_stridingType;              // offset 0x10, size 0x1
        hkEnum<u8> m_materialIndexStridingType; // offset 0x11, size 0x1
        s32 m_indexStriding;                    // offset 0x14, size 0x4
        s32 m_flipAlternateTriangles;           // offset 0x18, size 0x4
        s32 m_numTriangles;                     // offset 0x1C, size 0x4
        void* m_materialIndexBase;              // offset 0x20, size 0x4
        s32 m_materialIndexStriding;            // offset 0x24, size 0x4
        hkMeshMaterial* m_materialBase;         // offset 0x28, size 0x4
        s32 m_materialStriding;                 // offset 0x2C, size 0x4
        s32 m_numMaterials;                     // offset 0x30, size 0x4
        s32 m_triangleOffset;                   // offset 0x34, size 0x4
    };

    hkMeshShape(f32 f32Param1, s32 s32Param2);
    hkMeshShape(hkFinishLoadedObjectFlag sParam1);
    virtual ~hkMeshShape() {}
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual void getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const;
    virtual u32 getFirstKey() const;
    virtual u32 getNextKey(u32 u32Param1) const;
    virtual u32 getCollisionFilterInfo(u32 u32Param1) const;
    virtual const hkShape* getChildShape(u32 u32Param1, c8 (&sParam2)[512]) const;
    virtual void addSubpart(const Subpart& rParam1);

    static u8 Members[140];

    hkVector4 m_scaling;          // offset 0x20, size 0x10
    s32 m_numBitsForSubpartIndex; // offset 0x30, size 0x4
    hkArray<Subpart> m_subparts;  // offset 0x34, size 0xC
    hkArray<u16> m_weldingInfo;   // offset 0x40, size 0xC
    hkEnum<u8> m_weldingType;     // offset 0x4C, size 0x1
    f32 m_radius;                 // offset 0x50, size 0x4
    s32 m_pad[3];                 // offset 0x54, size 0xC
};

// total size: 0x0
class hkTypedBroadPhaseDispatcher {
public:
    hkTypedBroadPhaseDispatcher();
    ~hkTypedBroadPhaseDispatcher();

    void addPairs(hkTypedBroadPhaseHandlePair* pParam1,
                  s32 s32Param2,
                  const hkCollidableCollidableFilter* pParam3) const;
    void removePairs(hkTypedBroadPhaseHandlePair* pParam1, s32 s32Param2) const;
    void removeDuplicates(hkArray<hkBroadPhaseHandlePair>& rParam1,
                          hkArray<hkBroadPhaseHandlePair>& rParam2);
};

// total size: 0x10
class hkSphereRepShape : public hkShape {
public:
    virtual ~hkSphereRepShape() {}
};

// total size: 0xC
class hkStridedVertices {
public:
    f32* m_vertices;   // offset 0x0, size 0x4
    s32 m_numVertices; // offset 0x4, size 0x4
    s32 m_striding;    // offset 0x8, size 0x4
};

// total size: 0x14
class hkConvexShape : public hkSphereRepShape {
public:
    virtual ~hkConvexShape() {}
    virtual f32 getMaximumProjection(const hkVector4& rParam1) const;
    virtual void castRayWithCollector(const hkShapeRayCastInput& rParam1,
                                      const hkCdBody& rParam2,
                                      hkRayHitCollector& rParam3) const;
    virtual void weldContactPointImpl(u16* pParam1,
                                      u8& rParam2,
                                      hkVector4& rParam3,
                                      const hkTransform* pParam4,
                                      const hkConvexShape* pParam5,
                                      const hkTransform* pParam6,
                                      hkVector4& rParam7) const;
    virtual void getCentreImpl(hkVector4& rParam1) const;

    f32 m_radius; // offset 0x10, size 0x4
};

// total size: 0x60
class hkConvexVerticesShape : public hkConvexShape {
public:
    hkConvexVerticesShape(hkStridedVertices sParam1,
                          const hkArray<hkVector4>& rParam2,
                          f32 f32Param3);
    virtual ~hkConvexVerticesShape() {}
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual s32 calcSizeForSpu(s32 s32Param1) const { return 96; }
    virtual void getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const;
    virtual hkBool castRayImpl(const hkShapeRayCastInput& rParam1,
                               hkShapeRayCastOutput& rParam2) const;
    virtual s32 getNumCollisionSpheresImpl() const;
    virtual void getCollisionSpheresImpl(hkSphere* pParam1) const;
    virtual void getFirstVertex(hkVector4& rParam1) const;
    virtual void getSupportingVertexImpl(const hkVector4& rParam1, hkCdVertex& rParam2) const;
    virtual void
    convertVertexIdsToVerticesImpl(const u16* pParam1, s32 s32Param2, hkCdVertex* pParam3) const;
    virtual void getCentreImpl(hkVector4& rParam1) const;

    void getOriginalVertices(hkArray<hkVector4>& rParam1) const;
    void copyVertexData(const f32* pParam1, s32 s32Param2, s32 s32Param3);
    const hkArray<hkVector4>& getPlaneEquations() const;

    hkVector4 m_aabbHalfExtents;          // offset 0x20, size 0x10
    hkVector4 m_aabbCenter;               // offset 0x30, size 0x10
    hkArray<hkVector4> m_rotatedVertices; // offset 0x40, size 0xC
    s32 m_numVertices;                    // offset 0x4C, size 0x4
    hkArray<hkVector4> m_planeEquations;  // offset 0x50, size 0xC
};

// total size: 0x40
class hkCapsuleShape : public hkConvexShape {
public:
    hkCapsuleShape(const hkVector4& rParam1, const hkVector4& rParam2, f32 f32Param3);
    virtual ~hkCapsuleShape() {}
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual s32 calcSizeForSpu(s32 s32Param1) const { return 64; }
    virtual void getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const;
    virtual hkBool castRayImpl(const hkShapeRayCastInput& rParam1,
                               hkShapeRayCastOutput& rParam2) const;
    virtual s32 getNumCollisionSpheresImpl() const;
    virtual void getCollisionSpheresImpl(hkSphere* pParam1) const;
    virtual void getFirstVertex(hkVector4& rParam1) const;
    virtual void getSupportingVertexImpl(const hkVector4& rParam1, hkCdVertex& rParam2) const;
    virtual void
    convertVertexIdsToVerticesImpl(const u16* pParam1, s32 s32Param2, hkCdVertex* pParam3) const;
    virtual void getCentreImpl(hkVector4& rParam1) const;

    void closestInfLineSegInfLineSeg(const hkVector4& rParam1,
                                     const hkVector4& rParam2,
                                     const hkVector4& rParam3,
                                     const hkVector4& rParam4,
                                     f32& rParam5,
                                     f32& rParam6,
                                     f32& rParam7,
                                     hkVector4& rParam8,
                                     hkVector4& rParam9);
    void closestPointLineSeg(const hkVector4& rParam1,
                             const hkVector4& rParam2,
                             const hkVector4& rParam3,
                             hkVector4& rParam4);

    hkVector4 m_vertexA; // offset 0x20, size 0x10
    hkVector4 m_vertexB; // offset 0x30, size 0x10
};

// total size: 0x30
class hkBoxShape : public hkConvexShape {
public:
    hkBoxShape(const hkVector4& rParam1, f32 f32Param2);
    virtual ~hkBoxShape();
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual s32 calcSizeForSpu(s32 s32Param1) const { return 48; }
    virtual void getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const;
    virtual hkBool castRayImpl(const hkShapeRayCastInput& rParam1,
                               hkShapeRayCastOutput& rParam2) const;
    virtual s32 getNumCollisionSpheresImpl() const;
    virtual void getCollisionSpheresImpl(hkSphere* pParam1) const;
    virtual void getFirstVertex(hkVector4& rParam1) const;
    virtual void getSupportingVertexImpl(const hkVector4& rParam1, hkCdVertex& rParam2) const;
    virtual void
    convertVertexIdsToVerticesImpl(const u16* pParam1, s32 s32Param2, hkCdVertex* pParam3) const;
    virtual void getCentreImpl(hkVector4& rParam1) const;

    void setHalfExtents(const hkVector4& rParam1);

    hkVector4 m_halfExtents; // offset 0x20, size 0x10
};

// total size: 0x14
class hkSphereShape : public hkConvexShape {
public:
    hkSphereShape(f32 f32Param1);
    virtual ~hkSphereShape() {}
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual s32 calcSizeForSpu(s32 s32Param1) const { return 20; }
    virtual void getAabbImpl(const hkTransform& rParam1, f32 f32Param2, hkAabb& rParam3) const;
    virtual hkBool castRayImpl(const hkShapeRayCastInput& rParam1,
                               hkShapeRayCastOutput& rParam2) const;
    virtual s32 getNumCollisionSpheresImpl() const;
    virtual void getCollisionSpheresImpl(hkSphere* pParam1) const;
    virtual void getFirstVertex(hkVector4& rParam1) const;
    virtual void getSupportingVertexImpl(const hkVector4& rParam1, hkCdVertex& rParam2) const;
    virtual void
    convertVertexIdsToVerticesImpl(const u16* pParam1, s32 s32Param2, hkCdVertex* pParam3) const;
    virtual void getCentreImpl(hkVector4& rParam1) const;
};

// total size: 0x10
class hkRootCdBodyPair {
public:
    hkCollidable* m_rootCollidableA; // offset 0x0, size 0x4
    u32 m_shapeKeyA;                 // offset 0x4, size 0x4
    hkCollidable* m_rootCollidableB; // offset 0x8, size 0x4
    u32 m_shapeKeyB;                 // offset 0xC, size 0x4
};

// total size: 0x114
class hkAllCdBodyPairCollector : public hkCdBodyPairCollector {
public:
    hkAllCdBodyPairCollector() {}
    virtual ~hkAllCdBodyPairCollector() {}
    virtual void addCdBodyPair(const hkCdBody& rParam1, const hkCdBody& rParam2);

    const hkInplaceArray<hkRootCdBodyPair, 16>* getHits() const { return &m_hits; }

    hkInplaceArray<hkRootCdBodyPair, 16> m_hits; // offset 0x8, size 0x10C
};

// total size: 0x14
class hkAgentNnTrack {
public:
    u32 m_bytesUsedInLastSector;                   // offset 0x0, size 0x4
    hkInplaceArray<hkAgentNnSector*, 1> m_sectors; // offset 0x4, size 0x10
};

// total size: 0x10
class hkConstraintInfo {
public:
    s32 m_maxSizeOfSchema;    // offset 0x0, size 0x4
    s32 m_sizeOfSchemas;      // offset 0x4, size 0x4
    s32 m_numSolverResults;   // offset 0x8, size 0x4
    s32 m_numSolverElemTemps; // offset 0xC, size 0x4
};

// total size: 0x20
class hkModifierConstraintAtom : public hkConstraintAtom {
public:
    void addModifierDataToConstraintInfo(hkConstraintInfo& rParam1) const;
    static void addAllModifierDataToConstraintInfo(hkModifierConstraintAtom* pParam1,
                                                   hkConstraintInfo& rParam2);

    u16 m_modifierAtomSize;    // offset 0x10, size 0x2
    u16 m_childSize;           // offset 0x12, size 0x2
    hkConstraintAtom* m_child; // offset 0x14, size 0x4
    u32 m_pad[2];              // offset 0x18, size 0x8
};

// total size: 0x2C
class hkConstraintInstance : public hkReferencedObject {
public:
    enum ConstraintPriority { CONSTRAINT_PRIORITY_INVALID = 0 };

    hkConstraintInstance(hkEntity* pParam1,
                         hkEntity* pParam2,
                         hkConstraintData* pParam3,
                         ConstraintPriority sParam4);
    hkConstraintInstance(ConstraintPriority sParam1);
    virtual ~hkConstraintInstance();
    virtual void entityAddedCallback(hkEntity* pParam1);
    virtual void entityRemovedCallback(hkEntity* pParam1);
    virtual void entityDeletedCallback(hkEntity* pParam1);
    virtual s32 getType() const { return 0; }

    void setPriority(ConstraintPriority sParam1);
    void pointNullsToFixedRigidBody();

    hkConstraintOwner* m_owner;                      // offset 0x8, size 0x4
    hkConstraintData* m_data;                        // offset 0xC, size 0x4
    hkModifierConstraintAtom* m_constraintModifiers; // offset 0x10, size 0x4
    hkEntity* m_entities[2];                         // offset 0x14, size 0x8
    hkEnum<u8> m_priority;                           // offset 0x1C, size 0x1
    hkBool m_wantRuntime;                            // offset 0x1D, size 0x1
    c8* m_name;                                      // offset 0x20, size 0x4
    u32 m_userData;                                  // offset 0x24, size 0x4
    hkConstraintInternal* m_internal;                // offset 0x28, size 0x4
};

// total size: 0xC
class hkConstraintData : public hkReferencedObject {
public:
    class ConstraintInfo {};
    class RuntimeInfo {};

    virtual ~hkConstraintData() {}
    virtual hkSolverResults* getSolverResults(void* pvParam1);
    virtual void addInstance(hkConstraintInstance* pParam1, void* pvParam2, s32 s32Param3) const;
    virtual void buildJacobian(const hkConstraintQueryIn& rParam1, hkConstraintQueryOut& rParam2) {}
    virtual hkBool isBuildJacobianCallbackRequired() { return hkBool(); }
    virtual void buildJacobianCallback(const hkConstraintQueryIn& rParam1) {}

    static void
    getConstraintInfoUtil(const hkConstraintAtom* pParam1, s32 s32Param2, ConstraintInfo& rParam3);

    u32 m_userData; // offset 0x8, size 0x4
};

// total size: 0xA0
class hkHingeLimitsData : public hkConstraintData {
public:
    hkHingeLimitsData();
    virtual ~hkHingeLimitsData() {}
    virtual hkBool isValid() const;
    virtual s32 getType() const;
    virtual void getRuntimeInfo(hkBool sParam1, hkConstraintData::RuntimeInfo& rParam2) const;
    virtual void getConstraintInfo(hkConstraintData::ConstraintInfo& rParam1) const;

    void setInBodySpace(const hkVector4& rParam1,
                        const hkVector4& rParam2,
                        const hkVector4& rParam3,
                        const hkVector4& rParam4);

    Atoms m_atoms; // offset 0x10, size 0x90
};

// total size: 0xC
class hkConstraintChainData : public hkConstraintData {
public:
    virtual ~hkConstraintChainData() {}
};

// total size: 0x3C
class hkConstraintChainInstance : public hkConstraintInstance {
public:
    hkConstraintChainInstance(hkConstraintChainData* pParam1);
    virtual ~hkConstraintChainInstance();
    virtual void entityRemovedCallback(hkEntity* pParam1);
    virtual s32 getType() const { return 1; }

    void* operator new(size_t size) { return 0; }
    void addEntity(hkEntity* pParam1);

    hkArray<hkEntity*> m_chainedEntities;      // offset 0x2C, size 0xC
    hkConstraintChainInstanceAction* m_action; // offset 0x38, size 0x4
};

// total size: 0x34
class hkBallSocketChainData : public hkConstraintChainData {
public:
    hkBallSocketChainData();
    virtual ~hkBallSocketChainData();
    virtual hkBool isValid() const { return hkBool(); }
    virtual s32 getType() const;
    virtual void getRuntimeInfo(hkBool sParam1, hkConstraintData::RuntimeInfo& rParam2) const;
    virtual void buildJacobian(const hkConstraintQueryIn& rParam1, hkConstraintQueryOut& rParam2);
    virtual void getConstraintInfo(hkConstraintData::ConstraintInfo& rParam1) const;
    virtual s32 getNumConstraintInfos() { return m_infos.m_size; }

    void* operator new(size_t size) { return 0; }
    void addConstraintInfoInBodySpace(const hkVector4& rParam1, const hkVector4& rParam2);

    hkBridgeAtoms m_atoms;  // offset 0xC, size 0xC
    hkArray<void*> m_infos; // offset 0x18, size 0xC
    f32 m_tau;              // offset 0x24, size 0x4
    f32 m_damping;          // offset 0x28, size 0x4
    f32 m_cfm;              // offset 0x2C, size 0x4
    f32 m_maxErrorDistance; // offset 0x30, size 0x4
};

// total size: 0x0
class hkSimpleContactConstraintData : public hkConstraintData {
public:
    hkSimpleContactConstraintData(hkConstraintInstance* pParam1);
    virtual ~hkSimpleContactConstraintData() {}
    virtual hkBool isValid() const;
    virtual s32 getType() const;
    virtual void getRuntimeInfo(hkBool sParam1, hkConstraintData::RuntimeInfo& rParam2) const;
    virtual hkSolverResults* getSolverResults(void* pvParam1);
    virtual void getConstraintInfo(hkConstraintData::ConstraintInfo& rParam1) const;
    virtual void collisionResponseBeginCallback(const hkContactPoint& rParam1,
                                                hkSimpleConstraintInfoInitInput& rParam2,
                                                hkBodyVelocity& rParam3,
                                                hkSimpleConstraintInfoInitInput& rParam4,
                                                hkBodyVelocity& rParam5);
    virtual void collisionResponseEndCallback(const hkContactPoint& rParam1,
                                              f32 f32Param2,
                                              hkSimpleConstraintInfoInitInput& rParam3,
                                              hkBodyVelocity& rParam4,
                                              hkSimpleConstraintInfoInitInput& rParam5,
                                              hkBodyVelocity& rParam6);

    void allocateContactPoint(hkConstraintOwner& rParam1,
                              hkContactPoint** pParam2,
                              hkContactPointProperties** pParam3);
    void freeContactPoint(hkConstraintOwner& rParam1, u16 u16Param2);
};

// total size: 0x18
class hkConstraintOwner : public hkReferencedObject {
public:
    virtual ~hkConstraintOwner() {}
    virtual void addConstraintToCriticalLockedIsland(hkConstraintInstance* pParam1) {}
    virtual void removeConstraintFromCriticalLockedIsland(hkConstraintInstance* pParam1) {}
    virtual void addCallbackRequest(hkConstraintInstance* pParam1, s32 s32Param2) {}
    virtual void checkAccessRw() {}

    hkConstraintInfo m_constraintInfo; // offset 0x8, size 0x10
};

// total size: 0x70
class hkSimulationIsland : public hkConstraintOwner {
public:
    hkSimulationIsland(hkWorld* pParam1);
    virtual ~hkSimulationIsland();
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual void addConstraintToCriticalLockedIsland(hkConstraintInstance* pParam1);
    virtual void removeConstraintFromCriticalLockedIsland(hkConstraintInstance* pParam1);
    virtual void addCallbackRequest(hkConstraintInstance* pParam1, s32 s32Param2);

    void internalAddEntity(hkEntity* pParam1);
    void internalRemoveEntity(hkEntity* pParam1);
    void addAction(hkAction* pParam1);
    void removeAction(hkAction* pParam1);
    hkBool isFullyConnected(hkUnionFind& rParam1);
    hkBool shouldDeactivateDeprecated(const hkStepInfo& rParam1);
    void mergeConstraintInfo(hkSimulationIsland& rParam1);

    hkWorld* m_world;                        // offset 0x18, size 0x4
    s32 m_numConstraints;                    // offset 0x1C, size 0x4
    u16 m_storageIndex;                      // offset 0x20, size 0x2
    u16 m_dirtyListIndex;                    // offset 0x22, size 0x2
    u8 m_splitCheckFrameCounter;             // offset 0x24, size 0x1
    u8 m_highFrequencyDeactivationCounter;   // offset 0x25, size 0x1
    u8 m_lowFrequencyDeactivationCounter;    // offset 0x26, size 0x1
    u8 m_splitCheckRequested : 2;            // offset 0x27, size 0x1
    u8 m_sparseEnabled : 2;                  // offset 0x27, size 0x1
    u8 m_actionListCleanupNeeded : 2;        // offset 0x27, size 0x1
    u8 m_allowIslandLocking : 2;             // offset 0x27, size 0x1
    u8 m_isInActiveIslandsArray : 2;         // offset 0x28, size 0x1
    u8 m_active : 2;                         // offset 0x28, size 0x1
    u8 m_inIntegrateJob : 2;                 // offset 0x28, size 0x1
    hkMultiThreadCheck m_multiThreadCheck;   // offset 0x2C, size 0x8
    f32 m_timeSinceLastHighFrequencyCheck;   // offset 0x34, size 0x4
    f32 m_timeSinceLastLowFrequencyCheck;    // offset 0x38, size 0x4
    hkArray<hkAction*> m_actions;            // offset 0x3C, size 0xC
    f32 m_timeOfDeactivation;                // offset 0x48, size 0x4
    hkInplaceArray<hkEntity*, 1> m_entities; // offset 0x4C, size 0x10
    hkAgentNnTrack m_agentTrack;             // offset 0x5C, size 0x14
};

// total size: 0x4
class FreeElem {
public:
    FreeElem* m_next; // offset 0x0, size 0x4
};

// total size: 0x8
class FreeList {
public:
    FreeElem* m_head; // offset 0x0, size 0x4
    s32 m_numElem;    // offset 0x4, size 0x4
};

// total size: 0x10
class Stack {
public:
    c8* m_current; // offset 0x0, size 0x4
    Stack* m_prev; // offset 0x4, size 0x4
    c8* m_base;    // offset 0x8, size 0x4
    c8* m_end;     // offset 0xC, size 0x4
};

// total size: 0xA0
class hkAabbPhantom : public hkPhantom {
public:
    hkAabbPhantom(const hkAabb& rParam1, u32 u32Param2);
    virtual ~hkAabbPhantom();
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;
    virtual void* getMotionState() { return 0; }
    virtual s32 getType() const;
    virtual void calcAabb(hkAabb& rParam1);
    virtual void addOverlappingCollidable(hkCollidable* pParam1);
    virtual hkBool isOverlappingCollidableAdded(hkCollidable* pParam1);
    virtual void removeOverlappingCollidable(hkCollidable* pParam1);
    virtual hkAabbPhantom* clone() const;
    virtual void deallocateInternalArrays();

    void setAabb(const hkAabb& rParam1);
    hkArray<hkCollidable*>* getOverlappingCollidables() { return &m_overlappingCollidables; }

    hkAabb m_aabb;                                   // offset 0x70, size 0x20
    hkArray<hkCollidable*> m_overlappingCollidables; // offset 0x90, size 0xC
};

// total size: 0x314
class hkThreadMemory {
public:
    hkThreadMemory(hkMemory* pParam1, s32 s32Param2);
    virtual void* alignedAllocate(s32 s32Param1, s32 s32Param2, HK_MEMORY_CLASS sParam3);
    virtual void alignedDeallocate(void* pvParam1);
    virtual void setStackArea(void* pvParam1, s32 s32Param2);
    virtual void releaseCachedMemory();
    virtual ~hkThreadMemory();
    virtual void* onStackOverflow(s32 s32Param1);
    virtual void onStackUnderflow(void* pvParam1);

    void removeReference();
    void addReference();
    void onRowEmpty(s32 s32Param1);
    void onRowFull(s32 s32Param1, s32 s32Param2);
    void* allocate(s32 s32Param1, HK_MEMORY_CLASS sParam2);
    void deallocate(void* pvParam1);
    void* allocateChunk(s32 s32Param1, HK_MEMORY_CLASS sParam2);
    void deallocateChunk(void* pvParam1, s32 s32Param2, HK_MEMORY_CLASS sParam3);
    void replaceInstance(hkThreadMemory* pParam1);
    void init();
    void quit();

    static hkThreadMemory* s_threadMemoryInstance;

    hkMemory* m_memory;              // offset 0x4, size 0x4
    s32 m_referenceCount;            // offset 0x8, size 0x4
    Stack m_stack;                   // offset 0xC, size 0x10
    s32 m_stackSize;                 // offset 0x1C, size 0x4
    s32 m_maxNumElemsOnFreeList;     // offset 0x20, size 0x4
    FreeList m_free_list[17];        // offset 0x24, size 0x88
    s32 m_row_to_size_lut[17];       // offset 0xAC, size 0x44
    c8 m_small_size_to_row_lut[513]; // offset 0xF0, size 0x201
    s32 m_large_size_to_row_lut[8];  // offset 0x2F4, size 0x20
};

// total size: 0x28
class hkSimulation : public hkReferencedObject {
public:
    enum FindContacts {
        FIND_CONTACTS_DEFAULT = 0,
    };

    hkSimulation(hkWorld* pParam1);
    virtual ~hkSimulation();

    virtual hkStepResult stepDeltaTime(f32 f32Param1);
    virtual hkStepResult integrate(f32 f32Param1);
    virtual hkStepResult collide();
    virtual hkStepResult advanceTime();
    virtual void collideEntitiesDiscrete(hkEntity** pParam1,
                                         s32 s32Param2,
                                         hkWorld* pParam3,
                                         const hkStepInfo& rParam4,
                                         FindContacts sParam5);
    virtual void resetCollisionInformationForEntities(hkEntity** pParam1,
                                                      s32 s32Param2,
                                                      hkWorld* pParam3,
                                                      hkBool sParam4);
    virtual void assertThereIsNoCollisionInformationForEntities(hkEntity** pParam1,
                                                                s32 s32Param2,
                                                                hkWorld* pParam3)
    {
    }
    virtual void removeCollisionInformationForAgent(hkAgentNnEntry* pParam1) {}
    virtual void assertThereIsNoCollisionInformationForAgent(hkAgentNnEntry* pParam1) {}
    virtual void reintegrateAndRecollideEntities(hkEntity** pParam1,
                                                 s32 s32Param2,
                                                 hkWorld* pParam3,
                                                 s32 s32Param4);
    virtual hkStepResult collideInternal(const hkStepInfo& rParam1);
    virtual void warpTime(f32 f32Param1) {}

    hkStepResult reCollideAfterStepFailure();
    f32 snapSimulateTimeAndGetTimeToAdvanceTo();
    hkStepResult
    collideEntitiesBroadPhaseDiscrete(hkEntity** pParam1, s32 s32Param2, hkWorld* pParam3);
    hkStepResult integrateInternal(const hkStepInfo& rParam1);
    void applyActions();
    void collideEntitiesNarrowPhaseDiscrete(hkEntity** pParam1,
                                            s32 s32Param2,
                                            const hkProcessCollisionInput& rParam3,
                                            FindContacts sParam4);
    void processAgentCollideDiscrete(hkAgentNnEntry* pParam1,
                                     const hkProcessCollisionInput& rParam2,
                                     hkProcessCollisionOutput& rParam3);
    void processAgentResetCollisionInformation(hkAgentNnEntry* pParam1,
                                               const hkProcessCollisionInput& rParam2,
                                               hkProcessCollisionOutput& rParam3);
    void processAgentsOfEntities(hkEntity** pParam1,
                                 s32 s32Param2,
                                 const hkProcessCollisionInput& rParam3,
                                 void (hkSimulation::*pvParam4)(hkAgentNnEntry*,
                                                                const hkProcessCollisionInput&,
                                                                hkProcessCollisionOutput&),
                                 FindContacts sParam5);

    hkWorld* m_world;                        // offset 0x8, size 0x4
    LastProcessingStep m_lastProcessingStep; // offset 0xC, size 0x4
    f32 m_currentTime;                       // offset 0x10, size 0x4
    f32 m_currentPsiTime;                    // offset 0x14, size 0x4
    f32 m_physicsDeltaTime;                  // offset 0x18, size 0x4
    f32 m_simulateUntilTime;                 // offset 0x1C, size 0x4
    f32 m_frameMarkerPsiSnap;                // offset 0x20, size 0x4
    hkStepResult m_previousStepResult;       // offset 0x24, size 0x4
};

// total size: 0x18
class hkAction : public hkReferencedObject {
public:
    virtual ~hkAction() {}
    virtual void getPhantoms(hkArray<hkPhantom*>& rParam1) {}

    hkWorld* m_world;             // offset 0x8, size 0x4
    hkSimulationIsland* m_island; // offset 0xC, size 0x4
    u32 m_userData;               // offset 0x10, size 0x4
    c8* m_name;                   // offset 0x14, size 0x4
};

// total size: 0x0
class hkConstraintChainInstanceAction : public hkAction {
public:
    virtual ~hkConstraintChainInstanceAction() {}
    virtual void applyAction(const hkStepInfo& rParam1);
    virtual void getEntities(hkArray<hkEntity*>& rParam1);
    virtual void entityRemovedCallback(hkEntity* pParam1);
    virtual hkAction* clone(const hkArray<hkEntity*>& rParam1,
                            const hkArray<hkPhantom*>& rParam2) const;
};

// total size: 0x1C
class hkUnaryAction : public hkAction {
public:
    hkUnaryAction(hkEntity* pParam1, u32 u32Param2);
    virtual ~hkUnaryAction();

    virtual void getEntities(hkArray<hkEntity*>& rParam1);
    virtual void entityRemovedCallback(hkEntity* pParam1);

    hkEntity* m_entity; // offset 0x18, size 0x4
};

class InternalInertiaTensorComputer {
public:
    void compProjectionIntegrals(const hkVector4* psParam1);
    void compFaceIntegrals(const hkVector4* psParam1, const hkVector4& rsParam2);
    void compVolumeIntegrals(const hkGeometry* pcParam1, const hkVector4& rsParam2);
    void computeInertialTensorInternal(f32 f32Param1,
                                       f32 f32Param2,
                                       hkVector4& rsParam3,
                                       hkMatrix3& rcParam4);
    void compGeometryAabb(const hkVector4* psParam1,
                          s32 s32Param2,
                          hkVector4& rsParam3,
                          hkVector4& rsParam4);
};

// === No-DWARF stubs: stream base classes ===

class hkStreamWriter {
public:
    enum SeekWhence { STREAM_SET = 0 };
    virtual ~hkStreamWriter() {}
    virtual bool write(const void*, s32) { return false; }
    virtual void flush() {}
    virtual bool seekTellSupported() const { return false; }
    virtual bool seek(s32, SeekWhence) { return false; }
    virtual s32 tell() const { return -1; }
};

class hkStreamReader {
public:
    enum SeekWhence { STREAM_SET = 0 };
    virtual ~hkStreamReader() {}
    virtual s32 read(void*, s32) { return 0; }
    virtual s32 skip(s32 numBytes);
    virtual bool markSupported() const { return false; }
    virtual bool setMark(s32) { return false; }
    virtual void rewindToMark() {}
    virtual bool seekTellSupported() const { return false; }
    virtual bool seek(s32, SeekWhence) { return false; }
    virtual s32 tell() const { return -1; }
};

// === No-DWARF stubs: motion classes ===

class hkBoxMotion {
public:
    hkBoxMotion(const hkVector4&, const hkQuaternion&) {}
    virtual ~hkBoxMotion() {}
    virtual void getInertiaLocal(hkMatrix3&) const {}
    virtual void setInertiaLocal(const hkMatrix3&) {}
    virtual void getInertiaInvLocal(hkMatrix3&) const {}
    virtual void setInertiaInvLocal(const hkMatrix3&) {}
    virtual void getInertiaInvWorld(hkMatrix3&) const {}
    virtual void getInertiaWorld(hkMatrix3&) const {}
    virtual void setMass(f32) {}
    virtual void applyPointImpulse(const hkVector4&, const hkVector4&) {}
    virtual void applyAngularImpulse(const hkVector4&) {}
    virtual void applyForce(f32, const hkVector4&) {}
    virtual void applyForce(f32, const hkVector4&, const hkVector4&) {}
    virtual void applyTorque(f32, const hkVector4&) {}
};

class hkStabilizedBoxMotion {
public:
    hkStabilizedBoxMotion(const hkVector4&, const hkQuaternion&) {}
    virtual ~hkStabilizedBoxMotion() {}
};

class hkThinBoxMotion {
public:
    hkThinBoxMotion(const hkVector4&, const hkQuaternion&) {}
    virtual ~hkThinBoxMotion() {}
};

class hkFixedRigidMotion {
public:
    hkFixedRigidMotion(const hkVector4&, const hkQuaternion&) {}
    virtual ~hkFixedRigidMotion() {}
    virtual void setStepPosition(f32, f32) {}
    virtual void getPositionAndVelocities(hkMotion*) {}
};

// === No-DWARF stubs: shape classes ===

class hkCylinderShape {
public:
    f32 getCylinderRadius() const { return 0.0f; }
};

class hkFastMeshShape {
public:
    virtual ~hkFastMeshShape() {}
    virtual const hkShape* getChildShape(u32, c8 (&)[512]) const { return 0; }
};

// === No-DWARF stubs: collector classes ===

class hkFlagCdBodyPairCollector {
public:
    virtual ~hkFlagCdBodyPairCollector() {}
    virtual void addCdBodyPair(const hkCdBody&, const hkCdBody&) {}
};

class hkSymmetricAgentFlipBodyCollector {
public:
    virtual ~hkSymmetricAgentFlipBodyCollector() {}
    virtual void addCdBodyPair(const hkCdBody&, const hkCdBody&) {}
};

// === No-DWARF stubs: utility classes ===

class hkVector4Util {
public:
    static u32 packQuaternionIntoInt32(const hkVector4&) { return 0; }
};

class hkTriangleUtil {
public:
    static bool isDegenerate(const hkVector4&, const hkVector4&, const hkVector4&, f32)
    {
        return false;
    }
};

class hkAabbUtil {
public:
    static void calcAabb(const f32*, s32, s32, hkAabb&) {}
};

class hkSmallArrayUtil {
public:
    static void _reserve(void*, s32, s32) {}
    static void _reserveMore(void*, s32) {}
};

class hkMoppBvTreeStreamAgent {
public:
    static void registerAgent(hkCollisionDispatcher*) {}
};

// === No-DWARF stubs: constraint atom classes ===

class hkMassChangerModifierConstraintAtom {
public:
    virtual void collisionResponseBeginCallback(const hkContactPoint&,
                                                hkSimpleConstraintInfoInitInput&,
                                                hkBodyVelocity&,
                                                hkSimpleConstraintInfoInitInput&,
                                                hkBodyVelocity&)
    {
    }
    virtual void collisionResponseEndCallback(const hkContactPoint&,
                                              f32,
                                              hkSimpleConstraintInfoInitInput&,
                                              hkBodyVelocity&,
                                              hkSimpleConstraintInfoInitInput&,
                                              hkBodyVelocity&)
    {
    }
};

class hkMovingSurfaceModifierConstraintAtom {
public:
    virtual void collisionResponseBeginCallback(const hkContactPoint&,
                                                hkSimpleConstraintInfoInitInput&,
                                                hkBodyVelocity&,
                                                hkSimpleConstraintInfoInitInput&,
                                                hkBodyVelocity&)
    {
    }
    virtual void collisionResponseEndCallback(const hkContactPoint&,
                                              f32,
                                              hkSimpleConstraintInfoInitInput&,
                                              hkBodyVelocity&,
                                              hkSimpleConstraintInfoInitInput&,
                                              hkBodyVelocity&)
    {
    }
};

// === No-DWARF stubs: error/tracer classes ===

class hkErrStream {
public:
    hkErrStream(void*, s32) {}
    virtual ~hkErrStream() {}
};

class hkStackTracer {
public:
    hkStackTracer() {}
    virtual ~hkStackTracer() {}
    void dumpStackTrace(const u32*, s32, void (*)(const c8*, void*), void*) {}
    s32 getStackTrace(u32*, s32) { return 0; }
};

// === No-DWARF stubs: deactivator / monitor ===

class hkFakeRigidBodyDeactivator {
public:
    virtual ~hkFakeRigidBodyDeactivator() {}
    virtual s32 getRigidBodyDeactivatorType() const { return 0; }
    virtual bool shouldDeactivateHighFrequency(const hkEntity*) { return false; }
    virtual bool shouldDeactivateLowFrequency(const hkEntity*) { return false; }
    static hkFakeRigidBodyDeactivator m_fakeRigidBodyDeactivator;
};

class hkMonitorStream {
public:
    void init();
    void quit();
    static hkMonitorStream m_instance;
};

class hkWeldingUtility {
public:
    static void initWeldingTable(f32, f32);
    static u8 m_sinCosTable[744];
};

// === No-DWARF stubs: batch 3 ===

class hkUnionFind {
public:
    hkUnionFind(hkFixedArray<s32>& arr, s32 n);
    void addEdge(s32 a, s32 b);
    void collapseTree();
    void assignGroups(hkArray<s32>& groups);
    void moveBiggestGroupToIndexZero(hkArray<s32>& groups);
    void reindex(const hkFixedArray<s32>& arr, s32 n, hkArray<s32>& groups);
};

class hkDebugDisplay {
public:
    hkDebugDisplay() {}
    virtual ~hkDebugDisplay() {}
    virtual void unused0() {}
    virtual void unused1() {}
};

class hkString {
public:
    static void snprintf(c8* buf, s32 n, const c8* fmt, ...);
    static void sprintf(c8* buf, const c8* fmt, ...);
    static s32 strLen(const c8* s);
    static void memCpy(void* dst, const void* src, s32 n);
    static void memMove(void* dst, const void* src, s32 n);
    static void memSet(void* ptr, s32 val, s32 n);
    hkString operator+(const hkString&) const { return hkString(); }
    bool beginsWith(const c8* p) const
    {
        (void)p;
        return false;
    }
    static c8 s_emptyStringRep[13];
};

class hkGeometryUtility {
public:
    static void createConvexGeometry(const hkStridedVertices&,
                                     hkGeometry&,
                                     hkArray<hkVector4>&,
                                     hkGeomConvexHullMode);
};

class hkSoftContactModifierConstraintAtom {
public:
    virtual ~hkSoftContactModifierConstraintAtom() {}
    virtual void collisionResponseBeginCallback(const hkContactPoint&,
                                                hkSimpleConstraintInfoInitInput&,
                                                hkBodyVelocity&,
                                                hkSimpleConstraintInfoInitInput&,
                                                hkBodyVelocity&)
    {
    }
    virtual void collisionResponseEndCallback(const hkContactPoint&,
                                              f32,
                                              hkSimpleConstraintInfoInitInput&,
                                              hkBodyVelocity&,
                                              hkSimpleConstraintInfoInitInput&,
                                              hkBodyVelocity&)
    {
    }
};

class hkArrayUtil {
public:
    static void _reserve(void*, s32, s32);
    static void _reserveMore(void*, s32);
    static void _reduce(void*, s32, c8*, s32);
};

class hkProcessFactory {
public:
    hkProcessFactory() {}
    virtual ~hkProcessFactory() {}
    virtual void unused0() {}
    virtual void unused1() {}
};

class hkSpatialRigidBodyDeactivator {
public:
    hkSpatialRigidBodyDeactivator() {}
    virtual ~hkSpatialRigidBodyDeactivator() {}
    virtual s32 getRigidBodyDeactivatorType() const { return 0; }
    virtual bool shouldDeactivateHighFrequency(const hkEntity*) { return false; }
    virtual bool shouldDeactivateLowFrequency(const hkEntity*) { return false; }
};

class hkMath {
public:
    static f32 hkFloor(f32 v);
    static s32 hkFloorToInt(f32 v);
    static s32 hkFloatToInt(f32 v);
    static bool isNegative(f32 v);
};

class hkSphereMotion {
public:
    virtual ~hkSphereMotion() {}
    virtual void getInertiaLocal(hkMatrix3&) const {}
    virtual void getInertiaWorld(hkMatrix3&) const {}
    virtual void setInertiaLocal(const hkMatrix3&) {}
    virtual void setInertiaInvLocal(const hkMatrix3&) {}
    virtual void getInertiaInvLocal(hkMatrix3&) const {}
    virtual void getInertiaInvWorld(hkMatrix3&) const {}
    virtual void applyPointImpulse(const hkVector4&, const hkVector4&) {}
    virtual void applyAngularImpulse(const hkVector4&) {}
    virtual void applyForce(f32, const hkVector4&) {}
    virtual void applyForce(f32, const hkVector4&, const hkVector4&) {}
    virtual void applyTorque(f32, const hkVector4&) {}
};

class hkMatrix6 {
public:
    void setInvert(const hkMatrix6&);
};

class hkTriangleContainerCompressor {
public:
    hkTriangleContainerCompressor(const hkShapeContainer*, const u8*) {}
    virtual ~hkTriangleContainerCompressor() {}
    virtual s32 calcPrimitivesSize(const u32*, s32) const { return 0; }
    virtual void storePrimitives(const u32*, s32, s32, u8*) const {}
    virtual void unused0() {}
};

class hkDefaultWorldMaintenanceMgr {
public:
    hkDefaultWorldMaintenanceMgr() {}
    virtual ~hkDefaultWorldMaintenanceMgr() {}
    virtual void init(hkWorld*) {}
    virtual void performMaintenance(hkWorld*, hkStepInfo&) {}
    virtual void performMaintenanceNoSplit(hkWorld*, hkStepInfo&) {}
    virtual void unused0() {}
    virtual void unused1() {}
};

class hkBaseSystem {
public:
    static void initSingletons();
    static void quitSingletons();
    static void initThread(hkThreadMemory*);
    static void init(hkMemory*, hkThreadMemory*, void (*)(const c8*, void*), void*);
    static void clearThreadResources();
    static void quit();
};

class hkWorldConstraintUtil {
public:
    static void addConstraint(hkWorld*, hkConstraintInstance*);
    static void removeConstraint(hkConstraintInstance*);
    static void updateFatherOfMovedAtom(hkConstraintInstance*,
                                        const hkConstraintAtom*,
                                        const hkConstraintAtom*,
                                        s32);
};

class hkCollideTriangleUtil {
public:
    struct ClosestLineSegLineSegResult {
        hkVector4 m_pointA;
        hkVector4 m_pointB;
    };
    struct ClosestPointLineSegResult {
        hkVector4 m_closestPoint;
    };
    struct ClosestPointTriangleCache {
        hkVector4 m_data[4];
    };
    struct ClosestPointTriangleResult {
        hkVector4 m_closestPoint;
    };

    static void calcBarycentricCoordinates(
        const hkVector4&, const hkVector4&, const hkVector4&, const hkVector4&, hkPadSpu&);
    static void closestLineSegLineSeg(const hkVector4&,
                                      const hkVector4&,
                                      const hkVector4&,
                                      const hkVector4&,
                                      ClosestLineSegLineSegResult&);
    static void closestPointLineSeg(const hkVector4&,
                                    const hkVector4&,
                                    const hkVector4&,
                                    ClosestPointLineSegResult&);
    static void setupClosestPointTriangleCache(const hkVector4*, ClosestPointTriangleCache&);
    static void closestPointTriangle(const hkVector4&,
                                     const hkVector4*,
                                     const ClosestPointTriangleCache&,
                                     ClosestPointTriangleResult&);
    static u32 maskToIndex[16];
    static u8 vertexToEdgeLut[5];
};

class hkSweptTransformUtil {
public:
    static void lerp2(const hkSweptTransform&, f32, hkTransform&);
    static void lerp2Ha(const hkSweptTransform&, f32, f32, hkTransform&);
    static void backStepMotionState(f32, hkMotionState&);
    static void freezeMotionState(f32, hkMotionState&);
    static void setTimeInformation(f32, f32, hkMotionState&);
    static void warpTo(const hkVector4&, const hkQuaternion&, hkMotionState&);
    static void warpTo(const hkTransform&, hkMotionState&);
    static void warpToPosition(const hkVector4&, hkMotionState&);
    static void warpToRotation(const hkQuaternion&, hkMotionState&);
    static void setCentreOfRotationLocal(const hkVector4&, hkMotionState&);
};

// === No-DWARF stubs: batch 4 ===

class hkNullBroadPhaseListener {
public:
    virtual ~hkNullBroadPhaseListener() {}
    virtual void addCollisionPair(hkTypedBroadPhaseHandlePair&) {}
    virtual void removeCollisionPair(hkTypedBroadPhaseHandlePair&) {}
    virtual void unused0() {}
    virtual void unused1() {}
};

class hkDefaultConvexListFilter {
public:
    virtual ~hkDefaultConvexListFilter() {}
    virtual s32
    getConvexListCollisionType(const hkCdBody&, const hkCdBody&, const hkCollisionInput&) const
    {
        return 0;
    }
    virtual void unused0() {}
    virtual void unused1() {}
    virtual void unused2() {}
};

class hkSimpleClosestContactCollector {
public:
    virtual ~hkSimpleClosestContactCollector() {}
    virtual void addCdPoint(const hkCdPoint&) {}
};

class hkSymmetricAgentFlipCollector {
public:
    virtual ~hkSymmetricAgentFlipCollector() {}
    virtual void addCdPoint(const hkCdPoint&) {}
};

class hkSymmetricAgentFlipCastCollector {
public:
    virtual ~hkSymmetricAgentFlipCastCollector() {}
    virtual void addCdPoint(const hkCdPoint&) {}
};

class hkClosestCdPointCollector {
public:
    virtual ~hkClosestCdPointCollector() {}
    virtual void addCdPoint(const hkCdPoint&) {}
};

class hkOstream {
public:
    hkOstream(hkStreamWriter*) {}
    virtual ~hkOstream() {}
    hkOstream& operator<<(c8) { return *this; }
    hkOstream& operator<<(const c8*) { return *this; }
    hkOstream& operator<<(s32) { return *this; }
    hkOstream& operator<<(u32) { return *this; }
};

class hkAgentMachineUtil {
public:
    static void calc1nStatistics(const hkAgent1nTrack&, hkStatisticsCollector*);
    static void calcNnStatistics(const hkAgentNnTrack&, hkStatisticsCollector*);
    static void calcNnStatisticsContactMgrsOnly(const hkAgentNnTrack&, hkStatisticsCollector*);
};

class hkSimpleContactConstraintAtomUtil {
public:
    static hkSimpleContactConstraintAtom* allocateAtom(s32);
    static void deallocateAtom(hkSimpleContactConstraintAtom*);
    static void copyContents(hkSimpleContactConstraintAtom*, const hkSimpleContactConstraintAtom*);
    static hkSimpleContactConstraintAtom* expandOne(hkSimpleContactConstraintAtom*);
    static void removeAtAndCopy(hkSimpleContactConstraintAtom*, s32);
    static void optimizeCapacity(hkSimpleContactConstraintAtom*, s32);
};

class hkMoppUtility {
public:
    static void buildCode(const hkShapeContainer*,
                          const hkMoppCompilerInput&,
                          hkArray<hkMoppCodeReindexedTerminal>*);
    static void buildCodeInternal(hkMoppMediator&,
                                  const hkShapeContainer*,
                                  const hkMoppCompilerInput&,
                                  hkArray<hkMoppCodeReindexedTerminal>*);
};

class hkWorldOperationUtil {
public:
    enum FireCallbacks { DO_FIRE_CALLBACKS = 0 };

    static void updateEntityBP(hkWorld*, hkEntity*);
    static void addEntityBP(hkWorld*, hkEntity*);
    static void addPhantomBP(hkWorld*, hkPhantom*);
    static void addEntitySI(hkWorld*, hkEntity*, hkEntityActivation);
    static void removeEntityBP(hkWorld*, hkEntity*);
    static void removePhantomBP(hkWorld*, hkPhantom*);
    static void removeEntitySI(hkWorld*, hkEntity*);
    static void removeAttachedActionsFromFixedIsland(hkWorld*, hkEntity*, hkArray<hkAction*>&);
    static void removeAttachedActionsFromDynamicIsland(hkWorld*, hkEntity*, hkArray<hkAction*>&);
    static void addActionsToEntitysIsland(hkWorld*, hkEntity*, hkArray<hkAction*>&);
    static void removeIsland(hkWorld*, hkSimulationIsland*);
    static void addConstraintToCriticalLockedIsland(hkWorld*, hkConstraintInstance*);
    static void removeConstraintFromCriticalLockedIsland(hkWorld*, hkConstraintInstance*);
    static void addConstraintImmediately(hkWorld*, hkConstraintInstance*, FireCallbacks);
    static void removeConstraintImmediately(hkWorld*, hkConstraintInstance*, FireCallbacks);
    static void splitSimulationIsland(hkSimulationIsland*,
                                      hkWorld*,
                                      hkArray<hkSimulationIsland*>&,
                                      hkArray<hkEntity*>*);
    static void splitSimulationIsland(hkWorld*, hkSimulationIsland*);
    static void splitSimulationIslands(hkWorld*);
    static void mergeIslands(hkWorld*, hkEntity*, hkEntity*);
    static void internalMergeTwoIslands(hkWorld*, hkSimulationIsland*, hkSimulationIsland*);
    static void setRigidBodyMotionType(hkRigidBody*,
                                       hkMotion::MotionType,
                                       hkEntityActivation,
                                       hkUpdateCollisionFilterOnEntityMode);
    static void removeAttachedConstraints(hkEntity*, hkArray<hkConstraintInstance*>&);
    static void removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(
        hkAgentNnTrack&, hkEntity*, hkAgentNnTrack&, hkMotion::MotionType);
    static void cleanupDirtyIslands(hkWorld*);
    static void internalActivateIsland(hkWorld*, hkSimulationIsland*);
    static void internalDeactivateIsland(hkWorld*, hkSimulationIsland*);
    static void markIslandInactive(hkWorld*, hkSimulationIsland*);
    static void markIslandActive(hkWorld*, hkSimulationIsland*);
    static void removeIslandFromDirtyList(hkWorld*, hkSimulationIsland*);
    static void replaceMotionObject(hkRigidBody*, hkMotion::MotionType, hkBool, hkBool, hkWorld*);
};

// === No-DWARF stubs: batch 5+ remaining classes ===

class hkBufferedStreamWriter {
public:
    hkBufferedStreamWriter(hkStreamWriter*, s32);
    hkBufferedStreamWriter(void*, s32, hkBool);
    virtual ~hkBufferedStreamWriter();
    virtual void flushBuffer();
    virtual hkBool write(const void*, s32);
    virtual void flush();
    virtual hkBool seek(s32, SeekWhence);
};

class hkBufferedStreamReader {
public:
    hkBufferedStreamReader(hkStreamReader*, s32);
    virtual ~hkBufferedStreamReader();
    virtual void prepareBufferForRefill();
    virtual void refillBuffer();
    virtual s32 read(void*, s32);
    virtual s32 skip(s32);
    virtual hkBool setMark(s32);
    virtual void rewindToMark();
    virtual hkBool seek(s32, SeekWhence);
};

class hkMoppShapeMediator {
public:
    hkMoppShapeMediator(const hkShapeContainer*);
    virtual ~hkMoppShapeMediator();
    virtual void setSplittingPlaneDirections(const hkMoppSplittingPlaneDirection*, s32);
    virtual void getPrimitiveProperties(const hkMoppCompilerPrimitive&, u32*);
    virtual void
    projectPrimitives(const hkVector4&, s32, hkMoppCompilerPrimitive*, s32, f32*, f32*);
    virtual void
    findExtents(const hkVector4&, s32, const hkMoppCompilerPrimitive*, s32, f32*, f32*);
    virtual void getPrimitives(hkMoppCompilerPrimitive*);
    virtual void splitPrimitive(
        const hkMoppCompilerPrimitive&, const hkVector4&, f32, s32, hkMoppCompilerPrimitive*);
    virtual s32 getNumPrimitives();
};

class hkMoppCachedShapeMediator {
public:
    hkMoppCachedShapeMediator(const hkShapeContainer*);
    virtual ~hkMoppCachedShapeMediator();
    void addConvexShape(const hkConvexShape*, u32, const hkMoppSplittingPlaneDirection*, s32);
    virtual void setSplittingPlaneDirections(const hkMoppSplittingPlaneDirection*, s32);
    virtual void getPrimitiveProperties(const hkMoppCompilerPrimitive&, u32*);
    virtual void
    projectPrimitives(const hkVector4&, s32, hkMoppCompilerPrimitive*, s32, f32*, f32*);
    virtual void
    findExtents(const hkVector4&, s32, const hkMoppCompilerPrimitive*, s32, f32*, f32*);
    virtual void getPrimitives(hkMoppCompilerPrimitive*);
    virtual void splitPrimitive(
        const hkMoppCompilerPrimitive&, const hkVector4&, f32, s32, hkMoppCompilerPrimitive*);
    virtual s32 getNumPrimitives();
};

class hkMoppSphereVirtualMachine {
public:
    class hkMoppSphereVirtualMachineQuery {};
    void querySphereOnTree(const hkMoppSphereVirtualMachineQuery*, const u8*);
    void querySphere(const hkMoppCode*, const hkSphere&, hkArray<hkMoppPrimitiveInfo>*);
};

class hkMoppObbVirtualMachine {
public:
    void queryAabbOnTree(const hkMoppObbVirtualMachineQuery*, const u8*, s32);
    void queryObb(const hkMoppCode*,
                  const hkTransform&,
                  const hkVector4&,
                  f32,
                  hkArray<hkMoppPrimitiveInfo>*);
    void queryAabb(const hkMoppCode*, const hkAabb&, hkArray<hkMoppPrimitiveInfo>*);
};

class hkIterativeLinearCastAgent {
public:
    virtual ~hkIterativeLinearCastAgent();
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
};

class hkWingedEdge {
public:
    class Triangle {};
    class Edge {};
    class Vertex {};
    void findVisibilityBoundaryEdges(Triangle*, const hkVector4&, s32&, Edge*&);
    void findVisibleTriangles(Triangle*, const hkVector4&, s32&, Edge*&);
    void allocateTriangles(hkArray<Triangle*>&, s32);
    void patchInBoundaryToPointOfViewExpansion(s32, Edge*, Vertex*);
    void addTetrahedron();
    void findTriangleNearestOrigin(Triangle*);
    void
    find2ClosestMultiTriangles(hkWingedEdge&, hkWingedEdge&, hkVector4&, Triangle*&, Triangle*&);
};

class hkInertiaTensorComputer {
public:
    static void computeSphereVolumeMassProperties(f32, f32, hkMassProperties&);
    static void computeTriangleSurfaceMassProperties(
        const hkVector4&, const hkVector4&, const hkVector4&, f32, f32, hkMassProperties&);
    static void computeBoxVolumeMassProperties(const hkVector4&, f32, hkMassProperties&);
    static void computeVertexHullVolumeMassProperties(const f32*, s32, s32, f32, hkMassProperties&);
    static void computeCapsuleVolumeMassProperties(
        const hkVector4&, const hkVector4&, f32, f32, hkMassProperties&);
    static void computeCylinderVolumeMassProperties(
        const hkVector4&, const hkVector4&, f32, f32, hkMassProperties&);
    static void combineMassProperties(const hkArray<hkMassElement>&, hkMassProperties&);
    static void setShapeVolumeMassProperties(const hkShape*, f32, hkRigidBodyCinfo&);
    static void shiftInertiaToCom(hkVector4&, f32, hkMatrix3&);
    static void shiftInertiaFromCom(hkVector4&, f32, hkMatrix3&);
    static void computeGeometryVolumeMassProperties(const hkGeometry*, f32, hkMassProperties&);
};

class hkSimpleCollisionResponse {
public:
    class SolveSingleOutput {};
    class SolveSingleOutput2 {};
    static void solveSingleContact(const hkContactPoint&,
                                   f32,
                                   hkSimpleConstraintUtilCollideParams&,
                                   hkMotion*,
                                   hkMotion*,
                                   hkDynamicsContactMgr*,
                                   SolveSingleOutput&);
    static void solveSingleContact2(hkSimpleContactConstraintData*,
                                    const hkContactPoint&,
                                    hkSimpleConstraintUtilCollideParams&,
                                    hkRigidBody*,
                                    hkRigidBody*,
                                    hkVelocityAccumulator*,
                                    hkVelocityAccumulator*,
                                    SolveSingleOutput2&);
};

class hkMoppLongRayVirtualMachine {
public:
    class QueryInt {};
    class QueryFloat {};
    void queryRayOnTree(const QueryInt*, const u8*, QueryFloat*, s32);
    void queryLongRay(const hkShapeContainer*,
                      const hkMoppCode*,
                      const hkShapeRayCastInput&,
                      hkShapeRayCastOutput&);
    void queryLongRay(const hkShapeContainer*,
                      const hkMoppCode*,
                      const hkShapeRayCastInput&,
                      const hkCdBody&,
                      hkRayHitCollector&);
};

class hkMoppAabbCastVirtualMachine {
public:
    class hkAabbCastInput {};
    void queryRayOnTree(const hkMoppAabbCastVirtualMachineQueryInt*,
                        const u8*,
                        hkMoppAabbCastVirtualMachineQueryFloat*,
                        s32);
    void aabbCast(const hkAabbCastInput&, hkCdPointCollector&, hkCdPointCollector*);
};

class hkMoppCostFunction {
public:
    hkMoppCostFunction(const hkMoppSplitCostParams&);
    virtual ~hkMoppCostFunction();
    virtual void updateParams(const hkMoppSplitCostParams&);
};

class hkMoppBvTreeShape {
public:
    hkMoppBvTreeShape(const hkShapeCollection*, const hkMoppCode*);
    virtual ~hkMoppBvTreeShape();
};

class hkPredGskfAgent {
public:
    virtual ~hkPredGskfAgent();
    static void registerAgent(hkCollisionDispatcher*);
    static void
    createPredGskfAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
};

class hkConstraintSolverSetup {
public:
    enum SolverMode { SOLVER_MODE_DEFAULT = 0 };
    static void oneStepIntegrate(
        const hkSolverInfo&, const hkStepInfo&, const hkVelocityAccumulator*, hkEntity**, s32);
    static void solve(const hkStepInfo&,
                      const hkSolverInfo&,
                      hkConstraintQueryIn&,
                      hkSimulationIsland&,
                      hkEntity**,
                      s32);
    static void initializeSolverState(
        hkStepInfo&, hkSolverInfo&, hkConstraintQueryIn&, s8*, s32, hkConstraintSolverResources&);
    static void shutdownSolver(hkConstraintSolverResources&);
    static void internalAddAccumulators(hkConstraintSolverResources&, hkEntity**, s32);
    static void internalAddJacobianSchemas(hkConstraintSolverResources&,
                                           hkConstraintInstance**,
                                           s32,
                                           hkArray<hkConstraintSchemaInfo>&);
    static void internalIsMemoryOkForNewAccumulators(hkConstraintSolverResources&, hkEntity**, s32);
    static void internalIsMemoryOkForNewJacobianSchemas(hkConstraintSolverResources&,
                                                        hkConstraintInstance**,
                                                        s32);
    static void subSolve(hkConstraintSolverResources&, SolverMode);
};

class hkEntityCallbackUtil {
public:
    static void fireEntityAdded(hkEntity*);
    static void fireEntityRemoved(hkEntity*);
    static void fireEntityShapeSet(hkEntity*);
    static void fireEntityDeleted(hkEntity*);
    static void fireContactPointAddedInternal(hkEntity*, hkContactPointAddedEvent&);
    static void fireContactPointConfirmedInternal(hkEntity*, hkContactPointConfirmedEvent&);
    static void fireContactPointRemovedInternal(hkEntity*, hkContactPointRemovedEvent&);
    static void fireContactProcessInternal(hkEntity*, hkContactProcessEvent&);
};

class hkContinuousSimulation {
public:
    hkContinuousSimulation(hkWorld*);
    virtual ~hkContinuousSimulation();
    virtual void handleAllToisTill(f32);
    virtual void advanceTime();
    void advanceTimeInternal();
    void reintegrateAndRecollideEntities(hkEntity**, s32, hkWorld*, s32);
    void resetCollisionInformationForEntities(hkEntity**, s32, hkWorld*, hkBool);
    void assertThereIsNoCollisionInformationForEntities(hkEntity**, s32, hkWorld*);
    void removeCollisionInformationForAgent(hkAgentNnEntry*);
    void assertThereIsNoCollisionInformationForAgent(hkAgentNnEntry*);
    virtual void warpTime(f32);
    virtual void collideInternal(const hkStepInfo&);
    void collideEntitiesBroadPhaseContinuous(hkEntity**, s32, hkWorld*, s8*);
    void collideIslandNarrowPhaseContinuous(hkSimulationIsland*, const hkProcessCollisionInput&);
    void collideEntitiesNarrowPhaseContinuous(hkEntity**, s32, const hkProcessCollisionInput&);
    void processAgentCollideContinuous(hkAgentNnEntry*,
                                       const hkProcessCollisionInput&,
                                       hkProcessCollisionOutput&);
    void addToiEvent(const hkProcessCollisionOutput&, const hkAgentNnEntry&);
    void removeToiEventsOfEntities(hkEntity**, s32);
    void removeToiEventsOfEntity(hkEntity*);
    void simulateToi(hkWorld*, hkToiEvent&, f32);
};

class hkNullCollisionFilter {
public:
    virtual ~hkNullCollisionFilter();
};

class hkSimpleWorldRayCaster {
public:
    virtual ~hkSimpleWorldRayCaster();
    virtual void addBroadPhaseHandle(const hkBroadPhaseHandle*, s32);
    virtual void castRay(const hkBroadPhase&,
                         const hkWorldRayCastInput&,
                         const hkCollisionFilter*,
                         s8*,
                         hkWorldRayCastOutput&);
};

class hkGskfAgent {
public:
    hkGskfAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkGskfAgent();
    static void
    createGskfAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void removePoint(u16);
    virtual void commitPotential(u16);
    virtual void createZombie(u16);
    virtual void processCollisionNoTim(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkProcessCollisionInput&,
                                       hkProcessCollisionOutput&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
};

class hkWorldAgentUtil {
public:
    static void addAgent(hkLinkedCollidable*, hkLinkedCollidable*, const hkProcessCollisionInput&);
    static void removeAgent(hkAgentNnEntry*);
    static void removeAgentAndItsToiEvents(hkAgentNnEntry*);
    static void getIslandFromAgentEntry(hkAgentNnEntry*, hkSimulationIsland*, hkSimulationIsland*);
    static void invalidateTim(hkEntity*, hkCollisionInput&);
    static void warpTime(hkSimulationIsland*, f32, f32, hkCollisionInput&);
};

class hkDefaultToiResourceMgr {
public:
    hkDefaultToiResourceMgr();
    virtual ~hkDefaultToiResourceMgr();
    virtual void
    beginToiAndSetupResources(const hkToiEvent&, const hkArray<hkToiEvent>&, hkToiResources&);
    virtual void
    endToiAndFreeResources(const hkToiEvent&, const hkArray<hkToiEvent>&, const hkToiResources&);
    virtual void shouldHandleGivenToi(const hkToiEvent&);
    virtual void resourcesDepleted();
    virtual void cannotSolve(hkArray<ConstraintViolationInfo>&);
};

class hkWorldCallbackUtil {
public:
    static void fireActionAdded(hkWorld*, hkAction*);
    static void fireActionRemoved(hkWorld*, hkAction*);
    static void fireEntityAdded(hkWorld*, hkEntity*);
    static void fireEntityRemoved(hkWorld*, hkEntity*);
    static void fireEntityShapeSet(hkWorld*, hkEntity*);
    static void firePhantomAdded(hkWorld*, hkPhantom*);
    static void firePhantomRemoved(hkWorld*, hkPhantom*);
    static void firePhantomShapeSet(hkWorld*, hkPhantom*);
    static void fireConstraintAdded(hkWorld*, hkConstraintInstance*);
    static void fireConstraintRemoved(hkWorld*, hkConstraintInstance*);
    static void fireContactPointAdded(hkWorld*, hkContactPointAddedEvent&);
    static void fireContactPointConfirmed(hkWorld*, hkContactPointConfirmedEvent&);
    static void fireContactPointRemoved(hkWorld*, hkContactPointRemovedEvent&);
    static void fireContactProcess(hkWorld*, hkContactProcessEvent&);
    static void fireWorldDeleted(hkWorld*);
    static void fireIslandActivated(hkWorld*, hkSimulationIsland*);
    static void fireIslandDeactivated(hkWorld*, hkSimulationIsland*);
    static void firePostSimulationCallback(hkWorld*);
    static void firePostIntegrateCallback(hkWorld*, const hkStepInfo&);
    static void firePostCollideCallback(hkWorld*, const hkStepInfo&);
    static void fireIslandPostIntegrateCallback(hkWorld*, hkSimulationIsland*, const hkStepInfo&);
    static void fireIslandPostCollideCallback(hkWorld*, hkSimulationIsland*, const hkStepInfo&);
    static void fireContactImpulseLimitBreached(hkWorld*,
                                                const hkContactImpulseLimitBreachedListenerInfo*,
                                                s32);
    static void fireInactiveEntityMoved(hkWorld*, hkEntity*);
};

class hkTriangleShape {
public:
    virtual ~hkTriangleShape();
};

class hkBvTreeAgent {
public:
    hkBvTreeAgent(hkContactMgr*);
    virtual ~hkBvTreeAgent();
    virtual void cleanup(hkConstraintOwner&);
    virtual void invalidateTim(hkCollisionInput&);
    virtual void warpTime(f32, f32, hkCollisionInput&);
    virtual void updateShapeCollectionFilter(const hkCdBody&,
                                             const hkCdBody&,
                                             const hkCollisionInput&,
                                             hkConstraintOwner&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
};

class hkMultiSphereAgent {
public:
    hkMultiSphereAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkMultiSphereAgent();
    static void registerAgent(hkCollisionDispatcher*);
    static void
    createListAAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    static void
    createListBAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
};

class hkConvexListAgent {
public:
    hkConvexListAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkConvexListAgent();
    static void registerAgent(hkCollisionDispatcher*);
    static void createConvexConvexAgent(const hkCdBody&,
                                        const hkCdBody&,
                                        const hkCollisionInput&,
                                        hkContactMgr*);
    static void
    createConvexListAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    static void
    createListConvexAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    static void
    createListListAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void updateShapeCollectionFilter(const hkCdBody&,
                                             const hkCdBody&,
                                             const hkCollisionInput&,
                                             hkConstraintOwner&);
    virtual void invalidateTim(hkCollisionInput&);
    virtual void warpTime(f32, f32, hkCollisionInput&);
    virtual void removePoint(u16);
    virtual void commitPotential(u16);
    virtual void createZombie(u16);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    void switchToStreamMode(hkConstraintOwner&);
    void switchToGskMode(hkConstraintOwner&);
};

class hkBvTreeAgent3 {
public:
    static void initAgentFunc(hkCollisionDispatcher::Agent3Funcs&);
    static void registerAgent3(hkCollisionDispatcher*);
    static void create(const hkAgent3Input&, hkAgentEntry*, void*);
    static void
    destroy(hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&, hkCollisionDispatcher*);
    static void process(
        const hkAgent3ProcessInput&, hkAgentEntry*, void*, hkVector4*, hkProcessCollisionOutput&);
    static void updateFilter(hkAgentEntry*,
                             void*,
                             const hkCdBody&,
                             const hkCdBody&,
                             const hkCollisionInput&,
                             hkContactMgr*,
                             hkConstraintOwner&);
    static void invalidateTim(hkAgentEntry*, void*, hkCollisionInput&);
    static void warpTime(hkAgentEntry*, void*, f32, f32, hkCollisionInput&);
};

class hkBvTreeStreamAgent {
public:
    hkBvTreeStreamAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkBvTreeStreamAgent();
    static void registerAgent(hkCollisionDispatcher*);
    static void createBvTreeShapeAgent(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkContactMgr*);
    static void
    createShapeBvAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void updateShapeCollectionFilter(const hkCdBody&,
                                             const hkCdBody&,
                                             const hkCollisionInput&,
                                             hkConstraintOwner&);
    virtual void invalidateTim(hkCollisionInput&);
    virtual void warpTime(f32, f32, hkCollisionInput&);
};

class hkShapeCollectionAgent {
public:
    hkShapeCollectionAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkShapeCollectionAgent();
    virtual void cleanup(hkConstraintOwner&);
    virtual void invalidateTim(hkCollisionInput&);
    virtual void warpTime(f32, f32, hkCollisionInput&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
    virtual void updateShapeCollectionFilter(const hkCdBody&,
                                             const hkCdBody&,
                                             const hkCollisionInput&,
                                             hkConstraintOwner&);
};

class hkSimpleConstraintContactMgr {
public:
    hkSimpleConstraintContactMgr(hkWorld*, hkRigidBody*, hkRigidBody*);
    virtual ~hkSimpleConstraintContactMgr();
    hkConstraintInstance* getConstraintInstance();
    virtual void reserveContactPointsImpl(s32);
    virtual void addToiImpl(const hkCdBody&,
                            const hkCdBody&,
                            const hkProcessCollisionInput&,
                            hkProcessCollisionOutput&,
                            f32,
                            hkContactPoint&,
                            const hkGskCache*,
                            f32&,
                            hkContactPointMaterial&);
    virtual void removeToiImpl(const hkCollidable&,
                               const hkCollidable&,
                               hkConstraintOwner&,
                               hkContactPointMaterial&);
    virtual void processToi(hkToiEvent&, f32, hkArray<hkEntity*>&);
    virtual void addContactPointImpl(const hkCdBody&,
                                     const hkCdBody&,
                                     const hkProcessCollisionInput&,
                                     hkProcessCollisionOutput&,
                                     const hkGskCache*,
                                     hkContactPoint&);
    virtual void removeContactPointImpl(u16, hkConstraintOwner&);
    virtual hkContactPoint* getContactPoint(u16);
    virtual hkContactPointMaterial* getContactPointProperties(u16);
    virtual void toiCollisionResponseBeginCallback(const hkContactPoint&,
                                                   hkSimpleConstraintInfoInitInput&,
                                                   hkBodyVelocity&,
                                                   hkSimpleConstraintInfoInitInput&,
                                                   hkBodyVelocity&);
    virtual void toiCollisionResponseEndCallback(const hkContactPoint&,
                                                 f32,
                                                 hkSimpleConstraintInfoInitInput&,
                                                 hkBodyVelocity&,
                                                 hkSimpleConstraintInfoInitInput&,
                                                 hkBodyVelocity&);
    virtual void processContactImpl(const hkCollidable&,
                                    const hkCollidable&,
                                    const hkProcessCollisionInput&,
                                    hkProcessCollisionData&);
    virtual void cleanup(hkConstraintOwner&);
};

class hkBvAgent {
public:
    hkBvAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkBvAgent();
    static void registerAgent(hkCollisionDispatcher*);
    static void
    createBvShapeAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    static void
    createShapeBvAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void invalidateTim(hkCollisionInput&);
    virtual void warpTime(f32, f32, hkCollisionInput&);
    virtual void removePoint(u16);
    virtual void commitPotential(u16);
    virtual void createZombie(u16);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
    virtual void updateShapeCollectionFilter(const hkCdBody&,
                                             const hkCdBody&,
                                             const hkCollisionInput&,
                                             hkConstraintOwner&);
};

class hkConvexListAgent3 {
public:
    static void initAgentFunc(hkCollisionDispatcher::Agent3Funcs&);
    static void registerAgent3(hkCollisionDispatcher*);
    static void create(const hkAgent3Input&, hkAgentEntry*, void*);
    static void
    destroy(hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&, hkCollisionDispatcher*);
    static void process(
        const hkAgent3ProcessInput&, hkAgentEntry*, void*, hkVector4*, hkProcessCollisionOutput&);
    static void updateFilter(hkAgentEntry*,
                             void*,
                             const hkCdBody&,
                             const hkCdBody&,
                             const hkCollisionInput&,
                             hkContactMgr*,
                             hkConstraintOwner&);
    static void invalidateTim(hkAgentEntry*, void*, hkCollisionInput&);
    static void warpTime(hkAgentEntry*, void*, f32, f32, hkCollisionInput&);
    static void switchToStreamMode(
        hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&, hkCollisionDispatcher*);
    static void switchToGskMode(
        hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&, hkCollisionDispatcher*);
    static void getPredGskData(hkAgentEntry*, void*);
    static void getConvexListaData(hkAgentEntry*, void*);
};

class hkConvexListShape {
public:
    hkConvexListShape(const hkConvexShape* const*, s32);
    virtual ~hkConvexListShape();
    void setShapesAndRadius(const hkConvexShape* const*, s32);
    void setUseCachedAabb(hkBool);
};

class hkTransformAgent {
public:
    hkTransformAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkTransformAgent();
    static void registerAgent(hkCollisionDispatcher*);
    static void
    createTransformAAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    static void
    createTransformBAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
    virtual void updateShapeCollectionFilter(const hkCdBody&,
                                             const hkCdBody&,
                                             const hkCollisionInput&,
                                             hkConstraintOwner&);
    virtual void invalidateTim(hkCollisionInput&);
    virtual void warpTime(f32, f32, hkCollisionInput&);
    virtual void removePoint(u16);
    virtual void commitPotential(u16);
    virtual void createZombie(u16);
};

class hkSphereCapsuleAgent {
public:
    virtual ~hkSphereCapsuleAgent();
    static void registerAgent(hkCollisionDispatcher*);
    static void createCapsuleSphereAgent(const hkCdBody&,
                                         const hkCdBody&,
                                         const hkCollisionInput&,
                                         hkContactMgr*);
    static void createSphereCapsuleAgent(const hkCdBody&,
                                         const hkCdBody&,
                                         const hkCollisionInput&,
                                         hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
};

class hkSphereTriangleAgent {
public:
    virtual ~hkSphereTriangleAgent();
    static void initAgentFunc(hkCollisionDispatcher::AgentFuncs&);
    static void initAgentFuncInverse(hkCollisionDispatcher::AgentFuncs&);
    static void registerAgent2(hkCollisionDispatcher*);
    static void createTriangleSphereAgent(const hkCdBody&,
                                          const hkCdBody&,
                                          const hkCollisionInput&,
                                          hkContactMgr*);
    static void createSphereTriangleAgent(const hkCdBody&,
                                          const hkCdBody&,
                                          const hkCollisionInput&,
                                          hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
};

class hkPredGskAgent3 {
public:
    static void initAgentFunc(hkCollisionDispatcher::Agent3Funcs&);
    static void registerAgent3(hkCollisionDispatcher*, hkShapeType, hkShapeType);
    static void create(const hkAgent3Input&, hkAgentEntry*, void*);
    static void sepNormal(hkAgentEntry*, void*, hkVector4&);
    static void removePoint(hkAgentEntry*, void*, u16);
    static void commitPotential(hkAgentEntry*, void*, u16);
    static void createZombie(hkAgentEntry*, void*, u16);
    static void cleanup(hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&);
    static void
    destroy(hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&, hkCollisionDispatcher*);
    static void process(
        const hkAgent3ProcessInput&, hkAgentEntry*, void*, hkVector4*, hkProcessCollisionOutput&);
};

class hkBoxBoxAgent {
public:
    virtual ~hkBoxBoxAgent();
    static void initAgentFunc(hkCollisionDispatcher::AgentFuncs&);
    static void registerAgent(hkCollisionDispatcher*);
    static void
    createBoxBoxAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
};

class hkSphereSphereAgent {
public:
    virtual ~hkSphereSphereAgent();
    static void initAgentFunc(hkCollisionDispatcher::AgentFuncs&);
    static void registerAgent(hkCollisionDispatcher*);
    static void createSphereSphereAgent(const hkCdBody&,
                                        const hkCdBody&,
                                        const hkCollisionInput&,
                                        hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
};

class hkSphereBoxAgent {
public:
    virtual ~hkSphereBoxAgent();
    static void registerAgent(hkCollisionDispatcher*);
    static void
    createBoxSphereAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    static void
    createSphereBoxAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
};

class hkListAgent {
public:
    hkListAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkListAgent();
    static void initAgentFunc(hkCollisionDispatcher::AgentFuncs&);
    static void initAgentFuncInverse(hkCollisionDispatcher::AgentFuncs&);
    static void registerAgent(hkCollisionDispatcher*);
    static void
    createListAAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    static void
    createListBAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void invalidateTim(hkCollisionInput&);
    virtual void warpTime(f32, f32, hkCollisionInput&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
    virtual void updateShapeCollectionFilter(const hkCdBody&,
                                             const hkCdBody&,
                                             const hkCollisionInput&,
                                             hkConstraintOwner&);
};

class hkReportContactMgr {
public:
    hkReportContactMgr(hkWorld*, hkRigidBody*, hkRigidBody*);
    virtual ~hkReportContactMgr();
    virtual void addContactPointImpl(const hkCdBody&,
                                     const hkCdBody&,
                                     const hkProcessCollisionInput&,
                                     hkProcessCollisionOutput&,
                                     const hkGskCache*,
                                     hkContactPoint&);
    virtual void addToiImpl(const hkCdBody&,
                            const hkCdBody&,
                            const hkProcessCollisionInput&,
                            hkProcessCollisionOutput&,
                            f32,
                            hkContactPoint&,
                            const hkGskCache*,
                            f32&,
                            hkContactPointMaterial&);
    virtual void removeToiImpl(const hkCollidable&,
                               const hkCollidable&,
                               hkConstraintOwner&,
                               hkContactPointMaterial&);
    virtual void removeContactPointImpl(u16, hkConstraintOwner&);
    virtual void processContactImpl(const hkCollidable&,
                                    const hkCollidable&,
                                    const hkProcessCollisionInput&,
                                    hkProcessCollisionData&);
    virtual void processToi(hkToiEvent&, f32, hkArray<hkEntity*>&);
    virtual void reserveContactPointsImpl(s32);
    virtual void cleanup(hkConstraintOwner&);
};

class hkBoxBoxAgent3 {
public:
    static void initAgentFunc(hkCollisionDispatcher::Agent3Funcs&);
    static void registerAgent3(hkCollisionDispatcher*);
    static void create(const hkAgent3Input&, hkAgentEntry*, void*);
    static void cleanup(hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&);
    static void removePoint(hkAgentEntry*, void*, u16);
    static void commitPotential(hkAgentEntry*, void*, u16);
    static void createZombie(hkAgentEntry*, void*, u16);
    static void
    destroy(hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&, hkCollisionDispatcher*);
    static void process(
        const hkAgent3ProcessInput&, hkAgentEntry*, void*, hkVector4*, hkProcessCollisionOutput&);
};

class hkListAgent3 {
public:
    static void initAgentFunc(hkCollisionDispatcher::Agent3Funcs&);
    static void registerAgent3(hkCollisionDispatcher*);
    static void create(const hkAgent3Input&, hkAgentEntry*, void*);
    static void
    destroy(hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&, hkCollisionDispatcher*);
    static void process(
        const hkAgent3ProcessInput&, hkAgentEntry*, void*, hkVector4*, hkProcessCollisionOutput&);
    static void updateFilter(hkAgentEntry*,
                             void*,
                             const hkCdBody&,
                             const hkCdBody&,
                             const hkCollisionInput&,
                             hkContactMgr*,
                             hkConstraintOwner&);
    static void invalidateTim(hkAgentEntry*, void*, hkCollisionInput&);
    static void warpTime(hkAgentEntry*, void*, f32, f32, hkCollisionInput&);
};

class hkPhantomAgent {
public:
    hkPhantomAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkPhantomAgent();
    static void registerAgent(hkCollisionDispatcher*);
    static void
    createPhantomAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    virtual void cleanup(hkConstraintOwner&);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
};

class hkMoppAgent {
public:
    hkMoppAgent(hkContactMgr*);
    virtual ~hkMoppAgent();
    static void
    createBvBvAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
};

class hkAgent3Bridge {
public:
    static void registerAgent3(hkCollisionDispatcher*);
    static void create(const hkAgent3Input&, hkAgentEntry*, void*);
    static void process(
        const hkAgent3ProcessInput&, hkAgentEntry*, void*, hkVector4*, hkProcessCollisionOutput&);
    static void
    destroy(hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&, hkCollisionDispatcher*);
    static void updateFilter(hkAgentEntry*,
                             void*,
                             const hkCdBody&,
                             const hkCdBody&,
                             const hkCollisionInput&,
                             hkContactMgr*,
                             hkConstraintOwner&);
    static void invalidateTim(hkAgentEntry*, void*, hkCollisionInput&);
    static void warpTime(hkAgentEntry*, void*, f32, f32, hkCollisionInput&);
    static void removePoint(hkAgentEntry*, void*, u16);
    static void commitPotential(hkAgentEntry*, void*, u16);
    static void createZombie(hkAgentEntry*, void*, u16);
};

class hkNullAgent {
public:
    hkNullAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkNullAgent();
    static hkCollisionAgent*
    createNullAgent(const hkCdBody&, const hkCdBody&, const hkCollisionInput&, hkContactMgr*);
    static hkNullAgent* getNullAgent();
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
    static void staticLinearCast(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkLinearCastCollisionInput&,
                                 hkCdPointCollector&,
                                 hkCdPointCollector*);
    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);
    virtual void linearCast(const hkCdBody&,
                            const hkCdBody&,
                            const hkLinearCastCollisionInput&,
                            hkCdPointCollector&,
                            hkCdPointCollector*);
    virtual void cleanup(hkConstraintOwner&);
};

class hkNullAgent3 {
public:
    static void create(const hkAgent3Input&, hkAgentEntry*, void*);
    static void
    destroy(hkAgentEntry*, void*, hkContactMgr*, hkConstraintOwner&, hkCollisionDispatcher*);
    static void process(
        const hkAgent3ProcessInput&, hkAgentEntry*, void*, hkVector4*, hkProcessCollisionOutput&);
};

class hkGsk {
public:
    enum SupportTypes { SUPPORT_TYPES_PLACEHOLDER = 0 };
    struct GetClosesetPointInput {};

    void checkTriangleBoundaries(const hkVector4&, hkVector4*, SupportTypes);
    void processEdgeTriangle(hkVector4*, hkVector4*, hkPadSpu&, hkPadSpu&, hkBool, SupportTypes);
    void
    getClosestFeature(const hkConvexShape*, const hkConvexShape*, const hkTransform&, hkVector4&);
    void exitAndExportCacheImpl(hkGskCache&) const;
    void convertFeatureToClosestDistance(const hkVector4&, hkGskOut&);
    void getClosestPoint(const GetClosesetPointInput&, hkGskCache&, hkVector4&, hkVector4&);
    void handlePenetration(const hkConvexShape*, const hkConvexShape*, const hkTransform&);
    void reduceDimensionExtended();
};

class hkConvexPenetrationUtil {
public:
    void findBestProjection(const hkVector4&, const hkVector4&, hkWingedEdge::Vertex&, f32&);
    void case0To1(hkGskOut&);
    void case1To2();
    void case2To3();
    void case3To4(const hkVector4&);
    void getPointForSimplex(const hkVector4&, hkWingedEdge::Vertex&);
    void addPointToSimplex(const hkWingedEdge::Vertex&);
    void tryToExpandPolytope(hkWingedEdge&,
                             hkWingedEdge::Triangle*,
                             hkWingedEdge::Vertex*,
                             hkGskStatus&);
    void convertResultToFeature(hkWingedEdge&, hkWingedEdge::Triangle*, hkGskOut&);
    void builtTetrahedron(hkGskOut&, hkGskStatus&);
    void calculatePenetrationDepth(hkGskOut&);
    void randomVector(s32, f32, f32, hkVector4&);
};

class hkMoppDefaultSplitter {
public:
    class hkMoppPrimitiveArray {};
    class hkMoppDsSide {};

    hkMoppDefaultSplitter();
    virtual ~hkMoppDefaultSplitter();

    void findSplittingPlanePositions(hkMoppBasicNode*,
                                     const hkMoppSplittingPlaneDirection*,
                                     const hkMoppPrimitiveArray&,
                                     const hkMoppExtent&,
                                     s32);
    void groupPrimitives(const hkMoppPrimitiveArray&,
                         hkMoppBasicNode*,
                         s32,
                         hkMoppPrimitiveArray&,
                         hkMoppPrimitiveArray&);
    void createTerminal(hkMoppTreeInternalNode*, const hkMoppPrimitiveArray&);
    void createNode();
    void resortAxis(const hkMoppTreeInternalNode*, s32*, f32*);
    void split(hkMoppTreeInternalNode*, const hkMoppPrimitiveArray&, hkMoppDsSide, s32);
    void releaseNode(hkMoppTreeNode*);
    void getFreeNodes();
    void buildTree(hkMoppMediator*,
                   hkMoppCostFunction*,
                   hkMoppAssembler*,
                   const hkMoppSplitParams&,
                   hkMoppScratchArea&);
};

class hkTriangleCompressor {
public:
    s32 getCompressedSize(const hkTriangleShape*, s32, const u8*);
    void compress(const hkTriangleShape*, s32, const u8*, void*);
};

class hkMoppCompiler {
public:
    hkMoppCompiler(hkMoppMeshType);
    ~hkMoppCompiler();

    void setSplitParams(const hkMoppSplitParams&);
    void setCostParams(const hkMoppSplitCostParams&);
    void setAssemblerParams(const hkMoppAssembler::hkMoppAssemblerParams&);
    s32 calculateRequiredBufferSize(hkMoppMediator*);
    void compile(hkMoppMediator*, c8*, s32);
};

class hkGeomHull {
public:
    hkGeomHull();
    void initializeWithVertex(s32);
    void initializeWithEdge(s32, s32);
    void initializeWithTriangle(s32, s32, s32);
};

class hkGeomConvexHullBuilder {
public:
    static void generateConvexHull(
        const hkVector4*, s32, hkGeomHull&, hkArray<hkVector4>&, hkGeomConvexHullMode);
    static f32 getPseudoAngle(f32, f32);
    static void generateHullFromPlanarPoints(
        const hkVector4&, const hkVector4*, s32, hkArray<hkVector4>&, hkArray<hkVector4>&);
    static void getAabb(const hkArray<hkVector4>&, hkAabb&);
    static void weldXsortedVertices(f32, hkArray<hkVector4>&, s32&);
    static void buildGeometry(hkGeomHull&, hkGeometry&);
    static void buildPlaneEquations(const hkGeomConvexHullTolerances&,
                                    hkGeomHull&,
                                    const hkArray<hkVector4>&,
                                    hkArray<hkVector4>&);
    static void removeCollinearVertices(hkArray<hkVector4>&, f32);
    static void
    postFilterVertices(hkGeomHull&, s32, s32, const hkGeomConvexHullTolerances&, hkBool&);
    static void buildPlaneEquations(const hkGeomConvexHullTolerances&,
                                    hkGeomHull&,
                                    const hkArray<hkVector4>&,
                                    hkVector4&,
                                    hkBool&,
                                    hkArray<hkVector4>&,
                                    hkArray<PlaneAndPoints>&);
    static void createBevelPlane(const hkVector4&,
                                 const hkVector4&,
                                 const hkVector4&,
                                 const hkVector4&,
                                 hkArray<hkVector4>&);
    static void convertToUnitCube(hkArray<hkVector4>&, hkVector4&, hkVector4&);
    static void convertFromUnitCube(hkArray<hkVector4>&, hkVector4&, hkVector4&);
    static void buildConvexHull(
        const hkGeomConvexHullTolerances&, const hkVector4*, s32, hkGeomHull&, hkArray<hkVector4>&);
    static void buildConvexSubHull(
        const hkGeomConvexHullTolerances&, hkArray<hkVector4>&, s32, s32, hkGeomHull&);
    static void
    mergeHulls(const hkGeomConvexHullTolerances&, hkGeomHull&, hkGeomHull&, hkGeomHull&);
    static void isSingleLine(f32, hkGeomHull&, hkGeomHull&, hkGeomHull&);
    static void removeFlaggedVertices(hkArray<hkVector4>&);
    static void removeUnusedVertices(hkGeomHull&, hkArray<hkVector4>&);
    static void appendAndReindexEdges(hkGeomHull&, hkBool, hkGeomHull&, hkArray<u16>&);
    static void stitchHulls(hkGeomHull&, hkGeomHull&, hkArray<WrappingLine>&, hkGeomHull&);
    static void getPlaneEquationZaxis(const hkVector4&, const hkVector4&, hkVector4&);
    static void getCommonTangent(hkGeomHull&, hkGeomHull&, WeightedLine&, hkVector4&);
    static void findWeightedNeighbours(const hkGeomConvexHullTolerances&,
                                       hkGeomHull&,
                                       const hkVector4&,
                                       u16,
                                       const hkGeomEdge*,
                                       const hkVector4*,
                                       const hkVector4*,
                                       hkArray<WeightedNeighbour>&);
    static void removeCoPlanarNeighbours(const hkGeomConvexHullTolerances&,
                                         hkGeomHull&,
                                         const hkVector4&,
                                         const hkGeomEdge*,
                                         const hkVector4*,
                                         const hkVector4*,
                                         hkArray<WeightedNeighbour>&);
    static void calculateNewNeighbours(const hkVector4*,
                                       const hkGeomConvexHullTolerances&,
                                       f32,
                                       const hkVector4&,
                                       const hkGeomEdge*,
                                       const hkVector4*,
                                       const hkVector4*,
                                       hkArray<WeightedNeighbour>&);
    static void validateNeighbours(const hkGeomConvexHullTolerances&,
                                   const hkVector4*,
                                   const hkVector4&,
                                   u16,
                                   WeightedLine*,
                                   const hkVector4*,
                                   const hkVector4*,
                                   hkArray<WeightedNeighbour>&,
                                   hkArray<WeightedNeighbour>&);
    static void addWrappingLines(const hkGeomConvexHullConfig&,
                                 WeightedLine*,
                                 hkArray<WeightedNeighbour>&,
                                 hkArray<WeightedNeighbour>&,
                                 hkArray<WeightedLine>&);
    static void
    findWrapping(hkGeomHull&, hkGeomHull&, const hkArray<WeightedLine>&, hkArray<WrappingLine>&);
    static void isValidEdgeCheck(hkGeomHull&, hkGeomEdge*, s32);
    static void isValidWrapping(hkGeomHull&, hkGeomEdge*, hkBool, hkArray<WrappingLine>&);
    static void getAngleBetweenVertexAndPlane(const hkGeomConvexHullTolerances&,
                                              const hkVector4&,
                                              const hkVector4&,
                                              const hkVector4&,
                                              const hkVector4&);
    static void vectorLessAndMergeCoordinates(hkVector4&, hkVector4&);
};

class hkBoxBoxManifold {
public:
    hkBoxBoxManifold();
    void addPoint(const hkCdBody&, const hkCdBody&, hkFeatureContactPoint&);
    void removePoint(s32);
};

class hkBoxBoxCollisionDetection {
public:
    class hkFeaturePointCache {};

    void checkCompleteness(hkBoxBoxManifold&, s32, s32) const;
    void checkIntersection(const hkVector4&) const;
    void findClosestPoint(hkBoxBoxManifold&, hkFeatureContactPoint&, hkFeaturePointCache&) const;
    void isValidEdgeEdge(hkFeaturePointCache&) const;
    void calculateClosestPoint(hkContactPoint&) const;
    void calcManifold(hkBoxBoxManifold&) const;
};

class hkGskBaseAgent {
public:
    hkGskBaseAgent(const hkCdBody&, const hkCdBody&, hkContactMgr*);
    virtual ~hkGskBaseAgent();

    virtual void processCollision(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkProcessCollisionInput&,
                                  hkProcessCollisionOutput&);
    virtual void invalidateTim(hkCollisionInput&);
    virtual void cleanup(hkConstraintOwner&);
    virtual void warpTime(f32, f32, hkCollisionInput&);
    virtual void getPenetrations(const hkCdBody&,
                                 const hkCdBody&,
                                 const hkCollisionInput&,
                                 hkCdBodyPairCollector&);
    virtual void getClosestPoints(const hkCdBody&,
                                  const hkCdBody&,
                                  const hkCollisionInput&,
                                  hkCdPointCollector&);

    void calcSeparatingNormal(const hkCdBody&, const hkCdBody&, f32, hkGsk&, hkVector4&);
    static void staticGetClosestPoints(const hkCdBody&,
                                       const hkCdBody&,
                                       const hkCollisionInput&,
                                       hkCdPointCollector&);
    static void staticGetPenetrations(const hkCdBody&,
                                      const hkCdBody&,
                                      const hkCollisionInput&,
                                      hkCdBodyPairCollector&);
};

class hkGeomConvexHullTester {
public:
    static hkBool isValidHull(
        const hkGeomConvexHullTolerances&, const hkVector4*, s32, hkGeomHull&, hkArray<hkVector4>&);
    static void
    checkPlaneEquations(hkArray<hkVector4>&, hkArray<hkVector4>&, hkArray<hkVector4>&, f32);
    static void
    findSameEdges(const PlaneAndPoints&, const PlaneAndPoints&, hkBool&, hkBool&, hkBool&);
    static hkBool isValidPlanarHull(hkArray<hkVector4>&,
                                    hkGeomHull&,
                                    hkArray<hkVector4>&,
                                    hkArray<hkVector4>&,
                                    hkArray<PlaneAndPoints>&,
                                    f32);
    static hkBool isValidNonPlanarHull(hkArray<hkVector4>&,
                                       hkGeomHull&,
                                       hkArray<hkVector4>&,
                                       hkArray<hkVector4>&,
                                       hkArray<PlaneAndPoints>&,
                                       f32);
};

#endif // HAVOKHEAP_HPP
