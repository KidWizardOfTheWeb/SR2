#ifndef NNTEXMTXPS2_H
#define NNTEXMTXPS2_H

enum PXE_TRANSFORM {
    PXE_TRANSFORM_LIGHT = 0,
    PXE_TRANSFORM_VIEWPROJ = 1,
    PXE_TRANSFORM_TEXTURE1 = 2,
    PXE_TRANSFORM_TEXTURE2 = 3,
};

void nnSetTextureMatrixPS2(float (*mtx)[4][4]);
void nnPutEnvTextureMatrix(float (*mtx)[4][4], enum PXE_TRANSFORM transtex);
void nnPutEnvTextureMatrixNormalize(float (*mtx)[4][4], enum PXE_TRANSFORM transtex);
void nnPutProjTextureMatrix(float (*mtx)[4][4], enum PXE_TRANSFORM transtex);
void nnPutTextureMatrix(float (*mtx)[4][4], enum PXE_TRANSFORM transtex);

#endif // NNTEXMTXPS2_H
