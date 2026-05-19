#ifndef PLAYERMOTION_HPP
#define PLAYERMOTION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/hkArray.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GameData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Motion.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"

class hkAllCdPointCollector;
class hkCharacterProxyCinfo;
class hkEntity;
class hkLinearCastInput;
class hkPhantom;
class hkPhantomListener;
class hkRotation;
class hkQuaternion;
class hkConvexShape;
class hkRootCdPoint;
class hkShapePhantom;
class hkCharacterProxyListener;
class hkRigidBody;
class hkSimplexSolverInput;
class hkSimplexSolverOutput;
class hkSurfaceConstraintInfo;
class hkTriangleShape;
class hkCriticalSection;
class clsPlayerTask;

// total size: 0x4
class hkEntityListener {
public:
    virtual ~hkEntityListener() {}
};

// total size: 0x4
class hkPhantomListener {
public:
    virtual ~hkPhantomListener() {}
};

// total size: 0x1
class hkCriticalSection {};

// total size: 0x8
class hkMultiThreadCheck {
public:
    void disableChecks();

    u32 m_threadId;     // offset 0x0, size 0x4
    s16 m_markCount;    // offset 0x4, size 0x2
    u16 m_markBitStack; // offset 0x6, size 0x2
};

// total size: 0x14
class hkBroadPhase : public hkReferencedObject {
public:
    class hkBpAabb {};
    class hkCastAabbInput {};
    class hkCastRayInput {};

    hkBroadPhase();
    virtual ~hkBroadPhase();

    void lockImplementation();
    void unlockImplementation();

    static void* m_defaultCreationFunction;

    hkMultiThreadCheck m_multiThreadCheck; // offset 0x8, size 0x8
    hkCriticalSection* m_criticalSection;  // offset 0x10, size 0x4
};

// total size: 0x30
class hkMatrix3 {
public:
    hkMatrix3() {}

    const hkVector4& getColumn(s32 s32Param1) const { return (&m_col0)[s32Param1]; }
    void getRow(s32 s32Param1, hkVector4& rParam2) const {}
    void setIdentity() {}
    void setZero() {}
    void transpose();
    void setTranspose(const hkMatrix3& rParam1);
    void setMul(const hkMatrix3& rParam1, const hkMatrix3& rParam2);
    void setMulInverse(const hkMatrix3& rParam1, const hkRotation& rParam2);
    void invertSymmetric();
    void add(const hkMatrix3& rParam1);
    void mul(const hkMatrix3& rParam1);
    void mul(f32 f32Param1);
    void changeBasis(const hkRotation& rParam1);

    hkVector4 m_col0; // offset 0x0, size 0x10
    hkVector4 m_col1; // offset 0x10, size 0x10
    hkVector4 m_col2; // offset 0x20, size 0x10
};

// total size: 0x30
class hkRotation : public hkMatrix3 {
public:
    void set(const hkQuaternion& rParam1);
    s32 isOrthonormal(f32 f32Param1) const;
};

// total size: 0x40
class hkTransform {
public:
    hkTransform() {}

    const hkVector4& getColumn(s32 s32Param1) const { return (&m_rotation.m_col0)[s32Param1]; }
    const hkRotation& getRotation() const { return m_rotation; }
    void setTranslation(const hkVector4& rParam1) { m_translation = rParam1; }
    void setInverse(const hkTransform& rParam1);
    void setMul(const hkTransform& rParam1, const hkTransform& rParam2);
    void setMulInverseMul(const hkTransform& rParam1, const hkTransform& rParam2);

    hkRotation m_rotation;   // offset 0x0, size 0x30
    hkVector4 m_translation; // offset 0x30, size 0x10
};

// total size: 0xC
class hkGskCache {
public:
    void initTriangle(const hkConvexShape* pParam1,
                      const hkTriangleShape* pParam2,
                      const hkTransform& rParam3);
    void
    init(const hkConvexShape* pParam1, const hkConvexShape* pParam2, const hkTransform& rParam3);

    u16 m_vertices[4]; // offset 0x0, size 0x8
    u8 m_dimA;         // offset 0x8, size 0x1
    u8 m_dimB;         // offset 0x9, size 0x1
    u8 m_maxDimA;      // offset 0xA, size 0x1
    u8 m_maxDimB;      // offset 0xB, size 0x1
};

