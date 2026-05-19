#include "usr/local/sega/nn/src/Light/nnlight.h"

void nnInitLight(void)
{
}

void nnSetAmbientColor(float r, float g, float b)
{
}

void nnSetLightSwitch(enum NNE_LIGHT no, enum NNE_BOOL on_off)
{
}

void nnSetLightColor(enum NNE_LIGHT no, float r, float g, float b)
{
}

void nnSetLightPosition(enum NNE_LIGHT no, float x, float y, float z)
{
}

void nnSetLightType(enum NNE_LIGHT no, unsigned int type)
{
}

void nnSetLightDirection(enum NNE_LIGHT no, float x, float y, float z)
{
}

void nnSetLightIntensity(enum NNE_LIGHT no, float intensity)
{
}

void nnSetUpParallelLight(struct NNS_LIGHT_PARALLEL* light,
                          struct NNS_RGBA* color,
                          float inten,
                          struct NNS_VECTOR* dir)
{
}

void nnSetUpPointLight(struct NNS_LIGHT_POINT* light,
                       struct NNS_RGBA* color,
                       float inten,
                       struct NNS_VECTOR* pos,
                       float falloffstart,
                       float falloffend)
{
}

void nnSetUpSpecularLightPS2(struct NNS_LIGHT_SPECULAR_PS2* light,
                             struct NNS_RGBA* color,
                             struct NNS_VECTOR* dir)
{
}

void nnSetUpTargetDirectionalLight(struct NNS_LIGHT_TARGET_DIRECTIONAL* light,
                                   struct NNS_RGBA* color,
                                   float inten,
                                   struct NNS_VECTOR* pos,
                                   struct NNS_VECTOR* target,
                                   float innerrange,
                                   float outerrange,
                                   float falloffstart,
                                   float falloffend)
{
}

unsigned int nnEstimateLightBufferSize(unsigned int type)
{
}

void nnSetLight(enum NNE_LIGHT no, void* light, unsigned int type)
{
}

void nnSetLightSpecularLightPS2(enum NNE_LIGHT no,
                                void* light,
                                unsigned int type,
                                unsigned int flag)
{
}

void nnSetLightMatrix(float (*mtx)[4][4])
{
}

void nnPutLightSettings(void)
{
}
