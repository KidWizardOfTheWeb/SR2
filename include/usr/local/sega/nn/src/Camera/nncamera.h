#ifndef NNCAMERA_H
#define NNCAMERA_H

#include "usr/local/sega/nn/src/Matrix/nnvector.h"

enum NNE_ROTATETYPE {
    NNE_ROTATETYPE_XYZ = 0,
    NNE_ROTATETYPE_XZY = 1,
    NNE_ROTATETYPE_YXZ = 2,
    NNE_ROTATETYPE_YZX = 3,
    NNE_ROTATETYPE_ZXY = 4,
    NNE_ROTATETYPE_ZYX = 5,
};

// total size: 0x8
struct NNS_CAMERAPTR {
    unsigned int fType; // offset 0x0, size 0x4
    void* pCamera;      // offset 0x4, size 0x4
};

// total size: 0x30
struct NNS_CAMERA_ROTATION {
    unsigned int User;              // offset 0x0, size 0x4
    signed int Fovy;                // offset 0x4, size 0x4
    float Aspect;                   // offset 0x8, size 0x4
    float ZNear;                    // offset 0xC, size 0x4
    float ZFar;                     // offset 0x10, size 0x4
    struct NNS_VECTOR Position;     // offset 0x14, size 0xC
    enum NNE_ROTATETYPE RotType;    // offset 0x20, size 0x4
    struct NNS_ROTATE_A32 Rotation; // offset 0x24, size 0xC
};

// total size: 0x30
struct NNS_CAMERA_TARGET_ROLL {
    unsigned int User;          // offset 0x0, size 0x4
    signed int Fovy;            // offset 0x4, size 0x4
    float Aspect;               // offset 0x8, size 0x4
    float ZNear;                // offset 0xC, size 0x4
    float ZFar;                 // offset 0x10, size 0x4
    struct NNS_VECTOR Position; // offset 0x14, size 0xC
    struct NNS_VECTOR Target;   // offset 0x20, size 0xC
    signed int Roll;            // offset 0x2C, size 0x4
};

// total size: 0x38
struct NNS_CAMERA_TARGET_UPTARGET {
    unsigned int User;          // offset 0x0, size 0x4
    signed int Fovy;            // offset 0x4, size 0x4
    float Aspect;               // offset 0x8, size 0x4
    float ZNear;                // offset 0xC, size 0x4
    float ZFar;                 // offset 0x10, size 0x4
    struct NNS_VECTOR Position; // offset 0x14, size 0xC
    struct NNS_VECTOR Target;   // offset 0x20, size 0xC
    struct NNS_VECTOR UpTarget; // offset 0x2C, size 0xC
};

// total size: 0x38
struct NNS_CAMERA_TARGET_UPVECTOR {
    unsigned int User;          // offset 0x0, size 0x4
    signed int Fovy;            // offset 0x4, size 0x4
    float Aspect;               // offset 0x8, size 0x4
    float ZNear;                // offset 0xC, size 0x4
    float ZFar;                 // offset 0x10, size 0x4
    struct NNS_VECTOR Position; // offset 0x14, size 0xC
    struct NNS_VECTOR Target;   // offset 0x20, size 0xC
    struct NNS_VECTOR UpVector; // offset 0x2C, size 0xC
};

void nnMakeTargetUpVectorCameraViewMatrix(float (*mtx)[4][4],
                                          struct NNS_CAMERA_TARGET_UPVECTOR* cam);
unsigned int nnEstimateCameraBufferSize(unsigned int type);
void nnMakeVectorCameraViewMatrix(float (*mtx)[4][4],
                                  struct NNS_VECTOR* pos,
                                  struct NNS_VECTOR* right,
                                  struct NNS_VECTOR* up,
                                  struct NNS_VECTOR* ilook);

#endif // NNCAMERA_H
