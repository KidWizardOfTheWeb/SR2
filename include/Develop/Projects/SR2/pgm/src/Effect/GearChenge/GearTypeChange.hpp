#ifndef GEARTYPECHANGE_HPP
#define GEARTYPECHANGE_HPP

#include "Develop/Projects/SR2/pgm/src/Effect/BaseEffect.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/GearChenge/FlyAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/Gear.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x34
class clsOOMainHeap : public clsOOHeapFragment {
public:
    static clsOOMainHeap* getInstance() { return t_cInstance; }

    static clsOOMainHeap* t_cInstance;
};

// total size: 0x110
class clsGearTypeChengeEffect_Task : public clsBaseEffect_Task {
public:
    virtual ~clsGearTypeChengeEffect_Task();
    virtual void execute();
    virtual void draw();

    NNS_VECTORFAST m_sPosVecFast; // offset 0xD0, size 0x10
    enum enmGearType m_eType;     // offset 0xE0, size 0x4
    enum enmGearType m_eOldType;  // offset 0xE4, size 0x4
    f32 m_f32ScaleX;              // offset 0xE8, size 0x4
    f32 m_f32ScaleY;              // offset 0xEC, size 0x4
    f32 m_f32MaxScaleX;           // offset 0xF0, size 0x4
    f32 m_f32MaxScaleY;           // offset 0xF4, size 0x4
    f32 m_f32InitScaleX;          // offset 0xF8, size 0x4
    f32 m_f32InitScaleY;          // offset 0xFC, size 0x4
    f32 m_f32PosY;                // offset 0x100, size 0x4
};

#endif // GEARTYPECHANGE_HPP
