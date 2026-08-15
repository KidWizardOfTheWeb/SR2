#ifndef NNMATRIX_H
#define NNMATRIX_H

#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

#ifdef __cplusplus
extern "C" {
#endif

void nnCopyMatrix(NNS_MATRIX* dst, NNS_MATRIX* src);
enum NNE_BOOL nnInvertMatrix(NNS_MATRIX* dst, NNS_MATRIX* src);
void nnInvertOrthoMatrix(NNS_MATRIX* dst, NNS_MATRIX* src);
void nnMultiplyMatrix(NNS_MATRIX* dst, NNS_MATRIX* mtx1, NNS_MATRIX* mtx2);
void nnQuaternionMatrix(NNS_MATRIX* dst, NNS_MATRIX* src, struct NNS_QUATERNION* quat);
void nnRotateXMatrix(NNS_MATRIX* dst, NNS_MATRIX* src, signed int ax);
void nnRotateYMatrix(NNS_MATRIX* dst, NNS_MATRIX* src, signed int ay);
void nnRotateZMatrix(NNS_MATRIX* dst, NNS_MATRIX* src, signed int az);
void nnRotateXYZMatrix(
    NNS_MATRIX* dst, NNS_MATRIX* src, signed int ax, signed int ay, signed int az);
void nnRotateZXYMatrix(
    NNS_MATRIX* dst, NNS_MATRIX* src, signed int ax, signed int ay, signed int az);
void nnScaleMatrix(NNS_MATRIX* dst, NNS_MATRIX* src, float x, float y, float z);
void nnTranslateMatrix(NNS_MATRIX* dst, NNS_MATRIX* src, float x, float y, float z);
void nnCopyVectorMatrixTranslation(NNS_MATRIX* mtx, struct NNS_VECTOR* vec);
void nnCopyVectorFastMatrixTranslation(NNS_MATRIX* mtx, const struct NNS_VECTORFAST* vec);

#ifdef __cplusplus
}
#endif

#endif // NNMATRIX_H
