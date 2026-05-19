#ifndef PS2SYSTEM_HPP
#define PS2SYSTEM_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOSystem.hpp"

// total size: 0x4
class clsPfSystem : public clsSingleton<clsPfSystem>, public clsOOSystem {
public:
    clsPfSystem();

    static s32 tVBlanking_CallBack(s32 s32CaIn);

    void VWait();
    void setViewPort(u32 u32I);
    void getNowDateTime(stcDateTime* psNow);
};

#endif // PS2SYSTEM_HPP
