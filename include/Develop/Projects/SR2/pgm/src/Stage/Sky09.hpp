#ifndef SKY09_HPP
#define SKY09_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"

// total size: 0x4
struct stcThunderFogRange {
    s16 s16Near; // offset 0x0, size 0x2
    s16 s16Far;  // offset 0x2, size 0x2
};

// total size: 0xE0
class clsSky09_Task : public clsTask {
public:
    // Note: DWARF flattens several incompatible stcDetail layouts; Sky09 uses the 0x3 variant.
    struct stcDetail {
        u8 u8BackUpFogNo; // offset 0x0, size 0x1
        u8 u8ThundeMode;  // offset 0x1, size 0x1
        u8 bOutDoor_Old;  // offset 0x2, size 0x1
    };

    clsSky09_Task(stcBinInfo& rsBinInfoI);
    virtual ~clsSky09_Task() {}

    virtual void execute();
    virtual void draw();

    f32 m_sTrsMtx[4][4];                 // offset 0x60, size 0x40
    clsModelType_OB_TX_MO_MA m_cModel;   // offset 0xA0, size 0x20
    clsBaseRace_Task* m_pcBaseRace_Task; // offset 0xC0, size 0x4
    stcDetail m_asDetail[4];             // offset 0xC4, size 0xC
    u16 m_u16ThunderProbability;         // offset 0xD0, size 0x2
    f32* m_pf32ThunderFrame;             // offset 0xD4, size 0x4
};

#endif // SKY09_HPP
