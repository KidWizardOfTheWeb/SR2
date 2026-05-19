#ifndef NNMATEXT_H
#define NNMATEXT_H

void nnSetWireColor(float r, float g, float b, float a);
void nnPutSubMaterialWire(void);
void nnSetDrawObjectDivColorAlpha(float a);
void nnSetNormalLength(float len);
void nnSetNormalColor(float r, float g, float b, float a);
void nnPutMaterialNormal(void);
void nnLoadIgnoreTexture(void* tex5551, void* tex8888);
void nnReleaseIgnoreTexture(void);

#endif // NNMATEXT_H
