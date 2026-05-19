#ifndef OOFLASHPARSE_HPP
#define OOFLASHPARSE_HPP

#include "types.h"

// ---------------------------------------------------------------------------
// Flash file header types
// ---------------------------------------------------------------------------

// total size: 0x10
struct stcFgbRect {
    s32 s32XMin; // offset 0x0, size 0x4
    s32 s32XMax; // offset 0x4, size 0x4
    s32 s32YMin; // offset 0x8, size 0x4
    s32 s32YMax; // offset 0xC, size 0x4
};

// total size: 0x14
struct stcTagInfo {
    u32 u32DefNum;      // offset 0x0, size 0x4
    u32 u32ExportNum;   // offset 0x4, size 0x4
    u32 u32ImportNum;   // offset 0x8, size 0x4
    u32 u32SpriteNum;   // offset 0xC, size 0x4
    u32 u32SequenceNum; // offset 0x10, size 0x4
};

// total size: 0x34
struct stcFgbHeader {
    u8 u8IsLittleEndian;    // offset 0x0, size 0x1
    u8 u8FlashVersion;      // offset 0x1, size 0x1
    u8 u8FgbVersion;        // offset 0x2, size 0x1
    u8 u8Padding;           // offset 0x3, size 0x1
    u32 u32Reserved;        // offset 0x4, size 0x4
    stcFgbRect sScreenRect; // offset 0x8, size 0x10
    u32 u32FrameRate;       // offset 0x18, size 0x4
    u32 u32FrameCnt;        // offset 0x1C, size 0x4
    stcTagInfo sTagNumInfo; // offset 0x20, size 0x14
};

// ---------------------------------------------------------------------------
// Flash shape rendering types
// ---------------------------------------------------------------------------

// total size: 0x8
struct stcGradRecord {
    u32 u32Ratio; // offset 0x0, size 0x4
    u32 u32Rgba;  // offset 0x4, size 0x4
};

// total size: 0xC
struct stcGradient {
    u16 u16SpreadMode;         // offset 0x0, size 0x2
    u16 u16InterpolationRgb;   // offset 0x2, size 0x2
    u32 u32Num;                // offset 0x4, size 0x4
    stcGradRecord* psGradRecs; // offset 0x8, size 0x4
};

// total size: 0x48
struct stcFillStyle {
    u16 u16Style;           // offset 0x0, size 0x2
    u16 u16Padding1;        // offset 0x2, size 0x2
    u32 u32Rgba;            // offset 0x4, size 0x4
    f32 sGradientMtx[3][2]; // offset 0x8, size 0x18
    stcGradient sGradient;  // offset 0x20, size 0xC
    u16 u16BmpId;           // offset 0x2C, size 0x2
    u16 u16TexIdx;          // offset 0x2E, size 0x2
    f32 sBmpMtx[3][2];      // offset 0x30, size 0x18
};

// total size: 0x8
struct stcLineStyle {
    u16 u16Width;   // offset 0x0, size 0x2
    u16 u16Padding; // offset 0x2, size 0x2
    u32 u32RGBA;    // offset 0x4, size 0x4
};

// total size: 0x58
struct stcLineStyle2 {
    u16 u16Width;            // offset 0x0, size 0x2
    u8 u8StartCapStyle;      // offset 0x2, size 0x1
    u8 u8HasFillFlag;        // offset 0x3, size 0x1
    u8 u8NoHScaleFlag;       // offset 0x4, size 0x1
    u8 u8NoVScaleFlag;       // offset 0x5, size 0x1
    u8 u8PixelHintingFlag;   // offset 0x6, size 0x1
    u8 u8NoClose;            // offset 0x7, size 0x1
    u8 u8Padding;            // offset 0x8, size 0x1
    u8 u8EndCapStyle;        // offset 0x9, size 0x1
    u16 u16MiterLimitFactor; // offset 0xA, size 0x2
    u32 u32RGBA;             // offset 0xC, size 0x4
    stcFillStyle sFillStyle; // offset 0x10, size 0x48
};

// total size: 0x8
struct stcVertHeader {
    u32 u32Type; // offset 0x0, size 0x4
    u32 u32Num;  // offset 0x4, size 0x4
};

