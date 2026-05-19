#ifndef CHARASCRGP_HPP
#define CHARASCRGP_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaRoboBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

// total size: 0x90
class clsCharaScrGp : public clsCharaRoboBase {
public:
    clsCharaScrGp(clsPlayerTask* pcPlayer) : clsCharaRoboBase(pcPlayer, 0, 0) {}
    virtual ~clsCharaScrGp() {}

    virtual void draw(u32 u32Param1);
    virtual void initAttack00();
    virtual void initAttack01();
    virtual void actionAttack00();
    virtual void actionAttack01();
    virtual void reset();

    void loadAdditionalData(stcBinInfo& rParam1);

    static stcParam asScrGpLineParam[2];

    // Members (offset 0x80+)
    clsBackLineEffectTask* m_apcLineTask[2]; // offset 0x80, size 0x8
};

#endif // CHARASCRGP_HPP
