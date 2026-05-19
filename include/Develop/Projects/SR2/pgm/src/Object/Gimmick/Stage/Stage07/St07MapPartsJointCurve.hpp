#ifndef ST07MAPPARTSJOINTCURVE_HPP
#define ST07MAPPARTSJOINTCURVE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkTransformShape;

class clsMapPartsJointCurve_Object : public clsMapPartsObject {
public:
    clsMapPartsJointCurve_Object();
    virtual ~clsMapPartsJointCurve_Object();

    void createData();

    static f32 tof32ClipSqDist;
};

// total size: 0x9C
class clsMapPartsJointCurve_Task : public clsSingleModelGimmick_Task<clsMapPartsJointCurve_Task,
                                                                     clsMapPartsJointCurve_Object,
                                                                     clsModelType_OB_TX> {
public:
    clsMapPartsJointCurve_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsJointCurve_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    hkTransformShape* m_pcTransShape[2]; // offset 0x94, size 0x8
};

#endif // ST07MAPPARTSJOINTCURVE_HPP
