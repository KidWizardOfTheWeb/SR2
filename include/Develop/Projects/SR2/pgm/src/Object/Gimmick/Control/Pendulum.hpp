#ifndef PENDULUM_HPP
#define PENDULUM_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/SpeedDown.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickRigidBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"

class hkRigidBodyCinfo;
class hkHingeLimitsData;
class hkConstraintInstance;
class hkShape;

// total size: 0x60
class clsPendulum {
public:
    // total size: 0x8
    struct stcAngleLimitsData {
        hkHingeLimitsData* pcAngleLimitData;
        hkConstraintInstance* pcConstraintInstance;
    };

    // total size: 0x18
    struct stcInfoParam {
        f32 f32Length;
        f32 f32MaxAngle;
        f32 f32AngularDamping;
        f32 f32Mass;
        f32 f32CenterMass;
        f32 f32MaxAngleVelocity;
    };
    clsPendulum(u8 u8Param1, const NNS_VECTORFAST& rsPosVecFast, const NNS_QUATERNION& rsRotQuat);
    ~clsPendulum();

    NNS_VECTORFAST m_sOffsetPosVecFast;
    NNS_QUATERNION m_sRotQuat;
    hkArray<clsGimmickRigidBody*> m_vctpcRigidBody;
    hkArray<hkShape*> m_vctpcShape;
    hkConstraintChainInstance* m_pcChainInstance;
    hkBallSocketChainData* m_pcChainData;
    hkArray<stcAngleLimitsData> m_vctsAngleLimitsData;
    u8 m_u8LineNum;
    u8 m_u8RigidNum;
    f32 m_f32WorkLength;
    hkArray<f32> m_vctRigidLength;

    static f32 m_tof32SphereRadius;

    inline void updatePosition(f32 f32Param1) {}
    inline void getPosition(u8 u8Param1, NNS_VECTORFAST& rParam2) {}
    inline void getRotQuat(u8 u8Param1, NNS_QUATERNION& rParam2) {}

    void createRigidBody(hkRigidBodyCinfo& rcInfo);
    void setInfo(const stcInfoParam& rsInfoParam);
    void createChain();
    void draw(const NNS_VECTORFAST& rsPosVecFast, const NNS_QUATERNION& rsRotQuat);
};

// MATCHING_WORKAROUND: retain nested destructor calls.
#pragma push
#pragma inline_depth(1)
inline clsPendulum::~clsPendulum()
{
    clsHavok* pcHavok = clsHavok::GS();
    {
        stcAngleLimitsData* it = m_vctsAngleLimitsData.m_data;
        stcAngleLimitsData* end = it + m_vctsAngleLimitsData.m_size;
        do {
            pcHavok->m_pcWorld->removeConstraint(it->pcConstraintInstance);
            ++it;
        } while (it != end);
    }
    pcHavok->m_pcWorld->removeConstraint(m_pcChainInstance);
    {
        clsGimmickRigidBody** it = m_vctpcRigidBody.m_data;
        clsGimmickRigidBody** end = it + m_vctpcRigidBody.m_size;
        do {
            delete *it;
            ++it;
        } while (it != end);
    }
    {
        hkShape** it = m_vctpcShape.m_data;
        hkShape** end = it + m_vctpcShape.m_size;
        do {
            delete *it;
            ++it;
        } while (it != end);
    }
}
#pragma pop

typedef clsPendulum::stcAngleLimitsData stcAngleLimitsData;

typedef clsPendulum::stcInfoParam stcInfoParam;

#endif // PENDULUM_HPP
