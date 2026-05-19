#ifndef PLAYAROUNDSE_HPP
#define PLAYAROUNDSE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/System/RequestArray.hpp"
#include "types.h"

class hkShape;
struct stcRequestArray;

enum enmPlayAroundSeMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
};

enum enmPlayAroundSeState {
    STATE_STOP = 0,
    STATE_PLAY = 1,
};

// total size: 0x80
class clsPlayAroundSe_Obj : public clsPhantomGimmickObject {
public:
    clsPlayAroundSe_Obj();
    virtual ~clsPlayAroundSe_Obj();
    virtual void createData();
    virtual void destroyData();
    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void contactRemoveEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void execute();
    virtual nspPackId::enm getPackId() const;

    // Members
    hkShape* m_pcShape;                // offset 0x60, size 0x4
    enmPlayAroundSeMode m_ePlayMode;   // offset 0x64, size 0x4
    enmPlayAroundSeState m_ePlayState; // offset 0x68, size 0x4
    clsSe3DControl* m_pcSe3DControl;   // offset 0x6C, size 0x4
    u32 m_u32SeNo;                     // offset 0x70, size 0x4
    u16 m_u16PauseFrame;               // offset 0x74, size 0x2
    u32 m_u32PlayerFlg;                // offset 0x78, size 0x4
    u8 m_u8ViewPortNum;                // offset 0x7C, size 0x1

    static stcRequestArray m_oasu32RequestArray[2];
};

class clsPlayAroundSe_Task : public clsSingleModelGimmick_Task<clsPlayAroundSe_Task,
                                                               clsPlayAroundSe_Obj,
                                                               clsModelType_OB_TX> {
public:
    clsPlayAroundSe_Task(u32 u32ObjectAreaNum);
    virtual ~clsPlayAroundSe_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo&) {}
};

#endif // PLAYAROUNDSE_HPP
