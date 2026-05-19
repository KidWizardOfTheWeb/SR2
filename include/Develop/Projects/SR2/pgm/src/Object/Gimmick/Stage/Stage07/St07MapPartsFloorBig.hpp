#ifndef ST07MAPPARTSFLOORBIG_HPP
#define ST07MAPPARTSFLOORBIG_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsMapPartsFloorBig_Object : public clsMapPartsObject {
public:
    clsMapPartsFloorBig_Object();
    virtual ~clsMapPartsFloorBig_Object();

    nspPackId::enm getPackId() const;

    void createData();

    static f32 tof32ClipSqDist;
};

// total size: 0x98
class clsMapPartsFloorBig_Task : public clsSingleModelGimmick_Task<clsMapPartsFloorBig_Task,
                                                                   clsMapPartsFloorBig_Object,
                                                                   clsModelType_OB_TX> {
public:
    clsMapPartsFloorBig_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsFloorBig_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    static NNS_VECTOR tosCollisionHalfSizeVec;
};

#endif // ST07MAPPARTSFLOORBIG_HPP
