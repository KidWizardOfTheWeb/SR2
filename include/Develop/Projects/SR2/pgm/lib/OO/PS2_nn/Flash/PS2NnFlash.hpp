#ifndef PS2NNFLASH_HPP
#define PS2NNFLASH_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlash.hpp"

// total size: 0x40
class clsPfFMShapeSymbol : public clsOOFMShapeSymbol {
public:
    virtual ~clsPfFMShapeSymbol() {}
    virtual void draw(s32 s32X, s32 s32Y);
};

// total size: 0xF0
class clsPfFMSprite : public clsOOFMSprite {
public:
    virtual ~clsPfFMSprite() {}

    virtual void BlendModeAdd() {}
    virtual void BlendModeNormal() {}

    virtual void startMaskDraw();
    virtual void clearMaskDraw(u8 u8Param1);
    virtual void startClipDraw();
    virtual void endClipDraw();
};

#endif // PS2NNFLASH_HPP
