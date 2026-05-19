#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OODebugMenu.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreMap2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/DataSize.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/DebugGrind.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/DebugMiniWave.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/DrawCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/GDTrainData.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/Item.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/PointPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/TaskProfile.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/TurbulenceDbg.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Nega.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleData.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/BurnOut/PS2_BurnOut.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/BitFlag.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/PendulumControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/Script.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptBlur.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptGravityWave.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptLight.hpp"
#include "Develop/Projects/SR2/pgm/src/System/DrawCamera.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Camera/nncamera.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

class clsRainDrops_Task;

// total size: 0x6
struct stcModelViewerParticle {
    u16 u16Mode;      // offset 0x0, size 0x2
    u16 u16Check;     // offset 0x2, size 0x2
    u16 u16LoopCheck; // offset 0x4, size 0x2
};

// total size: 0x70
class clsModelViewerCamera {
public:
    void* m_pvBuf;                 // offset 0x0, size 0x4
    u32 m_u32Flg;                  // offset 0x4, size 0x4
    f32 m_f32Frame;                // offset 0x8, size 0x4
    f32 m_f32DrawSize;             // offset 0xC, size 0x4
    NNS_MOTION* m_psMotion;        // offset 0x10, size 0x4
    f32 m_sDrawMtx[4][4];          // offset 0x20, size 0x40
    NNS_CAMERAPTR* m_psDataPtr;    // offset 0x60, size 0x4
    NNS_CAMERAPTR* m_psCalcCamera; // offset 0x64, size 0x4
};

// total size: 0x70
class clsModelViewerLight {
public:
    void* m_pvBuf;               // offset 0x0, size 0x4
    u32 m_u32No;                 // offset 0x4, size 0x4
    u32 m_u32Flg;                // offset 0x8, size 0x4
    f32 m_f32Frame;              // offset 0xC, size 0x4
    NNS_MOTION* m_psMotion;      // offset 0x10, size 0x4
    f32 m_sDrawMtx[4][4];        // offset 0x20, size 0x40
    f32 m_f32DrawSize;           // offset 0x60, size 0x4
    NNS_LIGHTPTR* m_psDataPtr;   // offset 0x64, size 0x4
    NNS_LIGHTPTR* m_psCalcLight; // offset 0x68, size 0x4
};

// total size: 0xBC
class clsModelViewer_Task : public clsTask {
public:
    void* m_apv8BinBuffer[6];             // offset 0x54, size 0x18
    s8 m_s8CursorPos;                     // offset 0x6C, size 0x1
    void* m_pvFreeLoFrame;                // offset 0x70, size 0x4
    NNS_VECTOR m_sParticleTarget;         // offset 0x74, size 0xC
    void* m_pvParticleData;               // offset 0x80, size 0x4
    void* m_pvParticleTexture;            // offset 0x84, size 0x4
    clsModelType_OB_TX_MO_MA_MF m_cModel; // offset 0x88, size 0x34
};

// total size: 0x50
struct stcBurnOut {
    NNS_VECTOR sRandSp;            // offset 0x0, size 0xC
    NNS_VECTOR sBeginSp;           // offset 0xC, size 0xC
    NNS_VECTOR sLocalPos;          // offset 0x18, size 0xC
    NNS_VECTOR sLocalPosRandRange; // offset 0x24, size 0xC
    f32 f32GroundK;                // offset 0x30, size 0x4
    f32 f32AirK;                   // offset 0x34, size 0x4
    f32 f32Mass;                   // offset 0x38, size 0x4
    u32 u32MaxLifeFrame;           // offset 0x3C, size 0x4
    u8 u8Num;                      // offset 0x40, size 0x1
    s8 s8TextureNo;                // offset 0x41, size 0x1
    u8 u8Size;                     // offset 0x42, size 0x1
    u8 bPers;                      // offset 0x43, size 0x1
    f32 f32ColiY;                  // offset 0x44, size 0x4
    f32 f32MaxClipZ;               // offset 0x48, size 0x4
    u8 bAllDelete;                 // offset 0x4C, size 0x1
};

// total size: 0x4
struct stcRaceTime {
    u8 u8Minutes; // offset 0x0, size 0x1
    u8 u8Sec;     // offset 0x1, size 0x1
    u16 u16MSec;  // offset 0x2, size 0x2
};

// total size: 0x1BEA
struct stcComTime {
    u8 bEnableComDebug;             // offset 0x0, size 0x1
    u16 au16StackNum[8];            // offset 0x2, size 0x10
    u8 au8LeaderRank[8][99];        // offset 0x12, size 0x318
    stcRaceTime asRoundTime[8][99]; // offset 0x32A, size 0xC60
    stcRaceTime asDelayTime[8][99]; // offset 0xF8A, size 0xC60
};

// total size: 0x10
struct stcDFieldDbg {
    f32 f32Dist;                  // offset 0x0, size 0x4
    u32 u32Size;                  // offset 0x4, size 0x4
    u8 u8View;                    // offset 0x8, size 0x1
    u8 u8PlayerNo;                // offset 0x9, size 0x1
    clsRainDrops_Task* pcRD_Task; // offset 0xC, size 0x4
};

// total size: 0x28
struct stcEseLoadingCircle {
    NNS_VECTOR sCurRot;  // offset 0x0, size 0xC
    NNS_VECTOR sAddRot;  // offset 0xC, size 0xC
    NNS_VECTOR sBaseRot; // offset 0x18, size 0xC
    f32 f32Scale;        // offset 0x24, size 0x4
};

