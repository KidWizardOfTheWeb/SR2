#ifndef ST07MAPPARTSGIMMICKWALLOBJECT_HPP
#define ST07MAPPARTSGIMMICKWALLOBJECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"

// total size: 0x120
class clsMapPartsGimmickWall_Object : public clsMapPartsObject {
public:
    // Note: name collision with global enmMode — this variant has MODE_STOP/MODE_MOVE vs
    // MODE_EXECUTE/MODE_BREAK
    enum enmMode {
        MODE_INIT = 0,
        MODE_STOP = 1,
        MODE_MOVE = 2,
    };

    virtual ~clsMapPartsGimmickWall_Object() {}
    virtual void reset();
    virtual void init();
    virtual void execute();

    f32 m_f32MatMotionFrame;    // offset 0xE0, size 0x4
    f32 m_f32MotionFrame;       // offset 0xE4, size 0x4
    f32 m_f32MatMotionEndFrame; // offset 0xE8, size 0x4
    f32 m_f32MotionEndFrame;    // offset 0xEC, size 0x4
    f32 m_f32Num;               // offset 0xF0, size 0x4
    f32 m_f32Lap;               // offset 0xF4, size 0x4
    f32 m_f32Rank;              // offset 0xF8, size 0x4
    enum enmMode m_eMode;       // offset 0xFC, size 0x4
    u8 m_bFlag;                 // offset 0x100, size 0x1
    hkVector4 m_cVec;           // offset 0x110, size 0x10
};

#endif // ST07MAPPARTSGIMMICKWALLOBJECT_HPP
