#ifndef NNUTIL_PS2_HPP
#define NNUTIL_PS2_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Camera/nncamera.h"
#include "usr/local/sega/nn/src/Matrix/nnmatrixstack.h"
#include "usr/local/sega/nn/src/Morph/nnmorph.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

struct NNS_BINCNK_DATAHEADER;
struct NNS_BINCNK_NOF0HEADER;
struct NNS_TEXFILE;
struct NNS_TEXFILELIST;

enum NNE_NODENAME_SORTTYPE {
    NNE_NODENAME_SORTTYPE_INDEX = 0,
    NNE_NODENAME_SORTTYPE_NAME = 1,
};

// total size: 0x8
struct NNS_NODENAME {
    s32 iNode; // offset 0x0, size 0x4
    c8* Name;  // offset 0x4, size 0x4
};

// total size: 0xC
struct NNS_NODENAMELIST {
    NNE_NODENAME_SORTTYPE SortType; // offset 0x0, size 0x4
    s32 nNode;                      // offset 0x4, size 0x4
    NNS_NODENAME* pNodeNameList;    // offset 0x8, size 0x4
};

namespace nspNnUtil {
struct tagMatAlphaTmp;

extern u8 cb_buf[32];
extern u32 cb_texflush;
extern f32 tsaNnMtxStackBuf[256][4][4];
extern NNS_MATRIXSTACK tsNnMtxStack;
extern f32 (*tpsNnMtxList)[4][4];
extern f32 (*tpsNnMtxPal)[4][4];
extern u32* tpsNnNodeStatus;
extern NNS_TRS* tapTrs[2];
extern s32 ts32MtxListNum;
extern s32 ts32MtxPalNum;
extern s32 ts32NodeStatusNum;
extern s32 ts32TrsNum;
extern s32 ts32ResidenceTextureSize_PS2;
extern f32 (**tppsNnMultiMtxPtrList)[4][4];
extern void** tppsNodeStatusPtrList;
extern s32 ts32NnMultiObjNum;
extern s32 ts32MtxPtrListNum;
extern s32 ts32NodeStatusPtrListNum;
extern u32 tu32PtrListOffset;

void resetDrawModelAlpha();
void setDrawModelAlpha(f32 f32Param1);
void reversMaterialAlpha(NNS_OBJECT* psParam1, tagMatAlphaTmp* psParam2);
void setMaterialAlpha(NNS_OBJECT* psParam1, tagMatAlphaTmp* psParam2, f32 f32Param3);
void setMaterialAlphaN(NNS_OBJECT* psParam1,
                       tagMatAlphaTmp* psParam2,
                       f32 f32Param3,
                       u32 u32Param4);
void SfdMakeImagePacket(void* pParam1,
                        u32 u32Param2,
                        u32 u32Param3,
                        u32 u32Param4,
                        u32 u32Param5,
                        void* pParam6,
                        void* pParam7);
u32 SfdCalcImagePacketSize(u32 u32Param1, u32 u32Param2, u32 u32Param3);
void TexRelease(_NNS_TEXLIST* psParam1);
void TexResidence_PS2(_NNS_TEXLIST* psParam1);
void TexLoadFileOne(_NNS_TEXINFO* psParam1, NNS_TEXFILE* psParam2, const void* pParam3);
void PXInitCB();
u32 BinGetBinaryDataSize(void* pParam1);
void BinSetUpMorphTargetListCopy(NNS_MORPHTARGETLIST** ppsParam1, void* pParam2, void* pParam3);
void BinSetUpMorphMotionCopy(NNS_MOTION** ppsParam1, void* pParam2, void* pParam3);
void BinSetUpMotionCopy(NNS_MOTION** ppsParam1, void* pParam2, void* pParam3);
void BinSetUpObjectCopy(NNS_OBJECT** ppsParam1,
                        NNS_TEXFILELIST** ppsParam2,
                        void* pParam3,
                        void* pParam4);
void BinSetUpCameraMotion(NNS_CAMERAPTR** ppsParam1, NNS_MOTION** ppsParam2, void* pParam3);
void BinSetUpMorphTargetList(NNS_MORPHTARGETLIST** ppsParam1, void* pParam2);
void BinSetUpMorphMotion(NNS_MOTION** ppsParam1, void* pParam2);
void BinSetUpMotion(NNS_MOTION** ppsParam1, void* pParam2);
void BinSetUpObject(NNS_OBJECT** ppsParam1, NNS_TEXFILELIST** ppsParam2, void* pParam3);
void BinResolvePointer(NNS_BINCNK_DATAHEADER* psParam1, const NNS_BINCNK_NOF0HEADER* psParam2);
void MemCopyDma(void* pParam1, const void* pParam2, u32 u32Param3);
void MakeRotateYZXMatrix(f32 (*pasParam1)[4][4], s32 s32Param2, s32 s32Param3, s32 s32Param4);
void GetMultiDrawBuffer(const NNS_OBJECT* psParam1, f32 (**ppasParam2)[4][4], u32** ppu32Param3);
void SetUpMultiDraw();
void DrawMultiObjectInitialPose(const NNS_OBJECT* psParam1, u32 u32Param2, u32 u32Param3);
void DrawMultiObjectInitialPose(const clsModelType_OB_TX* pcParam1, u32 u32Param2, u32 u32Param3);
void DrawMultiObject(const NNS_OBJECT* psParam1, u32 u32Param2, u32 u32Param3);
void DrawMultiObject(const clsModelType_OB_TX* pcParam1, u32 u32Param2, u32 u32Param3);
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
} // namespace nspNnUtil

#endif // NNUTIL_PS2_HPP
