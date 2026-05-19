#ifndef GRAVITYDIVEPATHRANGE_HPP
#define GRAVITYDIVEPATHRANGE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

class clsPlayerTask;
class clsPathPoint;

// total size: 0xD0
class clsGravityDivePathRange {
public:
    typedef const f32 (*MtxPtr)[4];

    // Note: enmFlag — name collision with Player.hpp enmFlag (different values)
    enum enmFlag {
        FLAG_NULL = 0,
        FLAG_DRAW_COL = 1,
        FLAG_DRAW_MOV_LINE = 2,
        FLAG_DRAW_PST_LINE = 4,
        FLAG_DRAW_VLC_LINE = 8,
        FLAG_DRAW_GRAVITY = 16,
        FLAG_DRAW_GRID = 32,
        FLAG_INFINI_AGP = 64,
        FLAG_FREE_GEARCHANGE = 128,
        FLAG_CHANGE_COM = 256,
        FLAG_STOP = 512,
        FLAG_UPDATE_TIMER = 268435456,
        FLAG_DEFAULT = 0,
    };

    enum enmPathType {
        PATH_TYPE_DIVE = 0,
        PATH_TYPE_GRAVITY = 1,
        PATH_TYPE_COURSE = 2,
    };

    f32 m_sBaseMtx[4][4];               // offset 0x0, size 0x40
    NNS_VECTORFAST m_asPointVecFast[2]; // offset 0x40, size 0x20
    NNS_VECTORFAST m_asCrossVecFast[2]; // offset 0x60, size 0x20
    NNS_VECTORFAST m_sPathDirVecFast;   // offset 0x80, size 0x10
    NNS_VECTORFAST m_sPathUpVecFast;    // offset 0x90, size 0x10
    f32 m_af32Range[2];                 // offset 0xA0, size 0x8
    f32 m_af32CrossRange[2];            // offset 0xA8, size 0x8
    f32 m_af32LengthRate[2];            // offset 0xB0, size 0x8
    f32 m_af32RangeRate[2];             // offset 0xB8, size 0x8
    f32 m_f32SlerpFrame;                // offset 0xC0, size 0x4
    u32 m_u32DirFlag;                   // offset 0xC4, size 0x4
    enmFlag m_eFlag;                    // offset 0xC8, size 0x4
    enmPathType m_ePathType;            // offset 0xCC, size 0x4

    clsGravityDivePathRange() {}
    enmPathType getPathType() const { return m_ePathType; }
    enmFlag getFlag() const { return m_eFlag; }
    f32 getNextRangeRate() const { return m_af32RangeRate[1]; }
    MtxPtr getMtxPtr() const { return m_sBaseMtx; }
    const NNS_VECTORFAST* getDirVecFastPtr() const { return &m_sPathDirVecFast; }
    f32 getRangeRate() const { return m_af32RangeRate[0]; }
    f32 getSlerpFrame() const { return m_f32SlerpFrame; }
    const NNS_VECTORFAST* getUpVecFastPtr() const { return &m_sPathUpVecFast; }
    void setFlag(u32 param_1) { m_eFlag = (enmFlag)param_1; }

    void calcRangeDirVec(clsPlayerTask* p1, NNS_VECTORFAST* p2);
    void calcCrossInfo(s32 p1, NNS_VECTORFAST* p2);
    u32 getDiveRangeAttrCoursePath(clsPlayerTask* p1, clsPathPoint* p2);
    void set(clsPlayerTask* p1);
    void set(clsPlayerTask* p1, clsGravityDivePathRange::enmPathType p2, clsPathPoint* p3);
    void set(clsPlayerTask* p1, clsGravityDivePathRange::enmPathType p2, clsPath* p3);
};

#endif // GRAVITYDIVEPATHRANGE_HPP
