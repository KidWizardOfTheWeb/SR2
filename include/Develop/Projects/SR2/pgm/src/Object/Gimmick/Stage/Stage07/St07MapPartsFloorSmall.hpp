#ifndef ST07MAPPARTSFLOORSMALL_HPP
#define ST07MAPPARTSFLOORSMALL_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsMapPartsFloorSmall_Object : public clsMapPartsObject {
public:
    clsMapPartsFloorSmall_Object();
    virtual ~clsMapPartsFloorSmall_Object();

    void createData();

    static f32 tof32ClipSqDist;
};

// total size: 0x98
class clsMapPartsFloorSmall_Task : public clsSingleModelGimmick_Task<clsMapPartsFloorSmall_Task,
                                                                     clsMapPartsFloorSmall_Object,
                                                                     clsModelType_OB_TX> {
public:
    clsMapPartsFloorSmall_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsFloorSmall_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    static NNS_VECTOR tosCollisionHalfSizeVec;
};

#endif // ST07MAPPARTSFLOORSMALL_HPP
