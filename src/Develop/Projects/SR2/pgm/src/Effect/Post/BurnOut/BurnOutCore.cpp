#include "Develop/Projects/SR2/pgm/src/Effect/Post/BurnOut/BurnOutCore.hpp"

clsBurnOutCore_Task::clsBurnOutCore_Task(u32 u32NumI,
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
                                         f32 f32MaxClipZI)
    : clsTask(0x77A74, 5)
{
}

void clsBurnOutCore_Task::execute()
{
}

void clsBurnOutCore_Task::draw()
{
}
