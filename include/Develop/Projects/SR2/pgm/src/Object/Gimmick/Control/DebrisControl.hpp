#ifndef DEBRISCONTROL_HPP
#define DEBRISCONTROL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/DebriPartsBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"

// total size: 0x20
class clsDebrisControl {
public:
    ~clsDebrisControl() {}
    u8 isBreak() const { return m_bBreak; }
    void reset()
    {
        m_bBreak = 0;
        if (m_apcDebris != 0) {
            s32 i = 0;
            do {
                m_apcDebris[i]->reset();
                ++i;
            } while (i < m_s32Num);
        }
    }
    void setVelocity(const hkVector4& rcVelocity)
    {
        f32 z = rcVelocity.z;
        f32 y = rcVelocity.y;
        f32 x = rcVelocity.x;
        m_sVelocity.x = x;
        m_sVelocity.y = y;
        m_sVelocity.z = z;
    }

    void startBreak(const NNS_MATRIX* psTrsMtx,
                    const NNS_VECTORFAST* psBoundVecFst,
                    const NNS_VECTORFAST* opsContactPosVecFast);
    void startBreak(const NNS_MATRIX* psTrsMtx, const NNS_VECTORFAST* psBoundVecFst);
    void drawAlpha(NNS_OBJECT* psObject, f32 f32ClipSqDist, NNS_VECTOR* psScaleVec);
    void drawLocalRotate(NNS_OBJECT* psObject, f32 f32ClipSqDist);
    void draw(NNS_OBJECT* psObject, f32 f32ClipSqDist, NNS_VECTOR* psScaleVec);
    void update();

    clsDebriPartsBase** m_apcDebris; // offset 0x0, size 0x4
    clsDebriPartsBase* m_pcDebris;   // offset 0x4, size 0x4
    NNS_NODE* m_psNodeList;          // offset 0x8, size 0x4
    s32 m_s32Num;                    // offset 0xC, size 0x4
    NNS_VECTOR m_sVelocity;          // offset 0x10, size 0xC
    u8 m_bBreak;                     // offset 0x1C, size 0x1
};

#endif // DEBRISCONTROL_HPP
