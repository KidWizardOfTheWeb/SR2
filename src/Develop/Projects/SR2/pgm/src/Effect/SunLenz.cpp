#include "Develop/Projects/SR2/pgm/src/Effect/SunLenz.hpp"

namespace {
class strLensFlareInfo {
public:
    f32 f32PosOfs;    // offset 0x0, size 0x4
    f32 f32Scale;     // offset 0x4, size 0x4
    u32 u32RGB;       // offset 0x8, size 0x4
    s32 s32TextureNo; // offset 0xC, size 0x4
};

static f32 tf32z_Debug = -1.0f;
static strLensFlareInfo cotsLensFlareInfo[10];
} // namespace

void clsSunLenz_Task::setTexture(u8 u8type)
{
}

void clsSunLenz_Task::execute()
{
}

void clsSunLenz_Task::draw()
{
}
