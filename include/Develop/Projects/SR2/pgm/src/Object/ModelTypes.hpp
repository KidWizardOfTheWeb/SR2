#ifndef MODELTYPES_HPP
#define MODELTYPES_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Morph/nnmorph.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

void utilSafetyTexRelease(_NNS_TEXLIST* psTexList);

// total size: 0x8
class clsModelType_OB_TX {
public:
    clsModelType_OB_TX() : m_psObject(0), m_psTexList(0) {}

    ~clsModelType_OB_TX() { utilSafetyTexRelease(m_psTexList); }

    NNS_OBJECT* m_psObject;    // offset 0x0, size 0x4
    _NNS_TEXLIST* m_psTexList; // offset 0x4, size 0x4
};

// total size: 0x4
class clsModelType_OB {
public:
    clsModelType_OB() : m_psObject(0) {}

    ~clsModelType_OB() {}

    NNS_OBJECT* m_psObject; // offset 0x0, size 0x4
};

// total size: 0x10
class clsModelType_OB_TX_MO {
public:
    clsModelType_OB_TX_MO() : m_psObject(0), m_psTexList(0), m_psMotion(0), m_f32MotionFrame(0.0f)
    {
    }

    ~clsModelType_OB_TX_MO() { utilSafetyTexRelease(m_psTexList); }

    NNS_OBJECT* m_psObject;    // offset 0x0, size 0x4
    _NNS_TEXLIST* m_psTexList; // offset 0x4, size 0x4
    NNS_MOTION* m_psMotion;    // offset 0x8, size 0x4
    f32 m_f32MotionFrame;      // offset 0xC, size 0x4
};

// total size: 0x20
class clsModelType_OB_TX_MO_MA {
public:
    clsModelType_OB_TX_MO_MA()
        : m_psObject(0), m_psTexList(0), m_psMotion(0), m_f32MotionFrame(0.0f), m_psMatMotObj(0),
          m_psMatMotion(0), m_psMatStatus(0), m_f32MatMotionFrame(0.0f)
    {
    }

    ~clsModelType_OB_TX_MO_MA() { utilSafetyTexRelease(m_psTexList); }

    NNS_OBJECT* m_psObject;    // offset 0x0, size 0x4
    _NNS_TEXLIST* m_psTexList; // offset 0x4, size 0x4
    NNS_MOTION* m_psMotion;    // offset 0x8, size 0x4
    f32 m_f32MotionFrame;      // offset 0xC, size 0x4
    NNS_OBJECT* m_psMatMotObj; // offset 0x10, size 0x4
    NNS_MOTION* m_psMatMotion; // offset 0x14, size 0x4
    u32* m_psMatStatus;        // offset 0x18, size 0x4
    f32 m_f32MatMotionFrame;   // offset 0x1C, size 0x4
};

// total size: 0x34
class clsModelType_OB_TX_MO_MA_MF {
public:
    clsModelType_OB_TX_MO_MA_MF()
        : m_psObject(0), m_psTexList(0), m_psMotion(0), m_f32MotionFrame(0.0f), m_psMatMotObj(0),
          m_psMatMotion(0), m_psMatStatus(0), m_f32MatMotionFrame(0.0f), m_psMorphObj(0),
          m_psMorphTargetList(0), m_psMorphMotion(0), m_pf32MorphWaitPallet(0),
          m_f32MorphMotionFrame(0.0f)
    {
    }

    ~clsModelType_OB_TX_MO_MA_MF() { utilSafetyTexRelease(m_psTexList); }

    NNS_OBJECT* m_psObject;                   // offset 0x0, size 0x4
    _NNS_TEXLIST* m_psTexList;                // offset 0x4, size 0x4
    NNS_MOTION* m_psMotion;                   // offset 0x8, size 0x4
    f32 m_f32MotionFrame;                     // offset 0xC, size 0x4
    NNS_OBJECT* m_psMatMotObj;                // offset 0x10, size 0x4
    NNS_MOTION* m_psMatMotion;                // offset 0x14, size 0x4
    u32* m_psMatStatus;                       // offset 0x18, size 0x4
    f32 m_f32MatMotionFrame;                  // offset 0x1C, size 0x4
    NNS_OBJECT* m_psMorphObj;                 // offset 0x20, size 0x4
    NNS_MORPHTARGETLIST* m_psMorphTargetList; // offset 0x24, size 0x4
    NNS_MOTION* m_psMorphMotion;              // offset 0x28, size 0x4
    f32* m_pf32MorphWaitPallet;               // offset 0x2C, size 0x4
    f32 m_f32MorphMotionFrame;                // offset 0x30, size 0x4
};

#endif // MODELTYPES_HPP
