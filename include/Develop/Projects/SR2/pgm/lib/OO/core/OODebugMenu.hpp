#ifndef OODEBUGMENU_HPP
#define OODEBUGMENU_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"

enum enmDraw {
    DRAW___NON = 0,
    DRAW___ING = 1,
    DRAW___ONE_TIME_CHANGE = 2,
};

// total size: 0x8
class clsOOSubMenu {
public:
    ~clsOOSubMenu() {}
    s8* getName() const { return m_opc8Name; }

    s8* m_opc8Name;                     // offset 0x0, size 0x4
    s32 (*m_oFunc)(s32, s32, s32, s32); // offset 0x4
};

// total size: 0x4
class clsOOSubMenuIter {
public:
    clsOOSubMenu* it_; // offset 0x0
};

// total size: 0x14
class clsOOMainMenu {
public:
    ~clsOOMainMenu() {}
    s8* getName() const { return m_opc8Name; }

    s8* m_opc8Name;    // offset 0x0, size 0x4
    s8 m_s8SubMenuNum; // offset 0x4, size 0x1
    vector m_cSubMenu; // offset 0x8, size 0xC
};

// total size: 0x38
class clsOODebugMenu {
public:
    clsOODebugMenu();

    void exec();
    void drawSystemMenu();
    u8 isDrawSubMenuName(const c8* pc8Name);
    void addMainMenu(const c8* pc8Name);
    void addSubMenu(const c8* pc8Name, const c8* pc8Label, const s32 (*pFunc)(s32, s32, s32, s32));
    void removeAll();

    s32 execUrawaza(clsOOSubMenuIter iArg0, s32 s32Arg1, s32 s32Arg2, s32 s32Arg3, s32 s32Arg4)
    {
        return 0;
    }
    void drawDetailOnly() {}
    void drawMainSubMenu() {}

    static const u32 tou32DetailDrawOffX = 33;

    s8 m_s8DrawDefX;             // offset 0x0, size 0x1
    s8 m_s8DrawDefY;             // offset 0x1, size 0x1
    u32 m_u32ChangeTrig;         // offset 0x4, size 0x4
    u32 m_u32ChangeBeta;         // offset 0x8, size 0x4
    u32 m_u32ChangeOneTimeTrig;  // offset 0xC, size 0x4
    u32 m_u32SpeedUpBeta;        // offset 0x10, size 0x4
    s8 m_s8SystemMenuNo;         // offset 0x14, size 0x1
    u8 m_bDisableExecDetail;     // offset 0x15, size 0x1
    s8 m_s8SystemMenuMoveX;      // offset 0x16, size 0x1
    s8 m_s8MainMenuMoveX;        // offset 0x17, size 0x1
    s8 m_s8SubMenuMoveX;         // offset 0x18, size 0x1
    s8 m_s8DetailMoveX;          // offset 0x19, size 0x1
    s8 m_s8DetailMoveY;          // offset 0x1A, size 0x1
    vector m_cMainMenu;          // offset 0x1C, size 0xC
    clsOOSubMenuIter m_iUrawaza; // offset 0x28, size 0x4
    enmDraw m_eDraw;             // offset 0x2C, size 0x4
    u8 m_bUrawaza;               // offset 0x30, size 0x1
    s8 m_s8MainMenuCursorNo;     // offset 0x31, size 0x1
    s8 m_s8SubMenuCursorNo;      // offset 0x32, size 0x1
    s8 m_s8DetailCursorNo;       // offset 0x33, size 0x1
    s8 m_s8DetailNum;            // offset 0x34, size 0x1
    s8 m_s8MainMenuNum;          // offset 0x35, size 0x1
};

#endif // OODEBUGMENU_HPP
