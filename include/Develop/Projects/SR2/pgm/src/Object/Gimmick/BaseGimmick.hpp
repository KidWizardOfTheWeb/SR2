#ifndef BASEGIMMICK_HPP
#define BASEGIMMICK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class hkShape;
struct NNS_VECTORFAST;

// total size: 0x150
class clsSimpleShapePhantom : public hkSimpleShapePhantom {
public:
    virtual ~clsSimpleShapePhantom() {}

    void setPositionVecFast(const NNS_VECTORFAST* psPosVecFast) {}

    void* m_pvUserData01; // offset 0x140, size 0x4
};

// total size: 0x4
class clsCollision : public clsObject {};

// total size: 0x68
class clsBaseGimmickHead : public clsTask {
public:
    clsBaseGimmickHead(u32 packId, u32 objectMax) : clsTask(packId, 0) {}
    virtual ~clsBaseGimmickHead() {}

    virtual void execute() {}
    virtual void draw() {}

    void loadBinary(stcBinInfo&)
    {
        m_bIsLoadBinary = 1;
        reset();
    }
    u32 getObjectMax() const { return m_u32ObjectMax; }
    hkShape* getPhantomShape() const { return m_pcPhantomShape; }

    nspPackId::enm m_ePackId;  // offset 0x54, size 0x4
    u32 m_u32ObjectMax;        // offset 0x58, size 0x4
    hkShape* m_pcPhantomShape; // offset 0x5C, size 0x4
    hkShape* m_pcRigidShape;   // offset 0x60, size 0x4
    u8 m_bIsLoadBinary;        // offset 0x64, size 0x1
    // gap 0x65-0x67 (alignment padding)
};

// total size: 0x8
class clsMultiObTxModels {
public:
    clsMultiObTxModels() {}
    virtual ~clsMultiObTxModels() {}

    void createModels(stcBinInfo& rsBinInfoI, u32 u32CalcObjNum);

    u32 m_u32Num;                    // offset 0x0, size 0x4
    clsModelType_OB_TX* m_apcModels; // offset 0x4, size 0x4
};

// total size: 0x8
class clsMultiObjTxMoMaModels {
public:
    ~clsMultiObjTxMoMaModels() {}
    void createModels(stcBinInfo& rsBinInfoI, u32 u32CalcObjNum);

    u32 m_u32Num;                          // offset 0x0, size 0x4
    clsModelType_OB_TX_MO_MA* m_apcModels; // offset 0x4, size 0x4
};

// total size: 0x8
class clsMultiObjTxMaModels {
public:
    ~clsMultiObjTxMaModels() {}
    void createModels(stcBinInfo& rsBinInfoI, u32 u32CalcObjNum);

    u32 m_u32Num;                          // offset 0x0, size 0x4
    clsModelType_OB_TX_MO_MA* m_apcModels; // offset 0x4, size 0x4
};

// total size: 0x8
class clsMultiObjTxMoModels {
public:
    ~clsMultiObjTxMoModels() {}
    void createModels(stcBinInfo& rsBinInfoI, u32 u32CalcObjNum);

    u32 m_u32Num;                       // offset 0x0, size 0x4
    clsModelType_OB_TX_MO* m_apcModels; // offset 0x4, size 0x4
};

// total size: 0x8
class clsMultiModels {
public:
    ~clsMultiModels() {}
    void createModels(stcBinInfo& rsBinInfoI, u32 u32CalcObjNum);

    u32 m_u32Num;                          // offset 0x0, size 0x4
    clsModelType_OB_TX_MO_MA* m_apcModels; // offset 0x4, size 0x4
};

// total size: 0x4
class clsMultiModelGimmickHead_Task {
public:
    clsMultiModelGimmickHead_Task() : m_u32NowDrawModelNum(0) {}
    ~clsMultiModelGimmickHead_Task() {}
    void setNowDrawModelNum(u32 u32NowDrawModelNum) { m_u32NowDrawModelNum = u32NowDrawModelNum; }
    u32 getNowDrawModelNum() const { return m_u32NowDrawModelNum; }

    u32 m_u32NowDrawModelNum; // offset 0x0, size 0x4
};

#endif // BASEGIMMICK_HPP
