#ifndef ST14GPFAN_HPP
#define ST14GPFAN_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MultiShape.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

class clsGPFan_Obj;
class clsGPFanModel;

// total size: 0x28
class clsGPFanModel {
public:
    clsGPFanModel() {}
    ~clsGPFanModel() {}

    clsModelType_OB_TX_MO_MA m_cModel; // offset 0x0, size 0x20
    _NNS_TEXLIST* m_apsTexList[2];     // offset 0x20, size 0x8
};

// total size: 0xCC
class clsGPFan_Task : public clsMultiShape,
                      public clsBaseGimmickBody<clsGPFan_Task, clsGPFan_Obj, clsGPFanModel> {
public:
    clsGPFan_Task(u32 u32ObjectAreaNum);
    virtual ~clsGPFan_Task();

    void setDrawTexNo(u32 param_1);
    u32 getDrawTexNo() { return m_u32DrawTexNo; }

    virtual void execute();
    virtual void draw();
    virtual void reset();
    void createModel(stcBinInfo& rsBinInfoI);

    clsGmkBurnLight_Task<clsModelType_OB_TX_MO_MA>* m_pcBurnLightTask; // offset 0xC4, size 0x4
    u32 m_u32DrawTexNo;                                                // offset 0xC8, size 0x4
};

enum enmGPFanMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0x140
class clsGPFan_Obj : public clsRigidBodyGimmickObj {
public:
    inline clsGPFan_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsGPFan_Obj() {}

    enum enmGPFanMode m_eGPFanMode;  // offset 0xD0, size 0x4
    f32 m_f32MotFrame;               // offset 0xD4, size 0x4
    f32 m_f32MotEndFrame;            // offset 0xD8, size 0x4
    f32 m_f32Scale;                  // offset 0xDC, size 0x4
    f32 m_f32FanSpeed;               // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4
    f32 m_sEffectMatrix[4][4];       // offset 0xF0, size 0x40
    clsTask* m_pcEffectTask;         // offset 0x130, size 0x4

    static f32 tof32ClipSqDist;

    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const;
    virtual u8 checkRequestDrawDebris();
    u32 getTexNo() const;
};

#endif // ST14GPFAN_HPP
