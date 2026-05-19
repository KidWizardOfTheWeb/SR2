#ifndef DEBRISCONTROL_HPP
#define DEBRISCONTROL_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/DebriPartsBase.hpp"

struct hkVector4;

// total size: 0x20
class clsDebrisControl {
public:
    ~clsDebrisControl() {}
    u8 isBreak() const { return m_bBreak; }
    void setVelocity(const hkVector4& rv) {}

    void startBreak(const f32 (*psTrsMtx)[4][4],
                    const NNS_VECTORFAST* psBoundVecFst,
                    const NNS_VECTORFAST* opsContactPosVecFast);
    void startBreak(const f32 (*psTrsMtx)[4][4], const NNS_VECTORFAST* psBoundVecFst);
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
