#ifndef ST02SIDA_HPP
#define ST02SIDA_HPP

#include "Develop/Projects/SR2/pgm/src/Data/PlayerData.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Sound/PlaySe_2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class hkContactPoint;
class clsObject;

// total size: 0x90
class clsSida_Obj : public clsPhantomGimmickObject {
public:
    enum enmSidaMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsSida_Obj() {}
    virtual ~clsSida_Obj() {}

    virtual void contactAlwaysEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST02_SIDA_12040; }

    void init() {}
    void setMode(enmSidaMode eParam1) { m_eSidaMode = eParam1; }
    enmSidaMode getMode() const { return m_eSidaMode; }
    void drawDebugLeafCol() {}
    void rotation() {}
    void executeCatch() {}

    static NNS_VECTORFAST m_tosLeafPosFast;

    enmSidaMode m_eSidaMode;     // offset 0x60, size 0x4
    s32 m_A32RotateY;            // offset 0x64, size 0x4
    s32 m_A32RotateSpeed;        // offset 0x68, size 0x4
    _stcPlayerData* m_psExecute; // offset 0x6C, size 0x4
    u32 m_u32ExecuteNum;         // offset 0x70, size 0x4
    u32 m_u32ObjectNum;          // offset 0x74, size 0x4
    u32 m_u32LeafUseFlg;         // offset 0x78, size 0x4
    u32 m_u32CatchFlg;           // offset 0x7C, size 0x4
    clsPlaySe_2D* m_cPlaySe2d;   // offset 0x80, size 0x4
};

// total size: 0x98
class clsSida_Task
    : public clsSingleModelGimmick_Task<clsSida_Task, clsSida_Obj, clsModelType_OB_TX> {
public:
    clsSida_Task(u32 u32ObjectAreaNum);
    virtual ~clsSida_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST02SIDA_HPP
