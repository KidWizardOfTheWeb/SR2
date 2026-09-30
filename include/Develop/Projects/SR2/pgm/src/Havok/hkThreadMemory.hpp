#ifndef HKTHREADMEMORY_HPP
#define HKTHREADMEMORY_HPP

#include "types.h"

enum HK_MEMORY_CLASS {
    HK_MEMORY_CLASS_ROOT = 0,
    HK_MEMORY_CLASS_BASE = 1,
    HK_MEMORY_CLASS_COLLIDE = 2,
    HK_MEMORY_CLASS_CONSTRAINT_SOLVER = 3,
    HK_MEMORY_CLASS_DYNAMICS = 4,
    HK_MEMORY_CLASS_EXPORT = 5,
    HK_MEMORY_CLASS_SERIALIZE = 6,
    HK_MEMORY_CLASS_GEOMETRY = 7,
    HK_MEMORY_CLASS_DISPLAY = 8,
    HK_MEMORY_CLASS_MATH = 9,
    HK_MEMORY_CLASS_SCENE_DATA = 10,
    HK_MEMORY_CLASS_VEHICLE = 11,
    HK_MEMORY_CLASS_UTILITIES = 12,
    HK_MEMORY_CLASS_ANIMATION = 13,
    HK_MEMORY_CLASS_BEHAVIOR = 14,
    HK_MEMORY_CLASS_TOOLS = 15,
    HK_MEMORY_CLASS_DEMO_FRAMEWORK = 16,
    HK_MEMORY_CLASS_DEMO = 17,
    HK_MEMORY_CLASS_USER = 18,
    HK_MEMORY_CLASS_BASE_CLASS = 19,
    HK_MEMORY_CLASS_STRING = 20,
    HK_MEMORY_CLASS_ARRAY = 21,
    HK_MEMORY_CLASS_SINGLETON = 22,
    HK_MEMORY_CLASS_SCRATCHPAD = 23,
    HK_MEMORY_CLASS_STREAM = 24,
    HK_MEMORY_CLASS_MONITOR = 25,
    HK_MEMORY_CLASS_MAP = 26,
    HK_MEMORY_CLASS_TREE = 27,
    HK_MEMORY_CLASS_HKCLASS = 28,
    HK_MEMORY_CLASS_AGENT = 29,
    HK_MEMORY_CLASS_ALGORITHM = 30,
    HK_MEMORY_CLASS_BROAD_PHASE = 31,
    HK_MEMORY_CLASS_CONTACT = 32,
    HK_MEMORY_CLASS_DISPATCH = 33,
    HK_MEMORY_CLASS_MANIFOLD = 34,
    HK_MEMORY_CLASS_SHAPE = 35,
    HK_MEMORY_CLASS_COLLIDABLE = 36,
    HK_MEMORY_CLASS_CDINFO = 37,
    HK_MEMORY_CLASS_MOPP = 38,
    HK_MEMORY_CLASS_ACTION = 39,
    HK_MEMORY_CLASS_DYNCOLLIDE = 40,
    HK_MEMORY_CLASS_DEACTIVATOR = 41,
    HK_MEMORY_CLASS_CONSTRAINT = 42,
    HK_MEMORY_CLASS_ENTITY = 43,
    HK_MEMORY_CLASS_MOTION = 44,
    HK_MEMORY_CLASS_WORLD = 45,
    HK_MEMORY_CLASS_RIGID_BODY = 46,
    HK_MEMORY_CLASS_PHANTOM = 47,
    HK_MEMORY_CLASS_SIMISLAND = 48,
    HK_MEMORY_CLASS_CAMERA = 49,
    HK_MEMORY_CLASS_CHARACTER = 50,
    HK_MEMORY_CLASS_VDB = 51,
    HK_MEMORY_CLASS_INERTIA = 52,
    HK_MEMORY_CLASS_ANIM_UNCOMPRESSED = 53,
    HK_MEMORY_CLASS_ANIM_COMPRESSED = 54,
    HK_MEMORY_CLASS_ANIM_DATA = 55,
    HK_MEMORY_CLASS_ANIM_MOTION = 56,
    HK_MEMORY_CLASS_ANIM_RIG = 57,
    HK_MEMORY_CLASS_ANIM_CONTROL = 58,
    HK_MEMORY_CLASS_ANIM_RUNTIME = 59,
    HK_MEMORY_CLASS_ANIM_CACHE = 60,
    HK_MEMORY_CLASS_BEHAVIOR_RUNTIME = 61,
    HK_MEMORY_CLASS_BEHAVIOR_DEMOS = 62,
    HK_MEMORY_CLASS_USER_1 = 63,
    HK_MEMORY_CLASS_USER_2 = 64,
    HK_MEMORY_CLASS_USER_3 = 65,
    HK_MEMORY_CLASS_USER_4 = 66,
    HK_MEMORY_CLASS_PRE_ALLOCATED = 67,
    HK_MEMORY_CLASS_MAX = 68,
};

