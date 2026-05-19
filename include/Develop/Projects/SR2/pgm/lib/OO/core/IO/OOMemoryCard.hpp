#ifndef OOMEMORYCARD_HPP
#define OOMEMORYCARD_HPP

#include "types.h"

// total size: 0x8
struct stcAccessBuffer {
    void* pvAddr;  // offset 0x0, size 0x4
    s32 s32Length; // offset 0x4, size 0x4
};

enum enmCommand {
    CMD___CHECK_FREE_AREA = 0,
    CMD___CHECK_STATUS = 1,
    CMD___FORMAT = 2,
    CMD___CREATE_DIR = 3,
    CMD___CHANGE_DIR = 4,
    CMD___DELETE_DIR = 5,
    CMD___FILELIST_DIR = 6,
    CMD___GET_CURRENT_DIR = 7,
    CMD___CHECK_EXIST_FILE = 8,
    CMD___CHECK_EXIST_FILE_LOADED = 9,
    CMD___CREATE_FILE = 10,
    CMD___OPEN_FILE = 11,
    CMD___LOAD_FILE = 12,
    CMD___SAVE_FILE = 13,
    CMD___SAVE_ALLFILE = 14,
    CMD___CLOSE_FILE = 15,
    CMD___GET_LENGTH_FILE = 16,
    CMD___SEEK_FILE = 17,
    CMD___TELL_FILE = 18,
    CMD___DELETE_FILE = 19,
    CMD___DELETE_ALLFILE = 20,
    CMD___UNFORMAT = 21,
    CMD___END = 22,
};

// total size: 0x28
class clsOOMemoryCard {
public:
    enum enmFileOpenType {
        OPEN_FILE_TYPE___NONE = 0,
        OPEN_FILE_TYPE___R = 1,
        OPEN_FILE_TYPE___W = 2,
        OPEN_FILE_TYPE___RW = 3,
    };

    enum enmFileSeek {
        FILE_SEEK___SET = 0,
        FILE_SEEK___CURRENT = 1,
        FILE_SEEK___END = 2,
    };

    virtual u8 getStatus(s32& rs32ResultO);
    virtual void getHomeDir(char* param_1) {}
    virtual void getCurrentDir(char* param_1) {}
    s32 getSlotNo() const { return m_s8SlotNo; }
    virtual void checkExistMemoryCard(s32 s32SlotNoI) { m_s8SlotNo = s32SlotNoI; }
    virtual void checkFreeArea(s32 s32Param1, s32 s32Param2) {}
    virtual void createDir(const char* param_1) {}
    virtual void changeDir(const char* param_1) {}
    virtual void deleteDir(const char* param_1) {}
    virtual void getFileListDir(const char* param_1) {}
    virtual void openFile(const char* param_1, enmFileOpenType param_2) {}
    virtual void loadFile() {}
    virtual void saveFile() {}
    virtual void closeFile() { m_bOpened = 0; }
    virtual void unformatMemoryCard() {}

    void setRunning(u32 bI);

    // offset 0x0: vtable pointer (inherited from virtual methods above)
    s32 m_s32Status_ReturnAsync;     // offset 0x4, size 0x4
    s32 m_s32Status_Return;          // offset 0x8, size 0x4
    enmCommand m_eCommand;           // offset 0xC, size 0x4
    u32 m_u32FileSize;               // offset 0x10, size 0x4
    u32 m_u32FilePos;                // offset 0x14, size 0x4
    stcAccessBuffer m_sAccessBuffer; // offset 0x18, size 0x8
    u8 m_u8UserNum;                  // offset 0x20, size 0x1
    u8 m_u8FileNum;                  // offset 0x21, size 0x1
    u8 m_bAutoSeve;                  // offset 0x22, size 0x1
    u8 m_bRunning;                   // offset 0x23, size 0x1
    s8 m_s8SlotNo;                   // offset 0x24, size 0x1
    u8 m_bOpened;                    // offset 0x25, size 0x1
};

#endif // OOMEMORYCARD_HPP
