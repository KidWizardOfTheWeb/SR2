#ifndef PATHDATA_HPP
#define PATHDATA_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

struct stcSpeedPath {
    s16 s16MaxSpeed;    // offset 0x0, size 0x2
    s16 s16MinSpeed;    // offset 0x2, size 0x2
    s16 s16Type;        // offset 0x4, size 0x2
    s16 as16Reserve[5]; // offset 0x6, size 0xA
}; // total size: 0x10

struct stcGravityPath {
    s16 s16MaxSpeed;    // offset 0x0, size 0x2
    s16 s16MinSpeed;    // offset 0x2, size 0x2
    s16 s16Flag;        // offset 0x4, size 0x2
    s16 as16Reserve[5]; // offset 0x6, size 0xA
}; // total size: 0x10

struct stcGDivePath {
    s16 s16MaxSpeed;    // offset 0x0, size 0x2
    s16 s16MinSpeed;    // offset 0x2, size 0x2
    s16 s16Flag;        // offset 0x4, size 0x2
    s16 as16Reserve[5]; // offset 0x6, size 0xA
}; // total size: 0x10

// total size: 0x20
class clsPathData : public clsSingleton<clsPathData> {
public:
    // total size: 0x30
    struct stcLine {
        NNS_CAPSULE* psCapsule;      // offset 0x0, size 0x4
        NNS_VECTORFAST* psPointVec;  // offset 0x4, size 0x4
        NNS_VECTORFAST* psNormalVec; // offset 0x8, size 0x4
        NNS_SPHERE sLimitSph;        // offset 0xC, size 0x10
        u16 u16Num;                  // offset 0x1C, size 0x2
        u16 u16Attr;                 // offset 0x1E, size 0x2
        union {
            s8 s8Data[16];
            stcSpeedPath sSpeed;
            stcGravityPath sGravity;
            stcGDivePath sGDive;
        } uniData; // offset 0x20, size 0x10
    };

    // total size: 0xC
    struct stcData {
        u8 u8BigEndian;    // offset 0x0, size 0x1
        u8 u8Ver;          // offset 0x1, size 0x1
        u8 u8Id[6];        // offset 0x2, size 0x6
        u32 u32Num;        // offset 0x8, size 0x4
        stcLine* apLine[]; // offset 0xC, size 0x0
    };

    clsPathData() {}
    virtual ~clsPathData() {}

    stcData* getDataPtr(u8 u8Param1) const { return m_apsData[u8Param1]; }
    stcLine* getLinePtr(u8 u8Param1, u8 u8Param2) const
    {
        return m_apsData[u8Param1]->apLine[u8Param2];
    }

    void PathDebugDraw(const stcLine* opsPathLine,
                       u8 u8BFlag,
                       u8 u8LFlag,
                       u8 u8CFlag,
                       u8 u8NFlag,
                       u32 u32LineColor);
    void setBinData(u8 u8Type, void* pvData);

    stcData* m_apsData[7]; // offset 0x4, size 0x1C
};

#endif // PATHDATA_HPP
