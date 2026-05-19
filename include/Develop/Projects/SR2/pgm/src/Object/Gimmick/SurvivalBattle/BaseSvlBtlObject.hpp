#ifndef BASESVLBTLOBJECT_HPP
#define BASESVLBTLOBJECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj.hpp"

// total size: 0xE0
class clsBaseSvlBtlObject : public clsPutGravityObj_Obj {
public:
    virtual ~clsBaseSvlBtlObject();
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pObj);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void init();
    virtual void mainGravity();
    virtual void mainCrash();
};

#endif // BASESVLBTLOBJECT_HPP
