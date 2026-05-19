#ifndef RACEPAUSEMISSION_HPP
#define RACEPAUSEMISSION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/Pause/BaseRacePause.hpp"

// total size: 0x6C
class clsRacePauseMission_Task : public clsBaseRacePause_Task {
public:
    virtual ~clsRacePauseMission_Task();

    virtual void draw();
    void drawBest();
    void drawMissionMsg();

    u32 m_u32ModoNo;    // offset 0x60, size 0x4
    u32 m_u32BestScore; // offset 0x64, size 0x4
    u32 m_u32BestRank;  // offset 0x68, size 0x4
};

#endif // RACEPAUSEMISSION_HPP
