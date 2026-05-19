#ifndef SCRIPTFRAMETEXDRAW_HPP
#define SCRIPTFRAMETEXDRAW_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsScriptCreateFrameTex_Task;
class clsScript_Task;

// total size: 0x80
class clsScriptDrawFrameTex_Task : public clsTask {
public:
    clsScriptDrawFrameTex_Task(u8 u8TexNo,
                               clsScript_Task* pcParrent,
                               clsScriptCreateFrameTex_Task* pcTextureTask);
    virtual ~clsScriptDrawFrameTex_Task() {}

    virtual void draw();

    void drawPolygon();
    void update();
    void setParam(f32 f32PosX,
                  f32 f32PosY,
                  f32 f32Width,
                  f32 f32Height,
                  f32 f32PosZ,
                  f32 f32RotX,
                  f32 f32RotY,
                  f32 f32RotZ);

    // Members
    u8 m_u8TexNo;                                         // offset 0x54, size 0x1
    u8 m_u8Flg;                                           // offset 0x55, size 0x1
    f32 m_f32PosX;                                        // offset 0x58, size 0x4
    f32 m_f32PosY;                                        // offset 0x5C, size 0x4
    f32 m_f32PosZ;                                        // offset 0x60, size 0x4
    f32 m_f32Width;                                       // offset 0x64, size 0x4
    f32 m_f32Height;                                      // offset 0x68, size 0x4
    f32 m_f32RotX;                                        // offset 0x6C, size 0x4
    f32 m_f32RotY;                                        // offset 0x70, size 0x4
    f32 m_f32RotZ;                                        // offset 0x74, size 0x4
    clsScript_Task* m_pcParrentTask;                      // offset 0x78, size 0x4
    clsScriptCreateFrameTex_Task* m_pcCreateTexture_Task; // offset 0x7C, size 0x4
};

#endif // SCRIPTFRAMETEXDRAW_HPP
