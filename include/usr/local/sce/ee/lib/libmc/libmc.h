#ifndef LIBMC_H
#define LIBMC_H

// total size: 0x8
struct sceMcStDateTime {
    unsigned char Resv2; // offset 0x0, size 0x1
    unsigned char Sec;   // offset 0x1, size 0x1
    unsigned char Min;   // offset 0x2, size 0x1
    unsigned char Hour;  // offset 0x3, size 0x1
    unsigned char Day;   // offset 0x4, size 0x1
    unsigned char Month; // offset 0x5, size 0x1
    unsigned short Year; // offset 0x6, size 0x2
};

// total size: 0x3C4
struct sceMcIconSys {
    unsigned char Head[4];       // offset 0x0, size 0x4
    unsigned short Reserv1;      // offset 0x4, size 0x2
    unsigned short OffsLF;       // offset 0x6, size 0x2
    unsigned int Reserv2;        // offset 0x8, size 0x4
    unsigned int TransRate;      // offset 0xC, size 0x4
    signed int BgColor[4][4];    // offset 0x10, size 0x40
    float LightDir[3][4];        // offset 0x50, size 0x30
    float LightColor[3][4];      // offset 0x80, size 0x30
    float Ambient[4];            // offset 0xB0, size 0x10
    unsigned char TitleName[68]; // offset 0xC0, size 0x44
    unsigned char FnameView[64]; // offset 0x104, size 0x40
    unsigned char FnameCopy[64]; // offset 0x144, size 0x40
    unsigned char FnameDel[64];  // offset 0x184, size 0x40
    unsigned char Reserve3[512]; // offset 0x1C4, size 0x200
};

// total size: 0x40
struct sceMcTblGetDir {
    struct sceMcStDateTime _Create; // offset 0x0, size 0x8
    struct sceMcStDateTime _Modify; // offset 0x8, size 0x8
    unsigned int FileSizeByte;      // offset 0x10, size 0x4
    unsigned short AttrFile;        // offset 0x14, size 0x2
    unsigned short Reserve1;        // offset 0x16, size 0x2
    unsigned int Reserve2;          // offset 0x18, size 0x4
    unsigned int PdaAplNo;          // offset 0x1C, size 0x4
    unsigned char EntryName[32];    // offset 0x20, size 0x20
};

#endif // LIBMC_H
