#ifndef NNCOPYOBJECT_H
#define NNCOPYOBJECT_H

#include "usr/local/sega/nn/src/Object/nnobject.h"

// total size: 0x10
struct NNS_VTXLIST_COMMON_ARRAY {
    unsigned int fType; // offset 0x0, size 0x4
    signed int Number;  // offset 0x4, size 0x4
    unsigned int Size;  // offset 0x8, size 0x4
    void* pList;        // offset 0xC, size 0x4
};

unsigned int nnCalcObjectMaterialSizeCore(struct NNS_OBJECT* obj);
unsigned char*
nnCopyObjectMaterial(struct NNS_OBJECT* dstobj, struct NNS_OBJECT* srcobj, unsigned char* ptr);

#endif // NNCOPYOBJECT_H
