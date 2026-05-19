#ifndef SHOP_HPP
#define SHOP_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"

// total size: 0x48
struct stcShopDrawData {
    s16 s16MsgX;        // offset 0x0, size 0x2
    s16 s16MsgY;        // offset 0x2, size 0x2
    s16 s16MsgW;        // offset 0x4, size 0x2
    s16 s16MsgH;        // offset 0x6, size 0x2
    s16 s16HukidasiX;   // offset 0x8, size 0x2
    s16 s16TradeX;      // offset 0xA, size 0x2
    s16 s16TradeY;      // offset 0xC, size 0x2
    s16 s16TradeW;      // offset 0xE, size 0x2
    s16 s16TradeH;      // offset 0x10, size 0x2
    s16 s16TradeNextY;  // offset 0x12, size 0x2
    s16 s16TradeTextX;  // offset 0x14, size 0x2
    f32 f32BuyInFrame;  // offset 0x18, size 0x4
    f32 f32OutInFrame;  // offset 0x1C, size 0x4
    s16 s16ItemX;       // offset 0x20, size 0x2
    s16 s16ItemY;       // offset 0x22, size 0x2
    s16 s16ItemW;       // offset 0x24, size 0x2
    s16 s16ItemH;       // offset 0x26, size 0x2
    s16 s16ItemNameH;   // offset 0x28, size 0x2
    f32 f32ListInFrame; // offset 0x2C, size 0x4
    s16 s16YesX;        // offset 0x30, size 0x2
    s16 s16YesY;        // offset 0x32, size 0x2
    s16 s16NoX;         // offset 0x34, size 0x2
    s16 s16NoY;         // offset 0x36, size 0x2
    s16 s16InfoX;       // offset 0x38, size 0x2
    s16 s16InfoY;       // offset 0x3A, size 0x2
    s16 s16InfoW;       // offset 0x3C, size 0x2
    s16 s16InfoH;       // offset 0x3E, size 0x2
    s16 s16InfoEndX;    // offset 0x40, size 0x2
    f32 f32MoveFrame;   // offset 0x44, size 0x4
};

// total size: 0x88
class clsShop_Task : public clsTask {
public:
    virtual ~clsShop_Task() {}
    virtual void execute();
    virtual void draw();

    void drawMessage();
    void drawRingNum();
    void drawGearInfo();
    void drawInfoGearBg(s32 s32GearNo, f32 f32X, f32 f32Y);
    void drawInfoDetails(s32 s32GearNo, f32 f32X, f32 f32Y);
    void drawInfoParts(s32 s32GearNo, f32 f32X, f32 f32Y);
    void drawInfoStatus(s32 s32GearNo, f32 f32X, f32 f32Y);
    void drawInfoRing(s32 s32GearNo, f32 f32X, f32 f32Y);
    void drawInfoUser(s32 s32GearNo, f32 f32X, f32 f32Y);
    void drawInfoName(s32 s32GearNo, f32 f32X, f32 f32Y);
    void drawInfoWindow(s32 s32X, s32 s32Y, s32 s32W, s32 s32H, u32 u32Color);
    void drawTrade();
    void drawGearSelect();
    void drawTradeSelect();
    void updateGearList();

    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x54, size 0x4
    u32 m_u32Flg;                                // offset 0x58, size 0x4
    s8 m_s8GearSelect;                           // offset 0x5C, size 0x1
    s16 m_s16GearSelectTop;                      // offset 0x5E, size 0x2
    s16 m_s16GearNum;                            // offset 0x60, size 0x2
    u16 m_u16TradeAlpha;                         // offset 0x62, size 0x2
    u16 m_u16ItemAlpha;                          // offset 0x64, size 0x2
    u16 m_u16BuyAlpha;                           // offset 0x66, size 0x2
    f32 m_f32WaitFrame;                          // offset 0x68, size 0x4
    s16 m_s16InfoWindowX;                        // offset 0x6C, size 0x2
    f32 m_f32BuyFrame;                           // offset 0x70, size 0x4
    f32 m_f32OutFrame;                           // offset 0x74, size 0x4
    f32 m_f32ListFrame;                          // offset 0x78, size 0x4
    f32 m_f32GearListEffectLine;                 // offset 0x7C, size 0x4
    f32 m_f32InfoMoveFrame;                      // offset 0x80, size 0x4
    f32 m_f32ShopInFrame;                        // offset 0x84, size 0x4
};

#endif
