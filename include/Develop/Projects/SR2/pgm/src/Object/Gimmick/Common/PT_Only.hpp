#ifndef PT_ONLY_HPP
#define PT_ONLY_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03Macross.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "types.h"

class clsPlayerTask;

// total size: 0xE0
class clsPT_Only_Obj : public clsRigidBodyGimmickObj {
public:
    clsPT_Only_Obj() : m_eMode(MODE_INIT), m_pcShape(NULL), m_pcSe3DControl(NULL) {}
    virtual ~clsPT_Only_Obj() { destroyData(); }
    virtual void reset();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void requestDrawBreakEffect();
    virtual void requestPowerTypeSe(clsPlayerTask* pcPlayer);
    virtual void main();
    virtual nspPackId::enm getPackId() const;
    // RECONSTRUCTED: enum scope.
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enmMode m_eMode;                 // offset 0xD0, size 0x4
    hkShape* m_pcShape;              // offset 0xD4, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xD8, size 0x4

    static f32 m_tof32ClipDistx2;
};

// total size: 0x9C
class clsPT_Only_Task
    : public clsMultiModelGimmick_Task<clsPT_Only_Task, clsPT_Only_Obj, clsMultiObTxModels> {
public:
    clsPT_Only_Task(u32 u32ObjectAreaNum)
        : clsMultiModelGimmick_Task<clsPT_Only_Task, clsPT_Only_Obj, clsMultiObTxModels>(
              u32ObjectAreaNum, 101000)
    {
    }
    virtual ~clsPT_Only_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PT_ONLY_HPP
