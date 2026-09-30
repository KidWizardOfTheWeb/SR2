#ifndef SUNLENZ_HPP
#define SUNLENZ_HPP

#include "types.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnGraphics.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

struct _NNS_TEXLIST;

// total size: 0x110
class clsSunLenz_Task : public clsTask {
public:
    // RECONSTRUCTED: nested detail type.
    struct stcDetail {
        NNS_VECTORFAST m_sClipPosFast; // offset 0x0, size 0x10
        stcPoint2D_s16 m_sPos2D_s16;   // offset 0x10, size 0x4
        u16 m_u16TexSize;              // offset 0x14, size 0x2
        u8 m_u8TexAlpha;               // offset 0x16, size 0x1
        u8 m_bDraw;                    // offset 0x17, size 0x1
        u8 m_u8RandTimer;              // offset 0x18, size 0x1
        u8 m_u8RandCnt;                // offset 0x19, size 0x1
    };

    clsSunLenz_Task(const stcSetDataDetail& rsSetDataDetail) : clsTask(100001, 5)
    {
        m_u32ViewportNum = clsPfSystem::GS()->getViewportNum();
        m_s8ShiftX = 0;
        m_s8ShiftY = 0;
        m_sSunPosFast.x = rsSetDataDetail.sPosVec.x;
        m_sSunPosFast.y = rsSetDataDetail.sPosVec.y;
        m_sSunPosFast.z = rsSetDataDetail.sPosVec.z;
        m_s32SunSize = static_cast<s32>(rsSetDataDetail.sRotVec.x);
        m_sSunPosFast.w = 1.0f;
        memset(m_asDetail, 0, sizeof(m_asDetail));
        clsPfGraphics* pcGraphics = clsPfGraphics::GS();
        m_s16FbHalfW = pcGraphics->getFbWidth() >> 1;
        m_s16FbHalfH = pcGraphics->getFbHeight() >> 1;
        m_s16FbQuartW = m_s16FbHalfW >> 1;
        m_s16FbQuartH = m_s16FbHalfH >> 1;
        if (m_u32ViewportNum >= 2) {
            m_s8ShiftY = 1;
        }
        if (m_u32ViewportNum >= 3) {
            m_s8ShiftX = 1;
        }
        setTexture(0);
    }
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
