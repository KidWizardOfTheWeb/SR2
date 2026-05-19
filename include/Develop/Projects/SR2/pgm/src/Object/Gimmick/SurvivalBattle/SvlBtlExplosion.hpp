#ifndef SVLBTLEXPLOSION_HPP
#define SVLBTLEXPLOSION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Turbulence.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"

class clsPlayerTask;
class hkAabbPhantom;

// total size: 0x80
class clsSvlBtlExplosion_Object : public clsGimmickObj {
public:
    enum enmMode {
        MODE__READY = 0,
        MODE__MAIN = 1,
        MODE__ERASE = 2,
    };

    enum enmDamageType {
        DAMAGE_TYPE__EXPLOSION = 0,
        DAMAGE_TYPE__MISSILE = 1,
        DAMAGE_TYPE__BOMB = 2,
    };

    ~clsSvlBtlExplosion_Object() {}

    clsSvlBtlExplosion_Object() {}

    void start(const NNS_VECTORFAST* opsPosVecFast,
               clsPlayerTask* pcOwner,
               enmDamageType eDamageType,
               f32 f32StartRadius,
               f32 f32EndRadius,
               f32 f32Frame);

    void contactPlayer(clsPlayerTask* pPlayer) {}

    void contactGimmick(clsRigidBodyGimmickObj* pGimmick) {}

    virtual void execute();

    clsPlayerTask* m_pcOwner;    // offset 0x50, size 0x4
    hkAabbPhantom* m_pcPhantom;  // offset 0x54, size 0x4
    enmMode m_eMode;             // offset 0x58, size 0x4
    enmDamageType m_eDamageType; // offset 0x5C, size 0x4
    f32 m_f32Scale;              // offset 0x60, size 0x4
    f32 m_f32AddScale;           // offset 0x64, size 0x4
    f32 m_f32LimitFrame;         // offset 0x68, size 0x4
    f32 m_f32MatFrame;           // offset 0x6C, size 0x4
    f32 m_f32MatAddFrame;        // offset 0x70, size 0x4

    static f32 t_of32CLIP_DISTx2;
};

// total size: 0xAC
class clsSvlBtlExplosion_Task : public clsSingleModelGimmick_Task<clsSvlBtlExplosion_Task,
                                                                  clsSvlBtlExplosion_Object,
                                                                  clsModelType_OB_TX_MO_MA> {
public:
    clsSvlBtlExplosion_Task(const stcSetDataDetail& orsSetDataDetailI);
    virtual ~clsSvlBtlExplosion_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    void start(const NNS_VECTORFAST* opsPosVecFast,
               clsPlayerTask* pcOwner,
               clsSvlBtlExplosion_Object::enmDamageType eDamageType,
               f32 f32StartRadius,
               f32 f32EndRadius,
               f32 f32Frame);
};

#endif // SVLBTLEXPLOSION_HPP