// total size: 0xC0
class hkCharacterProxy : public hkReferencedObject,
                         public hkEntityListener,
                         public hkPhantomListener {
public:
    hkCharacterProxy(const hkCharacterProxyCinfo& rParam1);
    virtual ~hkCharacterProxy();

    void updateFromCinfo(const hkCharacterProxyCinfo& rParam1);
    void integrateWithCollectors(const hkStepInfo& rParam1,
                                 const hkVector4& rParam2,
                                 hkAllCdPointCollector& rParam3,
                                 hkAllCdPointCollector& rParam4);
    void moveToLinearCastHitPosition(const hkSimplexSolverOutput& rParam1,
                                     const hkAllCdPointCollector& rParam2,
                                     const hkLinearCastInput& rParam3,
                                     hkVector4& rParam4);
    void refreshManifold(hkAllCdPointCollector& rParam1);
    void extractSurfaceConstraintInfo(const hkRootCdPoint& rParam1,
                                      hkSurfaceConstraintInfo& rParam2,
                                      f32 f32Param3) const;
    void findSurface(const hkRootCdPoint& rParam1) const;
    void updateManifold(const hkAllCdPointCollector& rParam1, const hkAllCdPointCollector& rParam2);
    void applySurfaceInteractions(const hkStepInfo& rParam1, const hkVector4& rParam2);
    const hkVector4& getPosition() const;
    void setPosition(const hkVector4& rParam1);
    void setLinearVelocity(const hkVector4& rParam1);
    hkShapePhantom* getShapePhantom();
    void fireConstraintsProcessed(const hkArray<hkRootCdPoint>& rParam1,
                                  hkSimplexSolverInput& rParam2) const;
    void fireContactAdded(const hkRootCdPoint& rParam1) const;
    void fireContactRemoved(const hkRootCdPoint& rParam1) const;
    void entityRemovedCallback(hkEntity* pParam1);
    void phantomRemovedCallback(hkPhantom* pParam1);
    virtual void calcStatistics(hkStatisticsCollector* pParam1) const;

    hkVector4 m_velocity;                           // offset 0x10, size 0x10
    hkVector4 m_oldDisplacement;                    // offset 0x20, size 0x10
    hkShapePhantom* m_shapePhantom;                 // offset 0x30, size 0x4
    f32 m_dynamicFriction;                          // offset 0x34, size 0x4
    f32 m_staticFriction;                           // offset 0x38, size 0x4
    hkVector4 m_up;                                 // offset 0x40, size 0x10
    f32 m_extraUpStaticFriction;                    // offset 0x50, size 0x4
    f32 m_extraDownStaticFriction;                  // offset 0x54, size 0x4
    f32 m_keepDistance;                             // offset 0x58, size 0x4
    f32 m_keepContactTolerance;                     // offset 0x5C, size 0x4
    f32 m_contactAngleSensitivity;                  // offset 0x60, size 0x4
    s32 m_userPlanes;                               // offset 0x64, size 0x4
    f32 m_maxCharacterSpeedForSolver;               // offset 0x68, size 0x4
    f32 m_characterStrength;                        // offset 0x6C, size 0x4
    f32 m_characterMass;                            // offset 0x70, size 0x4
    hkArray<hkRootCdPoint> m_manifold;              // offset 0x74, size 0xC
    hkArray<hkCharacterProxyListener*> m_listeners; // offset 0x80, size 0xC
    hkArray<hkRigidBody*> m_bodies;                 // offset 0x8C, size 0xC
    hkArray<hkPhantom*> m_phantoms;                 // offset 0x98, size 0xC
    f32 m_maxSlopeCosine;                           // offset 0xA4, size 0x4
    f32 m_penetrationRecoverySpeed;                 // offset 0xA8, size 0x4
    s32 m_maxCastIterations;                        // offset 0xAC, size 0x4
    u8 m_refreshManifoldInCheckSupport;             // offset 0xB0, size 0x1
};

// total size: 0x10
class hkQuaternion {
public:
    hkQuaternion() {}
    hkQuaternion(f32 f32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4)
    {
        set(f32Param1, f32Param2, f32Param3, f32Param4);
    }

    hkVector4 getImag() const { return m_vec; }
    void set(f32 f32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4)
    {
        m_vec.x = f32Param1;
        m_vec.y = f32Param2;
        m_vec.z = f32Param3;
        m_vec.w = f32Param4;
    }
    void estimateAngleTo(const hkQuaternion& rParam1, hkVector4& rParam2) const {}
    void setAxisAngle(const hkVector4& rParam1, f32 f32Param2);
    void set(const hkRotation& rParam1);

    hkVector4 m_vec; // offset 0x0, size 0x10
};

