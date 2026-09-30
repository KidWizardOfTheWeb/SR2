#ifndef CLIPPER_HPP
#define CLIPPER_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/GlobalData.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/BaseStage.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCameraMgr.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCamera.hpp"
#include "usr/local/sega/nn/src/Matrix/nnmatrix.h"
#include "usr/local/sega/nn/src/Math/Math/nnsqrt.h"
#include "usr/local/sega/nn/src/System/nnclip.h"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "usr/local/sega/nn/src/Object/nnobject.h"

struct stcBinDataDetail;

// total size: 0x14
class clsClipper : public clsSingleton<clsClipper> {
public:
    clsClipper();
    virtual ~clsClipper() {}

    enmRet check(u32 u32ViewNo,
                 const NNS_OBJECT& rsObject,
                 const NNS_MATRIX& rsMtx,
                 u8 u8PortalNo,
                 f32 f32ClipDistx2,
                 f32* pf32CamDist)
    {
        if (*m_pu32DebugDisableCilp != 0) {
            if (pf32CamDist != NULL) {
                clsPfCamera* pcCamera = clsPfCameraMgr::GS()->getCamera(u32ViewNo);
                NNS_VECTORFAST sPosVecFast = {0.0f, 0.0f, 0.0f, 1.0f};
                sPosVecFast.y = rsObject.Center.y;
                nnTransformVectorFast(&sPosVecFast, &rsMtx, &sPosVecFast);
                *pf32CamDist = nnDistanceVectorFast(&sPosVecFast, pcCamera->getPosFast());
            }
            return VISIBLE;
        }
        if (nspGlobal::sTask.pcBaseStage->checkObjPortal(u32ViewNo, u8PortalNo) == 4) {
            if (pf32CamDist != NULL) {
                *pf32CamDist = 100000000.0f;
            }
            return OUT_PORTAL;
        }
        clsPfCamera* pcCamera = clsPfCameraMgr::GS()->getCamera(u32ViewNo);
        NNS_VECTORFAST sPosVecFast = {0.0f, 0.0f, 0.0f, 1.0f};
        sPosVecFast.y = rsObject.Center.y;
        nnTransformVectorFast(&sPosVecFast, &rsMtx, &sPosVecFast);
        f32 f32Distx2 = nnDistanceSqVectorFast(&sPosVecFast, pcCamera->getPosFast());
        if (pf32CamDist != NULL) {
            *pf32CamDist = nnSqrt(f32Distx2);
        }
        if (f32ClipDistx2 <= f32Distx2) {
            return OUT_FAR;
        }
        NNS_MATRIX sViewMtx;
        nnMultiplyMatrix(&sViewMtx, pcCamera->getViewMtx(), &rsMtx);
        static enmRet aoeRet[] = {VISIBLE_CLIP, OUT_VISIBLE, VISIBLE};
        return aoeRet[nnCheckObjectClip(&rsObject, &sViewMtx)];
    }

    static f32 MIN_Z;
    static f32 MAX_Z;

    f32 m_f32NnClipNear;                  // offset 0x4, size 0x4
    f32 m_f32NnClipFar;                   // offset 0x8, size 0x4
    stcBinDataDetail* m_opsBinDataDetail; // offset 0xC, size 0x4
    u32* m_pu32DebugDisableCilp;          // offset 0x10, size 0x4
};

#endif // CLIPPER_HPP
