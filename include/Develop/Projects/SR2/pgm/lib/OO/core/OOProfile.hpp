#ifndef OOPROFILE_HPP
#define OOPROFILE_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/Factor.hpp"
#include "Develop/Projects/SR2/pgm/src/Debug/History.hpp"
#include "types.h"

// total size: 0x1414
class clsOOProfile : public clsSingleton<clsOOProfile> {
public:
    clsOOProfile() {}
    virtual ~clsOOProfile() {}

    void begin(const c8* opc8NameIn);
    void end(const c8* opc8NameIn);

    stcFactor m_asFactor[128];   // offset 0x4, size 0xE00
    stcHistory m_asHistory[128]; // offset 0xE04, size 0x600
    c8* m_opc8BadEndName;        // offset 0x1404, size 0x4
    u32 m_u32DownLimitTime;      // offset 0x1408, size 0x4
    s16 m_s16ScrollNo;           // offset 0x140C, size 0x2
    u8 m_u8RegistNum;            // offset 0x140E, size 0x1
    u8 m_bRunning;               // offset 0x140F, size 0x1
    u8 m_u8SortType;             // offset 0x1410, size 0x1
};

#endif // OOPROFILE_HPP
