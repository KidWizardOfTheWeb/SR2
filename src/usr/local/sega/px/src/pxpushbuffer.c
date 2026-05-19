
#include "usr/local/sega/px/src/pxpushbuffer.h"

struct tagPXS_PUSHBUFFER* PXSetupPB(struct tagPXS_PUSHBUFFER* pb,
                                    unsigned int nTagBytes,
                                    unsigned int nDataBytes,
                                    void* addr,
                                    unsigned int bufsize,
                                    unsigned int flag)
{
}

void PXAddTagEnd(struct PXS_PUSHBUFFER1* db, unsigned int irq)
{
}

void PXFlipPB(struct tagPXS_PUSHBUFFER* pb)
{
}

enum PXE_ERR PXRenderPB(struct tagPXS_PUSHBUFFER* pb, unsigned int flag)
{
}

void* PXBeginPB(struct tagPXS_PUSHBUFFER* pb, unsigned int flag)
{
}

void PXAddTagCall(struct PXS_PUSHBUFFER1* db, void* addr)
{
}

void PXPutCallPB(struct tagPXS_PUSHBUFFER* pb, void* addr)
{
}

void PXPutRefPB(struct tagPXS_PUSHBUFFER* pb, void* addr, unsigned int qwc, unsigned int flag)
{
}

void PXAdjustSharedPB(struct tagPXS_PUSHBUFFER* pb)
{
}

void PXEndPB(struct tagPXS_PUSHBUFFER* pb, void* pEnd)
{
}

void PXPutShaderPB(struct tagPXS_PUSHBUFFER* pb, void* addr)
{
}

void PXPutShaderConstPB(struct tagPXS_PUSHBUFFER* pb,
                        unsigned int vumem,
                        void* addr,
                        unsigned int qwc)
{
}

void PXReferShaderConstPB(struct tagPXS_PUSHBUFFER* pb,
                          unsigned int vumem,
                          void* addr,
                          unsigned int qwc)
{
}

void* PXGetLastShaderConstAddrPB(struct tagPXS_PUSHBUFFER* pb)
{
}

void PXPutRegPB(struct tagPXS_PUSHBUFFER* pb, unsigned int addr, unsigned long data)
{
}

void PXStartShaderPB(struct tagPXS_PUSHBUFFER* pb)
{
}

void* PXBeginPrimPB(struct tagPXS_PUSHBUFFER* pb,
                    void* addr,
                    unsigned int vertices,
                    unsigned int stride,
                    unsigned int prim)
{
}

void* PXEndPrimPB(void* addr)
{
}
