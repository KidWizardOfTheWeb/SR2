#ifndef PLAYERENTRY_HPP
#define PLAYERENTRY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlash.hpp"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsRaceLight_Task;      // pointer-only; no header yet
class clsReInitGraphics_Task; // pointer-only; forward-declared in BaseRace.hpp

namespace nspOOMisc {
// total size: 0x8
struct stcPoint2D_s32 {
    s32 s32x; // offset 0x0, size 0x4
    s32 s32y; // offset 0x4, size 0x4
};
} // namespace nspOOMisc

// total size: 0x14
struct stcEntryGearTypeData {
    f32 f32PosHeight;                   // offset 0x0, size 0x4
    nspOOMisc::stcPoint2D_s32 asRot[2]; // offset 0x4, size 0x10
};

// total size: 0xA4
struct stcEntryCharaTypeData {
    f32 f32Scale;                       // offset 0x0, size 0x4
    stcEntryGearTypeData asGearData[8]; // offset 0x4, size 0xA0
};

// total size: 0x10
struct stcEntryRoboTypeData {
    f32 f32Scale;                   // offset 0x0, size 0x4
    f32 f32PosHeight;               // offset 0x4, size 0x4
    nspOOMisc::stcPoint2D_s32 sRot; // offset 0x8, size 0x8
};

// total size: 0x8
struct stcEntryCharaStatus {
    u16 u16Dash;  // offset 0x0, size 0x2
    u16 u16Limit; // offset 0x2, size 0x2
    u16 u16Power; // offset 0x4, size 0x2
    u16 u16Curve; // offset 0x6, size 0x2
};

// total size: 0x30
struct stcGearLocalData {
    u32 u32GearNo;                      // offset 0x0, size 0x4
    f32 f32ScaleRate;                   // offset 0x4, size 0x4
    NNS_VECTOR asAddPos[2];             // offset 0x8, size 0x18
    nspOOMisc::stcPoint2D_s32 asRot[2]; // offset 0x20, size 0x10
};

// total size: 0x48
struct stcEntryLight {
    NNS_RGB sAmbColor;  // offset 0x0, size 0xC
    f32 f32Inten;       // offset 0xC, size 0x4
    NNS_RGBA sParColor; // offset 0x10, size 0x10
    NNS_VECTOR sParDir; // offset 0x20, size 0xC
    NNS_RGBA sSpeColor; // offset 0x2C, size 0x10
    NNS_VECTOR sSpeDir; // offset 0x3C, size 0xC
};

namespace nspPlayerEntry {
extern stcEntryLight EntryLight[2];
extern NNS_VECTOR DrawPosData[4][2];
extern f32 CharaHeightDiff[19];
extern stcEntryRoboTypeData EntryRoboData[2];
extern stcEntryCharaTypeData EntryModelData[3];
extern stcGearLocalData EntryGearLocalData[1];
extern u32 SelectCharaTbl[19];

void getModelData(u32 u32Param1,
                  clsGameMgr::stcSendAdv* psParam2,
                  f32** ppf32Param3,
                  NNS_VECTOR** ppsParam4,
                  nspOOMisc::stcPoint2D_s32** ppsParam5,
                  f32** ppf32Param6,
                  f32** ppf32Param7,
                  f32* pf32Param8,
                  NNS_VECTOR* psParam9,
                  bool bParam10);
} // namespace nspPlayerEntry

