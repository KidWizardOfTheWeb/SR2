#ifndef OOFLASH_HPP
#define OOFLASH_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OODraw2d.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/CRI/OOCri.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlashParse.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptObject.hpp"

// Forward declarations
class clsOOFlashMovie;
class clsOOFlashMgr;
class clsOOTexture;
struct stcSprite;
struct stcActConstantPool;
struct stcDoAction;
struct stcFlash;
struct stcScriptObject;
struct stcActDefineFunction;
struct stcActDefineFunction2;
struct stcPushData;

// total size: 0x20
class clsOOFlashPlayer {
public:
    clsOOFlashMovie* m_pcFlashMovie; // offset 0x4, size 0x4
    c8* m_opc8SpriteName;            // offset 0x8, size 0x4
    s32 m_s32PlayNo;                 // offset 0xC, size 0x4
    u32 m_u32CharaId;                // offset 0x10, size 0x4
    u8 m_u8SkipPlace;                // offset 0x14, size 0x1
    u8 m_u8Stop;                     // offset 0x15, size 0x1
    s32 m_s32OffsetX;                // offset 0x18, size 0x4
    s32 m_s32OffsetY;                // offset 0x1C, size 0x4

    clsOOFlashPlayer();
    virtual ~clsOOFlashPlayer();
    virtual void execute();
    virtual void draw();
    virtual void addNextFrame();
    virtual void getPos(s32& s32X, s32& s32Y)
    {
        s32X = m_s32OffsetX;
        s32Y = m_s32OffsetY;
    }

    void setFrameLabel(const c8* opc8Label);
    void setFrame(u32 ou32Frame);
    void setPlayName(const c8* opc8SpriteName);
    void setSeqMode(u16 u16SeqMode) const {}
    u32 getRtnCode(u32 u32Param1) { return 0; }
    u16 getSeqMode() const { return 0; }
};

// total size: 0x8
struct stcTag {
    u32 u32TagID; // offset 0x0, size 0x4
    void* pvData; // offset 0x4, size 0x4
};

// total size: 0xC
struct stcSeqTag {
    u32 u32Frame; // offset 0x0, size 0x4
    stcTag sTag;  // offset 0x4, size 0x8
};

// total size: 0x8
struct stcScriptVar {
    c8* pc8Name;         // offset 0x0, size 0x4
    stcPushData* psData; // offset 0x4, size 0x4
};

// total size: 0x1C
struct stcScriptFunc {
    stcSprite* pcSprite;                // offset 0x0, size 0x4
    stcDoAction* psActRec;              // offset 0x4, size 0x4
    stcActDefineFunction* psDefFunc;    // offset 0x8, size 0x4
    stcActDefineFunction2* psDefFunc2;  // offset 0xC, size 0x4
    u32 u32CodeN;                       // offset 0x10, size 0x4
    c8* pc8Name;                        // offset 0x14, size 0x4
    stcActConstantPool* psConstantPool; // offset 0x18, size 0x4
};

// total size: 0x8
class uniPushData {
public:
    union {
        c8* pc8String;
        f32 f32Float;
        u8 u8RegisterNum;
        u8 u8Bool;
        f64 f64Double;
        u32 u32Integer;
        u8 u8Constant;
        u16 u16Constant;
        void* pvObject;
    };
};

// total size: 0x10
struct stcPushData {
    u8 u8Type;         // offset 0x0, size 0x1
    uniPushData uData; // offset 0x8, size 0x8
};

// total size: 0x4
struct stcPlaceHead {
    u16 u16HasBits; // offset 0x0, size 0x2
    u16 u16Depth;   // offset 0x2, size 0x2
};

// total size: 0xC
struct stcPlaceObject2 {
    u16 u16CharacterId;                // offset 0x0, size 0x2
    u16 u16ClipDepth;                  // offset 0x2, size 0x2
    f32 (*psPlaceMtx)[3][2];           // offset 0x4, size 0x4
    stcCXFormWithAlpha* psCXWithAlpha; // offset 0x8, size 0x4
};

