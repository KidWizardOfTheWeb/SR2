#include "usr/local/sce/ee/lib/eeregs.h"
#include "usr/local/sega/px/src/pxtex2.h"

unsigned int pxgPath3TransAddr; // size: 0x4, address: 0x6D1F38
unsigned int pxgPath3TransInvokeCount; // size: 0x4, address: 0x6D1F3C

enum PXE_ERR PXStartPath3Trans(void * tagAddr) {
    while (DGET_D2_CHCR() & 0x100);
    DPUT_D_STAT(4);
    DPUT_D2_QWC(0);
    DPUT_D2_TADR((unsigned int)tagAddr & 0x0FFFFFFF);
    asm("sync;");
    DPUT_D2_CHCR(0x185);
    pxgPath3TransAddr = (unsigned int)tagAddr & 0x0FFFFFFF;
    pxgPath3TransInvokeCount++;
    return PXE_ERR_OK;
}
