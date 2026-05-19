#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GameData.hpp"

stcFColor nspGame::asBoostColor[19][2];
clsModelType_OB_TX nspGame::acChara[6][19];
clsModelType_OB_TX nspGame::cSuperSonicModel;
_GearModelInfo nspGame::sGearModelInfo;
stcAttackModel nspGame::asAttackData[20];
nspGame::stcChaoMotion nspGame::sChaoMotion;

nspGame::stcTable* nspGame::BinSetUpTableData(void* pvBuff)
{
    return 0;
}

void nspGame::SetUpMotionTable(stcMotionTable* (&rapsParam1)[8],
                               stcMotionTable* (&raapsParam2)[19][8])
{
}