// total size: 0x10
struct stcPlaceObject3 {
    u16 u16CharacterId;                // offset 0x0, size 0x2
    u16 u16ClipDepth;                  // offset 0x2, size 0x2
    f32 (*psPlaceMtx)[3][2];           // offset 0x4, size 0x4
    stcCXFormWithAlpha* psCXWithAlpha; // offset 0x8, size 0x4
    u8 u8BlendMode;                    // offset 0xC, size 0x1
    u8 au8Padding[3];                  // offset 0xD, size 0x3
};

// total size: 0x14
class clsOOFMObject {
public:
    virtual ~clsOOFMObject();
    clsOOFlashMovie* m_pcParent; // offset 0x4, size 0x4
    s32 m_s32CharID;             // offset 0x8, size 0x4
    u8 m_u8IsDraw;               // offset 0xC, size 0x1
    f32 m_f32DrawZ;              // offset 0x10, size 0x4
    virtual void getClipNum();
    virtual void resetVert();
    virtual void getPos(s32& param_1, s32& param_2);
    virtual void BlendModeAdd();
    virtual void BlendModeSub();
    virtual void BlendModeNormal();
    virtual void startMaskDraw();
    virtual void clearMaskDraw(u8 param_1);
    virtual void startClipDraw();
    virtual void endClipDraw();
    virtual bool isEnd() { return false; }
    virtual u32 getRtnCode(u32 param_1) { return 0; }
    virtual void clearSeqEnd() {}
};

// total size: 0x20
class clsOOFMSequence : public clsOOFMObject {
public:
    clsOOFMSequence()
    {
        m_pcParent = 0;
        m_s32CharID = 0;
        m_u8IsDraw = 0;
        m_f32DrawZ = -3.0f;
        m_u32CurFrame = 0;
        m_u32MaxFrame = 0;
        m_u8FlashReserve = 0;
    }
    virtual ~clsOOFMSequence() {}

    u32 m_u32CurFrame;   // offset 0x14, size 0x4
    u32 m_u32MaxFrame;   // offset 0x18, size 0x4
    u8 m_u8FlashReserve; // offset 0x1C, size 0x1
    virtual void flashPlace();
    virtual clsOOFMObject* getPlaceObjectPtr();
    virtual void setPlaceObjectPtr(stcPlaceObject2* param_1);
    virtual void addFrame();
    virtual void setCurFrame(u32 param_1);
    virtual bool isEnd();
    virtual u32 getRtnCode(u32 param_1);
    virtual void clearSeqEnd();
};

// total size: 0xF0
class clsOOFMSprite : public clsOOFMSequence {
public:
    enum enmAddRepPlace {
        ADDREP_SKIP_PLACE = 0,
        ADDREP_CALL_PLACE = 1,
    };

    // Nested type (mangled as clsOOFMSprite::stcLayer)
    // total size: 0x20
    struct stcLayer {
        u32 u32DepthNo;          // offset 0x0, size 0x4
        vector vecsSeqTags;      // offset 0x4, size 0xC
        vector* pvecsSeqTags;    // offset 0x10, size 0x4
        clsOOFMObject* pcObject; // offset 0x14, size 0x4
        u32 u32RemoveID;         // offset 0x18, size 0x4
        u32 u32RemoveFrame;      // offset 0x1C, size 0x4
    };

    // total size: 0x8
    struct stcReplaceNode {
        u32 u32TargetID;             // offset 0x0, size 0x4
        clsOOFMObject* pcReplaceObj; // offset 0x4, size 0x4
    };

