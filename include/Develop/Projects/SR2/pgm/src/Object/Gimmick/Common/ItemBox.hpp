#ifndef ITEMBOX_HPP
#define ITEMBOX_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsPlayerTask;

// total size: 0x2C
class clsItemBoxModels {
public:
    clsItemBoxModels() {}
    ~clsItemBoxModels() {}

    clsModelType_OB_TX m_cItemBox;         // offset 0x0, size 0x8
    clsModelType_OB m_cItemBoxAir;         // offset 0x8, size 0x4
    clsModelType_OB_TX_MO_MA m_cColorPool; // offset 0xC, size 0x20
};

class clsItemBox_Task;

class clsGimmickCommon {
public:
    static f32 t_of32ClipDistRate;

private:
    u8 m_bDisableFog; // offset 0x0, size 0x1
};

enum enmItemBoxMode {
    INIT = 0,
    MAIN = 1,
    COLORPOOL = 2,
    SLEEP = 3,
    DEAD = 4,
};

enum enmItemType {
    QUESTION = 0,
    HISPEED = 1,
    SPEEDDOWN = 2,
    AGP_30 = 3,
    AGP_50 = 4,
    AGP_100 = 5,
    AGP_MAX = 6,
    RING_10 = 7,
    RING_20 = 8,
    RING_30 = 9,
    RING_100 = 10,
    ATTACK_1 = 11,
    TRAP_1 = 12,
    TRAP_2 = 13,
    EXPBOMB = 14,
    MAGBARRIER = 15,
    SVLBTL_MISSILE = 16,
    SVLBTL_BOMB = 17,
    SVLBTL_CURE = 18,
    SVLBTL_BARRIER = 19,
    TYPE_MAX = 20,
    COLOR_BALL = 12,
    PARTSLOCK = 13,
};

// total size: 0x90
class clsItemBox_Obj : public clsPhantomGimmickObject {
public:
    clsItemBox_Obj() {}
    virtual ~clsItemBox_Obj() {}
    virtual void contactAlwaysEvent(hkContactPoint* p, clsObject* pObj);
    virtual void contactRemoveEvent(hkContactPoint* p, clsObject* pObj);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ITEM_BOX_2010; }

    void execute();
    u32 execEffect(clsPlayerTask* pcPlayer, u32 u32ItemParam);
    void getAgp(clsPlayerTask* pcHitPlayer, f32 f32AgpAdd);

    enmItemType getItemNo() const { return m_u32ItemNo; }
    u8 isAir() { return m_bAirFlg; }
    u8 isBig() { return 0; }
    u32 calcRateTable(const u8* opu8RateTableI, u32 u32TableNumI, u32 u32ParamI) { return 0; }

    // @STRING@ inline draw callbacks (render system hooks)
    void drawMatModel(clsModelType_OB_TX_MO_MA* pcModel,
                      f32 (*pMtx)[4][4],
                      u32* pu32Flg,
                      const f32 (*pBaseMtx)[4][4],
                      f32 (*pDstMtx)[4][4],
                      u32 u32Arg)
    {
    }
    void draw(NNS_OBJECT* pcObj,
              f32 (*pMtx)[4][4],
              u32* pu32Flg,
              const f32 (*pBaseMtx)[4][4],
              u32 u32Arg1,
              f32 (*pDstMtx)[4][4],
              u32 u32Arg2,
              clsItemBox_Task* pcTask)
    {
    }

    u32 m_u32TexIdx;                // offset 0x60, size 0x4
    u32 m_u32TexIdx2;               // offset 0x64, size 0x4
    enmItemBoxMode m_enItemBoxMode; // offset 0x68, size 0x4
    f32 m_f32WaitTimer;             // offset 0x6C, size 0x4
    enmItemType m_u32ItemNo;        // offset 0x70, size 0x4
    u8 m_bAirFlg;                   // offset 0x74, size 0x1
    f32 m_f32MatMotionFrame;        // offset 0x78, size 0x4
    u32 m_u32HitFlg;                // offset 0x7C, size 0x4
    f32 m_f32LifeFrame;             // offset 0x80, size 0x4
    f32 m_f32Alpha;                 // offset 0x84, size 0x4

    static u32 t_u32ReBorn;
};

class clsItemBox_Task
    : public clsBaseGimmickBody<clsItemBox_Task, clsItemBox_Obj, clsItemBoxModels>,
      public clsGimmickCommon {
public:
    virtual ~clsItemBox_Task();

    clsItemBox_Task(u32 u32ObjectAreaNum, u32 u32TpI);

    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual void createModel(stcBinInfo& rsBinInfoI);

    f32 getScale() const { return m_f32Scale; }
    u8 isItemBom() const { return m_bIsItemBom; }
    void setTexId(u8 u8Air, u32 u32TexId, u32 u32TexId2) {}

    u16* m_TexIdx[2];             // offset 0xBC, size 0x8
    u16* m_TexIdx2[2];            // offset 0xC4, size 0x8
    u32 m_u32PutBoxNum;           // offset 0xCC, size 0x4
    f32 m_f32Scale;               // offset 0xD0, size 0x4
    u8 m_bChangeMaterial2;        // offset 0xD4, size 0x1
    u8 m_bIsItemBom;              // offset 0xD5, size 0x1
    hkShape* m_pcItemBoxShape[2]; // offset 0xD8, size 0x8
    hkShape* m_pcColPoolShape;    // offset 0xE0, size 0x4
};

#endif // ITEMBOX_HPP
