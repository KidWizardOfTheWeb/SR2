#ifndef PXPUSHBUFFER_H
#define PXPUSHBUFFER_H

#include "usr/local/sega/px/src/px.h"

struct tagPXS_PUSHBUFFER* PXSetupPB(struct tagPXS_PUSHBUFFER* pb,
                                    unsigned int nTagBytes,
                                    unsigned int nDataBytes,
                                    void* addr,
                                    unsigned int bufsize,
                                    unsigned int flag);
void PXPutShaderPB(struct tagPXS_PUSHBUFFER* pb, void* addr);

#endif