// total size: 0x84
struct stcDraw2D {
    u32 u32Page;                 // offset 0x0, size 0x4
    u8 bHide;                    // offset 0x4, size 0x1
    u8 bSafeArea;                // offset 0x5, size 0x1
    u8 bUnSafeArea;              // offset 0x6, size 0x1
    u8 bCenterLine;              // offset 0x7, size 0x1
    u8 b2DAreaInfo;              // offset 0x8, size 0x1
    u8 bNowLoading;              // offset 0x9, size 0x1
    stcEseLoadingCircle sRed;    // offset 0xC, size 0x28
    stcEseLoadingCircle sYellow; // offset 0x34, size 0x28
    stcEseLoadingCircle sBlue;   // offset 0x5C, size 0x28
};

// total size: 0x1F94
class clsDebug : public clsSingleton<clsDebug> {
public:
    enum enmRet {
        // Note: local DWARF body collides with nspOOFileMgr::enmRet.
        VISIBLE_CLIP = 0,
        VISIBLE = 1,
        OUT_VISIBLE = 2,
        OUT_PORTAL = 3,
        OUT_FAR = 4,
    };

    // total size: 0x1C
    struct stcBlur {
        u8 bUsed;         // offset 0x0, size 0x1
        u8 bEnd;          // offset 0x1, size 0x1
        u8 u8Type;        // offset 0x2, size 0x1
        u8 u8Alpha;       // offset 0x3, size 0x1
        u8 u8SAlpha;      // offset 0x4, size 0x1
        u8 u8EAlpha;      // offset 0x5, size 0x1
        s16 s16EndFrame;  // offset 0x6, size 0x2
        f32 f32Per;       // offset 0x8, size 0x4
        f32 f32SPer;      // offset 0xC, size 0x4
        f32 f32EPer;      // offset 0x10, size 0x4
        f32 f32GFrame;    // offset 0x14, size 0x4
        f32 f32WaitFrame; // offset 0x18, size 0x4
    };

    clsDebug();
    virtual ~clsDebug() {}

    void reinitMenu();
    void exec();
    u8 isDebugCamera(u32 u32Param1) { return m_au8IsDebugMode[u32Param1]; }

    static stcGimmick m_sGimmick;

    u8 m_au8DisableDrawPlayer[8];              // offset 0x4, size 0x8
    s32 m_s32ShimmerZ;                         // offset 0xC, size 0x4
    u8 m_u8ShimmerA;                           // offset 0x10, size 0x1
    clsOODebugMenu m_cOOMenu;                  // offset 0x14, size 0x38
    clsModelViewer_Task* m_pcModelViewer_Task; // offset 0x4C, size 0x4
    stcBitFlag m_sBitFlag;                     // offset 0x50, size 0x4
    stcBlur m_sBlur;                           // offset 0x54, size 0x1C
    stcBurnOutSystem m_sBurnOutSystem;         // offset 0x70, size 0x3
    stcBurnOut m_sBurnOut;                     // offset 0x74, size 0x50
    stcDraw2D m_sDraw2D;                       // offset 0xC4, size 0x84
    stcParticle m_sParticle;                   // offset 0x148, size 0x14
    stcDrawCollision m_sDrawCollision;         // offset 0x15C, size 0x5
    stcDrawCamera m_sDrawCamera;               // offset 0x161, size 0x6
    stcTurbulenceDbg m_sTurbDbg;               // offset 0x167, size 0x5
    stcDFieldDbg m_sDFDbg;                     // offset 0x16C, size 0x10
    stcDrawPath m_sDrawPath;                   // offset 0x17C, size 0x2B
    stcDebugGrind m_sGrind;                    // offset 0x1A8, size 0x10
    stcDebugMiniWave m_sMiniWave;              // offset 0x1B8, size 0x2C
    stcPointPath m_sPointPath;                 // offset 0x1E4, size 0x4
    stcFollowLine m_asFollowLine[4];           // offset 0x1E8, size 0x100
    stcPendulum m_sPendulum;                   // offset 0x2E8, size 0x28
    stcScriptInfo m_sScriptInfo;               // offset 0x310, size 0x5
    stcScriptBlur m_sScriptBlur;               // offset 0x318, size 0x18
    stcScriptNega m_sScriptNega;               // offset 0x330, size 0x14
    stcScriptWave m_sScriptWave;               // offset 0x344, size 0xC
    stcDataSize m_sDataSize;                   // offset 0x350, size 0x18
    stcGDTrainData m_sGDTrainDbg;              // offset 0x368, size 0x5
    stcNegaZ m_sNegaZ;                         // offset 0x370, size 0x8
    stcComTime m_sComTime;                     // offset 0x378, size 0x1BEA
    stcItem m_sItem;                           // offset 0x1F62, size 0x4
    u8* m_pu8MapBuffer;                        // offset 0x1F68, size 0x4
    enmRet m_eStageBinBuffer_Ret;              // offset 0x1F6C, size 0x4
    s32 m_s32FollowLineNo;                     // offset 0x1F70, size 0x4
    stcTaskProfile m_sTaskProfile;             // offset 0x1F74, size 0x14
    s16 m_s16DivMap_DrawFlg;                   // offset 0x1F88, size 0x2
    u8 m_u8DivMap_DrawType;                    // offset 0x1F8A, size 0x1
    u8 m_u8FlushDebugLine;                     // offset 0x1F8B, size 0x1
    u8 m_au8IsDebugMode[5];                    // offset 0x1F8C, size 0x5
};

#endif // DEBUG_HPP
