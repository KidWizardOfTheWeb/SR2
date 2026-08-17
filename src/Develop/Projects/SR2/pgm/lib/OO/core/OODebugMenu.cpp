#include "Develop/Projects/SR2/pgm/lib/OO/core/OODebugMenu.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Heap.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Peripheral.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Timer.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnDraw2d.hpp"
#include "usr/local/sega/nn/src/Print/nnprint.h"

extern "C" s32 strcmp(const c8*, const c8*);

template <typename T, typename U, typename V>
inline void OOUpLimit(T& value, const U& limit, const V& replacement)
{
    value = limit < value ? replacement : value;
}

template <typename T, typename U, typename V>
inline void OOUpLimitDraw(T& value, const U& limit, const V& replacement)
{
    T oldValue = value;
    V result = replacement;
    value = limit < oldValue ? result : oldValue;
}

namespace {
static clsOOSubMenu tcOOSubMenu;
static clsOOMainMenu tcOOMainMenu;
} // namespace

inline bool clsOOMainMenu::operator==(const clsOOMainMenu& rhs) const
{
    return !strcmp(m_opc8Name, rhs.m_opc8Name);
}

inline void clsOOMainMenu::addSubMenu(const c8* name, const s32 (*func)(s32, s32, s32, s32))
{
    tcOOSubMenu.m_opc8Name = name;
    tcOOSubMenu.m_oFunc = func;
    m_cSubMenu.insert(m_cSubMenu.end_ptr(), 1, tcOOSubMenu);
    ++m_s8SubMenuNum;
}

const u32 clsOODebugMenu::tou32DetailDrawOffX;

void clsOODebugMenu::addMainMenu(const c8* opc8NameI)
{
    tcOOMainMenu.m_opc8Name = opc8NameI;
    m_cMainMenu.insert(m_cMainMenu.end_ptr(), 1, tcOOMainMenu);
    m_s8MainMenuNum++;
}

void clsOODebugMenu::removeAll()
{
    clsOODebugMenu* pcThis = this;
    clsOOMainMenuVector::iterator iMain;

    for (iMain = pcThis->m_cMainMenu.begin(); iMain != pcThis->m_cMainMenu.end(); ++iMain) {
        iMain->m_cSubMenu.clear();
    }

    pcThis->m_cMainMenu.clear();
    pcThis->m_s8MainMenuNum = 0;
    pcThis->m_s8SystemMenuNo = 0;
    pcThis->m_s8SystemMenuMoveX = -0x14;
    pcThis->m_s8MainMenuMoveX = -0x14;
    pcThis->m_s8MainMenuCursorNo = -1;
    pcThis->m_s8SubMenuCursorNo = -1;
    pcThis->m_bUrawaza = 0;
}

void clsOODebugMenu::addSubMenu(const c8* opc8MainMenuNameI,
                                const c8* opc8SubMenuNameI,
                                const s32 (*oFuncI)(s32, s32, s32, s32))
{
    tcOOMainMenu.m_opc8Name = opc8MainMenuNameI;

    clsOOMainMenuVector::iterator iMain =
        std::find(m_cMainMenu.begin(), m_cMainMenu.end(), tcOOMainMenu);

    if (iMain != m_cMainMenu.end()) {
        iMain->addSubMenu(opc8SubMenuNameI, oFuncI);
    }
}

clsOODebugMenu::clsOODebugMenu()
    : m_s8DrawDefX(0), m_s8DrawDefY(0), m_u32ChangeTrig(0), m_u32ChangeBeta(0),
      m_u32ChangeOneTimeTrig(0), m_u32SpeedUpBeta(0x100), m_s8SystemMenuNo(0),
      m_s8MainMenuCursorNo(-1), m_s8MainMenuNum(0)
{
    m_cMainMenu.reserve(10);
}

