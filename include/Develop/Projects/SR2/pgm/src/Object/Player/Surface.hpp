#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

extern "C" s32 nnNormalizeQuaternion(NNS_QUATERNION* psDstQuat, const NNS_QUATERNION* psSrcQuat);

// total size: 0x20
class clsSurface {
public:
    clsSurface() { reset(); }

    f32 getRotateRadToDirNrmVecFast(const NNS_VECTORFAST* posDirVecFast,
                                    const NNS_QUATERNION* posSurfaceQuat);
    void reset();
    void change(NNS_QUATERNION& rsBaseQuat, const NNS_VECTORFAST& rsUpVecFast);
    void update(const NNS_VECTORFAST& rsUpVecFast);
    void updateDirection(NNS_VECTORFAST& rsUpVecFast,
                         const NNS_VECTORFAST* opsBaseDirVecFast,
                         const NNS_VECTORFAST* opsDirVecFast);
    void
    convertQuatToSurface(NNS_VECTORFAST& rsUpVecFast, f32& rf32Rad, const NNS_QUATERNION& rsQuat);

    NNS_QUATERNION* getQuatPtr() const { return const_cast<NNS_QUATERNION*>(&m_sQuat); }
    void setQuat(const NNS_QUATERNION& rsQuat) { nnNormalizeQuaternion(&m_sQuat, &rsQuat); }
    f32 getRotateRadToDirNrmVecFast(const NNS_VECTORFAST* posDirVecFast)
    {
        return getRotateRadToDirNrmVecFast(posDirVecFast, &m_sQuat);
    }

    NNS_QUATERNION m_sQuat;      // offset 0x0, size 0x10
    NNS_VECTORFAST m_sUpVecFast; // offset 0x10, size 0x10
};

#endif // SURFACE_HPP
