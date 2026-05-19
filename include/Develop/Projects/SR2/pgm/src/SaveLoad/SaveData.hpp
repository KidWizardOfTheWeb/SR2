#ifndef SAVEDATA_HPP
#define SAVEDATA_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOSystem.hpp"

extern u16 au16DemoName[11];

namespace nspSaveData {
enum enmMissionClrRank {
    RANK_NONE = 0,
    RANK_C = 1,
    RANK_B = 2,
    RANK_A = 3,
    RANK_S = 4,
};

enum enmUnlockChara {
    CHARA_ROLL = 0,
    CHARA_BALDA = 1,
    CHARA_EGGMAN = 2,
    CHARA_WHISPER = 3,
    CHARA_METAL_SONIC = 4,
    CHARA_SERPENT = 5,
    CHARA_TAILSTWO = 6,
    CHARA_SCORP = 7,
    CHARA_NOVA = 8,
    CHARA_WHISPERF = 9,
    CHARA_MAX = 10,
};

enum enmSaveDataNo {
    SAVEDATA_NO_01 = 0,
    SAVEDATA_NO_02 = 1,
    SAVEDATA_NO_03 = 2,
    SAVEDATA_MAX_NUM = 3,
    SAVEDATA_NO_NODATA = -1,
};
} // namespace nspSaveData

enum enmTempState {
    TEMP_DATA_NO_DATA = 0,
    TEMP_DATA_BREAK = 1,
    TEMP_DATA_OK = 2,
};

template <typename T>
class clsBitset {
public:
    clsBitset(T* pBuffer = 0, u32 size = 0) : m_pBuffer(pBuffer), m_BufferSize(size), m_pVTable(0)
    {
    }
    ~clsBitset() {}

    T* m_pBuffer;          // offset 0x0, size 0x4
    u32 m_BufferSize;      // offset 0x4, size 0x4
    const void* m_pVTable; // offset 0x8, size 0x4

    u8 get(u32 u32Pos) const;
    u32 getOnBitCnt() const;
    void set(u32 u32Pos, bool bVal);
};

// total size: 0x8
struct stcSaveDataHeader {
public:
    u8 u8Version;    // offset 0x0, size 0x1
    u8 u8Padding[3]; // offset 0x1, size 0x3
    u32 u32Size;     // offset 0x4, size 0x4
};

// total size: 0x8
struct stcOptionData {
    u8 u8AudioMode;   // offset 0x0, size 0x1
    u8 u8MessageMode; // offset 0x1, size 0x1
    u8 u8VoiceMode;   // offset 0x2, size 0x1
    u8 u8VibMode;     // offset 0x3, size 0x1
    u8 u8PadType;     // offset 0x4, size 0x1
    u8 u8Padding[3];  // offset 0x5, size 0x3
};

// total size: 0x10
struct stcRaceOption {
    s8 m_s8Story_Hint;       // offset 0x0, size 0x1
    s8 m_s8Free_Lap;         // offset 0x1, size 0x1
    s8 m_s8Free_Gp;          // offset 0x2, size 0x1
    s8 m_s8Free_Hint;        // offset 0x3, size 0x1
    s8 m_s8TimeAttack_Ghost; // offset 0x4, size 0x1
    s8 m_s8WorldGP_Hint;     // offset 0x5, size 0x1
    s8 m_s8Relay_Lap;        // offset 0x6, size 0x1
    s8 m_s8Relay_Gp;         // offset 0x7, size 0x1
    s8 m_s8Ball_Time;        // offset 0x8, size 0x1
    s8 m_s8Ball_Point;       // offset 0x9, size 0x1
    s8 m_s8Battle_Mode;      // offset 0xA, size 0x1
    s8 m_s8Battle_Hp;        // offset 0xB, size 0x1
    s8 m_s8Battle_Time;      // offset 0xC, size 0x1
    s8 m_s8Padding[3];       // offset 0xD, size 0x3
};

// total size: 0x51C
struct stcGameData {
    u32 u32PlayTime;                      // offset 0x0, size 0x4
    u32 u32RingCount;                     // offset 0x4, size 0x4
    u32 au32NormalRaceBestTime[16];       // offset 0x8, size 0x40
    u32 au32FreeRaceBestTime[16];         // offset 0x48, size 0x40
    u32 au32TimeAttackBestTime[16];       // offset 0x88, size 0x40
    u32 au32StoryBestTime[16];            // offset 0xC8, size 0x40
    u32 au32NormalRaceBestLap[16];        // offset 0x108, size 0x40
    u32 au32FreeRaceBestLap[16];          // offset 0x148, size 0x40
    u32 au32TimeAttackBestLap[16];        // offset 0x188, size 0x40
    u32 au32StoryBestLap[16];             // offset 0x1C8, size 0x40
    u32 au32MissionBestData[128];         // offset 0x208, size 0x200
    u32 au32WorldGPTime[2];               // offset 0x408, size 0x8
    u16 au16UserName[11];                 // offset 0x410, size 0x16
    u16 au16Padding[1];                   // offset 0x426, size 0x2
    stcOptionData sOption;                // offset 0x428, size 0x8
    stcRaceOption sRaceOption;            // offset 0x430, size 0x10
    clsOOSystem::stcDateTime sUpdateTime; // offset 0x440, size 0x8
    u8 au8MissionClrRank[128];            // offset 0x448, size 0x80
    u8 au8CharaUnlock[1];                 // offset 0x4C8, size 0x1
    u8 au8GearUnlock[8];                  // offset 0x4C9, size 0x8
    u8 au8StageUnlock[2];                 // offset 0x4D1, size 0x2
    u8 au8StoryUnlock[2];                 // offset 0x4D3, size 0x2
    u8 au8MissionClear[16];               // offset 0x4D5, size 0x10
    u8 au8MissionSelect[16];              // offset 0x4E5, size 0x10
    u8 au8TutorialSelect[2];              // offset 0x4F5, size 0x2
    u8 au8GameFlag[32];                   // offset 0x4F7, size 0x20
    u8 au8WorldGPPoint[2];                // offset 0x517, size 0x2
};

