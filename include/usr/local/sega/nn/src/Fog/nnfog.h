#ifndef NNFOG_H
#define NNFOG_H

#include "usr/local/sega/nn/src/System/nnsystem.h"

extern unsigned int nngFogFlag;
extern unsigned int nngFogFlagPXPlus;

void nnSetFogSwitch(enum NNE_BOOL on_off);
void nnSetFogColor(float r, float g, float b);
void nnSetFogRangePS2(float fnear, float ffar, float fmin, float fmax);

#endif // NNFOG_H
