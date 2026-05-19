#ifndef ST15FLOATINGMETEORITE_HPP
#define ST15FLOATINGMETEORITE_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkContactPoint;
class clsSe3DControl;
class clsGravityGimmickParam;

enum enmFloatingMeteoriteMode {
    MODE_INIT = 0,
    MODE_WAIT = 1,
    MODE_SHOOT_WAIT = 2,
    MODE_SHOOT = 3,
};

// total size: 0x150
class clsFloatingMeteorite_Obj : public clsBaseGravityLinkObject {
public:
    clsFloatingMeteorite_Obj();
    virtual ~clsFloatingMeteorite_Obj();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual nspPackId::enm getPackId() const { return nspPackId::ST15_FLOATING_METEORITE_25080; }
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const;

    enum enmFloatingMeteoriteMode m_eFloatingMeteoriteMode; // offset 0xE0, size 0x4
    f32 m_f32DelayFrame;                                    // offset 0xE4, size 0x4
    f32 m_f32EndFrame;                                      // offset 0xE8, size 0x4
    f32 m_sEffectMtx[4][4];                                 // offset 0xF0, size 0x40
    NNS_QUATERNION m_sRotQuat;                              // offset 0x130, size 0x10
    clsSe3DControl* m_pcSe3DControl;                        // offset 0x140, size 0x4
    clsTask* m_psEffectTask;                                // offset 0x144, size 0x4

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0x98
class clsFloatingMeteorite_Task : public clsSingleModelGimmick_Task<clsFloatingMeteorite_Task,
                                                                    clsFloatingMeteorite_Obj,
                                                                    clsModelType_OB_TX>,
                                  public clsGimmickCommon {
public:
    clsFloatingMeteorite_Task(u32 u32ObjectAreaNum);
    virtual ~clsFloatingMeteorite_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();
    virtual void createModel(stcBinInfo& rsBinInfoI) {}

    void attackFloatingMeteorite(u32 u32GroupNo);
    void setAction(bool bParam1) { m_bAction = bParam1; }

    u8 m_bAction; // offset 0x95, size 0x1
};

#endif // ST15FLOATINGMETEORITE_HPP
