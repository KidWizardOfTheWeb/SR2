#ifndef RENDER2D_HPP
#define RENDER2D_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OODraw2d.hpp"
#include "types.h"

namespace nspRender2D {
void renderDirect(u32 u32Param1,
                  f32 f32Param2,
                  f32 f32Param3,
                  f32 f32Param4,
                  f32 f32Param5,
                  const clsOODraw2d::stcTexUV* psParam6,
                  u32 u32Param7);
void renderDiffClipXY(u32 u32Param1,
                      f32 f32Param2,
                      f32 f32Param3,
                      f32 f32Param4,
                      f32 f32Param5,
                      const clsOODraw2d::stcTexUV* psParam6,
                      u32 u32Param7,
                      f32 f32Param8,
                      f32 f32Param9,
                      f32 f32Param10,
                      f32 f32Param11,
                      f32 f32Param12,
                      f32 f32Param13,
                      f32 (*pasParam14)[4][4]);
void renderDiff(u32 u32Param1,
                f32 f32Param2,
                f32 f32Param3,
                f32 f32Param4,
                f32 f32Param5,
                const clsOODraw2d::stcTexUV* psParam6,
                u32 u32Param7,
                f32 f32Param8,
                f32 f32Param9,
                f32 (*pasParam10)[4][4],
                f32 f32Param11);
} // namespace nspRender2D

#endif // RENDER2D_HPP
