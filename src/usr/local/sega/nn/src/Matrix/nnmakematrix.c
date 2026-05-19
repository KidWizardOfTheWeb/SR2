#include "usr/local/sega/nn/src/Matrix/nnmakematrix.h"

void nnMakeUnitMatrix(float (*dst)[4][4])
{
}

void nnMakeQuaternionMatrix(float (*dst)[4][4], struct NNS_QUATERNION* quat)
{
}

void nnMakeRotateXMatrix(float (*dst)[4][4], signed int ax)
{
}

void nnMakeRotateYMatrix(float (*dst)[4][4], signed int ay)
{
}

void nnMakeRotateZMatrix(float (*dst)[4][4], signed int az)
{
}

void nnMakeRotateYMatrixSinCos(float (*mtx)[4][4], float s, float c)
{
}

void nnMakeRotateZMatrixSinCos(float (*mtx)[4][4], float s, float c)
{
}

void nnMakeRotateXYZMatrix(float (*dst)[4][4], signed int ax, signed int ay, signed int az)
{
}

void nnMakeRotateXZYMatrix(float (*dst)[4][4], signed int ax, signed int ay, signed int az)
{
}

void nnMakeRotateZXYMatrix(float (*dst)[4][4], signed int ax, signed int ay, signed int az)
{
}

void nnMakeRotateAxisMatrix(float (*dst)[4][4], float vx, float vy, float vz, signed int ang)
{
}

void nnMakeScaleMatrix(float (*dst)[4][4], float x, float y, float z)
{
}

void nnMakeTranslateMatrix(float (*dst)[4][4], float x, float y, float z)
{
}

void nnMakePerspectiveMatrix(
    float (*mtx)[4][4], signed int fovy, float aspect, float znear, float zfar)
{
}

void nnMakeOrthoMatrix(
    float (*mtx)[4][4], float left, float right, float bottom, float top, float znear, float zfar)
{
}
