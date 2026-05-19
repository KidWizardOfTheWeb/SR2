#ifndef ST05DOMINO_HPP
#define ST05DOMINO_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"

class clsSe3DControl;
class clsPlayerTask;
class clsDomino_Obj;
class clsGimmickRigidBody;

// total size: 0xE0
class clsDomino_Obj : public clsRigidBodyGimmickObj {
public:
    inline clsDomino_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsDomino_Obj() {}

    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    }; // Note: name collision with Game.hpp enmMode

    enmMode m_eMode;                 // offset 0xD0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xD4, size 0x4
    s32 m_s32DrawRotY;               // offset 0xD8, size 0x4
    u32 m_u32DrawFlg;                // offset 0xDC, size 0x4

    static f32 m_tof32ClipSqDist;
    static u8 t_u8DownCount;

    virtual void reset();
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void requestDrawBreakEffect();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void start(const NNS_VECTORFAST& rsLocalFoceVecFast);
    virtual void contactInterraction(clsRigidBodyGimmickObj* pcObject);
    virtual void main();
    virtual void mainCrash();
    inline nspPackId::enm getPackId() const { return nspPackId::ST05_DOMINO_15040; }
};

// total size: 0x14
class clsDominoThroughCol : public clsBaseThroughCollision {
public:
    clsDominoThroughCol() {}
    virtual ~clsDominoThroughCol() {}
    void contactAlwaysEvent(clsPlayerTask* pcPlayer);

    clsDomino_Obj* m_pcObj[2]; // offset 0x8, size 0x8
    u8 m_u8RegistNum;          // offset 0x10, size 0x1
};

// total size: 0xF0
class clsDomino_Task
    : public clsSingleModelGimmick_Task<clsDomino_Task, clsDomino_Obj, clsModelType_OB_TX> {
public:
    clsDomino_Task(u32 u32ObjectAreaNum);
    virtual ~clsDomino_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();

    void setThroughObj();

    static NNS_VECTOR m_tosThroughColPosVec[4];

    clsDominoThroughCol m_acThroughCol[4]; // offset 0x94, size 0x50
    hkShape* m_pcThroghShape;              // offset 0xE4, size 0x4
    hkShape* m_pcShape;                    // offset 0xE8, size 0x4
    clsGimmickRigidBody* m_pcRigidBody;    // offset 0xEC, size 0x4
};

#endif // ST05DOMINO_HPP
