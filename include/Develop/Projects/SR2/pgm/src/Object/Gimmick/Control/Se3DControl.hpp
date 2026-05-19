#ifndef SE3DCONTROL_HPP
#define SE3DCONTROL_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x18
struct stcSeData {
    u32 u32SndId;      // offset 0x0, size 0x4
    f32 f32ClipDistx2; // offset 0x4, size 0x4
    f32 f32DistDownK;  // offset 0x8, size 0x4
    s16 as16Id3D[4];   // offset 0xC, size 0x8
    u8 bLoop;          // offset 0x14, size 0x1
    u8 u8Padd[3];      // offset 0x15, size 0x3
};

// total size: 0x8
struct stcSeView {
    s8 s8ViewNo;   // offset 0x0, size 0x1
    f32 f32Distx2; // offset 0x4, size 0x4
};

// total size: 0xC
class clsSe3DControl {
public:
    clsSe3DControl(u8 u8Param1) : m_u8SeNum(u8Param1) {}

    virtual ~clsSe3DControl() {}

    void play(u8 u8SeNum, const NNS_VECTORFAST& rsPosVecFast);
    void setParam(u8 u8SeNum, const NNS_VECTORFAST& rsPosVecFast);
    void setInfo(u8 u8Num, u32 u32SndId, f32 rf32SeDistx2, bool bLoop, f32 f32DistDownK);
    void stopAll();
    void stop(u8 u8SeNum);

    stcSeData* m_apsSeData; // offset 0x4, size 0x4
    u8 m_u8SeNum;           // offset 0x8, size 0x1
};

#endif // SE3DCONTROL_HPP
