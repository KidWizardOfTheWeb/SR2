#ifndef SCRIPTPARTICLE_HPP
#define SCRIPTPARTICLE_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsScript_Task;

// total size: 0xE0
class clsScriptParticle_Task : public clsTask {
public:
    clsScriptParticle_Task(u32 u32View,
                           u32 u32Code,
                           f32 f32OfsX,
                           f32 f32OfsY,
                           f32 f32OfsZ,
                           u32 u32ModelNo,
                           u32 u32NodeNo,
                           f32 f32InterFrame,
                           f32 f32StartFrame,
                           f32 f32EndFrame,
                           f32 f32Wait);
    virtual ~clsScriptParticle_Task();

    virtual void execute();

    void codeParticle(u8* pu8Ptr, clsScript_Task* pParam2);

    u32 m_u32View;                // offset 0x54, size 0x4
    u32 m_u32Code;                // offset 0x58, size 0x4
    u32 m_u32ModelNo;             // offset 0x5C, size 0x4
    u32 m_u32NodeNo;              // offset 0x60, size 0x4
    NNS_VECTOR m_sOfsVec;         // offset 0x64, size 0xC
    f32 m_f32InterFrame;          // offset 0x70, size 0x4
    f32 m_f32PlayFrame;           // offset 0x74, size 0x4
    f32 m_f32Frame;               // offset 0x78, size 0x4
    f32 m_f32EndFrame;            // offset 0x7C, size 0x4
    f32 m_f32WaitFrame;           // offset 0x80, size 0x4
    NNS_VECTORFAST m_sPosVecFast; // offset 0x90, size 0x10
    f32 m_sMatrix[4][4];          // offset 0xA0, size 0x40
};

#endif // SCRIPTPARTICLE_HPP
