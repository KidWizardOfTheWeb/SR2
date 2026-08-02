
#include "usr/local/sega/px/src/pxpushbuffer.h"
#include "usr/local/sega/px/src/px.h"
#include "usr/local/sce/ee/lib/eekernel.h"

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
    struct PXS_DMATAG* dt;

    dt = (struct PXS_DMATAG *)db->tagPtr;
    *(__int128 *)dt = 0;
    dt->id = (short) ((irq | 7) << 0xC);
    db->tagPtr++;
    db->numTags++;
}

void PXFlipPB(struct tagPXS_PUSHBUFFER* pb)
{
    struct PXS_PUSHBUFFER1 * db;
    struct PXS_DMATAG* dt;
    int flg;

    flg = DIntr();
    db = &pb->db[pb->dbIndex];
    if ((pb->flag & 3) == 2) {
        if ((pxgInitParam.flag & 0x200)) {
            PXPutReg(0x61,0);
        }
        dt = (struct PXS_DMATAG*) db->tagPtr;
        *(__int128 *)dt = 0;
        dt->id = 0x6000;
        dt->vifnop = 0x11000000;
        db->tagPtr++;
        db->numTags++;
        if (pb->peakBytes < db->numBytes) {
            pb->peakBytes = db->numBytes;
        }

        if (pb->peakTags < db->numTags) {
            pb->peakTags = db->numTags;
        }
        db->ready = 1;
        pb->dbIndex ^= 1;
        db->numTags = 0;
        db->numBytes = 0;
        db->bufPtr = db->bufTop;
        db->tagPtr = db->tagTop;
        db = &pb->db[pb->dbIndex];
        PXAddTagCall(db,db->tagTop + 2);
        dt = (struct PXS_DMATAG*) db->tagPtr;
        *(__int128 *)dt = 0;
        dt->id = 0x7000;
        db->tagPtr++;
        db->numTags++;
    }
    if (flg != 0) {
        EIntr();
    }
    return;
}

enum PXE_ERR PXRenderPB(struct tagPXS_PUSHBUFFER* pb, unsigned int flag)
{
}

void* PXBeginPB(struct tagPXS_PUSHBUFFER* pb, unsigned int flag)
{
    struct PXS_PUSHBUFFER1 * db = &pb->db[pb->dbIndex];
    __int128 * bp;

    bp = db->bufPtr;
    db->beginPtr = bp;
    pb->beginFlag = flag;
    db->pushVuOffset = 1;
    return (void *) ((unsigned int)bp & 0x0FFFFFFF | 0x30000000);
}

void PXAddTagCall(struct PXS_PUSHBUFFER1* db, void* addr)
{
    struct PXS_DMATAG *dt;

    dt = (struct PXS_DMATAG *)db->tagPtr;
    dt->id = 0x5000;
    dt->qwc = 0;
    dt->addr = addr;
    dt->vifnop = db->nextVifCmd;
    dt->directhl = 0;
    db->nextVifCmd = 0;
    db->tagPtr++;
    db->numTags++;
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
    return pb->recentAddr;
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

void* PXEndPrimPB(struct tagPXS_PUSHBUFFER* pb, void* addr) {
    unsigned int * p = (unsigned int *)addr;
    p[0] = 0x17000000;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    return (void *)&p[4];
}
