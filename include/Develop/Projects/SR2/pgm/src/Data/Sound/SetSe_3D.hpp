#ifndef SETSE_3D_HPP
#define SETSE_3D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFontSystem.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnFontSystem.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PlayAroundSe.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x2C
class clsPfSplitTexture : public clsOOSplitTexture, private clsPfTextureBase {
public:
    clsPfSplitTexture(void* pvTex, bool bSetUp, void* pvTexUVListFile)
        : clsOOSplitTexture(), clsPfTextureBase(pvTex, bSetUp)
    {
        SetTexUVListFile(pvTexUVListFile);
    }
    virtual ~clsPfSplitTexture() {}
    virtual void SetTexture(void* pvTex, bool bSetUp) { SetTexture_Base(pvTex, bSetUp); }
    virtual void SetDrawTexture(s32 s32Param1) {}
    virtual void* GetSize(s32 s32Param1) const { return GetSize_Base(s32Param1); }
};

// total size: 0xA0
class clsSetSe_3D_Task : public clsTask {
public:
    ~clsSetSe_3D_Task();

    clsSetSe_3D_Task(const stcRequestArray& packData);

    virtual void execute();

    static void* m_oasRequestArray[42];

    NNS_VECTORFAST m_sPosVecFast;       // offset 0x60, size 0x10
    stcRequestArray& m_orsRequestArray; // offset 0x70, size 0x4
    f32 m_af32ReSpawnFrame[4];          // offset 0x74, size 0x10
    f32& m_orf32ReSpawnFrame_default;   // offset 0x84, size 0x4
    s16 m_as16Id3D[4];                  // offset 0x88, size 0x8
    f32 m_f32DistDownK;                 // offset 0x90, size 0x4
    u8 m_u8ViewPortNum;                 // offset 0x94, size 0x1
    u8 m_u8PortalType;                  // offset 0x95, size 0x1
};

#endif // SETSE_3D_HPP
