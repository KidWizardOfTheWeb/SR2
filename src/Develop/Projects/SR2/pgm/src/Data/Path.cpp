#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"

void clsPath::initPath_Object(const clsPathData::stcData* opsPath, u32 u32PathNo, u32 u32DirFlag)
{
}

void clsPath::setPath(const clsPathData::stcData* opsPath, s32 s32PathNo, s32 s32PointNo)
{
}

void clsPath::search(const clsPathData::stcData* opsPath,
                     const NNS_VECTORFAST* opsPosVecFast,
                     const NNS_VECTORFAST* opsDirVecFast,
                     f32 f32Radius,
                     u32 u32DirFlag)
{
}

void clsPath::search2(const clsPathData::stcData* opsPath,
                      const NNS_VECTORFAST* opsPosVecFast,
                      const NNS_VECTORFAST* opsDirVecFast,
                      f32 f32Radius,
                      u32 u32DirFlag)
{
}

void clsPath::searchN(const clsPathData::stcData* opsPath,
                      const NNS_VECTORFAST* opsPosVecFast,
                      const NNS_VECTORFAST* opsDirVecFast,
                      f32 f32Radius,
                      u32 u32DirFlag,
                      const u8* pu8LineNumArray,
                      u32 u32ArrayNum,
                      bool bBSCheck)
{
}

void clsPath::searchLine(const clsPathData::stcData* opsPath,
                         const NNS_VECTORFAST* opsPosVecFast,
                         const NNS_VECTORFAST* opsDirVecFast,
                         u32 u32DirFlag,
                         s32 s32LineNo)
{
}

void clsPath::searchAutoWallRun(const NNS_VECTORFAST* opsPosVecFast, s32 s32LineNo)
{
}

void clsPath::searchTrick(const clsPathData::stcData* opsPath,
                          s32 os32PathNo,
                          const NNS_VECTORFAST* opsPosVecFast,
                          const NNS_VECTORFAST* opsDirVecFast,
                          f32 f32Radius,
                          u32 u32DirFlag)
{
}

void clsPath::searchOtherLine(const clsPathData::stcData* opsPath,
                              const NNS_VECTORFAST* opsPosVecFast,
                              const NNS_VECTORFAST* opsDirVecFast,
                              f32 f32Radius,
                              u32 u32DirFlag)
{
}

void clsPath::searchPosOnLine(const NNS_VECTORFAST* opsPosVecFast,
                              const NNS_VECTORFAST* opsDirVecFast,
                              f32 f32Radius)
{
}

void clsPath::_GetPosition_Player(const NNS_VECTORFAST* opsPosVecFast, f32 f32Speed)
{
}

void clsPath::_GetPosition_Object(f32 f32Speed)
{
}

void clsPath::GetPosition_Trick(const NNS_VECTORFAST* opsPosVecFast,
                                const NNS_VECTORFAST* opsUpVec,
                                f32 f32Length)
{
}

void clsPath::getPosition_BSpline(f32 of32Speed)
{
}

void clsPath::update_PathData(const NNS_VECTORFAST* opsPosVecFast,
                              const NNS_VECTORFAST* opsDirVecFast)
{
}

void clsPath::calcDistanceLR(const NNS_VECTORFAST* opsPosVecFast)
{
}

void clsPath::calcRankPath(const clsPathData::stcData* opsPath,
                           s32 os32PathNo,
                           const NNS_VECTORFAST* opsPosVecFast,
                           const NNS_VECTORFAST* opsDirVecFast)
{
}

u8 clsPath::searchPoint(const clsPathData::stcLine* opcLine,
                        const NNS_VECTORFAST* opsPosVecFast,
                        u32 u32DirFlag)
{
    return 0;
}

f32 clsPath::getDistanceLR(const NNS_VECTORFAST* opsPosVecFast)
{
    return 0.0f;
}

void clsPath::getPathPointToRate(f32 of32LengthRate, NNS_VECTORFAST* psVecFast)
{
}

void clsPath::calcPathTrsMatrix(f32 (*psDstMtx)[4][4], const NNS_VECTORFAST* opsPosVecFast)
{
}
