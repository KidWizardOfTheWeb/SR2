#ifndef LAPST15_HPP
#define LAPST15_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Lap.hpp"

// total size: 0x44
class clsLapSt15 : public clsLap {
public:
    virtual ~clsLapSt15() {}
    virtual void update();
    virtual void reset() {}
    virtual void copyLapNum(const clsLap& rcSrcLap);

    s32 m_s32TotalLapCnt; // offset 0x40, size 0x4
};

#endif // LAPST15_HPP
