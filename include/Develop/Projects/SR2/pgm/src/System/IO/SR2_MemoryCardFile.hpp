#ifndef SR2_MEMORYCARDFILE_HPP
#define SR2_MEMORYCARDFILE_HPP

#include "types.h"

namespace nspMemoryCardFile {
void SetIconImage(u32 u32Param1, void* pvParam2);
void* GetIconImage(u32 u32Param1);

extern void* m_tpvIconImage[3];
} // namespace nspMemoryCardFile

// total size: 0x38
class clsBaseMemoryCardFile {
public:
    enum enmDataType {
        DATA_TYPE___GAMES = 0,
        DATA_TYPE___GHOST = 1,
        DATA_TYPE___BANNER = 2,
        DATA_TYPE___MAX = 3,
    };

    virtual ~clsBaseMemoryCardFile() {}
    virtual void setFileName(s32 param_1, s32 param_2) = 0;
    virtual void setFileName(const c8* param_1) {}
    virtual void setSaveData(void* pvSaveData);
    virtual void setLoadDataBuff(u32 param_1, void* param_2) {}
    virtual void createSaveData() {}
    virtual s32 getFileSize() const = 0;
    virtual s32 getFileSdkBlock() const;
    virtual s32 getFileUserBlock() const;
    virtual s32 getMaxFileNum() const = 0;
    virtual s32 getFileLumpNum() const = 0;
    virtual enmDataType getDataType() const = 0;
    virtual void* getSaveData() { return m_pvDataBuff; }
    virtual void* getLoadDataBuff(u32 param_1) { return m_apvLoadDataBuff[param_1]; }

    static const s8* otac8DataTypeName_Debug[3]; // address: 0x006544A0

    s8 m_ac8FileName[32];       // offset 0x4, size 0x20
    void* m_pvDataBuff;         // offset 0x24, size 0x4
    void* m_apvLoadDataBuff[3]; // offset 0x28, size 0xC
    s8 m_s8StageNo;             // offset 0x34, size 0x1
};

typedef clsBaseMemoryCardFile::enmDataType enmDataType;

// total size: 0x38
class clsMemoryCardFile_Ghost : public clsBaseMemoryCardFile {
public:
    clsMemoryCardFile_Ghost();
    virtual ~clsMemoryCardFile_Ghost() {}
    virtual void setFileName(s32 s32FileNoI, s32 s32StageNoMmI);
    virtual s32 getFileSize() const { return 0; }
    virtual s32 getMaxFileNum() const { return 0; }
    virtual s32 getFileLumpNum() const { return 0; }
    virtual enmDataType getDataType() const { return DATA_TYPE___GHOST; }
};

// total size: 0x38
class clsMemoryCardFile_Games : public clsBaseMemoryCardFile {
public:
    clsMemoryCardFile_Games();
    virtual ~clsMemoryCardFile_Games() {}
    virtual void setFileName(s32 s32FileNoI, s32 s32Param2);
    virtual s32 getFileSize() const { return 0; }
    virtual s32 getMaxFileNum() const { return 0; }
    virtual s32 getFileLumpNum() const { return 0; }
    virtual enmDataType getDataType() const { return DATA_TYPE___GAMES; }
};

// total size: 0x38
class clsMemoryCardFile_Banner : public clsBaseMemoryCardFile {
public:
    clsMemoryCardFile_Banner();
    virtual ~clsMemoryCardFile_Banner() {}
    virtual void setFileName(s32 param_1, s32 param_2) {}
    virtual s32 getFileSize() const { return 0; }
    virtual s32 getMaxFileNum() const { return 0; }
    virtual s32 getFileLumpNum() const { return 0; }
    virtual enmDataType getDataType() const { return DATA_TYPE___BANNER; }
    virtual void setSaveData(void* pvSaveData) {}
    virtual void setLoadDataBuff(u32 param_1, void* param_2) {}
};

#endif // SR2_MEMORYCARDFILE_HPP
