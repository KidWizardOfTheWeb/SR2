#ifndef ST02BEEBASE_HPP
#define ST02BEEBASE_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0xC
class clsBeeRoboBase_Obj {
public:
    virtual ~clsBeeRoboBase_Obj() {}

    void stopSe() {}
    void playSe(const NNS_VECTORFAST& rParam1, const f32& rf32Param2, f32 f32Param3) {}

    s16 m_as16Id3D[4]; // offset 0x4, size 0x8
};

#endif // ST02BEEBASE_HPP
