#ifndef NNMAKEMATRIX_H
#define NNMAKEMATRIX_H

#include "usr/local/sega/nn/src/Matrix/nnvector.h"

#ifdef __cplusplus
extern "C" {
#endif

void nnMakeUnitMatrix(NNS_MATRIX* dst);
void nnMakeQuaternionMatrix(NNS_MATRIX* dst, struct NNS_QUATERNION* quat);
void nnMakeRotateXMatrix(NNS_MATRIX* dst, signed int ax);
void nnMakeRotateYMatrix(NNS_MATRIX* dst, signed int ay);
void nnMakeRotateZMatrix(NNS_MATRIX* dst, signed int az);
void nnMakeRotateYMatrixSinCos(NNS_MATRIX* mtx, float s, float c);
void nnMakeRotateZMatrixSinCos(NNS_MATRIX* mtx, float s, float c);
void nnMakeRotateXYZMatrix(NNS_MATRIX* dst, signed int ax, signed int ay, signed int az);
void nnMakeRotateXZYMatrix(NNS_MATRIX* dst, signed int ax, signed int ay, signed int az);
void nnMakeRotateZXYMatrix(NNS_MATRIX* dst, signed int ax, signed int ay, signed int az);
void nnMakeRotateAxisMatrix(NNS_MATRIX* dst, float vx, float vy, float vz, signed int ang);
void nnMakeScaleMatrix(NNS_MATRIX* dst, float x, float y, float z);
void nnMakeTranslateMatrix(NNS_MATRIX* dst, float x, float y, float z);
void nnMakePerspectiveMatrix(
    NNS_MATRIX* mtx, signed int fovy, float aspect, float znear, float zfar);
void nnMakeOrthoMatrix(
    NNS_MATRIX* mtx, float left, float right, float bottom, float top, float znear, float zfar);

#ifdef __cplusplus
}
#endif

#endif // NNMAKEMATRIX_H
