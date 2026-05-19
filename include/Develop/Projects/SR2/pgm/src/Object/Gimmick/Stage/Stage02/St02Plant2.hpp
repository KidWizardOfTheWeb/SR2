#ifndef ST02PLANT2_HPP
#define ST02PLANT2_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Plant.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0xE0
class clsPlant2_Obj : public clsRigidBodyGimmickObj {
public:
    clsPlant2_Obj() {}
    virtual ~clsPlant2_Obj() {}

    virtual void reset() {}
    virtual void main() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::ST02_PLANT_12031; }

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void requestDrawBreakEffect();

    enum enmPlantMode m_ePlantMode; // offset 0xD0, size 0x4
    static f32 tof32ClipSqDist;
};

// total size: 0x98
class clsPlant2_Task
    : public clsSingleModelGimmick_Task<clsPlant2_Task, clsPlant2_Obj, clsModelType_OB_TX> {
public:
    clsPlant2_Task(u32 u32ObjectAreaNum);
    virtual ~clsPlant2_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST02PLANT2_HPP
