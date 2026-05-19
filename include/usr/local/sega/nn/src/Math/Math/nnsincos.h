#ifndef NNSINCOS_H
#define NNSINCOS_H

extern float nngSinCosTbl[1025];

float nnSin(signed int ang);
float nnCos(signed int ang);
void nnSinCos(signed int ang, float* s, float* c);

#endif // NNSINCOS_H
