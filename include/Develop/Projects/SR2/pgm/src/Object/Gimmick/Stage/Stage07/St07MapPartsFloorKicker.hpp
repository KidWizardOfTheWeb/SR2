#ifndef ST07MAPPARTSFLOORKICKER_HPP
#define ST07MAPPARTSFLOORKICKER_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsMapPartsFloorKicker_Object : public clsMapPartsObject {
public:
    clsMapPartsFloorKicker_Object();
    virtual ~clsMapPartsFloorKicker_Object();

    void createData();

    static f32 tof32ClipSqDist;
};

// total size: 0x98
class clsMapPartsFloorKicker_Task : public clsSingleModelGimmick_Task<clsMapPartsFloorKicker_Task,
                                                                      clsMapPartsFloorKicker_Object,
                                                                      clsModelType_OB_TX> {
public:
    clsMapPartsFloorKicker_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsFloorKicker_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    static NNS_VECTOR tosCollisionHalfSizeVec;
};

#endif // ST07MAPPARTSFLOORKICKER_HPP
