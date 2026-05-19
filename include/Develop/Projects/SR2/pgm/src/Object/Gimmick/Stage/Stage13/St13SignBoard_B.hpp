#ifndef ST13SIGNBOARD_B_HPP
#define ST13SIGNBOARD_B_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0x60
class clsSignBoardB_Object : public clsGimmickObj {
public:
    // Note: name collision with global enmMode in GimmickObj.hpp — this variant has MODE_CRASH vs
    // MODE_EXECUTE
    enum enmMode {
        MODE_NONE = 0,
        MODE_CRASH = 1,
        MODE_BREAK = 2,
    };

    static f32 tof32ClipSqDist;

    clsSignBoardB_Object() {}
    virtual ~clsSignBoardB_Object() {}
    virtual void setData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST13_SIGNBOARD_B_23110; }

    void draw(clsModelType_OB_TX_MO_MA& rcModel,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    enum enmMode m_eMode; // offset 0x50, size 0x4
    f32 m_f32MatFrame;    // offset 0x54, size 0x4
    f32 m_f32Scale;       // offset 0x58, size 0x4
    f32 m_f32MaxScale;    // offset 0x5C, size 0x4
};

// total size: 0xAC
class clsSignBoardB_Task : public clsSingleModelGimmick_Task<clsSignBoardB_Task,
                                                             clsSignBoardB_Object,
                                                             clsModelType_OB_TX_MO_MA> {
public:
    clsSignBoardB_Task(u32 u32ObjectAreaNum);
    virtual ~clsSignBoardB_Task() {}

    virtual void execute();
    virtual void draw();
};

#endif // ST13SIGNBOARD_B_HPP
