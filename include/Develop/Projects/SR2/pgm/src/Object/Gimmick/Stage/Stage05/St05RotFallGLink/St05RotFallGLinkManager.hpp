#ifndef ST05ROTFALLGLINKMANAGER_HPP
#define ST05ROTFALLGLINKMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GmkBurnLight.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotFallGLink/St05RotFallGLinkObject.hpp"

// total size: 0x70
class clsRotFallGLinkManager_Object : public clsGimmickObj {
public:
    clsRotFallGLinkManager_Object();
    virtual ~clsRotFallGLinkManager_Object();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST05_ROT_FALL_GLINK_MANAGER_15050;
    }

    void reset();
    void execute();
    void draw();
    void stop();

    clsRotFallGLink_Object* m_pcObject;                                // offset 0x50, size 0x4
    stcSetDataDetail* m_psSetData;                                     // offset 0x54, size 0x4
    s32 m_s32ObjectNum;                                                // offset 0x58, size 0x4
    clsGmkBurnLight_Task<clsModelType_OB_TX_MO_MA>* m_pcBurnLightTask; // offset 0x5C, size 0x4
    u8 m_bStop;                                                        // offset 0x60, size 0x1
};

#endif // ST05ROTFALLGLINKMANAGER_HPP
