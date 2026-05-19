#ifndef PS2NNLIGHT_HPP
#define PS2NNLIGHT_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOLight.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Detail_PS2.hpp"

// total size: 0x14
class clsPfLight : public clsSingleton<clsPfLight>, public clsOOLight {
public:
    clsPfLight() {}
    virtual ~clsPfLight() {}

    virtual void reinitLight(u32 ou32HardWareNumI,
                             u32 ou32SoftWareNumI,
                             const f32 (*paViewMtxI)[4][4]);
    virtual void updateLightMtx(const f32 (&pParam1)[4][4]) const {}
    virtual void sendLight(u32 ou32NoI);

    stcDetail_PS2* m_psDetail_Heap_PS2; // offset 0x10, size 0x4
};

#endif // PS2NNLIGHT_HPP
