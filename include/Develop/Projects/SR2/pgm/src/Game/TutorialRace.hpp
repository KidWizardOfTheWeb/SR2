#ifndef TUTORIALRACE_HPP
#define TUTORIALRACE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/MissionRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Ghost.hpp"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

class clsPressStart_Task;
class clsRacePauseTutorial_Task;

// total size: 0xD64
class clsTutorialRace_Task : public clsMissionRace_Task {
public:
    inline clsTutorialRace_Task(u32 param_1)
        : clsMissionRace_Task(0, 0, 0, 0, static_cast<enmMode>(0))
    {
    }
    virtual ~clsTutorialRace_Task() {}

    enum enmControlMode {
        MODE___PRACTICE = 0,
        MODE___TAKE_EXPAIN = 1,
        MODE___TAKE = 2,
    };

    _NNS_TEXLIST* m_psTexList_TutorialUnion2D;             // offset 0xD3C, size 0x4
    _NNS_TEXLIST* m_psTexList_TutorialMine2D;              // offset 0xD40, size 0x4
    clsPressStart_Task* m_pcPressStart2Quit_Task;          // offset 0xD44, size 0x4
    enmControlMode m_eControlMode;                         // offset 0xD48, size 0x4
    f32 m_f32TakeDrawSubjectTime;                          // offset 0xD4C, size 0x4
    f32 m_f32ResultTime;                                   // offset 0xD50, size 0x4
    clsGhost* m_pcGhostTask;                               // offset 0xD54, size 0x4
    stcSendAdv* m_psGhostLoadData;                         // offset 0xD58, size 0x4
    clsRacePauseTutorial_Task* m_pcRacePauseTutorial_Task; // offset 0xD5C, size 0x4
    u8 m_bDrawSubject_2D;                                  // offset 0xD60, size 0x1
    u8 m_bDrawPractice_2D;                                 // offset 0xD61, size 0x1
    u8 m_bAheadPressStart;                                 // offset 0xD62, size 0x1

    virtual void execute();
    virtual void wakeUpResult();
    virtual void setClearUnlock();
    virtual void setPauseScreen(s32 s32PushPausePadNo,
                                clsBaseRacePause_Task::enmPadConnectDraw enConnectDraw);
    virtual void draw();
    virtual void createGhostTask();
    virtual void
    addReadChara(oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcCharaList);
    virtual void
    addReadGear(oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcGearList,
                u32* pu32GearLoadCnt);
    virtual void addReadCharaMotion(
        std::vector<const clsGameMgr::stcSendAdv*, std::allocator<const clsGameMgr::stcSendAdv*> >*
            pcCharaMotionList);
    virtual void restart();
    virtual void selectedPauseMenu_RET___ADD_EXT();
    inline _NNS_TEXLIST* getTexListUnion2D_p() { return m_psTexList_TutorialUnion2D; }
    inline u8 isEndTakeDrawSubject() const { return 0; }
    inline u8 isClearRank() const { return 0; }
};

#endif // TUTORIALRACE_HPP
