#ifndef ST03PATHROBO_HPP
#define ST03PATHROBO_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PathGravityObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0x220
class clsPathRobo_Obj : public clsPathGravityObj_Obj {
public:
    inline clsPathRobo_Obj() : clsPathGravityObj_Obj() {}
    virtual ~clsPathRobo_Obj() {}

    virtual void reset();
    virtual void createData();
    virtual void destroyData();
    virtual void requestDrawBreakEffect();
    virtual void draw(clsModelType_OB_TX& rcObj,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);
    inline nspPackId::enm getPackId() const { return nspPackId::ST03_PATH_ROBO_13090; }
};

// total size: 0x98
class clsPathRobo_Task
    : public clsSingleModelGimmick_Task<clsPathRobo_Task, clsPathRobo_Obj, clsModelType_OB_TX> {
public:
    clsPathRobo_Task(u32 u32ObjectAreaNum);
    virtual ~clsPathRobo_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST03PATHROBO_HPP
