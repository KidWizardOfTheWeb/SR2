#ifndef SCRIPT_HPP
#define SCRIPT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Fade.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Blur.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Fog.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Nega.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Wave.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptBlur.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptGravityWave.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptLight.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptMemory.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptModelManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptShadow.hpp"

class clsPfScriptHeap;
class clsScriptCamera;
class clsScriptCameraFrameTex_Task;
class clsScriptCreateFrameTex_Task;
class clsScriptDrawFrameTex_Task;
class clsSunLenz_Task;

// total size: 0x5
struct stcScriptInfo {
    u8 bFrame;     // offset 0x0, size 0x1
    u8 bBlur;      // offset 0x1, size 0x1
    u8 bNega;      // offset 0x2, size 0x1
    u8 bWave;      // offset 0x3, size 0x1
    u8 bMemoryBar; // offset 0x4, size 0x1
};

// total size: 0x2C
struct stcScriptStatus {
    u32 u32Flg;             // offset 0x0, size 0x4
    s32 s32CutNo;           // offset 0x4, size 0x4
    s32 s32NextCutNo;       // offset 0x8, size 0x4
    s32 s32CodeNo;          // offset 0xC, size 0x4
    s32 s32CodeMax;         // offset 0x10, size 0x4
    f32 f32SceneFrame;      // offset 0x14, size 0x4
    f32 f32CutFrame;        // offset 0x18, size 0x4
    f32 f32CutEndFrame;     // offset 0x1C, size 0x4
    f32 f32NextCutEndFrame; // offset 0x20, size 0x4
    s16 s16WaitCnt;         // offset 0x24, size 0x2
    s16 s16WaitFrame;       // offset 0x26, size 0x2
    u32 u32WaitButton;      // offset 0x28, size 0x4
};

// total size: 0x10
struct tagstcScriptData {
    u16 u16Size;     // offset 0x0, size 0x2
    u16 u16Att;      // offset 0x2, size 0x2
    u32 u32Num;      // offset 0x4, size 0x4
    u8 u8Padding[8]; // offset 0x8, size 0x8
};

// total size: 0x100
struct tagstcScriptFuncLineData {
    u32 u32FunctionType;               // offset 0x0, size 0x4
    u32 u32Att;                        // offset 0x4, size 0x4
    u8 u8Padding[8];                   // offset 0x8, size 0x8
    tagstcScriptData sArgumentsDt[15]; // offset 0x10, size 0xF0
};

// total size: 0x98
struct stcScriptBinaryHeader {
    u8 u8BigEndian;                             // offset 0x0, size 0x1
    u8 u8Ver;                                   // offset 0x1, size 0x1
    u8 u8Id[6];                                 // offset 0x2, size 0x6
    u16 u16MotDivMax[20];                       // offset 0x8, size 0x28
    u16 u16MatDivMax[20];                       // offset 0x30, size 0x28
    u16 u16MorfDivMax[20];                      // offset 0x58, size 0x28
    u16 u16FileDivNum;                          // offset 0x80, size 0x2
    u16 u16MotionMax;                           // offset 0x82, size 0x2
    u16 u16MaterialMax;                         // offset 0x84, size 0x2
    u16 u16MorfMax;                             // offset 0x86, size 0x2
    u16 u16MallocDataNum;                       // offset 0x88, size 0x2
    u8 u8Pad[6];                                // offset 0x8A, size 0x6
    u32 u32Num;                                 // offset 0x90, size 0x4
    tagstcScriptFuncLineData* ppScriptFuncLine; // offset 0x94, size 0x4
};

// total size: 0x20
struct stcScriptCode {
    u32 u32Code;    // offset 0x0, size 0x4
    u32 au32Pad[7]; // offset 0x4, size 0x1C
};

// total size: 0x4
struct stcScriptBurnOut {
    u8 u8EventNo;     // offset 0x0, size 0x1
    u8 u8EraseAlpha;  // offset 0x1, size 0x1
    u8 u8EraseColor;  // offset 0x2, size 0x1
    u8 u8PathDrawNum; // offset 0x3, size 0x1
};

// total size: 0x8B0
class clsScript_Task : public clsTask {
public:
    clsScript_Task(s32 s32No, u8 u8ModeType);
    virtual ~clsScript_Task();
    virtual void execute();
    virtual void draw();

