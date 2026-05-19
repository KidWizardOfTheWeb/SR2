#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnGraphics.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

struct NNS_MOTION;

// total size: 0x10
struct stcFColor {
    f32 f32r; // offset 0x0, size 0x4
    f32 f32g; // offset 0x4, size 0x4
    f32 f32b; // offset 0x8, size 0x4
    f32 f32a; // offset 0xC, size 0x4
};

namespace nspGame {
// total size: 0x8
struct stcMotionTable {
    u32 u32Num;             // offset 0x0, size 0x4
    u32 u32FileSize;        // offset 0x4, size 0x4
    NNS_MOTION* aspTable[]; // offset 0x8, size 0x0
};

// total size: 0x8
struct stcTable {
    u32 u32Num;      // offset 0x0, size 0x4
    u32 u32FileSize; // offset 0x4, size 0x4
    u32 au32Table[]; // offset 0x8, size 0x0
};

// total size: 0x18
struct stcChaoMotion {
    NNS_MOTION* psMotion[6]; // offset 0x0, size 0x18
};

void SetUpMotionTable(stcMotionTable* (&rapsParam1)[8], stcMotionTable* (&raapsParam2)[19][8]);
stcTable* BinSetUpTableData(void* pvBuff);

extern stcFColor asBoostColor[19][2];
extern clsModelType_OB_TX acChara[6][19];
extern clsModelType_OB_TX cSuperSonicModel;
extern _GearModelInfo sGearModelInfo;
extern stcAttackModel asAttackData[20];
extern stcChaoMotion sChaoMotion;
} // namespace nspGame

#endif // GAMEDATA_HPP
