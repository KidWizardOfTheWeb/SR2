#ifndef CRI_HPP
#define CRI_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOSystem.hpp"
#include "types.h"

// total size: 0x10
class RofsInitPara {
public:
    s32 max_open;    // offset 0x0, size 0x4
    s32 max_volume;  // offset 0x4, size 0x4
    s32 max_dirent;  // offset 0x8, size 0x4
    void* rofs_work; // offset 0xC, size 0x4
};

namespace nspCri {
void setup();
void setSoundMode(clsOOSystem::enmSoundMode eParam1);

extern u32 oau32StageSeTblSize[16];
extern u32 oau32StageSePcmSize[16];
extern u32 oau32PlayerVoiceTblPcmSize[8];
} // namespace nspCri

#endif // CRI_HPP
