#ifndef GRAVITYBGM_HPP
#define GRAVITYBGM_HPP

#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"

// total size: 0x78
class clsGravityBgm_Task : public clsTask {
public:
    virtual ~clsGravityBgm_Task();
    virtual void execute();

    void getPlayerGravityInfo(u32& u32StatO);
    void playBgm(bool bReadyI, bool bNextI);
    void playXbox360(bool bReadyI);

    c8 m_ac8Name_BGM[14];        // offset 0x54, size 0xE
    c8 m_ac8Name_X[14];          // offset 0x62, size 0xE
    c8 m_c8EndCode_BGM;          // offset 0x70, size 0x1
    u8 m_u8BgmMode;              // offset 0x71, size 0x1
    u8 m_bReady_X;               // offset 0x72, size 0x1
    u8 m_bReady_Bgm;             // offset 0x73, size 0x1
    u8 m_bMulti;                 // offset 0x74, size 0x1
    s8 m_s8HangOnPlayerNo_Start; // offset 0x75, size 0x1
    s8 m_s8HangOnPlayerNo_End;   // offset 0x76, size 0x1
};

#endif // GRAVITYBGM_HPP
