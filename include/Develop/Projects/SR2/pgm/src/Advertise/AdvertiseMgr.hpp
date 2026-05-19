#ifndef ADVERTISEMGR_HPP
#define ADVERTISEMGR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlashParse.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFontSystem.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnFontSystem.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"

// Forward declarations — pointer-only types
class clsOOFlashPlayer;
class clsOOFlashMovie;
class clsModelType_OB_TX_MO_MA_MF;
class clsExtraMenu_Task;
class clsOption_Task;
class clsModeSelect_Task;
class clsTitleMenu_Task;
class clsPlayerEntry_Task;
class clsSaveData2D_Task;
struct stcTag;
struct stcSprite;

// total size: 0x8
struct stcExportInner {
    u16 u16Tag;    // offset 0x0, size 0x2
    u16 u16StrLen; // offset 0x2, size 0x2
    s8* pc8Name;   // offset 0x4, size 0x4
};

// total size: 0x8
struct stcExportAssets {
    u16 u16Num;                // offset 0x0, size 0x2
    u16 u16Padding;            // offset 0x2, size 0x2
    stcExportInner* psExInner; // offset 0x4, size 0x4
};

// total size: 0xC
struct stcImportAssets {
    u16 u16URLLen;             // offset 0x0, size 0x2
    u16 u16Num;                // offset 0x2, size 0x2
    s8* pc8URL;                // offset 0x4, size 0x4
    stcExportInner* psImInner; // offset 0x8, size 0x4
};

// total size: 0x8
struct stcDepthData {
    u32 u32DepthNo;     // offset 0x0, size 0x4
    u32 u32InstructNum; // offset 0x4, size 0x4
};

// Global enums — DWARF stores these at global scope
enum enmChildState {
    CHILD_STATE___MOVE_EX_00 = 0,
    CHILD_STATE___MOVE_EX_01 = 1,
    CHILD_STATE___MOVE_EX_02 = 2,
    CHILD_STATE___MOVE_EX_03 = 3,
    CHILD_STATE___MOVE_EX_04 = 4,
    CHILD_STATE___MOVE_EX_05 = 5,
    CHILD_STATE___MOVE_EX_06 = 6,
    CHILD_STATE___MOVE_EX_07 = 7,
    CHILD_STATE___MOVE_EX_08 = 8,
    CHILD_STATE___MOVE_EX_09 = 9,
    CHILD_STATE___MOVE_EX_10 = 10,
    CHILD_STATE___MOVE_EX_11 = 11,
    CHILD_STATE___MOVE_EX_12 = 12,
    CHILD_STATE___MOVE_EX_13 = 13,
    CHILD_STATE___MOVE_EX_14 = 14,
    CHILD_STATE___MOVE_EX_15 = 15,
    CHILD_STATE___MOVE_EX_16 = 16,
    CHILD_STATE___MOVE_EX_17 = 17,
    CHILD_STATE___MOVE_EX_18 = 18,
    CHILD_STATE___MOVE_EX_19 = 19,
    CHILD_STATE___MOVE_EX_MAX = 20,
    CHILD_STATE___NO_CHANGE = 21,
    CHILD_STATE___MOVE_NEXT = 22,
    CHILD_STATE___MOVE_BACK = 23,
};

enum enmHbMode {
    MODE___HEROES = 0,
    MODE___BABYLON = 1,
};

// total size: 0x20
class clsPfTexture : public clsOOTexture, public clsPfTextureBase {
public:
    virtual ~clsPfTexture() {}
    virtual void SetTexture(void* pvTex, bool bSetUp) { SetTexture_Base(pvTex, bSetUp); }
    virtual void SetDrawTexture(s32 s32Param1) {}
    virtual void* GetSize(s32 s32Param1) const { return GetSize_Base(s32Param1); }
};

// Flash sub-structs now in OOFlashParse.hpp (included above)

// total size: 0x8
struct stcDepthInfo {
    u32 u32DepthNum;           // offset 0x0, size 0x4
    stcDepthData* psDepthData; // offset 0x4, size 0x4
};

// total size: 0x14
struct stcSprite {
    stcDepthInfo sDepthInfo; // offset 0x0, size 0x8
    u16 u16CharacterID;      // offset 0x8, size 0x2
    u16 u16FrameCnt;         // offset 0xA, size 0x2
    u32 u32CtrlTagNum;       // offset 0xC, size 0x4
    stcSeqTag* psSeqTags;    // offset 0x10, size 0x4
};

