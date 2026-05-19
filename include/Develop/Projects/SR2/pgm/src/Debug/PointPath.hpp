#ifndef POINTPATH_HPP
#define POINTPATH_HPP

#include "types.h"

// total size: 0x4
struct stcPointPath {
    u8 bIsDrawCoursePath;              // offset 0x0, size 0x1
    u8 bIsDisableDrawCoursePathSphere; // offset 0x1, size 0x1
    u8 bIsDrawComPath;                 // offset 0x2, size 0x1
    u8 bIsDisableDrawComPathSphere;    // offset 0x3, size 0x1
};

#endif // POINTPATH_HPP
