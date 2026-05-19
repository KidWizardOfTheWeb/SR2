#ifndef PARTICLEABSORB_HPP
#define PARTICLEABSORB_HPP

#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleBase.hpp"

// total size: 0x130
class clsParticleAbsorb : public clsParticleBase {
public:
    virtual ~clsParticleAbsorb() {}

    virtual void setCreatedSeparate(NNS_VECTORFAST* psVecFast,
                                    stcParticleDetail* psDetailHi,
                                    bool bSphere,
                                    stcParticleExtensionData* psExtension,
                                    u32 u32Param5);
    virtual void moveCalc(NNS_VECTORFAST* psVecFast,
                          stcParticleDetail* psDetailHi,
                          stcParticleExtensionData* psExtension,
                          f32 f32AddFrame,
                          const f32 (*opsPositionMtx)[4][4],
                          bool bFollowPostion);
};

#endif // PARTICLEABSORB_HPP
