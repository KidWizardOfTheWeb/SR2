#ifndef ST06ELEVATOR_HPP
#define ST06ELEVATOR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsElevator;
class hkShape;

// total size: 0xD0
class clsElevator_Obj : public clsPhantomGimmickObject {
public:
    enum enmElevatorMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    // enmControlMode collision with global enmControlMode in PlayerData.hpp
    // Global values: CONTROL_FOLLOW, CONTROL_MAIN — these differ from local values
    enum enmControlMode {
        CONTROL_NULL = 0,
        CONTROL_RUN = 1,
        CONTROL_STOP = 2,
    };

    ~clsElevator_Obj();

    clsElevator_Obj();

    void setMode(enmElevatorMode mode);

    enmElevatorMode getMode() const;

    void eraseExexuteElevator(clsElevator* pElevator);

    nspPackId::enm getPackId() const;

    void controlPlayer();

    void setData();

    void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);

    void createData();

    void destroyData();

    enmElevatorMode m_eElevatorMode;               // offset 0x60, size 0x4
    hkShape* m_pcPhantomShape;                     // offset 0x64, size 0x4
    NNS_VECTORFAST m_sDirPosVecFast;               // offset 0x70, size 0x10
    f32 m_f32MaxSpeed;                             // offset 0x80, size 0x4
    f32 m_f32MinSpeed;                             // offset 0x84, size 0x4
    u32 m_u32PlayerFlg;                            // offset 0x88, size 0x4
    enmControlMode m_aeControlMode[8];             // offset 0x8C, size 0x20
    clsGimmickAutoRunBufferBase m_cElevatorBuffer; // offset 0xAC, size 0x1C
};

// total size: 0x9C
class clsElevator_Task
    : public clsSingleModelGimmick_Task<clsElevator_Task, clsElevator_Obj, clsModelType_OB_TX> {
public:
    clsElevator_Task(u32 u32ObjectAreaNum);
    virtual ~clsElevator_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    s32 m_s32SeId;      // offset 0x94, size 0x4
    s32 m_s32PlaySeNum; // offset 0x98, size 0x4
};

// total size: 0x1F0
class clsElevator : public clsGimmickAutoRunObj {
public:
    clsElevator();

    virtual ~clsElevator();

    void movePlayer();

    void draw(clsModelType_OB_TX& rModel,
              f32 (*psDrawMtx)[4][4],
              u32* pu32DrawFlag,
              const f32 (*psGearMtx)[4][4],
              f32 (*psDrawMtx2)[4][4],
              u32 u32DrawFlag);

    static f32 tof32ClipSqDist;

    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_SLEEP = 2,
    };

    enum enmMoveMode {
        MOVEMODE_JUMP = 0,
        MOVEMODE_WAIT = 1,
        MOVEMODE_MOVE = 2,
        MOVEMODE_MOVEEND = 3,
        MOVEMODE_STOP = 4,
        MOVEMODE_RETURN = 5,
        MOVEMODE_END = 6,
        MOVEMODE_RETURN_EMPTYWAIT = 7,
        MOVEMODE_EMPTYWAIT = 8,
        MOVEMODE_EMPTYWAIT_RUN = 9,
        MOVEMODE_STARTWAIT = 10,
    };

    enum enmMode m_eMode;               // offset 0x1C0, size 0x4
    enum enmMoveMode m_eMoveMode;       // offset 0x1C4, size 0x4
    clsElevator_Obj* m_pcElevatorObj;   // offset 0x1C8, size 0x4
    NNS_VECTORFAST m_sOffsetPosVedFast; // offset 0x1D0, size 0x10
    f32 m_f32WidthDist;                 // offset 0x1E0, size 0x4
    f32 m_f32RotY;                      // offset 0x1E4, size 0x4
    f32 m_f32InterpolateFrame;          // offset 0x1E8, size 0x4
    s32 m_A32InterpolateRot;            // offset 0x1EC, size 0x4
};

#endif // ST06ELEVATOR_HPP
