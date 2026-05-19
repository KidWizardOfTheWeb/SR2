#ifndef MAGBARRIER_HPP
#define MAGBARRIER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "usr/local/metrowerks/PS2_Support/stl/deque.h"

class clsPlayerTask;

class clsMagBarrier_Obj : public clsGimmickObj {
public:
    enum enmMode { // Note: name collision with Game.hpp and others
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_DEAD = 2,
    };

    clsMagBarrier_Obj() {}
    virtual ~clsMagBarrier_Obj() {}

    virtual void destroyData();
    void execute();
    virtual nspPackId::enm getPackId() const { return nspPackId::MAG_BARRIRER_2220; }

    enmMode m_eMode;                   // offset 0x50, size 0x4
    clsPlayerTask* m_pcPlayer;         // offset 0x54, size 0x4
    hkSimpleShapePhantom* m_pcPhantom; // offset 0x58, size 0x4
    f32 m_f32Scale;                    // offset 0x5C, size 0x4
    u32 m_u32NodeNo;                   // offset 0x60, size 0x4
    u8 m_bInfinity;                    // offset 0x64, size 0x1
    clsFrameControl m_cFrameControl;   // offset 0x68, size 0x8
};

// total size: 0x20
class clsOODeque : public deque {
public:
    u8 m_au8Storage[0x8]; // offset 0x18, size 0x8
};

// total size: 0xEC
class clsMagBarrier_Task : public clsSingleModelGimmick_Task<clsMagBarrier_Task,
                                                             clsMagBarrier_Obj,
                                                             clsModelType_OB_TX_MO_MA> {
public:
    clsMagBarrier_Task(const stcSetDataDetail& orsSetDataDetailI);
    virtual ~clsMagBarrier_Task() {}

    clsOODeque m_tddqUseObj;   // offset 0xAC, size 0x20
    clsOODeque m_tddqUnUseObj; // offset 0xCC, size 0x20

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual clsMagBarrier_Obj* getRegistObj(clsPlayerTask* pcPlayer);
    virtual void regist(clsPlayerTask* pcPlayer, bool bInfinity);
    virtual void change(clsPlayerTask* pcPlayer00, clsPlayerTask* pcPlayer01);
    inline void setSetData(const stcSetDataDetail& rParam1) {}
};

#endif // MAGBARRIER_HPP
