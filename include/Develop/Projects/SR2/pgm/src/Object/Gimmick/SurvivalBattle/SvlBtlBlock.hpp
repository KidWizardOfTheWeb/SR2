#ifndef SVLBTLBLOCK_HPP
#define SVLBTLBLOCK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/BaseSvlBtlObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSvlBtlBlock_Object : public clsBaseSvlBtlObject {
public:
    clsSvlBtlBlock_Object() {}
    virtual ~clsSvlBtlBlock_Object() {}

    hkShape* getShape();
    f32 getMass();
    clsGravityGimmickParam* getGravityGimmickParam();
    void requestDrawBreakEffect();

    static f32 t_of32Mass;
    static f32 t_of32CLIP_DISTx2;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0x98
class clsSvlBtlBlock_Task : public clsSingleModelGimmick_Task<clsSvlBtlBlock_Task,
                                                              clsSvlBtlBlock_Object,
                                                              clsModelType_OB_TX> {
public:
    clsSvlBtlBlock_Task(u32 u32NumI);
    virtual ~clsSvlBtlBlock_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // SVLBTLBLOCK_HPP
