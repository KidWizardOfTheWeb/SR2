#ifndef BACKRIBBON_HPP
#define BACKRIBBON_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

class clsPlayerTask;

namespace nspBackRibbon {
extern _NNS_TEXLIST* psTexList_BackRibbon;
}

// total size: 0x7F0
class clsBackRibbonEffect_Task : public clsTask {
public:
    clsBackRibbonEffect_Task(u8 u8PlayerNo, u32 u32PointNum); // [verify params from ASM]
    virtual ~clsBackRibbonEffect_Task() {}

    virtual void execute();
    virtual void draw();

    void settingMarks();
    void init();

    NNS_PRIM3D_PCT m_asPrim3D_PCT[80]; // offset 0x54, size 0x780
    u32 m_u32LocalSaveNo;              // offset 0x7D4, size 0x4
    u32 m_u32MarkTimingCount;          // offset 0x7D8, size 0x4
    u32 m_u32ViewNo;                   // offset 0x7DC, size 0x4
    u8 m_u8PlayerNo;                   // offset 0x7E0, size 0x1
    u8 m_u8TexType;                    // offset 0x7E1, size 0x1
    clsPlayerTask* m_pcPlayer;         // offset 0x7E4, size 0x4
    u32 m_u32PointNum;                 // offset 0x7E8, size 0x4
    f32 m_f32Anim;                     // offset 0x7EC, size 0x4
};

#endif // BACKRIBBON_HPP
