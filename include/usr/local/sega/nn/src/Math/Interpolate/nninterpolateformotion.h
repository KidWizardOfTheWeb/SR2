#ifndef NNINTERPOLATEFORMOTION_H
#define NNINTERPOLATEFORMOTION_H

#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"

struct NNS_ROTATE_A16;
struct NNS_MOTION_KEY_FLOAT;
struct NNS_MOTION_KEY_FLOAT3;
struct NNS_MOTION_KEY_ANGLE32;
struct NNS_MOTION_KEY_ROTATION_A32;
struct NNS_MOTION_KEY_ANGLE16;
struct NNS_MOTION_KEY_ROTATION_A16;
struct NNS_MOTION_KEY_FLOAT_BEZIER;
struct NNS_MOTION_KEY_ANGLE32_BEZIER;
struct NNS_MOTION_KEY_QUATERNION;
struct NNS_MOTION_KEY_FLOAT_SI_SPLINE;
struct NNS_MOTION_KEY_ANGLE32_SI_SPLINE;
struct NNS_MOTION_KEY_ANGLE16_SI_SPLINE;
struct NNS_MOTION_KEY_UINT32;
struct NNS_MOTION_KEY_SINT32;
struct NNS_MOTION_KEY_TEXCOORD;

// total size: 0x10
struct NNS_MOTION_BEZIER_HANDLE {
    struct NNS_VECTOR2D In;  // offset 0x0, size 0x8
    struct NNS_VECTOR2D Out; // offset 0x8, size 0x8
};

// total size: 0x8
struct NNS_MOTION_SI_SPLINE_HANDLE {
    float In;  // offset 0x0, size 0x4
    float Out; // offset 0x4, size 0x4
};

extern float nngNodeUserMotionTriggerTime;

void nnInterpolateConstantF1(struct NNS_MOTION_KEY_FLOAT* vk,
                             signed int nKey,
                             float frame,
                             float* val);
void nnInterpolateConstantF3(struct NNS_MOTION_KEY_FLOAT3* vk,
                             signed int nKey,
                             float frame,
                             struct NNS_VECTOR* val);
void nnInterpolateConstantA32_1(struct NNS_MOTION_KEY_ANGLE32* vk,
                                signed int nKey,
                                float frame,
                                signed int* val);
void nnInterpolateConstantA32_3(struct NNS_MOTION_KEY_ROTATION_A32* vk,
                                signed int nKey,
                                float frame,
                                struct NNS_ROTATE_A32* val);
void nnInterpolateConstantA16_1(struct NNS_MOTION_KEY_ANGLE16* vk,
                                signed int nKey,
                                float frame,
                                signed short* val);
void nnInterpolateConstantA16_3(struct NNS_MOTION_KEY_ROTATION_A16* vk,
                                signed int nKey,
                                float frame,
                                struct NNS_ROTATE_A16* val);
void nnInterpolateLinearF1(struct NNS_MOTION_KEY_FLOAT* vk,
                           signed int nKey,
                           float frame,
                           float* val);
void nnInterpolateLinearF3(struct NNS_MOTION_KEY_FLOAT3* vk,
                           signed int nKey,
                           float frame,
                           struct NNS_VECTOR* val);
void nnInterpolateLinearA32_1(struct NNS_MOTION_KEY_ANGLE32* vk,
                              signed int nKey,
                              float frame,
                              signed int* val);
void nnInterpolateLinearA32_3(struct NNS_MOTION_KEY_ROTATION_A32* vk,
                              signed int nKey,
                              float frame,
                              struct NNS_ROTATE_A32* val);
void nnInterpolateLinearA16_1(struct NNS_MOTION_KEY_ANGLE16* vk,
                              signed int nKey,
                              float frame,
                              signed short* val);
void nnInterpolateLinearA16_3(struct NNS_MOTION_KEY_ROTATION_A16* vk,
                              signed int nKey,
                              float frame,
                              struct NNS_ROTATE_A16* val);
float nnSolveBezier(float f0, float h0, float f1, float h1, float frame);
void nnInterpolateBezierF1(struct NNS_MOTION_KEY_FLOAT_BEZIER* vk,
                           signed int nKey,
                           float frame,
                           float* val);
