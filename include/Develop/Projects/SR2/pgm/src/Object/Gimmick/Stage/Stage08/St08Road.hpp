#ifndef ST08ROAD_HPP
#define ST08ROAD_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPlayerTask;
class clsRoadCarControl;

// total size: 0x10
struct stcRoadInfo {
    f32 f32Speed;              // offset 0x0, size 0x4
    u16 u16TotalFrame;         // offset 0x4, size 0x2
    u16 u16StartWaitFarme;     // offset 0x6, size 0x2
    u16 u16StartIntervalFrame; // offset 0x8, size 0x2
    u8 u8Path00;               // offset 0xA, size 0x1
    u8 u8Path01;               // offset 0xB, size 0x1
    u8 u8Signal;               // offset 0xC, size 0x1
    u8 u8Padd[3];              // offset 0xD, size 0x3
};

// total size: 0xA0
class clsRoad_Obj : public clsPhantomGimmickObject {
public:
    // Note: enmMode collision with Game.hpp (GAME_MODE___* pParam1) — nested per scaffold rule
    enum enmMode {
        MODE_START = 0,
        MODE_MAIN = 1,
        MODE_WAIT = 2,
    };
    // Note: enmState collision with St03Cogwheel.hpp — nested per scaffold rule
    enum enmState {
        STATE_START = 0,
        STATE_MOVEWAIT = 1,
        STATE_MOVE = 2,
        STATE_MOVE_FIX = 3,
        STATE_STOPWAIT = 4,
        STATE_STOP = 5,
        STATE_STOP_FIX = 6,
        STATE_MAX = 7,
        SIGNAL_BLUE = 2,
        SIGNAL_YELLOW = 4,
        SIGNAL_RED = 5,
    };

    class clsCarObjectLenCmp {
    public:
        bool operator()(const clsRoadCarControl* a, const clsRoadCarControl* b) const;
    };

    clsRoad_Obj() {}
    virtual ~clsRoad_Obj() {}
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObj);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST08_ROAD_18000;
    } // [verify from ASM]

    stcRoadInfo* getRoadInfo() const;              // weak inline, size:24
    enmState getState() const { return m_eState; } // weak inline, size:8

    void requestMove();
    void requestStop();
    void execute();
    u8 sortPathRate();
    u8 setCar(clsRoadCarControl* pcCar);

    enmMode m_eMode;           // offset 0x60, size 0x4
    enmState m_eState;         // offset 0x64, size 0x4
    f32 m_f32WaitFrame;        // offset 0x68, size 0x4
    f32 m_f32WorkFrame;        // offset 0x6C, size 0x4
    f32 m_f32FrameAdd;         // offset 0x70, size 0x4
    f32 m_f32ResetStopDist;    // offset 0x74, size 0x4
    clsPlayerTask* m_pcPlayer; // offset 0x78, size 0x4
    clsOOVector m_vctCar;      // offset 0x7C, size 0x10
    clsOOVector m_vctCarSort;  // offset 0x8C, size 0x10

    static stcRoadInfo t_astcRoadInfoTbl[6];
    static f32 t_of32AccleFrame;
    static f32 t_of32SlowDownFrame;
};

// total size: 0x94
class clsRoad_Task : public clsBaseGimmickBody<clsRoad_Task, clsRoad_Obj, clsModelType_OB_TX> {
public:
    clsRoad_Task(u32 u32PackId)
        : clsBaseGimmickBody<clsRoad_Task, clsRoad_Obj, clsModelType_OB_TX>(u32PackId, 0)
    {
    } // [verify params from ASM]
    virtual ~clsRoad_Task() {}

    virtual void draw();
    virtual void execute();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI) {} // weak inline, size:12
};

#endif // ST08ROAD_HPP
