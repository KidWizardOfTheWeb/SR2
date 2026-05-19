#ifndef GEARCHILDREN_HPP
#define GEARCHILDREN_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnEffectPart.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnAirride.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnBike.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnBoard.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnEmpty.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnGrind.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnModelPart.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnSkate.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnSurfing.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearPtnWheel.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsTask;

// TODO: scaffold all gear child classes (depend on clsGear → clsGearBasePrototype)

namespace nspGear {
enum enmLevel {
    LV_ERROR = -1,
    LV_BASE = 0,
    LV_01 = 1,
    LV_02 = 2,
    LV_03 = 3,
    MAX_LV_NUM = 4,
    MAX_LV_TABLE_NUM = 4,
    MAX_MODELS = 9,
};
}

// total size: 0x70
class clsGearBdDef : public clsGearPtnBoard {
public:
    clsGearBdDef(clsGearCtrl* pcGearCtrl,
                 const stcGearData& rsGearData,
                 const stcAddPrfm& rsGearPrfm)
        : clsGearPtnBoard(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearBdDef() {}
};

// total size: 0x70
class clsGearSpDef : public clsGearPtnBoard {
public:
    clsGearSpDef(clsGearCtrl* pcGearCtrl,
                 const stcGearData& rsGearData,
                 const stcAddPrfm& rsGearPrfm)
        : clsGearPtnBoard(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpDef() {}
};

// total size: 0x60
class clsGearBkDef : public clsGearPtnBike {
public:
    clsGearBkDef(clsGearCtrl* pcGearCtrl,
                 const stcGearData& rsGearData,
                 const stcAddPrfm& rsGearPrfm)
        : clsGearPtnBike(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearBkDef() {}
};

// total size: 0x60
class clsGearSuperHangOn : public clsGearPtnBike {
public:
    clsGearSuperHangOn(clsGearCtrl* pcGearCtrl,
                       const stcGearData& rsGearData,
                       const stcAddPrfm& rsGearPrfm)
        : clsGearPtnBike(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSuperHangOn() {}
    virtual enmDraw2DType getDraw2DType() const { return TYPE_2D_SP_SOUND_CHANGE; }
};

// total size: 0x60
class clsGearArDef : public clsGearPtnAirride {
public:
    clsGearArDef(clsGearCtrl* pcGearCtrl,
                 const stcGearData& rsGearData,
                 const stcAddPrfm& rsGearPrfm)
        : clsGearPtnAirride(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearArDef() {}
};

// total size: 0xA0
class clsGearSfDef : public clsGearPtnSurfing {
public:
    clsGearSfDef(clsGearCtrl* pcGearCtrl,
                 const stcGearData& rsGearData,
                 const stcAddPrfm& rsGearPrfm)
        : clsGearPtnSurfing(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSfDef() {}
};

// total size: 0x70
class clsGearWhDef : public clsGearPtnWheel {
public:
    clsGearWhDef(clsGearCtrl* pcGearCtrl,
                 const stcGearData& rsGearData,
                 const stcAddPrfm& rsGearPrfm)
        : clsGearPtnWheel(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearWhDef() {}
};

// total size: 0x80
class clsGearGdDef : public clsGearPtnGrind {
public:
    clsGearGdDef(clsGearCtrl* pcGearCtrl,
                 const stcGearData& rsGearData,
                 const stcAddPrfm& rsGearPrfm)
        : clsGearPtnGrind(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearGdDef() {}
};

// total size: 0x70
class clsGearSkDef : public clsGearPtnSkate {
public:
    clsGearSkDef(clsGearCtrl* pcGearCtrl,
                 const stcGearData& rsGearData,
                 const stcAddPrfm& rsGearPrfm)
        : clsGearPtnSkate(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSkDef() {}
};

class clsGearEmDef : public clsGearPtnEmpty {
public:
    clsGearEmDef(clsGearCtrl* pcGearCtrl,
                 const stcGearData& rsGearData,
                 const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEmpty(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearEmDef() {}
};

// total size: 0x60
class clsGearSpThrottle : public clsGearPtnEffectPart {
public:
    virtual ~clsGearSpThrottle() {}

    virtual enmDraw2DType getDraw2DType() const { return m_eDraw2DType; }
    virtual f32 getDraw2DRate() const;
    virtual stcAddPrfm& getPrfm() const;
    virtual void eventGearChange();
    virtual void draw(const f32 (*pParam1)[4][4], f32 f32Param2, u32 u32Param3) {}
    void copy(const clsGearSpThrottle* pcGear);

    nspGear::enmLevel m_eLevel;  // offset 0x50, size 0x4
    enmDraw2DType m_eDraw2DType; // offset 0x54, size 0x4
    u32 m_u32SelectNo;           // offset 0x58, size 0x4
    f32 m_f32SelectFrame;        // offset 0x5C, size 0x4
};

// total size: 0x50
class clsGearSpTank : public clsGearPtnEffectPart {
public:
    virtual ~clsGearSpTank() {}

    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(16); }
    virtual void eventGearChange();
    virtual void draw(const f32 (*pParam1)[4][4], f32 f32Param2, u32 u32Param3) {}
};

// total size: 0x50
class clsGearSpMagBarrier : public clsGearPtnEffectPart {
public:
    virtual ~clsGearSpMagBarrier() {}

    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(17); }
    virtual void eventGearChange();
    virtual void draw(const f32 (*pParam1)[4][4], f32 f32Param2, u32 u32Param3) {}
};

// total size: 0x50
class clsGearSpCtrlTrap : public clsGearPtnEffectPart {
public:
    virtual ~clsGearSpCtrlTrap() {}

    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(22); }
    virtual void eventGearChange();
    virtual void draw(const f32 (*pParam1)[4][4], f32 f32Param2, u32 u32Param3) {}
};

// total size: 0x50
class clsGearSpSpeedTrap : public clsGearPtnEffectPart {
public:
    virtual ~clsGearSpSpeedTrap() {}

    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(23); }
    virtual void eventGearChange();
    virtual void draw(const f32 (*pParam1)[4][4], f32 f32Param2, u32 u32Param3) {}
};

// total size: 0x50
class clsGearSpViewTrap : public clsGearPtnEffectPart {
public:
    virtual ~clsGearSpViewTrap() {}

    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(21); }
    virtual void eventGearChange();
    virtual void draw(const f32 (*pParam1)[4][4], f32 f32Param2, u32 u32Param3) {}
};

// total size: 0x60
class clsGearSpGpInfinity : public clsGearPtnModelPart {
public:
    clsGearSpGpInfinity(clsGearCtrl* pcGearCtrl,
                        const stcGearData& rsGearData,
                        const stcAddPrfm& rsGearPrfm)
        : clsGearPtnModelPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpGpInfinity() {}

