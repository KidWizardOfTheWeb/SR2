#ifndef RACEPAUSETUTORIAL_HPP
#define RACEPAUSETUTORIAL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/Pause/BaseRacePause.hpp"

class clsTutorialRace_Task;

// total size: 0x64
class clsRacePauseTutorial_Task : public clsBaseRacePause_Task {
public:
    virtual ~clsRacePauseTutorial_Task() {}
    void draw();

    clsTutorialRace_Task& m_rcTutorialRace_Task; // offset 0x60, size 0x4
};

#endif // RACEPAUSETUTORIAL_HPP
