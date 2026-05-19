#ifndef ST15SAFETRAMPOLINE_HPP
#define ST15SAFETRAMPOLINE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkContactPoint;

enum enmSafeTMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

class clsSafeTrampoline_Obj : public clsPhantomGimmickObject {
public:
    clsSafeTrampoline_Obj();
    virtual ~clsSafeTrampoline_Obj();

    virtual void createData();
    virtual void destroyData();
    virtual void contactTriggerEvent(hkContactPoint* pParam1, clsObject* pParam2);
    virtual nspPackId::enm getPackId() const { return nspPackId::ST15_SAFE_TRAMPOLINE_25100; }

    enmSafeTMode m_eSafeTMode; // offset 0x60, size 0x4
    u32 m_u32FlagList;         // offset 0x64, size 0x4
    f32 m_f32Speed;            // offset 0x68, size 0x4
    f32 m_f32Gravity;          // offset 0x6C, size 0x4
    f32 m_f32Jump;             // offset 0x70, size 0x4
};

// total size: 0x90
class clsSafeTrampoline_Task : public clsSingleModelGimmick_Task<clsSafeTrampoline_Task,
                                                                 clsSafeTrampoline_Obj,
                                                                 clsModelType_OB> {
public:
    clsSafeTrampoline_Task(u32 u32Param1)
        : clsSingleModelGimmick_Task<clsSafeTrampoline_Task,
                                     clsSafeTrampoline_Obj,
                                     clsModelType_OB>(u32Param1, 0x18A88)
    {
    }
    virtual ~clsSafeTrampoline_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI) {}
};

#endif // ST15SAFETRAMPOLINE_HPP
