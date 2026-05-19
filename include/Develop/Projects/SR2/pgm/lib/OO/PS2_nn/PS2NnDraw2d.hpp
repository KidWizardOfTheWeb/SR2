#ifndef PS2NNDRAW2D_HPP
#define PS2NNDRAW2D_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OODraw2d.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"

// total size: 0x60
class clsPfDraw2d : public clsTask, public clsSingleton<clsPfDraw2d>, public clsOODraw2d {
public:
    virtual ~clsPfDraw2d() {}

    virtual void Begin(u32 oeI);
    virtual void renderData(f32 of32x0I,
                            f32 of32y0I,
                            f32 of32x1I,
                            f32 of32y1I,
                            u32 ou32ColI,
                            const clsOODraw2d::stcTexUV* opsUVI,
                            const f32 (*opaMtxI)[4][4],
                            f32 of32zI) const;
    virtual void renderVertArray(u32 u32Flg, void* pvVertArray, u32 u32VertNum, f32 f32Pri);
    virtual void End() const;
    virtual void renderPoint(f32 of32xI, f32 of32yI, u32 ou32ColI, f32 of32zI) const;
    virtual void renderArrayPoint(const clsOODraw2d::stcPrim2d_PC* opsPrim2d_PCI,
                                  u32 ou32NumI,
                                  f32 of32zI) const;
};

#endif // PS2NNDRAW2D_HPP
