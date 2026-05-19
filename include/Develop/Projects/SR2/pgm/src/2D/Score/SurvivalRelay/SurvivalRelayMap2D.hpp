#ifndef SURVIVALRELAYMAP2D_HPP
#define SURVIVALRELAYMAP2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreMap2D.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsScore2D_Task;

// total size: 0x90
class clsSurvivalRelayMap2D : public clsScoreMap2D {
public:
    clsSurvivalRelayMap2D(clsScore2D_Task* pcParent);
    virtual ~clsSurvivalRelayMap2D();

    void draw();
    void drawStartMap();

    s16 m_s16MapLeft;       // offset 0x80, size 0x2
    s16 m_s16MapTop;        // offset 0x82, size 0x2
    s16 m_s16MapWidth;      // offset 0x84, size 0x2
    s16 m_s16MapHeight;     // offset 0x86, size 0x2
    s16 m_s16MapLineHeight; // offset 0x88, size 0x2
};

#endif // SURVIVALRELAYMAP2D_HPP
