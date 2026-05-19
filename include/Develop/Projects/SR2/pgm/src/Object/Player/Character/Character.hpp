#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/CharaData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"

class clsModelType_OB_TX;
class clsDrawAttackEffect_Task;
class clsPlayerTask;
namespace nspChara {
struct stcMotionFlgs;
}

// total size: 0x60
class clsCharacter {
public:
    // Bone node indices for character skeleton
    enum enmCharaBornNo {
        BORN_ID__WORLD = 0,
        BORN_ID__UNUSED1 = 1,
        BORN_ID__UNUSED2 = 2,
        BORN_ID__HIP = 3,
        BORN_ID__SPINE1 = 4,
        BORN_ID__SPINE2 = 5,
        BORN_ID__NECK = 6,
        BORN_ID__HEAD = 7,
        BORN_ID__LEFTARM = 8,
        BORN_ID__LEFTFOREARM = 9,
        BORN_ID__LEFTHAND = 10,
        BORN_ID__L_HAND00 = 11,
        BORN_ID__L_HAND01 = 12,
        BORN_ID__L_HAND02 = 13,
        BORN_ID__L_HAND03 = 14,
        BORN_ID__L_HAND04 = 15,
        BORN_ID__L_HAND05 = 16,
        BORN_ID__RIGHTARM = 17,
        BORN_ID__RIGHTFOREARM = 18,
        BORN_ID__RIGHTHAND = 19,
        BORN_ID__R_HAND00 = 20,
        BORN_ID__R_HAND01 = 21,
        BORN_ID__R_HAND02 = 22,
        BORN_ID__R_HAND03 = 23,
        BORN_ID__R_HAND04 = 24,
        BORN_ID__R_HAND05 = 25,
        BORN_ID__E_MC_1 = 26,
        BORN_ID__E_MC_2 = 27,
        BORN_ID__E_MC_3 = 28,
        BORN_ID__LEFTUPLEG = 29,
        BORN_ID__LEFTLEG = 30,
        BORN_ID__LEFTFOOT = 31,
        BORN_ID__LEFTTOE = 32,
        BORN_ID__RIGHTUPLEG = 33,
        BORN_ID__RIGHTLEG = 34,
        BORN_ID__RIGHTFOOT = 35,
        BORN_ID__RIGHTTOE = 36,
        BORN_ID__BD_ALL = 37,
        BORN_ID__HEAD_TOP = 38,
        BORN_ID__SJ_HC_1 = 39,
        BORN_ID__WAV_HL_1 = 40,
        BORN_ID__WAV_HR_1 = 41,
        BORN_ID__C_ECL_1 = 42,
        BORN_ID__C_ECR_1 = 43,
        BORN_ID__AC_NECK_DUM = 44,
        BORN_ID__NW_TC_1 = 45,
        BORN_ID__NW_TC_2 = 46,
        BORN_ID__T_TCL_1 = 47,
        BORN_ID__T_TCL_2 = 48,
        BORN_ID__T_TCR_1 = 49,
        BORN_ID__T_TCR_2 = 50,
        BORN_ID__AC_HIP_DUM = 51,
        BORN_ID__MAX = 52,
    };

    clsCharacter(clsPlayerTask* pcPlayer, u8 u8Type, u8 u8ModelType);
    ~clsCharacter() {}
    f32 getSpeedRate();
    void draw(u32 u32AddDrawFlagI);
    void drawAttackEffect();
    f32 getCollisionRadius() const;
    f32 getDrawOffset() const;
    void behavior();
    void initAttack00();
    void initAttack01();
    void actionAttack00();
    void actionAttack01();
    void updateModel() {}
    void reset() {}
    s32 getNodeIndex(enmCharaBornNo) const;

    u32 holdAttackBase();
    void addAttackMotionFrame();
    u8 isBehaviorMotion(const nspChara::stcMotionFlgs* oapsMotionFlg);
    f32 checkPlayRangeAttackSe();
    void setShadowMatrix();
    u8 getType() const { return m_u8Type; }
    clsModelType_OB_TX* getModelPtr() const { return m_pcModel; }

    static f32 t_of32OffsetWalkHeight;
    static f32 t_of32OffsetGearHeight;
    static NNS_VECTORFAST m_toaFalseStartOffsetVec[19];

    clsModelType_OB_TX* m_pcModel;            // offset 0x0, size 0x4
    stcData* m_posData;                       // offset 0x4, size 0x4
    clsPlayerTask* m_pcPlayer;                // offset 0x8, size 0x4
    f32 m_f32OffsetPosition;                  // offset 0xC, size 0x4
    u8 m_u8Type;                              // offset 0x10, size 0x1
    enmBaseType m_eBaseType;                  // offset 0x14, size 0x4
    enmWalkType m_eWalkType;                  // offset 0x18, size 0x4
    u8 m_u8ModelType;                         // offset 0x1C, size 0x1
    f32 m_f32DrawAlpha;                       // offset 0x20, size 0x4
    f32 m_f32behaviorCnt;                     // offset 0x24, size 0x4
    clsDrawAttackEffect_Task* m_pcDrawEffTsk; // offset 0x28, size 0x4
    f32 m_sFollowOffsetVF[4];                 // offset 0x30, size 0x10
    f32 m_sFollowVF[4];                       // offset 0x40, size 0x10
    u32 m_u32FollowCalcNodeIdx;               // offset 0x50, size 0x4
};

#endif // CHARACTER_HPP
