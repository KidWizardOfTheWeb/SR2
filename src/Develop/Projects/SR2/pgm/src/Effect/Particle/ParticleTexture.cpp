#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleTexture.hpp"

f32 clsParticleTexture::m_tsInvertViewMtx[4][4];
s32 g_s32ParTexTestCount;

clsParticleTexture::~clsParticleTexture()
{
}

void clsParticleTexture::draw()
{
}

s32 clsParticleTexture::calcTaskPriority(
    bool bBurn, u8 u8Blend, u8 u8Zmode, u8 u8DrawType, u16 u16TexNo)
{
    return 0;
}
