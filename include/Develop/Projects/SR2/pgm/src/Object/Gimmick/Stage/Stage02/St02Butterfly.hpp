#ifndef ST02BUTTERFLY_HPP
#define ST02BUTTERFLY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

enum enmButterflyMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
    MODE_WAIT = 2,
};

// total size: 0x90
class clsButterfly_Obj : public clsGimmickObj {
public:
    clsButterfly_Obj() {}
    virtual ~clsButterfly_Obj() {}

    NNS_VECTORFAST* m_opsPointVecFast; // offset 0x50, size 0x4
    NNS_VECTORFAST m_sDirVecFast;      // offset 0x60, size 0x10
    enmButterflyMode m_eButterflyMode; // offset 0x70, size 0x4
    f32 m_f32WaitFrame;                // offset 0x74, size 0x4
    f32 m_f32Frame;                    // offset 0x78, size 0x4
    f32 m_f32Speed;                    // offset 0x7C, size 0x4
    s8 m_s8TableNo;                    // offset 0x80, size 0x1
    s8 m_s8PointNum;                   // offset 0x81, size 0x1
    s8 m_s8PointNo;                    // offset 0x82, size 0x1

    inline void setNextPoint() {}
    inline u32 checkWaitFrame() { return 0; }
    inline void moveUpDown() {}
    inline void movePoint() {}
    inline void init() {}
    inline enmButterflyMode getMode() const { return m_eButterflyMode; }
    virtual nspPackId::enm getPackId() const { return nspPackId::ST02_BUTTERFLY_12060; }
};

// total size: 0x98
class clsButterfly_Task : public clsSingleModelGimmick_Task<clsButterfly_Task,
                                                            clsButterfly_Obj,
                                                            clsModelType_OB_TX_MO> {
public:
    clsButterfly_Task(u32 u32ObjectAreaNum);
    virtual ~clsButterfly_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST02BUTTERFLY_HPP
