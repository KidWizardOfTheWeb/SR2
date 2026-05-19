#ifndef SVLBTLMAPPARTSFLOORGRAVITY_HPP
#define SVLBTLMAPPARTSFLOORGRAVITY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorGravity.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

// total size: 0x170
class clsSvlBtlMapPartsFloorGravity_Object : public clsMapPartsFloorGravity_Object {
public:
    clsSvlBtlMapPartsFloorGravity_Object() {}
    virtual ~clsSvlBtlMapPartsFloorGravity_Object() {}
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void setData();
    virtual void createData();

    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0x98
class clsSvlBtlMapPartsFloorGravity_Task
    : public clsSingleModelGimmick_Task<clsSvlBtlMapPartsFloorGravity_Task,
                                        clsSvlBtlMapPartsFloorGravity_Object,
                                        clsModelType_OB_TX> {
public:
    clsSvlBtlMapPartsFloorGravity_Task(u32 u32ObjectAreaNum);
    virtual ~clsSvlBtlMapPartsFloorGravity_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // SVLBTLMAPPARTSFLOORGRAVITY_HPP
