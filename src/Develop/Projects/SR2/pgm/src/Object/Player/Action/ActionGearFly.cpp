#include "types.h"

static s32 toaA32PitchGravityTable[3] = {0, 0, 0};

namespace nspFly {
static f32 FLYACTION_MIN_PITCH = 5461.0f;
static f32 FLYACTION_MAX_PITCH = 5461.0f;
static f32 FLYACTION_LEFT_RIGHT_ROT = 127.0f;
static f32 FLYACTION_UP_DOWN_ROT = 127.0f;
} // namespace nspFly

namespace nspAgp {
f32 toaf32BonusFly[3] = {0.07f, 0.15f, 0.25f};
} // namespace nspAgp
