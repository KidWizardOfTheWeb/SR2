#ifndef GLINKTRAINMANAGER_HPP
#define GLINKTRAINMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GLinkTrain/GLinkTrainThroughCollision.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsGLinkTrainManager_Object;
class clsGLinkTrain_Object;
class clsPlayerTask;
struct NNS_OBJECT;

// total size: 0xB0
class clsGLinkTrainManager_Object : public clsGimmickObj {
public:
    inline clsGLinkTrainManager_Object() : clsGimmickObj() {}
    virtual ~clsGLinkTrainManager_Object() {}

    clsGLinkTrainThroughCollision m_cThroughCollision; // offset 0x50, size 0xC
    clsGLinkTrainStartThroughCol m_cThroughStartCol;   // offset 0x60, size 0x30
    clsGLinkTrain_Object* m_pcTrains;                  // offset 0x90, size 0x4
    stcSetDataDetail* m_psSetData;                     // offset 0x94, size 0x4
    enmMode m_eMode;                                   // offset 0x98, size 0x4
    s32 m_s32TrainNum;                                 // offset 0x9C, size 0x4
    s32 m_s32PathNo;                                   // offset 0xA0, size 0x4
    f32 m_f32Speed;                                    // offset 0xA4, size 0x4
    f32 m_f32StartWait;                                // offset 0xA8, size 0x4

    static u32 t_oau32MissionFlg[2];

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const;
    virtual u32 getMultiDrawNum() const;
    virtual void drawCollision();
    virtual void draw(NNS_OBJECT* psObject,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);
    virtual void execute();
    virtual void reset();
    virtual void startGravityAction(clsPlayerTask* pcPlayer);
    virtual void start();
};

#endif // GLINKTRAINMANAGER_HPP
