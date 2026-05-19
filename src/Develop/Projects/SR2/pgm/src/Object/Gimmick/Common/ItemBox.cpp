#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"

static c8 c8ItemName[20][16];
static u8*** sco8RateTable[16];
static u8 sco8RateTable2Num[4][2][19];
static u8 sco8RateTable3Num[4][3][19];
static u8 sco8RateTable4Num[4][4][19];
static u8 sco8St15RateTable2Num[4][2][19];
static u8 sco8St15RateTable3Num[4][3][19];
static u8 sco8St15RateTable4Num[4][4][19];
static u8 sco8St15RateTable8Num[4][8][19];
static u8 tou8MissileNumTbl_SvlBtl[2][4] = {{1, 1, 2, 3}, {1, 1, 2, 3}};
static u8 tou8ItemNoTable_SvlBtl[8] = {11, 16, 17, 18, 19, 3, 4, 5};
static u8 tou8RateTable_SvlBtl[2][3][4][8];
static u32 scu32RateTblSize[8] = {8, 2, 3, 4, 8, 8, 8, 8};
static u32 toau32RateTblSizeDebug[8] = {8, 2, 3, 4, 8, 2, 3, 4};

namespace nspAgp {
f32 toaf32ItemBox[3] = {30.0f, 50.0f, 100.0f};
}

u32 clsItemBox_Obj::t_u32ReBorn = 0;

void clsItemBox_Obj::createData()
{
}

void clsItemBox_Obj::destroyData()
{
}

void clsItemBox_Obj::execute()
{
}

void clsItemBox_Obj::contactAlwaysEvent(hkContactPoint* p, clsObject* pObj)
{
}

void clsItemBox_Obj::contactRemoveEvent(hkContactPoint* p, clsObject* pObj)
{
}

u32 clsItemBox_Obj::execEffect(clsPlayerTask* pcPlayer, u32 u32ItemParam)
{
    return 0;
}

void clsItemBox_Obj::getAgp(clsPlayerTask* pcHitPlayer, f32 f32AgpAdd)
{
}

clsItemBox_Task::clsItemBox_Task(u32 u32ObjectAreaNum, u32 u32TpI)
    : clsBaseGimmickBody<clsItemBox_Task, clsItemBox_Obj, clsItemBoxModels>(0, 0)
{
}

void clsItemBox_Task::reset()
{
}

void clsItemBox_Task::createModel(stcBinInfo& rsBinInfoI)
{
}

void clsItemBox_Task::execute()
{
}

void clsItemBox_Task::draw()
{
}
