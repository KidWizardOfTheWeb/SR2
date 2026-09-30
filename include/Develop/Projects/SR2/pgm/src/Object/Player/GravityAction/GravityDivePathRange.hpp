#ifndef GRAVITYDIVEPATHRANGE_HPP
#define GRAVITYDIVEPATHRANGE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"

class clsPlayerTask;
class clsPathPoint;

// total size: 0xD0
class clsGravityDivePathRange {
public:
    typedef const f32 (*MtxPtr)[4];

    enum enmFlag {
        FLAG_CLEAR = 0,
        FLAG_CONST_RUN = 1,
        FLAG_NOT_CANCEL = 2,
    };

    enum enmPathType {
        PATH_TYPE_DIVE = 0,
        PATH_TYPE_GRAVITY = 1,
        PATH_TYPE_COURSE = 2,
    };

    NNS_MATRIX m_sBaseMtx;              // offset 0x0, size 0x40
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

    clsGravityDivePathRange()
        : m_f32SlerpFrame(0.0f), m_u32DirFlag(0), m_eFlag(FLAG_CLEAR), m_ePathType(PATH_TYPE_COURSE)
    {
    }
    enmPathType getPathType() const { return m_ePathType; }
    enmFlag getFlag() const { return m_eFlag; }
    f32 getNextRangeRate() const { return m_af32RangeRate[1]; }
    MtxPtr getMtxPtr() const { return m_sBaseMtx; }
    const NNS_VECTORFAST* getDirVecFastPtr() const { return &m_sPathDirVecFast; }
    f32 getRangeRate() const { return m_af32RangeRate[0]; }
    f32 getSlerpFrame() const { return m_f32SlerpFrame; }
    const NNS_VECTORFAST* getUpVecFastPtr() const { return &m_sPathUpVecFast; }
    void setFlag(u32 param_1) { m_eFlag = static_cast<enmFlag>(param_1); }

    void calcRangeDirVec(clsPlayerTask* p1, NNS_VECTORFAST* p2);
    void calcCrossInfo(s32 p1, NNS_VECTORFAST* p2);
    u32 getDiveRangeAttrCoursePath(clsPlayerTask* p1, clsPathPoint* p2);
    void set(clsPlayerTask* p1);
    void set(clsPlayerTask* p1, clsGravityDivePathRange::enmPathType p2, clsPathPoint* p3);
    void set(clsPlayerTask* p1, clsGravityDivePathRange::enmPathType p2, clsPath* p3);
};

#endif // GRAVITYDIVEPATHRANGE_HPP
