#ifndef ITEMBOMB_HPP
#define ITEMBOMB_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"

class clsSe3DControl;
class clsModelType_OB_TX_MO_MA;

enum enmItemBombMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
    MODE_EXP = 2,
};

class clsItemBomb_Obj;

// total size: 0x58
class clsItemBomb_Task : public clsTask {
public:
    static clsModelType_OB_TX_MO_MA t_cModel;
    static clsModelType_OB_TX_MO_MA t_cExpModel;

    clsItemBomb_Task(const NNS_VECTORFAST* pParam1,
                     const NNS_QUATERNION* pParam2,
                     f32 f32Param3,
                     s16 s16Param4);

    virtual ~clsItemBomb_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();

    void registModel(stcBinInfo& rParam1);

    clsItemBomb_Obj* m_pcObj; // offset 0x54, size 0x4
};

// total size: 0x190
class clsItemBomb_Obj : public clsRigidBodyGimmickObj {
public:
    static f32 tof32ClipSqDist;

    clsItemBomb_Obj(clsItemBomb_Task* pParam1,
                    const NNS_VECTORFAST* pParam2,
                    const NNS_QUATERNION* pParam3,
                    f32 f32Param4,
                    s16 s16Param5);

    virtual ~clsItemBomb_Obj();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ITEMTRAP_BOMB_38001; }
    virtual void reset();
    virtual void init() {}
    virtual void main();
    virtual void contactInterraction(clsRigidBodyGimmickObj* pParam1);

    void draw(clsModelType_OB_TX_MO_MA& rParam1,
              f32 (*)[4][4],
              u32* pParam3,
              const f32 (*)[4][4],
              f32 (*)[4][4],
              u32 u32Param6);
    void searchObj();
    void CalcNonGravityVelocity(NNS_VECTORFAST* pParam1);
    void CalcGravityVelocity(NNS_VECTORFAST* pParam1);
    void updataPath();

    clsItemBomb_Task* m_pcTask; // offset 0xD0, size 0x4
    enmItemBombMode m_eMode;    // offset 0xD4, size 0x4
    u8 m_bIsExp;                // offset 0xD8, size 0x1
    // gap 0xD9–0xDB (alignment padding)
    hkSimpleShapePhantom* m_pcPhantom; // offset 0xDC, size 0x4
    clsRetPath m_cRetPath;             // offset 0xE0, size 0x20
    clsPath m_cPath;                   // offset 0x100, size 0x60
    clsSe3DControl* m_pcSe3DControl;   // offset 0x160, size 0x4
    f32 m_f32LifeFrame;                // offset 0x164, size 0x4
    f32 m_f32MatFrame;                 // offset 0x168, size 0x4
    f32 m_f32MatEndFrame;              // offset 0x16C, size 0x4
    f32 m_f32ExpScale;                 // offset 0x170, size 0x4
    f32 m_f32ExpAddScale;              // offset 0x174, size 0x4
    s16 m_s16InitPathNo;               // offset 0x178, size 0x2
    // gap 0x17A–0x17B (alignment padding)
    f32 m_f32OldDistx2; // offset 0x17C, size 0x4
    u8 m_bSearchCourse; // offset 0x180, size 0x1
    // gap 0x181–0x18F (trailing padding)
};

#endif // ITEMBOMB_HPP