void clsOODebugMenu::drawSystemMenu()
{
    if (m_s8SystemMenuNo == 0) {
        return;
    }

    clsPfTimer* pcTimer = clsPfTimer::GS();
    clsPfSystem* pcSystem = clsPfSystem::GS();
    s32 s32x = m_s8SystemMenuMoveX + m_s8DrawDefX;
    s32 s32y = m_s8DrawDefY;

    if (m_eDraw != DRAW___ONE_TIME_CHANGE) {
        m_eDraw = DRAW___ING;
        m_s8SystemMenuMoveX += (m_s8SystemMenuMoveX < 0) << 3;
        OOUpLimitDraw<s8, s32, s32>(m_s8SystemMenuMoveX, 0, 0);

        if (m_s8SystemMenuNo <= 2) {
            nnSetPrintColor(0xD0A000FF);
            nnPrint(s32x,
                    s32y++,
                    "CNT: %d:%dHz",
                    pcSystem->getGameCnt(),
                    (s32)pcSystem->getFrameRate());

            nnSetPrintColor(0x00D0D0FF);
            s32 s32RestSize = clsPfMainHeap::GS()->m_s32AllRestSize;
            nnPrint(s32x, s32y++, "HEP: %2.3f MB", (f32)s32RestSize / 1048576.0f);
        }
    } else {
        nnSetPrintColor(0xFFA0A0FF);
        if (pcSystem->m_u32VblankCnt & 0x28) {
            nnPrint(s32y, s32y, "\x02\x02\x02\x02 DEBUG MENU STOP \x02\x02\x02\x02");
        }
        ++s32y;
    }

    u32 u32Cpu = pcTimer->m_s32CpuMicroSec;
    clsOOTimer& rcTimer = static_cast<clsOOTimer&>(*pcTimer);
    u32 u32Gpu = pcTimer->m_s32GpuMicroSec =
        rcTimer.TickDiff2MicroSec(pcTimer->m_s32EndGpuDiffTick);
    f32 f32FrameMSec = 100.0f / (f32)clsPfSystem::GS()->m_s32FrameRateMaxMicroSec;
    u32 u32BgCol = 0x87;
    u32 u32CpuPer = (u32)((f32)u32Cpu * f32FrameMSec);

    nnSetPrintColor(0xFFFFFFFF);
    if (u32CpuPer >= 100) {
        nnSetPrintColor(0xFFA0A0FF);
        u32BgCol = 0x370000FF;
    } else if (u32CpuPer > 90) {
        nnSetPrintColor(0xD08040FF);
    } else if (u32CpuPer > 80) {
        nnSetPrintColor(0xD0A000FF);
    }

    nnPrint(s32x, s32y++, "CPU: %d:%d%%", u32Cpu, u32CpuPer);

    u32 u32GpuPer = (u32)((f32)u32Gpu * f32FrameMSec);
    if (u32GpuPer >= 100) {
        nnSetPrintColor(0xFFA0A0FF);
        if (u32BgCol == 0x370000FF) {
            u32BgCol = 0x28FF;
        } else {
            u32BgCol = 0x3700FF;
        }
    } else if (u32GpuPer > 90) {
        nnSetPrintColor(0xD08040FF);
    } else if (u32GpuPer > 80) {
        nnSetPrintColor(0xD0A000FF);
    } else {
        nnSetPrintColor(0xFFFFFFFF);
    }

    nnPrint(s32x, s32y++, "GPU: %d:%d%%", u32Gpu, u32GpuPer);

    static_cast<clsOODraw2d&>(*clsPfDraw2d::GS())
        .renderDp_Debug((f32)s32x, (f32)m_s8DrawDefY, 16.0f, (f32)(s32y - m_s8DrawDefY), u32BgCol);
}

u8 clsOODebugMenu::isDrawSubMenuName(const c8* opc8NameI)
{
    if (m_s8MainMenuCursorNo == -1 || m_s8SubMenuCursorNo == -1) {
        return 0;
    }
    clsOOMainMenuVector::iterator iMain = m_cMainMenu.begin();
    iMain += m_s8MainMenuCursorNo;
    clsOOSubMenuVector::iterator iSub = iMain.it_->m_cSubMenu.begin();
    iSub += m_s8SubMenuCursorNo;
    return !strcmp(iSub.it_->getName(), opc8NameI);
}

