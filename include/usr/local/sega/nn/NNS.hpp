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

// total size: 0x10
class NNS_QUATERNION {
public:
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
    float w; // offset 0xC, size 0x4
};

// total size: 0x10
class NNS_SPHERE {
public:
    class NNS_VECTOR c; // offset 0x0, size 0xC
    float r; // offset 0xC, size 0x4
};

// total size: 0x1C
class NNS_CAPSULE {
public:
    class NNS_VECTOR c1; // offset 0x0, size 0xC
    class NNS_VECTOR c2; // offset 0xC, size 0xC
    float r; // offset 0x18, size 0x4
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

class sceGsTex1 {
public:
    unsigned long LCM : 1;
    unsigned long pad01 : 1;
    unsigned long MXL : 3;
    unsigned long MMAG : 1;
    unsigned long MMIN : 3;
    unsigned long MTBA : 1;
    unsigned long pad10 : 9;
    unsigned long L : 2;
    unsigned long pad21 : 11;
    unsigned long K : 12;
    unsigned long pad44 : 20;
};

class sceGsTex0 {
public:
    unsigned long TBP0 : 14;
    unsigned long TBW : 6;
    unsigned long PSM : 6;
    unsigned long TW : 4;
    unsigned long TH : 4;
    unsigned long TCC : 1;
    unsigned long TFX : 2;
    unsigned long CBP : 14;
    unsigned long CPSM : 4;
    unsigned long CSM : 1;
    unsigned long CSA : 5;
    unsigned long CLD : 3;
};

class sceGsMiptbp1 {
public:
    unsigned long TBP1 : 14;
    unsigned long TBW1 : 6;
    unsigned long TBP2 : 14;
    unsigned long TBW2 : 6;
    unsigned long TBP3 : 14;
    unsigned long TBW3 : 6;
    unsigned long pad60 : 4;
};

class sceGsMiptbp2 {
public:
    unsigned long TBP4 : 14;
    unsigned long TBW4 : 6;
    unsigned long TBP5 : 14;
    unsigned long TBW5 : 6;
    unsigned long TBP6 : 14;
    unsigned long TBW6 : 6;
    unsigned long pad60 : 4;
};

class PXS_TEXREG {
public:
    class sceGsTex1 tex1; // offset 0x0, size 0x8
    class sceGsTex0 tex0; // offset 0x8, size 0x8
    class sceGsMiptbp1 miptbp1; // offset 0x10, size 0x8
    class sceGsMiptbp2 miptbp2; // offset 0x18, size 0x8
};

class PXS_TEXOBJ {
public:
    class PXS_TEXREG texReg; // offset 0x0, size 0x20
};

class NVS_GBIXHEADER {
public:
    unsigned int globalIndex; // offset 0x0, size 0x4
    unsigned int bank; // offset 0x4, size 0x4
};

class NVS_SVRHEADER {
public:
    unsigned short type; // offset 0x0, size 0x2
    unsigned short miplevel; // offset 0x2, size 0x2
    unsigned short width; // offset 0x4, size 0x2
    unsigned short height; // offset 0x6, size 0x2
};

class NVS_SVROBJ {
public:
    class NVS_GBIXHEADER gbixh; // offset 0x0, size 0x8
    class NVS_SVRHEADER svrh; // offset 0x8, size 0x8
    class PXS_TEXOBJ texobj; // offset 0x10, size 0x20
};

// total size: 0x50
class _NNS_TEXINFO {
public:
    class NVS_SVROBJ SvrObj; // offset 0x0, size 0x30
    void * pMainMemory; // offset 0x30, size 0x4
    void * pLocalMemory; // offset 0x34, size 0x4
    unsigned int nLocalBytes; // offset 0x38, size 0x4
    unsigned int nDmaTagBytes; // offset 0x3C, size 0x4
    unsigned int GlobalIndex; // offset 0x40, size 0x4
    unsigned int Bank; // offset 0x44, size 0x4
    unsigned short MinFilter; // offset 0x48, size 0x2
    unsigned short MagFilter; // offset 0x4A, size 0x2
    unsigned int Flag; // offset 0x4C, size 0x4
};

// total size: 0x8
class _NNS_TEXLIST {
public:
    signed int nTex; // offset 0x0, size 0x4
    class _NNS_TEXINFO * pTexInfoList; // offset 0x4, size 0x4
};

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
