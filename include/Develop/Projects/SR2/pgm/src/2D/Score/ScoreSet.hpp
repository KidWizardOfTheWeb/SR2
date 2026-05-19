#ifndef SCORESET_HPP
#define SCORESET_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"

struct _NNS_TEXLIST;

namespace nspScoreSet {
// total size: 0x6
struct stcMenu2D {
    u16 u16Width;          // offset 0x0, size 0x2
    u8 u8WidthMargin;      // offset 0x2, size 0x1
    u8 u8TitleWidthMargin; // offset 0x3, size 0x1
    u8 u8ItemHeight;       // offset 0x4, size 0x1
};

extern f32 of32GaugeZ;
extern f32 of32GaugeMaskZ;
extern stcPoint2D_s16 oasStageTextureSize[2];
extern stcPoint2D_s16 oasUnionTextureSize[11];
extern stcMenu2D osDrawData;
extern _NNS_TEXLIST* apsTextureList[2];

void drawWindow(
    s32 s32Param1, s32 s32Param2, s32 s32Param3, s32 s32Param4, u8 u8Param5, bool bParam6);
void drawMenu2D(s32 s32Param1, u32 u32Param2, s32 s32Param3, s32 s32Param4);
void setStageTextureList(u8* pu8Param1);
void setGameTextureList(u8* pu8Param1);
} // namespace nspScoreSet

#endif // SCORESET_HPP
