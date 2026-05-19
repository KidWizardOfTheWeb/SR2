#ifndef GROUNDCOLLISION_HPP
#define GROUNDCOLLISION_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"

class hkShape;

// total size: 0x28
class clsGroundCollision : public clsObject {
public:
    // total size: 0x10
    struct stcInfo {
        u8 u8Effect;     // offset 0x0, size 0x1
        u8 u8Attr;       // offset 0x1, size 0x1
        u8 u8Filter;     // offset 0x2, size 0x1
        s8 s8Grip;       // offset 0x3, size 0x1
        u8 u8Union[4];   // offset 0x4, size 0x4
        f32 f32Param;    // offset 0x8, size 0x4
        u32 u32Reserved; // offset 0xC, size 0x4
    };

    // total size: 0x20
    struct stcBinBody {
        f32* pf32Vertex;    // offset 0x0, size 0x4
        u16* pu16Triangle;  // offset 0x4, size 0x4
        u32 u32VertexNum;   // offset 0x8, size 0x4
        u32 u32TriangleNum; // offset 0xC, size 0x4
        stcInfo sInfo;      // offset 0x10, size 0x10
    };

    ~clsGroundCollision();

    clsGroundCollision();

    virtual enmType getObjectType() const;

    void create(hkShape* pcShape, const stcInfo* psInfo);

    void destroy();

    void setData(const stcBinBody* psBody);
};

typedef clsGroundCollision::stcBinBody stcBinBody;

#endif // GROUNDCOLLISION_HPP
