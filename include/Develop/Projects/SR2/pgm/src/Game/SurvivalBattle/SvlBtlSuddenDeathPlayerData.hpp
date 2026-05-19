#ifndef SVLBTLSUDDENDEATHPLAYERDATA_HPP
#define SVLBTLSUDDENDEATHPLAYERDATA_HPP

#include "Develop/Projects/SR2/pgm/src/Game/SurvivalBattle/BaseSvlBtlPlayerData.hpp"

// total size: 0xC
class clsSvlBtlSuddendeathPlayerData : public clsBaseSvlBtlPlayerData {
public:
    clsSvlBtlSuddendeathPlayerData() {}
    virtual ~clsSvlBtlSuddendeathPlayerData() {}

    virtual void damageMissile() {}
    virtual void damageBomb() {}
    virtual void damageGimmick() {}
    virtual void damageGravity() {}
    virtual void damageDead() {}
    virtual void attack() {}
    virtual void cure() {}
};

#endif // SVLBTLSUDDENDEATHPLAYERDATA_HPP
