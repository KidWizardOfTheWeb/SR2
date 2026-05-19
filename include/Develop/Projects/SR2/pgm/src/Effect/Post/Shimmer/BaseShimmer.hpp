#ifndef BASESHIMMER_HPP
#define BASESHIMMER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Geometry.hpp"

// total size: 0xB0
class clsBaseShimmer_Task : public clsTask {
public:
    clsBaseShimmer_Task();
    virtual ~clsBaseShimmer_Task() {}

    virtual void execute();
    virtual void draw();

    void updateGeometry();

    s32 m_dh;                     // offset 0x54, size 0x4
    u32 m_bDraw;                  // offset 0x58, size 0x4
    stcGeometry m_asGeometry[21]; // offset 0x5C, size 0x54
};

#endif // BASESHIMMER_HPP
