#include "usr/local/sega/nn/src/Matrix/nnvector.h"

void nnAddVector(struct NNS_VECTOR* dst, struct NNS_VECTOR* vec1, struct NNS_VECTOR* vec2)
{
}

void nnCrossProductVector(struct NNS_VECTOR* dst, struct NNS_VECTOR* vec1, struct NNS_VECTOR* vec2)
{
}

void nnCopyVector(struct NNS_VECTOR* dst, const struct NNS_VECTOR* src)
{
}

float nnDotProductVector(struct NNS_VECTOR* vec1, struct NNS_VECTOR* vec2)
{
}

float nnLengthVector(struct NNS_VECTOR* vec)
{
}

float nnDistanceVector(struct NNS_VECTOR* vec1, struct NNS_VECTOR* vec2)
{
}

enum NNE_BOOL nnNormalizeVector(struct NNS_VECTOR* dst, struct NNS_VECTOR* src)
{
}

void nnScaleVector(struct NNS_VECTOR* dst, struct NNS_VECTOR* src, float scale)
{
}

void nnScaleAddVector(struct NNS_VECTOR* dst,
                      struct NNS_VECTOR* vec1,
                      struct NNS_VECTOR* vec2,
                      float scale)
{
}

void nnSubtractVector(struct NNS_VECTOR* dst, struct NNS_VECTOR* vec1, struct NNS_VECTOR* vec2)
{
}

void nnTransformVector(struct NNS_VECTOR* dst, float (*mtx)[4][4], struct NNS_VECTOR* src)
{
}

void nnTransformNormalVector(struct NNS_VECTOR* dst, float (*mtx)[4][4], struct NNS_VECTOR* src)
{
}

void nnSetUpVectorFast(struct NNS_VECTORFAST* dst, float x, float y, float z)
{
}

void nnAddVectorFast(struct NNS_VECTORFAST* dst,
                     struct NNS_VECTORFAST* vec1,
                     struct NNS_VECTORFAST* vec2)
{
}

void nnCrossProductVectorFast(struct NNS_VECTORFAST* dst,
                              struct NNS_VECTORFAST* vec1,
                              struct NNS_VECTORFAST* vec2)
{
}

void nnCopyVectorFast(struct NNS_VECTORFAST* dst, struct NNS_VECTORFAST* src)
{
}

float nnDotProductVectorFast(struct NNS_VECTORFAST* vec1, struct NNS_VECTORFAST* vec2)
{
}

float nnLengthVectorFast(struct NNS_VECTORFAST* vec)
{
}

float nnDistanceVectorFast(struct NNS_VECTORFAST* vec1, struct NNS_VECTORFAST* vec2)
{
}

float nnLengthSqVectorFast(struct NNS_VECTORFAST* vec)
{
}

float nnDistanceSqVectorFast(struct NNS_VECTORFAST* vec1, struct NNS_VECTORFAST* vec2)
{
}

enum NNE_BOOL nnNormalizeVectorFast(struct NNS_VECTORFAST* dst, struct NNS_VECTORFAST* src)
{
}

void nnScaleVectorFast(struct NNS_VECTORFAST* dst, struct NNS_VECTORFAST* src, float scale)
{
}

void nnScaleAddVectorFast(struct NNS_VECTORFAST* dst,
                          struct NNS_VECTORFAST* vec1,
                          struct NNS_VECTORFAST* vec2,
                          float scale)
{
}

void nnSubtractVectorFast(struct NNS_VECTORFAST* dst,
                          struct NNS_VECTORFAST* vec1,
                          struct NNS_VECTORFAST* vec2)
{
}

void nnTransformVectorFast(struct NNS_VECTORFAST* dst,
                           float (*mtx)[4][4],
                           struct NNS_VECTORFAST* src)
{
}

void nnTransformNormalVectorFast(struct NNS_VECTORFAST* dst,
                                 float (*mtx)[4][4],
                                 struct NNS_VECTORFAST* src)
{
}

void nnCopyMatrixTranslationVector(struct NNS_VECTOR* dst, float (*mtx)[4][4])
{
}

void nnCopyMatrixTranslationVectorFast(struct NNS_VECTORFAST* dst, float (*mtx)[4][4])
{
}
