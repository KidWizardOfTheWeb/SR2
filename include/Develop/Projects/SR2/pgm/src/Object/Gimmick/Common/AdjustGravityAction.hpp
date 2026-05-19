#ifndef ADJUSTGRAVITYACTION_HPP
#define ADJUSTGRAVITYACTION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"

// total size: 0x60
class clsAdjustGravityAction_Object : public clsBaseThroughCollision, public clsGimmickObj {
public:
    clsAdjustGravityAction_Object() {}
    virtual ~clsAdjustGravityAction_Object() {}

    virtual void contactTriggerEvent(hkContactPoint* pcPoint, clsObject* pcObj) {}
    virtual void contactAlwaysEvent(hkContactPoint* pcPoint, clsObject* pcObj) {}
    virtual void contactRemoveEvent(hkContactPoint* pcPoint, clsObject* pcObj) {}
    virtual void contactTriggerEvent(clsPlayerTask* pcPlayer);
    virtual void contactRemoveEvent(clsPlayerTask* pcPlayer);
    virtual void createData();
    virtual void destroyData();
    virtual void updateSetEditorCollision();
};

// total size: 0x8C
class clsAdjustGravityAction_Task
    : public clsBaseGimmickThrough<clsAdjustGravityAction_Task, clsAdjustGravityAction_Object>,
      public clsGimmickCommon {
public:
    clsAdjustGravityAction_Task(u32 u32ObjectAreaNum);
    virtual ~clsAdjustGravityAction_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset() {}
};

#endif // ADJUSTGRAVITYACTION_HPP
