#ifndef ST15FLOATINGMETEORITETIRGGER_HPP
#define ST15FLOATINGMETEORITETIRGGER_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkContactPoint;
class clsObject;

// total size: 0x60
class clsFloatingMeteoTrig_Obj : public clsPhantomGimmickObject {
public:
    clsFloatingMeteoTrig_Obj() {}
    virtual ~clsFloatingMeteoTrig_Obj() {}
    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST15_FLOATING_METEO_TRIG_25090; }
};

// total size: 0x90
class clsFloatingMeteoTrig_Task : public clsSingleModelGimmick_Task<clsFloatingMeteoTrig_Task,
                                                                    clsFloatingMeteoTrig_Obj,
                                                                    clsModelType_OB> {
public:
    clsFloatingMeteoTrig_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task(0, u32ObjectAreaNum)
    {
    }
    virtual ~clsFloatingMeteoTrig_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void createModel(stcBinInfo& rsBinInfoI) {}
};

#endif // ST15FLOATINGMETEORITETIRGGER_HPP