// total size: 0x50
class hkSweptTransform {
public:
    void initSweptTransform(const hkVector4& rParam1, const hkQuaternion& rParam2);

    hkVector4 m_centerOfMass0;     // offset 0x0, size 0x10
    hkVector4 m_centerOfMass1;     // offset 0x10, size 0x10
    hkQuaternion m_rotation0;      // offset 0x20, size 0x10
    hkQuaternion m_rotation1;      // offset 0x30, size 0x10
    hkVector4 m_centerOfMassLocal; // offset 0x40, size 0x10
};

// total size: 0xC0
class hkMotionState {
public:
    void initMotionState(const hkVector4& rParam1, const hkQuaternion& rParam2);

    hkTransform m_transform;             // offset 0x0, size 0x40
    hkSweptTransform m_sweptTransform;   // offset 0x40, size 0x50
    hkVector4 m_deltaAngle;              // offset 0x90, size 0x10
    f32 m_objectRadius;                  // offset 0xA0, size 0x4
    f32 m_maxLinearVelocity;             // offset 0xA4, size 0x4
    f32 m_maxAngularVelocity;            // offset 0xA8, size 0x4
    f32 m_linearDamping;                 // offset 0xAC, size 0x4
    f32 m_angularDamping;                // offset 0xB0, size 0x4
    u16 m_deactivationClass;             // offset 0xB4, size 0x2
    u16 m_deactivationCounter;           // offset 0xB6, size 0x2
    u32 m_deactivationRefOrientation[2]; // offset 0xB8, size 0x8
};

// total size: 0x11C
class clsPlayerMotion : public clsMotion {
public:
    enum enmPriority {
        PRI_LV_00 = 0,
        PRI_LV_01 = 1,
        PRI_LV_02 = 2,
        PRI_LV_03 = 3,
        PRI_LV_04 = 4,
        PRI_LV_05 = 5,
        PRI_LV_06 = 6,
        PRI_HIGHT = 5,
        PRI_MID_HIGHT = 4,
        PRI_NORMAL = 3,
        PRI_MID_LOW = 2,
        PRI_LOW = 1,
    };

    clsPlayerMotion(clsPlayerTask* pcPlayer) : clsMotion(), m_pcPlayer(pcPlayer) {}
    virtual ~clsPlayerMotion() {}

    virtual void setStartDemoMotion();
    virtual void cancelStartDemoMotion();
    virtual void init(s8 s8CharaType, s8 s8ModelType, s8 s8MotionType);
    virtual void startPlayData();
    virtual void updatePlayData();
    virtual void registTable(s8 s8MotionType,
                             s8 s8MotionNo,
                             f32 f32StartFrame,
                             f32 f32LinkFrame,
                             clsMotion::enmStatus eStatus);
    virtual void registEnd(enmPriority eRegistPri, enmPriority ePlayPri);
    virtual void reset() {}

    void registTableBase(s8 s8MotionNo,
                         f32 f32StartFrame,
                         f32 f32LinkFrame,
                         clsMotion::enmStatus eStatus)
    {
    }
    void registBegin() {}
    s8 getOldBaseMotionType() const { return m_s8OldBaseMotionType; }
    void setBaseMotionType(s8 s8MotionType) { m_s8BaseMotionType = s8MotionType; }
    nspGame::stcMotionTable** getMotionTablePtr() const
    {
        return const_cast<nspGame::stcMotionTable**>(m_apsMotionTable);
    }

    void checkNodeMotion();

    nspGame::stcMotionTable* m_apsMotionTable[8]; // offset 0x5C, size 0x20
    stcPlayData m_sPlayData[2];                   // offset 0x7C, size 0x90
    s8 m_s8PlayDataNo;                            // offset 0x10C, size 0x1
    s8 m_s8BaseMotionType;                        // offset 0x10D, size 0x1
    s8 m_s8OldBaseMotionType;                     // offset 0x10E, size 0x1
    s8 m_s8MotionNo;                              // offset 0x10F, size 0x1
    s8 m_s8LinkMotionNo;                          // offset 0x110, size 0x1
    s8 m_s8BlendMotionNo;                         // offset 0x111, size 0x1
    s8 m_s8MotionType;                            // offset 0x112, size 0x1
    s8 m_s8LinkMotionType;                        // offset 0x113, size 0x1
    s8 m_s8BlendMotionType;                       // offset 0x114, size 0x1
    u8 m_bRoboFlag;                               // offset 0x115, size 0x1
    clsPlayerTask* m_pcPlayer;                    // offset 0x118, size 0x4
};

#endif // PLAYERMOTION_HPP