void nnInterpolateBezierA32_1(struct NNS_MOTION_KEY_ANGLE32_BEZIER* vk,
                              signed int nKey,
                              float frame,
                              signed int* val);
void nnInterpolateLerpA16_3(struct NNS_MOTION_KEY_ROTATION_A16* vk,
                            signed int nKey,
                            float frame,
                            struct NNS_QUATERNION* val,
                            unsigned int rtype);
void nnInterpolateLerpA32_3(struct NNS_MOTION_KEY_ROTATION_A32* vk,
                            signed int nKey,
                            float frame,
                            struct NNS_QUATERNION* val,
                            unsigned int rtype);
void nnInterpolateLerpQuat_4(struct NNS_MOTION_KEY_QUATERNION* vk,
                             signed int nKey,
                             float frame,
                             struct NNS_QUATERNION* val);
void nnInterpolateSlerpA16_3(struct NNS_MOTION_KEY_ROTATION_A16* vk,
                             signed int nKey,
                             float frame,
                             struct NNS_QUATERNION* val,
                             unsigned int rtype);
void nnInterpolateSlerpA32_3(struct NNS_MOTION_KEY_ROTATION_A32* vk,
                             signed int nKey,
                             float frame,
                             struct NNS_QUATERNION* val,
                             unsigned int rtype);
void nnInterpolateSlerpQuat_4(struct NNS_MOTION_KEY_QUATERNION* vk,
                              signed int nKey,
                              float frame,
                              struct NNS_QUATERNION* val);
void nnInterpolateSquadA16_3(struct NNS_MOTION_KEY_ROTATION_A16* vk,
                             signed int nKey,
                             float frame,
                             struct NNS_QUATERNION* val,
                             unsigned int rtype);
void nnInterpolateSquadA32_3(struct NNS_MOTION_KEY_ROTATION_A32* vk,
                             signed int nKey,
                             float frame,
                             struct NNS_QUATERNION* val,
                             unsigned int rtype);
void nnInterpolateSquadQuat_4(struct NNS_MOTION_KEY_QUATERNION* vk,
                              signed int nKey,
                              float frame,
                              struct NNS_QUATERNION* val);
void nnInterpolateConstantQuat_4(struct NNS_MOTION_KEY_QUATERNION* vk,
                                 signed int nKey,
                                 float frame,
                                 struct NNS_QUATERNION* val);
void nnInterpolateSISplineF1(struct NNS_MOTION_KEY_FLOAT_SI_SPLINE* vk,
                             signed int nKey,
                             float frame,
                             float* val);
void nnInterpolateSISplineA32_1(struct NNS_MOTION_KEY_ANGLE32_SI_SPLINE* vk,
                                signed int nKey,
                                float frame,
                                signed int* val);
void nnInterpolateSISplineA16_1(struct NNS_MOTION_KEY_ANGLE16_SI_SPLINE* vk,
                                signed int nKey,
                                float frame,
                                signed short* val);
void nnInterpolateConstantU1(struct NNS_MOTION_KEY_UINT32* vk,
                             signed int nKey,
                             float frame,
                             unsigned int* val);
void nnInterpolateLinearU1(struct NNS_MOTION_KEY_UINT32* vk,
                           signed int nKey,
                           float frame,
                           unsigned int* val);
enum NNE_BOOL nnInterpolateTriggerU1(struct NNS_MOTION_KEY_UINT32* vk,
                                     signed int nKey,
                                     float frame,
                                     unsigned int* val);
void nnInterpolateConstantS32_1(struct NNS_MOTION_KEY_SINT32* vk,
                                signed int nKey,
                                float frame,
                                signed int* val);
void nnInterpolateConstantF2(struct NNS_MOTION_KEY_TEXCOORD* vk,
                             signed int nKey,
                             float frame,
                             struct NNS_TEXCOORD* val);
void nnInterpolateLinearF2(struct NNS_MOTION_KEY_TEXCOORD* vk,
                           signed int nKey,
                           float frame,
                           struct NNS_TEXCOORD* val);

#endif // NNINTERPOLATEFORMOTION_H