class hkMemory;

// total size: 0x4
class FreeElem {
public:
    FreeElem* m_next; // offset 0x0, size 0x4
};

// total size: 0x8
class FreeList {
public:
    FreeElem* pop()
    {
        FreeElem* pFreeElem;
        if (m_head != NULL) {
            pFreeElem = m_head;
            --m_numElem;
            m_head = m_head->m_next;
        } else {
            pFreeElem = NULL;
        }
        return pFreeElem;
    }

    FreeElem* m_head; // offset 0x0, size 0x4
    s32 m_numElem;    // offset 0x4, size 0x4
};

// total size: 0x10
class Stack {
public:
    c8* m_current; // offset 0x0, size 0x4
    Stack* m_prev; // offset 0x4, size 0x4
    c8* m_base;    // offset 0x8, size 0x4
    c8* m_end;     // offset 0xC, size 0x4
};

// total size: 0x314
class hkThreadMemory {
public:
    hkThreadMemory(hkMemory* pParam1, s32 s32Param2);
    virtual void* alignedAllocate(s32 s32Param1, s32 s32Param2, HK_MEMORY_CLASS sParam3);
    virtual void alignedDeallocate(void* pvParam1);
    virtual void setStackArea(void* pvParam1, s32 s32Param2);
    virtual void releaseCachedMemory();
    virtual ~hkThreadMemory();
    virtual void* onStackOverflow(s32 s32Param1);
    virtual void onStackUnderflow(void* pvParam1);

    void removeReference();
    void addReference();
    void onRowEmpty(s32 s32Param1);
    void onRowFull(s32 s32Param1, s32 s32Param2);
    void* allocate(s32 s32Param1, HK_MEMORY_CLASS sParam2);
    void deallocate(void* pvParam1);
    void* allocateChunk(s32 s32Param1, HK_MEMORY_CLASS sParam2);
    void deallocateChunk(void* pvParam1, s32 s32Param2, HK_MEMORY_CLASS sParam3);
    void replaceInstance(hkThreadMemory* pParam1);
    void init();
    void quit();

    static hkThreadMemory* s_threadMemoryInstance;

    hkMemory* m_memory;              // offset 0x4, size 0x4
    s32 m_referenceCount;            // offset 0x8, size 0x4
    Stack m_stack;                   // offset 0xC, size 0x10
    s32 m_stackSize;                 // offset 0x1C, size 0x4
    s32 m_maxNumElemsOnFreeList;     // offset 0x20, size 0x4
    FreeList m_free_list[17];        // offset 0x24, size 0x88
    s32 m_row_to_size_lut[17];       // offset 0xAC, size 0x44
    c8 m_small_size_to_row_lut[513]; // offset 0xF0, size 0x201
    s32 m_large_size_to_row_lut[8];  // offset 0x2F4, size 0x20
};

#endif // HKTHREADMEMORY_HPP
