#ifndef STAGE11_HPP
#define STAGE11_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Sound/Cri.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11FogNearManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11Fade.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOLibChecker.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/DivStage.hpp"

// total size: 0x49C
class clsStage11_Task : public clsDivStage_Task {
public:
    clsStage11_Task(stcBinInfo& rsBinInfoI) : clsDivStage_Task(rsBinInfoI), m_s32SeId(0)
    {
        new clsFogNearManager_Task;
        new clsFadeCircle_Task;
        nspOOLibChecker::ClassC("clsStage11_Task");
        SNDF_SendFxControl(0xa4000000, 0);
    }
    virtual ~clsStage11_Task() {}
    void execute();

    s32 m_s32SeId; // offset 0x498, size 0x4
};

#endif // STAGE11_HPP
