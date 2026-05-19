#ifndef ZNONE_HPP
#define ZNONE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

struct stcBinDataDetail;

// total size: 0x8C
class clsReInitGraphics_Task : public clsTask {
public:
    virtual ~clsReInitGraphics_Task() {}

    virtual void draw();

    u8 getFogNo(u32 u32Param1) const { return m_au8FogNo[u32Param1]; }
    void setChangeFogNo(s32 s32vI, s32 s32FogNoI);
    void setFogBinData_NearFar(s32 s32vI, f32 f32NearI, f32 f32FarI);

    // Members
    u8 m_au8FogNo[4];                                // offset 0x54, size 0x4
    stcBinDataDetail* m_aopsBinDataDetail_FogNow[4]; // offset 0x58, size 0x10
    stcBinDataDetail* m_aopsBinDataDetail_FogDst[4]; // offset 0x68, size 0x10
    f32 m_af32ChangeFogTime[4];                      // offset 0x78, size 0x10
    u32 bDisableChangeFog;                           // offset 0x88, size 0x4
};

class clsZNone_Task : public clsTask {
public:
    virtual ~clsZNone_Task();
    virtual void draw();
};

#endif // ZNONE_HPP
