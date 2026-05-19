#ifndef ST05ROTFALLGLINKTASK_HPP
#define ST05ROTFALLGLINKTASK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotFallGLink/St05RotFallGLinkManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

// total size: 0x94
class clsRotFallGLink_Task : public clsSingleModelGimmick_Task<clsRotFallGLink_Task,
                                                               clsRotFallGLinkManager_Object,
                                                               clsModelType_OB_TX> {
public:
    clsRotFallGLink_Task(u32 u32ObjectAreaNum);
    virtual ~clsRotFallGLink_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST05ROTFALLGLINKTASK_HPP
