#ifndef EXTRAMENU_HPP
#define EXTRAMENU_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"

class clsMovie_Task; // pointer-only; full definition in System/Movie.hpp (placeholder)

// total size: 0x94
class clsExtraMenu_Task : public clsTask {
public:
    virtual ~clsExtraMenu_Task() {}
    virtual void execute();
    virtual void draw();

    clsExtraMenu_Task(clsAdvertiseMgr_Task* param_1) : clsTask(0, 0) {}

    void setTheater();
    void setSound(u32 u32Arg);
    void checkTheater();
    void checkDeside();
    u8 controlGallery();
    void checkEnd();
    void checkFont();
    void drawGearSingle(s32 s32Arg, f32 f32X, f32 f32Y, u32 u32Arg);
    void drawGearCursol(f32 f32X, f32 f32Y);
    void drawGearView();
    void drawInfoWindow(s32 s32A, s32 s32B, s32 s32C, s32 s32D, u32 u32Arg);
    void drawInfoName(s32 s32Arg, f32 f32X, f32 f32Y);
    void drawInfoUser(s32 s32Arg, f32 f32X, f32 f32Y);
    void drawInfoStatus(s32 s32Arg, f32 f32X, f32 f32Y);
    void drawInfoParts(s32 s32Arg, f32 f32X, f32 f32Y);
    void drawInfoDetails(s32 s32Arg, f32 f32X, f32 f32Y);
    void drawInfoGearBg(s32 s32Arg, f32 f32X, f32 f32Y);
    void drawGearInfo();
    void drawGallery();

    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x54, size 0x4
    u8 m_u8ReadMode;                             // offset 0x58, size 0x1
    u8 m_bMovieEnd;                              // offset 0x59, size 0x1
    u8 m_bMovieChenge;                           // offset 0x5A, size 0x1
    u8 m_bBgmChenge;                             // offset 0x5B, size 0x1
    u8 m_bMiniMovieEnd;                          // offset 0x5C, size 0x1
    u32 m_u32MovieAsync;                         // offset 0x60, size 0x4
    u32 m_u32MusicType;                          // offset 0x64, size 0x4
    u32 m_u32Movie;                              // offset 0x68, size 0x4
    u32 m_u32Deside;                             // offset 0x6C, size 0x4
    f32 m_f32SubMovieFreeWait;                   // offset 0x70, size 0x4
    u8 m_u8GalleryMode;                          // offset 0x74, size 0x1
    u32 m_u32GallerySellect;                     // offset 0x78, size 0x4
    u16 m_u16SelectAlpha;                        // offset 0x7C, size 0x2
    u16 m_u16CorsolAlpha;                        // offset 0x7E, size 0x2
    u8 m_bGalleryDraw;                           // offset 0x80, size 0x1
    u8 m_bGalleryInfoDraw;                       // offset 0x81, size 0x1
    u8 m_u8GalleryInfoAlpha;                     // offset 0x82, size 0x1
    f32 m_f32ButtonDrawWait;                     // offset 0x84, size 0x4
    u32 m_u32MovieNo;                            // offset 0x88, size 0x4
    f32 m_f32MovieStartWaitFrame;                // offset 0x8C, size 0x4
    clsMovie_Task* m_psMiniMovieTask;            // offset 0x90, size 0x4
};

#endif // EXTRAMENU_HPP
