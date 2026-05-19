#ifndef ST02GLINKKUKI_HPP
#define ST02GLINKKUKI_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSe3DControl;

// total size: 0xF0
class clsGLinkKuki_Object : public clsBaseGravityLinkObject {
public:
    // Note: enmMode name collision with Game.hpp (GAME_MODE___NONE) — nested per scaffold rule
    // Values from DWARF for clsGLinkKuki_Object
    enum enmMode {
        MODE_NONE = 0,
        MODE_CRASH = 1,
        MODE_BREAK = 2,
    };

    clsGLinkKuki_Object() {}
    virtual ~clsGLinkKuki_Object() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST02_KUKI_12020;
    } // likely: return 12020; [ASM-derived guess — verify]
    virtual void reset();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void playSe(clsPlayerTask* pcPlayer);
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const
    {
        return &tosCollisionHalfSizeVec;
    } // [new] — verify

    void draw(NNS_OBJECT* psObject,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    enum enmMode m_eMode;            // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4

    static u32 otau32Se_BotanicalLink[2];
    static u32 otau32Se_ShidaCut[2];
    static u32 otau32Se_ShidaCrash[2];
    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0x98
class clsGLinkKuki_Task : public clsSingleModelGimmick_Task<clsGLinkKuki_Task,
                                                            clsGLinkKuki_Object,
                                                            clsModelType_OB_TX> {
public:
    clsGLinkKuki_Task(u32 u32ObjectAreaNum);
    virtual ~clsGLinkKuki_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkShape* m_pcPartsShape; // offset 0x94, size 0x4
};

#endif // ST02GLINKKUKI_HPP
