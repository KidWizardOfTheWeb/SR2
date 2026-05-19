#ifndef SCRIPT2D_HPP
#define SCRIPT2D_HPP

#include "Develop/Projects/SR2/pgm/src/Script/Script.hpp"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

// total size: 0x90
class clsScript2D_Task : public clsTask {
public:
    clsScript2D_Task(u32 u32Param1,
                     u32 u32Param2,
                     f32 f32Param3,
                     f32 f32Param4,
                     f32 f32Param5,
                     f32 f32Param6,
                     u32 u32Param7,
                     u32 u32Param8,
                     u32 u32Param9,
                     s32 s32Param10,
                     s32 s32Param11,
                     f32 f32Param12,
                     f32 f32Param13);
    virtual ~clsScript2D_Task() {}
    virtual void execute();
    virtual void draw();

    void codeShow2D(u8* pu8Ptr, clsScript_Task* pcTask);
    void releaseData();
    void initData();

    u32 m_u32Flg;        // offset 0x54, size 0x4
    s32 m_s322DFrame;    // offset 0x58, size 0x4
    u32 m_u32TexNum;     // offset 0x5C, size 0x4
    s32 m_s32AriveFrame; // offset 0x60, size 0x4
    f32 m_f32x;          // offset 0x64, size 0x4
    f32 m_f32y;          // offset 0x68, size 0x4
    f32 m_f32w;          // offset 0x6C, size 0x4
    f32 m_f32h;          // offset 0x70, size 0x4
    u32 m_u32ColMask;    // offset 0x74, size 0x4
    u32 m_u32StartCol;   // offset 0x78, size 0x4
    u32 m_u32EndCol;     // offset 0x7C, size 0x4
    s32 m_s32ColFrame;   // offset 0x80, size 0x4
    s32 m_s32ScrFrame;   // offset 0x84, size 0x4
    f32 m_f32x2;         // offset 0x88, size 0x4
    f32 m_f32y2;         // offset 0x8C, size 0x4

    static _NNS_TEXLIST* m_tpsTexList;
    static clsScript2D_Task* m_tapc2DTask[16];
};

#endif // SCRIPT2D_HPP
