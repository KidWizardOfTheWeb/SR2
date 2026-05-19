#ifndef ST07MAPPARTSJOINTSMALL_HPP
#define ST07MAPPARTSJOINTSMALL_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsMapPartsJointSmall_Object : public clsMapPartsObject {
public:
    clsMapPartsJointSmall_Object();
    virtual ~clsMapPartsJointSmall_Object();

    void createData();

    static f32 tof32ClipSqDist;
};

// total size: 0x94
class clsMapPartsJointSmall_Task : public clsSingleModelGimmick_Task<clsMapPartsJointSmall_Task,
                                                                     clsMapPartsJointSmall_Object,
                                                                     clsModelType_OB_TX> {
public:
    clsMapPartsJointSmall_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsJointSmall_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST07MAPPARTSJOINTSMALL_HPP
