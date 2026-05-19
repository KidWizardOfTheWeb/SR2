#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlash.hpp"

c8* apc8NewObjectName[6] = {"Object", "Number", "String", "Array", "Key", "ModeValue"};

void clsOOFMSprite::setCurFrame(u32 ou32Frame)
{
}

void clsOOFMSprite::frameCtrl(stcPlaceObject2* psPlace2)
{
}

void clsOOFMSprite::sequenceCommand(stcLayer* psLayer, stcSeqTag* psSTag, stcPlaceObject2* psPlace2)
{
}

clsOOFMSprite::~clsOOFMSprite()
{
}

void clsOOFMSprite::copySetupSprite(stcSprite* psSprite, clsOOFMSprite* pcBaseSprite)
{
}

u32 clsOOFMSprite::setupSprite(stcSprite* psSprite)
{
    return 0;
}

u32 clsOOFMSprite::getFrameLabel(const c8* opc8Label)
{
    return 0;
}

void clsOOFMSprite::execAScript(stcDoAction* psAction,
                                u32 u32PcN,
                                u32 ou32ExecNum,
                                stcActConstantPool* psConstantPool)
{
}

void clsOOFMSprite::actCallFunction()
{
}

clsOOFMObject* clsOOFMShapeSymbol::duplicate() const
{
    return 0;
}

clsOOFMShapeSymbol::~clsOOFMShapeSymbol()
{
}

u32 clsOOFMShapeSymbol::setupShape(stcDefineShape1* psDefShape1)
{
    return 0;
}

void clsOOFMShapeSymbol::resetVert()
{
}

void clsOOFMShapeSymbol::replaceOffSet(s32 s32X, s32 s32Y)
{
}

void clsOOFMShapeSymbol::draw(s32 s32X, s32 s32Y)
{
}

void clsOOFMShapeSymbol::flashPlace()
{
}

void clsOOFMShapeSymbol::place2(stcPlaceObject2* psPlaceObj)
{
}

void clsOOFMShapeSymbol::place(stcPlaceObject2* psPlaceObj)
{
}

clsOOFlashMovie::clsOOFlashMovie(clsOOFlashMgr* pcFlashMgr)
{
}

void clsOOFlashMovie::delKeyListener(stcScriptObject* psSObj)
{
}

clsOOFMObject* clsOOFlashMovie::getCharacter(u32 u32CharaID, u32* pu32Idx)
{
    return 0;
}

clsOOFMObject* clsOOFlashMovie::getExportObject(const c8* opc8Name, u32* pu32Idx)
{
    return 0;
}

void clsOOFMSprite::place2(stcPlaceObject2* psPlaceObj)
{
}

void clsOOFMSprite::place(stcPlaceObject2* psPlaceObj)
{
}

void clsOOFMSprite::execJump()
{
}

void clsOOFMSprite::draw(s32 s32X, s32 s32Y)
{
}

void clsOOFMSprite::clearSeqEnd()
{
}

stcPlaceObject2* clsOOFMSprite::getLayerPlaceObjectPtr(s32 s32Layer)
{
    return 0;
}

clsOOFMObject* clsOOFMSprite::duplicate() const
{
    return 0;
}

void clsOOFMSprite::addReplaceObject(u32 u32TargetID,
                                     clsOOFMObject* pcObject,
                                     enmAddRepPlace eIsPlace)
{
}

void clsOOFMSprite::resetVert()
{
}

u32 clsOOFlashMovie::setupFlash(stcFlash* psFlash)
{
    return 0;
}

void clsOOFlashMovie::execKeyListener(s32 s32SpriteNo)
{
}

clsOOFlashMovie::~clsOOFlashMovie()
{
}

u32 clsOOFlashMovie::getValueNumber(u8 u8Type)
{
    return 0;
}

u32 clsOOFlashMovie::setValueNumber(u8 u8Type, u32 u32Num)
{
    return 0;
}

void clsOOFlashMovie::execute(u32 u32SpriteNo)
{
}

void clsOOFlashMovie::draw(u32 u32SpriteNo, stcPlaceObject2* psPlaceObj)
{
}

void clsOOFlashMovie::drawSingle(s32 s32Idx, bool bStop, stcPlaceObject2* psPlaceObj)
{
}

void clsOOFlashMovie::setPlace(s32 s32Idx, stcPlaceObject2* psPlaceObj)
{
}

void clsOOFlashMovie::setDrawZ(s32 s32Idx, f32 f32z)
{
}

stcPlaceObject2* clsOOFlashMovie::getLayerPlaceObjectPtr(s32 s32Idx, s32 s32Layer)
{
    return 0;
}

clsOOFlashPlayer::clsOOFlashPlayer()
{
}

clsOOFlashPlayer::~clsOOFlashPlayer()
{
}

void clsOOFlashPlayer::execute()
{
}

void clsOOFlashPlayer::addNextFrame()
{
}

void clsOOFlashPlayer::draw()
{
}

void clsOOFlashPlayer::setPlayName(const c8* opc8SpriteName)
{
}

void clsOOFlashPlayer::setFrame(u32 ou32Frame)
{
}

void clsOOFlashPlayer::setFrameLabel(const c8* opc8Label)
{
}
