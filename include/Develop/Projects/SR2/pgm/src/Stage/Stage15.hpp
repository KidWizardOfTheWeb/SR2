#ifndef STAGE15_HPP
#define STAGE15_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Debug/Debug.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/DebugDetail.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/DivStage.hpp"
#include "usr/local/sega/nn/src/Object/nnobject.h"

class clsStage15_Task : public clsDivStage_Task {
public:
    clsStage15_Task(stcBinInfo& rsBinInfoI) : clsDivStage_Task(rsBinInfoI)
    {
        clsDebug& rcDebug = *clsDebug::GS();
        rcDebug.m_cOOMenu.addSubMenu("DEBUG", "BOSSDISP", nspDebugDetail::BossDisp);
        rcDebug.m_cOOMenu.addSubMenu("DEBUG", "BOSSDEBUG", nspDebugDetail::BossDebug);
        rcDebug.m_cOOMenu.addSubMenu("DEBUG", "BOSSATTACK", nspDebugDetail::BossAttackDebug);
        rcDebug.m_cOOMenu.addSubMenu("DEBUG", "BLACK HOLE", nspDebugDetail::BlackHoleDebug);
    }
    virtual ~clsStage15_Task();

    virtual void execute();
    virtual void reset();

    void hideNode(NNS_NODE* psNode, s32 s32Arg);
    void dispNode(NNS_NODE* psNode, s32 s32Arg);
    void hideDistantView();
    void dispDistantView();
    void changeDrawParts(u32 u32Arg1, u32 u32Arg2);

    virtual clsPathCourse* createCoursePath();
    virtual clsLap* createLap();
};

#endif // STAGE15_HPP
