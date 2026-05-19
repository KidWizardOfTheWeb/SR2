#ifndef ROBOMOTION_HPP
#define ROBOMOTION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerMotion.hpp"

// total size: 0x120
class clsRoboMotion : public clsPlayerMotion {
public:
    virtual ~clsRoboMotion() {}

    virtual void init(s8 s8CharaType, s8 s8ModelType, s8 s8MotionType);
    virtual void registTable(s8 s8MotionType,
                             s8 s8MotionNo,
                             f32 f32StartFrame,
                             f32 f32LinkFrame,
                             clsMotion::enmStatus eStatus);
    virtual void reset();

    nspChara::enmCharaType m_eCharaType; // offset 0x11C, size 0x4
};

#endif // ROBOMOTION_HPP
