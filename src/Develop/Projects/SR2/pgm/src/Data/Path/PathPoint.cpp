#include "Develop/Projects/SR2/pgm/src/Data/Path/PathPoint.hpp"

f32 COURSE_SEARCH_POINT_POS_RADIUS;

f32 clsPathPoint::COURSEPATH_PLAYER_SIZE = 1.0f;

void clsPathPoint::searchPoint(clsRetPath* pcRetIO,
                               const NNS_VECTORFAST* psPosition,
                               const NNS_VECTORFAST* psDirNrmVecFast,
                               u32 u32DisableType) const
{
}

void clsPathPoint::searchNextLine(clsRetPath* pcRetIO, s32 s32PointNo) const
{
}

void clsPathPoint::searchNextLineBack(clsRetPath* pcRetIO, s32 s32PointNo) const
{
}

f32 clsPathPoint::calcDistFromStart(u16 u16ActiveLineNo, const NNS_VECTORFAST* psPos) const
{
    return 0.0f;
}

void clsPathPoint::getCrossPoint(NNS_VECTORFAST* psDstPos,
                                 const NNS_VECTORFAST* psPos,
                                 s32 s32LineNo)
{
}

void clsPathPoint::AllocAndCalculateCapsule()
{
}

void clsPathPoint::FreeCalculateCapsule()
{
}

void clsPathPoint::DrawLine_Debug(bool bIsDrawSphere, s32 s32NonDrawLineNoI)
{
}

void clsPathPoint::loadBinaryData(u8* pu8DataI, clsBaseStage_Task* pcStageI, s32 s32FlagI)
{
}

const _LineData* clsPathPoint::getLineData(u16 u16LineNoI) const
{
    return 0;
}

const NNS_VECTORFAST* clsPathPoint::getPoint(u32 u32PointNoI) const
{
    return 0;
}
