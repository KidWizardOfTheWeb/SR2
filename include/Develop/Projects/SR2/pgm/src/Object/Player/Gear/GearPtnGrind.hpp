#ifndef GEARPTNGRIND_HPP
#define GEARPTNGRIND_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearBurnLight.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnBoard.hpp"

// total size: 0x80
class clsGearPtnGrind : public clsGearPtnBoard {
public:
    clsGearPtnGrind(clsGearCtrl* pcGearCtrl,
                    const stcGearData& rsGearData,
                    const stcAddPrfm& rsGearPrfm)
        : clsGearPtnBoard(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearPtnGrind() {}

    virtual void setHideNodeStatus(u32* psNodeStat) { psNodeStat[1] = 1; }
    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(6); }
    virtual u8 isUseModel() const { return 0; }
    virtual void clearChangeActionParam();
    virtual void requsetBurnLight(const f32 (&rsMtx)[4][4]) {}

    clsGearBurnLight_Task* m_pcBurnLight_Task; // offset 0x70, size 0x4
};

#endif // GEARPTNGRIND_HPP
