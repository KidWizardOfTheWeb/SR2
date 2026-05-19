#ifndef SURVIVALMESSAGEGOALTEXT2D_HPP
#define SURVIVALMESSAGEGOALTEXT2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/GoalText2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalBall/GetPoint2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"

// total size: 0x68
class clsSurvivalMessageGoalText2D_Task : public clsTemporary2D_Task {
public:
    clsSurvivalMessageGoalText2D_Task(s32 s32Player, s32 s32Point);
    virtual ~clsSurvivalMessageGoalText2D_Task();

    virtual void execute();

    clsGoalText2D_Task* m_pcGoalText; // offset 0x58, size 0x4
    clsGetPoint2D_Task* m_pcGetPoint; // offset 0x5C, size 0x4
    s32 m_s32Player;                  // offset 0x60, size 0x4
    s32 m_s32Point;                   // offset 0x64, size 0x4
};

#endif // SURVIVALMESSAGEGOALTEXT2D_HPP
