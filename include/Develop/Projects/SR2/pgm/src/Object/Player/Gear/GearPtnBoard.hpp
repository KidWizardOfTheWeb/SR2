#ifndef GEARPTNBOARD_HPP
#define GEARPTNBOARD_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBasePrototype.hpp"

// total size: 0x70
class clsGearPtnBoard : public clsGearBasePrototype {
public:
    clsGearPtnBoard(clsGearCtrl* pcGearCtrl,
                    const stcGearData& rsGearData,
                    const stcAddPrfm& rsGearPrfm)
        : clsGearBasePrototype(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearPtnBoard() {}

    virtual void setHideNodeStatus(u32* pStatus)
    {
        pStatus[1] = *(u8*)((u8*)m_pcGearCtrl + 0xDE); // clsGearCtrl::m_bIsDrawBurnLight
    }
    virtual enmGearType getGearType() const { return GEAR_TYPE_BOARD; }
    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(0); }
    virtual void clearChangeActionParam();
    virtual void behavior();
    virtual void behavior_NodeMtx();
    virtual enmMotionType getBaseMotionType() const { return (enmMotionType)(1); }
    virtual s32 getGearRunSeNo() const { return 0; }

    f32 m_f32UpMove;  // offset 0x60, size 0x4
    f32 m_f32SideMov; // offset 0x64, size 0x4
};

#endif // GEARPTNBOARD_HPP
