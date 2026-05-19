#include "usr/local/sega/px/src/px.h"
#include "usr/local/sega/px/src/pxpushbuffer.h"

struct tagPXS_PUSHBUFFER* pxgPrimaryPB; // size: 0x4, address: 0x6D1F04
struct tagPXS_PUSHBUFFER* pxgCurrentPB; // size: 0x4, address: 0x6D1F08

struct tagPXS_PUSHBUFFER pxgPBWork; // size: 0xA0, address: 0x6E65D0

const static char __license_string__[] = {
    0xa0, 0xb0, 0x40, 0x5a, 0x40, 0x98, 0xde, 0xee, 0x40, 0x98, 0xca, 0xec, 0xca, 0xd8,
    0x40, 0x8e, 0xe4, 0xc2, 0xe0, 0xd0, 0xd2, 0xc6, 0xe6, 0x40, 0x98, 0xd2, 0xc4, 0xe4,
    0xc2, 0xe4, 0xf2, 0x40, 0xcc, 0xde, 0xe4, 0x40, 0xa0, 0xd8, 0xc2, 0xf2, 0xa6, 0xe8,
    0xc2, 0xe8, 0xd2, 0xde, 0xdc, 0x50, 0xa4, 0x52, 0x64, 0x40, 0x5a, 0x14};

char* __license_string_ptr__;

const static char pxgVersion[] = "\nPX Ver.1.46.07 Build:Jun  2 2006 18:45:32\n";

char* pxgVersionPtr;

struct PXS_INITPARAM pxgInitParam;

enum PXE_ERR PXInit(struct PXS_INITPARAM* iprm)
{
}

signed int PXGsInterruptHandler(signed int ca)
{
}

void PXInitInterrupt(unsigned int flag)
{
}

void PXExit()
{
}

enum PXE_ERR PXRender(unsigned int flag)
{
}

void* PXBegin(unsigned int flag)
{
}

void PXEnd(void* p)
{
}

void PXPutReg(unsigned int addr, unsigned long data)
{
}

void PXPutCustomShader(void* addr)
{
}

void PXStartShader()
{
}

void PXPutCall(void* addr)
{
}

void PXPutRef(void* addr, unsigned int qwc, unsigned int flag)
{
}

void* PXBeginPrim(void* addr, unsigned int vertices, unsigned int stride, unsigned int prim)
{
}

void* PXEndPrim(void* addr)
{
}

void PXPutVifMask()
{
}
