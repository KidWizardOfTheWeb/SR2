#ifndef NNDRAW3D_HPP
#define NNDRAW3D_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "types.h"

// total size: 0x4
class clsOODraw3d {
public:
    virtual ~clsOODraw3d() {}
    virtual void renderVector(u32 ou32ViewI, const NNS_VECTOR* opsVecI, u32 ou32ColI) const {}
    virtual void renderVectorAddDiff(u32 ou32ViewI, NNS_VECTOR* psVecI, u32 ou32ColI) const {}
    virtual void renderVectorSubDiff(u32 ou32ViewI, NNS_VECTOR* psVecI, u32 ou32ColI) const {}
    virtual void renderTriangle(u32 ou32ViewI,
                                const NNS_VECTOR* opsVecI,
                                u32 ou32ColI,
                                u32 oeRenderFlag) const
    {
    }
    virtual void renderPolygon(u32 ou32ViewI,
                               const NNS_VECTOR* opsVecI,
                               u32 ou32ColI,
                               u32 oeRenderFlag) const
    {
    }
    virtual void renderSphere(u32 ou32ViewI,
                              const NNS_VECTOR* opsVecI,
                              f32 of32RadI,
                              u32 ou32ColI,
                              u32 oeRenderFlag) const
    {
    }
    virtual void renderCube(u32 ou32ViewI, const f32 (*opaMtxI)[4][4], u32 ou32ColI) const {}
    virtual void renderVectorQuad(u32 u32ViewI,
                                  const NNS_VECTOR* opsVecI,
                                  u32 u32ColI,
                                  const f32 (*opsTrsMtxI)[4][4]) const
    {
    }
};

// total size: 0x8
class clsPfDraw3d : public clsSingleton<clsPfDraw3d>, public clsOODraw3d {
public:
    clsPfDraw3d() {}
    virtual ~clsPfDraw3d() {}

    virtual void renderVector(u32 ou32ViewI, const NNS_VECTOR* opsVecI, u32 ou32ColI) const;
    virtual void renderVectorAddDiff(u32 ou32ViewI, NNS_VECTOR* psVecI, u32 ou32ColI) const;
    virtual void renderVectorSubDiff(u32 ou32ViewI, NNS_VECTOR* psVecI, u32 ou32ColI) const;
    virtual void renderTriangle(u32 ou32ViewI,
                                const NNS_VECTOR* opsVecI,
                                u32 ou32ColI,
                                u32 oeRenderFlag) const;
    virtual void renderPolygon(u32 ou32ViewI,
                               const NNS_VECTOR* opsVecI,
                               u32 ou32ColI,
                               u32 oeRenderFlag) const;
    virtual void renderSphere(u32 ou32ViewI,
                              const NNS_VECTOR* opsVecI,
                              f32 of32RadI,
                              u32 ou32ColI,
                              u32 oeRenderFlag) const;
    virtual void renderCube(u32 ou32ViewI, const f32 (*opaMtxI)[4][4], u32 ou32ColI) const;
    virtual void renderVectorQuad(u32 u32ViewI,
                                  const NNS_VECTOR* opsVecI,
                                  u32 u32ColI,
                                  const f32 (*opsTrsMtxI)[4][4]) const;

    void renderVector(u32 ou32ViewI,
                      const NNS_VECTOR* opsVec0I,
                      const NNS_VECTOR* opsVec1I,
                      u32 ou32ColI) const;
    void renderArrayVector(u32 ou32ViewI,
                           const NNS_VECTOR* opsVecI,
                           u32 ou32LineNum,
                           u32 ou32ColI,
                           const f32 (*opsTrsMtxI)[4][4]) const;
    void renderVectorFast(u32, const NNS_VECTORFAST*, const NNS_VECTORFAST*, u32) const {}
};

#endif // NNDRAW3D_HPP
