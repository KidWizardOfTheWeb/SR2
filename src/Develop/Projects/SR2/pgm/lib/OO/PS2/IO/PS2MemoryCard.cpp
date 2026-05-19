#include "Develop/Projects/SR2/pgm/lib/OO/PS2/IO/PS2MemoryCard.hpp"

c8* tpoc8oDirCurrent;
c8* tpoc8oDirCurrentP;
c8* tpoc8oDirPathChara;
c8* tpoc8oDirTopName_Eu;
c8* tpoc8oDirTopName_Jp;
c8* tpoc8oDirTopName_Kr;
c8* tpoc8oDirTopName_Us;
c8* tpoc8oIconSysName;

c8* clsPfMemoryCard::tpoc8oRootPath;
s32 clsPfMemoryCard::clsLocalMode::m_tas32LocalMode[8];
s32 clsPfMemoryCard::clsLocalMode::m_ts32LocalCallCnt;

void clsPfMemoryCard::setIconDataSize(enmIconData enIconDataNo, u32 u32Size)
{
}

void clsPfMemoryCard::setIconDir(const c8* opc8Dir)
{
}

clsPfMemoryCard::clsPfMemoryCard(u32 u32UserNumI, u32 u32FileNumI)
{
}

clsPfMemoryCard::~clsPfMemoryCard()
{
}

void clsPfMemoryCard::setFileData(const stcFileData* posFileData, u8 u8FileNum)
{
}

void clsPfMemoryCard::chkEndAsync()
{
}

u8 clsPfMemoryCard::getStatus(s32& rs32ResultO)
{
    return 0;
}

u8 clsPfMemoryCard::isChange()
{
    return 0;
}

enmMcState clsPfMemoryCard::endchkMcInfo(s32 s32Result)
{
    return MC_STATE_OK;
}

u32 clsPfMemoryCard::calcNeedArea(u32 u32FileNum,
                                  const stcFileData* posFileData,
                                  const stcIconData* posIconData,
                                  bool bNewDirectory)
{
    return 0;
}

void clsPfMemoryCard::checkExistMemoryCard(s32 s32SlotNoI)
{
}

void clsPfMemoryCard::checkFormatMemoryCard()
{
}

void clsPfMemoryCard::formatMemoryCard()
{
}

void clsPfMemoryCard::checkFreeArea(s32 s32Param1, s32 s32Param2)
{
}

u8 clsPfMemoryCard::endchkCheckFreeArea(s32 s32Result)
{
    return 0;
}

s32 clsPfMemoryCard::checkFileExist(const stcIconData* posIcon,
                                    const stcFileData* posFileData,
                                    s32 s32FileNum,
                                    s32* ps32Cluster,
                                    s32* ps32CreateFileNum,
                                    bool* pbIconReWrite)
{
    return 0;
}

void clsPfMemoryCard::getCurrentDir(c8* pc8DirNameO)
{
}

void clsPfMemoryCard::createDir(const c8* opc8DirNameI)
{
}

s32 clsPfMemoryCard::endchkCreateDir(s32 s32Result)
{
    return 0;
}

void clsPfMemoryCard::changeDir(const c8* opc8DirNameI)
{
}

void clsPfMemoryCard::deleteDir(const c8* opc8DirNameI)
{
}

s32 clsPfMemoryCard::endchkDeleteDir(s32 s32Result)
{
    return 0;
}

void clsPfMemoryCard::getFileListDir(const c8* opc8DirNameI)
{
}

s32 clsPfMemoryCard::endchkGetFileListDir(s32 s32Result)
{
    return 0;
}

void clsPfMemoryCard::checkExistFile(const c8* opc8FileNameI)
{
}

u8 clsPfMemoryCard::endchkCheckExistFile(s32 s32Result, s32* ps32Rtn)
{
    return 0;
}

void clsPfMemoryCard::checkExistFileLoaded(const c8* pcParam1)
{
}

void clsPfMemoryCard::createFile(const c8* opc8FileNameI)
{
}

s32 clsPfMemoryCard::endchkCreateFile(s32 s32Result)
{
    return 0;
}

void clsPfMemoryCard::openFile(const c8* opc8FileNameI, enmFileOpenType eFileOpenTypeI)
{
}

void clsPfMemoryCard::loadFile(void* pvBufferI, s32 s32LengthI)
{
}

void clsPfMemoryCard::loadFile()
{
}

s32 clsPfMemoryCard::endchkLoadFile(s32 s32Result)
{
    return 0;
}

void clsPfMemoryCard::saveFile(void* pvBufferI, s32 s32LengthI)
{
}

void clsPfMemoryCard::saveFile()
{
}

u8 clsPfMemoryCard::endchkSaveFile(s32 s32Result, s32* ps32Rtn)
{
    return 0;
}

void clsPfMemoryCard::saveAllFile()
{
}

u8 clsPfMemoryCard::endchkSaveAllFile(s32 s32Result, s32* ps32Rtn)
{
    return 0;
}

void clsPfMemoryCard::closeFile()
{
}

s32 clsPfMemoryCard::endchkCloseFile(s32 s32Result)
{
    return 0;
}

void clsPfMemoryCard::getLengthFile(u32* pu32LengthO)
{
}

s32 clsPfMemoryCard::endchkGetLengthFile(s32 s32Result)
{
    return 0;
}

void clsPfMemoryCard::seekFile(s32 s32OffsetI, enmFileSeek eFileSeekI)
{
}

s32 clsPfMemoryCard::endchkSeekFile(s32 s32Result)
{
    return 0;
}

void clsPfMemoryCard::tellFile(u32* pu32PosO)
{
}

void clsPfMemoryCard::deleteFile(const c8* opc8FileNameI)
{
}

void clsPfMemoryCard::deleteAllFile()
{
}

u8 clsPfMemoryCard::endchkDeleteAllFile(s32 s32Result, s32* ps32Rtn)
{
    return 0;
}

void clsPfMemoryCard::unformatMemoryCard()
{
}

u8 clsPfMemoryCard::isOk(s32 s32Result)
{
    return 0;
}
