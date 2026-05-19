#ifndef MATHETC_HPP
#define MATHETC_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

namespace nspMathEtc {
extern u32 tu32MaxC;
extern u16 tu16KParam;
extern f32 tf32MaxPos;

void interpolateBSprineVNF(NNS_VECTORFAST* psParam1,
                           NNS_VECTORFAST* psParam2,
                           NNS_VECTORFAST* psParam3,
                           NNS_VECTORFAST* psParam4,
                           u32 u32Param5,
                           f32 f32Param6,
                           u16 u16Param7);
f32 BSplineBlend_Loop(u32 u32Param1, u16 u16Param2, f32 f32Param3);
f32 BSplineBlend_NLoop(u32 u32Param1, u16 u16Param2, f32 f32Param3);
bool getClosestPointOnLine_RetFlag(NNS_VECTORFAST* psParam1,
                                   const NNS_VECTORFAST* psParam2,
                                   const NNS_VECTORFAST* psParam3,
                                   const NNS_VECTORFAST* psParam4);
void getClosestPointOnLine(NNS_VECTORFAST* psParam1,
                           const NNS_VECTORFAST* psParam2,
                           const NNS_VECTORFAST* psParam3,
                           const NNS_VECTORFAST* psParam4);
void getQuat2VecFast(NNS_QUATERNION* psParam1,
                     const NNS_VECTORFAST* psParam2,
                     const NNS_VECTORFAST* psParam3);
void getQuat2NrmVecFast(NNS_QUATERNION* psParam1,
                        const NNS_VECTORFAST* psParam2,
                        const NNS_VECTORFAST* psParam3);
f32 getRad2VecFast(const NNS_VECTORFAST* psParam1, const NNS_VECTORFAST* psParam2);
f32 getRad2NrmVec(const NNS_VECTOR* psParam1, const NNS_VECTOR* psParam2);
void setupMatrixAxisVectorFast(f32 (*pasParam1)[4][4],
                               const NNS_VECTORFAST* psParam2,
                               const NNS_VECTORFAST* psParam3,
                               const NNS_VECTORFAST* psParam4,
                               const NNS_VECTORFAST* psParam5);
void multiplyQuatVecFast(NNS_VECTORFAST* psParam1,
                         const NNS_QUATERNION* psParam2,
                         const NNS_VECTORFAST* psParam3);
} // namespace nspMathEtc

#endif // MATHETC_HPP
