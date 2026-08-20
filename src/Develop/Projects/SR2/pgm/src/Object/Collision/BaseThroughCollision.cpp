#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokBase.hpp"
#include "usr/local/sega/nn/src/Matrix/nnquaternion.h"

inline clsSimpleShapePhantom::clsSimpleShapePhantom(const hkShape* pcShape,
                                                    const hkTransform& rcTransform,
                                                    u32 u32FilterInfo)
    : hkSimpleShapePhantom(pcShape, rcTransform, u32FilterInfo), m_pvUserData01(0)
{
    m_userData = 0;
}

void clsBaseThroughCollision::create(const NNS_VECTOR* psPosVec,
                                     const NNS_QUATERNION* psQuat,
                                     hkShape* pcShape)
{
    hkVector4 cPos(psPosVec->x, psPosVec->y, psPosVec->z, 0.0f);

    NNS_QUATERNION sQuat;
    nnNormalizeQuaternion(&sQuat, psQuat);

    hkQuaternion cRot(sQuat.x, sQuat.y, sQuat.z, sQuat.w);

    hkTransform cTransform;
    cTransform.setTranslation(cPos);
    cTransform.m_rotation.set(cRot);

    m_pcPhantom = new (HK_MEMORY_CLASS_PHANTOM) clsSimpleShapePhantom(pcShape, cTransform, 0x40002);
    m_pcPhantom->m_userData = this;
    clsHavok::GS()->m_pcWorld->addPhantom(m_pcPhantom);
    m_pcPhantom->removeReference();
}

void clsBaseThroughCollision::destroy()
{
    if (m_pcPhantom != 0) {
        clsHavok::GS()->m_pcWorld->removePhantom(m_pcPhantom);
        m_pcPhantom = 0;
    }
}

void clsBaseThroughCollision::contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
    contactTriggerEvent((clsPlayerTask*)pcObject);
}

void clsBaseThroughCollision::contactAlwaysEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
    contactAlwaysEvent((clsPlayerTask*)pcObject);
}

void clsBaseThroughCollision::contactRemoveEvent(hkContactPoint* pcContact, clsObject* pcObject)
{
    contactRemoveEvent((clsPlayerTask*)pcObject);
}

void clsBaseThroughCollision::draw()
{
    clsHavok::GS()->drawShape(
        clsTaskManager::GS()->getCurViewNo(),
        m_pcPhantom->m_collidable.m_shape,
        *reinterpret_cast<const hkTransform*>(m_pcPhantom->m_collidable.m_motion),
        0x80);
}
