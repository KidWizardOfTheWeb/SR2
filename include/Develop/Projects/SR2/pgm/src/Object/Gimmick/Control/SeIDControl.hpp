#ifndef SEIDCONTROL_HPP
#define SEIDCONTROL_HPP

#include "types.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"

// total size: 0x10
class clsSeIDControl {
public:
    clsSeIDControl()
    {
        m_u16PlayFlg = 0;
        memset(m_as16SfID, -1, sizeof(m_as16SfID));
    }
    virtual ~clsSeIDControl() {}
    virtual void play(u16 u16SeID) {}
    virtual void stop(u16 u16SeID) {}

    s16 m_as16SfID[4]; // offset 0x4, size 0x8
    u16 m_u16PlayFlg;  // offset 0xC, size 0x2
};

#endif // SEIDCONTROL_HPP
