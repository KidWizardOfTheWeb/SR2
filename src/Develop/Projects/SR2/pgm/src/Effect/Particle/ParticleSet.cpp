#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleSet.hpp"

static u8 g_au8ParticleConfigDrawType[8] = {0, 2, 2, 2, 2, 2, 1, 1};
stcParticleEditParam sParticleFullData;

namespace nspParticleSet {

void subtractParticleTextureTask(stcParticleData* psParam1)
{
}

bool checkDeleateParticleTextureTask(
    bool bParam1, u8 u8Param2, u8 u8Param3, u8 u8Param4, u8 u8Param5)
{
    return false;
}

void initSetTask()
{
}

clsParticleLayer* registTaskParticleData(u8 u8Param1,
                                         const u16* pu16Param2,
                                         u16 u16Param3,
                                         stcParticleEditParam* psParam4,
                                         const f32 (*psParam5)[4][4],
                                         const NNS_VECTORFAST* psParam6,
                                         const _NNS_TEXLIST* psParam7,
                                         u8 u8Param8,
                                         s32 s32Param9)
{
    return 0;
}

clsParticleLayer* registTask(u8 u8Param1,
                             u32 u32Param2,
                             const f32 (*psParam3)[4][4],
                             const NNS_VECTORFAST* psParam4,
                             const _NNS_TEXLIST* psParam5,
                             u8 u8Param6,
                             u8 u8Param7)
{
    return 0;
}

clsParticleLayer* registTaskObjData(u8 u8Param1,
                                    u32 u32Param2,
                                    const NNS_VECTORFAST* psParam3,
                                    const NNS_VECTORFAST* psParam4,
                                    const _NNS_TEXLIST* psParam5,
                                    u8 u8Param6,
                                    s32 s32Param7)
{
    return 0;
}

clsParticleLayer* registTask(u8 u8Param1,
                             u32 u32Param2,
                             const NNS_VECTORFAST* psParam3,
                             u8 u8Param4)
{
    return 0;
}

clsParticleLayer* registTaskAdr(u8 u8Param1,
                                u32 u32Param2,
                                const NNS_VECTORFAST* psParam3,
                                u8 u8Param4)
{
    return 0;
}

clsParticleLayer* registTaskAdr(u8 u8Param1,
                                u32 u32Param2,
                                const f32 (*psParam3)[4][4],
                                const NNS_VECTORFAST* psParam4,
                                const _NNS_TEXLIST* psParam5,
                                u8 u8Param6,
                                u8 u8Param7)
{
    return 0;
}

clsParticleLayer* registTask(u8 u8Param1,
                             u32 u32Param2,
                             f32 f32Param3,
                             f32 f32Param4,
                             f32 f32Param5,
                             f32 f32Param6,
                             f32 f32Param7,
                             f32 f32Param8,
                             u8 u8Param9)
{
    return 0;
}

void setBadTrackLow(u8 u8Param1, const f32 (*psParam2)[4][4], const NNS_VECTORFAST* psParam3)
{
}

void setBadTrackHi(u8 u8Param1, const f32 (*psParam2)[4][4], const NNS_VECTORFAST* psParam3)
{
}

void setBreakSmallObjectParticle(const NNS_VECTORFAST* psParam1, u32 u32Param2)
{
}

void setBreakLargeObjectParticle(const NNS_VECTORFAST* psParam1, u32 u32Param2)
{
}

void setGrindLinkParticle(clsPlayerTask& rcParam1, u8* pu8Param2, u32 u32Param3)
{
}

void setWallParticle(clsPlayerTask& rcParam1)
{
}

void setWaterRunParticle(clsPlayerTask& rcParam1)
{
}

void setWaterLandingParticle(clsPlayerTask& rcParam1)
{
}

void setWaterWalkParticle(clsPlayerTask* pcParam1, bool bParam2)
{
}

void setThroughColisionParticle(clsPlayerTask* pcParam1, u8 u8Param2)
{
}

void setRemoveThroughColisionParticle(clsPlayerTask* pcParam1, u8 u8Param2)
{
}

clsParticleLayer* registTaskForEvent(u8 u8Param1,
                                     u32 u32Param2,
                                     const NNS_VECTORFAST* psParam3,
                                     const f32 (*psParam4)[4][4])
{
    return 0;
}

void setParticleColision()
{
}

u32 getModoEffectNo(u32 u32Param1)
{
    return 0;
}

} // namespace nspParticleSet
