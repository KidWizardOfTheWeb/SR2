#include "usr/local/sega/px/src/pxgeom.h"

void PXNormalizeVector(struct PXS_FXYZW* v0, struct PXS_FXYZW* v1)
{
}

void PXSetLightColor(enum PXE_LIGHT num, float r, float g, float b, float a)
{
}

void PXSetLightVector(enum PXE_LIGHT num, float x, float y, float z)
{
}

void PXSetAmbientColor(float r, float g, float b, float a)
{
}

void PXPutMaterial(struct PXS_MATERIAL* mat)
{
}

void PXPutMaterial2(struct PXS_MATERIAL* mat)
{
}

void* PXGetLastShaderConstAddr()
{
}

void PXReferMaterial(struct PXS_MATERIAL* mat)
{
}

void PXReferMaterial2(struct PXS_MATERIAL* mat)
{
}

void PXSetupPrimMode(struct PXS_PRMODESET* prmode, unsigned int prmode0, unsigned int prmode1)
{
}

void PXPutPrimMode(struct PXS_PRMODESET* prmode)
{
}

void PXPutClipParam(enum PXE_CULL cullmode)
{
}

void PXPutNearZ(float nearz)
{
}

void PXTransposeMatrix(struct PXS_MATRIX* dst, struct PXS_MATRIX* src)
{
}

void PXCalcLightMatrix(struct PXS_MATRIX* p, struct PXS_FXYZW* l, struct PXS_MATRIX* v)
{
}

void PXCalcLightMatrix2(struct PXS_MATRIX* p, struct PXS_FXYZW* l, struct PXS_MATRIX* v)
{
}

void PXPutLightMatrix(void* mtx, unsigned int flag)
{
}

void PXPutLightVector(void* mtx, unsigned int flag)
{
}

void PXPutLightColor()
{
}

void PXPutShaderConst(unsigned int vumem, void* addr, unsigned int qwc)
{
}

void PXReferShaderConst(unsigned int vumem, void* addr, unsigned int qwc)
{
}

void PXPutBoneMatrix(struct PXS_MATRIX* mtx, signed int ofs, signed int num)
{
}

void PXMakeScreenParam(struct PXS_SCREENPARAM* p,
                       float width,
                       float height,
                       float cx,
                       float cy,
                       float zmul,
                       float zbias)
{
}

void PXPutScreenParam(struct PXS_SCREENPARAM* p)
{
}

void PXGetScreenParam(struct PXS_SCREENPARAM* p)
{
}

void PXPutTransform(enum PXE_TRANSFORM type, void* mtx)
{
}

void PXPutViewProjection(void* mtx)
{
}

void PXInitSubShaderParam()
{
}

void PXSetFogRange(float FogNear, float FogFar, float Fmin, float Fmax)
{
}

void PXSetUvParam(float uoffset, float voffset, float uscale, float vscale)
{
}

void PXSetScissorMode(signed int mode)
{
}

void PXPutSubShaderParam()
{
}

void PXMakeNormalParam(struct PXS_NORMALPARAM* param, float len)
{
}

void PXPutNormalParam(struct PXS_NORMALPARAM* param)
{
}

void PXMakeWireParam(struct PXS_WIREPARAM* param,
                     unsigned int mode,
                     unsigned int colflag,
                     unsigned int prim,
                     unsigned int r,
                     unsigned int g,
                     unsigned int b,
                     unsigned int a)
{
}

void PXPutWireParam(struct PXS_WIREPARAM* param)
{
}
