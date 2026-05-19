#ifndef ST02PLANT_HPP
#define ST02PLANT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

enum enmPlantMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
    MODE_BLINK = 2,
};

// total size: 0xE0
class clsPlant_Obj : public clsRigidBodyGimmickObj {
public:
    clsPlant_Obj() {}
    virtual ~clsPlant_Obj();

    virtual void reset() {}
    virtual void main() {}
    virtual u8 checkRequestDrawDebris();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST02_PLANT_12030; }

    virtual void requestDrawBreakEffect();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();

    static u32 otau32Se_Glass[2];
    static f32 tof32ClipSqDist;

    enmPlantMode m_ePlantMode; // offset 0xD0, size 0x4
};

// total size: 0x98
class clsPlant_Task
    : public clsSingleModelGimmick_Task<clsPlant_Task, clsPlant_Obj, clsModelType_OB_TX> {
public:
    clsPlant_Task(u32 u32ObjectAreaNum);
    virtual ~clsPlant_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST02PLANT_HPP
