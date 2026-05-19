#ifndef COMMONMOTION_HPP
#define COMMONMOTION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerMotion.hpp"

// total size: 0x11C
class clsCommonMotion : public clsPlayerMotion {
public:
    virtual ~clsCommonMotion() {}

    virtual void init(s8 s8CharaType, s8 s8ModelType, s8 s8MotionType);
    virtual void registTable(s8 s8MotionType,
                             s8 s8MotionNo,
                             f32 f32StartFrame,
                             f32 f32LinkFrame,
                             clsMotion::enmStatus eStatus);
};

#endif // COMMONMOTION_HPP
