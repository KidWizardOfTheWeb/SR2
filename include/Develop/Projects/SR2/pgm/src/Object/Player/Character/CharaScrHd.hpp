#ifndef CHARASCRHD_HPP
#define CHARASCRHD_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/IonMist/IonMist.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaRoboBase.hpp"
#include "types.h"

struct stcCharaScrHdParam {
    u16 u16Flg;    // offset 0x0
    u8 u8Num;      // offset 0x2
    u8 u8MaxAlpha; // offset 0x3
    s32 s32No;     // offset 0x4
    s32 s32RotZ;   // offset 0x8
    f32 f32Frame;  // offset 0xC
    f32 f32Tu;     // offset 0x10
    f32 f32TuSize; // offset 0x14
};

class clsBackLineEffectTask;
class clsPlayerTask;

class clsCharaScrHd : public clsCharaRoboBase {
public:
    virtual ~clsCharaScrHd();

    clsCharaScrHd(clsPlayerTask* pcPlayerTask) : clsCharaRoboBase(pcPlayerTask, 0, 0) {}

    virtual void draw(u32 u32Arg);
    virtual void reset();
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();

    void loadAdditionalData(stcBinInfo& rParam);

    static stcCharaScrHdParam asScrHdLineParam[2];

    // Members
    clsBackLineEffectTask* m_apcLineTask[2]; // offset 0x80, size 0x8
};

#endif // CHARASCRHD_HPP
