#ifndef PARTICLEDATA_HPP
#define PARTICLEDATA_HPP

#include "types.h"

namespace nspParticleData {
void initData();
void setUnionData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4);
void setGameData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4);
void setModeData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4);
void setSetData(u8* pu8Param1, u32* pu32Param2, u16 u16Param3, u32 u32Param4);
void* getSetDataStart();

extern u16 u16NumUnion;
extern u16 u16NumGame;
extern u16 u16NumMode;
extern u16 u16NumSet;
extern void* apvUnionDataAdr[100];
extern void* apvGameDataAdr[100];
extern void* apvModeDataAdr[50];
extern void* apvSetDataAdr[100];
} // namespace nspParticleData

// total size: 0x14
struct stcParticle {
    u8 bLayerForceStop;    // offset 0x0, size 0x1
    u8 bAllKill;           // offset 0x1, size 0x1
    u8 bTaskPriority;      // offset 0x2, size 0x1
    u32 s32LayerNum;       // offset 0x4, size 0x4
    s32 s32PlayNum;        // offset 0x8, size 0x4
    s32 s32GearChengeNode; // offset 0xC, size 0x4
    u8 u8CarEffect;        // offset 0x10, size 0x1
    u8 u8VecTest;          // offset 0x11, size 0x1
};

#endif // PARTICLEDATA_HPP
