#ifndef SVLBTLPOINTPLAYERDATA_HPP
#define SVLBTLPOINTPLAYERDATA_HPP

#include "Develop/Projects/SR2/pgm/src/Game/SurvivalBattle/BaseSvlBtlPlayerData.hpp"

// total size: 0xC
class clsSvlBtlPointPlayerData : public clsBaseSvlBtlPlayerData {
public:
    clsSvlBtlPointPlayerData() {}
    virtual ~clsSvlBtlPointPlayerData() {}

    virtual void damageMissile() {}
    virtual void damageBomb() {}
    virtual void damageGimmick() {}
    virtual void damageGravity() {}
    virtual void damageDead() {}
    virtual void attack() {}
    virtual void cure() {}
};

#endif // SVLBTLPOINTPLAYERDATA_HPP
