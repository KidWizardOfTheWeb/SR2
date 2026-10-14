#ifndef CTRLICON_HPP
#define CTRLICON_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/System/nnsystem.h"

// total size: 0x2A0
class clsCtrlIcon_Task : public clsTask {
public:
    NNS_MATRIX m_sGhostDrawMtx;      // offset 0x60, size 0x40
    NNS_MATRIX m_asPlayerDrawMtx[8]; // offset 0xA0, size 0x200

    virtual ~clsCtrlIcon_Task() {}
    virtual void draw();
    void drawPlayerIcon(u32 u32Param1,
                        bool* pParam2,
                        const NNS_VECTORFAST* pParam3,
                        f32 f32Param4,
                        f32 f32Param5,
                        f32 f32Param6);
    void drawGhostIcon(u32 u32Param1,
                       bool* pParam2,
                       const NNS_VECTORFAST* pParam3,
                       f32 f32Param4,
                       f32 f32Param5,
                       f32 f32Param6);
};

#endif // CTRLICON_HPP
