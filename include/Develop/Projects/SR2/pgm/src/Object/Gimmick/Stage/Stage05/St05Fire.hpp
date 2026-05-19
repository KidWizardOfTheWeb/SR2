#ifndef ST05FIRE_HPP
#define ST05FIRE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleLayer.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsFire_Obj;

class clsFireModel {
public:
    clsFireModel() {}
    ~clsFireModel() {}

    clsModelType_OB_TX m_acModel[2]; // offset 0x0, size 0x10
};

// total size: 0x80
class clsFire_Obj : public clsGimmickObj {
public:
    enum enmMode {
        MODE__NONE = 0,
        MODE__SETUP = 1,
        MODE__CHARGE = 2,
        MODE__READY_SHOOT = 3,
        MODE__SHOOT = 4,
        MODE__CRUISE = 5,
        MODE__BLAST = 6,
    };

    clsFire_Obj() {}
    virtual ~clsFire_Obj() {}

    virtual void setData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST05_FIRE_15020; }

    static s8 t_s8DrawModelNo;
    static f32 m_tof32AnimNum;

    enmMode m_eMode;                 // offset 0x50, size 0x4
    clsParticleLayer* m_pcSparks;    // offset 0x54, size 0x4
    NNS_VECTORFAST m_sSparksPosFast; // offset 0x60, size 0x10
    u8 m_u8FireType;                 // offset 0x70, size 0x1
};

// total size: 0xA4
class clsFire_Task : public clsBaseGimmickBody<clsFire_Task, clsFire_Obj, clsFireModel> {
public:
    inline clsFire_Task(u32 u32ViewNo) : clsBaseGimmickBody(0, 0) {}
    virtual ~clsFire_Task() {}

    f32* m_pf32TexCoordU; // offset 0x9C, size 0x4
    f32 m_f32AnimSpeed;   // offset 0xA0, size 0x4

    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);
    virtual void execute();
    virtual void draw();
};

#endif // ST05FIRE_HPP
