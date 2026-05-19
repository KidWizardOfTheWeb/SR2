#ifndef ST07MAPPARTSJOINTSHARP_HPP
#define ST07MAPPARTSJOINTSHARP_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkTransformShape;

class clsMapPartsJointSharp_Object : public clsMapPartsObject {
public:
    clsMapPartsJointSharp_Object();
    virtual ~clsMapPartsJointSharp_Object();

    void createData();

    static f32 tof32ClipSqDist;
};

// total size: 0xA4
class clsMapPartsJointSharp_Task : public clsSingleModelGimmick_Task<clsMapPartsJointSharp_Task,
                                                                     clsMapPartsJointSharp_Object,
                                                                     clsModelType_OB_TX> {
public:
    clsMapPartsJointSharp_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsJointSharp_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkTransformShape* m_pcTransShape[4]; // offset 0x94, size 0x10
};

#endif // ST07MAPPARTSJOINTSHARP_HPP
