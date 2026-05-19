#ifndef ST05ROTFALLTASK_HPP
#define ST05ROTFALLTASK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotFall/St05RotFallManager.hpp"

// total size: 0xF0
class clsRotFall_Task : public clsMultiModelGimmick_Task<clsRotFall_Task,
                                                         clsRotFallManager_Object,
                                                         clsMultiObTxModels> {
public:
    clsRotFall_Task(u32 u32ObjectAreaNum);
    virtual ~clsRotFall_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    f32 m_sBaseMtx[4][4];   // offset 0xA0, size 0x40
    hkShape* m_apcShape[3]; // offset 0xE0, size 0xC
};

#endif // ST05ROTFALLTASK_HPP
