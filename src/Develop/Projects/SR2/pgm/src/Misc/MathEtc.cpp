#include "Develop/Projects/SR2/pgm/src/Misc/MathEtc.hpp"

u32 nspMathEtc::tu32MaxC;
u16 nspMathEtc::tu16KParam;
f32 nspMathEtc::tf32MaxPos;

void nspMathEtc::getQuat2NrmVecFast(NNS_QUATERNION* psParam1,
                                    const NNS_VECTORFAST* psParam2,
                                    const NNS_VECTORFAST* psParam3)
{
}

void nspMathEtc::getQuat2VecFast(NNS_QUATERNION* psParam1,
                                 const NNS_VECTORFAST* psParam2,
                                 const NNS_VECTORFAST* psParam3)
{
}

void nspMathEtc::getClosestPointOnLine(NNS_VECTORFAST* psParam1,
                                       const NNS_VECTORFAST* psParam2,
                                       const NNS_VECTORFAST* psParam3,
                                       const NNS_VECTORFAST* psParam4)
{
}

bool nspMathEtc::getClosestPointOnLine_RetFlag(NNS_VECTORFAST* psParam1,
                                               const NNS_VECTORFAST* psParam2,
                                               const NNS_VECTORFAST* psParam3,
                                               const NNS_VECTORFAST* psParam4)
{
    return false;
}

f32 nspMathEtc::BSplineBlend_NLoop(u32 u32Param1, u16 u16Param2, f32 f32Param3)
{
    return 0.0f;
}

f32 nspMathEtc::BSplineBlend_Loop(u32 u32Param1, u16 u16Param2, f32 f32Param3)
{
    return 0.0f;
}

void nspMathEtc::interpolateBSprineVNF(NNS_VECTORFAST* psParam1,
                                       NNS_VECTORFAST* psParam2,
                                       NNS_VECTORFAST* psParam3,
                                       NNS_VECTORFAST* psParam4,
                                       u32 u32Param5,
                                       f32 f32Param6,
                                       u16 u16Param7)
{
}

f32 nspMathEtc::getRad2VecFast(const NNS_VECTORFAST* psParam1, const NNS_VECTORFAST* psParam2)
{
    return 0.0f;
}

f32 nspMathEtc::getRad2NrmVec(const NNS_VECTOR* psParam1, const NNS_VECTOR* psParam2)
{
    return 0.0f;
}

void nspMathEtc::setupMatrixAxisVectorFast(f32 (*pasParam1)[4][4],
                                           const NNS_VECTORFAST* psParam2,
                                           const NNS_VECTORFAST* psParam3,
                                           const NNS_VECTORFAST* psParam4,
                                           const NNS_VECTORFAST* psParam5)
{
}

void nspMathEtc::multiplyQuatVecFast(NNS_VECTORFAST* psParam1,
                                     const NNS_QUATERNION* psParam2,
                                     const NNS_VECTORFAST* psParam3)
{
}
