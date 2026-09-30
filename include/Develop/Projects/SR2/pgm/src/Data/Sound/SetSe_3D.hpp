#ifndef SETSE_3D_HPP
#define SETSE_3D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2System.hpp"
#include "Develop/Projects/SR2/pgm/src/System/RequestArray.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/metrowerks/PS2_Support/stl/algorithm.h"

// total size: 0xA0
class clsSetSe_3D_Task : public clsTask {
public:
    ~clsSetSe_3D_Task();

    clsSetSe_3D_Task(const stcSetDataDetail& orsSetDataDetailI)
        : clsTask(800000, 4), m_orsRequestArray(m_oasRequestArray[orsSetDataDetailI.u32Attr]),
          m_orf32ReSpawnFrame_default(orsSetDataDetailI.sRotVec.y),
          m_f32DistDownK(orsSetDataDetailI.sRotVec.x),
          m_u8ViewPortNum(std::min(static_cast<u8>(clsPfSystem::GS()->getViewportNum()),
                                   orsSetDataDetailI.uniu8ViewportNum)),
          m_u8PortalType(orsSetDataDetailI.u8PortalType)
    {
        m_as16Id3D[0] = m_as16Id3D[1] = m_as16Id3D[2] = m_as16Id3D[3] = -1;
        m_af32ReSpawnFrame[0] = m_af32ReSpawnFrame[1] = m_af32ReSpawnFrame[2] =
            m_af32ReSpawnFrame[3] = m_orf32ReSpawnFrame_default;
        m_sPosVecFast.x = orsSetDataDetailI.sPosVec.x;
        m_sPosVecFast.y = orsSetDataDetailI.sPosVec.y;
        m_sPosVecFast.z = orsSetDataDetailI.sPosVec.z;
        m_sPosVecFast.w = 1.0f;
    }

    virtual void execute();

    static stcRequestArray m_oasRequestArray[21];

    NNS_VECTORFAST m_sPosVecFast;           // offset 0x60, size 0x10
    stcRequestArray& m_orsRequestArray;     // offset 0x70, size 0x4
    f32 m_af32ReSpawnFrame[4];              // offset 0x74, size 0x10
    const f32& m_orf32ReSpawnFrame_default; // offset 0x84, size 0x4
    s16 m_as16Id3D[4];                      // offset 0x88, size 0x8
    f32 m_f32DistDownK;                     // offset 0x90, size 0x4
    u8 m_u8ViewPortNum;                     // offset 0x94, size 0x1
    u8 m_u8PortalType;                      // offset 0x95, size 0x1
};

#endif // SETSE_3D_HPP
