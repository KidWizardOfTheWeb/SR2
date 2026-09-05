#ifndef NNVECTOR_H
#define NNVECTOR_H

#include "usr/local/sega/nn/src/System/nnsystem.h"

// total size: 0xC
struct NNS_VECTOR {
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
};

// total size: 0x10
struct NNS_VECTORFAST {
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
    float w; // offset 0xC, size 0x4
} __attribute__((aligned(16)));

// total size: 0x10
struct NNS_VECTOR4D {
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
    float w; // offset 0xC, size 0x4
};

// total size: 0x10
struct NNS_QUATERNION {
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
    float w; // offset 0xC, size 0x4
};

// total size: 0x10
struct NNS_SPHERE {
    struct NNS_VECTOR c; // offset 0x0, size 0xC
    float r;             // offset 0xC, size 0x4
};

// total size: 0x1C
struct NNS_CAPSULE {
    struct NNS_VECTOR c1; // offset 0x0, size 0xC
    struct NNS_VECTOR c2; // offset 0xC, size 0xC
    float r;              // offset 0x18, size 0x4
};

// total size: 0xC
struct NNS_ROTATE {
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
};

// total size: 0xC
struct NNS_ROTATE_A32 {
    signed int x; // offset 0x0, size 0x4
    signed int y; // offset 0x4, size 0x4
    signed int z; // offset 0x8, size 0x4
};

// total size: 0x30
struct NNS_TRS {
    struct NNS_VECTORFAST Translation; // offset 0x0,  size 0x10
    struct NNS_QUATERNION Rotation;    // offset 0x10, size 0x10
    struct NNS_VECTORFAST Scaling;     // offset 0x20, size 0x10
};

#ifdef __cplusplus
extern "C" {
#endif

void nnAddVector(struct NNS_VECTOR* dst, struct NNS_VECTOR* vec1, struct NNS_VECTOR* vec2);
void nnCrossProductVector(struct NNS_VECTOR* dst, struct NNS_VECTOR* vec1, struct NNS_VECTOR* vec2);
void nnCopyVector(struct NNS_VECTOR* dst, const struct NNS_VECTOR* src);
float nnDotProductVector(struct NNS_VECTOR* vec1, struct NNS_VECTOR* vec2);
float nnLengthVector(struct NNS_VECTOR* vec);
float nnDistanceVector(struct NNS_VECTOR* vec1, struct NNS_VECTOR* vec2);
enum NNE_BOOL nnNormalizeVector(struct NNS_VECTOR* dst, struct NNS_VECTOR* src);
void nnScaleVector(struct NNS_VECTOR* dst, struct NNS_VECTOR* src, float scale);
void nnScaleAddVector(struct NNS_VECTOR* dst,
                      struct NNS_VECTOR* vec1,
                      struct NNS_VECTOR* vec2,
                      float scale);
void nnSubtractVector(struct NNS_VECTOR* dst, struct NNS_VECTOR* vec1, struct NNS_VECTOR* vec2);
void nnTransformVector(struct NNS_VECTOR* dst, float (*mtx)[4][4], struct NNS_VECTOR* src);
void nnTransformNormalVector(struct NNS_VECTOR* dst, float (*mtx)[4][4], struct NNS_VECTOR* src);
void nnSetUpVectorFast(struct NNS_VECTORFAST* dst, float x, float y, float z);
void nnAddVectorFast(struct NNS_VECTORFAST* dst,
                     struct NNS_VECTORFAST* vec1,
                     struct NNS_VECTORFAST* vec2);
void nnCrossProductVectorFast(struct NNS_VECTORFAST* dst,
                              struct NNS_VECTORFAST* vec1,
                              struct NNS_VECTORFAST* vec2);
void nnCopyVectorFast(struct NNS_VECTORFAST* dst, struct NNS_VECTORFAST* src);
float nnDotProductVectorFast(struct NNS_VECTORFAST* vec1, struct NNS_VECTORFAST* vec2);
float nnLengthVectorFast(struct NNS_VECTORFAST* vec);
float nnDistanceVectorFast(struct NNS_VECTORFAST* vec1, struct NNS_VECTORFAST* vec2);
float nnLengthSqVectorFast(struct NNS_VECTORFAST* vec);
float nnDistanceSqVectorFast(struct NNS_VECTORFAST* vec1, struct NNS_VECTORFAST* vec2);
enum NNE_BOOL nnNormalizeVectorFast(struct NNS_VECTORFAST* dst, struct NNS_VECTORFAST* src);
void nnScaleVectorFast(struct NNS_VECTORFAST* dst, struct NNS_VECTORFAST* src, float scale);
void nnScaleAddVectorFast(struct NNS_VECTORFAST* dst,
                          struct NNS_VECTORFAST* vec1,
                          struct NNS_VECTORFAST* vec2,
                          float scale);
void nnSubtractVectorFast(struct NNS_VECTORFAST* dst,
                          struct NNS_VECTORFAST* vec1,
                          struct NNS_VECTORFAST* vec2);
void nnTransformVectorFast(struct NNS_VECTORFAST* dst,
                           float (*mtx)[4][4],
                           struct NNS_VECTORFAST* src);
void nnTransformNormalVectorFast(struct NNS_VECTORFAST* dst,
                                 float (*mtx)[4][4],
                                 struct NNS_VECTORFAST* src);
void nnCopyMatrixTranslationVector(struct NNS_VECTOR* dst, float (*mtx)[4][4]);
void nnCopyMatrixTranslationVectorFast(struct NNS_VECTORFAST* dst, float (*mtx)[4][4]);

#ifdef __cplusplus
}
#endif

#endif // NNVECTOR_H
