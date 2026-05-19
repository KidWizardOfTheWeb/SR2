#ifndef NNMATERIALCONTROL_H
#define NNMATERIALCONTROL_H

#include "usr/local/sega/nn/src/Material/nnmaterial.h"

enum NNE_MATCTRLMODE {
    NNE_MATCTRLMODE_NONE = 0,
    NNE_MATCTRLMODE_REPLACE = 1,
    NNE_MATCTRLMODE_ADD = 2,
    NNE_MATCTRLMODE_MODULATE = 3,
};

enum NNE_MATCTRL_BLEND {
    NNE_MATCTRL_BLEND_ALPHA = 0,
    NNE_MATCTRL_BLEND_ADD = 1,
    NNE_MATCTRL_BLEND_SUBTRACT = 2,
};

enum NNE_MATCTRL_TEXCOORDSRC {
    NNE_MATCTRL_TEXCOORDSRC_POSITION = 0,
    NNE_MATCTRL_TEXCOORDSRC_NORMAL = 1,
};

enum NNE_TEXSLOT {
    NNE_TEXSLOT_0 = 0,
    NNE_TEXSLOT_1 = 1,
    NNE_TEXSLOT_MAX = 2,
};

// total size: 0x8
struct NNS_MATCTRL_ALPHA {
    enum NNE_MATCTRLMODE mode; // offset 0x0, size 0x4
    float alpha;               // offset 0x4, size 0x4
};

// total size: 0x10
struct NNS_MATCTRL_RGB {
    enum NNE_MATCTRLMODE mode; // offset 0x0, size 0x4
    struct NNS_RGB col;        // offset 0x4, size 0xC
};

// total size: 0xC
struct NNS_MATCTRL_TEXOFFSET {
    enum NNE_MATCTRLMODE mode;  // offset 0x0, size 0x4
    struct NNS_TEXCOORD offset; // offset 0x4, size 0x8
};

// total size: 0x50
struct NNS_MATCTRL_ENVTEXMATRIX {
    enum NNE_MATCTRL_TEXCOORDSRC texcoordsrc; // offset 0x0, size 0x4
    unsigned int _pad4[3];                    // offset 0x4, size 0xC
    float texmtx[4][4];                       // offset 0x10, size 0x40
};

extern struct NNS_MATCTRL_ALPHA nngMatCtrlSpecular;
extern struct NNS_MATCTRL_ALPHA nngMatCtrlAlpha;
extern struct NNS_MATCTRL_ALPHA nngMatCtrlAlphaRef;
extern enum NNE_BOOL nngMatCtrlAlphaWithAlphaRef;
extern enum NNE_MATCTRL_BLEND nngMatCtrlBlendMode;
extern unsigned int nngMatCtrlGsPrmodeAnd;
extern unsigned int nngMatCtrlGsPrmodeOr;
extern unsigned int nngMatCtrlGsAlphaAnd;
extern unsigned int nngMatCtrlGsAlphaOr;
extern struct NNS_MATCTRL_RGB nngMatCtrlDiffuse;
extern struct NNS_MATCTRL_RGB nngMatCtrlAmbient;
extern struct NNS_MATCTRL_TEXOFFSET nngMatCtrlTexOffset[2];
extern struct NNS_MATCTRL_ENVTEXMATRIX nngMatCtrlEnvTexMatrix;

void nnSetMaterialControlAlpha(enum NNE_MATCTRLMODE mode, float alpha);
void nnSetMaterialControlBlendMode(enum NNE_MATCTRL_BLEND blendmode);
void nnSetUpMaterialControlMaterial(struct NNS_DRAWCALLBACK_VAL* val);

#endif // NNMATERIALCONTROL_H