template <typename T, typename U>
inline void OOUpLimit(T& value, const U& limit)
{
    U result = limit;
    T oldValue = value;
    value = result < oldValue ? result : oldValue;
}

template <typename T, typename U>
inline void OODownLimit(T& value, const U& limit)
{
    value = value < limit ? limit : value;
}

template <typename T, typename U, typename V>
inline void OODownLimit(T& value, const U& limit, const V& replacement)
{
    value = value < limit ? replacement : value;
}

template <typename T, typename U, typename V>
inline void OOUpLimitBranch(T& value, const U& limit, const V& replacement)
{
    T& ref = value;
    T oldValue = ref;
    V result = limit < oldValue ? replacement : oldValue;
    ref = result;
}

template <typename T, typename U, typename V>
inline void OODownLimitBranch(T& value, const U& limit, const V& replacement)
{
    T& ref = value;
    T oldValue = ref;
    V result = oldValue < limit ? replacement : oldValue;
    ref = result;
}

inline u32 OOGetIsColor(bool bIsColor, u32 u32Color)
{
    static u32 oau32Col[2] = {0xFFFFFFFF, u32Color};
    return oau32Col[bIsColor];
}

inline void clsOODebugMenu::execMainSubMenu()
{
    clsPfPeripheral* pcPeripheral = clsPfPeripheral::GS();
    if (m_s8SystemMenuNo != 2) {
        return;
    }

    clsOOMainMenuVector::iterator iMain = m_cMainMenu.begin();
    iMain += m_s8MainMenuCursorNo;
    if (m_s8SubMenuCursorNo == -1) {
        if (pcPeripheral->getActiveRep(0x20)) {
            s32 s32Max = m_s8MainMenuNum - 1;
            ++m_s8MainMenuCursorNo;
            OOUpLimit(m_s8MainMenuCursorNo, s32Max, 0);
            m_s8SubMenuMoveX = -(m_s8DrawDefX + 20);
            m_s8SubMenuCursorNo = -1;
        }
        if (pcPeripheral->getActiveRep(0x10)) {
            s32 s32Max = m_s8MainMenuNum - 1;
            --m_s8MainMenuCursorNo;
            OODownLimit(m_s8MainMenuCursorNo, 0, s32Max);
            m_s8SubMenuMoveX = -(m_s8DrawDefX + 20);
            m_s8SubMenuCursorNo = -1;
        }
        if (m_s8MainMenuCursorNo != -1 && pcPeripheral->getActiveRep(0x80) &&
            iMain->m_s8SubMenuNum != 0)
        {
            m_s8SubMenuCursorNo = 0;
            m_s8DetailMoveX = 80;
            m_s8DetailMoveY = 5;
        }
    } else {
        if (pcPeripheral->getActiveRep(0x20)) {
            s32 s32Max = iMain->m_s8SubMenuNum - 1;
            ++m_s8SubMenuCursorNo;
            OOUpLimit(m_s8SubMenuCursorNo, s32Max, 0);
            m_s8DetailMoveX = 80;
        }
        if (pcPeripheral->getActiveRep(0x10)) {
            s32 s32Max = iMain->m_s8SubMenuNum - 1;
            --m_s8SubMenuCursorNo;
            OODownLimit(m_s8SubMenuCursorNo, 0, s32Max);
            m_s8DetailMoveX = 80;
        }
        if (pcPeripheral->getActiveRep(0x40)) {
            if (m_bUrawaza) {
                m_iUrawaza->m_oFunc(-100, -100, 0x7F, 0);
            }
            m_s8SubMenuCursorNo = -1;
        } else if (pcPeripheral->getActiveTrig(0x80)) {
            m_s8SystemMenuNo = 4;
            m_s8DetailCursorNo = 0;
            m_bDisableExecDetail = 0;
        }
    }
}