// total size: 0x14
struct stcScene {
    stcDepthInfo sDepthInfo; // offset 0x0, size 0x8
    u32 u32FrameCnt;         // offset 0x8, size 0x4
    u32 u32CtrlTagNum;       // offset 0xC, size 0x4
    stcTag* psTags;          // offset 0x10, size 0x4
};

// total size: 0x58
struct stcFlash {
    stcFgbHeader sHeader;            // offset 0x0, size 0x34
    stcTag* psDefineTags;            // offset 0x34, size 0x4
    stcExportAssets* psExportAssets; // offset 0x38, size 0x4
    stcImportAssets* psImportAssets; // offset 0x3C, size 0x4
    stcSprite* psSprites;            // offset 0x40, size 0x4
    stcScene sScene;                 // offset 0x44, size 0x14
};

// total size: 0x68
struct stcFlashData {
    clsOOFlashPlayer* pcPlayer; // offset 0x0, size 0x4
    clsOOFlashMovie* pcMovie;   // offset 0x4, size 0x4
    clsPfTexture* pcTexture;    // offset 0x8, size 0x4
    stcFlash sFlash;            // offset 0xC, size 0x58
    void* pvLoFrame;            // offset 0x64, size 0x4
};

// total size: 0x8
struct stcSubFlashData {
    clsOOFlashPlayer* pcPlayer;      // offset 0x0, size 0x4
    clsOOFlashMovie* pcParrentMovie; // offset 0x4, size 0x4
};

// total size: 0x69C
class clsAdvertiseMgr_Task : public clsTask {
public:
    // Virtual functions
    virtual ~clsAdvertiseMgr_Task(); // [vtable slot 2]
    virtual void execute();          // [vtable slot 3]
    virtual void draw();             // [vtable slot 4]

    // Non-virtual member functions
    void drawUnLock();
    void drawUnLockInfo(u32 u32Param1,
                        u32 u32Param2,
                        s32 s32Param3,
                        s32 s32Param4,
                        s32 s32Param5,
                        s32 s32Param6,
                        u32 u32Param7);
    void drawUnLockWindow(
        s32 s32Param1, s32 s32Param2, s32 s32Param3, s32 s32Param4, u32 u32Param5);
    u8 checkUnLock();
    void drawShopModel(u8 u8Param1, f32 f32Param2);
    u32 callbackOption(void* pvParam1, u32 u32Param2, u32 u32Param3, u32 u32Param4);
    void drawTutorialStart(bool bParam1);
    void drawDiffFontData(
        u32 u32Param1, u32 u32Param2, s32 s32Param3, s32 s32Param4, s32 s32Param5, f32 f32Param6);
    void drawFontData(u32 u32Param1, s32 s32Param2, s32 s32Param3, s32 s32Param4, f32 f32Param5);
    void drawFontColor(f32 f32Param1, f32 f32Param2, f32 f32Param3, f32 f32Param4);
    void drawButtonForFlash();
    void checkTitleDemo(clsTask* pParam1);
    void jumpMode();
    void changeNextGearNo(bool bParam1, stcSendAdv& rParam2, bool bParam3);
    void drawSubFlashData(u32 u32Param1);
    void executeSubFlashData(u32 u32Param1);
    u8 isFlashData(u32 u32Param1);
    void drawFlashData(u32 u32Param1);
    void executeFlashData(u32 u32Param1);
    NNS_MOTION* getEntryMotion(u32 u32Param1, u32 u32Param2);
    void setEntryMotion(u32 u32Param1, u8* pParam2, u32* pParam3, u16 u16Param4, u32 u32Param5);
    void setEtcMenu();
    void setAddMenu();
    void setSelectStageAnime(bool bParam1, bool bParam2);
    void setModeSelectTutorial();
    void setTitleLogo();
    void setTitlePressButton();
    stcSubFlashData* getSubFlashData(u32 u32Param1);
    stcFlashData* getFlashData(u32 u32Param1);
    void setupFlashData(u32 u32Param1);
    void setFlashData(u32 u32Param1, stcBinInfo& rParam2);
    void setGearPartsTexture(stcBinInfo& rParam1);
    void setFlashTexture(u32 u32Param1, stcBinInfo& rParam2);
    void drawMorphBG();
    void setBGModel(stcBinInfo& rParam1);
    void setPackDataSub(u32 u32Param1, stcBinInfo& rParam2);
    void setPackData(stcBinInfo& rParam1);
    u8 jumpMoveSelect();
    void requestReadFile(u32 u32Param1);
    u8 openRequestFile(u32 u32Param1, u8 u8Param2);
    void releaseSubTexture(u32 u32Param1);
    void releasePack();
    void release();
    clsAdvertiseMgr_Task();

