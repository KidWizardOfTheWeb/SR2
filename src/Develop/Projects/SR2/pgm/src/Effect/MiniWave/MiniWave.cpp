#include "Develop/Projects/SR2/pgm/src/Effect/MiniWave/MiniWave.hpp"

namespace nspMiniWave {
_NNS_TEXLIST* psTexList_MiniWave;
static stcMiniWaveParam asMiniWaveParam[4];
} // namespace nspMiniWave

namespace nspNnUtil {
static NNS_VECTOR tosZVec = {0.0f, 0.0f, 1.0f};
}

clsMiniWaveEffect_Task::clsMiniWaveEffect_Task(u8 u8PlayerNo,
                                               u8 u8EffectNo,
                                               u32 u32DataNo,
                                               u8 u8TexType)
    : clsTask(0x46D34, 5)
{
}

void clsMiniWaveEffect_Task::execute()
{
}

void clsMiniWaveEffect_Task::draw()
{
}

void clsMiniWaveEffect_Task::init()
{
}

void clsMiniWaveEffect_Task::setWavePosition(NNS_VECTORFAST& rsPosVecFast)
{
}

void clsMiniWaveEffect_Task::setVelocityMtxPtr(const f32 (*opaMtx)[4][4])
{
}

void clsMiniWaveEffect_Task::setPosturalMtxPtr(const f32 (*opaMtx)[4][4])
{
}

void clsMiniWaveEffect_Task::setPosVecFast(NNS_VECTORFAST& rsPosVecFast)
{
}