inline void clsOODebugMenu::drawMainSubMenu()
{
    s32 s32x = m_s8MainMenuMoveX + m_s8DrawDefX;
    m_s8MainMenuMoveX += (m_s8MainMenuMoveX < 0) << 3;
    OOUpLimit(m_s8MainMenuMoveX, 0);

    nnSetPrintColor(0xFF7828FF);
    if (static_cast<clsOOSystem&>(*clsPfSystem::GS()).getTonTon_V()) {
        s32 s32CursorX = s32x;
        s32 s32CursorY = m_s8DrawDefY + 6;
        if (m_s8SubMenuCursorNo == -1) {
            s32CursorY += m_s8MainMenuCursorNo;
        } else {
            s32CursorY += m_s8SubMenuCursorNo;
            s32CursorX += 17;
        }
        nnPrint(s32CursorX, s32CursorY, ">");
    }
    nnPrint(s32x + 1, m_s8DrawDefY + 5, "MAIN MENU");

    nnSetPrintColor(0xFFFFFFFF);
    clsOOMainMenuVector::iterator iMain = m_cMainMenu.begin();
    s32 s32MainNo = 0;
    for (; iMain != m_cMainMenu.end(); ++iMain, ++s32MainNo) {
        nnSetPrintColor(OOGetIsColor(s32MainNo == m_s8MainMenuCursorNo, 0xE01414FF));
        nnPrint(s32x + 1, m_s8DrawDefY + 6 + s32MainNo, "%s", iMain->getName());

        if (s32MainNo == m_s8MainMenuCursorNo) {
            s32 s32SubX = m_s8SubMenuMoveX + m_s8DrawDefX;
            m_s8SubMenuMoveX += (m_s8SubMenuMoveX < 0) << 2;
            OOUpLimit(m_s8SubMenuMoveX, 0);

            clsOOSubMenuVector::iterator iSub = iMain->m_cSubMenu.begin();
            s32 s32SubNo = 0;
            nnSetPrintColor(0x0078FFFF);
            nnPrint(s32SubX + 17, m_s8DrawDefY + 5, "SUB MENU");
            for (; iSub != iMain->m_cSubMenu.end(); ++iSub, ++s32SubNo) {
                const s32 s32SubPrintX = s32SubX + 18;
                nnSetPrintColor(OOGetIsColor(s32SubNo == m_s8SubMenuCursorNo, 0xE01414FF));
                nnPrint(s32SubPrintX, m_s8DrawDefY + 6 + s32SubNo, "%s", iSub->getName());

                if (s32SubNo == m_s8SubMenuCursorNo) {
                    m_s8DetailMoveX -= (m_s8DetailMoveX > tou32DetailDrawOffX) << 3;
                    OODownLimit(m_s8DetailMoveX, tou32DetailDrawOffX);
                    nnSetPrintColor(0x96FF1EFF);
                    nnPrint(m_s8DrawDefX + m_s8DetailMoveX,
                            m_s8DrawDefY + m_s8DetailMoveY,
                            "%s",
                            iSub->getName());
                    nnSetPrintColor(0xFFFFFFFF);
                    execUrawaza(iSub,
                                m_s8DrawDefX + m_s8DetailMoveX,
                                m_s8DrawDefY + m_s8DetailMoveY + 1,
                                -1,
                                0);
                }
            }
        }
    }
}

