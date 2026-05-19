#include "Develop/Projects/SR2/pgm/src/Advertise/Select/PlayerEntry.hpp"
#include "Develop/Projects/SR2/pgm/src/Advertise/Title/Title.hpp"

static u8 tabWalkMode[4];
static u8 chk__SelectCharaTbl_SizeCheck_[1];

namespace nspNnModelType {
static u32 BIT_DIV_MAP = 0x40;
static u32 BIT_OBJECT = 0x1;
static u32 BIT_TEXTURE = 0x2;
static u32 BIT_MOTION = 0x4;
static u32 BIT_MATMOTOBJ = 0x8;
static u32 BIT_MORPHOBJ = 0x10;
static u32 BIT_MORPHTARGETLIST = 0x20;
} // namespace nspNnModelType

stcEntryLight nspPlayerEntry::EntryLight[2];
NNS_VECTOR nspPlayerEntry::DrawPosData[4][2];
f32 nspPlayerEntry::CharaHeightDiff[19];
stcEntryRoboTypeData nspPlayerEntry::EntryRoboData[2];
stcEntryCharaTypeData nspPlayerEntry::EntryModelData[3];
stcGearLocalData nspPlayerEntry::EntryGearLocalData[1];
u32 nspPlayerEntry::SelectCharaTbl[19];

stcSendAdv clsPlayerEntry_Task::m_tasUserSendAdv[4];

void nspPlayerEntry::getModelData(u32 u32Param1,
                                  clsGameMgr::stcSendAdv* psParam2,
                                  f32** ppf32Param3,
                                  NNS_VECTOR** ppsParam4,
                                  nspOOMisc::stcPoint2D_s32** ppsParam5,
                                  f32** ppf32Param6,
                                  f32** ppf32Param7,
                                  f32* pf32Param8,
                                  NNS_VECTOR* psParam9,
                                  bool bParam10)
{
}

clsPlayerEntry_Task::clsPlayerEntry_Task(clsAdvertiseMgr_Task* pcAdv, u32 u32A, u32 u32B)
    : clsTask(0, 0)
{
}

void clsPlayerEntry_Task::Pack2SetLocal(void* pv, u32 u32A, u32 u32B)
{
}

void clsPlayerEntry_Task::loadGearModels(u32 u32Idx, stcBinInfo& rcBin)
{
}

void clsPlayerEntry_Task::checkReadFile(u32 u32Idx)
{
}

void clsPlayerEntry_Task::returnMode()
{
}

void clsPlayerEntry_Task::setupNextMode()
{
}

void clsPlayerEntry_Task::execute()
{
}

void clsPlayerEntry_Task::drawLockCharater()
{
}

void clsPlayerEntry_Task::drawPrepare()
{
}

void clsPlayerEntry_Task::drawGearInfo(u32 u32Idx, stcPlaceObject2* psObj)
{
}

void clsPlayerEntry_Task::drawModel(u32 u32Idx)
{
}

void clsPlayerEntry_Task::drawStatus(u32 u32Idx)
{
}

void clsPlayerEntry_Task::drawUser(u32 u32Idx)
{
}

void clsPlayerEntry_Task::draw()
{
}
