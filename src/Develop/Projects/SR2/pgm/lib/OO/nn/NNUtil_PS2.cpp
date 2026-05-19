#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil_PS2.hpp"

static s32 gs32CdFileIdx;
static c8 smpsBinaryPath[256];
static c8 smpsTexturePath[256];

u8 nspNnUtil::cb_buf[32];
u32 nspNnUtil::cb_texflush;
f32 nspNnUtil::tsaNnMtxStackBuf[256][4][4];
NNS_MATRIXSTACK nspNnUtil::tsNnMtxStack;
f32 (*nspNnUtil::tpsNnMtxList)[4][4];
f32 (*nspNnUtil::tpsNnMtxPal)[4][4];
u32* nspNnUtil::tpsNnNodeStatus;
NNS_TRS* nspNnUtil::tapTrs[2];
s32 nspNnUtil::ts32MtxListNum;
s32 nspNnUtil::ts32MtxPalNum;
s32 nspNnUtil::ts32NodeStatusNum;
s32 nspNnUtil::ts32TrsNum;
s32 nspNnUtil::ts32ResidenceTextureSize_PS2;
f32 (**nspNnUtil::tppsNnMultiMtxPtrList)[4][4];
void** nspNnUtil::tppsNodeStatusPtrList;
s32 nspNnUtil::ts32NnMultiObjNum;
s32 nspNnUtil::ts32MtxPtrListNum;
s32 nspNnUtil::ts32NodeStatusPtrListNum;
u32 nspNnUtil::tu32PtrListOffset;

void nspNnUtil::MemCopyDma(void* pParam1, const void* pParam2, u32 u32Param3)
{
}

void nspNnUtil::BinResolvePointer(NNS_BINCNK_DATAHEADER* psParam1,
                                  const NNS_BINCNK_NOF0HEADER* psParam2)
{
}

void nspNnUtil::BinSetUpObject(NNS_OBJECT** ppsParam1, NNS_TEXFILELIST** ppsParam2, void* pParam3)
{
}

void nspNnUtil::BinSetUpMotion(NNS_MOTION** ppsParam1, void* pParam2)
{
}

void nspNnUtil::BinSetUpMorphMotion(NNS_MOTION** ppsParam1, void* pParam2)
{
}

void nspNnUtil::BinSetUpMorphTargetList(NNS_MORPHTARGETLIST** ppsParam1, void* pParam2)
{
}

void nspNnUtil::BinSetUpCameraMotion(NNS_CAMERAPTR** ppsParam1,
                                     NNS_MOTION** ppsParam2,
                                     void* pParam3)
{
}

void nspNnUtil::BinSetUpObjectCopy(NNS_OBJECT** ppsParam1,
                                   NNS_TEXFILELIST** ppsParam2,
                                   void* pParam3,
                                   void* pParam4)
{
}

void nspNnUtil::BinSetUpMotionCopy(NNS_MOTION** ppsParam1, void* pParam2, void* pParam3)
{
}

void nspNnUtil::BinSetUpMorphMotionCopy(NNS_MOTION** ppsParam1, void* pParam2, void* pParam3)
{
}

void nspNnUtil::BinSetUpMorphTargetListCopy(NNS_MORPHTARGETLIST** ppsParam1,
                                            void* pParam2,
                                            void* pParam3)
{
}

u32 nspNnUtil::BinGetBinaryDataSize(void* pParam1)
{
    return 0;
}

void nspNnUtil::PXInitCB()
{
}

void nspNnUtil::TexLoadFileOne(_NNS_TEXINFO* psParam1, NNS_TEXFILE* psParam2, const void* pParam3)
{
}

void nspNnUtil::TexResidence_PS2(_NNS_TEXLIST* psParam1)
{
}

void nspNnUtil::TexRelease(_NNS_TEXLIST* psParam1)
{
}

u32 nspNnUtil::SfdCalcImagePacketSize(u32 u32Param1, u32 u32Param2, u32 u32Param3)
{
    return 0;
}

void nspNnUtil::SfdMakeImagePacket(void* pParam1,
                                   u32 u32Param2,
                                   u32 u32Param3,
                                   u32 u32Param4,
                                   u32 u32Param5,
                                   void* pParam6,
                                   void* pParam7)
{
}

void nspNnUtil::setMaterialAlphaN(NNS_OBJECT* psParam1,
                                  tagMatAlphaTmp* psParam2,
                                  f32 f32Param3,
                                  u32 u32Param4)
{
}

void nspNnUtil::setMaterialAlpha(NNS_OBJECT* psParam1, tagMatAlphaTmp* psParam2, f32 f32Param3)
{
}

void nspNnUtil::reversMaterialAlpha(NNS_OBJECT* psParam1, tagMatAlphaTmp* psParam2)
{
}

void nspNnUtil::setDrawModelAlpha(f32 f32Param1)
{
}

void nspNnUtil::resetDrawModelAlpha()
{
}
