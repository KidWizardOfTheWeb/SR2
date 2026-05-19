#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GearControlData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/CtrlData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/Gear.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"

namespace nspGear {

s8 aos8ChangeRingTbl[18][4] = {{0, 0, 0, 0},
                               {0, 50, 0, 0},
                               {0, 100, 0, 0},
                               {0, 20, 40, 0},
                               {0, 50, 70, 0},
                               {0, 50, 80, 0},
                               {0, 50, 100, 0},
                               {0, 10, 20, 50},
                               {0, 20, 40, 50},
                               {0, 20, 40, 60},
                               {0, 20, 40, 70},
                               {0, 20, 40, 100},
                               {0, 20, 50, 70},
                               {0, 30, 40, 50},
                               {0, 40, 50, 70},
                               {0, 50, 70, 100},
                               {0, 40, 60, 80},
                               {0, 50, 100, 100}};
stcAddPrfm oasAddPrfmData[96];
stcCtrlData oasCtrlData[63];
stcGearData oasGearData[54];

} // namespace nspGear

static u8 chk__nspGear_oasAddPrfmData_SizeCheck_[1];
static u8 chk__nspGear_oasCtrlData_SizeCheck_[1];
static u8 chk__nspGear_oasGearData_SizeCheck_[1];
