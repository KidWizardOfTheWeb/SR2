#ifndef SCRIPTFADE_HPP
#define SCRIPTFADE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Effect/Post/Fade.hpp"

// total size: 0x74
class clsScriptFade_Task : public clsFade_Task {
public:
    virtual ~clsScriptFade_Task() {}

    virtual void execute();
    virtual void draw();

    f32 m_f32WaitFrame; // offset 0x70, size 0x4
};

#endif // SCRIPTFADE_HPP
