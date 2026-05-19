#ifndef MISSIONTARGET_HPP
#define MISSIONTARGET_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Data/Path/PathPoint.hpp"

// total size: 0x28
class clsMissionTarget_Obj {
public:
    virtual ~clsMissionTarget_Obj() {}

    void setSearchPoint(const NNS_VECTORFAST* psPos, const NNS_VECTORFAST* psDir);

    clsRetPath m_cRetCoursePath; // offset 0x4, size 0x20
    u8 m_u8MoveFlag;             // offset 0x24, size 0x1
};

// total size: 0xC
class clsMissionTarget {
public:
    virtual ~clsMissionTarget() {}

    void initBrokenNum(u32 u32ObjectNum);
    void setBroken(u32 u32No, u8 u8Flag);
    void BrokenReset();
    u32 getBrokenNum() const;
    u8 getBroken(u32 u32No);

    u32 m_u32ObjectNum; // offset 0x4, size 0x4
    u8* m_pu8Broken;    // offset 0x8, size 0x4
};

#endif // MISSIONTARGET_HPP
