#ifndef PATHRANGEEDITOR_HPP
#define PATHRANGEEDITOR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x7C
class clsPathRangeEditor_Debug_Task : public clsTask {
public:
    // Note: enmPathType nested per DWARF — values differ from GravityDivePathRange.hpp
    // (PATH_TYPE_DIVE variant) Values from DWARF for clsPathRangeEditor_Debug_Task
    enum enmPathType {
        COURSE = 0,
        GRAVITY = 1,
        GDIVE = 2,
    };

    clsPathRangeEditor_Debug_Task(enmPathType ePathTypeI, u32 u32Tp, s32 s32Flg);
    virtual ~clsPathRangeEditor_Debug_Task();
    virtual void execute();
    virtual void draw();

    void drawDetail();

    enum enmPathType m_ePathType; // offset 0x54, size 0x4
    s32 m_s32Cursor;              // offset 0x58, size 0x4
    s32 m_s32CursorDetail;        // offset 0x5C, size 0x4
    s32 m_s32Num;                 // offset 0x60, size 0x4
    u32 m_bZComp;                 // offset 0x64, size 0x4
    u32 m_bDrawLinearSphere;      // offset 0x68, size 0x4
    f32* m_apf32Range[2];         // offset 0x6C, size 0x8
    u8* m_apu8RangeAttr[2];       // offset 0x74, size 0x8
};

#endif // PATHRANGEEDITOR_HPP