// total size: 0x1E4
class clsPlayerEntry_Task : public clsTask {
public:
    // total size: 0x5C
    // Note: mangled as clsPlayerEntry_Task::stcUserSelect in function signatures;
    // also emitted as a standalone DWARF struct — treat as nested for MWCC compat.
    struct stcUserSelect {
        u8 u8Mode;                // offset 0x0, size 0x1
        u8 u8CharaNo;             // offset 0x1, size 0x1
        u16 u16Flg;               // offset 0x2, size 0x2
        u16 u16StatusCnt;         // offset 0x4, size 0x2
        u16 u16StatusNum;         // offset 0x6, size 0x2
        u32 u32GearFrame;         // offset 0x8, size 0x4
        u32 u32GearWindowFrame;   // offset 0xC, size 0x4
        f32 f32GearFloat;         // offset 0x10, size 0x4
        s32 s32RoboRot;           // offset 0x14, size 0x4
        u32 u32TeamNum;           // offset 0x18, size 0x4
        u32 u32ModelLoadIdx;      // offset 0x1C, size 0x4
        void* pvModelBuf;         // offset 0x20, size 0x4
        void* pvModelTexBuf;      // offset 0x24, size 0x4
        void* pvGearBuf;          // offset 0x28, size 0x4
        void* pvGearTexBuf[4];    // offset 0x2C, size 0x10
        f32 f32MotionFrame;       // offset 0x3C, size 0x4
        NNS_MOTION* psMotion;     // offset 0x40, size 0x4
        f32 (*psNnMtxList)[4][4]; // offset 0x44, size 0x4
        f32 (*psNnMtxPal)[4][4];  // offset 0x48, size 0x4
        u32* psNnNodeStatus;      // offset 0x4C, size 0x4
        s32 s32MtxListNum;        // offset 0x50, size 0x4
        s32 s32MtxPalNum;         // offset 0x54, size 0x4
        s32 s32NodeStatusNum;     // offset 0x58, size 0x4
    };

    virtual ~clsPlayerEntry_Task() {}
    virtual void execute();
    virtual void draw();

    clsPlayerEntry_Task(clsAdvertiseMgr_Task* pcAdv, u32 u32A, u32 u32B);

    void Pack2SetLocal(void* pv, u32 u32A, u32 u32B);
    void loadGearModels(u32 u32Idx, stcBinInfo& rcBin);
    void checkReadFile(u32 u32Idx);
    void returnMode();
    void setupNextMode();
    void drawLockCharater();
    void drawPrepare();
    void drawGearInfo(u32 u32Idx, stcPlaceObject2* psObj);
    void drawModel(u32 u32Idx);
    void drawStatus(u32 u32Idx);
    void drawUser(u32 u32Idx);

    void mallocMtxBuffer(stcUserSelect* psUser) {}
    void releaseMtxBuffer(stcUserSelect* psUser) {}
    void changeNextGearNo(bool bFlg, stcSendAdv& rcAdv, u32 u32Idx, stcSendAdv* psAdv) {}
    void checkControlerOff(u32 u32Idx) {}
    u8 execModeWait(u32 u32Idx) { return 0; }
    u8 execModeChara(u32 u32Idx) { return 0; }
    u8 execModeTeamWait(u32 u32Idx) { return 0; }
    u8 execModeTeamGearWait(u32 u32Idx) { return 0; }
    u8 execModeGear(u32 u32Idx) { return 0; }
    u8 execModeGearStatus(u32 u32Idx) { return 0; }
    u8 execModeResult(u32 u32Idx) { return 0; }

    static stcSendAdv m_tasUserSendAdv[4];

    u32 m_u32AllFlg;                             // offset 0x54, size 0x4
    u32 m_u32PlayerMax;                          // offset 0x58, size 0x4
    u32 m_u32UserNum;                            // offset 0x5C, size 0x4
    u32 m_u32UserMax;                            // offset 0x60, size 0x4
    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x64, size 0x4
    stcFlashData* m_psFlashData;                 // offset 0x68, size 0x4
    stcUserSelect m_asUserSelect[4];             // offset 0x6C, size 0x170
    clsRaceLight_Task* m_pcLightTask;            // offset 0x1DC, size 0x4
    clsReInitGraphics_Task* m_pcReInitTask;      // offset 0x1E0, size 0x4
};

#endif // PLAYERENTRY_HPP
