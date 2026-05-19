#include "Develop/Projects/SR2/pgm/src/Object/Player/Motion.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

namespace nspNnUtil {
static NNS_VECTORFAST tosUnitScaleVecFast = {1.0f, 1.0f, 1.0f, 1.0f};
}

f32 clsMotion::m_tf32SystemRate;

void clsMotion::create(NNS_OBJECT* psObject)
{
}

void clsMotion::release()
{
}

void clsMotion::updateFrame()
{
}

void clsMotion::updateTrs()
{
}

void clsMotion::play(NNS_MOTION* pMotion, f32 fFrame, enmStatus eStatus)
{
}

void clsMotion::playLink(NNS_MOTION* pMotion, f32 fFrame1, f32 fFrame2, enmStatus eStatus)
{
}
