#ifndef STAGENAME2D_HPP
#define STAGENAME2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"

// total size: 0x5C
class clsStageName2D_Task : public clsTemporary2D_Task {
public:
    clsStageName2D_Task();
    virtual ~clsStageName2D_Task();
    virtual void execute();
    virtual void draw();

    u8 m_bEndFlag; // offset 0x58, size 0x1
};

#endif // STAGENAME2D_HPP
