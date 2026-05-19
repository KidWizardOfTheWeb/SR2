#include "Develop/Projects/SR2/pgm/lib/OO/core/Flash/OOFlashParse.hpp"

struct stcFlash;
struct stcImportAssets;
struct stcPlaceObject2;
struct stcPlaceObject3;
struct stcScene;
struct stcSprite;

namespace nspFlashParse {
u32 u32FileAddr;
f32 (*psMtx)[3][2];
stcCXFormWithAlpha* psCXFwithA;
stcCXFormWithAlpha* psCXFwithB;
stcCXFormWithAlpha sNormalCXFwithA;
stcCXFormWithAlpha sNormalCXFwithB;
} // namespace nspFlashParse

u32 Parse_ImportAssets(u8* pou8RowData, stcImportAssets* psIm)
{
    return 0;
}

u32 Parse_PlaceObject3(u8* pou8RowData, stcPlaceObject3* psData, u32& ru32Depth)
{
    return 0;
}

u32 Parse_PlaceObject2(u8* pou8RowData, stcPlaceObject2* psData, u32& ru32Depth)
{
    return 0;
}

u32 Parse_ActionRec(u8* pou8RowData, stcActionRec* psActRec)
{
    return 0;
}

u32 Parse_FMScene(u8* pou8RowData, stcScene* psScene)
{
    return 0;
}

u32 Parse_FMSprite(u8* pou8RowData, stcSprite* psSprite)
{
    return 0;
}

u32 Parse_StyleChangeRec(u8* pou8RowData, stcStyleChangeRec* psSCRec)
{
    return 0;
}

u32 Parse_Shape(u8* pou8RowData, stcShape* psShape)
{
    return 0;
}

u32 Parse_ShapeWithStyle(u8* pou8RowData, stcShapeWithStyle* psSWStyle)
{
    return 0;
}

s32 Parse_FGB(void* pvRowData, stcFlash* psFlash)
{
    return 0;
}
