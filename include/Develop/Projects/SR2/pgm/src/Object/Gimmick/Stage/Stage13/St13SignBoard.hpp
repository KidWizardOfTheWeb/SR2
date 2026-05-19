#ifndef ST13SIGNBOARD_HPP
#define ST13SIGNBOARD_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

enum enmSignBoardMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0xE0
class clsSignBoard_Obj : public clsRigidBodyGimmickObj {
public:
    clsSignBoard_Obj();
    virtual ~clsSignBoard_Obj();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual inline nspPackId::enm getPackId() const;
    virtual void init();

    void reset();
    void main();
    void draw(clsModelType_OB_TX& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    static f32 m_tof32CLIP_DISTx2;

    enum enmSignBoardMode m_eSignBoardMode; // offset 0xD0, size 0x4
};

class clsSignBoard_Task
    : public clsSingleModelGimmick_Task<clsSignBoard_Task, clsSignBoard_Obj, clsModelType_OB_TX> {
public:
    clsSignBoard_Task(u32 u32Param1);
    virtual ~clsSignBoard_Task();
    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // ST13SIGNBOARD_HPP
