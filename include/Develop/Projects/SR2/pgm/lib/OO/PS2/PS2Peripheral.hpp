#ifndef PS2PERIPHERAL_HPP
#define PS2PERIPHERAL_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOPeripheral.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/System/SrPad.hpp"

// total size: 0x24
class clsPfPeripheral : public clsSingleton<clsPfPeripheral>, public clsOOPeripheral {
public:
    virtual ~clsPfPeripheral() {}

    clsPfPeripheral();
    void reinit();
    virtual void destroy();
    virtual void read();
    void setRumble(u32 u32NoI, u32 u32FrameIn);
    void setAllRumble(u32 u32FrameI, s32 s32PadNumI);
    void setConfigueDisableAllRumble(bool bI);
    u8 getConfigueDisableAllRumble();
    u8 isCheckingAll();
    s32 getActiveTrigNo(u32 u32PI);
    bool getTrigBool(u32, u32) const { return false; }

    static ::stcPeripheral m_asPeripheral[4];

    u32 m_u32MultiTapStatus; // offset 0x20, size 0x4
};

#endif // PS2PERIPHERAL_HPP
