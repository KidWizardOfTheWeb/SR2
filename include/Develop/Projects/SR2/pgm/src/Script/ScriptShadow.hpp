#ifndef SCRIPTSHADOW_HPP
#define SCRIPTSHADOW_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Compression/OOCompression.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsScript_Task;

// total size: 0x4
class clsOOCompModelObj : public clsOOCompObj {
public:
    virtual ~clsOOCompModelObj() {}
};

// total size: 0x90
class clsScriptShadowObj {
public:
    clsScriptShadowObj(u16 u16TaskNo,
                       u32 u32Shadow,
                       u32 u32MdlNo,
                       u32 u32Node,
                       f32 f32ScaleX,
                       f32 f32ScaleZ,
                       f32 f32OffsetX,
                       f32 f32OffsetY,
                       f32 f32OffsetZ,
                       u8 u8GlobalOffsetFlg);
    virtual ~clsScriptShadowObj() {}

    u16 m_u16Flg;          // offset 0x4, size 0x2
    u16 m_u16TaskNo;       // offset 0x6, size 0x2
    stcParam m_sCurParam;  // offset 0x8, size 0x1C
    stcParam m_sNextParam; // offset 0x24, size 0x1C
    f32 m_sDrawMtx[4][4];  // offset 0x40, size 0x40
    u32 m_u32GsOld;        // offset 0x80, size 0x4
    u32 m_u32Priority;     // offset 0x84, size 0x4

    static clsModelType_OB m_tacModel[2];

    void update();
    void drawShadowPS2();
    void initData();
    void releaseData();
    void codeShadow(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeShadowDisp(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeDelShadow(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeShadowOffset(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeShadowModel(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeShadowScale(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeShadowChange(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeShadowPriority(u8* pu8Ptr, clsScript_Task* pcTask);
    void setShadowData(u32 u32Type, stcBinInfo& rsBinInfoI);
};

// total size: 0x94
class clsScriptShadowMgr_Task : public clsTask {
public:
    virtual ~clsScriptShadowMgr_Task() {}

    void update();
    void draw();

    clsScriptShadowObj* m_apsShadowObjTask[16]; // offset 0x54, size 0x40
};

#endif // SCRIPTSHADOW_HPP
