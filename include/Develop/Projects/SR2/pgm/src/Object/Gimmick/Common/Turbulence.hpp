#ifndef TURBULENCE_HPP
#define TURBULENCE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/GroundCollision.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsRigidBody;
class clsPlayerTask;
struct hkShape;
class clsTurbulence_Obj;

// total size: 0x8
struct stcTurbInfo {
    u32 u32Index;                 // offset 0x0, size 0x4
    clsTurbulence_Obj* pcTurbObj; // offset 0x4, size 0x4
};

// total size: 0x60
struct stcSt04TurbModel {
    stcSt04TurbModel() {}
    stcSt04TurbModel(const stcSt04TurbModel& rsOther)
        : cObjStart(rsOther.cObjStart), cObjBody(rsOther.cObjBody), cObjEnd(rsOther.cObjEnd)
    {
    }

    clsModelType_OB_TX_MO_MA cObjStart; // offset 0x0, size 0x20
    clsModelType_OB_TX_MO_MA cObjBody;  // offset 0x20, size 0x20
    clsModelType_OB_TX_MO_MA cObjEnd;   // offset 0x40, size 0x20
};

// total size: 0x10
class clsTurbThroughColli : public clsBaseThroughCollision {
public:
    clsTurbThroughColli() : clsBaseThroughCollision() {}
    virtual ~clsTurbThroughColli() {}

    void contactTriggerEvent(clsPlayerTask* pcPlayer);
    void contactRemoveEvent(clsPlayerTask* pcPlayer);
    void contactAlwaysEvent(clsPlayerTask* pcPlayer);

    clsTurbulence_Obj* m_pcTurbObj; // offset 0x8, size 0x4
    u32 m_u32ColIdx;                // offset 0xC, size 0x4
};

// total size: 0x100
class clsTurbulence_Obj : public clsPhantomGimmickObject {
public:
    struct stcTurbInfo {
        u32 u32Index;                 // offset 0x0, size 0x4
        clsTurbulence_Obj* pcTurbObj; // offset 0x4, size 0x4
    };

    inline clsTurbulence_Obj() : clsPhantomGimmickObject() {}
    virtual ~clsTurbulence_Obj() {}

    enum enmTurbMode {
        MODE_INIT = 0,
        MODE_WAIT = 1,
        MODE_START_WAIT = 2,
        MODE_SLEEP = 3,
        MODE_START = 4,
        MODE_STOP = 5,
        MODE_FIN = 6,
    };

    enmTurbMode m_eMode;                   // offset 0x60, size 0x4
    NNS_VECTORFAST m_sPosVF;               // offset 0x70, size 0x10
    NNS_VECTORFAST m_sScaleVF;             // offset 0x80, size 0x10
    NNS_VECTORFAST m_sInitPosVF;           // offset 0x90, size 0x10
    NNS_QUATERNION m_sRotQ;                // offset 0xA0, size 0x10
    clsPlayerTask* m_pcPlayerTask;         // offset 0xB0, size 0x4
    clsRigidBody* m_pcRigidBody;           // offset 0xB4, size 0x4
    vector* m_pvecpcRigid;                 // offset 0xB8, size 0x4
    vector* m_pvecpcWallRigid;             // offset 0xBC, size 0x4
    f32* m_pf32Alpha;                      // offset 0xC0, size 0x4
    u32* m_pu32ActiveCnt;                  // offset 0xC4, size 0x4
    u32 m_u32ColliNum;                     // offset 0xC8, size 0x4
    u32 m_u32StartIdx;                     // offset 0xCC, size 0x4
    u32 m_u32VisibleWaitIdx;               // offset 0xD0, size 0x4
    u32 m_u32EnableWaitIdx;                // offset 0xD4, size 0x4
    u32 m_u32EnableWaitFrm;                // offset 0xD8, size 0x4
    u32 m_u32RemoveCnt;                    // offset 0xDC, size 0x4
    NNS_MATERIALPTR* m_psMaterials;        // offset 0xE0, size 0x4
    NNS_MATERIALPTR* m_psOriginalMaterial; // offset 0xE4, size 0x4
    stcTurbInfo* m_psTurbInfo;             // offset 0xE8, size 0x4
    vector m_vecpcTurbThroughColli;        // offset 0xEC, size 0xC
    u8 m_u8MatFlg;                         // offset 0xF8, size 0x1

    static u32 TURB_RIGID_KEY;
    static f32 CLIP_DISTx2;

    virtual void init(u32 u32Num,
                      clsModelType_OB_TX_MO_MA* pcModel,
                      std::vector<clsRigidBody*, std::allocator<clsRigidBody*> >* pvecpcRigid,
                      std::vector<clsRigidBody*, std::allocator<clsRigidBody*> >* pvecpcWallRigid);
    virtual void trigThroughTurb(clsPlayerTask* pcPlayer, u32 u32ColIdx);
    virtual void addTurbThroughColli(clsRigidBody* pcRigid, u32 u32Index);
    virtual void execute();
    virtual void draw(clsModelType_OB_TX_MO_MA& rcObj,
                      clsModelType_OB_TX_MO_MA& rcAObj,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4]);
    virtual void createData();
    virtual void destroyData();
    inline nspPackId::enm getPackId() const { return nspPackId::ST01_TURB_COL_11210; }
};

