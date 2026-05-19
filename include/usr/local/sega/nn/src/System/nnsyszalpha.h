#ifndef NNSYSZALPHA_H
#define NNSYSZALPHA_H

#include "usr/local/sega/nn/src/System/nnsystem.h"

void nnSetZWriteModePS2(enum NNE_BOOL mode);
void nnSetAlphaCompModePS2(unsigned int on_off,
                           unsigned int compmode,
                           unsigned char aref,
                           unsigned int failmode);
void nnSetDestAlphaCompModePS2(unsigned int on_off, unsigned int mode);
void nnSetZCompModePS2(unsigned int mode);

#endif // NNSYSZALPHA_H
