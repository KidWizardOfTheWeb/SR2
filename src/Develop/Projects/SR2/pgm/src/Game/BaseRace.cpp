#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "Develop/Projects/SR2/pgm/src/Config/nspStartCam.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/CharaData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GearData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GearControlData.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_CRI/PS2CriFileMgr.hpp"
#include "usr/local/sce/ee/lib/libkernl/kprintf2.h"
#include "macros.h"

namespace {
typedef oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> > CharaSetArg;
typedef oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> > GearSetArg;
typedef std::vector<const clsGameMgr::stcSendAdv*, std::allocator<const clsGameMgr::stcSendAdv*> >
    SendAdvVector;
typedef std::pair<const u32, u32> MotionMapPair;
typedef oostd::clsOOMap<u32, u32, std::less<u32>, oostd::clsOOStlAllocator<MotionMapPair> >
    MotionMap;

static f32 tof32StartCamFrame[4] = {120.0f, 120.0f, 140.0f, 140.0f};
static f32 tof32StartCamFrame4[4] = {120.0f, 120.0f, 180.0f, 180.0f};
static clsBackLineEffectTask::stcParam oasGCtrlLineParam = {2,
                                                            1,
                                                            0xFF,
                                                            0xFF,
                                                            37,
                                                            16,
                                                            0xFFFFFFFF,
                                                            0.0f,
                                                            1.0f,
                                                            {0.15f, 0.15f, 0.0f, 0.0f},
                                                            {0.0f, 0.05f, 0.0f, 0.0f}};
} // namespace

c8* clsBaseRace_Task::m_toac8StageName_Debug[17];

clsBaseRace_Task::clsBaseRace_Task(s32 s32Param1,
                                   s32 s32Param2,
                                   s32 s32Param3,
                                   s32 s32Param4,
                                   s32 s32Param5,
                                   const stcSendAdv* pParam6,
                                   void** pvParam7,
                                   enmMode,
                                   s32 s32Param9)
    : clsTask(0, 0)
{
}

clsBaseRace_Task::~clsBaseRace_Task()
{
}

void clsBaseRace_Task::LoadStageData(s32 s32Param1)
{
}

void clsBaseRace_Task::init()
{
}

u8 clsBaseRace_Task::packMap()
{
    return 0;
}

void clsBaseRace_Task::addReadChara(
    oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcParam1)
{
}

void clsBaseRace_Task::addReadGear(
    oostd::clsOOSet<u32, std::less<u32>, oostd::clsOOStlAllocator<u32> >* pcParam1, u32* pu32Param2)
{
}

void clsBaseRace_Task::addReadCharaMotion(
    std::vector<const clsGameMgr::stcSendAdv*, std::allocator<const clsGameMgr::stcSendAdv*> >*
        pcParam1)
{
}

void clsBaseRace_Task::requestReadChara()
{
    CharaSetArg setCharaModel(std::less<u32>(), *clsOOMainHeap::getInstance());
    CharaSetArg::iterator itChrMdl;
    u32 u32i;
    u32 u32IdxTmp;
    clsPfFileMgr* pcPfFileMgr;
    clsPack* pcPack;

    m_u32CharaLoadNum = 0;
    memset(m_au32LoadedCharaIndex, 0, sizeof(m_au32LoadedCharaIndex));
    memset(nspGame::asAttackData, 0, sizeof(stcAttackModel) * nspChara::MAX_CHARA_NUM);

    u32i = 0;
    do {
        u32IdxTmp = (nspChara::getCharaModelType(m_sSendAdv[u32i].u8GearCtrlNo) << 16) |
                    m_sSendAdv[u32i].u5CharaId;
        if (setCharaModel.find(u32IdxTmp) == setCharaModel.end()) {
            setCharaModel.insert(u32IdxTmp);
        }
        ++u32i;
    } while (u32i < static_cast<u32>(m_s32PlayerNum));

    addReadChara(&setCharaModel);
    m_u32LoadCnt = 0;

    if (setCharaModel.empty()) {
        SUPER_ASSERT(0x36520122, "BaseRace.cpp", 0x286, "キャラなし？？ありえません。\n");
    }

    pcPfFileMgr = clsPfFileMgr::GS();
    itChrMdl = setCharaModel.begin();
    pcPack = clsPack::GS();

    do {
        u32IdxTmp = *itChrMdl;
        pcPfFileMgr->requestRead(
            pcPack->getFileName(
                nspPackId::CHARA_0, u32IdxTmp & 0xffff, u32IdxTmp >> 16, m_s32UserNum),
            &m_pavCharaPackBuffer[m_u32CharaLoadNum],
            0x12,
            0);
        m_au32LoadedCharaIndex[m_u32CharaLoadNum] = u32IdxTmp;
        ++m_u32CharaLoadNum;
        ++itChrMdl;
    } while (itChrMdl != setCharaModel.end());
}

