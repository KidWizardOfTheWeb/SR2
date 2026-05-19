#ifndef ST05ROTFALLMANAGER_HPP
#define ST05ROTFALLMANAGER_HPP

#include "types.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotFall/St05RotFallObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

// total size: 0x60
class clsRotFallManager_Object : public clsGimmickObj {
public:
    clsRotFallManager_Object();
    virtual ~clsRotFallManager_Object();

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual inline nspPackId::enm getPackId() const;

    void reset();
    void execute();
    void draw();
    void stop();

    static s8 t_oas8Numtable[14];

    clsRotFall_Object* m_pcObject; // offset 0x50, size 0x4
    stcSetDataDetail* m_psSetData; // offset 0x54, size 0x4
    s32 m_s32ObjectNum;            // offset 0x58, size 0x4
    u8 m_bStop;                    // offset 0x5C, size 0x1
};

#endif // ST05ROTFALLMANAGER_HPP
