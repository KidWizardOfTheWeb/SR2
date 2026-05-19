#ifndef NNOBJECT_H
#define NNOBJECT_H

#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// Forward declarations
struct NNS_MESHSET;
struct _NNS_NODEEX;
struct NNS_MATERIALPTR;
struct NNS_VTXLISTPTR;
struct NNS_PRIMLISTPTR;

// total size: 0x4
struct NNS_NODEEXPTR {
    struct _NNS_NODEEX* pNodeEx; // offset 0x0, size 0x4
};

// total size: 0x90
struct NNS_NODE {
    unsigned int fType;             // offset 0x0,  size 0x4
    signed short iMatrix;           // offset 0x4,  size 0x2
    signed short iParent;           // offset 0x6,  size 0x2
    signed short iChild;            // offset 0x8,  size 0x2
    signed short iSibling;          // offset 0xA,  size 0x2
    struct NNS_VECTOR Translation;  // offset 0xC,  size 0xC
    struct NNS_ROTATE_A32 Rotation; // offset 0x18, size 0xC
    struct NNS_VECTOR Scaling;      // offset 0x24, size 0xC
    float InvInitMtx[4][4];         // offset 0x30, size 0x40
    struct NNS_VECTOR Center;       // offset 0x70, size 0xC
    float Radius;                   // offset 0x7C, size 0x4
    unsigned int User;              // offset 0x80, size 0x4
    union {
        float SIIKBoneLength; // offset 0x84, size 0x4
        float BoundingBoxX;   // offset 0x84, size 0x4
    };
    float BoundingBoxY; // offset 0x88, size 0x4
    float BoundingBoxZ; // offset 0x8C, size 0x4
};

// total size: 0x14
struct NNS_SUBOBJ {
    unsigned int fType;               // offset 0x0,  size 0x4
    signed int nMeshset;              // offset 0x4,  size 0x4
    struct NNS_MESHSET* pMeshsetList; // offset 0x8,  size 0x4
    signed int nTex;                  // offset 0xC,  size 0x4
    signed int* pTexNumList;          // offset 0x10, size 0x4
};

// total size: 0x24
struct NNS_MESHSET {
    struct NNS_VECTOR Center; // offset 0x0,  size 0xC
    float Radius;             // offset 0xC,  size 0x4
    signed int iNode;         // offset 0x10, size 0x4
    signed int iMatrix;       // offset 0x14, size 0x4
    signed int iMaterial;     // offset 0x18, size 0x4
    signed int iVtxList;      // offset 0x1C, size 0x4
    signed int iPrimList;     // offset 0x20, size 0x4
};

// total size: 0x58
struct NNS_OBJECT {
    struct NNS_VECTOR Center;                 // offset 0x0,  size 0xC
    float Radius;                             // offset 0xC,  size 0x4
    signed int nMaterial;                     // offset 0x10, size 0x4
    struct NNS_MATERIALPTR* pMatPtrList;      // offset 0x14, size 0x4
    signed int nVtxList;                      // offset 0x18, size 0x4
    struct NNS_VTXLISTPTR* pVtxListPtrList;   // offset 0x1C, size 0x4
    signed int nPrimList;                     // offset 0x20, size 0x4
    struct NNS_PRIMLISTPTR* pPrimListPtrList; // offset 0x24, size 0x4
    signed int nNode;                         // offset 0x28, size 0x4
    signed int MaxNodeDepth;                  // offset 0x2C, size 0x4
    union {
        struct NNS_NODE* pNodeList;           // offset 0x30, size 0x4
        struct NNS_NODEEXPTR* pNodeExPtrList; // offset 0x30, size 0x4
    };
    signed int nMtxPal;             // offset 0x34, size 0x4
    signed int nSubobj;             // offset 0x38, size 0x4
    struct NNS_SUBOBJ* pSubobjList; // offset 0x3C, size 0x4
    signed int nTex;                // offset 0x40, size 0x4
    unsigned int fType;             // offset 0x44, size 0x4
    signed int Version;             // offset 0x48, size 0x4
    float BoundingBoxX;             // offset 0x4C, size 0x4
    float BoundingBoxY;             // offset 0x50, size 0x4
    float BoundingBoxZ;             // offset 0x54, size 0x4
};

// total size: 0x28
struct NNS_SUBMOTION {
    unsigned int fType;   // offset 0x0,  size 0x4
    unsigned int fIPType; // offset 0x4,  size 0x4
    union {
        signed int Id; // offset 0x8,  size 0x4
        struct {
            signed short Id0; // offset 0x8,  size 0x2
            signed short Id1; // offset 0xA,  size 0x2
        };
    };
    float StartFrame;     // offset 0xC,  size 0x4
    float EndFrame;       // offset 0x10, size 0x4
    float StartKeyFrame;  // offset 0x14, size 0x4
    float EndKeyFrame;    // offset 0x18, size 0x4
    signed int nKeyFrame; // offset 0x1C, size 0x4
    signed int KeySize;   // offset 0x20, size 0x4
    void* pKeyList;       // offset 0x24, size 0x4
};

// total size: 0x20
struct NNS_MOTION {
    unsigned int fType;               // offset 0x0,  size 0x4
    float StartFrame;                 // offset 0x4,  size 0x4
    float EndFrame;                   // offset 0x8,  size 0x4
    signed int nSubmotion;            // offset 0xC,  size 0x4
    struct NNS_SUBMOTION* pSubmotion; // offset 0x10, size 0x4
    float FrameRate;                  // offset 0x14, size 0x4
    unsigned int Reserved0;           // offset 0x18, size 0x4
    unsigned int Reserved1;           // offset 0x1C, size 0x4
};

#endif // NNOBJECT_H