    stcSprite* m_psSprite;                // offset 0x20, size 0x4
    vector m_vecLayer;                    // offset 0x24, size 0xC
    vector m_vecsReplaceTbl;              // offset 0x30, size 0xC
    stcPlaceObject2* m_psPlaceObj2;       // offset 0x3C, size 0x4
    stcPlaceObject2* m_psUpPlaceObj2;     // offset 0x40, size 0x4
    u8 m_u8Placed;                        // offset 0x44, size 0x1
    u16 m_u16SeqMode;                     // offset 0x46, size 0x2
    vector m_vecsStack;                   // offset 0x48, size 0xC
    stcActConstantPool* m_psConstantPool; // offset 0x54, size 0x4
    stcPushData m_asRegister[5];          // offset 0x58, size 0x50
    stcDoAction* m_psLastPlayAction;      // offset 0xA8, size 0x4
    vector m_vecpsFrameLabel;             // offset 0xAC, size 0xC
    u32* m_pu32CurIdx;                    // offset 0xB8, size 0x4
    u32* m_pu32JmpIdx;                    // offset 0xBC, size 0x4
    u8 m_u8IsJump;                        // offset 0xC0, size 0x1
    u32 m_au32RtnCode[4];                 // offset 0xC4, size 0x10
    s32 m_s32NextSpriteNo;                // offset 0xD4, size 0x4
    u32 m_u32NextSpriteFrame;             // offset 0xD8, size 0x4
    c8* m_pc8NextSpriteLabel;             // offset 0xDC, size 0x4
    s32 m_s32PlaceX;                      // offset 0xE0, size 0x4
    s32 m_s32PlaceY;                      // offset 0xE4, size 0x4
    u8 m_u8BlendMode;                     // offset 0xE8, size 0x1

    // --- vtable overrides ---
    virtual ~clsOOFMSprite();
    virtual void place(stcPlaceObject2* psPlaceObj);
    virtual void place2(stcPlaceObject2* psPlaceObj);
    virtual void draw(s32 s32X, s32 s32Y);
    virtual clsOOFMObject* duplicate() const;
    virtual void flashPlace();
    virtual clsOOFMObject* getPlaceObjectPtr();
    virtual stcPlaceObject2* getLayerPlaceObjectPtr(s32 s32Layer);
    virtual void setPlaceObjectPtr(stcPlaceObject2* param_1);
    virtual void addFrame();
    virtual void setCurFrame(u32 ou32Frame);
    virtual bool isEnd();
    virtual u32 getRtnCode(u32 param_1);
    virtual void clearSeqEnd();
    virtual void resetVert();
    virtual void getPos(s32& param_1, s32& param_2);
    virtual void frameCtrl(stcPlaceObject2* psPlace2);
    virtual void BlendModeAdd();
    virtual void BlendModeSub();
    virtual void BlendModeNormal();
    virtual void startMaskDraw();
    virtual void clearMaskDraw(u8 param_1);
    virtual void startClipDraw();
    virtual void endClipDraw();

    // --- non-weak, non-virtual methods ---
    void sequenceCommand(stcLayer* psLayer, stcSeqTag* psSTag, stcPlaceObject2* psPlace2);
    void copySetupSprite(stcSprite* psSprite, clsOOFMSprite* pcBaseSprite);
    u32 setupSprite(stcSprite* psSprite);
    u32 getFrameLabel(const c8* opc8Label);
    void execAScript(stcDoAction* psAction,
                     u32 u32PcN,
                     u32 ou32ExecNum,
                     stcActConstantPool* psConstantPool);
    void actCallFunction();
    void execJump();
    void addReplaceObject(u32 u32TargetID, clsOOFMObject* pcObject, enmAddRepPlace eIsPlace);
    void getPushNumber(stcPushData* param_1);

    clsOOFMSprite();
};

typedef clsOOFMSprite::enmAddRepPlace enmAddRepPlace;

// total size: 0x40
class clsOOFMShapeSymbol : public clsOOFMObject {
public:
    stcDefineShape1* m_psBase;               // offset 0x14, size 0x4
    stcBitsLossLess2* m_psBLL2;              // offset 0x18, size 0x4
    u32 m_u32TotalVNum;                      // offset 0x1C, size 0x4
    stcShapeVert m_sShapeVert;               // offset 0x20, size 0x10
    stcPlaceObject2* m_psPlaceObj2;          // offset 0x30, size 0x4
    stcPlaceObject2* m_psUpPlaceObj2;        // offset 0x34, size 0x4
    u8 m_u8Placed;                           // offset 0x38, size 0x1
    u8 m_u8Clip;                             // offset 0x39, size 0x1
    stcCXFormWithAlpha* m_psCXFormWithAlpha; // offset 0x3C, size 0x4

