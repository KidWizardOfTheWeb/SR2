#ifndef PS2_SHADOWVOLUME_HPP
#define PS2_SHADOWVOLUME_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOLibChecker.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil_PS2.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsPlayerTask;

class clsShadowVolume_Task : public clsTask {
public:
    clsShadowVolume_Task(stcBinInfo& rsBinInfoI) : clsTask(100099, 1)
    {
        nspOOLibChecker::ClassC("clsShadowVolume_Task");
        nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(m_cModel),
                                  rsBinInfoI.opu8Bin);
        nspNnUtil::CalcUnionNnMtxBuffer(m_cModel);
    }
    virtual ~clsShadowVolume_Task() {}

    virtual void draw();
    void drawShadow(u32 p0, clsPlayerTask* p1);

    clsModelType_OB m_cModel; // offset 0x54, size 0x4

    static u8 m_oau8BoardNodeNo[];
};

#endif // PS2_SHADOWVOLUME_HPP
