#ifndef ST11LINEOBJ_HPP
#define ST11LINEOBJ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PathGravityObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0x230
class clsLineObj_Obj : public clsPathGravityObj_Obj {
public:
    clsLineObj_Obj() {}
    virtual ~clsLineObj_Obj() {}
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST11_LINE_OBJ_21060; }
    virtual void reset();
    virtual void mainGravity();
    virtual void mainCrash();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();

    void draw(clsModelType_OB_TX& rcObj,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    void resetRigidBody();

    f32 m_f32AliveFrame;      // offset 0x220, size 0x4
    f32 m_f32AliveFrameReset; // offset 0x224, size 0x4
    u32 m_u32DrawFlg;         // offset 0x228, size 0x4
    u8 m_u8Break;             // offset 0x22C, size 0x1

    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0x94
class clsLineObj_Task
    : public clsSingleModelGimmick_Task<clsLineObj_Task, clsLineObj_Obj, clsModelType_OB_TX> {
public:
    clsLineObj_Task(u32 u32ObjectAreaNum);
    virtual ~clsLineObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST11LINEOBJ_HPP
