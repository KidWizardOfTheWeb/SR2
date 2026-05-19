#ifndef PATHCOURSE_HPP
#define PATHCOURSE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Path/PathPoint.hpp"

class clsPlayerTask;

// total size: 0x80
class clsPathCourse : public clsPathPoint {
public:
    virtual ~clsPathCourse() {}
    virtual void setBinDataAttribute();
    virtual s32 checkGoalLine(clsPlayerTask* pcPlayer, f32* pf32DepthIO, s32 s32Flags);

    u32 calcPlannedGoalTime(clsPlayerTask* pcPlayer, f32 f32Param);
    u8 isStartLineOver(clsPlayerTask* pcPlayer);
    f32 calcRankingPointDepth(clsPlayerTask* pcPlayer);
    s32 serarchActiveNextLine(clsRetPath* pcRetIO);
    void calcOnLinePlayerPos(clsPlayerTask* pcPlayer, NNS_VECTORFAST& rsDstPos);
    const u32* getUserData(
        const _LineData* psLineI) const; // [ASM-derived guess — verify return type]

    NNS_VECTORFAST m_sGoalLinePos;  // offset 0x20, size 0x10
    NNS_VECTORFAST m_sGoalLineDir;  // offset 0x30, size 0x10
    NNS_VECTORFAST m_sLastLineDir;  // offset 0x40, size 0x10
    NNS_VECTORFAST m_sStartLinePos; // offset 0x50, size 0x10
    NNS_VECTORFAST m_sStartLineDir; // offset 0x60, size 0x10
    NNS_VECTORFAST m_sFirstLineDir; // offset 0x70, size 0x10
};

#endif // PATHCOURSE_HPP
