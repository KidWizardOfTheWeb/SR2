#ifndef ST15GLINKFLOORBOARD_HPP
#define ST15GLINKFLOORBOARD_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkShape;
class clsPlayerTask;
class clsSe3DControl;

// total size: 0x140
class clsGLinkFloorBoard_Object : public clsBaseGravityLinkObject {
public:
    // Note: enmMode name collision with Game.hpp ? nested per scaffold rule
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    clsGLinkFloorBoard_Object() {}
    virtual ~clsGLinkFloorBoard_Object() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST15_GLINK_FLOOR_BOARD_25060; }
    virtual void reset();
    virtual void main();
    virtual void mainGravity();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent() {}
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const { return &tosCollisionHalfSizeVec; }

    void draw(NNS_OBJECT* psObject,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    enum enmMode m_eMode;            // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4
    s32 m_s32CheckHP;                // offset 0xE8, size 0x4
    u32 m_u32LinkMapUserDataNo;      // offset 0xEC, size 0x4
    u8 m_bDrawFlag;                  // offset 0xF0, size 0x1
    u8 m_StateChangeFlag;            // offset 0xF1, size 0x1
    f32 m_sEffectMtx[4][4];          // offset 0x100, size 0x40

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0x9C
class clsGLinkFloorBoard_Task : public clsSingleModelGimmick_Task<clsGLinkFloorBoard_Task,
                                                                  clsGLinkFloorBoard_Object,
                                                                  clsModelType_OB_TX>,
                                public clsGimmickCommon {
public:
    clsGLinkFloorBoard_Task(u32 u32ObjectAreaNum);
    virtual ~clsGLinkFloorBoard_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    void startGActionCheck(s32 os32HP);
    void endGActionCheck();
    void rebirthSetFloorBoard();

    hkShape* m_pcPartsShape; // offset 0x98, size 0x4
};

#endif // ST15GLINKFLOORBOARD_HPP
