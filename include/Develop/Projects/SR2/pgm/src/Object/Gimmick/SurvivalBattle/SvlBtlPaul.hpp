#ifndef SVLBTLPAUL_HPP
#define SVLBTLPAUL_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/BaseSvlBtlObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsGravityGimmickParam;

class clsSvlBtlPaul_Object : public clsBaseSvlBtlObject {
public:
    clsSvlBtlPaul_Object();
    virtual ~clsSvlBtlPaul_Object();

    hkShape* getShape();
    f32 getMass();
    clsGravityGimmickParam* getGravityGimmickParam();

    static f32 t_of32Mass;
    static f32 t_of32CLIP_DISTx2;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0x98
class clsSvlBtlPaul_Task : public clsSingleModelGimmick_Task<clsSvlBtlPaul_Task,
                                                             clsSvlBtlPaul_Object,
                                                             clsModelType_OB_TX_MO_MA> {
public:
    clsSvlBtlPaul_Task(u32 u32NumI);
    virtual ~clsSvlBtlPaul_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // SVLBTLPAUL_HPP