// total size: 0xC
struct stcPolyVert {
    f32 f32X;     // offset 0x0, size 0x4
    f32 f32Y;     // offset 0x4, size 0x4
    u32 u32Color; // offset 0x8, size 0x4
};

// total size: 0x14
struct stcPolyVertUV {
    f32 f32X;     // offset 0x0, size 0x4
    f32 f32Y;     // offset 0x4, size 0x4
    u32 u32Color; // offset 0x8, size 0x4
    f32 f32U;     // offset 0xC, size 0x4
    f32 f32V;     // offset 0x10, size 0x4
};

// total size: 0x10
struct stcShapeVert {
    u16 u16GroupNum;              // offset 0x0, size 0x2
    u8 u8HasTex;                  // offset 0x2, size 0x1
    u8 u8Padding;                 // offset 0x3, size 0x1
    stcVertHeader* psHeaders;     // offset 0x4, size 0x4
    stcPolyVert* psPolyVerts;     // offset 0x8, size 0x4
    stcPolyVertUV* psPolyVertsUV; // offset 0xC, size 0x4
};

// total size: 0xC
struct stcStraightEdgeRec {
    u8 u8LineType;    // offset 0x0, size 0x1
    u8 au8Padding[3]; // offset 0x1, size 0x3
    s32 s32DeltaX;    // offset 0x4, size 0x4
    s32 s32DeltaY;    // offset 0x8, size 0x4
};

// total size: 0x10
struct stcCurvedEdgeRec {
    s32 s32ControlDeltaX; // offset 0x0, size 0x4
    s32 s32ControlDeltaY; // offset 0x4, size 0x4
    s32 s32AnchorDeltaX;  // offset 0x8, size 0x4
    s32 s32AnchorDeltaY;  // offset 0xC, size 0x4
};

// Forward declaration for stcShape which references stcStyleChangeRec
struct stcStyleChangeRec;

// total size: 0x28
struct stcShape {
    u32 u32ShapeRecNum;                    // offset 0x0, size 0x4
    u32* pu32RecArraySeq;                  // offset 0x4, size 0x4
    u32 au32RecTypeNums[4];                // offset 0x8, size 0x10
    stcStyleChangeRec* psStyleChangeRec;   // offset 0x18, size 0x4
    stcStraightEdgeRec* psStraightEdgeRec; // offset 0x1C, size 0x4
    stcCurvedEdgeRec* psCurvedEdgeRec;     // offset 0x20, size 0x4
    stcShapeVert* psShapeVert;             // offset 0x24, size 0x4
};

// total size: 0x28
struct stcStyleChangeRec {
    s32 s32MoveDeltaX;            // offset 0x0, size 0x4
    s32 s32MoveDeltaY;            // offset 0x4, size 0x4
    u16 u16FillStyle0;            // offset 0x8, size 0x2
    u16 u16FillStyle1;            // offset 0xA, size 0x2
    u16 u16LineStyle;             // offset 0xC, size 0x2
    u16 u16Padding;               // offset 0xE, size 0x2
    u32 u32FillStyleNum;          // offset 0x10, size 0x4
    u32 u32LineStyleNum;          // offset 0x14, size 0x4
    u8 u8IsLineStyle2;            // offset 0x18, size 0x1
    u8 u8NumFillBits;             // offset 0x19, size 0x1
    u8 u8NumLineBits;             // offset 0x1A, size 0x1
    u8 au8Padding[1];             // offset 0x1B, size 0x1
    stcFillStyle* psFillStyle;    // offset 0x1C, size 0x4
    stcLineStyle* psLineStyles;   // offset 0x20, size 0x4
    stcLineStyle2* psLineStyles2; // offset 0x24, size 0x4
};

// total size: 0x40
struct stcShapeWithStyle {
    u32 u32FillStyleNum;          // offset 0x0, size 0x4
    stcFillStyle* psFillStyles;   // offset 0x4, size 0x4
    u32 u32LineStyleNum;          // offset 0x8, size 0x4
    u8 u8IsLineStyle2;            // offset 0xC, size 0x1
    u8 au8Padding[3];             // offset 0xD, size 0x3
    stcLineStyle* psLineStyles;   // offset 0x10, size 0x4
    stcLineStyle2* psLineStyles2; // offset 0x14, size 0x4
    stcShape sShape;              // offset 0x18, size 0x28
};