void clsBaseRace_Task::requestReadGear()
{
    GearSetArg setGearCtrlNo(std::less<u32>(), *clsOOMainHeap::getInstance());
    u16 u16CtrlNoTmp;
    u32 u32i;
    GearSetArg::iterator it;
    u32 u32FindKey;
    u32 u32InsertKey;
    clsPfFileMgr* pcPfFileMgr;
    clsPack* pcPack;

    memset(&nspGame::sGearModelInfo, 0, sizeof(nspGame::sGearModelInfo));
    m_u32GearLoadCnt = 0;

    u32i = 0;
    do {
        u16CtrlNoTmp = nspGear::getGearCtrlNoForModel(m_sSendAdv[u32i].u8GearCtrlNo,
                                                      m_sSendAdv[u32i].u5CharaId);
        if (u16CtrlNoTmp != 0xffff) {
            u32FindKey = u16CtrlNoTmp;
            if (setGearCtrlNo.find(u32FindKey) == setGearCtrlNo.end()) {
                u32InsertKey = u16CtrlNoTmp;
                setGearCtrlNo.insert(u32InsertKey);
            }
        } else if (nspGame::sGearModelInfo.u32DataNum == 0) {
            nspGame::sGearModelInfo.sGearModels[0].u16CtrlNo = u16CtrlNoTmp;
            ++nspGame::sGearModelInfo.u32DataNum;
            m_u32GearLoadCnt = 1;
        }
        ++u32i;
    } while (u32i < static_cast<u32>(m_s32PlayerNum));

    addReadGear(&setGearCtrlNo, &m_u32GearLoadCnt);

    pcPfFileMgr = clsPfFileMgr::GS();
    it = setGearCtrlNo.begin();
    pcPack = clsPack::GS();

    if (setGearCtrlNo.empty() && nspGame::sGearModelInfo.u32DataNum == 0) {
        SUPER_ASSERT(0x32566581, "BaseRace.cpp", 0x2c7, "ギアなし？？ありえません\n");
    }

    while (it != setGearCtrlNo.end()) {
        if (nspGame::sGearModelInfo.u32DataNum >= 8) {
            SUPER_ASSERT(0x36952032, "BaseRace.cpp", 0x2c9, "データ多すぎです。\n");
        }

        _GearModels& rsGearModels =
            nspGame::sGearModelInfo.sGearModels[nspGame::sGearModelInfo.u32DataNum];
        u32 u32GearCtrlNo = *it;
        pcPfFileMgr->requestRead(pcPack->getFileName(nspPackId::GEAR_10, u32GearCtrlNo, 0, 0),
                                 &rsGearModels.pvGearPackBuffer,
                                 0x12,
                                 0);
        rsGearModels.u16CtrlNo = u32GearCtrlNo;
        ++nspGame::sGearModelInfo.u32DataNum;
        ++it;
    }

    setGearCtrlNo.clear();
}

