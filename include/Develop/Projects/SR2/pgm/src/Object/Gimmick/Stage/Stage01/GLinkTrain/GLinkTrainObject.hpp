#ifndef GLINKTRAINOBJECT_HPP
#define GLINKTRAINOBJECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"

class clsSe3DControl;
class clsBackLineEffectTask;

enum enmPositionType {
    POSITION_HEAD = 0,
    POSITION_INSIDE = 1,
    POSITION_REAR = 2,
};

// total size: 0x1B0
class clsGLinkTrain_Object : public clsBaseGravityLinkObject {
public:
    // Note: enmMode collision with Game.hpp (GAME_MODE___* pParam1) — nested here
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmFlag {
        FLAG_CLEAR = 0,
        FLAG_VIBRATION = 1,
        FLAG_AUTORETURN = 2,
        FLAG_SCALING = 4,
        FLAG_INIT = 7,
    };

    clsPath m_cPath;                         // offset 0xE0, size 0x60
    enmMode m_eMode;                         // offset 0x140, size 0x4
    enmPositionType m_ePositionType;         // offset 0x144, size 0x4
    s32 m_s32PathNo;                         // offset 0x148, size 0x4
    f32 m_f32Offset;                         // offset 0x14C, size 0x4
    f32 m_f32Speed;                          // offset 0x150, size 0x4
    clsSe3DControl* m_pcSe3DControl;         // offset 0x154, size 0x4
    u8 m_bDraw;                              // offset 0x158, size 0x1
    f32 m_sDrawMtx[4][4];                    // offset 0x160, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2]; // offset 0x1A0, size 0x8

    static clsGravityGimmickParam t_ocGravityGimmickParam;
    static clsGravityGimmickParam t_ocGravityGimmickParam2;
    static u32 otau32Se_TrainHorn[2];
    static u32 otau32Se_TrainL[2];
    static u32 otau32Se_TrainCrash[2];
    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;

    clsGLinkTrain_Object();
    void startGravityAction(clsPlayerTask* pParam1, enmFlag);
    void draw(NNS_OBJECT* pParam1,
              f32 (*)[4][4],
              u32* pParam3,
              const f32 (*)[4][4],
              f32 (*)[4][4],
              u32 u32Param6);

    virtual ~clsGLinkTrain_Object() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::ST01_GLINK_TRAIN_OBJECT_11201; }
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const { return &tosCollisionHalfSizeVec; }
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void drawEffect(clsPlayerTask* pParam1);
};

#endif // GLINKTRAINOBJECT_HPP
