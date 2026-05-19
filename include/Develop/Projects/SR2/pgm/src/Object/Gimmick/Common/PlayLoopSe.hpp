#ifndef PLAYLOOPSE_HPP
#define PLAYLOOPSE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkShape;

enum enmPlayLoopSeMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

// total size: 0x80
class clsPlayLoopSe_Obj : public clsPhantomGimmickObject {
public:
    ~clsPlayLoopSe_Obj();

    clsPlayLoopSe_Obj();

    nspPackId::enm getPackId() const;

    void createData();

    void destroyData();

    void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);

    void contactRemoveEvent(hkContactPoint* pcObject, clsObject* pParam2);

    hkShape* m_pcShape;            // offset 0x60, size 0x4
    enmPlayLoopSeMode m_ePlayMode; // offset 0x64, size 0x4
    s32 m_s32SeId;                 // offset 0x68, size 0x4
    u32 m_u32PlayerFlg;            // offset 0x6C, size 0x4
    u32 m_u32RequestId;            // offset 0x70, size 0x4
    f32 m_f32Frame;                // offset 0x74, size 0x4
    u8 m_bRequestPlay;             // offset 0x78, size 0x1

    static u32 m_oau32RequestArray[8];
};

// total size: 0x94
class clsPlayLoopSe_Task
    : public clsSingleModelGimmick_Task<clsPlayLoopSe_Task, clsPlayLoopSe_Obj, clsModelType_OB_TX> {
public:
    clsPlayLoopSe_Task(u32 u32ObjectAreaNum);
    virtual ~clsPlayLoopSe_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI) {}
};

#endif // PLAYLOOPSE_HPP
