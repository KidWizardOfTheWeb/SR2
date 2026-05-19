#ifndef ST05ROTFALLOBJECT_HPP
#define ST05ROTFALLOBJECT_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSe3DControl;
class clsMultiObTxModels;

enum enmRotFallMode {
    MODE_INIT = 0,
    MODE_WAIT = 1,
    MODE_MAIN = 2,
};

// total size: 0x170
class clsRotFall_Object : public clsRigidBodyGimmickObj {
public:
    // TODO: enmModelType name collision with CharaData.hpp — verify scope during implementation
    enum enmModelType {
        MODEL_TYPE_ROCK_A = 0,
        MODEL_TYPE_ROCK_B = 1,
        MODEL_TYPE_ROCK_C = 2,
        MAX_MODEL_TYPE_NUM = 3,
    };

    clsRotFall_Object() {}
    virtual ~clsRotFall_Object() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST05_ROT_FALL_OBJECT_15011; }
    virtual void reset();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();

    void draw(clsMultiObTxModels& rcObj,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4]);
    void countAppearFrame();
    void clearAppearFrame();

    static f32 tof32ClipSqDist;
    static f32 t_of32FallHeighTable[14];
    static NNS_VECTOR t_osScaleVec[3];
    static f32 t_f32AppearFrame;
    static u8 t_au8ModelTypeTable[14];

    f32 m_sBaseMtx[4][4];            // offset 0xD0, size 0x40
    f32 m_sBaseInvMtx[4][4];         // offset 0x110, size 0x40
    NNS_VECTOR m_sFallRotSpeed;      // offset 0x150, size 0xC
    enmRotFallMode m_eMode;          // offset 0x15C, size 0x4
    enmModelType m_eModelType;       // offset 0x160, size 0x4
    u32 m_u32DrawFlg;                // offset 0x164, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0x168, size 0x4
};

#endif // ST05ROTFALLOBJECT_HPP