// total size: 0x4000
struct stcSaveGameData {
public:
    u32 u32CrcData;            // offset 0x0, size 0x4
    stcSaveDataHeader sHeader; // offset 0x4, size 0x8
    stcGameData sGameData;     // offset 0xC, size 0x51C
    u8 au8Reserve[15064];      // offset 0x528, size 0x3AD8
};

// total size: 0x6C
class clsSaveDataCtrl {
public:
    inline clsSaveDataCtrl();

    stcSaveGameData* m_psSaveData;        // offset 0x0, size 0x4
    stcGameData* m_psGameData;            // offset 0x4, size 0x4
    s32 m_s32PlayTimeCnt;                 // offset 0x8, size 0x4
    clsBitset<u8> m_sCharaUnlockCtrl;     // offset 0xC, size 0xC
    clsBitset<u8> m_sGearUnlockCtrl;      // offset 0x18, size 0xC
    clsBitset<u8> m_sStageUnlockCtrl;     // offset 0x24, size 0xC
    clsBitset<u8> m_sStoryUnlockCtrl;     // offset 0x30, size 0xC
    clsBitset<u8> m_sMissinClrFlagCtrl;   // offset 0x3C, size 0xC
    clsBitset<u8> m_sMissinSelFlagCtrl;   // offset 0x48, size 0xC
    clsBitset<u8> m_sTutorialSelFlagCtrl; // offset 0x54, size 0xC
    clsBitset<u8> m_sGameFlagCtrl;        // offset 0x60, size 0xC

    static s32 tas32CrcTbl[256];

    void InitSaveData();
    void SaveAllOptionData();
    void LoadAllOptionData();
    void* GetSaveDataBuff_Crc();
    void InitBestTime();
    void SetRingCnt(u32 u32Param1);
    u8 SetNormalRaceBestTime(u32 u32Param1, u32 u32Param2);
    u8 SetFreeRaceBestTime(u32 u32Param1, u32 u32Param2);
    u8 SetTimeAttackBestTime(u32 u32Param1, u32 u32Param2);
    u8 SetStoryBestTime(u32 u32Param1, u32 u32Param2);
    u8 SetNormalRaceBestLap(u32 u32Param1, u32 u32Param2);
    u8 SetFreeRaceBestLap(u32 u32Param1, u32 u32Param2);
    u8 SetTimeAttackBestLap(u32 u32Param1, u32 u32Param2);
    u8 SetStoryBestLap(u32 u32Param1, u32 u32Param2);
    u8 SetWorldGPBestTime(u8 u8Param1, u32 u32Param2);
    u8 SetWorldGPBestPoint(u8 u8Param1, u8 u8Param2);
    u8 SetMissionBestData(u32 u32Param1, u32 u32Param2, u32 u32Param3, bool bParam4);
    void SetMissinClrRank(u32 u32Param1, u32 u32Param2, nspSaveData::enmMissionClrRank);
    void AddPlayTime(s32 s32Param1);
    void SetTutorialSelFlag(u32 u32Param1, u32 u32Param2, bool bParam3);
    u8 IsTutorialSel(u32 u32Param1, u32 u32Param2) const;
    void SetAllCharaUnlockFlag();
    void SetAllGearUnlockFlag();
    void SetAllStageUnlockFlag();
    void SetAllStoryUnlockFlag();
    void SetAllMissinClrFlag(nspSaveData::enmMissionClrRank);
    void SetAllMissinSelFlag();
    void SetAllTutorialSelFlag();
    void SetAllGameFlag();
    u8 CheckSaveDataCrc(const void* pvParam1) const;
    inline u8 IsGearUnlock(u32 u32Param1) const;
    inline u8 IsCharaUnlock(nspSaveData::enmUnlockChara) const;
};

// total size: 0x30
class clsSaveDataMgr : public clsSingleton<clsSaveDataMgr> {
public:
    clsSaveDataMgr() {}
    virtual ~clsSaveDataMgr() {}

    clsSaveDataCtrl* GetCtrl() { return m_pcSaveDataCtrl; }
    void SetCurrentNo(nspSaveData::enmSaveDataNo enCurrentNo) { m_enCurrentNo = enCurrentNo; }
    void DeleteSaveDataTemp(bool bSetMainData);

    nspSaveData::enmSaveDataNo m_enCurrentNo;  // offset 0x4, size 0x4
    clsSaveDataCtrl* m_pcSaveDataCtrl;         // offset 0x8, size 0x4
    clsSaveDataCtrl* m_apcSaveDataCtrlTemp[4]; // offset 0xC, size 0x10
    enmTempState m_aenTempState[4];            // offset 0x1C, size 0x10
    u8 m_bPlayTimeCntFlag;                     // offset 0x2C, size 0x1
};

#endif // SAVEDATA_HPP
