#ifndef BULLETINBOARD_HPP
#define BULLETINBOARD_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0xE0
class clsBulletinBoard_Obj : public clsPutGravityObj_Obj {
public:
    clsBulletinBoard_Obj();
    virtual ~clsBulletinBoard_Obj();

    virtual void createData();
    virtual void destroyData();
    virtual void main();

    nspPackId::enm getPackId() const { return nspPackId::ST01_GUIDE_BOARD_11193; }

    void draw(clsModelType_OB_TX& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
};

// total size: 0x94
class clsBulletinBoard_Task : public clsSingleModelGimmick_Task<clsBulletinBoard_Task,
                                                                clsBulletinBoard_Obj,
                                                                clsModelType_OB_TX> {
public:
    clsBulletinBoard_Task(u32 u32ObjectAreaNum);
    virtual ~clsBulletinBoard_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // BULLETINBOARD_HPP
