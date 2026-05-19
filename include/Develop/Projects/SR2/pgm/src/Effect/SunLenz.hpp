#ifndef SUNLENZ_HPP
#define SUNLENZ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

struct _NNS_TEXLIST;

// total size: 0x110
class clsSunLenz_Task : public clsTask {
public:
    // Note: DWARF flattens several incompatible stcDetail layouts; SunLenz uses the 0x20 variant.
    struct stcDetail {
        NNS_VECTORFAST m_sClipPosFast; // offset 0x0, size 0x10
        stcPoint2D_s16 m_sPos2D_s16;   // offset 0x10, size 0x4
        u16 m_u16TexSize;              // offset 0x14, size 0x2
        u8 m_u8TexAlpha;               // offset 0x16, size 0x1
        u8 m_bDraw;                    // offset 0x17, size 0x1
        u8 m_u8RandTimer;              // offset 0x18, size 0x1
        u8 m_u8RandCnt;                // offset 0x19, size 0x1
    };

    clsSunLenz_Task(const stcSetDataDetail& rsSetDataDetail) : clsTask(0, 0) {}
    virtual ~clsSunLenz_Task() {}

    virtual void execute();
    virtual void draw();

    void setTexture(u8 u8type);

    stcDetail m_asDetail[4];       // offset 0x60, size 0x80
    NNS_VECTORFAST m_sSunPosFast;  // offset 0xE0, size 0x10
    s32 m_s32SunSize;              // offset 0xF0, size 0x4
    u32 m_u32ViewportNum;          // offset 0xF4, size 0x4
    s16 m_s16FbHalfW;              // offset 0xF8, size 0x2
    s16 m_s16FbHalfH;              // offset 0xFA, size 0x2
    s16 m_s16FbQuartW;             // offset 0xFC, size 0x2
    s16 m_s16FbQuartH;             // offset 0xFE, size 0x2
    s8 m_s8ShiftX;                 // offset 0x100, size 0x1
    s8 m_s8ShiftY;                 // offset 0x101, size 0x1
    _NNS_TEXLIST* m_psTextureList; // offset 0x104, size 0x4
};

#endif // SUNLENZ_HPP
