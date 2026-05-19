#ifndef PS2_SHADOWVOLUME_HPP
#define PS2_SHADOWVOLUME_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsPlayerTask;

class clsShadowVolume_Task : public clsTask {
public:
    virtual ~clsShadowVolume_Task() {}

    virtual void draw();
    void drawShadow(u32 p0, clsPlayerTask* p1);

    clsModelType_OB m_cModel; // offset 0x54, size 0x4

    static u8 m_oau8BoardNodeNo[];
};

#endif // PS2_SHADOWVOLUME_HPP
