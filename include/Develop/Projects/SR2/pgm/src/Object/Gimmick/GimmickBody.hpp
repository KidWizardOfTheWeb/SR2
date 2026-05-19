#ifndef GIMMICKBODY_HPP
#define GIMMICKBODY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"

class clsAdjustGravityAction_Object;
template <class T_MODEL>
class clsGmkBurnLight_Task;

// Template base for all single-model gimmick tasks.
// T_TASK = the concrete task class (CRTP-like), T_OBJ = gimmick object, T_MODEL = model type.
// inherits: clsBaseGimmickHead (0x68) + clsSingleton<T_TASK> (vtptr at 0x68)
// own fields start at 0x6C
template <class T_TASK, class T_OBJ, class T_MODEL>
class clsBaseGimmickBody : public clsBaseGimmickHead, public clsSingleton<T_TASK> {
public:
    clsBaseGimmickBody(u32 packId, u32 objectMax) : clsBaseGimmickHead(packId, objectMax) {}
    virtual ~clsBaseGimmickBody() {}
    virtual T_OBJ* getModelRef();
    virtual void setSetData(const stcSetDataDetail&);
    virtual u32 getMultiDrawNum();
    T_OBJ* getObject(u32 u32NoI) { return static_cast<T_OBJ**>(m_vecGmkObjArray._data)[u32NoI]; }
    clsGmkBurnLight_Task<T_MODEL>* getBurnLightTask() const { return pcGmkBurnLight_Task; }

    T_OBJ* m_pcObjArray;                                // offset 0x6C, size 0x4
    vector m_vecGmkObjArray;                            // offset 0x70, size 0xC
    vector m_vecUnusedGmkObjArray;                      // offset 0x7C, size 0xC
    T_MODEL m_cModel;                                   // offset 0x88, size varies by T_MODEL
    clsGmkBurnLight_Task<T_MODEL>* pcGmkBurnLight_Task; // after m_cModel
};

// Single-model specialisation - adds virtual createModel().
template <class T_TASK, class T_OBJ, class T_MODEL>
class clsSingleModelGimmick_Task : public clsBaseGimmickBody<T_TASK, T_OBJ, T_MODEL> {
public:
    clsSingleModelGimmick_Task(u32 packId, u32 objectMax)
        : clsBaseGimmickBody<T_TASK, T_OBJ, T_MODEL>(packId, objectMax)
    {
    }
    virtual ~clsSingleModelGimmick_Task() {}
    virtual void createModel(stcBinInfo&);
};

// total size: 0x88
template <class T_TASK, class T_OBJ>
class clsBaseGimmickThrough : public clsBaseGimmickHead, public clsSingleton<T_TASK> {
public:
    clsBaseGimmickThrough(u32 packId, u32 objectMax) : clsBaseGimmickHead(packId, objectMax) {}
    virtual ~clsBaseGimmickThrough() {}
    virtual void createModel(stcBinInfo&) {}
    virtual void setSetData(const stcSetDataDetail&) {}

    T_OBJ* m_pcObjArray;           // offset 0x6C, size 0x4
    vector m_vecGmkObjArray;       // offset 0x70, size 0xC
    vector m_vecUnusedGmkObjArray; // offset 0x7C, size 0xC
};

// Multi-model gimmick task template - adds execute(), draw(), reset(), createModel().
// inherits: clsBaseGimmickBody (0x98) + clsMultiModelGimmickHead_Task (0x4 at 0x98)
// total size: 0x9C
template <class T_TASK, class T_OBJ, class T_MODEL>
class clsMultiModelGimmick_Task : public clsBaseGimmickBody<T_TASK, T_OBJ, T_MODEL> {
public:
    clsMultiModelGimmick_Task(u32 packId, u32 objectMax)
        : clsBaseGimmickBody<T_TASK, T_OBJ, T_MODEL>(packId, objectMax)
    {
    }
    virtual ~clsMultiModelGimmick_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo&);
    u32 getModelNum() { return this->m_cModel.m_u32Num; }
};

#endif // GIMMICKBODY_HPP
