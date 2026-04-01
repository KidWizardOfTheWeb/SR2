#ifndef PXTEX2_H
#define PXTEX2_H

extern unsigned int pxgPath3TransAddr; // size: 0x4, address: 0x6D1F38
extern unsigned int pxgPath3TransInvokeCount; // size: 0x4, address: 0x6D1F3C

enum PXE_ERR {
    PXE_ERR_OK = 0,
    PXE_ERR_INVALIDARG = -1,
    PXE_ERR_BUSY = -2,
    PXE_ERR_NOTREADY = -10,
    PXE_ERR_NOTVB = -50,
    PXE_ERR_INVALIDVBVERSION = -51,
    PXE_ERR_TOOMANYVERTICES = -52,
    PXE_ERR_NODATA = -53,
    PXE_ERR_NOTENOUGHBUFFER = -54,
    PXE_ERR_INCORRECTDBINDEX = -55,
};

enum PXE_ERR PXStartPath3Trans(void * tagAddr);

#endif
