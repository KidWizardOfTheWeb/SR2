#ifndef SURVIVALMESSAGESET_HPP
#define SURVIVALMESSAGESET_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

struct _NNS_TEXLIST;

namespace nspSurvivalMessageSet {
enum enmIconMode {};

extern _NNS_TEXLIST* psTexList_SurvivalMessage2D;

void drawSecondS3d(
    const NNS_VECTORFAST* psParam1, s32 s32Param2, u32 u32Param3, u32 u32Param4, f32 f32Param5);
void drawSecondS(
    f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4, f32 f32Param5, f32 f32Param6);
void drawSecond(
    f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4, f32 f32Param5, f32 f32Param6);
void drawTimeS(
    f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4, f32 f32Param5, f32 f32Param6);
void calcTime();
void drawTime(
    f32 f32Param1, f32 f32Param2, u32 u32Param3, u32 u32Param4, f32 f32Param5, f32 f32Param6);
void drawNumbarSS(f32 f32Param1,
                  f32 f32Param2,
                  u32 u32Param3,
                  s32 s32Param4,
                  u32 u32Param5,
                  f32 f32Param6,
                  f32 f32Param7);
void calcNumbarS(u32 u32Param1, s32 s32Param2);
void drawNumbarS(f32 f32Param1,
                 f32 f32Param2,
                 u32 u32Param3,
                 s32 s32Param4,
                 u32 u32Param5,
                 f32 f32Param6,
                 f32 f32Param7);
void calcNumbar(s32 s32Param1);
void drawNumbar(f32 f32Param1,
                f32 f32Param2,
                u32 u32Param3,
                s32 s32Param4,
                u32 u32Param5,
                enmIconMode eParam6,
                f32 f32Param7,
                f32 f32Param8);
} // namespace nspSurvivalMessageSet

#endif // SURVIVALMESSAGESET_HPP
