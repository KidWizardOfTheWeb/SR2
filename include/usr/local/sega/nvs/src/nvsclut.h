#ifndef NVSCLUT_H
#define NVSCLUT_H

struct NVS_CLUTMANAGE;
struct NVS_CLUTINFO;
struct NVS_SVROBJ;

// total size: 0x20
struct NVS_CLUTCONFIG {
    unsigned int c4localptr;      // offset 0x0, size 0x4
    void* c4hostptr;              // offset 0x4, size 0x4
    unsigned int c4num;           // offset 0x8, size 0x4
    struct NVS_CLUTMANAGE* c4mng; // offset 0xC, size 0x4
    unsigned int c8localptr;      // offset 0x10, size 0x4
    void* c8hostptr;              // offset 0x14, size 0x4
    unsigned int c8num;           // offset 0x18, size 0x4
    struct NVS_CLUTMANAGE* c8mng; // offset 0x1C, size 0x4
};

// total size: 0x100
struct NVS_CLUTMANAGE {
    unsigned short format;     // offset 0x0, size 0x2
    unsigned short entrycount; // offset 0x2, size 0x2
    unsigned short psm;        // offset 0x4, size 0x2
    unsigned short group;      // offset 0x6, size 0x2
    void* hostbuf;             // offset 0x8, size 0x4
    unsigned int localptr;     // offset 0xC, size 0x4
    unsigned int enable;       // offset 0x10, size 0x4
    unsigned int pktenable;    // offset 0x14, size 0x4
    unsigned int reserved[10]; // offset 0x18, size 0x28
    unsigned int dmabuf[48];   // offset 0x40, size 0xC0
};

// total size: 0x8
struct NVS_SVPHEADER {
    unsigned short mode; // offset 0x0, size 0x2
    short bank;          // offset 0x2, size 0x2
    short entryoffset;   // offset 0x4, size 0x2
    short entrycount;    // offset 0x6, size 0x2
};

// total size: 0x10
struct NVS_PALETTE_CONSTANT {
    unsigned int width;    // offset 0x0, size 0x4
    unsigned int height;   // offset 0x4, size 0x4
    unsigned int bits;     // offset 0x8, size 0x4
    unsigned int bankSize; // offset 0xC, size 0x4
};

extern struct NVS_CLUTMANAGE* nvg_clutmanage4;
extern struct NVS_CLUTMANAGE* nvg_clutmanage8;

signed int nvIsClut(struct NVS_SVROBJ* svrobj);
signed int nvGetClutInfo(struct NVS_CLUTINFO* info, struct NVS_SVROBJ* svrobj, unsigned int bank);

#endif // NVSCLUT_H
