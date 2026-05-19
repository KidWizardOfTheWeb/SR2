#ifndef SCRIPTSOUND_HPP
#define SCRIPTSOUND_HPP

#include "Develop/Projects/SR2/pgm/src/Script/Script.hpp"

class clsScriptSound {
public:
    void codeBgm(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeBgmVol(u8* pu8Ptr, clsScript_Task* pcTask);
    void codeBgmStop(u8* pu8Ptr, clsScript_Task* pcTask);
};

#endif // SCRIPTSOUND_HPP
