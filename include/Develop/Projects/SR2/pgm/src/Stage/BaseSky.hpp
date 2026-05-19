#ifndef BASESKY_HPP
#define BASESKY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0xC
struct stcBinDataDetail {
    s32 a32RotNode1; // offset 0x0, size 0x4
    s32 a32RotNode2; // offset 0x4, size 0x4
    s32 a32RotNode3; // offset 0x8, size 0x4
};

// total size: 0xB0
class clsBaseSky_Task : public clsTask {
public:
    clsBaseSky_Task(stcBinInfo& rsBinInfoI);
    virtual ~clsBaseSky_Task() {}

    virtual void execute();
    virtual void draw();

    clsModelType_OB_TX m_cModel;       // offset 0x54, size 0x8
    f32 m_sTrsMtx[4][4];               // offset 0x60, size 0x40
    stcBinDataDetail* m_opsSkyRotData; // offset 0xA0, size 0x4
    stcBinDataDetail m_sSkyRotData;    // offset 0xA4, size 0xC
};

#endif // BASESKY_HPP
