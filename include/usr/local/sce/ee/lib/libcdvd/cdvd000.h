#ifndef CDVD000_H
#define CDVD000_H

// total size: 0x8
struct sceCdCLOCK {
    unsigned char stat;   // offset 0x0, size 0x1
    unsigned char second; // offset 0x1, size 0x1
    unsigned char minute; // offset 0x2, size 0x1
    unsigned char hour;   // offset 0x3, size 0x1
    unsigned char pad;    // offset 0x4, size 0x1
    unsigned char day;    // offset 0x5, size 0x1
    unsigned char month;  // offset 0x6, size 0x1
    unsigned char year;   // offset 0x7, size 0x1
};

#endif // CDVD000_H
