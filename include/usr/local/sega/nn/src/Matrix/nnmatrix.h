#ifndef NNMATRIX_H
#define NNMATRIX_H

#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

void nnCopyMatrix(float (*dst)[4][4], float (*src)[4][4]);
enum NNE_BOOL nnInvertMatrix(float (*dst)[4][4], float (*src)[4][4]);
void nnInvertOrthoMatrix(float (*dst)[4][4], float (*src)[4][4]);
void nnMultiplyMatrix(float (*dst)[4][4], float (*mtx1)[4][4], float (*mtx2)[4][4]);
void nnQuaternionMatrix(float (*dst)[4][4], float (*src)[4][4], struct NNS_QUATERNION* quat);
void nnRotateXMatrix(float (*dst)[4][4], float (*src)[4][4], signed int ax);
void nnRotateYMatrix(float (*dst)[4][4], float (*src)[4][4], signed int ay);
void nnRotateZMatrix(float (*dst)[4][4], float (*src)[4][4], signed int az);
void nnRotateXYZMatrix(
    float (*dst)[4][4], float (*src)[4][4], signed int ax, signed int ay, signed int az);
void nnRotateZXYMatrix(
    float (*dst)[4][4], float (*src)[4][4], signed int ax, signed int ay, signed int az);
void nnScaleMatrix(float (*dst)[4][4], float (*src)[4][4], float x, float y, float z);
void nnTranslateMatrix(float (*dst)[4][4], float (*src)[4][4], float x, float y, float z);
void nnCopyVectorMatrixTranslation(float (*mtx)[4][4], struct NNS_VECTOR* vec);
void nnCopyVectorFastMatrixTranslation(float (*mtx)[4][4], struct NNS_VECTORFAST* vec);

#endif // NNMATRIX_H
