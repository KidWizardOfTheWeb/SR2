#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerMotion.hpp"

void* hkBroadPhase::m_defaultCreationFunction;

void clsPlayerMotion::init(s8 s8CharaType, s8 s8ModelType, s8 s8MotionType)
{
}

void clsPlayerMotion::startPlayData()
{
}

void clsPlayerMotion::updatePlayData()
{
}

void clsPlayerMotion::registTable(s8 s8MotionType,
                                  s8 s8MotionNo,
                                  f32 f32StartFrame,
                                  f32 f32LinkFrame,
                                  clsMotion::enmStatus eStatus)
{
}

void clsPlayerMotion::registEnd(enmPriority eRegistPri, enmPriority ePlayPri)
{
}

void clsPlayerMotion::setStartDemoMotion()
{
}

void clsPlayerMotion::cancelStartDemoMotion()
{
}

void clsPlayerMotion::checkNodeMotion()
{
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

void hkVector4::add4(const hkVector4& rParam1)
{
}

void hkVector4::setNeg4(const hkVector4& rParam1)
{
}

f32 hkVector4::dot4(const hkVector4& rParam1) const
{
    return 0.0f;
}

f32 hkVector4::dot4xyz1(const hkVector4& rParam1) const
{
    return 0.0f;
}

void hkVector4::addMul4(f32 f32Param1, const hkVector4& rParam2)
{
}

void hkVector4::subMul4(f32 f32Param1, const hkVector4& rParam2)
{
}

void hkVector4::setCross(const hkVector4& rParam1, const hkVector4& rParam2)
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
}

void hkVector4::setRotatedInverseDir(const hkRotation& rParam1, const hkVector4& rParam2)
{
}

void hkVector4::setMul3(const hkMatrix3& rParam1, const hkVector4& rParam2)
{
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
