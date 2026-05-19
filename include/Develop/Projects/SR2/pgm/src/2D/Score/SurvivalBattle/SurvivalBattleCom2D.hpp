#ifndef SURVIVALBATTLECOM2D_HPP
#define SURVIVALBATTLECOM2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreCom2D.hpp"

// total size: 0x40 (same as clsScoreCom2D, no new members)
class clsSurvivalBattleCom2D : public clsScoreCom2D {
public:
    virtual ~clsSurvivalBattleCom2D() {}

    virtual void draw();
};

#endif // SURVIVALBATTLECOM2D_HPP
