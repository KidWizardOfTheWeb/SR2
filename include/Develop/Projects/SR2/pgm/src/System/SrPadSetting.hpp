#ifndef SRPADSETTING_HPP
#define SRPADSETTING_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

enum enmPadConnectState {
    PADCONNECT_OK = 0,
    PADCONNECT_NOT_CONNECT = 1,
    PADCONNECT_CRITICAL = 2,
};

// total size: 0x18
class clsSrPadSetting : public clsSingleton<clsSrPadSetting> {
public:
    virtual ~clsSrPadSetting() {}

    clsSrPadSetting();

    enmPadConnectState m_aenConnectReport[4]; // offset 0x4, size 0x10
    u8 m_au8CoonectReportCnt[4];              // offset 0x14, size 0x4
};

#endif // SRPADSETTING_HPP