// total size: 0xE8
class clsTurbulence_Task
    : public clsBaseGimmickBody<clsTurbulence_Task, clsTurbulence_Obj, clsModelType_OB_TX_MO_MA> {
public:
    virtual ~clsTurbulence_Task() {}
    clsTurbulence_Task(u32 param_1)
        : clsBaseGimmickBody<clsTurbulence_Task, clsTurbulence_Obj, clsModelType_OB_TX_MO_MA>(0, 0)
    {
    } // [verify params from ASM]

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);

    void parseColliData(const clsGroundCollision::stcBinBody* psBody,
                        u32 u32Num,
                        clsTurbulence_Obj* pcTurbObj,
                        u32 u32Idx);
    clsRigidBody* create(hkShape* pcShape,
                         const clsGroundCollision::stcInfo* psInfo,
                         clsTurbulence_Obj::stcTurbInfo* psTurbInfo,
                         u8 u8IsCreateThrough);

    vector m_vecvecpcRigid;     // offset 0xAC, size 0xC
    vector m_vecvecpcWallRigid; // offset 0xB8, size 0xC
    vector m_veccObject;        // offset 0xC4, size 0xC
    vector m_veccAObject;       // offset 0xD0, size 0xC
    vector m_vecu32ColliNum;    // offset 0xDC, size 0xC
};

// Enum used by clsPutTurbulence_Obj
enum enmPutTurbMode {
    MODE_INIT = 0,
    MODE_WAIT = 1,
    MODE_SLEEP = 2,
    MODE_START = 3,
    MODE_GROW = 4,
    MODE_MOVE = 5,
    MODE_STOP = 6,
    MODE_FIN = 7,
};

// total size: 0x130
class clsPutTurbulence_Obj : public clsPhantomGimmickObject {
public:
    clsPutTurbulence_Obj() : clsPhantomGimmickObject() {}
    virtual ~clsPutTurbulence_Obj() {}

    enmPutTurbMode m_eMode;         // offset 0x60, size 0x4
    NNS_VECTORFAST m_sPosVF;        // offset 0x70, size 0x10
    NNS_VECTORFAST m_sBFPosVF;      // offset 0x80, size 0x10
    NNS_VECTORFAST m_sScaleVF;      // offset 0x90, size 0x10
    NNS_VECTORFAST m_sTailPosVF;    // offset 0xA0, size 0x10
    NNS_VECTORFAST m_sActivePosVF;  // offset 0xB0, size 0x10
    NNS_VECTORFAST* m_psNowPosVF;   // offset 0xC0, size 0x4
    NNS_QUATERNION m_sRotQ;         // offset 0xC4, size 0x10
    clsPlayerTask* m_pcPlayerTask;  // offset 0xD4, size 0x4
    clsRigidBody** m_ppcRigidBody;  // offset 0xD8, size 0x4
    clsRigidBody** m_ppcRigidGuide; // offset 0xDC, size 0x4
    clsRigidBody** m_ppcRigidBack;  // offset 0xE0, size 0x4
    u32* m_pu32ActiveCnt;           // offset 0xE4, size 0x4
    u32 m_u32ColliNum;              // offset 0xE8, size 0x4
    stcSt04TurbModel* m_psModels;   // offset 0xEC, size 0x4
    f32 m_f32MotFrameA;             // offset 0xF0, size 0x4
    f32 m_f32MotFrameC;             // offset 0xF4, size 0x4
    f32 m_f32MatFrame;              // offset 0xF8, size 0x4
    u32 m_u32StartIdx;              // offset 0xFC, size 0x4
    u32 m_u32ActiveNum;             // offset 0x100, size 0x4
    f32 m_f32TailBodyLen;           // offset 0x104, size 0x4
    u8 m_u8LineNo;                  // offset 0x108, size 0x1
    hkAabb m_cAabb;                 // offset 0x110, size 0x20

    static f32 CLIP_DISTx2;
    static f32 tf32TrickDeg;

    virtual void init(u32 u32Num, stcSt04TurbModel* psModels, clsRigidBody*** ppcRigid);
    virtual void startTurb(const NNS_VECTORFAST* psNowPosVF);
    virtual void finishTurb();
    virtual void updateCol();
    virtual void clearCol();
    virtual void execute();
    virtual void draw(stcSt04TurbModel& rcObj,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4]);
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST01_TURB_COL_11210;
    } // [ASM-derived guess — verify]
};

// total size: 0xC0
class clsPutTurbulence_Task : public clsBaseGimmickBody<clsPutTurbulence_Task,
                                                        clsPutTurbulence_Obj,
                                                        clsModelType_OB_TX_MO_MA> {
public:
    clsPutTurbulence_Task(u32 u32ObjectAreaNum);
    virtual ~clsPutTurbulence_Task() {}

    u32 m_u32ColBaseNum;        // offset 0xAC, size 0x4
    vector m_veccObject;        // offset 0xB0, size 0xC
    clsRigidBody*** m_ppcRigid; // offset 0xBC, size 0x4

    virtual void reset();
    virtual void execute();
    virtual void draw();
    virtual void createModel(stcBinInfo& rsBinInfoI);
    void parseColliData(const clsGroundCollision::stcBinBody* psBody, u32 u32Num, u32 u32Idx);
};

#endif // TURBULENCE_HPP
