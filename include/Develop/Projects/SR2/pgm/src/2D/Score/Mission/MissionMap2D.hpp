#ifndef MISSIONMAP2D_HPP
#define MISSIONMAP2D_HPP

#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreMap2D.hpp"

// total size: 0x80
class clsMissionMap2D : public clsScoreMap2D {
public:
    virtual ~clsMissionMap2D() {}
    virtual void drawEtc(f32 (*psClipMtx)[4][4], u8 u8DrawAlpha);
};

#endif // MISSIONMAP2D_HPP
