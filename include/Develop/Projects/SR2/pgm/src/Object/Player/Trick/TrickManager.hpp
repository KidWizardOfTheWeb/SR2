#ifndef TRICKMANAGER_HPP
#define TRICKMANAGER_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/BaseTrickAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/FlipTrickAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/FreeTrickAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/PartsTrickAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/PipeTrickAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/SpinTrickAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/TrickParam.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/TurbTrickAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/VerticalTrickAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/WallTrickAction.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlayerTask;

// total size: 0x160
class clsTrickManager {
public:
    clsTrickManager() {}
    clsTrickManager(clsPlayerTask* pcPlayer);
    ~clsTrickManager();

    void init();
    void execute();
    void reset();
    u8 check();
    void landing();
    void end();
    void cancel();
    enmKickerRankZone checkTrickRankZone();
    nspTrick::enmKicker getKickerType() const { return m_cParam.m_eKickerType; }

    clsBaseTrickAction* m_apcActionTable[9];       // offset 0x0, size 0x24
    clsTrickParam m_cParam;                        // offset 0x30, size 0xD0
    clsFlipTrickAction m_cFlipTrickAction;         // offset 0x100, size 0x4
    clsSpinTrickAction m_cSpinTrickAction;         // offset 0x104, size 0x4
    clsPipeTrickAction m_cPipeTrickAction;         // offset 0x108, size 0x4
    clsFreeTrickAction m_cFreeTrickAction;         // offset 0x10C, size 0x4
    clsWallTrickAction m_cWallTrickAction;         // offset 0x110, size 0x4
    clsVerticalTrickAction m_cVerticalTrickAction; // offset 0x120, size 0x30
    clsTurbTrickAction m_cTurbTrickAction;         // offset 0x150, size 0x4
    clsPartsTrickAction m_cPartsTrickAction;       // offset 0x154, size 0x4
};

#endif // TRICKMANAGER_HPP
