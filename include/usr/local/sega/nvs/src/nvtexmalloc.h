#ifndef NVTEXMALLOC_H
#define NVTEXMALLOC_H

// total size: 0x14
struct NVS_ALLOC_AREA {
    struct NVS_ALLOC_AREA* next;   // offset 0x0, size 0x4
    struct NVS_ALLOC_AREA* before; // offset 0x4, size 0x4
    signed int flag;               // offset 0x8, size 0x4
    unsigned int addr;             // offset 0xC, size 0x4
    unsigned int size;             // offset 0x10, size 0x4
};

void nvInitTexMemory(unsigned int localptr, unsigned int size);
void nvSetTexArea(unsigned int localptr, unsigned int size);
signed int nvInitTexArea();
unsigned int nvTexMalloc(unsigned int size);
void nvTexFree(unsigned int addr);
void nvCalcTexAreaFree(unsigned int* SizeOfTexture, unsigned int* MaxBlockSizeOfTexture);

#endif // NVTEXMALLOC_H
