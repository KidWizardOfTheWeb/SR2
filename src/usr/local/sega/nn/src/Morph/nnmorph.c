#include "usr/local/sega/nn/src/Morph/nnmorph.h"

unsigned int nnCalcMorphObjectBufferSize(struct NNS_OBJECT* obj,
                                         struct NNS_MORPHTARGETLIST* mtgt,
                                         unsigned int flag)
{
}

unsigned int nnInitMorphObject(struct NNS_OBJECT* mobj,
                               struct NNS_OBJECT* obj,
                               struct NNS_MORPHTARGETLIST* mtgt,
                               unsigned int flag)
{
}

void nnCalcMorphSeparateVertices(struct NNS_VTXLISTPTR* pVtxListPtrList,
                                 struct NNS_MORPHTARGETLIST* mtgt,
                                 unsigned int iVtxList,
                                 float* mwpal,
                                 unsigned int flag)
{
}

void nnCalcMorphObject(struct NNS_OBJECT* mobj,
                       struct NNS_MORPHTARGETLIST* mtgt,
                       float* mwpal,
                       unsigned int flag)
{
}

void nnDrawMorphObject(struct NNS_OBJECT* mobj,
                       float (*mtxpal)[4][4],
                       unsigned int* nodestatlist,
                       unsigned int subobjtype,
                       unsigned int flag)
{
}