inline void clsOODebugMenu::drawDetailOnly()
{
    clsPfPeripheral* pcPeripheral = clsPfPeripheral::GS();

    clsOOMainMenuVector::iterator iMain = m_cMainMenu.begin();
    iMain += m_s8MainMenuCursorNo;
    clsOOSubMenuVector::iterator iSub = iMain->m_cSubMenu.begin();
    iSub += m_s8SubMenuCursorNo;

    nnSetPrintColor(0xFF7828FF);
    if (static_cast<clsOOSystem&>(*clsPfSystem::GS()).getTonTon_V()) {
        nnPrint(m_s8DrawDefX, m_s8DrawDefY + 3 + m_s8DetailCursorNo, ">");
    }

    if (m_s8DetailMoveX > 0) {
        m_s8DetailMoveX -= 8;
    }
    if (m_s8DetailMoveX < 0) {
        m_s8DetailMoveX += 8;
        OOUpLimit(m_s8DetailMoveX, 0);
    }

    m_s8DetailMoveY -= ((u8)((m_s8DetailMoveY < 5) ^ 1)) << 1;
    OODownLimit(m_s8DetailMoveY, 5);

    nnPrint(m_s8DrawDefX + 1, m_s8DrawDefY + 2, "DETAIL MENU");
    nnSetPrintColor(0x96FF1EFF);
    nnPrint(m_s8DrawDefX + m_s8DetailMoveX + 1,
            m_s8DrawDefY + m_s8DetailMoveY,
            "%s > %s",
            iMain->getName(),
            iSub->getName());
    nnSetPrintColor(0xFFFFFFFF);

    f32 f32Speed = 1.0f;
    static u16 tu16Cnt = 0;
    if (pcPeripheral->getActiveBetaBool(m_u32SpeedUpBeta)) {
        f32Speed = 10.0f;
        if (!pcPeripheral->getActiveRel()) {
            u16 u16Cnt = tu16Cnt + 1;
            tu16Cnt = u16Cnt;
            if (u16Cnt >= 180) {
                f32Speed = 100.0f;
            }
        } else {
            tu16Cnt = 0;
        }
    } else {
        tu16Cnt = 0;
    }

    m_s8DetailNum = execUrawaza(iSub,
                                m_s8DrawDefX + m_s8DetailMoveX,
                                m_s8DrawDefY + m_s8DetailMoveY + 1,
                                m_s8DetailCursorNo - 1,
                                (s32)f32Speed);

    pcPeripheral = clsPfPeripheral::GS();
    if (!m_bDisableExecDetail && m_s8DetailMoveX == 0) {
        if (m_s8DetailCursorNo == -1 && pcPeripheral->getActiveTrig(0xC0)) {
            m_s8SystemMenuNo = 0;
            m_s8MainMenuCursorNo = -1;
            if (m_bUrawaza) {
                m_iUrawaza->m_oFunc(-100, -100, 0x7F, 0);
            }
            return;
        }

        if (m_s8DetailCursorNo == 0) {
            clsOOMainMenuVector::iterator iMoveMain = m_cMainMenu.begin();
            if (pcPeripheral->getActiveRep(0x80)) {
                m_s8DetailMoveX = (m_s8DrawDefX + 16) * 8;
                iMoveMain += m_s8MainMenuCursorNo;
                clsOOSubMenuVector::iterator iMoveSub = iMoveMain->m_cSubMenu.begin();
                ++m_s8SubMenuCursorNo;
                iMoveSub += m_s8SubMenuCursorNo;
                if (iMoveSub == iMoveMain->m_cSubMenu.end()) {
                    u32 u32NoSubMenu;
                    do {
                        ++m_s8MainMenuCursorNo;
                        ++iMoveMain;
                        if (iMoveMain == m_cMainMenu.end()) {
                            m_s8MainMenuCursorNo = 0;
                            iMoveMain = m_cMainMenu.begin();
                        }
                        m_s8SubMenuCursorNo = 0;
                        iMoveSub = iMoveMain->m_cSubMenu.begin();
                        u32NoSubMenu = ((u32)0 < (u32)iMoveMain->m_s8SubMenuNum) ^ 1;
                    } while (u32NoSubMenu);
                }
            } else if (pcPeripheral->getActiveRep(0x40)) {
                m_s8DetailMoveX = (m_s8DrawDefX + 16) * -8;
                iMoveMain += m_s8MainMenuCursorNo;
                clsOOSubMenuVector::iterator iMoveSub = iMoveMain->m_cSubMenu.begin();
                --m_s8SubMenuCursorNo;
                iMoveSub += m_s8SubMenuCursorNo;
                if (m_s8SubMenuCursorNo < 0) {
                    u32 u32NoSubMenu;
                    do {
                        --m_s8MainMenuCursorNo;
                        --iMoveMain;
                        if (m_s8MainMenuCursorNo < 0) {
                            m_s8MainMenuCursorNo = m_s8MainMenuNum - 1;
                            iMoveMain = m_cMainMenu.end() - 1;
                        }
                        m_s8SubMenuCursorNo = iMoveMain->m_s8SubMenuNum - 1;
                        iMoveSub = iMoveMain->m_cSubMenu.end() - 1;
                        u32NoSubMenu = ((u32)0 < (u32)iMoveMain->m_s8SubMenuNum) ^ 1;
                    } while (u32NoSubMenu);
                }
            }
        }

        if (pcPeripheral->getActiveRep(0x20)) {
            ++m_s8DetailCursorNo;
            OOUpLimit(m_s8DetailCursorNo, m_s8DetailNum, 0);
        }
        if (pcPeripheral->getActiveRep(0x10)) {
            --m_s8DetailCursorNo;
            OODownLimit(m_s8DetailCursorNo, 0, m_s8DetailNum);
        }
    }
}

