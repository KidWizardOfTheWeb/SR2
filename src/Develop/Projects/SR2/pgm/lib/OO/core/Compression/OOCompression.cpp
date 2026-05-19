#include "Develop/Projects/SR2/pgm/lib/OO/core/Compression/OOCompression.hpp"

clsOOHeapFragment clsOOCompression::__dummy_heap;
s32 clsOOCompression::s_s32CompThPri;
s32 clsOOCompression::s_s32ObjThPri;

enum enmObjFuncArgType {
    OBJ_FUNC_ARG_S_NORMAL_D_NORMAL = 0,
    OBJ_FUNC_ARG_S_NORMAL_D_RING = 1,
    OBJ_FUNC_ARG_S_RING_D_NORMAL = 2,
    OBJ_FUNC_ARG_S_RING_D_RING = 3,
};

// total size: 0x14
class _ObjThreadArg {
public:
    enmObjFuncArgType eArgType;    // offset 0x0, size 0x4
    void* pvSrcBuf;                // offset 0x4, size 0x4
    void* pvDstBuf;                // offset 0x8, size 0x4
    clsOOCompObj* pcObj;           // offset 0xC, size 0x4
    clsOOCompression* pcOwnerComp; // offset 0x10, size 0x4
};

void clsOOCompression::initSetting(s32 s32CompThreadPri, s32 s32ObjThreadPri)
{
    s_s32CompThPri = s32CompThreadPri;
    s_s32ObjThPri = s32ObjThreadPri;
}

s32 clsOOCompression::__startComp(clsOOBuffer& rcDstBuf, clsOORingBuffer& rcSrcBuf, execMode eMode)
{
    return 0;
}

void* clsOOCompression::execComp(const clsOOThread::_EntryArg* psArg)
{
    return 0;
}

void clsOOCompression::init()
{
}
