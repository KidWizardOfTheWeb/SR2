#ifndef PLAYERGRAVITYWAVE_HPP
#define PLAYERGRAVITYWAVE_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/GravityWave/PS2_GravityWave.hpp"

// total size: 0xE0
class clsPlayerGravityWave_Task : public clsSingleton<clsPlayerGravityWave_Task>,
                                  public clsGravityWave_Task {
public:
    virtual ~clsPlayerGravityWave_Task() {}
};

#endif // PLAYERGRAVITYWAVE_HPP
