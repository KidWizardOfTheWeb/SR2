#ifndef TAXI_HPP
#define TAXI_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class hkShape;
class hkContactPoint;
class clsObject;
class clsTaxi;

// total size: 0xC0
class clsTaxi_Obj : public clsPhantomGimmickObject {
public:
    clsTaxi_Obj();
    virtual ~clsTaxi_Obj();

    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual void init();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST01_TAXI_11080; }
    virtual void controlPlayer();

    enum enmTaxiMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmControlMode {
        CONTROL_NULL = 0,
        CONTROL_RUN = 1,
        CONTROL_STOP = 2,
    };

    void setMode(enmTaxiMode eMode) { m_eTaxiMode = eMode; }
    enmTaxiMode getMode() { return m_eTaxiMode; }
    f32 getMinSpeed() const { return m_f32MinSpeed; }
    void elaseExexuteTaxi(clsTaxi* pTaxi);

    enum enmTaxiMode m_eTaxiMode;              // offset 0x60, size 0x4
    hkShape* m_pcPhantomShape;                 // offset 0x64, size 0x4
    f32 m_f32MaxSpeed;                         // offset 0x68, size 0x4
    f32 m_f32MinSpeed;                         // offset 0x6C, size 0x4
    NNS_VECTORFAST m_sDirPosVecFast;           // offset 0x70, size 0x10
    u32 m_u32PlayerFlg;                        // offset 0x80, size 0x4
    enum enmControlMode m_aeControlMode[8];    // offset 0x84, size 0x20
    clsGimmickAutoRunBufferBase m_cTaxiBuffer; // offset 0xA4, size 0x1C
};

// total size: 0x98
class clsTaxi_Task
    : public clsSingleModelGimmick_Task<clsTaxi_Task, clsTaxi_Obj, clsModelType_OB_TX> {
public:
    clsTaxi_Task(u32 u32ObjectAreaNum);
    virtual ~clsTaxi_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

class clsBackLineEffectTask;
class clsSe3DControl;

// total size: 0x240
class clsTaxi : public clsGimmickAutoRunObj {
public:
    clsTaxi();

    virtual ~clsTaxi();

    virtual void destroy();

    void setLineParam(NNS_OBJECT* pcObj);

    void hideLine();

    void movePlayer();

    void draw(clsModelType_OB_TX& rModel,
              f32 (*psDrawMtx)[4][4],
              u32* pu32DrawFlag,
              const f32 (*psGearMtx)[4][4],
              f32 (*psDrawMtx2)[4][4],
              u32 u32DrawFlag);

    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_SLEEP = 2,
    };

    enum enmMoveMode {
        MOVEMODE_JUMP = 0,
        MOVEMODE_WAIT = 1,
        MOVEMODE_MOVE = 2,
        MOVEMODE_STOP = 3,
        MOVEMODE_RETURN = 4,
        MOVEMODE_END = 5,
        MOVEMODE_RETURN_EMPTYWAIT = 6,
        MOVEMODE_EMPTYWAIT = 7,
        MOVEMODE_EMPTYWAIT_RUN = 8,
        MOVEMODE_STARTWAIT = 9,
    };

    static u32 otau32Se_AirCarL[2];
    static u32 otau32Se_TaxiDoor[2];

    enum enmMode m_eMode;                    // offset 0x1C0, size 0x4
    enum enmMoveMode m_eMoveMode;            // offset 0x1C4, size 0x4
    clsTaxi_Obj* m_pcTaxiObj;                // offset 0x1C8, size 0x4
    NNS_VECTORFAST m_sOffsetPosVedFast;      // offset 0x1D0, size 0x10
    f32 m_f32WidthDist;                      // offset 0x1E0, size 0x4
    f32 m_f32RotY;                           // offset 0x1E4, size 0x4
    s32 m_s32SeId;                           // offset 0x1E8, size 0x4
    f32 m_sDrawMtx[4][4];                    // offset 0x1F0, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2]; // offset 0x230, size 0x8
    clsSe3DControl* m_pcSe3DControl;         // offset 0x238, size 0x4
};

#endif // TAXI_HPP
