#ifndef FLASHLINE_HPP
#define FLASHLINE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/BaseEffect.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"

// total size: 0xE0
class clsTrickXFlashLineEffect_Task : public clsBaseEffect_Task {
public:
    virtual ~clsTrickXFlashLineEffect_Task() {}
    virtual void execute();
    virtual void draw();

    u32 m_u32ViewNo;        // offset 0xD0, size 0x4
    enum enmNo m_ePlayerNo; // offset 0xD4, size 0x4
};

#endif // FLASHLINE_HPP
