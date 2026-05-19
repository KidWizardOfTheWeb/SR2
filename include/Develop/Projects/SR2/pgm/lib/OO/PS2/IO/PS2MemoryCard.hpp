#ifndef PS2MEMORYCARD_HPP
#define PS2MEMORYCARD_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/IO/OOMemoryCard.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "usr/local/sce/ee/lib/libmc/libmc.h"

enum enmMcState {
    MC_STATE_OK = 0,
    MC_STATE_EXIST = 1,
    MC_STATE_NOEXIST = 2,
    MC_STATE_UNFORMAT = 3,
    MC_STATE_BREAK = 4,
    MC_STATE_EMPTY = 5,
    MC_STATE_CHANGE = 6,
    MC_STATE_NOT_CHANGE = 7,
    MC_STATE_PS1 = 8,
    MC_STATE_PDA = 9,
    MC_STATE_NOCARD = 10,
    MC_STATE_DIR_EXIST = 11,
    MC_STATE_NO_DIR_ENTRY = 12,
    MC_STATE_NO_FILE_ENTRY = 13,
    MC_STATE_NO_EMPTY_DIR = 14,
    MC_STATE_FILE_OPEN_LIMIT = 15,
    MC_STATE_NO_OPEN_FILE = 16,
    MC_STATE_OTHER = 17,
    MC_STATE_ENTRYBREAK = 18,
};

// total size: 0x7C4
class clsPfMemoryCard : public clsOOMemoryCard, public clsSingleton<clsPfMemoryCard> {
public:
    enum enmIconData {
        ICONDATA_ICON_SYS = 0,
        ICONDATA_ICON_01 = 1,
        ICONDATA_ICON_02 = 2,
        ICONDATA_ICON_03 = 3,
        ICONDATA_MAX_NUM = 4,
    };

    // Q2-qualified as clsPfMemoryCard::stcFileData
    struct stcFileData {
        c8 c8Name[32]; // offset 0x0, size 0x20
        void* pvData;  // offset 0x20, size 0x4
        u32 u32Size;   // offset 0x24, size 0x4
    };

    // Q2-qualified as clsPfMemoryCard::stcIconData
    struct stcIconData {
        c8 ac8Dir[22];             // offset 0x0, size 0x16
        u8 u8FileNum;              // offset 0x16, size 0x1
        u8 u8Padding;              // offset 0x17, size 0x1
        stcFileData asFileData[4]; // offset 0x18, size 0xA0
    };

    // total size: 0x4
    class clsLocalMode {
    public:
        static s32 m_tas32LocalMode[8];
        static s32 m_ts32LocalCallCnt;
    };

    virtual ~clsPfMemoryCard();
    virtual u8 getStatus(s32& rs32ResultO);
    virtual u8 isOk(s32 s32Result);
    virtual void setError(s32 s32Result) {}
    virtual void getCurrentDir(c8* pc8DirNameO);
    virtual void checkExistMemoryCard(s32 s32SlotNoI);
    virtual void checkFormatMemoryCard();
    virtual void formatMemoryCard();
    virtual void checkFreeArea(s32 s32Param1, s32 s32Param2);
    virtual void createDir(const c8* opc8DirNameI);
    virtual void changeDir(const c8* opc8DirNameI);
    virtual void deleteDir(const c8* opc8DirNameI);
    virtual void getFileListDir(const c8* opc8DirNameI);
    virtual void checkExistFile(const c8* opc8FileNameI);
    virtual void createFile(const c8* opc8FileNameI);
    virtual void openFile(const c8* opc8FileNameI, enmFileOpenType eFileOpenTypeI);
    virtual void loadFile(void* pvBufferI, s32 s32LengthI);
    virtual void loadFile();
    virtual void saveFile(void* pvBufferI, s32 s32LengthI);
    virtual void saveFile();
    virtual void closeFile();
    virtual void getLengthFile(u32* pu32LengthO);
    virtual void seekFile(s32 s32OffsetI, enmFileSeek eFileSeekI);
    virtual void tellFile(u32* pu32PosO);
    virtual void deleteFile(const c8* opc8FileNameI);
    virtual void unformatMemoryCard();
    virtual void checkExistFileLoaded(const c8* opc8FileNameI);
    virtual void saveAllFile();
    virtual void deleteAllFile();
    virtual s32 checkFileExist(const stcIconData* posIcon,
                               const stcFileData* posFileData,
                               s32 s32FileNum,
                               s32* ps32Cluster,
                               s32* ps32CreateFileNum,
                               bool* pbIconReWrite);

