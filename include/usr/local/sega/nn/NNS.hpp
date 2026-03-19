#ifndef NNS_HPP
#define NNS_HPP

// total size: 0xC
class NNS_VECTOR {
public:
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
};

// total size: 0x10
class NNS_VECTORFAST {
public:
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
    float w; // offset 0xC, size 0x4
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

// total size: 0x8
class NNS_MATERIALPTR {
public:
    unsigned int fType;  // offset 0x0, size 0x4
    void * pMaterial;    // offset 0x4, size 0x4
};

// total size: 0x8
class NNS_VTXLISTPTR {
public:
    unsigned int fType;  // offset 0x0, size 0x4
    void * pVtxList;     // offset 0x4, size 0x4
};

// total size: 0x8
class NNS_PRIMLISTPTR {
public:
    unsigned int fType;  // offset 0x0, size 0x4
    void * pPrimList;    // offset 0x4, size 0x4
};

// forward declarations
class NNS_MESHSET;
class _NNS_NODEEX;
class _NNS_TEXLIST;

// total size: 0x4
class NNS_NODEEXPTR {
public:
    class _NNS_NODEEX * pNodeEx; // offset 0x0, size 0x4
};

// total size: 0x90
class NNS_NODE {
public:
    unsigned int fType;                 // offset 0x0,  size 0x4
    signed short iMatrix;               // offset 0x4,  size 0x2
    signed short iParent;               // offset 0x6,  size 0x2
    signed short iChild;                // offset 0x8,  size 0x2
    signed short iSibling;              // offset 0xA,  size 0x2
    class NNS_VECTOR Translation;       // offset 0xC,  size 0xC
    struct NNS_ROTATE_A32 Rotation;     // offset 0x18, size 0xC
    class NNS_VECTOR Scaling;           // offset 0x24, size 0xC
    float InvInitMtx[4][4];             // offset 0x30, size 0x40
    class NNS_VECTOR Center;            // offset 0x70, size 0xC
    float Radius;                       // offset 0x7C, size 0x4
    unsigned int User;                  // offset 0x80, size 0x4
    union {
        float SIIKBoneLength;           // offset 0x84, size 0x4
        float BoundingBoxX;             // offset 0x84, size 0x4
    };
    float BoundingBoxY;                 // offset 0x88, size 0x4
    float BoundingBoxZ;                 // offset 0x8C, size 0x4
};

// total size: 0x14
class NNS_SUBOBJ {
public:
    unsigned int fType;             // offset 0x0,  size 0x4
    signed int nMeshset;            // offset 0x4,  size 0x4
    class NNS_MESHSET * pMeshsetList; // offset 0x8, size 0x4
    signed int nTex;                // offset 0xC,  size 0x4
    signed int * pTexNumList;       // offset 0x10, size 0x4
};

// total size: 0x24
class NNS_MESHSET {
public:
    class NNS_VECTOR Center; // offset 0x0,  size 0xC
    float Radius;            // offset 0xC,  size 0x4
    signed int iNode;        // offset 0x10, size 0x4
    signed int iMatrix;      // offset 0x14, size 0x4
    signed int iMaterial;    // offset 0x18, size 0x4
    signed int iVtxList;     // offset 0x1C, size 0x4
    signed int iPrimList;    // offset 0x20, size 0x4
};

// total size: 0x58
struct NNS_OBJECT {
    class NNS_VECTOR Center;                    // offset 0x0,  size 0xC
    float Radius;                               // offset 0xC,  size 0x4
    signed int nMaterial;                       // offset 0x10, size 0x4
    class NNS_MATERIALPTR * pMatPtrList;        // offset 0x14, size 0x4
    signed int nVtxList;                        // offset 0x18, size 0x4
    class NNS_VTXLISTPTR * pVtxListPtrList;     // offset 0x1C, size 0x4
    signed int nPrimList;                       // offset 0x20, size 0x4
    class NNS_PRIMLISTPTR * pPrimListPtrList;   // offset 0x24, size 0x4
    signed int nNode;                           // offset 0x28, size 0x4
    signed int MaxNodeDepth;                    // offset 0x2C, size 0x4
    union {
        class NNS_NODE * pNodeList;             // offset 0x30, size 0x4
        class NNS_NODEEXPTR * pNodeExPtrList;   // offset 0x30, size 0x4
    };
    signed int nMtxPal;                         // offset 0x34, size 0x4
    signed int nSubobj;                         // offset 0x38, size 0x4
    class NNS_SUBOBJ * pSubobjList;             // offset 0x3C, size 0x4
    signed int nTex;                            // offset 0x40, size 0x4
    unsigned int fType;                         // offset 0x44, size 0x4
    signed int Version;                         // offset 0x48, size 0x4
    float BoundingBoxX;                         // offset 0x4C, size 0x4
    float BoundingBoxY;                         // offset 0x50, size 0x4
    float BoundingBoxZ;                         // offset 0x54, size 0x4
};

// total size: 0x8
class clsModelType_OB_TX {
public:
    struct NNS_OBJECT * m_psObject;     // offset 0x0, size 0x4
    class _NNS_TEXLIST * m_psTexList;   // offset 0x4, size 0x4
};

// total size: 0x4
class clsModelType_OB {
public:
    struct NNS_OBJECT * m_psObject; // offset 0x0, size 0x4
};

#ifdef __cplusplus
extern "C" {
#endif

void nnSetUpVectorFast(class NNS_VECTORFAST * dst, float x, float y, float z);

#ifdef __cplusplus
}
#endif

#endif // NNS_HPP
