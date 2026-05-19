#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleData.hpp"

u16 nspParticleData::u16NumUnion;
u16 nspParticleData::u16NumGame;
u16 nspParticleData::u16NumMode;
u16 nspParticleData::u16NumSet;
void* nspParticleData::apvUnionDataAdr[100];
void* nspParticleData::apvGameDataAdr[100];
void* nspParticleData::apvModeDataAdr[50];
void* nspParticleData::apvSetDataAdr[100];

void nspParticleData::initData()
{
}

void nspParticleData::setUnionData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4)
{
}

void nspParticleData::setGameData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4)
{
}

void nspParticleData::setModeData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4)
{
}

void nspParticleData::setSetData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4)
{
}

void* nspParticleData::getSetDataStart()
{
    return 0;
}