    clsPfMemoryCard(u32 u32UserNumI, u32 u32FileNumI);

    u8 endchkDeleteAllFile(s32 s32Result, s32* ps32Rtn);
    s32 endchkSeekFile(s32 s32Result);
    s32 endchkGetLengthFile(s32 s32Result);
    s32 endchkCloseFile(s32 s32Result);
    u8 endchkSaveAllFile(s32 s32Result, s32* ps32Rtn);
    u8 endchkSaveFile(s32 s32Result, s32* ps32Rtn);
    s32 endchkLoadFile(s32 s32Result);
    s32 endchkCreateFile(s32 s32Result);
    u8 endchkCheckExistFile(s32 s32Result, s32* ps32Rtn);
    s32 endchkGetFileListDir(s32 s32Result);
    s32 endchkDeleteDir(s32 s32Result);
    s32 endchkCreateDir(s32 s32Result);
    u8 endchkCheckFreeArea(s32 s32Result);
    enmMcState endchkMcInfo(s32 s32Result);
    u32 calcNeedArea(u32 u32FileNum,
                     const stcFileData* posFileData,
                     const stcIconData* posIconData,
                     bool bNewDirectory);
    u8 isChange();
    void chkEndAsync();
    void setFileData(const stcFileData* posFileData, u8 u8FileNum);
    void setIconDir(const c8* opc8Dir);
    void setIconDataSize(enmIconData enIconDataNo, u32 u32Size);

    static c8* tpoc8oRootPath; // address: 0x697C68

    s8 m_s8PortNo;                   // offset 0x2C, size 0x1
    s32 m_s32McType;                 // offset 0x30, size 0x4
    s32 m_s32FreeCluster;            // offset 0x34, size 0x4
    s32 m_s32Format;                 // offset 0x38, size 0x4
    enmMcState m_enMcState;          // offset 0x3C, size 0x4
    enmMcState m_enOldMcState;       // offset 0x40, size 0x4
    s32 m_s32MaxNeedSize;            // offset 0x44, size 0x4
    s32 m_s32NeedSize;               // offset 0x48, size 0x4
    s32 m_s32DefiSize;               // offset 0x4C, size 0x4
    s32 m_s32Fd;                     // offset 0x50, size 0x4
    s32 m_s32ReWriteSize;            // offset 0x54, size 0x4
    s32 m_s32GetReWriteSize;         // offset 0x58, size 0x4
    u32* m_pu32FileSize;             // offset 0x5C, size 0x4
    u32* m_pu32SeekEndPos;           // offset 0x60, size 0x4
    u8 m_u8FileDataNum;              // offset 0x64, size 0x1
    stcFileData m_asFileData[18];    // offset 0x68, size 0x2D0
    stcIconData m_sIconData;         // offset 0x338, size 0xB8
    sceMcIconSys m_sIconSys;         // offset 0x3F0, size 0x3C4
    sceMcTblGetDir* m_psDirFileList; // offset 0x7B4, size 0x4
    s32 m_s32FileListNum;            // offset 0x7B8, size 0x4
    s32 m_s32SyncResult;             // offset 0x7BC, size 0x4
    u8 m_bIconReWrite;               // offset 0x7C0, size 0x1
    u8 m_bBreak;                     // offset 0x7C1, size 0x1
};

#endif // PS2MEMORYCARD_HPP
