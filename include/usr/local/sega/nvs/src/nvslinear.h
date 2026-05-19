#ifndef NVSLINEAR_H
#define NVSLINEAR_H

struct NVS_SVROBJ;
struct PXS_TEXOBJ2;

// total size: 0x10
struct NVS_TIPSVRINFO {
    signed int isTip;           // offset 0x0, size 0x4
    struct PXS_TEXOBJ2* texobj; // offset 0x4, size 0x4
    void* dmabuf;               // offset 0x8, size 0x4
    unsigned int type;          // offset 0xC, size 0x4
};

void nvSetupSVRTexObjLinear(struct NVS_SVROBJ* svrobj,
                            unsigned int localptr,
                            unsigned int clutptr,
                            unsigned int cluttype,
                            unsigned int mag,
                            unsigned int min);
unsigned int nvCalcSVRTexLocalMemorySizeLinear(struct NVS_SVROBJ* svrobj);

#endif // NVSLINEAR_H
