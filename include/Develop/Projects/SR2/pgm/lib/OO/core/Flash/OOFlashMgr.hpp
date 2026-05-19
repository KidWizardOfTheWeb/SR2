#ifndef OOFLASHMGR_HPP
#define OOFLASHMGR_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlash.hpp"

// total size: 0x18
class clsOOFlashMgr {
public:
    clsOOFlashMgr();
    virtual ~clsOOFlashMgr() {}

    clsOOFMObject* getExportObject(const c8* opc8ObjName);

    vector m_vecpcFlashData;                        // offset 0x4, size 0xC
    clsOOFMShapeSymbol* (*m_pfCreateShapeSymbol)(); // offset 0x10, size 0x4
    clsOOFMSprite* (*m_pfCreateSprite)();           // offset 0x14, size 0x4
};

#endif // OOFLASHMGR_HPP
