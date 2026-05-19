#ifndef STAGE09_HPP
#define STAGE09_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Stage/DivStage.hpp"

class clsStage09_Task : public clsDivStage_Task {
public:
    virtual ~clsStage09_Task() {}

    virtual void reset();

    f32 m_af32ThunderFrame[4]; // offset 0x498, size 0x10
};

#endif // STAGE09_HPP
