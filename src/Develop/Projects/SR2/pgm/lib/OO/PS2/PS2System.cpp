#include "usr/local/sce/ee/gcc/ee/lib/libc/memcpy.h"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "usr/local/sce/ee/lib/libcdvd/cdvd000.h"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCameraMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/System/ScissorRect.hpp"
#include "usr/local/sega/px/src/pxgeom.h"
#include "usr/local/sega/px/src/pxcontext.h"
#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Timer.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnGraphics.hpp"
#include "usr/local/cri/mwlib/ee/lib/cri_libs.h"
#include "usr/local/sce/ee/lib/eekernel.h"
#include "usr/local/sce/ee/lib/libgraph.h"
#include "usr/local/sce/ee/lib/libscf/libscf.h"

clsPfSystem::clsPfSystem()
{
    m_eVoiceLanguage = LANGUAGE___ENGLISH;
    switch (sceScfGetLanguage()) {
    case SCE_JAPANESE_LANGUAGE:
        m_eMessageLanguage = LANGUAGE___JAPANESE;
        m_eVoiceLanguage = LANGUAGE___JAPANESE;
        break;
    case SCE_ENGLISH_LANGUAGE:
        m_eMessageLanguage = LANGUAGE___ENGLISH;
        break;
    case SCE_FRENCH_LANGUAGE:
        m_eMessageLanguage = LANGUAGE___FRENCH;
        break;
    case SCE_SPANISH_LANGUAGE:
        m_eMessageLanguage = LANGUAGE___SPANISH;
        break;
    case SCE_GERMAN_LANGUAGE:
        m_eMessageLanguage = LANGUAGE___GERMAN;
        break;
    case SCE_ITALIAN_LANGUAGE:
        m_eMessageLanguage = LANGUAGE___ITALIAN;
        break;
    case SCE_DUTCH_LANGUAGE:
        m_eMessageLanguage = LANGUAGE___DUTCH;
        break;
    case SCE_PORTUGUESE_LANGUAGE:
        m_eMessageLanguage = LANGUAGE___PORTUGUESE;
        break;
    }
}

s32 clsPfSystem::tVBlanking_CallBack(s32 s32CaIn)
{
    GS()->m_u32VblankCnt++;
    ExitHandler();
    return s32CaIn;
}

inline void clsPfSystem::VWait()
{
    clsPfTimer& rcTimer = clsPfTimer::RS();
    clsPfSystem& rcSystem = *GS();

    rcTimer.endCpu();

    while (sceGsSyncPath(0, 0) != 0) {
    }

    ADXM_WaitVsync();

    rcTimer.beginCpu();

    volatile u32 u32VblankNum = rcSystem.m_u8VblankNum;
    while (rcSystem.m_u32VblankCnt - rcSystem.m_u32VblankCntOld < u32VblankNum) {
    }

    m_u32VblankCntOld = m_u32VblankCnt;
    clsPfGraphics::GS()->updateFrameBuffer();
    m_u32GameCnt += m_bUnPause;
}

inline void clsPfSystem::setViewPort(u32 u32I)
{
    PXS_SCREENPARAM sprm;
    u64 u64Scissor = static_cast<u64>(m_apsScissorRect[u32I]->u32OffsetX) |
                     (static_cast<u64>(m_apsScissorRect[u32I]->u32Right) << 16) |
                     (static_cast<u64>(m_apsScissorRect[u32I]->u32OffsetY) << 32) |
                     (static_cast<u64>(m_apsScissorRect[u32I]->u32Bottom) << 48);

    PXGetScreenParam(&sprm);
    sprm.width = m_apsViewRect[u32I]->f32Width;
    sprm.height = m_apsViewRect[u32I]->f32Height;
    sprm.cx = m_apsViewRect[u32I]->f32OffsetX;
    sprm.cy = m_apsViewRect[u32I]->f32OffsetY;
    PXPutScreenParam(&sprm);

    clsPfCamera* pcCamera = clsPfCameraMgr::GS()->getCamera(u32I);
    nnSetProjection(&pcCamera->m_sPrjMtx, NNE_PROJECTION_TYPE_PERSPECTIVE);

    memcpy(&pxg_context[0].scissor, &u64Scissor, sizeof(u64Scissor));
    pxg_context[0].scissoraddr = pxg_scissor_addr[0];
    memcpy(&pxg_context[1].scissor, &u64Scissor, sizeof(u64Scissor));
    pxg_context[1].scissoraddr = pxg_scissor_addr[1];
    PXPutContext(PXE_CTX1);
    PXPutContext(PXE_CTX2);
}

namespace {

// RECONSTRUCTED: helper name.
inline u8 convertFromBcd(u8 u8Bcd)
{
    return (u8Bcd >> 4) * 10 + (u8Bcd & 0x0F);
}

} // namespace

void clsPfSystem::getNowDateTime(stcDateTime* psNow)
{
    sceCdCLOCK sClock;

    if (sceCdReadClock(&sClock) == 0) {
        sClock.stat = 5;
        sClock.second = 7;
        sClock.minute = 6;
        sClock.hour = 5;
        sClock.day = 4;
        sClock.month = 3;
        sClock.year = 0;
    }

    sceScfGetLocalTimefromRTC(&sClock);

    psNow->u16Year = convertFromBcd(sClock.year);
    psNow->u8Month = convertFromBcd(sClock.month);
    psNow->u8Day = convertFromBcd(sClock.day);
    psNow->u8Hour = convertFromBcd(sClock.hour);
    psNow->u8Min = convertFromBcd(sClock.minute);
    psNow->u8Sec = convertFromBcd(sClock.second);
}