    void initLightStatus(stcLight* psLight);
    void codePrint(u8* pcParam1, clsScript_Task* pParam2);
    void codeDispStrBackFrame(u8* pcParam1, clsScript_Task* pParam2);
    void codeStartFrameBufTex(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeEndFrameBufTex(u8* pcTask, clsScript_Task* pParam2);
    void codeShowFrameBufTex(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeChangeFrameBufTexPos(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeCopyFrameBufTex(u8* pcParam1, clsScript_Task* pParam2);
    void codeChangeCopyFrameBufTexPos(u8* pu8Ptr, clsScript_Task* pcTask);
    void setSunLenz();
    void codeInitHishakai(u8* pcParam1, clsScript_Task* pParam2);
    void codeYuragi(u8* pcParam1, clsScript_Task* pParam2);
    void codeHishakaiZ(u8* pcParam1, clsScript_Task* pParam2);
    void codeChangeLineEffectMov(u8* pcParam1, clsScript_Task* pParam2);
    void setNegaStatus(u8 u8Pri,
                       u8 u8Type,
                       u8 u8rgb,
                       f32 f32Frame,
                       f32 f32SubFrame,
                       f32 f32EndFrame,
                       f32 f32WaitFrame);
    void setNegaEndStatus(s16 s16Frame);
    void codeOptionMot(u8* pcParam1, clsScript_Task* pParam2);
    void codeLastBgm(u8* pcParam1, clsScript_Task* pParam2);
    void setWaveStatus(u32 u32Pri, f32 f32Frame, f32 f32WaitFrame);
    void setBlurStatus(u8 u8Type,
                       u8 u8a,
                       u8 u8Sa,
                       u8 u8Ea,
                       f32 f32Per,
                       f32 f32SPer,
                       f32 f32EPer,
                       f32 f32GFrame,
                       f32 f32WaitFrame,
                       f32 f32FadeFrame);
    void setBlurEndStatus(s16 s16Frame);
    void setBinaryData(u8* pu8Buf);
    void unusedFunc(u8* pcParam1, clsScript_Task* pParam2);
    void codeCut(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeFastStart(u8* pcTask, clsScript_Task* pParam2);
    void codeCutPlay(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeLightAmbient(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeLightPara(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeLightParaInten(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeLightParaDir(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeLightSpe(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeLightSpeDir(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeLightData(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeLightDisp(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeSetSunLenz(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeStopSunLenz(u8* pcTask, clsScript_Task* pParam2);
    void codeFogColor(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeFogRange(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeFogSwitch(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeWait(u8* pcTask, clsScript_Task* pParam2);
    void codeWaitButton(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeFrameWait(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeAllPlayModelCamera(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeFade(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeJump(u8* pcParam1, clsScript_Task* pParam2);
    void codeSwapBuf(u8* pcTask, clsScript_Task* pParam2);
    u8 checkEnd();
    u8 checkFileRead();
    void startInit();
    s32 Heap(s32 s32xI, s32 s32yI, s32 s32ActiveNoI, s32 s32Param4);
    s32 ScriptInfo(s32 s32xI, s32 s32yI, s32 s32ActiveNoI, s32 s32Param4);

    static void (*m_oascodeFunc[114])(u8*, clsScript_Task*);
    static u8* m_pu8DataBuf;
    static s32 m_ts32DrawModelNum;

    clsResidenceEffect cResidenceEffect;               // offset 0x54, size 0x704
    u8 m_bSwapDataRead;                                // offset 0x758, size 0x1
    s8 m_s8SwapDataMode;                               // offset 0x759, size 0x1
    u8 m_u8SwapReadMode;                               // offset 0x75A, size 0x1
    u8 m_u8SwapReadCnt;                                // offset 0x75B, size 0x1
    s16 m_s16SwapDataNo;                               // offset 0x75C, size 0x2
    clsScriptBlur_Task* m_pcBlurTask;                  // offset 0x760, size 0x4
    clsScriptNega_Task* m_pcNegaTask;                  // offset 0x764, size 0x4
    clsScriptWave_Task* m_pcWaveTask;                  // offset 0x768, size 0x4
    clsSunLenz_Task* m_pcSunLenz;                      // offset 0x76C, size 0x4
    clsPfScriptHeap* m_pcScriptHeap;                   // offset 0x770, size 0x4
    clsScriptLight* m_pcLight;                         // offset 0x774, size 0x4
    clsScriptCameraFrameTex_Task* m_pcCameraFrameTex;  // offset 0x778, size 0x4
    clsScriptCreateFrameTex_Task* m_pcCreateFrameTask; // offset 0x77C, size 0x4
    clsScriptDrawFrameTex_Task* m_pcDrawFrameTexTask;  // offset 0x780, size 0x4
    clsScriptShadowMgr_Task* m_pcShadowMgrTask;        // offset 0x784, size 0x4
    u8* m_pu8DataPtr;                                  // offset 0x788, size 0x4
    void* m_pvFreeLoFrame;                             // offset 0x78C, size 0x4
    stcScriptStatus m_sStatus;                         // offset 0x790, size 0x2C
    stcLight m_asLightStatus[1];                       // offset 0x7BC, size 0x48
    stcSunLenz m_asSunLenzStatus[1];                   // offset 0x804, size 0x14
    stcNega m_asNegaStatus[1];                         // offset 0x818, size 0x18
    stcFade m_asFadeStatus[1];                         // offset 0x830, size 0x14
    stcWave m_asWaveStatus[1];                         // offset 0x844, size 0x10
    stcBlur m_asBlurStatus[1];                         // offset 0x854, size 0x20
    stcFog m_asFogStatus[1];                           // offset 0x874, size 0x24
    clsScriptCamera* m_pcCamera;                       // offset 0x898, size 0x4
    clsScriptModelManager m_cModelManager;             // offset 0x89C, size 0x4
    clsScriptMemory m_cMemory;                         // offset 0x8A0, size 0x1
    s32 m_s32EventNo;                                  // offset 0x8A4, size 0x4
    u8 m_u8StopCutNo;                                  // offset 0x8A8, size 0x1
    u8 m_u8ModeType;                                   // offset 0x8A9, size 0x1
    s8 m_s8MesLanguage;                                // offset 0x8AA, size 0x1
    s8 m_s8VoiceLanguage;                              // offset 0x8AB, size 0x1
    u8 m_bGravityWave;                                 // offset 0x8AC, size 0x1
};

#endif // SCRIPT_HPP
