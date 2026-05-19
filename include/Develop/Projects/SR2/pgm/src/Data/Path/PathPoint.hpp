#ifndef PATHPOINT_HPP
#define PATHPOINT_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsBaseStage_Task;
struct _BinData;

// total size: 0x4
struct _stcEndPosList {
    u16 u16EndPointNo; // offset 0x0, size 0x2
    u16 u16LineNo;     // offset 0x2, size 0x2
};

// total size: 0x8
class clsPathBase {
public:
    clsPathBase() {}
    virtual ~clsPathBase() {}

    clsBaseStage_Task* m_pcOwnerStage; // offset 0x4, size 0x4
};

// total size: 0x14
class clsPathPoint : public clsPathBase {
public:
    // total size: 0x40
    struct _LineData {
        u16 u16StartPointNo;  // offset 0x0, size 0x2
        u16 u16EndPointNo;    // offset 0x2, size 0x2
        u16 u16TypeAttr;      // offset 0x4, size 0x2
        u16 u16LineAttr;      // offset 0x6, size 0x2
        f32 f32Radius;        // offset 0x8, size 0x4
        f32 f32Length;        // offset 0xC, size 0x4
        f32 f32SLength;       // offset 0x10, size 0x4
        u32 u32GravityPathNo; // offset 0x14, size 0x4
        u32 u32Reserved[2];   // offset 0x18, size 0x8
        u32 au32UserData[8];  // offset 0x20, size 0x20
    };

    // total size: 0x20
    class clsRetPath {
    public:
        u16 m_u16LineNo[8];    // offset 0x0, size 0x10
        u16 m_u16LineNum;      // offset 0x10, size 0x2
        u16 m_u16ActiveLineNo; // offset 0x12, size 0x2
        u16 m_u16OldLineNo;    // offset 0x14, size 0x2
        f32 m_f32DotPro;       // offset 0x18, size 0x4
        f32 m_f32DotPro_Deg;   // offset 0x1C, size 0x4
    };

    virtual ~clsPathPoint() {}
    virtual void loadBinaryData(u8* pu8DataI, clsBaseStage_Task* pcStageI, s32 s32FlagI);
    virtual void setBinDataAttribute() {}

    void DrawLine_Debug(bool bIsDrawSphere, s32 s32NonDrawLineNoI);
    void FreeCalculateCapsule();
    void AllocAndCalculateCapsule();
    void getCrossPoint(NNS_VECTORFAST* psDstPos, const NNS_VECTORFAST* psPos, s32 s32LineNo);
    f32 calcDistFromStart(u16 u16ActiveLineNo, const NNS_VECTORFAST* psPos) const;
    void searchNextLineBack(clsRetPath* pcRetIO, s32 s32PointNo) const;
    void searchNextLine(clsRetPath* pcRetIO, s32 s32PointNo) const;
    void searchPoint(clsRetPath* pcRetIO,
                     const NNS_VECTORFAST* psPosition,
                     const NNS_VECTORFAST* psDirNrmVecFast,
                     u32 u32DisableType) const;

    const _LineData* getLineData(u16 u16LineNoI) const; // [ASM-derived guess — verify return type]
    const NNS_VECTORFAST*
    getPoint(u32 u32PointNoI) const; // [ASM-derived guess — verify return type]
    _BinData* getPathData() const { return m_pPathData; } // [ASM-derived guess — verify]

    _BinData* m_pPathData;             // offset 0x8, size 0x4
    NNS_CAPSULE* m_calculated_capsule; // offset 0xC, size 0x4
    s32 m_s32FilseSize_Debug;          // offset 0x10, size 0x4

    static f32 COURSEPATH_PLAYER_SIZE;
};

typedef clsPathPoint::_LineData _LineData;
typedef clsPathPoint::clsRetPath clsRetPath;

// total size: 0x28
struct _BinData {
    c8 c8Type[4];             // offset 0x0, size 0x4
    s32 s32Ver;               // offset 0x4, size 0x4
    NNS_VECTORFAST* psVector; // offset 0x8, size 0x4
    _LineData* psLine;        // offset 0xC, size 0x4
    _stcEndPosList* psEPList; // offset 0x10, size 0x4
    f32 f32MaxLineDepth;      // offset 0x14, size 0x4
    f32 f32MainLength;        // offset 0x18, size 0x4
    s32 s32PointNum;          // offset 0x1C, size 0x4
    s32 s32LineNum;           // offset 0x20, size 0x4
    u8 u8LineType;            // offset 0x24, size 0x1
    u8 u8PathType;            // offset 0x25, size 0x1
    u8 u8Padding[2];          // offset 0x26, size 0x2
};

#endif // PATHPOINT_HPP
