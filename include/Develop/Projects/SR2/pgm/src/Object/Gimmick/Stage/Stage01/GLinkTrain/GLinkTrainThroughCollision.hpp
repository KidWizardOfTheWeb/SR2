#ifndef GLINKTRAINTHROUGHCOLLISION_HPP
#define GLINKTRAINTHROUGHCOLLISION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsGLinkTrainManager_Object;
class clsPlayerTask;

// total size: 0xC
class clsGLinkTrainThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsGLinkTrainThroughCollision() {}
    virtual void contactAlwaysEvent(clsPlayerTask* pcPlayer);

    clsGLinkTrainManager_Object* m_pcGLinkTrainManager; // offset 0x8, size 0x4
};

// total size: 0x30
class clsGLinkTrainStartThroughCol : public clsBaseThroughCollision {
public:
    virtual ~clsGLinkTrainStartThroughCol() {}
    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);

    void initCourseDirection();

    static s8 m_toas8EffectiveRanking[2][3];

    NNS_VECTORFAST m_sDirVecFast;                       // offset 0x10, size 0x10
    clsGLinkTrainManager_Object* m_pcGLinkTrainManager; // offset 0x20, size 0x4
    f32 m_f32WaitFrame;                                 // offset 0x24, size 0x4
    u8 m_u8ObjectNo;                                    // offset 0x28, size 0x1
};

#endif // GLINKTRAINTHROUGHCOLLISION_HPP
