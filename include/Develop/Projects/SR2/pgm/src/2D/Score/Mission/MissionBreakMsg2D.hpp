#ifndef MISSIONBREAKMSG2D_HPP
#define MISSIONBREAKMSG2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x5C
class clsMissionBreakMsg2D_Task : public clsTask {
public:
    clsMissionBreakMsg2D_Task() : clsTask(0x3A598, 5) {}
    clsMissionBreakMsg2D_Task(NNS_VECTORFAST* psParam1)
        : clsTask(0x3A598, 5), m_psPosVecFast(psParam1), m_u32Count(0)
    {
    }
    ~clsMissionBreakMsg2D_Task();

    virtual void execute();

    virtual void draw();

    NNS_VECTORFAST* m_psPosVecFast; // offset 0x54, size 0x4
    u32 m_u32Count;                 // offset 0x58, size 0x4
};

#endif // MISSIONBREAKMSG2D_HPP