    // Inline functions (weak)
    void setStateNext() {}
    u32 getOldMenu() const { return m_u32OldMenu; }
    s32 getStageNo() const { return m_s8StageNo; }
    void reinitChildState() {}
    static void tsetSelectedMode(enmMode eMode) {}

    // Static members
    static enmMode m_teSelectedGameMode;
    static u32 tu32ResidenceTexSize;

    // Members
    u8 m_bStartMovieEnd;                          // offset 0x54, size 0x1
    u8* m_pu8PackBufHi;                           // offset 0x58, size 0x4
    void* m_pvTexListBufHi;                       // offset 0x5C, size 0x4
    _NNS_TEXLIST* m_psTexList;                    // offset 0x60, size 0x4
    enmChildState m_eChildState;                  // offset 0x64, size 0x4
    enmChildState m_eChildSubState;               // offset 0x68, size 0x4
    stcSendAdv m_sSendAdv[8];                     // offset 0x6C, size 0x20
    s8 m_s8StageNo;                               // offset 0x8C, size 0x1
    s8 m_s8LoadedStageNo;                         // offset 0x8D, size 0x1
    s8 m_s8PlayerNum;                             // offset 0x8E, size 0x1
    s8 m_s8UserNum;                               // offset 0x8F, size 0x1
    f32 m_f32TitleDemoTimer;                      // offset 0x90, size 0x4
    u8* m_pu8PackSubBufHi[10];                    // offset 0x94, size 0x28
    void* m_apvTexListSubBufHi[10];               // offset 0xBC, size 0x28
    u8* m_apu8FlashBufHi[11];                     // offset 0xE4, size 0x2C
    u8* m_apu8FontBufHi[6];                       // offset 0x110, size 0x18
    u8* m_pu8SaveDataFile;                        // offset 0x128, size 0x4
    _NNS_TEXLIST* m_apsTexListSub[10];            // offset 0x12C, size 0x28
    u32 m_u32OldMenu;                             // offset 0x154, size 0x4
    u32 m_u32CallBackReturnFrame;                 // offset 0x158, size 0x4
    s8 m_s8LoadShopSe_PortNo;                     // offset 0x15C, size 0x1
    u8 m_u8SelectPadNo;                           // offset 0x15D, size 0x1
    stcFlashData m_asFlashData[11];               // offset 0x160, size 0x478
    stcSubFlashData m_asSubFlashData[6];          // offset 0x5D8, size 0x30
    _NNS_TEXLIST* m_psGearPartsTexList;           // offset 0x608, size 0x4
    void* m_pvGearPartsTexListBufHi;              // offset 0x60C, size 0x4
    NNS_MOTION* m_apsUniEntryMotion[7];           // offset 0x610, size 0x1C
    NNS_MOTION* m_apsEggEntryMotion[7];           // offset 0x62C, size 0x1C
    NNS_MOTION* m_apsRoboEntryMotion[7];          // offset 0x648, size 0x1C
    clsModelType_OB_TX_MO_MA_MF* m_pcBGModel;     // offset 0x664, size 0x4
    clsModelType_OB_TX_MO_MA* m_pcShopChao_Model; // offset 0x668, size 0x4
    clsModelType_OB_TX_MO_MA* m_pcShopObj_Model;  // offset 0x66C, size 0x4
    _NNS_TEXLIST* m_psRTexList;                   // offset 0x670, size 0x4
    // TODO: m_eOldMode — DWARF says MODE_INIT=0/MODE_MAIN=1, but
    // enmMode is already declared in Game.hpp with GAME_MODE values. Resolve during
    // function implementation.
    enmMode m_eOldMode;        // offset 0x674, size 0x4
    enmHbMode m_eWgpMode;      // offset 0x678, size 0x4
    u32 m_u32UnlockMode;       // offset 0x67C, size 0x4
    f32 m_s32InfoMoveFrame;    // offset 0x680, size 0x4
    u32 m_u32UnlockInfoType;   // offset 0x684, size 0x4
    u32 m_u32UnlockInfoParam1; // offset 0x688, size 0x4
    u32 m_u32UnlockInfoParam2; // offset 0x68C, size 0x4
    u32 m_u32OldInfoType;      // offset 0x690, size 0x4
    u32 m_u32OldInfoParam1;    // offset 0x694, size 0x4
    u32 m_u32OldInfoParam2;    // offset 0x698, size 0x4
};

#endif // ADVERTISEMGR_HPP
