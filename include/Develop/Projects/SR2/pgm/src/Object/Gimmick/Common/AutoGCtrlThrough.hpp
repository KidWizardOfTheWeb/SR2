#ifndef AUTOGCTRLTHROUGH_HPP
#define AUTOGCTRLTHROUGH_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"

// total size: 0x60
class clsAutoGCtrlThrough_Object : public clsBaseThroughCollision, public clsGimmickObj {
public:
    clsAutoGCtrlThrough_Object() {}
    virtual ~clsAutoGCtrlThrough_Object() {}

    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void createData();
    virtual void destroyData();
    virtual void updateSetEditorCollision();
};

// total size: 0x8C
class clsAutoGCtrlThrough_Task
    : public clsBaseGimmickThrough<clsAutoGCtrlThrough_Task, clsAutoGCtrlThrough_Object>,
      public clsGimmickCommon {
public:
    clsAutoGCtrlThrough_Task(u32 u32ObjectAreaNum);
    virtual ~clsAutoGCtrlThrough_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset() {}
};

#endif // AUTOGCTRLTHROUGH_HPP
