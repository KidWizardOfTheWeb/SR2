#ifndef TEMPORARY2D_HPP
#define TEMPORARY2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x58
class clsTemporary2D_Task : public clsTask {
public:
    f32 m_f32Frame; // offset 0x54, size 0x4

    clsTemporary2D_Task(u32 u32Param1, clsTask* pParam2);
    virtual ~clsTemporary2D_Task();
};

#endif
