#ifndef ST02BEE_HPP
#define ST02BEE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02BeeBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlayerTask;
class clsBeeRobo_Obj;

// total size: 0xB0
class clsBeeRobo_Obj : public clsGimmickObj, private clsBeeRoboBase_Obj {
public:
    // Note: enmBeeRoboMode has generic enumerators that collide with ItemBomb.hpp; nested for
    // disambiguation.
    enum enmBeeRoboMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
        MODE_WAIT = 2,
    };

    clsBeeRobo_Obj() {}
    virtual ~clsBeeRobo_Obj() {}

    virtual nspPackId::enm getPackId() const { return nspPackId::ST02_BEE_ROBO_12010; }

    void setNextPoint() {}
    u32 checkWaitFrame() { return 0; }
    void moveUpDown() {}
    void movePoint() {}
    void init() {}
    enmBeeRoboMode getMode() const { return m_enBeeRoboMode; }

    clsPlayerTask* m_pcPlayer;         // offset 0x5C, size 0x4
    NNS_VECTORFAST* m_opsPointVecFast; // offset 0x60, size 0x4
    NNS_VECTORFAST m_sDirVecFast;      // offset 0x70, size 0x10
    enmBeeRoboMode m_enBeeRoboMode;    // offset 0x80, size 0x4
    f32 m_f32WaitFrame;                // offset 0x84, size 0x4
    f32 m_f32Frame;                    // offset 0x88, size 0x4
    f32 m_f32MaxSpeed;                 // offset 0x8C, size 0x4
    f32 m_f32Speed;                    // offset 0x90, size 0x4
    f32 m_f32Accele;                   // offset 0x94, size 0x4
    f32 m_f32Rot;                      // offset 0x98, size 0x4
    f32 m_f32RotSpeed;                 // offset 0x9C, size 0x4
    s8 m_s8TableNo;                    // offset 0xA0, size 0x1
    s8 m_s8PointNum;                   // offset 0xA1, size 0x1
    s8 m_s8PointNo;                    // offset 0xA2, size 0x1
    s8 m_s8UserNum;                    // offset 0xA3, size 0x1
};

// total size: 0x94
class clsBeeRobo_Task
    : public clsSingleModelGimmick_Task<clsBeeRobo_Task, clsBeeRobo_Obj, clsModelType_OB_TX> {
public:
    clsBeeRobo_Task(u32 u32ObjectAreaNum);
    virtual ~clsBeeRobo_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();
};

#endif // ST02BEE_HPP
