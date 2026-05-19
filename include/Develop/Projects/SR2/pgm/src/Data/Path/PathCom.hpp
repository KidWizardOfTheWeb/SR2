#ifndef PATHCOM_HPP
#define PATHCOM_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Path/PathPoint.hpp"

// total size: 0x6
class _ComUserData {
public:
    u16 u16GearChange; // offset 0x0, size 0x2
    u16 u16ComAttr;    // offset 0x2, size 0x2
    u8 u8MVProb;       // offset 0x4, size 0x1
    u8 u8ShortCutAttr; // offset 0x5, size 0x1
};

// total size: 0x14
class clsPathCom : public clsPathPoint {
public:
    virtual ~clsPathCom() {}

    NNS_VECTORFAST* searchTrickGCtrlConnectPoint(const _LineData* psStartLine, u32 u32Ability);
    NNS_VECTORFAST* searchGCtrlEndPoint(const _LineData* psStartLine);
    u8 searchCourseAIPath(clsRetPath* pcRetIO,
                          const NNS_VECTORFAST* psPosition,
                          u32 u32DisableRoots,
                          bool bNextSearchFlag);
    void serarchNextAILine(clsRetPath* pcRetIO, s32 s32PointNo);
};

#endif // PATHCOM_HPP