void clsBaseRace_Task::requestReadCharaMotion()
{

    SendAdvVector vecSendAdv;
    vecSendAdv.reserve(0x20);

    m_u8MotLoadNum = 0;
    memset(m_apsUnionMotionTable, 0, sizeof(m_apsUnionMotionTable));
    memset(m_apsCharaMotionTable, 0, sizeof(m_apsCharaMotionTable));

    u32 u32i = 0;
    do {
        vecSendAdv.push_back(&m_sSendAdv[u32i]);
        ++u32i;
    } while (u32i < static_cast<u32>(m_s32PlayerNum));

    addReadCharaMotion(&vecSendAdv);

    MotionMap mapUniMot(*clsOOMainHeap::getInstance());
    MotionMap mapChrMot(*clsOOMainHeap::getInstance());

    SendAdvVector::iterator itVec = vecSendAdv.begin();

    if (vecSendAdv.size() == 0) {
        SUPER_ASSERT(0x36521024, "BaseRace.cpp", 0x308, "ロード用データが１つもない？？\n");
    }

    u32 u32ChrListKey_Chr;
    u32 u32ValCode;
    u32 u32j;
    u32 u32PlayerNoTmp = 0;
    stcCtrlData* psGearCtrlData;
    enmMotionType eMotNo;
    enmGear eBaseGearNo;
    do {
        psGearCtrlData = &nspGear::oasCtrlData[(*itVec)->u8GearCtrlNo];
        u32ValCode = u32PlayerNoTmp < static_cast<u32>(m_s32UserNum);
        u32ChrListKey_Chr = (*itVec)->u5CharaId << 16;

        eBaseGearNo = psGearCtrlData->aeGear[0];
        if (eBaseGearNo >= GEAR_SKATE_START && eBaseGearNo <= GEAR_SKATE_END) {
            if (mapUniMot.find(MOTION_DUMMY_SKATE_WALK) == mapUniMot.end()) {
                mapUniMot.insert(MotionMap::value_type(MOTION_DUMMY_SKATE_WALK, u32ValCode));
            }

            if (mapChrMot.find(u32ChrListKey_Chr | MOTION_DUMMY_SKATE_WALK) == mapChrMot.end()) {
                mapChrMot.insert(
                    MotionMap::value_type(u32ChrListKey_Chr | MOTION_DUMMY_SKATE_WALK, u32ValCode));
            }
        } else {
            if (mapUniMot.find(MOTION_WALK) == mapUniMot.end()) {
                mapUniMot.insert(MotionMap::value_type(MOTION_WALK, u32ValCode));
            }

            if (mapChrMot.find(u32ChrListKey_Chr) == mapChrMot.end()) {
                mapChrMot.insert(MotionMap::value_type(u32ChrListKey_Chr, u32ValCode));
            }
        }

        for (u32j = 0; u32j < 4; ++u32j) {
            eBaseGearNo = psGearCtrlData->aeGear[u32j];
            if (eBaseGearNo == GEAR_NON) {
                break;
            }

            switch (eBaseGearNo) {
            case GEAR_BOARD_START ... GEAR_BOARD_END:
                eMotNo = MOTION_BOARD;
                break;
            case GEAR_BIKE_START ... GEAR_BIKE_END:
                eMotNo = MOTION_BIKE;
                break;
            case GEAR_AIRRIDE_START ... GEAR_AIRRIDE_END:
                eMotNo = MOTION_AIRRIDE;
                break;
            case GEAR_SURFING_START ... GEAR_SURFING_END:
                eMotNo = MOTION_SURFING;
                break;
            case GEAR_WHEEL_START ... GEAR_WHEEL_END:
                eMotNo = MOTION_WHEEL;
                break;
            case GEAR_SKATE_START ... GEAR_SKATE_END:
                eMotNo = MOTION_SKATE;
                break;
            case GEAR_GRIND_START ... GEAR_GRIND_END:
                eMotNo = MOTION_BOARD;
                break;
            case GEAR_SPECIAL_START ... GEAR_EFFECT_PARTS_END:
                eMotNo = MOTION_EMPTY;
                break;
            case GEAR_EMPTY_START ... GEAR_EMPTY_END:
                eMotNo = MOTION_BOARD;
                break;
            }

            if (eMotNo != MOTION_EMPTY) {
                if (mapUniMot.find(eMotNo) == mapUniMot.end()) {
                    mapUniMot.insert(MotionMap::value_type(eMotNo, u32ValCode));
                }

                if (mapChrMot.find(u32ChrListKey_Chr | eMotNo) == mapChrMot.end()) {
                    mapChrMot.insert(MotionMap::value_type(u32ChrListKey_Chr | eMotNo, u32ValCode));
                }
            }
        }

        ++itVec;
        ++u32PlayerNoTmp;
    } while (itVec != vecSendAdv.end());

    clsPfFileMgr* pcPfFileMgr = clsPfFileMgr::GS();
    clsPack* pcPack = clsPack::GS();
    c8* pc8FileName;
    MotionMap::iterator it = mapUniMot.begin();

    do {
        m_appvMotLoadBufAddr[m_u8MotLoadNum] =
            reinterpret_cast<void**>(&m_apsUnionMotionTable[it->first]);
        pc8FileName = pcPack->getFileName(nspPackId::___DUMMY__MOTION,
                                          it->first | (it->second << 16),
                                          reinterpret_cast<s32>("uni"),
                                          0);
        scePrintf("Motion Load Request - %s\n", pc8FileName);
        pcPfFileMgr->requestRead(pc8FileName, m_appvMotLoadBufAddr[m_u8MotLoadNum], 0x12, 0);
        ++m_u8MotLoadNum;
        ++it;
    } while (it != mapUniMot.end());

    it = mapChrMot.begin();
    do {
        u32 u32CharaNo = it->first >> 16;
        u32 u32MotNo = it->first & 0xffff;
        m_appvMotLoadBufAddr[m_u8MotLoadNum] =
            reinterpret_cast<void**>(&m_apsCharaMotionTable[u32CharaNo][u32MotNo]);
        pc8FileName =
            pcPack->getFileName(nspPackId::___DUMMY__MOTION,
                                (it->second << 16) | u32MotNo,
                                reinterpret_cast<s32>(nspChara::oasCharaCode3[u32CharaNo]),
                                0);
        scePrintf("Motion Load Request - %s\n", pc8FileName);
        pcPfFileMgr->requestRead(pc8FileName, m_appvMotLoadBufAddr[m_u8MotLoadNum], 0x12, 0);
        ++m_u8MotLoadNum;
        ++it;
    } while (it != mapChrMot.end());
}

