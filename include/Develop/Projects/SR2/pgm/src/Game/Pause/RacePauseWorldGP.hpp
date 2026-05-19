#ifndef RACEPAUSEWORLDGP_HPP
#define RACEPAUSEWORLDGP_HPP

#include "Develop/Projects/SR2/pgm/src/Game/Pause/BaseRacePause.hpp"

class clsTask;

class clsRacePauseWorldGP_Task : public clsBaseRacePause_Task {
public:
    clsRacePauseWorldGP_Task(s32 s32Param1, s32& rParam2);

    virtual ~clsRacePauseWorldGP_Task();
    virtual void execute();
    virtual void draw();

    clsTask* m_pcPoint2D_Task; // offset 0x60, size 0x4
};

#endif // RACEPAUSEWORLDGP_HPP
