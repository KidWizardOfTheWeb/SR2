#ifndef ST05ROTFALLGLINKOBJECT_HPP
#define ST05ROTFALLGLINKOBJECT_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

class clsSe3DControl;
class clsPlayerTask;
struct hkContactPoint;

// total size: 0xF0
class clsRotFallGLink_Object : public clsBaseGravityLinkObject {
public:
    // TODO: enmMode name collision with Game.hpp — verify correct enum body during implementation
    enum enmMode {
        MODE_NONE = 0,
        MODE_EXECUTE = 1,
        MODE_BREAK = 2,
    };

    clsRotFallGLink_Object() {}
    virtual ~clsRotFallGLink_Object() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST05_ROT_FALL_GLINK_OBJECT_15051;
    } // [verify params from ASM]
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void requestDrawContactEffect(const hkContactPoint* pParam1);
    virtual void drawEffect(clsPlayerTask* pParam1);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const { return &tosCollisionHalfSizeVec; }

    u8 draw(NNS_OBJECT* pParam1,
            f32 (*)[4][4],
            u32* pParam3,
            const f32 (*)[4][4],
            f32 (*)[4][4],
            u32 u32Param6);

    static f32 t_f32OffsetSide;
    static f32 t_oaf32FallSpeed[2];
    static f32 t_of32FallAccele;
    static f32 t_oaf32IntervalFrame[2];
    static f32 t_oaf32OffsetSide[2];
    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
    static f32 t_sBaseMtx[4][4];
    static f32 t_sBaseInvMtx[4][4];
    static NNS_VECTORFAST t_sDirVecFast;
    static s32 t_s32AppearCount;
    static f32 t_f32AppearFrame;
    static clsGravityGimmickParam* t_opcGravityGimmickParam;
    static f32 t_f32FallSpeed;
    static f32 t_f32IntervalFrame;

    enmMode m_eMode;                 // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4
    u32 m_u32SePlayFlg;              // offset 0xE8, size 0x4
    u32 m_u32DrawFlg;                // offset 0xEC, size 0x4
};

#endif // ST05ROTFALLGLINKOBJECT_HPP
