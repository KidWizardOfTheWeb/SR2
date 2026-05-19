#ifndef PATHCOURSEST15_HPP
#define PATHCOURSEST15_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Path/PathCourse.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/LapSt15.hpp"

// total size: 0xC0
class clsPathCourseSt15 : public clsPathCourse {
public:
    virtual ~clsPathCourseSt15();

    virtual void setBinDataAttribute();
    virtual s32 checkGoalLine(clsPlayerTask* pcPlayer, f32* pf32DepthIO, s32 s32TotalLapCnt);

    NNS_VECTORFAST m_sTmpGoalLinePos; // offset 0x80, size 0x10
    NNS_VECTORFAST m_sTmpGoalLineDir; // offset 0x90, size 0x10
    NNS_VECTORFAST m_sTmpLastLineDir; // offset 0xA0, size 0x10
    f32 m_f32BackTmpGoalLineDepth;    // offset 0xB0, size 0x4
    f32 m_f32FrontTmpGoalLineDepth;   // offset 0xB4, size 0x4
};

#endif // PATHCOURSEST15_HPP