    virtual ~clsOOFMShapeSymbol();
    virtual void place(stcPlaceObject2* psPlaceObj);
    virtual void place2(stcPlaceObject2* psPlaceObj);
    virtual void draw(s32 s32X, s32 s32Y);
    virtual clsOOFMObject* duplicate() const;
    virtual void flashPlace();
    virtual clsOOFMObject* getPlaceObjectPtr() { return (clsOOFMObject*)m_psPlaceObj2; }
    virtual void setPlaceObjectPtr(stcPlaceObject2* param_1) { m_psPlaceObj2 = param_1; }
    virtual void addFrame() {}
    virtual void setCurFrame(u32 param_1) {}
    virtual bool isEnd() { return false; }
    virtual void getClipNum() {}
    virtual void resetVert();

    u32 setupShape(stcDefineShape1* psDefShape1);
    void replaceOffSet(s32 s32X, s32 s32Y);
};

class clsOOFlashMovie {
public:
    struct stcKeyListenerSet {
        clsOOFMSprite* pcSprite; // offset 0x0, size 0x4
        stcDoAction* psActRec;   // offset 0x4, size 0x4
        stcScriptObject* psSObj; // offset 0x8, size 0x4
    };

    clsOOFlashMgr* m_pcFlashMgr;                   // offset 0x4, size 0x4
    stcFlash* m_psFlash;                           // offset 0x8, size 0x4
    vector m_vecpcSprite;                          // offset 0xC, size 0xC
    vector m_vecpcImport;                          // offset 0x18, size 0xC
    vector m_vecpcDefineShape;                     // offset 0x24, size 0xC
    stcScriptObject m_sKeyObj;                     // offset 0x30, size 0x20
    vector m_vecsKeyListener;                      // offset 0x50, size 0xC
    clsOOTexture* m_pcTexList;                     // offset 0x5C, size 0x4
    clsOODraw2d* m_pcDraw2d;                       // offset 0x60, size 0x4
    vector m_vecScriptObject;                      // offset 0x64, size 0xC
    vector m_vecScriptFunction;                    // offset 0x70, size 0xC
    u8 m_u8SetSkip;                                // offset 0x7C, size 0x1
    clsOOCri* m_pcCri;                             // offset 0x80, size 0x4
    u32 (*m_pfCallBackFunc)(void*, u32, u32, u32); // offset 0x84, size 0x4
    void* m_pvCallBackParam;                       // offset 0x88, size 0x4

    clsOOFlashMovie(clsOOFlashMgr* pcFlashMgr);
    virtual ~clsOOFlashMovie();
    u32 setupFlash(stcFlash* psFlash);
    void execKeyListener(s32 s32SpriteNo);
    void setDrawZ(s32 s32Idx, f32 f32z);
    void setPlace(s32 s32Idx, stcPlaceObject2* psPlaceObj);
    void drawSingle(s32 s32Idx, bool bStop, stcPlaceObject2* psPlaceObj);
    void draw(u32 u32SpriteNo, stcPlaceObject2* psPlaceObj);
    void execute(u32 u32SpriteNo);
    stcPlaceObject2* getLayerPlaceObjectPtr(s32 s32Idx, s32 s32Layer);
    u32 setValueNumber(u8 u8Type, u32 u32Num);
    u32 getValueNumber(u8 u8Type);
    clsOOFMObject* getExportObject(const c8* opc8Name, u32* pu32Idx);
    clsOOFMObject* getCharacter(u32 u32CharaID, u32* pu32Idx);
    void delKeyListener(stcScriptObject* psSObj);
    u32 getSpriteNum() const { return m_vecpcSprite._size; }
    void setTexList(clsOOTexture* pcTexList) { m_pcTexList = pcTexList; }
};

#endif // OOFLASH_HPP