void clsOODebugMenu::exec()
{
    u32 u32ChangeBeta = m_u32ChangeBeta;
    clsPfPeripheral* pcPeripheral = clsPfPeripheral::GS();
    if (u32ChangeBeta != 0 && !(pcPeripheral->m_sActivePeripheral.m_u32Beta & u32ChangeBeta)) {
        return;
    }

    if (m_u32ChangeOneTimeTrig != 0) {
        u32 u32Check = m_u32ChangeOneTimeTrig & pcPeripheral->m_sActivePeripheral.m_u32Rep;
        u32 bIsSame = m_u32ChangeOneTimeTrig == u32Check;
        if (bIsSame) {
            if (m_eDraw == DRAW___ING) {
                m_eDraw = DRAW___ONE_TIME_CHANGE;
            } else if (m_eDraw == DRAW___ONE_TIME_CHANGE) {
                m_eDraw = DRAW___ING;
            }
        }
    }

    if (m_eDraw == DRAW___ONE_TIME_CHANGE) {
        drawSystemMenu();
        return;
    }

    m_eDraw = DRAW___NON;
    if (m_u32ChangeTrig != 0) {
        if (!(pcPeripheral->m_sActivePeripheral.m_u32Beta & m_u32ChangeTrig)) {
            if (m_s8SystemMenuNo != 0) {
                m_s8SystemMenuNo = 0;
                return;
            }
            m_s8SystemMenuNo = 1;
        }
    }
    if (m_s8SystemMenuNo < 3) {
        pcPeripheral = clsPfPeripheral::GS();
        if (m_s8MainMenuCursorNo == -1) {
            if (pcPeripheral->m_sActivePeripheral.m_u32Trig & 0x80) {
                ++m_s8SystemMenuNo;
                OOUpLimitBranch(m_s8SystemMenuNo, 2, 1);
                if (m_s8SystemMenuNo == 1) {
                    m_s8SystemMenuMoveX = -20;
                }
                m_s8MainMenuMoveX = -20;
                m_s8MainMenuCursorNo = -1;
                m_s8SubMenuCursorNo = -1;
                m_bUrawaza = 0;
            }
            if (pcPeripheral->m_sActivePeripheral.m_u32Trig & 0x40) {
                --m_s8SystemMenuNo;
                OODownLimitBranch(m_s8SystemMenuNo, 1, 2);
                if (m_s8SystemMenuNo == 2) {
                    m_s8SystemMenuMoveX = -20;
                }
                m_s8MainMenuMoveX = -20;
                m_s8MainMenuCursorNo = -1;
                m_s8SubMenuCursorNo = -1;
                m_bUrawaza = 0;
            }
        }

        execMainSubMenu();
        drawSystemMenu();
        if (m_s8SystemMenuNo == 2) {
            drawMainSubMenu();
        }
    } else {
        drawSystemMenu();
        drawDetailOnly();
    }

    nnSetPrintColor(0xFFFFFFFF);
}
