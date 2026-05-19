#ifndef PS2NNCAMERAMGR_HPP
#define PS2NNCAMERAMGR_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2CamCtrl.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Main2.hpp"
#include "types.h"

// total size: 0x14
class clsPfCameraMgr : public clsSingleton<clsPfCameraMgr>, private clsOOCameraMgr {
public:
    clsPfCameraMgr() {}
    virtual ~clsPfCameraMgr() {}

    clsPfCamera* getCamera(u32 u32Param1) const
    {
        return static_cast<clsPfCamera**>(m_vecCamera._data)[u32Param1];
    }

    void updateAllCamera();

    vector m_vecCamera; // offset 0x8, size 0xC
};

#endif // PS2NNCAMERAMGR_HPP