// total size: 0x54
struct stcDefineShape1 {
    u16 u16CharaID;                    // offset 0x0, size 0x2
    u16 u16Padding;                    // offset 0x2, size 0x2
    stcFgbRect sShapeBounds;           // offset 0x4, size 0x10
    stcShapeWithStyle sShapeWithStyle; // offset 0x14, size 0x40
};

// total size: 0x64
struct stcDefineShape4 {
    u16 u16CharaID;                    // offset 0x0, size 0x2
    u8 u8IsUsesNonScalingStrokes;      // offset 0x2, size 0x1
    u8 u8IsUsesScalingStrokes;         // offset 0x3, size 0x1
    stcFgbRect sShapeBounds;           // offset 0x4, size 0x10
    stcFgbRect sEdgeBounds;            // offset 0x14, size 0x10
    stcShapeWithStyle sShapeWithStyle; // offset 0x24, size 0x40
};

// total size: 0x8
struct stcBitsLossLess2 {
    u16 u16CharaID; // offset 0x0, size 0x2
    u8 u8Format;    // offset 0x2, size 0x1
    u8 u8TexIdx;    // offset 0x3, size 0x1
    u16 u16Width;   // offset 0x4, size 0x2
    u16 u16Height;  // offset 0x6, size 0x2
};

// total size: 0x14
struct stcCXFormWithAlpha {
    u8 u8Type;        // offset 0x0, size 0x1
    u8 u8PlaceType;   // offset 0x1, size 0x1
    u8 au8Padding[2]; // offset 0x2, size 0x2
    s16 s16AddR;      // offset 0x4, size 0x2
    s16 s16AddG;      // offset 0x6, size 0x2
    s16 s16AddB;      // offset 0x8, size 0x2
    s16 s16AddA;      // offset 0xA, size 0x2
    s16 s16MultR;     // offset 0xC, size 0x2
    s16 s16MultG;     // offset 0xE, size 0x2
    s16 s16MultB;     // offset 0x10, size 0x2
    s16 s16MultA;     // offset 0x12, size 0x2
};

struct stcPushData;

// total size: 0x8
struct stcActionRec {
    u8 u8ActCode;     // offset 0x0, size 0x1
    u8 au8Padding[3]; // offset 0x1, size 0x3
    void* pvData;     // offset 0x4, size 0x4
};

// total size: 0xC
struct stcActConstantPool {
    u16 u16PoolNum;   // offset 0x0, size 0x2
    u16* pu16NameLen; // offset 0x4, size 0x4
    c8** ppc8String;  // offset 0x8, size 0x4
};

// total size: 0x14
struct stcActDefineFunction {
    u16 u16FNameLen;    // offset 0x0, size 0x2
    c8* pc8FName;       // offset 0x4, size 0x4
    u16 u16ParamNum;    // offset 0x8, size 0x2
    u16 u16CodeSize;    // offset 0xA, size 0x2
    u16* pu16ParamLen;  // offset 0xC, size 0x4
    c8** ppc8ParamName; // offset 0x10, size 0x4
};

// total size: 0x20
struct stcActDefineFunction2 {
    u16 u16FNameLen;            // offset 0x0, size 0x2
    c8* pc8FuncName;            // offset 0x4, size 0x4
    u16 u16ParamNum;            // offset 0x8, size 0x2
    u8 u8RegisterCount;         // offset 0xA, size 0x1
    u8 u8PreloadParentFlag;     // offset 0xB, size 0x1
    u8 u8PreloadRootFlag;       // offset 0xC, size 0x1
    u8 u8SuppressSuperFlag;     // offset 0xD, size 0x1
    u8 u8PreloadSuperFlag;      // offset 0xE, size 0x1
    u8 u8SuppressArgumentsFlag; // offset 0xF, size 0x1
    u8 u8PreloadArgumentsFlag;  // offset 0x10, size 0x1
    u8 u8SuppressThisFlag;      // offset 0x11, size 0x1
    u8 u8PreloadThisFlag;       // offset 0x12, size 0x1
    u8 u8PreloadGlobalFlag;     // offset 0x13, size 0x1
    u16* pu16PNameLen;          // offset 0x14, size 0x4
    c8** ppc8ParamName;         // offset 0x18, size 0x4
    u16 u16CodeSize;            // offset 0x1C, size 0x2
};

