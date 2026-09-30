#ifndef GHOST_HPP
#define GHOST_HPP

#include "types.h"
#include "usr/local/sce/ee/lib/libkernl/kprintf2.h"
#include "macros.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsPlayerGhost;
class clsPlayerTask;

// total size: 0x24
struct stcGhostData_1F {
    f32 f32PosX;            // offset 0x0, size 0x4
    f32 f32PosY;            // offset 0x4, size 0x4
    f32 f32PosZ;            // offset 0x8, size 0x4
    f32 f32QuatX;           // offset 0xC, size 0x4
    f32 f32QuatY;           // offset 0x10, size 0x4
    f32 f32QuatZ;           // offset 0x14, size 0x4
    f32 f32QuatW;           // offset 0x18, size 0x4
    f32 f32CurveMotionRate; // offset 0x1C, size 0x4
    u32 u8MotionState : 8;  // offset 0x20
    u32 u7MotionCurrentNo : 7;
    u32 u1IsRide : 1;
    u32 u4BaseMotType : 4;
    u32 u4EquipsGears : 4;
    u32 u5ActionType : 5;
    u32 u1IsAttack : 1;
    u32 u2Padding1 : 2;
};

// total size: 0xFD24
struct stcGhostDataBuf {
    u32 u32DataNum;               // offset 0x0, size 0x4
    stcGhostData_1F asData[1800]; // offset 0x4, size 0xFD20
};

// total size: 0xFD40
struct stcGhostSaveData {
    u32 u32CrcData;             // offset 0x0, size 0x4
    u32 u32GoalTimeMSec;        // offset 0x4, size 0x4
    stcSendAdv sCharaLoadParam; // offset 0x8, size 0x4
    u32 u4StageNoSub1 : 4;      // offset 0xC
    u32 u1IsUsed : 1;
    u32 u1FrameRate : 1;
    u32 u2Padding : 2;
    u32 u8Version : 8;
    u32 u8Padding1 : 8;
    u32 u8Padding2 : 8;
    stcGhostDataBuf sBuf; // offset 0x10, size 0xFD24
    u8 u8Padding[12];     // offset 0xFD34, size 0xC
};

// total size: 0x70
struct stcGhostInfo {
    NNS_VECTORFAST sPos;    // offset 0x0, size 0x10
    NNS_QUATERNION sQuat;   // offset 0x10, size 0x10
    NNS_MATRIX sDrawMatrix; // offset 0x20, size 0x40
    u8 u8CharaType;         // offset 0x60, size 0x1
    u8 bIsEnable;           // offset 0x61, size 0x1
};

// total size: 0xFE10
class clsGhost : public clsSingleton<clsGhost>, public clsTask {
public:
    static stcGhostSaveData* t_psSaveBuf;

    clsGhost(u8 u8PlayerNo, clsPlayerTask* pcPlayer, bool bEnableSave) : clsTask(0, 0) {}
    virtual ~clsGhost() {}

    virtual void execute();
    virtual void draw();

    void setStartFlag(bool bFlag);
    void* getSaveDataBuff(s32 s32Idx);
    u8 checkGhostDataCrc(const void* pv);
    void setGhostData(void* pv, bool bFlag, const u16* pu16);
    void updateGhostPlayer();
    void restart();
    void createGhostSaveBuffer();
    static stcSendAdv* getGhostLoadData(u32 u32StageNoI)
    {
        if (u32StageNoI == 0 || u32StageNoI > 16) {
            SUPER_ASSERT(0x32652012,
                         "Ghost.h",
                         386,
                         "clsGhost::getGhostLoadData() ステージナンバーが範囲外です。\n");
        }
        if (t_psSaveBuf->u1IsUsed && t_psSaveBuf->u4StageNoSub1 == u32StageNoI - 1) {
            return &t_psSaveBuf->sCharaLoadParam;
        }
        return NULL;
    }
    bool getGhostDownloadFlag(u32 u32Idx); // RECONSTRUCTED: return type.

    clsPlayerGhost* m_pcGhostPlayer;      // offset 0x58, size 0x4
    clsPlayerTask* m_pcPlayer;            // offset 0x5C, size 0x4
    stcGhostDataBuf m_sWorkBuf;           // offset 0x60, size 0xFD24
    u8 m_u8CurrentDataNo;                 // offset 0xFD84, size 0x1
    u8 m_u8StageNo;                       // offset 0xFD85, size 0x1
    u8 m_bIsFinished;                     // offset 0xFD86, size 0x1
    u8 m_bIsBuffOver;                     // offset 0xFD87, size 0x1
    u32 m_u32FrameCount;                  // offset 0xFD88, size 0x4
    u32 m_u32PosLinearInterpolationFrame; // offset 0xFD8C, size 0x4
    u32 m_u32PlayDataNum;                 // offset 0xFD90, size 0x4
    u8 m_bEnableSave;                     // offset 0xFD94, size 0x1
    u8 m_bStartFlag;                      // offset 0xFD95, size 0x1
    stcGhostInfo m_sGhostInfo;            // offset 0xFDA0, size 0x70
};

#endif // GHOST_HPP
