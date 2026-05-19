#ifndef SVLBTLBARRIER_HPP
#define SVLBTLBARRIER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPlayerTask;

// total size: 0x70
class clsSvlBtlBarrier_Object : public clsGimmickObj {
public:
    clsSvlBtlBarrier_Object();
    virtual ~clsSvlBtlBarrier_Object();

    static f32 t_of32LimitFrame;
    static f32 t_of32CLIP_DISTx2;

    enum enmBarrierMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    clsPlayerTask* m_pcPlayer; // offset 0x50, size 0x4
    enmBarrierMode m_eMode;    // offset 0x54, size 0x4
    f32 m_f32LimitFrame;       // offset 0x58, size 0x4
    f32 m_f32MatFrame;         // offset 0x5C, size 0x4
    f32 m_f32MotFrame;         // offset 0x60, size 0x4
};

// total size: 0xAC
class clsSvlBtlBarrier_Task : public clsSingleModelGimmick_Task<clsSvlBtlBarrier_Task,
                                                                clsSvlBtlBarrier_Object,
                                                                clsModelType_OB_TX_MO_MA> {
public:
    clsSvlBtlBarrier_Task(const stcSetDataDetail& orsSetDataDetailI);
    virtual ~clsSvlBtlBarrier_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    void setup(clsPlayerTask* pcPlayer);
    void cancel(clsPlayerTask* pcPlayer);
};

#endif // SVLBTLBARRIER_HPP