// total size: 0x8
struct stcActGotoFrame2 {
    u8 u8ActCode;     // offset 0x0, size 0x1
    u8 u8BiasFlag;    // offset 0x1, size 0x1
    u8 u8PlayFlag;    // offset 0x2, size 0x1
    u8 u8Padding;     // offset 0x3, size 0x1
    u16 u16SceneBias; // offset 0x4, size 0x2
    u8 au8Padding[2]; // offset 0x6, size 0x2
};

// total size: 0x8
struct stcActGotoLabel {
    u8 u8ActCode;     // offset 0x0, size 0x1
    u8 u8Padding;     // offset 0x1, size 0x1
    u16 u16LabelLen;  // offset 0x2, size 0x2
    c8* pc8LabelName; // offset 0x4, size 0x4
};

// total size: 0x8
struct stcActIf {
    u8 u8ActCode;  // offset 0x0, size 0x1
    u8 u8Padding;  // offset 0x1, size 0x1
    s16 s16OffSet; // offset 0x2, size 0x2
    void* pvData;  // offset 0x4, size 0x4
};

// total size: 0x8
struct stcActPush {
    u8 u8Type;               // offset 0x0, size 0x1
    u8 u8Padding;            // offset 0x1, size 0x1
    u16 u16Num;              // offset 0x2, size 0x2
    stcPushData* psPushData; // offset 0x4, size 0x4
};

// total size: 0x8
struct stcDoAction {
    u32 u32RecNum;           // offset 0x0, size 0x4
    stcActionRec* psActRecs; // offset 0x4, size 0x4
};

// total size: 0x14
struct stcClipEventFlag {
    u8 u8KeyUp;          // offset 0x0, size 0x1
    u8 u8KeyDown;        // offset 0x1, size 0x1
    u8 u8MouseUp;        // offset 0x2, size 0x1
    u8 u8MouseDown;      // offset 0x3, size 0x1
    u8 u8MouseMove;      // offset 0x4, size 0x1
    u8 u8Unload;         // offset 0x5, size 0x1
    u8 u8Frame;          // offset 0x6, size 0x1
    u8 u8Load;           // offset 0x7, size 0x1
    u8 u8DragOver;       // offset 0x8, size 0x1
    u8 u8RollOut;        // offset 0x9, size 0x1
    u8 u8RollOver;       // offset 0xA, size 0x1
    u8 u8ReleaseOutside; // offset 0xB, size 0x1
    u8 u8Release;        // offset 0xC, size 0x1
    u8 u8Press;          // offset 0xD, size 0x1
    u8 u8Initialize;     // offset 0xE, size 0x1
    u8 u8Data;           // offset 0xF, size 0x1
    u8 u8Construct;      // offset 0x10, size 0x1
    u8 u8KeyPress;       // offset 0x11, size 0x1
    u8 u8DragOut;        // offset 0x12, size 0x1
    u8 u8Padding;        // offset 0x13, size 0x1
};

// total size: 0x20
struct stcClipActRec {
    stcClipEventFlag sEvFlag; // offset 0x0, size 0x14
    u8 u8KeyCode;             // offset 0x14, size 0x1
    u8 au8Padding[3];         // offset 0x15, size 0x3
    u32 u32RecNum;            // offset 0x18, size 0x4
    stcActionRec* psActRecs;  // offset 0x1C, size 0x4
};

// total size: 0x1C
struct stcClipAction {
    stcClipEventFlag sEvFlag;    // offset 0x0, size 0x14
    u32 u32ClipRecNum;           // offset 0x14, size 0x4
    stcClipActRec* psClipActRec; // offset 0x18, size 0x4
};

#endif // OOFLASHPARSE_HPP
