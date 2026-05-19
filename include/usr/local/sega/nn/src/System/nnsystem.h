#ifndef NNSYSTEM_H
#define NNSYSTEM_H

enum NNE_BOOL {
    NNE_FALSE = 0,
    NNE_OFF = 0,
    NNE_TRUE = 1,
    NNE_ON = 1,
};

enum NNE_PROJECTION_TYPE {
    NNE_PROJECTION_TYPE_PERSPECTIVE = 0,
    NNE_PROJECTION_TYPE_ORTHO = 1,
};

// total size: 0x14
struct NNS_CONFIG_PS2 {
    unsigned short GsInterMode;      // offset 0x0, size 0x2
    unsigned short GsOutMode;        // offset 0x2, size 0x2
    unsigned short GsFFMode;         // offset 0x4, size 0x2
    unsigned short DrawBuffPsm;      // offset 0x6, size 0x2
    unsigned short DrawBuffWidth;    // offset 0x8, size 0x2
    unsigned short DrawBuffHeight;   // offset 0xA, size 0x2
    unsigned short ResolutionWidth;  // offset 0xC, size 0x2
    unsigned short ResolutionHeight; // offset 0xE, size 0x2
    unsigned short DrawBuffZbp;      // offset 0x10, size 0x2
    unsigned short DrawBuffZPsm;     // offset 0x12, size 0x2
};

// total size: 0x20
struct NNS_BINCNK_FILEHEADER {
    unsigned int Id; // offset 0x0, size 0x4
    int OfsNextId;   // offset 0x4, size 0x4
    int nChunk;      // offset 0x8, size 0x4
    int OfsData;     // offset 0xC, size 0x4
    int SizeData;    // offset 0x10, size 0x4
    int OfsNOF0;     // offset 0x14, size 0x4
    int SizeNOF0;    // offset 0x18, size 0x4
    int Version;     // offset 0x1C, size 0x4
};

extern char* nngVersion;
extern unsigned char* nngBuildAddr;
extern double nngZMulPs2;
extern struct NNS_CONFIG_PS2 nngConfigPs2;

void nnInitSystemPS2();
void nnConfigureSystemPS2(struct NNS_CONFIG_PS2* pConfigPs2);
void nnSetProjection(float (*mtx)[4][4], enum NNE_PROJECTION_TYPE type);

#endif // NNSYSTEM_H
