#ifndef NNCALCMATRIXPALETTEMOTION_H
#define NNCALCMATRIXPALETTEMOTION_H

#include "usr/local/sega/nn/src/System/nnsystem.h"

#include "usr/local/sega/nn/src/Object/nnobject.h"

struct NNS_MATRIXSTACK;

// total size: 0x20
struct NNS_NODEUSRMOT_CALLBACK_VAL {
    signed int iNode; // offset 0x0, size 0x4
    float Frame;      // offset 0x4, size 0x4
    union {
        unsigned int IValue; // offset 0x8, size 0x4
        float FValue;        // offset 0x8, size 0x4
    };
    struct NNS_MOTION* pMotion; // offset 0xC, size 0x4
    signed int iSubmot;         // offset 0x10, size 0x4
    unsigned int fSubmotType;   // offset 0x14, size 0x4
    unsigned int fSubmotIPType; // offset 0x18, size 0x4
    struct NNS_OBJECT* pObject; // offset 0x1C, size 0x4
};

typedef void (*NNS_NODEUSRMOT_CALLBACK_FUNC)(struct NNS_NODEUSRMOT_CALLBACK_VAL*);

extern NNS_NODEUSRMOT_CALLBACK_FUNC nngNodeUserMotionCallbackFunc;

#ifdef __cplusplus
extern "C" {
#endif

void nnCalcMatrixPaletteMotion(NNS_MATRIX* mtxpal,
                               unsigned int* nodestatlist,
                               struct NNS_OBJECT* obj,
                               struct NNS_MOTION* mot,
                               float frame,
                               NNS_MATRIX* basemtx,
                               struct NNS_MATRIXSTACK* mstk,
                               unsigned int flag);
signed int nnCalcMotionFrame(
    float* dstframe, unsigned int fType, float startframe, float endframe, float frame);
void nnCalcMatrixPaletteMotionNode(signed int nodeIdx);
signed int nnCalcNodeMotionCore(NNS_MATRIX* pNodeMtx,
                                signed int* pHideFlag,
                                NNS_MATRIX* pBaseMtx,
                                struct NNS_NODE* pNode,
                                signed int NodeIdx,
                                struct NNS_MOTION* pMot,
                                signed int SubMotIdx,
                                float frame);
signed int nnCalcMotionRotate(struct NNS_SUBMOTION* submot,
                              float frame,
                              struct NNS_ROTATE_A32* rv,
                              struct NNS_QUATERNION* rq,
                              unsigned int rtype);
void nnRotateXYZMatrixFast(NNS_MATRIX* mtx, signed int ax, signed int ay, signed int az);
void nnRotateXZYMatrixFast(NNS_MATRIX* mtx, signed int ax, signed int ay, signed int az);
void nnRotateZXYMatrixFast(NNS_MATRIX* mtx, signed int ax, signed int ay, signed int az);
signed int nnCalcMotionTranslate(struct NNS_SUBMOTION* submot, float frame, struct NNS_VECTOR* tv);
void nnTranslateMatrixFast(NNS_MATRIX* mtx, float x, float y, float z);
signed int nnCalcMotionScale(struct NNS_SUBMOTION* submot, float frame, struct NNS_VECTOR* sv);
void nnScaleMatrixFast(NNS_MATRIX* mtx, float x, float y, float z);
void nnCalcMatrixPaletteMotionNode2BoneSIIK(signed int jnt1nodeIdx);
void nnCalcMatrixPaletteMotionNode1BoneSIIK(signed int jnt1nodeIdx);
enum NNE_BOOL nnCalcMotionUserData(struct NNS_NODEUSRMOT_CALLBACK_VAL* val,
                                   struct NNS_SUBMOTION* submot,
                                   float frame);
void nnNormalizeColumn(NNS_MATRIX* mtx, signed int clm);

#ifdef __cplusplus
}
#endif

#endif // NNCALCMATRIXPALETTEMOTION_H
