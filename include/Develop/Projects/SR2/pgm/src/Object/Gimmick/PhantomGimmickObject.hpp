#ifndef PHANTOMGIMMICKOBJECT_HPP
#define PHANTOMGIMMICKOBJECT_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/HaveGimmickPhantom.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/Debug.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"

// total size: 0x60
// Inherits clsGimmickObj (0x50) + clsHaveGimmickPhantom (0x8); trailing 8 bytes are alignment
// padding.
class clsPhantomGimmickObject : public clsGimmickObj, public clsHaveGimmickPhantom {
public:
    virtual ~clsPhantomGimmickObject() {}

    virtual void destroyCollision()
    {
        if (m_pcPhantom != NULL) {
            delete m_pcPhantom;
            m_pcPhantom = NULL;
        }
    }

    virtual void updateSetEditorCollision()
    {
        clsSimpleShapePhantom* pcPhantom = m_pcPhantom;
        if (pcPhantom != NULL) {
            hkQuaternion cRot(m_sRotQuat.x, m_sRotQuat.y, m_sRotQuat.z, m_sRotQuat.w);
            hkTransform cTransform;
            cTransform.m_translation.set(m_sPosVecFast.x, m_sPosVecFast.y, m_sPosVecFast.z, 0.0f);
            cTransform.m_rotation.set(cRot);
            pcPhantom->setTransform(cTransform);
        }
    }

    virtual void drawCollision()
    {
        if (clsDebug::GS()->m_sDrawCollision.u8DrawPhantom != 0 && m_pcPhantom != NULL) {
            clsHavok::GS()->drawShape(clsTaskManager::GS()->getCurViewNo(),
                                      m_pcPhantom->m_collidable.m_shape,
                                      m_pcPhantom->m_motionState.m_transform,
                                      0x80);
        }
    }
};

#endif // PHANTOMGIMMICKOBJECT_HPP
