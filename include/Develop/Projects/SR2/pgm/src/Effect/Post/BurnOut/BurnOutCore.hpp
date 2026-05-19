#ifndef BURNOUTCORE_HPP
#define BURNOUTCORE_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

struct stcDetail;

// total size: 0x74
class clsBurnOutCore_Task : public clsTask {
public:
    clsBurnOutCore_Task(u32 u32NumI,
                        u32 u32SizeI,
                        const f32 (&orsInitRotMtxI)[4][4],
                        const NNS_VECTOR& orsPosI,
                        const NNS_VECTOR& orsLocalPosI,
                        const NNS_VECTOR& orsLocalPosRandRangeI,
                        const NNS_VECTOR& orsVelocityI,
                        const NNS_VECTOR& orsRandLocalVelocityI,
                        f32 f32ColliYI,
                        f32 f32AirKI,
                        f32 f32MassI,
                        u32 u32MaxLifeFrameI,
                        f32 f32GroundKI,
                        f32 f32MaxClipZI);
    virtual ~clsBurnOutCore_Task() {}
    virtual void execute();
    virtual void draw();

    stcDetail* m_psDetail; // offset 0x54, size 0x4
    f32 m_f32ColliY;       // offset 0x58, size 0x4
    u32 m_u32MaxLifeFrame; // offset 0x5C, size 0x4
    f32 m_f32MaxClipZ;     // offset 0x60, size 0x4
    f32 m_f32AirK;         // offset 0x64, size 0x4
    f32 m_f32GroundK;      // offset 0x68, size 0x4
    f32 m_f32Mass;         // offset 0x6C, size 0x4
    u16 m_u16Num;          // offset 0x70, size 0x2
    u8 m_u8Size;           // offset 0x72, size 0x1
};

#endif // BURNOUTCORE_HPP
