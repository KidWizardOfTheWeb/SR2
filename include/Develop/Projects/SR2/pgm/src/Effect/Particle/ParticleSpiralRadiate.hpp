#ifndef PARTICLESPIRALRADIATE_HPP
#define PARTICLESPIRALRADIATE_HPP

#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleBase.hpp"

// total size: 0x130
class clsParticleSpiralRadiate : public clsParticleBase {
public:
    virtual ~clsParticleSpiralRadiate() {}
    virtual void setCreatedSeparate(NNS_VECTORFAST* psExtension,
                                    stcParticleDetail* pParam2,
                                    bool bParam3,
                                    stcParticleExtensionData* pParam4,
                                    u32 u32Param5);
    virtual void moveCalc(NNS_VECTORFAST* psVecFast,
                          stcParticleDetail* psDetailHi,
                          stcParticleExtensionData* psExtension,
                          f32 f32AddFrame,
                          const f32 (*opsPositionMtx)[4][4],
                          bool bFollowPostion);
};

#endif // PARTICLESPIRALRADIATE_HPP
