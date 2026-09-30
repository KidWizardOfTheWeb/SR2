#ifndef PLAYERMOTION_HPP
#define PLAYERMOTION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/hkBaseObject.hpp"
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
class hkBroadPhaseHandle;
class hkBroadPhaseHandlePair;
struct hkAabb;
class clsPlayerTask;

// total size: 0x4
class hkEntityListener {
public:
    virtual ~hkEntityListener() {}
};

// total size: 0x1
class hkCriticalSection {};

// total size: 0x8
class hkMultiThreadCheck {
public:
    hkMultiThreadCheck() : m_threadId(-47), m_markCount(0) {}

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
    virtual s32 getType() const = 0;
    virtual void addObject(hkBroadPhaseHandle* pParam1,
                           const hkAabb& rParam2,
                           hkArray<hkBroadPhaseHandlePair>& rParam3) = 0;
    virtual void addObjectBatch(hkArray<hkBroadPhaseHandle*>& rParam1,
                                hkArray<hkAabb>& rParam2,
                                hkArray<hkBroadPhaseHandlePair>& rParam3) = 0;
    virtual void removeObject(hkBroadPhaseHandle* pParam1,
                              hkArray<hkBroadPhaseHandlePair>& rParam2) = 0;
    virtual void removeObjectBatch(hkArray<hkBroadPhaseHandle*>& rParam1,
                                   hkArray<hkBroadPhaseHandlePair>& rParam2) = 0;
    virtual s32 getNumObjects() = 0;
    virtual void updateAabbs(hkBroadPhaseHandle** pParam1,
                             const hkAabb* pParam2,
                             s32 s32Param3,
                             hkArray<hkBroadPhaseHandlePair>& rParam4,
                             hkArray<hkBroadPhaseHandlePair>& rParam5) = 0;

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
    void setZero()
    {
        m_col0.setZero4();
        m_col1.setZero4();
        m_col2.setZero4();
    }
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

inline void hkVector4::setMul3(const hkMatrix3& rParam1, const hkVector4& rParam2)
{
    const f32 x0 = rParam2.x;
    const f32 y0 = rParam2.y;
    const f32 z0 = rParam2.z;
    x = x0 * rParam1.m_col0.x + y0 * rParam1.m_col1.x + z0 * rParam1.m_col2.x;
    y = x0 * rParam1.m_col0.y + y0 * rParam1.m_col1.y + z0 * rParam1.m_col2.y;
    z = x0 * rParam1.m_col0.z + y0 * rParam1.m_col1.z + z0 * rParam1.m_col2.z;
    w = 0.0f;
}

extern f32 hkTransformIdentity[];

// total size: 0x40
class hkTransform {
public:
    hkTransform() {}

    // RECONSTRUCTED: accessor name.
    static const hkTransform& getIdentity()
    {
        return *reinterpret_cast<const hkTransform*>(hkTransformIdentity);
    }

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
    void init(const hkConvexShape* pParam1,
              const hkConvexShape* pParam2,
              const hkTransform& rParam3);

    u16 m_vertices[4]; // offset 0x0, size 0x8
    u8 m_dimA;         // offset 0x8, size 0x1
    u8 m_dimB;         // offset 0x9, size 0x1
    u8 m_maxDimA;      // offset 0xA, size 0x1
    u8 m_maxDimB;      // offset 0xB, size 0x1
};

// total size: 0x10
class hkQuaternion {
public:
    hkQuaternion() {}
    hkQuaternion(f32 f32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4)
    {
        set(f32Param1, f32Param2, f32Param3, f32Param4);
    }

    const hkVector4& getImag() const { return m_vec; }
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
    NNS_MOTION* getMotionTablePtr() const
    {
        return m_apsMotionTable[m_s8MotionType]->aspTable[m_s8MotionNo];
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
