#ifndef ST15METEORITEFALLEFFECT_HPP
#define ST15METEORITEFALLEFFECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x64
class clsSt15MeteoriteFallEffect_Task : public clsTask {
public:
    clsSt15MeteoriteFallEffect_Task(const f32 (*opsMatrix)[4][4]);
    virtual ~clsSt15MeteoriteFallEffect_Task() {}
    virtual void execute();
    virtual void draw();
    void setDraw(bool bParam1) { m_bDraw = bParam1; }

    f32 (*m_opsDrawMatrix)[4][4];        // offset 0x54, size 0x4
    clsModelType_OB_TX_MO_MA* m_pcModel; // offset 0x58, size 0x4
    f32 m_f32Frame;                      // offset 0x5C, size 0x4
    u8 m_bDraw;                          // offset 0x60, size 0x1
};

#endif // ST15METEORITEFALLEFFECT_HPP
