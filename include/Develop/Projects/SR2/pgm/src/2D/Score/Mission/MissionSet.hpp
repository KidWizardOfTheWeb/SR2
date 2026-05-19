#ifndef MISSIONSET_HPP
#define MISSIONSET_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OODraw2d.hpp"

struct _NNS_TEXLIST;

namespace nspOOMisc {
struct stcPoint2D_s16;
}

namespace nspMissionSet {
void drawScoreBoxAttack(f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4);
void drawScoreBoxSkill(f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4);
void drawScoreBoxBreak(f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4);
void drawScoreBoxMark(f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4);
void drawScoreBoxGDive(f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4);
void drawScoreBoxGRink(f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4);
void drawScoreBoxAGP(f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4);
void drawScoreBoxTrick(f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4);
void drawScoreBoxRing(f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4);
void drawScoreBoxTime(f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4);
void drawScoreBoxLevel(
    f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4, f32 f32Param5, f32 f32Param6);
void drawScoreBoxMsg(f32 f32Param1, f32 f32Param2, u8 u8Param3, u32 u32Param4);
void drawScoreBox(f32 f32Param1, f32 f32Param2, u32 u32Param3, s32 s32Param4, f32 f32Param5);
void drawWindow(f32 f32Param1,
                f32 f32Param2,
                f32 f32Param3,
                f32 f32Param4,
                s32 s32Param5,
                u32 u32Param6,
                f32 f32Param7);
void drawWindowDx(f32 f32Param1,
                  f32 f32Param2,
                  f32 f32Param3,
                  f32 f32Param4,
                  u32 u32Param5,
                  f32 f32Param6,
                  const clsOODraw2d::stcTexUV* psParam7,
                  const nspOOMisc::stcPoint2D_s16* psParam8,
                  _NNS_TEXLIST* psParam9,
                  u32 u32Param10,
                  u32 u32Param11,
                  u32 u32Param12,
                  u32 u32Param13,
                  s32 s32Param14,
                  s32 s32Param15,
                  s32 s32Param16);
} // namespace nspMissionSet

#endif // MISSIONSET_HPP
