#ifndef NNPRINT_H
#define NNPRINT_H

// total size: 0x14
struct NNS_PRINT_BUF_PS2 {
    float x;         // offset 0x0, size 0x4
    float y;         // offset 0x4, size 0x4
    float sx;        // offset 0x8, size 0x4
    float sy;        // offset 0xC, size 0x4
    unsigned char a; // offset 0x10, size 0x1
    unsigned char r; // offset 0x11, size 0x1
    unsigned char g; // offset 0x12, size 0x1
    unsigned char b; // offset 0x13, size 0x1
};

// total size: 0x30
struct NNS_SCREEN {
    float xad;    // offset 0x0, size 0x4
    float yad;    // offset 0x4, size 0x4
    float cx;     // offset 0x8, size 0x4
    float cy;     // offset 0xC, size 0x4
    float ooxad;  // offset 0x10, size 0x4
    float ooyad;  // offset 0x14, size 0x4
    float dist;   // offset 0x18, size 0x4
    float ax;     // offset 0x1C, size 0x4
    float ay;     // offset 0x20, size 0x4
    float aspect; // offset 0x24, size 0x4
    float w;      // offset 0x28, size 0x4
    float h;      // offset 0x2C, size 0x4
};

extern unsigned char nngPrintTexture[8224];
extern struct NNS_SCREEN nngScreen;

unsigned int nnGetPrintBufferSize(signed int n);
void nnInitPrint(void* buf, signed int n, void* font);
void nnExitPrint();
void nnSetPrintSize(float sizex, float sizey);
void nnSetPrintColor(unsigned int c);
void nnPrint(signed int x, signed int y, char* fmt);
void nnFlushPrint();

#endif // NNPRINT_H
