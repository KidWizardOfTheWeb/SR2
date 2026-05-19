#ifndef BOSSGRAVITYWAVE_HPP
#define BOSSGRAVITYWAVE_HPP

#include "Develop/Projects/SR2/pgm/src/Effect/Post/GravityWave/PS2_GravityWave.hpp"

class clsBossGravityWave_Task : public clsGravityWave_Task {
public:
    virtual ~clsBossGravityWave_Task();
    virtual void execute();
    virtual void draw();

    u8 m_bInitFlag; // offset 0xD0, size 0x1
};

#endif // BOSSGRAVITYWAVE_HPP
