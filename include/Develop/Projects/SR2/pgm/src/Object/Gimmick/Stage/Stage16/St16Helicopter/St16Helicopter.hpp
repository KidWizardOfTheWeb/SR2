#ifndef ST16HELICOPTER_HPP
#define ST16HELICOPTER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/SlerpQuat.hpp"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "usr/local/sega/nn/src/Object/nnobject.h"

class clsSe3DControl;
class clsPlayerTask;

// total size: 0x20
struct stcPointData {
    NNS_VECTORFAST sPointVecFast; // offset 0x0, size 0x10
    f32 f32WaitFrame;             // offset 0x10, size 0x4
    u8 u8Flg;                     // offset 0x14, size 0x1
};

// total size: 0x190
class clsHelicopter_Obj : public clsRigidBodyGimmickObj {
public:
    // Note: enmMode name collision with Game.hpp — nested to resolve ambiguity
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    // Note: enmState name collision with St07MapPartsFloorSwitch.hpp — nested to resolve ambiguity
    enum enmState {
        STATE_NULL = 0,
        STATE_MAIN = 1,
        STATE_MAIN_ROTATE = 2,
        STATE_ROTATE = 3,
        STATE_LIGHT = 4,
        STATE_GRAVITY = 5,
    };

    clsHelicopter_Obj() {}
    virtual ~clsHelicopter_Obj() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::ST16_HELICOPTER_OBJ_26001; }

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* p);
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();

    void calcDirVecFast();
    void getNextPointRotate(NNS_QUATERNION& rQuat, u32 u32Idx);
    void slowDown(f32 f32Speed);
    void start();
    void draw(clsModelType_OB_TX_MO& rModel,
              f32 (*pMtx)[4][4],
              u32* pu32Flg,
              const f32 (*pBaseMtx)[4][4],
              f32 (*pDstMtx)[4][4],
              u32 u32Arg1,
              u32 u32Arg2);

    enmMode m_eMode;                   // offset 0xD0, size 0x4
    enmState m_eState;                 // offset 0xD4, size 0x4
    f32 m_f32Frame;                    // offset 0xD8, size 0x4
    f32 m_f32Speed;                    // offset 0xDC, size 0x4
    NNS_VECTORFAST m_sDirVecFast;      // offset 0xE0, size 0x10
    NNS_VECTORFAST m_sLightPosVecFast; // offset 0xF0, size 0x10
    NNS_QUATERNION m_sDrawRotQuat;     // offset 0x100, size 0x10
    NNS_ROTATE_A32* m_opsLightRotVec;  // offset 0x110, size 0x4
    clsSlerpQuat m_cSlerpQuat;         // offset 0x114, size 0x3C
    stcPointData* m_psPointTbl;        // offset 0x150, size 0x4
    f32 m_f32RotX;                     // offset 0x154, size 0x4
    f32 m_f32RotZ;                     // offset 0x158, size 0x4
    f32 m_f32RotZAdd;                  // offset 0x15C, size 0x4
    f32 m_f32LightFrame;               // offset 0x160, size 0x4
    f32 m_f32GroundLightY;             // offset 0x164, size 0x4
    clsSe3DControl* m_pcSe3DControl;   // offset 0x168, size 0x4
    f32 m_f32StartRotFrame;            // offset 0x16C, size 0x4
    f32 m_f32SlowDownFrame;            // offset 0x170, size 0x4
    u32 m_u32Flg;                      // offset 0x174, size 0x4
    u16 m_u16PlayerFlg;                // offset 0x178, size 0x2
    u8 m_bLight;                       // offset 0x17A, size 0x1
    u8 m_bDrawLightGround;             // offset 0x17B, size 0x1
    u8 m_u8PointArrayNum;              // offset 0x17C, size 0x1
    u8 m_u8PointIndex;                 // offset 0x17D, size 0x1
    u8 m_au8BackUpLigthNo[8];          // offset 0x17E, size 0x8

    static NNS_PRIM3D_PCT t_asPrim3D_PCT_Polygon[4];
    static s32 t_s32TryPrim3D_PCT_Num;
    static f32 t_of32ClipDistx2;
    static NNS_VECTORFAST t_osLightOffsetPosVecFast;
};

// total size: 0x70
class clsHelicopter_Manager : public clsPhantomGimmickObject {
public:
    // Note: enmMode name collision with Game.hpp — nested to resolve ambiguity
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    clsHelicopter_Manager();
    virtual ~clsHelicopter_Manager();
    virtual void init();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const;
    virtual void contactAlwaysEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual void draw(clsModelType_OB_TX_MO& rParam1,
                      f32 (*psMtxPal)[4][4],
                      u32* pParam3,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32Param6);

    enmMode m_eMode;                // offset 0x60, size 0x4
    clsHelicopter_Obj* m_pcObjects; // offset 0x64, size 0x4
    stcSetDataDetail* m_psSetData;  // offset 0x68, size 0x4
    u32 m_u32ObjNum;                // offset 0x6C, size 0x4
};

// total size: 0xAC
class clsHelicopter_Task : public clsSingleModelGimmick_Task<clsHelicopter_Task,
                                                             clsHelicopter_Manager,
                                                             clsModelType_OB_TX_MO> {
public:
    clsHelicopter_Task(u32 u32ObjectAreaNum);
    virtual ~clsHelicopter_Task();
    virtual void reset();
    virtual void execute();
    virtual void draw();

    // Members
    NNS_ROTATE_A32* m_psLightRootRot;      // offset 0x9C, size 0x4
    f32 m_f32LightFrame;                   // offset 0xA0, size 0x4
    NNS_ROTATE_A32* m_psPropellerBigRot;   // offset 0xA4, size 0x4
    NNS_ROTATE_A32* m_psPropellerSmallRot; // offset 0xA8, size 0x4
};

#endif // ST16HELICOPTER_HPP
