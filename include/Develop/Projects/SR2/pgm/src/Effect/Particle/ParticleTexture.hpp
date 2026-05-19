#ifndef PARTICLETEXTURE_HPP
#define PARTICLETEXTURE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

struct _NNS_TEXLIST;

// total size: 0x60
class clsParticleTexture : public clsTask {
public:
    ~clsParticleTexture();

    virtual void draw();

    u8 m_bBurn;                 // offset 0x54, size 0x1
    u8 m_u8Type;                // offset 0x55, size 0x1
    u8 m_u8ZMode;               // offset 0x56, size 0x1
    u8 m_u8Blend;               // offset 0x57, size 0x1
    u8 m_u8DrawType;            // offset 0x58, size 0x1
    u16 m_u16Texture;           // offset 0x5A, size 0x2
    _NNS_TEXLIST* m_opsTexList; // offset 0x5C, size 0x4

    static f32 m_tsInvertViewMtx[4][4];

    static s32 calcTaskPriority(bool bBurn, u8 u8Blend, u8 u8Zmode, u8 u8DrawType, u16 u16TexNo);
};

#endif // PARTICLETEXTURE_HPP
