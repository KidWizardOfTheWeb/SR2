#ifndef NNUTIL_UNION_HPP
#define NNUTIL_UNION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil_PS2.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

// total size: 0x1
struct stcTexFileType {
    u8 u4MinFilter : 4; // offset 0x0, size 0x1
    u8 u2MagFilter : 2; // offset 0x0, size 0x1
    u8 u2Padding : 2;   // offset 0x0, size 0x1
};

namespace nspNnUtil {
void transformVectorFast44(NNS_VECTORFAST& rsParam1,
                           const f32 (&rasParam2)[4][4],
                           const NNS_VECTORFAST& rsParam3);
void BinSetUp_Model(clsModelType_OB_TX_MO_MA_MF& rcParam1,
                    const u8* pu8Param2,
                    const u32* pu32Param3);
void BinSetUp_Model(clsModelType_OB_TX_MO_MA_MF& rcParam1, const u8** ppu8Param2);
void BinSetUp_MatMotion(NNS_OBJECT** ppsParam1,
                        NNS_OBJECT** ppsParam2,
                        NNS_MOTION** ppsParam3,
                        u32** ppu32Param4,
                        void* pParam5);
void BinSetUpTexList_Texture(_NNS_TEXLIST** ppsParam1, void** ppParam2, const void* pParam3);
void MallocUnionNnData();
void InitUnionNnData();
void MakeRotateYZXMatrix(f32 (*pasParam1)[4][4], s32 s32Param2, s32 s32Param3, s32 s32Param4);
void GetMultiDrawBuffer(const NNS_OBJECT* psParam1, f32 (**ppasParam2)[4][4], u32** ppu32Param3);
void SetUpMultiDraw();
void DrawMultiObjectInitialPose(const NNS_OBJECT* psParam1, u32 u32Param2, u32 u32Param3);
void DrawMultiObjectInitialPose(const clsModelType_OB_TX* pcParam1, u32 u32Param2, u32 u32Param3);
void DrawMultiObject(const NNS_OBJECT* psParam1, u32 u32Param2, u32 u32Param3);
void DrawMultiObject(const clsModelType_OB_TX* pcParam1, u32 u32Param2, u32 u32Param3);
} // namespace nspNnUtil

#endif // NNUTIL_UNION_HPP
