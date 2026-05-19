#ifndef SETSE_2D_HPP
#define SETSE_2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/System/SeInfo.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Sound/PlaySe_2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0xA0
class clsSetSe_2D_Task : public clsTask {
public:
    ~clsSetSe_2D_Task();

    clsSetSe_2D_Task(const stcSetDataDetail& packData);

    virtual void execute();

    NNS_VECTORFAST m_sPosVecFast;    // offset 0x60, size 0x10
    stcSeInfo* m_opsRequestArray[3]; // offset 0x70, size 0xC
    s16 m_as16Id2D[4];               // offset 0x7C, size 0x8
    u8 m_u8ViewPortNum;              // offset 0x84, size 0x1
    u8 m_u8PortalType;               // offset 0x85, size 0x1
    clsPlaySe_2D* m_cPlaySe2d[3];    // offset 0x88, size 0xC
    s32 m_s32StageNo;                // offset 0x94, size 0x4
    u32 m_u32BirdNo;                 // offset 0x98, size 0x4

    static void* m_oasRequestArray2D[22];
};

#endif // SETSE_2D_HPP
