#ifndef PATH_HPP
#define PATH_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/PathData.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x60
class clsPath {
public:
    clsPath() {}
    clsPath(const clsPath& rParam1) {}
    ~clsPath() {}

    void calcPathTrsMatrix(f32 (*psDstMtx)[4][4], const NNS_VECTORFAST* opsPosVecFast);
    void getPathPointToRate(f32 of32LengthRate, NNS_VECTORFAST* psVecFast);
    f32 getDistanceLR(const NNS_VECTORFAST* opsPosVecFast);
    u8 searchPoint(const clsPathData::stcLine* opcLine,
                   const NNS_VECTORFAST* opsPosVecFast,
                   u32 u32DirFlag);
    void calcRankPath(const clsPathData::stcData* opsPath,
                      s32 os32PathNo,
                      const NNS_VECTORFAST* opsPosVecFast,
                      const NNS_VECTORFAST* opsDirVecFast);
    void calcDistanceLR(const NNS_VECTORFAST* opsPosVecFast);
    void update_PathData(const NNS_VECTORFAST* opsPosVecFast, const NNS_VECTORFAST* opsDirVecFast);
    void getPosition_BSpline(f32 of32Speed);
    void GetPosition_Trick(const NNS_VECTORFAST* opsPosVecFast,
                           const NNS_VECTORFAST* opsUpVec,
                           f32 f32Length);
    void _GetPosition_Object(f32 f32Speed);
    void _GetPosition_Player(const NNS_VECTORFAST* opsPosVecFast, f32 f32Speed);
    void searchPosOnLine(const NNS_VECTORFAST* opsPosVecFast,
                         const NNS_VECTORFAST* opsDirVecFast,
                         f32 f32Radius);
    void searchOtherLine(const clsPathData::stcData* opsPath,
                         const NNS_VECTORFAST* opsPosVecFast,
                         const NNS_VECTORFAST* opsDirVecFast,
                         f32 f32Radius,
                         u32 u32DirFlag);
    void searchTrick(const clsPathData::stcData* opsPath,
                     s32 os32PathNo,
                     const NNS_VECTORFAST* opsPosVecFast,
                     const NNS_VECTORFAST* opsDirVecFast,
                     f32 f32Radius,
                     u32 u32DirFlag);
    void searchAutoWallRun(const NNS_VECTORFAST* opsPosVecFast, s32 s32LineNo);
    void searchLine(const clsPathData::stcData* opsPath,
                    const NNS_VECTORFAST* opsPosVecFast,
                    const NNS_VECTORFAST* opsDirVecFast,
                    u32 u32DirFlag,
                    s32 s32LineNo);
    void searchN(const clsPathData::stcData* opsPath,
                 const NNS_VECTORFAST* opsPosVecFast,
                 const NNS_VECTORFAST* opsDirVecFast,
                 f32 f32Radius,
                 u32 u32DirFlag,
                 const u8* pu8LineNumArray,
                 u32 u32ArrayNum,
                 bool bBSCheck);
    void search2(const clsPathData::stcData* opsPath,
                 const NNS_VECTORFAST* opsPosVecFast,
                 const NNS_VECTORFAST* opsDirVecFast,
                 f32 f32Radius,
                 u32 u32DirFlag);
    void search(const clsPathData::stcData* opsPath,
                const NNS_VECTORFAST* opsPosVecFast,
                const NNS_VECTORFAST* opsDirVecFast,
                f32 f32Radius,
                u32 u32DirFlag);
    void setPath(const clsPathData::stcData* opsPath, s32 s32PathNo, s32 s32PointNo);
    void initPath_Object(const clsPathData::stcData* opsPath, u32 u32PathNo, u32 u32DirFlag);

    clsPathData::stcLine* getLine() const { return m_psLine; }
    s16 getPathNo() const { return m_s16PathNo; }
    NNS_VECTORFAST* getUpVecFastRef() const { return const_cast<NNS_VECTORFAST*>(&m_sUpVecFast); }
    NNS_VECTORFAST* getMoveVecFastRef() const
    {
        return const_cast<NNS_VECTORFAST*>(&m_sMoveVecFast);
    }
    NNS_VECTORFAST* getDirVecFastRef() const { return const_cast<NNS_VECTORFAST*>(&m_sDirVecFast); }
    u16 getHitBit() const { return m_u16HitBit; }
    u16 getSearchHitBit() const { return m_u16SearchHitBit; }
    void reset() {}
    NNS_VECTORFAST* getCrossVecFastRef() const
    {
        return const_cast<NNS_VECTORFAST*>(&m_sCrossVecFast);
    }
    f32 getLengthRate() const { return m_f32LengthRate; }
    f32 getLength() const { return m_f32Length; }

    NNS_VECTORFAST m_sUpVecFast;    // offset 0x0, size 0x10
    NNS_VECTORFAST m_sDirVecFast;   // offset 0x10, size 0x10
    NNS_VECTORFAST m_sCrossVecFast; // offset 0x20, size 0x10
    NNS_VECTORFAST m_sMoveVecFast;  // offset 0x30, size 0x10
    clsPathData::stcLine* m_psLine; // offset 0x40, size 0x4
    f32 m_f32LengthRate;            // offset 0x44, size 0x4
    f32 m_f32Length;                // offset 0x48, size 0x4
    f32 m_f32DistanceLR;            // offset 0x4C, size 0x4
    u16 m_u16HitBit;                // offset 0x50, size 0x2
    u16 m_u16PointNo;               // offset 0x52, size 0x2
    s16 m_s16PathNo;                // offset 0x54, size 0x2
    u16 m_u16SearchHitBit;          // offset 0x56, size 0x2
};

#endif // PATH_HPP
