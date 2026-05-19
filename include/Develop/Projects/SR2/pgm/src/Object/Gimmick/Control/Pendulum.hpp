#ifndef PENDULUM_HPP
#define PENDULUM_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/SpeedDown.hpp"

class hkRigidBodyCinfo;
class hkHingeLimitsData;
class hkConstraintInstance;

// total size: 0x8
struct stcAngleLimitsData {
    hkHingeLimitsData* pcAngleLimitData;        // offset 0x0, size 0x4
    hkConstraintInstance* pcConstraintInstance; // offset 0x4, size 0x4
};

// total size: 0x60
class clsPendulum {
public:
    // total size: 0x18
    struct stcInfoParam {
        f32 f32Length;           // offset 0x0, size 0x4
        f32 f32MaxAngle;         // offset 0x4, size 0x4
        f32 f32AngularDamping;   // offset 0x8, size 0x4
        f32 f32Mass;             // offset 0xC, size 0x4
        f32 f32CenterMass;       // offset 0x10, size 0x4
        f32 f32MaxAngleVelocity; // offset 0x14, size 0x4
    };
    clsPendulum(u8 u8Param1, const NNS_VECTORFAST& rsPosVecFast, const NNS_QUATERNION& rsRotQuat);
    ~clsPendulum();

    NNS_VECTORFAST m_sOffsetPosVecFast;           // offset 0x0, size 0x10
    NNS_QUATERNION m_sRotQuat;                    // offset 0x10, size 0x10
    hkArray<void*> m_vctpcRigidBody;              // offset 0x20, size 0xC
    hkArray<void*> m_vctpcShape;                  // offset 0x2C, size 0xC
    hkConstraintChainInstance* m_pcChainInstance; // offset 0x38, size 0x4
    hkBallSocketChainData* m_pcChainData;         // offset 0x3C, size 0x4
    hkArray<void*> m_vctsAngleLimitsData;         // offset 0x40, size 0xC
    u8 m_u8LineNum;                               // offset 0x4C, size 0x1
    u8 m_u8RigidNum;                              // offset 0x4D, size 0x1
    f32 m_f32WorkLength;                          // offset 0x50, size 0x4
    hkArray<void*> m_vctRigidLength;              // offset 0x54, size 0xC

    static f32 m_tof32SphereRadius;

    inline void updatePosition(f32 f32Param1) {}
    inline void getPosition(u8 u8Param1, NNS_VECTORFAST& rParam2) {}
    inline void getRotQuat(u8 u8Param1, NNS_QUATERNION& rParam2) {}

    void createRigidBody(hkRigidBodyCinfo& rcInfo);
    void setInfo(const stcInfoParam& rsInfoParam);
    void createChain();
    void draw(const NNS_VECTORFAST& rsPosVecFast, const NNS_QUATERNION& rsRotQuat);
};

typedef clsPendulum::stcInfoParam stcInfoParam;

#endif // PENDULUM_HPP
