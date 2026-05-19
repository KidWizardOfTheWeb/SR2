#ifndef ST07MAPPARTSGUARDRAILSMALL_HPP
#define ST07MAPPARTSGUARDRAILSMALL_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsMapPartsGuardRailSmall_Object : public clsMapPartsObject {
public:
    clsMapPartsGuardRailSmall_Object();
    virtual ~clsMapPartsGuardRailSmall_Object();

    void createData();

    static f32 tof32ClipSqDist;
};

// total size: 0x98
class clsMapPartsGuardRailSmall_Task
    : public clsSingleModelGimmick_Task<clsMapPartsGuardRailSmall_Task,
                                        clsMapPartsGuardRailSmall_Object,
                                        clsModelType_OB_TX> {
public:
    clsMapPartsGuardRailSmall_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsGuardRailSmall_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST07MAPPARTSGUARDRAILSMALL_HPP
