#ifndef OOTASK_HPP
#define OOTASK_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOStl.hpp"

// Opaque internal list/map/iterator types used by clsOOTask members

// total size: 0x14
class clsOOList {
    u32 m_au32ListStorage[5]; // offset 0x0, size 0x14
};

// total size: 0x18
class clsOOMap {
    u32 m_au32MapStorage[6]; // offset 0x0, size 0x18
};

// total size: 0x18
class clsOOMMap {
    u32 m_au32MapStorage[6]; // offset 0x0, size 0x18
};

// total size: 0x54
class clsOOTask {
public:
    virtual ~clsOOTask() {}
    virtual void execute() = 0;
    virtual void draw() {}
    virtual void setMode(u32 param_1) { m_u8Mode = (u8)param_1; }
    virtual void addMode() { m_u8Mode++; }
    virtual void addMode(u32 param_1) { m_u8Mode += (u8)param_1; }
    virtual void subMode() { m_u8Mode--; }
    virtual void subMode(u32 param_1) { m_u8Mode -= (u8)param_1; }
    virtual void reinitMode() {}

    u32 getMode() const { return m_u8Mode; }

    clsOOTask(u32 u32Priority, u32 u32ExecFlags, u32 u32EnablePauseFlags);
    clsOOTask(u32 u32Priority, clsOOTask* pcParent, u32 u32ExecFlags, u32 u32EnablePauseFlags);

    u32 m_u32ExecFlags;              // offset 0x4, size 0x4
    u32 m_u32EnablePauseFlags;       // offset 0x8, size 0x4
    u32 m_u32Priority;               // offset 0xC, size 0x4
    u8 m_u8Mode;                     // offset 0x10, size 0x1
    u32 m_u32TaskDepth;              // offset 0x14, size 0x4
    clsOOTask* m_pcParentTask;       // offset 0x18, size 0x4
    clsOOList m_lstChildTask;        // offset 0x1C, size 0x14
    u8 m_bIsDead;                    // offset 0x30, size 0x1
    generic_iterator m_itParentList; // offset 0x34, size 0x4
    generic_iterator m_itMgrList;    // offset 0x38, size 0x4
    clsOOMap m_mapMgrExecListIt;     // offset 0x3C, size 0x18
};

#endif // OOTASK_HPP
