#ifndef ST07MAPPARTSJOINTBIG_HPP
#define ST07MAPPARTSJOINTBIG_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsMapPartsJointBig_Object : public clsMapPartsObject {
public:
    clsMapPartsJointBig_Object();
    virtual ~clsMapPartsJointBig_Object();

    void createData();

    static f32 tof32ClipSqDist;
};

// total size: 0x94
class clsMapPartsJointBig_Task : public clsSingleModelGimmick_Task<clsMapPartsJointBig_Task,
                                                                   clsMapPartsJointBig_Object,
                                                                   clsModelType_OB_TX> {
public:
    clsMapPartsJointBig_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsJointBig_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST07MAPPARTSJOINTBIG_HPP
