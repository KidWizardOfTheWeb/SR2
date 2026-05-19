#ifndef TIMEATTACK_HPP
#define TIMEATTACK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

// Forward declarations
class clsGhost;

namespace nspTimeAttack2D {
extern _NNS_TEXLIST* psTexList_TimeAttack2D;
}

// total size: 0xCD4
class clsTimeAttack_Task : public clsBaseRace_Task {
public:
    clsTimeAttack_Task(s32 s32StageNoI,
                       s32 s32PlayerNumI,
                       s32 s32UserNumI,
                       s32 s32LapNumI,
                       const stcSendAdv* opsSendAdvI,
                       void** ppvMapBufferI,
                       enmMode eModeI);
    virtual ~clsTimeAttack_Task();
    virtual void execute();
    virtual void start();
    virtual u8 packEtc();
    virtual void restart();
    virtual void checkPauseResult(s32 bOnI);
    virtual void setPauseScreen(s32 s32PushPausePadNo,
                                clsBaseRacePause_Task::enmPadConnectDraw enConnectDraw);
    virtual void setPauseReslutScreen(s32 s32PushPausePadNo);
    virtual void
    addReadChara(oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcCharaList);
    virtual void
    addReadGear(oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcGearList,
                u32* pu32GearLoadCnt);
    virtual void addReadCharaMotion(
        std::vector<const clsGameMgr::stcSendAdv*, std::allocator<const clsGameMgr::stcSendAdv*> >*
            pcCharaMotionList);
    virtual void setBestTime();
    virtual void requestReadEtc();

    u8 saveGhostData();
    u8 loadGhostData();
    void createGhostTask();

    clsGhost* m_pcGhostTask;       // offset 0xCB0, size 0x4
    stcSendAdv* m_psGhostLoadData; // offset 0xCB4, size 0x4
    void* m_pvTimeAttack2DBuff;    // offset 0xCB8, size 0x4
    void* m_pvMemoCaIconBuff;      // offset 0xCBC, size 0x4
    u8 m_bRPauseCancel;            // offset 0xCC0, size 0x1
    u8 m_bBestTime;                // offset 0xCC1, size 0x1
    s32 m_s32OldTime;              // offset 0xCC4, size 0x4
    f32 m_f32SaveWait;             // offset 0xCC8, size 0x4
    u32 m_u32SaveMode;             // offset 0xCCC, size 0x4
    u8 m_bGhostSave;               // offset 0xCD0, size 0x1
    u8 m_bGhostOneSave;            // offset 0xCD1, size 0x1
};

#endif // TIMEATTACK_HPP
