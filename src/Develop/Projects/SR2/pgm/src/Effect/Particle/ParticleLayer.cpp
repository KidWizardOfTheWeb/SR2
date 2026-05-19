#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleLayer.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/ModelViewer.hpp"

u16 g_u16ParticleLayerStopCode;
u16 g_u16ParticleLayerCtrlStopCode;
f32 g_f32LastLayerCountModelViewer;
u32 g_u32LayerAdrMask;

void nspParticleSet::stopAllLayer()
{
}

void clsParticleLayer::checkFlg()
{
}

void nspParticleSet::setParticleTextureTask(bool bParam1, stcParticleData* psParam2)
{
}

void nspParticleSet::subtractParticleTextureTask(stcParticleData* psParam1)
{
}

bool nspParticleSet::checkDeleateParticleTextureTask(
    bool bParam1, u8 u8Param2, u8 u8Param3, u8 u8Param4, u8 u8Param5)
{
    return false;
}

void clsParticleLayer::execute()
{
}

void nspParticleSet::initSetTask()
{
}

clsParticleLayer* nspParticleSet::registTaskParticleData(u8 u8Param1,
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

clsParticleLayer* nspParticleSet::registTask(u8 u8Param1,
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

clsParticleLayer* nspParticleSet::registTask(u8 u8Param1,
                                             u32 u32Param2,
                                             const f32 (*psParam3)[4][4],
                                             const NNS_VECTORFAST* psParam4,
                                             const _NNS_TEXLIST* psParam5,
                                             u8 u8Param6,
                                             u8 u8Param7)
{
    return 0;
}

clsParticleLayer* nspParticleSet::registTask(u8 u8Param1,
                                             u32 u32Param2,
                                             const NNS_VECTORFAST* psParam3,
                                             u8 u8Param4)
{
    return 0;
}

clsParticleLayer* nspParticleSet::registTaskObjData(u8 u8Param1,
                                                    u32 u32Param2,
                                                    const NNS_VECTORFAST* psParam3,
                                                    const NNS_VECTORFAST* psParam4,
                                                    const _NNS_TEXLIST* psParam5,
                                                    u8 u8Param6,
                                                    s32 s32Param7)
{
    return 0;
}

clsParticleLayer* nspParticleSet::registTaskAdr(u8 u8Param1,
                                                u32 u32Param2,
                                                const f32 (*psParam3)[4][4],
                                                const NNS_VECTORFAST* psParam4,
                                                const _NNS_TEXLIST* psParam5,
                                                u8 u8Param6,
                                                u8 u8Param7)
{
    return 0;
}

clsParticleLayer* nspParticleSet::registTaskAdr(u8 u8Param1,
                                                u32 u32Param2,
                                                const NNS_VECTORFAST* psParam3,
                                                u8 u8Param4)
{
    return 0;
}

void nspParticleSet::setBadTrackLow(u8 u8Param1,
                                    const f32 (*psParam2)[4][4],
                                    const NNS_VECTORFAST* psParam3)
{
}

void nspParticleSet::setBadTrackHi(u8 u8Param1,
                                   const f32 (*psParam2)[4][4],
                                   const NNS_VECTORFAST* psParam3)
{
}

void nspParticleSet::setBreakSmallObjectParticle(const NNS_VECTORFAST* psParam1, u32 u32Param2)
{
}

void nspParticleSet::setBreakLargeObjectParticle(const NNS_VECTORFAST* psParam1, u32 u32Param2)
{
}

void nspParticleSet::setGrindLinkParticle(clsPlayerTask& rcParam1, u8* pu8Param2, u32 u32Param3)
{
}

void nspParticleSet::setWallParticle(clsPlayerTask& rcParam1)
{
}

void nspParticleSet::setWaterRunParticle(clsPlayerTask& rcParam1)
{
}

void nspParticleSet::setWaterLandingParticle(clsPlayerTask& rcParam1)
{
}

void nspParticleSet::setWaterWalkParticle(clsPlayerTask* pcParam1, bool bParam2)
{
}

void nspParticleSet::setThroughColisionParticle(clsPlayerTask* pcParam1, u8 u8Param2)
{
}

void nspParticleSet::setRemoveThroughColisionParticle(clsPlayerTask* pcParam1, u8 u8Param2)
{
}

clsParticleLayer* nspParticleSet::registTaskForEvent(u8 u8Param1,
                                                     u32 u32Param2,
                                                     const NNS_VECTORFAST* psParam3,
                                                     const f32 (*psParam4)[4][4])
{
    return 0;
}

void nspParticleSet::setParticleColision()
{
}

u32 nspParticleSet::getModoEffectNo(u32 u32Param1)
{
    return 0;
}