void clsBaseRace_Task::requestReadEtc()
{
}

u8 clsBaseRace_Task::packMotion()
{
    return 0;
}

u8 clsBaseRace_Task::setSeData()
{
    return 0;
}

u8 clsBaseRace_Task::packEtc()
{
    return 0;
}

void clsBaseRace_Task::start()
{
}

void clsBaseRace_Task::settingPlayer()
{
}

void clsBaseRace_Task::restart()
{
}

u8 clsBaseRace_Task::countDown()
{
    return 0;
}

void clsBaseRace_Task::setRaceTime(u32 u32Param1,
                                   s32 s32Param2,
                                   s32 s32Param3,
                                   s32 s32Param4,
                                   s32 s32Param5,
                                   s32 s32Param6,
                                   s32 s32Param7)
{
}

void clsBaseRace_Task::setSendAdv(const stcSendAdv* pParam1)
{
}

s8 clsBaseRace_Task::chkPadConnect(u32* pParam1)
{
    return 0;
}

void clsBaseRace_Task::setPauseScreen(s32 s32Param1, enmPadConnectDraw)
{
}

void clsBaseRace_Task::setPauseReslutScreen(s32 s32Param1)
{
}

void clsBaseRace_Task::setBestTime()
{
}

void clsBaseRace_Task::checkPause(s32 s32Param1)
{
}

void clsBaseRace_Task::checkPauseResult(s32 s32Param1)
{
}

void clsBaseRace_Task::copyCharaMotionTable(nspChara::enmCharaType, nspGame::stcMotionTable* (&)[8])
{
}

u8 clsBaseRace_Task::checkGoalPlayer()
{
    return 0;
}

void clsBaseRace_Task::updateRanking()
{
}

void clsBaseRace_Task::setGoalComPlayer()
{
}

void clsBaseRace_Task::setComPlannedRank()
{
}

void clsBaseRace_Task::setStartCamMotion(enmCamMotionNo,
                                         const NNS_VECTORFAST* pParam2,
                                         const NNS_QUATERNION* pParam3)
{
}

void clsBaseRace_Task::initStartCamMotion()
{
}

void clsBaseRace_Task::endStartCamMotion()
{
}

void clsBaseRace_Task::setPlayerStartCamData(u32 u32Param1)
{
}

u8 clsBaseRace_Task::updateStartCamMotion()
{
    return 0;
}

void clsBaseRace_Task::execGoal()
{
}

void clsBaseRace_Task::endDemoSetting()
{
}

void clsBaseRace_Task::setFreeRaceUnlock()
{
}

void clsBaseRace_Task::setStoryUnlock()
{
}

void clsBaseRace_Task::execute()
{
}

void clsBaseRace_Task::selectedPauseMenu_RET___RESTART()
{
}

void clsBaseRace_Task::selectedPauseMenu_RET___EXIT()
{
}

void clsBaseRace_Task::selectedPauseMenu_RET___CANCEL()
{
}
