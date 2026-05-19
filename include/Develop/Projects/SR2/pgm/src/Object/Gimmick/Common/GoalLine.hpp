#ifndef GOALLINE_HPP
#define GOALLINE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

// total size: 0x50
class clsGoalLine_Obj : public clsGimmickObj {
public:
    clsGoalLine_Obj();
    virtual ~clsGoalLine_Obj();

    nspPackId::enm getPackId() const { return nspPackId::GOAL_LINE_2060; }
};

class clsGoalLine_Task
    : public clsSingleModelGimmick_Task<clsGoalLine_Task, clsGoalLine_Obj, clsModelType_OB_TX> {
public:
    clsGoalLine_Task() : clsSingleModelGimmick_Task(0, 0) {}
    virtual ~clsGoalLine_Task() {}

    virtual void execute();
    virtual void draw();
};

#endif // GOALLINE_HPP
