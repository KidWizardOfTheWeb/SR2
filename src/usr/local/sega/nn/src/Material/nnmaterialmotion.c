#include "usr/local/sega/nn/src/Material/nnmaterialmotion.h"

unsigned int nnCalcMaterialMotionObjectBufferSize(struct NNS_OBJECT* obj, struct NNS_MOTION* mmot)
{
}

void nnInitMaterialMotionObject(struct NNS_OBJECT* mmobj,
                                struct NNS_OBJECT* obj,
                                struct NNS_MOTION* mmot)
{
}

void nnCalcMaterialMotionDiffuseColor(struct NNS_MATERIALPTR* pMatPtrList,
                                      struct NNS_SUBMOTION* pSubMot,
                                      float frame)
{
}

void nnCalcMaterialMotionAlpha(struct NNS_MATERIALPTR* pMatPtrList,
                               struct NNS_SUBMOTION* pSubMot,
                               float frame)
{
}

void nnCalcMaterialMotionSpecularLevel(struct NNS_MATERIALPTR* pMatPtrList,
                                       struct NNS_SUBMOTION* pSubMot,
                                       float frame)
{
}

void nnCalcMaterialMotionAmbientColor(struct NNS_MATERIALPTR* pMatPtrList,
                                      struct NNS_SUBMOTION* pSubMot,
                                      float frame)
{
}

void nnCalcMaterialMotionTextureIndex(struct NNS_MATERIALPTR* pMatPtrList,
                                      struct NNS_SUBMOTION* pSubMot,
                                      float frame)
{
}

void nnCalcMaterialMotionTextureBlend(struct NNS_MATERIALPTR* pMatPtrList,
                                      struct NNS_SUBMOTION* pSubMot,
                                      float frame)
{
}

void nnCalcMaterialMotionTextureOffset(struct NNS_MATERIALPTR* pMatPtrList,
                                       struct NNS_SUBMOTION* pSubMot,
                                       float frame)
{
}

void nnCalcMaterialMotionUserData(struct NNS_MATERIALPTR* pMatPtrList,
                                  struct NNS_SUBMOTION* pSubMot,
                                  float frame)
{
}

void nnCalcMaterialMotionCore(struct NNS_OBJECT* pMObj,
                              struct NNS_OBJECT* pObj,
                              struct NNS_MOTION* pMot,
                              float frame,
                              unsigned int* pMatStatList)
{
}

void nnCalcMaterialMotion(struct NNS_OBJECT* mmobj,
                          struct NNS_OBJECT* obj,
                          struct NNS_MOTION* mmot,
                          float frame)
{
}

void nnCalcMaterialMotionMaterialStatusList(struct NNS_OBJECT* mmobj,
                                            struct NNS_OBJECT* obj,
                                            struct NNS_MOTION* mmot,
                                            float frame,
                                            unsigned int* pMatStatList)
{
}

void nnCalcMaterialStatusListNodeStatusList(unsigned int* pMatStatList,
                                            struct NNS_OBJECT* pObj,
                                            unsigned int* pNodeStatList)
{
}

void nnDrawMaterialMotionObject(struct NNS_OBJECT* mmobj,
                                float (*mtxpal)[4][4],
                                unsigned int* nodestatlist,
                                unsigned int subobjtype,
                                unsigned int flag)
{
}
