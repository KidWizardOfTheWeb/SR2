#ifndef GIMMICKBODY_HPP
#define GIMMICKBODY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil_PS2.hpp"

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
    clsBaseGimmickBody(u32 u32ObjectAreaNum, u32 u32TpI)
        : clsBaseGimmickHead(u32ObjectAreaNum, u32TpI, 5), m_pcObjArray(NULL),
          pcGmkBurnLight_Task(NULL)
    {
        u32 u32CalcObjNum = getObjectMax();
        if (u32CalcObjNum != 0) {
            m_pcObjArray = new T_OBJ[u32CalcObjNum];
            T_OBJ* pcObjArray = m_pcObjArray;
            m_vecGmkObjArray.reserve(u32CalcObjNum);
            m_vecUnusedGmkObjArray.reserve(u32CalcObjNum);
            u32 u32i = 0;
            do {
                T_OBJ* pcPushObj = pcObjArray;
                m_vecUnusedGmkObjArray.push_back(pcPushObj);
                ++u32i;
                ++pcObjArray;
            } while (u32i < u32CalcObjNum);
        }
    }
    virtual ~clsBaseGimmickBody() { delete[] m_pcObjArray; }
    T_MODEL& getModelRef();
    virtual void setSetData(const stcSetDataDetail& orsSetDataDetailI)
    {
        T_OBJ* pcObj = m_vecUnusedGmkObjArray.back();
        m_vecUnusedGmkObjArray.pop_back();
        m_vecGmkObjArray.push_back(pcObj);
        pcObj->setSetData(orsSetDataDetailI);
    }
    virtual u32 getMultiDrawNum()
    {
        u32 u32CalcObjNum = m_vecGmkObjArray.size();
        u32 u32Num = u32CalcObjNum;
        if (u32CalcObjNum != 0) {
            u32 u32i = 0;
            u32Num = 0;
            do {
                u32Num += m_vecGmkObjArray.at(u32i)->getMultiDrawNum();
                ++u32i;
            } while (u32i < u32CalcObjNum);
        }
        return u32Num;
    }
    T_OBJ* getObject(u32 u32NoI) { return m_vecGmkObjArray.at(u32NoI); }
    clsGmkBurnLight_Task<T_MODEL>* getBurnLightTask() const { return pcGmkBurnLight_Task; }

    T_OBJ* m_pcObjArray;                                                 // offset 0x6C, size 0x4
    std::vector<T_OBJ*, std::allocator<T_OBJ*> > m_vecGmkObjArray;       // offset 0x70, size 0xC
    std::vector<T_OBJ*, std::allocator<T_OBJ*> > m_vecUnusedGmkObjArray; // offset 0x7C, size 0xC
    T_MODEL m_cModel;                                   // offset 0x88, size varies by T_MODEL
    clsGmkBurnLight_Task<T_MODEL>* pcGmkBurnLight_Task; // after m_cModel
};

template <class T_TASK, class T_OBJ, class T_MODEL>
T_MODEL& clsBaseGimmickBody<T_TASK, T_OBJ, T_MODEL>::getModelRef()
{
    return m_cModel;
}

// Single-model specialisation - adds virtual createModel().
template <class T_TASK, class T_OBJ, class T_MODEL>
class clsSingleModelGimmick_Task : public clsBaseGimmickBody<T_TASK, T_OBJ, T_MODEL> {
public:
    clsSingleModelGimmick_Task(u32 u32ObjectAreaNum, u32 u32TpI)
        : clsBaseGimmickBody<T_TASK, T_OBJ, T_MODEL>(u32ObjectAreaNum, u32TpI)
    {
        this->getModelRef().m_psObject = NULL;
    }
    virtual ~clsSingleModelGimmick_Task() {}
    virtual void createModel(stcBinInfo& rsBinInfoI)
    {
        if (this->m_u32ObjectMax != 0) {
            this->m_ePackId = rsBinInfoI.ePackId;
            nspNnUtil::BinSetUp_Model(
                reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(this->m_cModel), rsBinInfoI.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer(this->getModelRef());
            u32 u32CalcObjNum = this->getMultiDrawNum();
            if (nspNnUtil::ts32MtxListNum < u32CalcObjNum * this->m_cModel.m_psObject->nNode) {
                nspNnUtil::ts32MtxListNum = u32CalcObjNum * this->m_cModel.m_psObject->nNode;
            }
            if (nspNnUtil::ts32NodeStatusNum < u32CalcObjNum * this->m_cModel.m_psObject->nNode) {
                nspNnUtil::ts32NodeStatusNum = u32CalcObjNum * this->m_cModel.m_psObject->nNode;
            }
            if (nspNnUtil::ts32MtxPtrListNum < u32CalcObjNum) {
                nspNnUtil::ts32MtxPtrListNum = u32CalcObjNum;
            }
            if (nspNnUtil::ts32NodeStatusPtrListNum < u32CalcObjNum) {
                nspNnUtil::ts32NodeStatusPtrListNum = u32CalcObjNum;
            }
        }
    }
};

// total size: 0x88
template <class T_TASK, class T_OBJ>
class clsBaseGimmickThrough : public clsBaseGimmickHead, public clsSingleton<T_TASK> {
public:
    clsBaseGimmickThrough(u32 u32ObjectAreaNum, u32 u32TpI)
        : clsBaseGimmickHead(u32ObjectAreaNum, u32TpI, 5)
    {
    }
    virtual ~clsBaseGimmickThrough() {}
    virtual void createModel(stcBinInfo&) {}
    virtual void setSetData(const stcSetDataDetail&) {}

    T_OBJ* m_pcObjArray;           // offset 0x6C, size 0x4
    vector m_vecGmkObjArray;       // offset 0x70, size 0xC
    vector m_vecUnusedGmkObjArray; // offset 0x7C, size 0xC
};

// Multi-model gimmick task template - adds execute(), draw(), reset(), createModel().
// The four-byte draw-counter base follows clsBaseGimmickBody.
// With clsMultiObTxModels, the bases occupy 0x94 + 0x4 bytes.
template <class T_TASK, class T_OBJ, class T_MODEL>
class clsMultiModelGimmick_Task : public clsBaseGimmickBody<T_TASK, T_OBJ, T_MODEL>,
                                  public clsMultiModelGimmickHead_Task {
public:
    clsMultiModelGimmick_Task(u32 u32ObjectAreaNum, u32 u32TpI)
        : clsBaseGimmickBody<T_TASK, T_OBJ, T_MODEL>(u32ObjectAreaNum, u32TpI)
    {
    }
    virtual ~clsMultiModelGimmick_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI)
    {
        if (this->m_u32ObjectMax != 0) {
            this->m_ePackId = rsBinInfoI.ePackId;
            this->m_cModel.createModels(rsBinInfoI, this->getMultiDrawNum());
        }
    }
    u32 getModelNum() { return this->m_cModel.m_u32Num; }
};

#endif // GIMMICKBODY_HPP