    virtual enmDraw2DType getDraw2DType() const { return (enmDraw2DType)(26); }
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlagI);
};

// total size: 0x60
class clsGearAngelOrDevil : public clsGearPtnAirride {
public:
    virtual ~clsGearAngelOrDevil() {}

    virtual void clearChangeActionParam();
    virtual void behavior();
};

// total size: 0x80
class clsGearAngelOrDevilChange : public clsGearPtnAirride {
public:
    enum enmType {
        TYPE_NORAML = 0,
        TYPE_ANGEL = 1,
        TYPE_DEVIL = 2,
        TYPE_MAX = 3,
    };

    virtual ~clsGearAngelOrDevilChange() {}

    virtual enmDraw2DType getDraw2DType() const { return m_eDraw2DType; }
    virtual f32 getDraw2DRate() const;
    virtual void behavior();
    virtual void eventGearChange();

    enmDraw2DType m_eDraw2DType;       // offset 0x60, size 0x4
    u32 m_u32SelectNo;                 // offset 0x64, size 0x4
    f32 m_f32SelectFrame;              // offset 0x68, size 0x4
    enmType m_eType;                   // offset 0x6C, size 0x4
    clsModelType_OB_TX* m_apcModel[3]; // offset 0x70, size 0xC
};

// total size: 0x70
class clsInitialBoard : public clsGearPtnBoard {
public:
    virtual ~clsInitialBoard() {}

    void drawNonAction(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlagI);
};

// total size: 0x80
class clsGearThrottle : public clsGearPtnBoard {
public:
    virtual ~clsGearThrottle() {}

    virtual void clearChangeActionParam();
    virtual void behavior();

    clsGearSpThrottle* m_pcGearOldThrottle; // offset 0x70, size 0x4
};

// total size: 0x70
class clsGearReserveTank : public clsGearPtnBike {
public:
    virtual ~clsGearReserveTank() {}

    virtual void setHideNodeStatus(u32* psNodeStat);
    virtual void clearChangeActionParam();

    u8 m_u8RestRankCnt; // offset 0x60, size 0x1
};

// total size: 0x80
class clsGearMag : public clsGearPtnBoard {
public:
    virtual ~clsGearMag() {}

    virtual void setHideNodeStatus(u32* psNodeStat);
    virtual void clearChangeActionParam();
    virtual void behavior();
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlagI);

