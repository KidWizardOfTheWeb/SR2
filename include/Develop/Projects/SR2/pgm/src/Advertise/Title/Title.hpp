#ifndef TITLE_HPP
#define TITLE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OODraw2d.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/MsgWnd2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

extern stcTexUV g_oasTexSrc_Title[84];

// total size: 0x64
class clsTitle_Task : public clsTask {
public:
    virtual ~clsTitle_Task() {}
    virtual void execute();
    virtual void draw();

    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x54, size 0x4
    f32 m_f32LogoTime;                           // offset 0x58, size 0x4
    u8 m_u8ReadMode;                             // offset 0x5C, size 0x1
    u8 m_bMovieEnd;                              // offset 0x5D, size 0x1
    clsMsgWnd_Task* m_pcMsgWndTask;              // offset 0x60, size 0x4
};

#endif // TITLE_HPP
