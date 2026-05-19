#ifndef TRICKDATA_HPP
#define TRICKDATA_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/BonusParam.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/KickerParam.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/TrickParam.hpp"

namespace nspTrick {

extern f32 af32RankMaxSpeedRate[9];
extern f32 af32RankUpSpeedRate[9];
extern f32 f32CompensationAnglePipe;
extern f32 oaf32DistanceTable_Pipe[7];
extern f32 oaf32DistanceTable_Spin[7];
extern f32 oaf32KickerRateTable[9][3];
extern s32 oas32BingoRingTable[9];
extern stcBonusParam oasBonusParamTable[9][7];
extern stcKickerParam oasKickerParamTable[9][7];
extern f32 of32VerticalTrickUpFrame;
extern stcFlipKicker* opsKickerParam_BF[21];
extern stcFlipKicker* opsKickerParam_FF[16];

} // namespace nspTrick

#endif // TRICKDATA_HPP
