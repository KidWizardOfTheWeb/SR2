#ifndef GEAR_HPP
#define GEAR_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// For now, we assume this to be the correctly associated enum
#ifndef ENMRET_DECLARED
#define ENMRET_DECLARED
enum enmRet {
    VISIBLE_CLIP = 0,
    VISIBLE = 1,
    OUT_VISIBLE = 2,
    OUT_PORTAL = 3,
    OUT_FAR = 4,
};
#endif

enum enmGearType {
    GEAR_TYPE_BOARD = 0,
    GEAR_TYPE_BIKE = 1,
    GEAR_TYPE_AIRRIDE = 2,
    GEAR_TYPE_SKATE = 3,
    GEAR_TYPE_WHEEL = 4,
    GEAR_TYPE_SURFING = 5,
    GEAR_TYPE_EMPTY = 6,
    GEAR_PROTOTYPE_MAX = 7,
    GEAR_TYPE_EFFECT_PART = 7,
    GEAR_TYPE_MODEL_PART = 8,
};

enum enmDraw2DType {
    TYPE_2D_BOARD = 0,
    TYPE_2D_BIKE = 1,
    TYPE_2D_SKATE = 2,
    TYPE_2D_AIRRIDE = 3,
    TYPE_2D_WHEEL = 4,
    TYPE_2D_SURFING = 5,
    TYPE_2D_GRIND = 6,
    TYPE_2D_SP_DURABILITY = 7,
    TYPE_2D_SP_AGP = 8,
    TYPE_2D_SP_MAX_SPEED = 9,
    TYPE_2D_SP_1ST_SPEED = 10,
    TYPE_2D_SP_GC_SPEED = 11,
    TYPE_2D_SP_ADD_TRICK = 12,
    TYPE_2D_SP_GHOST = 13,
    TYPE_2D_SP_AUTO_WALL_RUN = 14,
    TYPE_2D_SP_RING_CAPACITY = 15,
    TYPE_2D_SP_TANK = 16,
    TYPE_2D_SP_MAG_BARRIER = 17,
    TYPE_2D_SP_ANGEL_OR_DEVIL = 18,
    TYPE_2D_SP_ITEM_RANK_UP = 19,
    TYPE_2D_SP_SOUND_CHANGE = 20,
    TYPE_2D_SP_TRAP_VIEW = 21,
    TYPE_2D_SP_TRAP_CTRL = 22,
    TYPE_2D_SP_TRAP_SPEED = 23,
    TYPE_2D_SP_ALL_PARAM_UP = 24,
    TYPE_2D_SP_ATTACK_TIME_UP = 25,
    TYPE_2D_SP_GP_INFINITY = 26,
    TYPE_2D_SP_GP_GET_RATE = 27,
    TYPE_2D_SP_ANGEL = 28,
    TYPE_2D_SP_DEVIL = 29,
    TYPE_2D_SP_THROTTLE = 30,
    TYPE_2D_MAX = 31,
    TYPE_2D_EMPTY = 32,
};

enum enmMotionType {
    MOTION_WALK = 0,
    MOTION_BOARD = 1,
    MOTION_BIKE = 2,
    MOTION_SKATE = 3,
    MOTION_AIRRIDE = 4,
    MOTION_WHEEL = 5,
    MOTION_SURFING = 6,
    MOTION_DUMMY_SKATE_WALK = 7,
    MAX_MOTION = 8,
    MOTION_EMPTY = -1,
};

class clsGearCtrl;

// total size: 0x8
struct stcGearData {
    u32 u32AttributeBits; // offset 0x0, size 0x4
    u32 u32AddAbility;    // offset 0x4, size 0x4
};

// total size: 0x50
class clsGear {
public:
    clsGear(clsGearCtrl* pcGearCtrl, const stcGearData& rsGearData, const stcAddPrfm& rsGearPrfm)
        : m_pcGearCtrl(pcGearCtrl), m_rsGearData(const_cast<stcGearData&>(rsGearData)),
          m_rsGearPrfm(const_cast<stcAddPrfm&>(rsGearPrfm))
    {
    }

    virtual ~clsGear() {}

    virtual void setHideNodeStatus(u32* pStatus) {}

    virtual f32 getDraw2DRate() const { return 1.0f; }

    virtual f32 getAlphaRate(f32 f32Alpha) const { return f32Alpha; }

    virtual stcAddPrfm& getPrfm() const { return m_rsGearPrfm; }

    virtual u32 getGearAbility() const { return m_rsGearData.u32AddAbility; }

    virtual void clearChangeActionParam();

    virtual void behavior() {}

    virtual void behavior_NodeMtx() {}

    virtual void eventGearChange() {}

    virtual void requsetBurnLight(const f32 (&rsMtx)[4][4]) {}

    virtual void draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlag);

    clsGearCtrl* m_pcGearCtrl;      // offset 0x4, size 0x4
    stcGearData& m_rsGearData;      // offset 0x8, size 0x4
    stcAddPrfm& m_rsGearPrfm;       // offset 0xC, size 0x4
    clsModelType_OB_TX m_sModel;    // offset 0x10, size 0x8
    clsModelType_OB m_sShadowModel; // offset 0x18, size 0x4
    NNS_VECTORFAST m_sActionTrans;  // offset 0x20, size 0x10
    NNS_ROTATE m_sActionRot;        // offset 0x30, size 0xC
    NNS_VECTOR m_sActionScale;      // offset 0x3C, size 0xC
    f32 m_f32ActionAlpha;           // offset 0x48, size 0x4
    u32 m_u32ActionCnt;             // offset 0x4C, size 0x4
};

#endif // GEAR_HPP