    NNS_VECTOR* m_psTranslation; // offset 0x70, size 0x4
};

// total size: 0x60
class clsGearSp1stSpeed : public clsGearPtnEffectPart {
public:
    clsGearSp1stSpeed(clsGearCtrl* pcGearCtrl,
                      const stcGearData& rsGearData,
                      const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSp1stSpeed();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void clearChangeActionParam();
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);

    u8 m_u8EffectType;       // offset 0x50, size 0x1
    clsTask* m_pcEffectTask; // offset 0x54, size 0x4
};

// total size: 0x50
class clsGearSpMaxSpeed : public clsGearPtnEffectPart {
public:
    clsGearSpMaxSpeed(clsGearCtrl* pcGearCtrl,
                      const stcGearData& rsGearData,
                      const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpMaxSpeed();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void eventGearChange();
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);
};

// total size: 0x50
class clsGearSpAgp : public clsGearPtnEffectPart {
public:
    clsGearSpAgp(clsGearCtrl* pcGearCtrl,
                 const stcGearData& rsGearData,
                 const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpAgp();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);
};

// total size: 0x50
class clsGearSpAttackTimeUp : public clsGearPtnModelPart {
public:
    clsGearSpAttackTimeUp(clsGearCtrl* pcGearCtrl,
                          const stcGearData& rsGearData,
                          const stcAddPrfm& rsGearPrfm)
        : clsGearPtnModelPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpAttackTimeUp();
    virtual enmDraw2DType getDraw2DType() const;
};

// total size: 0x50
class clsGearSpAllParamUp : public clsGearPtnModelPart {
public:
    clsGearSpAllParamUp(clsGearCtrl* pcGearCtrl,
                        const stcGearData& rsGearData,
                        const stcAddPrfm& rsGearPrfm)
        : clsGearPtnModelPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpAllParamUp();
    virtual enmDraw2DType getDraw2DType() const;
};

// total size: 0x50
class clsGearSpDurability : public clsGearPtnModelPart {
public:
    clsGearSpDurability(clsGearCtrl* pcGearCtrl,
                        const stcGearData& rsGearData,
                        const stcAddPrfm& rsGearPrfm)
        : clsGearPtnModelPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpDurability();
    virtual enmDraw2DType getDraw2DType() const;
};

class clsGearSpGpGetRate : public clsGearPtnEffectPart {
public:
    clsGearSpGpGetRate(clsGearCtrl* pcGearCtrl,
                       const stcGearData& rsGearData,
                       const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpGpGetRate();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);
};

class clsGearSpSoundChange : public clsGearPtnEffectPart {
public:
    clsGearSpSoundChange(clsGearCtrl* pcGearCtrl,
                         const stcGearData& rsGearData,
                         const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpSoundChange();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);
};

class clsGearSpItemRankUp : public clsGearPtnEffectPart {
public:
    clsGearSpItemRankUp(clsGearCtrl* pcGearCtrl,
                        const stcGearData& rsGearData,
                        const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpItemRankUp();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);
};

class clsGearSpRingCapacity : public clsGearPtnEffectPart {
public:
    clsGearSpRingCapacity(clsGearCtrl* pcGearCtrl,
                          const stcGearData& rsGearData,
                          const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpRingCapacity();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);
};

class clsGearSpAutoWall : public clsGearPtnEffectPart {
public:
    clsGearSpAutoWall(clsGearCtrl* pcGearCtrl,
                      const stcGearData& rsGearData,
                      const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpAutoWall();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);
};

class clsGearSpGhost : public clsGearPtnEffectPart {
public:
    clsGearSpGhost(clsGearCtrl* pcGearCtrl,
                   const stcGearData& rsGearData,
                   const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpGhost();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);
};

class clsGearSpAddTrick : public clsGearPtnEffectPart {
public:
    clsGearSpAddTrick(clsGearCtrl* pcGearCtrl,
                      const stcGearData& rsGearData,
                      const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpAddTrick();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);
};

class clsGearSpGcSpeed : public clsGearPtnEffectPart {
public:
    clsGearSpGcSpeed(clsGearCtrl* pcGearCtrl,
                     const stcGearData& rsGearData,
                     const stcAddPrfm& rsGearPrfm)
        : clsGearPtnEffectPart(pcGearCtrl, rsGearData, rsGearPrfm)
    {
    }
    virtual ~clsGearSpGcSpeed();
    virtual enmDraw2DType getDraw2DType() const;
    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);
};

#endif // GEARCHILDREN_HPP
