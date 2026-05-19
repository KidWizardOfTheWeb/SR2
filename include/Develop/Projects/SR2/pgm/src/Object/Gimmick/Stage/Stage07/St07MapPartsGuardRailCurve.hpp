#ifndef ST07MAPPARTSGUARDRAILCURVE_HPP
#define ST07MAPPARTSGUARDRAILCURVE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkTransformShape;

class clsMapPartsGuardRailCurve_Object : public clsMapPartsObject {
public:
    clsMapPartsGuardRailCurve_Object();
    virtual ~clsMapPartsGuardRailCurve_Object();

    void createData();

    static f32 tof32ClipSqDist;
};

// total size: 0x9C
class clsMapPartsGuardRailCurve_Task
    : public clsSingleModelGimmick_Task<clsMapPartsGuardRailCurve_Task,
                                        clsMapPartsGuardRailCurve_Object,
                                        clsModelType_OB_TX> {
public:
    clsMapPartsGuardRailCurve_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsGuardRailCurve_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    hkTransformShape* m_pcTransShape[2]; // offset 0x94, size 0x8
};

#endif // ST07MAPPARTSGUARDRAILCURVE_HPP
