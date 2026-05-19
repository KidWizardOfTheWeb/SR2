#ifndef SETCAMEDITOR_HPP
#define SETCAMEDITOR_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Camera/SetCamColli.hpp"
#include "types.h"

enum enmSCamEditMode {
    SCAMEDIT_INITMODE = 0,
    SCAMEDIT_LISTMODE = 1,
    SCAMEDIT_EDITMODE = 2,
    SCAMEDIT_ADDMODE1 = 3,
    SCAMEDIT_DELETE_CONFIRM = 4,
};

enum enmListMode {
    LIST_SETCAM = 0,
    LIST_REPLAYCAM = 1,
};

enum enmBaseEditMode {
    BEDIT_NONE = 0,
    BEDIT_ISENABLE = 1,
    BEDIT_POS = 2,
    BEDIT_ROT = 3,
    BEDIT_SCALE = 4,
    BEDIT_FOVY = 5,
    BEDIT_ACTIVE = 6,
    BEDIT_SCAMTYPE = 7,
    BEDIT_PLAYERFLG = 8,
    BEDIT_REPLAY = 9,
    BEDIT_MAX = 10,
};

// total size: 0x50
class clsSetCamEditor : public clsSingleton<clsSetCamEditor> {
public:
    virtual ~clsSetCamEditor() {}

    vector m_vecsSetCamList;          // offset 0x4, size 0xC
    vector m_vecsReplayCamList;       // offset 0x10, size 0xC
    vector* m_pvecsCamList;           // offset 0x1C, size 0x4
    enmSCamEditMode m_eMode;          // offset 0x20, size 0x4
    s8 m_s8CursorX;                   // offset 0x24, size 0x1
    s8 m_s8CursorY;                   // offset 0x25, size 0x1
    s8 m_s8CursorX2;                  // offset 0x26, size 0x1
    s8 m_s8CursorY2;                  // offset 0x27, size 0x1
    u8 m_u8CursorChgFlg;              // offset 0x28, size 0x1
    enmListMode m_eListMode;          // offset 0x2C, size 0x4
    enmBaseEditMode m_eBEditMode;     // offset 0x30, size 0x4
    s32 m_s32ActTypeTop;              // offset 0x34, size 0x4
    s32 m_s32ListCursor;              // offset 0x38, size 0x4
    f32 m_f32ToItemDist;              // offset 0x3C, size 0x4
    enmSCamType m_eNewScamType;       // offset 0x40, size 0x4
    enmSCamShapeType m_eNewShapeType; // offset 0x44, size 0x4
    u8 m_u8NewReplayFlag;             // offset 0x48, size 0x1
    u32 m_u32ListTopIdx;              // offset 0x4C, size 0x4
};

#endif // SETCAMEDITOR_HPP
