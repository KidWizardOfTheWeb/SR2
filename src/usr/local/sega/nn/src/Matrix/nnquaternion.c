#include "usr/local/sega/nn/src/Matrix/nnquaternion.h"

void nnCopyQuaternion(struct NNS_QUATERNION* dst, struct NNS_QUATERNION* src)
{
}

void nnMultiplyQuaternion(struct NNS_QUATERNION* dst,
                          struct NNS_QUATERNION* quat1,
                          struct NNS_QUATERNION* quat2)
{
}

enum NNE_BOOL nnNormalizeQuaternion(struct NNS_QUATERNION* dst, struct NNS_QUATERNION* src)
{
}

enum NNE_BOOL nnInvertQuaternion(struct NNS_QUATERNION* dst, struct NNS_QUATERNION* src)
{
}

void nnExpQuaternion(struct NNS_QUATERNION* dst, struct NNS_QUATERNION* src)
{
}

void nnSplineQuaternion(struct NNS_QUATERNION* dst,
                        struct NNS_QUATERNION* quatprev,
                        struct NNS_QUATERNION* quat,
                        struct NNS_QUATERNION* quatnext)
{
}

void nnLerpQuaternion(struct NNS_QUATERNION* dst,
                      struct NNS_QUATERNION* quat1,
                      struct NNS_QUATERNION* quat2,
                      float t)
{
}

void nnSlerpQuaternion(struct NNS_QUATERNION* dst,
                       struct NNS_QUATERNION* quat1,
                       struct NNS_QUATERNION* quat2,
                       float t)
{
}

void nnSquadQuaternion(struct NNS_QUATERNION* dst,
                       struct NNS_QUATERNION* quat1,
                       struct NNS_QUATERNION* quata,
                       struct NNS_QUATERNION* quatb,
                       struct NNS_QUATERNION* quat2,
                       float t)
{
}

void nnMakeUnitQuaternion(struct NNS_QUATERNION* dst)
{
}

void nnMakeRotateAxisQuaternion(
    struct NNS_QUATERNION* dst, float vx, float vy, float vz, signed int ang)
{
}

void nnMakeRotateMatrixQuaternion(struct NNS_QUATERNION* dst, float (*mtx)[4][4])
{
}

void nnMakeRotateXYZQuaternion(struct NNS_QUATERNION* dst,
                               signed int rx,
                               signed int ry,
                               signed int rz)
{
}

void nnMakeRotateXZYQuaternion(struct NNS_QUATERNION* dst,
                               signed int rx,
                               signed int ry,
                               signed int rz)
{
}

void nnMakeRotateZXYQuaternion(struct NNS_QUATERNION* dst,
                               signed int rx,
                               signed int ry,
                               signed int rz)
{
}
