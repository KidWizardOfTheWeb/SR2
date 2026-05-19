#ifndef SCRIPTFRAMETEXCAMERA_HPP
#define SCRIPTFRAMETEXCAMERA_HPP

#include "Develop/Projects/SR2/pgm/src/Script/Script.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptCamera.hpp"
#include "types.h"

// total size: 0x78
class clsScriptCameraFrameTex_Task : public clsTask, public clsScriptCamera {
public:
    clsScriptCameraFrameTex_Task(u8 u8TexNo, clsScript_Task* pcParrent);
    virtual ~clsScriptCameraFrameTex_Task() {}

    virtual void execute();
    virtual void draw();

    void codeSetCamera(u8* pu8Ptr, clsScript_Task* pcTask);
    void checkCamera();

    u8 m_u8TexNo;                    // offset 0x70, size 0x1
    clsScript_Task* m_pcParrentTask; // offset 0x74, size 0x4
};

#endif // SCRIPTFRAMETEXCAMERA_HPP
