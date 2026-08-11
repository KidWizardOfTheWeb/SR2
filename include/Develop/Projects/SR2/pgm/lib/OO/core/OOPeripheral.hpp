#ifndef OOPERIPHERAL_HPP
#define OOPERIPHERAL_HPP

#include "types.h"

// total size: 0x10
struct stcActivePeripheral {
    u32 m_u32Beta; // offset 0x0, size 0x4
    u32 m_u32Trig; // offset 0x4, size 0x4
    u32 m_u32Rel;  // offset 0x8, size 0x4
    u32 m_u32Rep;  // offset 0xC, size 0x4
};

// total size: 0x1C
class clsOOPeripheral {
public:
    // total size: 0x20
    struct stcPeripheral {
        u32 m_u32Beta;         // offset 0x0, size 0x4
        u32 m_u32Trig;         // offset 0x4, size 0x4
        u32 m_u32Rel;          // offset 0x8, size 0x4
        u32 m_u32Rep;          // offset 0xC, size 0x4
        u32 m_u32RepCnt;       // offset 0x10, size 0x4
        u32 m_u32LoopRepCnt;   // offset 0x14, size 0x4
        u32 m_u32UnInputFrame; // offset 0x18, size 0x4
        u8 m_u8PeripheralNo;   // offset 0x1C, size 0x1
        u8 m_u8ConnectNo;      // offset 0x1D, size 0x1
        u8 m_u8State;          // offset 0x1E, size 0x1
        u8 m_u8Paddin[1];      // offset 0x1F, size 0x1
    };

    clsOOPeripheral();
    virtual ~clsOOPeripheral();

    u32 getActiveRel() const { return m_sActivePeripheral.m_u32Rel; }
    u32 getActiveBetaBool(u32 u32Bit) const
    {
        return (m_sActivePeripheral.m_u32Beta & u32Bit) != 0;
    }
    u32 getActiveTrig(u32 u32Bit) const { return m_sActivePeripheral.m_u32Trig & u32Bit; }
    u32 getActiveRep(u32 u32Bit) const { return m_sActivePeripheral.m_u32Rep & u32Bit; }
    u32 getActiveRel(u32 u32Bit) const { return m_sActivePeripheral.m_u32Rel & u32Bit; }
    u32 getActiveBetaEq(u32 u32Bit) const { return m_sActivePeripheral.m_u32Beta == u32Bit; }

    stcActivePeripheral m_sActivePeripheral; // offset 0x4, size 0x10
    u32 m_u32ConnectNum;                     // offset 0x14, size 0x4
    u32 m_u32BasePadCnt;                     // offset 0x18, size 0x4
};

#endif // OOPERIPHERAL_HPP
