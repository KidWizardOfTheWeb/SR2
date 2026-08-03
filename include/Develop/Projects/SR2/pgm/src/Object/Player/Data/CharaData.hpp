#ifndef CHARADATA_HPP
#define CHARADATA_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x10
class Fuid {
    // Members
public:
    u32 m_0; // offset 0x0, size 0x4
    u32 m_1; // offset 0x4, size 0x4
    u32 m_2; // offset 0x8, size 0x4
    u32 m_3; // offset 0xC, size 0x4
};
namespace nspChara {
// total size: 0x8
struct stcMotionFlgs {
    // Members
    u32 u32Flg[2]; // offset 0x0, size 0x8
};
} // namespace nspChara
typedef nspChara::stcMotionFlgs stcMotionFlgs;
#ifndef ENMRET_DECLARED
#define ENMRET_DECLARED
enum enmRet {
    VISIBLE_CLIP = 0,
    VISIBLE = 1,
    OUT_VISIBLE = 2,
    OUT_PORTAL = 3,
    OUT_FAR = 4,
};
#endif
enum enmModelType {
    MODEL_TYPE_DEF = 0,
    MODEL_TYPE_SKATE_START = 1,
    MODEL_TYPE_ADS = 1,
    MODEL_TYPE_CVS = 2,
    MODEL_TYPE_RLL = 3,
    MODEL_TYPE_SNB = 4,
    MODEL_TYPE_WTD = 5,
    MODEL_TYPE_MAX = 6,
    MODEL_TYPE_SKATE_END = 5,
};

// total size: 0x24
struct stcData {
    // Members
    s8 ac8Name_Debug[16]; // offset 0x0, size 0x10
    f32 f32Height;        // offset 0x10, size 0x4
    f32 f32Weight;        // offset 0x14, size 0x4
    u8 u8Style;           // offset 0x18, size 0x1
    u8 u8SkillType;       // offset 0x19, size 0x1
    u8 u8BaseType;        // offset 0x1A, size 0x1
    u8 u8Reserve[1];      // offset 0x1B, size 0x1
    f32 f32AttackLFrame;  // offset 0x1C, size 0x4
    f32 f32AttackRFrame;  // offset 0x20, size 0x4
};
namespace nspChara {
extern f32 of32BaseHeight;                             // size: 0x4, address: 0x6651C0
extern const stcBasePrfm oasBasePrfm[5];               // size: 0xDC, address: 0x6651D0
extern const stcBasePrfm osWalkPrfm[4];                // size: 0xB0, address: 0x6652B0
extern stcData oasData[19];                            // size: 0x2AC, address: 0x665360
static u8 chk__oasData_SizeCheck_[1];                  // size: 0x1, address: 0x0
extern s8* oasCharaCode3[19];                          // size: 0x4C, address: 0x620CA0
static u8 chk__oasCharaCode3_SizeCheck_[1];            // size: 0x1, address: 0x0
extern u32 oasImageColor[19];                          // size: 0x4C, address: 0x6656B0
static u8 chk__oasImageColor_SizeCheck_[1];            // size: 0x1, address: 0x0
extern u32 oasImageColorRgb[19];                       // size: 0x4C, address: 0x665700
static u8 chk__oasImageColorRgb_SizeCheck_[1];         // size: 0x1, address: 0x0
extern void (*afloadAdditionalFuncs[19])(stcBinInfo&); // size: 0x4C, address: 0x620CF0
static u8 chk__afloadAdditionalFuncs_SizeCheck_[1];    // size: 0x1, address: 0x0
extern stcMotionFlgs asMotionFlgsDef[8];               // size: 0x40, address: 0x665750
extern stcMotionFlgs asMotionFlgsEgg[8];               // size: 0x40, address: 0x665790
extern stcMotionFlgs asMotionFlgsOther[8];             // size: 0x40, address: 0x6657D0
extern stcMotionFlgs asMotionFlgsWave[8];              // size: 0x40, address: 0x665810
extern stcMotionFlgs asMotionFlgsBily[8];              // size: 0x40, address: 0x665850
} // namespace nspChara

#endif // CHARADATA_HPP
