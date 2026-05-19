#ifndef ST13PT_OBJ_HPP
#define ST13PT_OBJ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBomb.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class hkShape;

// total size: 0x150
class clsSt13PTObj_Obj : public clsRigidBodyGimmickObj {
public:
    inline clsSt13PTObj_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsSt13PTObj_Obj() {}

    enum enmPTObjMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmAiMode {
        AIMODE_MAIN = 0,
        AIMODE_WAIT = 1,
        AIMODE_MOVE = 2,
        AIMODE_STOP = 3,
        AIMODE_REVERS = 4,
    };

    enmPTObjMode m_eMode;             // offset 0xD0, size 0x4
    hkShape* m_pcShape;               // offset 0xD4, size 0x4
    f32 m_f32ObjPosY;                 // offset 0xD8, size 0x4
    NNS_QUATERNION m_sInitRotQuat;    // offset 0xDC, size 0x10
    f32 m_f32MovePos;                 // offset 0xEC, size 0x4
    f32 m_f32MoveFrame;               // offset 0xF0, size 0x4
    enmAiMode m_eAiMode;              // offset 0xF4, size 0x4
    f32 m_f32MoveCount;               // offset 0xF8, size 0x4
    f32 m_f32NodeAngle;               // offset 0xFC, size 0x4
    hkVector4 m_cRotSpeed;            // offset 0x100, size 0x10
    hkVector4 m_cReversSpeed;         // offset 0x110, size 0x10
    s16 m_s16HitCount;                // offset 0x120, size 0x2
    f32 m_f32WaitFrame;               // offset 0x124, size 0x4
    NNS_VECTORFAST m_sInitPosVecFast; // offset 0x130, size 0x10
    f32 m_f32No;                      // offset 0x140, size 0x4
    u8 m_bReversFlag;                 // offset 0x144, size 0x1
    f32 m_f32EffectFrame;             // offset 0x148, size 0x4
    clsSe3DControl* m_pcSe3DControl;  // offset 0x14C, size 0x4

    static f32 tof32ClipSqDist;

    virtual void reset();
    virtual void main();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void requestPowerTypeSe(clsPlayerTask* pParam1);
    inline void SetWaitMode(f32 f32Param1) {}
    inline void SetReversMode(f32 f32Param1) {}
    inline void setAiMode(enmAiMode) {}
    inline enmAiMode getAiMode() const { return AIMODE_MAIN; }
    inline nspPackId::enm getPackId() const { return nspPackId::ST13_PT_OBJ_23080; }
    virtual void init();
};

// total size: 0x9C
class clsSt13PTObj_Task
    : public clsSingleModelGimmick_Task<clsSt13PTObj_Task, clsSt13PTObj_Obj, clsModelType_OB_TX> {
public:
    clsSt13PTObj_Task(u32 u32ObjectAreaNum);
    virtual ~clsSt13PTObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    u16* m_TexIdx;  // offset 0x94, size 0x4
    u16* m_TexIdx2; // offset 0x98, size 0x4
};

#endif // ST13PT_OBJ_HPP
