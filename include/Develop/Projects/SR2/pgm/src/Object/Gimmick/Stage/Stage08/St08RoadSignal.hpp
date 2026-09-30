#ifndef ST08ROADSIGNAL_HPP
#define ST08ROADSIGNAL_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08Road.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

// total size: 0x60
class clsRoadSignal_Obj : public clsGimmickObj {
public:
    // RECONSTRUCTED: enum scope.
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsRoadSignal_Obj() : m_eMode(MODE_INIT), m_f32MotionFrame(0.0f), m_pcRoadObj(NULL) {}
    virtual ~clsRoadSignal_Obj() { destroyData(); }
    virtual nspPackId::enm getPackId() const { return nspPackId::ST08_ROAD_SIGNAL_18010; }

    void execute();
    void draw(clsModelType_OB_TX_MO& rParam1,
              NNS_MATRIX* psMtxPal,
              u32* pParam3,
              const NNS_MATRIX* opaNnViewMtx,
              NNS_MATRIX* psMtxWork,
              u32 u32Param6);

    enmMode m_eMode;          // offset 0x50, size 0x4
    f32 m_f32MotionFrame;     // offset 0x54, size 0x4
    clsRoad_Obj* m_pcRoadObj; // offset 0x58, size 0x4
    f32 m_f32OldFrame;        // offset 0x5C, size 0x4

    static f32 m_tof32CLIP_DISTx2;
};

class clsRoadSignal_Task : public clsSingleModelGimmick_Task<clsRoadSignal_Task,
                                                             clsRoadSignal_Obj,
                                                             clsModelType_OB_TX_MO> {
public:
    clsRoadSignal_Task(u32 u32ObjectAreaNum) : clsSingleModelGimmick_Task(u32ObjectAreaNum, 101010)
    {
    }
    virtual ~clsRoadSignal_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST08ROADSIGNAL_HPP
