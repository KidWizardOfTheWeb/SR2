#include "Develop/Projects/SR2/pgm/src/Script/Script.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"

static c8 oac8LangTypeName[2] = {'J', 'F'};
static stcScriptBurnOut osBurnOutBase;
static stcScriptBurnOut osBurnOutTbl[1];
c8* ac8CodeName[114];

static void draw_HeapDetail(s32 s32xI, s32& rs32yI, clsOOHeapFragment* pcOOHeapI)
{
}

void (*clsScript_Task::m_oascodeFunc[114])(u8*, clsScript_Task*);
u8* clsScript_Task::m_pu8DataBuf;
s32 clsScript_Task::m_ts32DrawModelNum;

void clsScript_Task::initLightStatus(stcLight* psLight)
{
}

void clsScript_Task::codePrint(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeDispStrBackFrame(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeStartFrameBufTex(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeEndFrameBufTex(u8* pcTask, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeShowFrameBufTex(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeChangeFrameBufTexPos(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeCopyFrameBufTex(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeChangeCopyFrameBufTexPos(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::setSunLenz()
{
}

void clsScript_Task::codeInitHishakai(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeYuragi(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeHishakaiZ(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeChangeLineEffectMov(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::setNegaStatus(
    u8 u8Pri, u8 u8Type, u8 u8rgb, f32 f32Frame, f32 f32SubFrame, f32 f32EndFrame, f32 f32WaitFrame)
{
}

void clsScript_Task::setNegaEndStatus(s16 s16Frame)
{
}

clsScript_Task::clsScript_Task(s32 s32No, u8 u8ModeType) : clsTask(0, 0)
{
}

void clsScript_Task::codeOptionMot(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeLastBgm(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::setWaveStatus(u32 u32Pri, f32 f32Frame, f32 f32WaitFrame)
{
}

clsScript_Task::~clsScript_Task()
{
}

void clsScript_Task::setBlurStatus(u8 u8Type,
                                   u8 u8a,
                                   u8 u8Sa,
                                   u8 u8Ea,
                                   f32 f32Per,
                                   f32 f32SPer,
                                   f32 f32EPer,
                                   f32 f32GFrame,
                                   f32 f32WaitFrame,
                                   f32 f32FadeFrame)
{
}

void clsScript_Task::setBlurEndStatus(s16 s16Frame)
{
}

void clsScript_Task::setBinaryData(u8* pu8Buf)
{
}

void clsScript_Task::unusedFunc(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeCut(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeFastStart(u8* pcTask, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeCutPlay(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeLightAmbient(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeLightPara(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeLightParaInten(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeLightParaDir(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeLightSpe(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeLightSpeDir(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeLightData(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeLightDisp(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeSetSunLenz(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeStopSunLenz(u8* pcTask, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeFogColor(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeFogRange(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeFogSwitch(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeWait(u8* pcTask, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeWaitButton(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeFrameWait(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeAllPlayModelCamera(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeFade(u8* pu8Ptr, clsScript_Task* pcTask)
{
}

void clsScript_Task::codeJump(u8* pcParam1, clsScript_Task* pParam2)
{
}

void clsScript_Task::codeSwapBuf(u8* pcTask, clsScript_Task* pParam2)
{
}

u8 clsScript_Task::checkEnd()
{
    return 0;
}

u8 clsScript_Task::checkFileRead()
{
    return 0;
}

void clsScript_Task::startInit()
{
}

void clsScript_Task::execute()
{
}

void clsScript_Task::draw()
{
}

s32 clsScript_Task::Heap(s32 s32xI, s32 s32yI, s32 s32ActiveNoI, s32 s32Param4)
{
    return 0;
}

s32 clsScript_Task::ScriptInfo(s32 s32xI, s32 s32yI, s32 s32ActiveNoI, s32 s32Param4)
{
    return 0;
}
