#include "usr/local/sega/px/src/pxcontext.h"
#include "usr/local/sce/ee/lib/eestruct.h"
#include "usr/local/sega/px/src/px.h"

struct PXS_CONTEXT pxg_context[2];
unsigned long pxg_frame_addr[2] = {0x4C, 0x4D};
unsigned long pxg_scissor_addr[2] = {0x40, 0x41};

void PXInitContext(enum PXE_CTX context)
{
    unsigned long* p;
    int i;

    p = (unsigned long*)&pxg_context[context & 0xFF];
    i = 0;
    do {
        p[0] = 0;
        i += 7;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        p[8] = 0;
        p[9] = 0;
        p[10] = 0;
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
        p += 14;
    } while (i < 15);
    p[0] = 0;
    p[1] = 0;
}

void PXPutContext(enum PXE_CTX context)
{
    unsigned long* top;
    unsigned long* end;
    unsigned long* p;
    unsigned long* reg;
    unsigned long data;
    unsigned long addr;
    signed int i;
    signed int cnt;

    reg = (unsigned long*)&pxg_context[context & 0xFF];
    p = (unsigned long*)PXBegin(0);
    top = p;
    end = p;
    cnt = 0;
    p += 2;
    for (i = 0; i < 0x16; i++) {
        data = reg[i * 2 + 0];
        addr = reg[i * 2 + 1];
        if (addr != 0) {
            *p++ = data;
            *p++ = addr;
            reg[i * 2 + 1] = 0;
            cnt++;
        }
    }

    if (cnt != 0) {
        end = p;
        top[0] = SCE_GIF_SET_TAG(cnt, SCE_GS_TRUE, SCE_GS_FALSE, NULL, SCE_GIF_PACKED, 1);
        top[1] = GIF_REGLIST(SCE_GIF_PACKED_AD);
    }

    PXEnd(end);
    return;
}

struct PXS_CONTEXTBUFFER* PXSetupCB(void* buf, unsigned int bufsize, int num)
{
    if (bufsize < ((num * 16) + 16)) {
        return 0;
    } else {
        ((struct PXS_CONTEXTBUFFER*)buf)->reg[-1].data =
            SCE_GIF_SET_TAG(num, SCE_GS_TRUE, SCE_GS_FALSE, NULL, SCE_GIF_PACKED, 1);
        ((struct PXS_CONTEXTBUFFER*)buf)->reg[-1].addr = GIF_REGLIST(SCE_GIF_PACKED_AD);
        return (struct PXS_CONTEXTBUFFER*)buf;
    }
}

void PXReferCB(struct PXS_CONTEXTBUFFER* cb)
{
    PXPutRef(cb, (cb->giftag[0] & 0x7fff) + 1, 0);
}

void PXPutCB(struct PXS_CONTEXTBUFFER* cb)
{
    __int128* dp;
    __int128* sp;
    int num;

    dp = (__int128*)cb;
    num = (cb->giftag[0] & 0x7FFF) + 1;
    sp = PXBegin(0);

    do {
        num--;
        *sp = *dp;
        dp++;
        sp++;
    } while (num != 0);

    PXEnd(sp);
}

void PXSetCB(struct PXS_CONTEXTBUFFER* cb, signed int num, unsigned long addr, unsigned long data)
{
    struct PXS_GSREG_AD* reg;

    reg = &cb->reg[num];
    reg->addr = addr;
    reg->data = data;
}
