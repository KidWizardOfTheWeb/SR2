#include "usr/local/sega/px/src/px.h"

struct tagPXS_PUSHBUFFER* pxgPrimaryPB; // size: 0x4, address: 0x6D1F04
struct tagPXS_PUSHBUFFER* pxgCurrentPB; // size: 0x4, address: 0x6D1F08

struct tagPXS_PUSHBUFFER pxgPBWork; // size: 0xA0, address: 0x6E65D0

static const char __license_string__[] =
    "\xa0\xb0\x40\x5a\x40\x98\xde\xee\x40\x98\xca\xec\xca\xd8\x40\x8e\xe4\xc2\xe0\xd0\xd2\xc6\xe6"
    "\x40\x98\xd2\xc4\xe4\xc2\xe4\xf2\x40\xcc\xde\xe4\x40\xa0\xd8\xc2\xf2\xa6\xe8\xc2\xe8\xd2\xde"
    "\xdc\x50\xa4\x52\x64\x40\x5a\x14";
static char* const pxgVersion = "\nPX Ver.1.46.07 Build:Jun  2 2006 18:45:32\n";

const char* __license_string_ptr__;

const char* pxgVersionPtr;

signed int pxgGsHandlerID;
struct PXS_INITPARAM pxgInitParam;

unsigned int pxgRenderDmaBusy;
unsigned int pxgRenderFlag;

enum PXE_ERR PXInit(struct PXS_INITPARAM* iprm)
{
    struct PXS_PRMODESET prmode;
    unsigned int flag = 2;

    __license_string_ptr__ = __license_string__;
    pxgVersionPtr = pxgVersion;

    pxgInitParam.tagSize = iprm->tagSize;
    pxgInitParam.dataSize = iprm->dataSize;
    pxgInitParam.pushBuffer = iprm->pushBuffer;
    pxgInitParam.bufSize = iprm->bufSize;
    pxgInitParam.chainSize = iprm->chainSize;
    pxgInitParam.chainBuffer = iprm->chainBuffer;
    pxgInitParam.pushBufferMax = iprm->pushBufferMax;
    pxgInitParam.flag = iprm->flag;

    if (pxgInitParam.flag & 0x200) {
        flag |= 0x200;
    }
    flag = (unsigned int)PXSetupPB(
        &pxgPBWork, iprm->tagSize, iprm->dataSize, iprm->pushBuffer, iprm->bufSize, flag);
    pxgPrimaryPB = (struct tagPXS_PUSHBUFFER*)flag;
    if (flag == 0) {
        return PXE_ERR_INVALIDARG;
    }
    pxgCurrentPB = (struct tagPXS_PUSHBUFFER*)flag;
    memset(pxgLightMatrix, 0, 0x80);
    PXPutClipParam(PXE_CULL_NONE);
    PXSetupPrimMode(&prmode, 0x18, 0x18);
    PXPutPrimMode(&prmode);
    PXPutMaterial(&pxgDefaultMaterial);
    PXPutMaterial2(&pxgDefaultMaterial);
    PXInitContext(PXE_CTX1);
    PXInitContext(PXE_CTX2);
    pxgGsGuardBand = 2040.0f;
    PXInitSubShaderParam();
    PXPutSubShaderParam();
    PXSetAmbientColor(1.0f, 1.0f, 1.0f, 1.0f);
    // TODO: Fix the fake match, error in the splits, no .vutext splits it seems
    //  PXPutCustomShader((void *)&pxgVuCode_Scissor);
    PXPutCustomShader((void*)&D_005A44E0);
    // D_005A44E0 should be pxgVuCode_Scissor
    PXMakeScreenParam(&pxgScreenParam, 320.0f, -112.0f, 2048.0f, 2048.0f, 1.6777215e7f, 0.0f);
    PXPutScreenParam(&pxgScreenParam);
    PXPutVifMask();
    PXPutReg(0x46, 1);
    PXPutReg(0x49, 0);
    PXPutReg(0x1A, 0);
    pxgDmaStartCallback = NULL;
    pxgRenderCallback = NULL;
    pxgRenderCallbackArg = NULL;
    REG_GIF_MODE = 4;
    flag = iprm->flag & 0x700;

    if (flag != 0) {
        PXInitInterrupt(flag);
    }

    return PXE_ERR_OK;
}

signed int PXGsInterruptHandler(signed int ca)
{
}

void PXInitInterrupt(unsigned int flag)
{
}

void PXExit()
{
    int flg;
    if (pxgInitParam.flag & 0x700) {
        flg = DIntr();
        pxgRenderDmaBusy = 0;
        RemoveIntcHandler(0, pxgGsHandlerID);
        sceGsPutIMR(sceGsGetIMR() | 0x300);
        DisableIntc(0);
        if (flg) {
            EIntr();
        }
    }
}

enum PXE_ERR PXRender(unsigned int flag)
{
    pxgRenderFlag = flag;
    PXRenderPB(pxgCurrentPB, pxgRenderFlag);
}

void* PXBegin(unsigned int flag)
{
    PXBeginPB(pxgCurrentPB, flag);
}

void PXEnd(void* p)
{
    PXEndPB(pxgCurrentPB, p);
}

void PXPutReg(unsigned int addr, unsigned long data)
{
    PXPutRegPB(pxgCurrentPB, addr, data);
}

void PXPutCustomShader(void* addr)
{
    PXPutShaderPB(pxgCurrentPB, addr);
}

void PXStartShader()
{
    PXStartShaderPB(pxgCurrentPB);
}

void PXPutCall(void* addr)
{
    PXPutCallPB(pxgCurrentPB, addr);
}

void PXPutRef(void* addr, unsigned int qwc, unsigned int flag)
{
    PXPutRefPB(pxgCurrentPB, addr, qwc, flag);
}

void* PXBeginPrim(void* addr, unsigned int vertices, unsigned int stride, unsigned int prim)
{
    PXBeginPrimPB(pxgCurrentPB, addr, vertices, stride, prim);
}

void* PXEndPrim(void* addr)
{
    PXEndPrimPB(pxgCurrentPB, addr);
}

void PXPutVifMask()
{
    unsigned int* p;

    /* scope { */
    p = PXBeginPB(pxgCurrentPB, 1);
    p[0] = 0x30000000;
    p[1] = 0xaaaaaaaa;
    p[2] = 0xbbbbbbbb;
    p[3] = 0x3f800000;
    p[4] = 0x3f800000;
    p[5] = 0x31000000;
    p[6] = 0x66666666;
    p[7] = 0x77777777;
    p[8] = 0x88888888;
    p[9] = 0x99999999;
    p[10] = 0;
    p[0xb] = 0;
    PXEndPB(pxgCurrentPB, p + 0xc);
}
