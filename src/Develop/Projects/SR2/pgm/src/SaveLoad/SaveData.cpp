#include "Develop/Projects/SR2/pgm/src/SaveLoad/SaveData.hpp"

namespace {
static u32 au32TimeAtkDefTime[16][2] = {{192000, 62000},
                                        {240000, 78000},
                                        {220000, 72000},
                                        {204000, 66000},
                                        {215000, 70000},
                                        {240000, 78000},
                                        {170000, 40000},
                                        {198000, 65000},
                                        {205000, 68000},
                                        {218000, 72000},
                                        {220000, 73000},
                                        {232000, 77000},
                                        {230000, 75000},
                                        {198000, 65000},
                                        {192000, 63000},
                                        {190000, 63000}};
}

u16 au16DemoName[11];

s32 clsSaveDataCtrl::tas32CrcTbl[256];

template <>
u32 clsBitset<u8>::getOnBitCnt() const
{
    u32 u32Count = 0;
    u32 u32Buffer = 0;

    if (m_BufferSize != 0) {
        u8* pu8Buffer = m_pBuffer;
        do {
            u8 u8Val = *pu8Buffer;
            u32Buffer++;
            pu8Buffer++;
            u32 u32Val = u8Val;
            u32Count += (u8Val & 1) + ((u32)u8Val >> 1 & 1) + ((u32)u8Val >> 2 & 1) +
                        (u32Val >> 3 & 1) + (u32Val >> 4 & 1) + (u32Val >> 5 & 1) +
                        (u32Val >> 6 & 1) + (u32Val >> 7);
        } while (u32Buffer < m_BufferSize);
    }

    return u32Count;
}

clsSaveDataCtrl::clsSaveDataCtrl()
{
}

void clsSaveDataCtrl::InitSaveData()
{
}

void clsSaveDataCtrl::SaveAllOptionData()
{
}

void clsSaveDataCtrl::LoadAllOptionData()
{
}

void* clsSaveDataCtrl::GetSaveDataBuff_Crc()
{
    return 0;
}

u8 clsSaveDataCtrl::CheckSaveDataCrc(const void* pvParam1) const
{
    return 0;
}

void clsSaveDataCtrl::InitBestTime()
{
}

void clsSaveDataCtrl::SetRingCnt(u32 u32Param1)
{
}

u8 clsSaveDataCtrl::SetNormalRaceBestTime(u32 u32Param1, u32 u32Param2)
{
    return 0;
}

u8 clsSaveDataCtrl::SetFreeRaceBestTime(u32 u32Param1, u32 u32Param2)
{
    return 0;
}

u8 clsSaveDataCtrl::SetTimeAttackBestTime(u32 u32Param1, u32 u32Param2)
{
    return 0;
}

u8 clsSaveDataCtrl::SetStoryBestTime(u32 u32Param1, u32 u32Param2)
{
    return 0;
}

u8 clsSaveDataCtrl::SetNormalRaceBestLap(u32 u32Param1, u32 u32Param2)
{
    return 0;
}

u8 clsSaveDataCtrl::SetFreeRaceBestLap(u32 u32Param1, u32 u32Param2)
{
    return 0;
}

u8 clsSaveDataCtrl::SetTimeAttackBestLap(u32 u32Param1, u32 u32Param2)
{
    return 0;
}

u8 clsSaveDataCtrl::SetStoryBestLap(u32 u32Param1, u32 u32Param2)
{
    return 0;
}

u8 clsSaveDataCtrl::SetWorldGPBestTime(u8 u8Param1, u32 u32Param2)
{
    return 0;
}

u8 clsSaveDataCtrl::SetWorldGPBestPoint(u8 u8Param1, u8 u8Param2)
{
    return 0;
}

u8 clsSaveDataCtrl::SetMissionBestData(u32 u32Param1, u32 u32Param2, u32 u32Param3, bool bParam4)
{
    return 0;
}

void clsSaveDataCtrl::SetMissinClrRank(u32 u32Param1, u32 u32Param2, nspSaveData::enmMissionClrRank)
{
}

void clsSaveDataCtrl::AddPlayTime(s32 s32Param1)
{
}

void clsSaveDataCtrl::SetTutorialSelFlag(u32 u32Param1, u32 u32Param2, bool bParam3)
{
}

u8 clsSaveDataCtrl::IsTutorialSel(u32 u32Param1, u32 u32Param2) const
{
    return 0;
}

void clsSaveDataCtrl::SetAllCharaUnlockFlag()
{
}

void clsSaveDataCtrl::SetAllGearUnlockFlag()
{
}

void clsSaveDataCtrl::SetAllStageUnlockFlag()
{
}

void clsSaveDataCtrl::SetAllStoryUnlockFlag()
{
}

void clsSaveDataCtrl::SetAllMissinClrFlag(nspSaveData::enmMissionClrRank)
{
}

void clsSaveDataCtrl::SetAllMissinSelFlag()
{
}

void clsSaveDataCtrl::SetAllTutorialSelFlag()
{
}

void clsSaveDataCtrl::SetAllGameFlag()
{
}

void clsSaveDataMgr::DeleteSaveDataTemp(bool bSetMainData)
{
}

u8 clsSaveDataCtrl::IsGearUnlock(u32 u32Param1) const
{
    return 0;
}

u8 clsSaveDataCtrl::IsCharaUnlock(nspSaveData::enmUnlockChara) const
{
    return 0;
}
