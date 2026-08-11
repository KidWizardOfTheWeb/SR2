#ifndef GIMMICKOBJ_HPP
#define GIMMICKOBJ_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/FrameControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/HaveGimmickRigidBody.hpp"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/Matrix/nnmakematrix.h"
#include "usr/local/sega/nn/src/Matrix/nnmatrix.h"
#include "usr/local/sega/nn/src/Matrix/nnquaternion.h"

// Enum used by clsGimmickObj for clip visibility state (owned by nspOOFileMgr)
#ifndef ENMRET_DECLARED
#define ENMRET_DECLARED
enum enmRet {
    VISIBLE_CLIP = 0,
    VISIBLE = 1,
    OUT_VISIBLE = 2,
    OUT_PORTAL = 3,
    OUT_FAR = 4,
};
#endif

// Enum used by clsBreakControl (global, MWCC scoping — verify during implementation)
#ifndef ENM_MODE_DECLARED
#define ENM_MODE_DECLARED
enum enmMode {
    MODE_NONE = 0,
    MODE_EXECUTE = 1,
    MODE_BREAK = 2,
};
#endif

class clsDebrisControl;
class clsGravityActionControl;
// total size: 0x50
class clsGimmickObj : public clsObject {
public:
    clsGimmickObj() {}
    virtual ~clsGimmickObj() {}

    NNS_VECTORFAST m_sPosVecFast;        // offset 0x10, size 0x10
    NNS_QUATERNION m_sRotQuat;           // offset 0x20, size 0x10
    NNS_VECTOR m_sScaleVec;              // offset 0x30, size 0xC
    stcSetDataDetail* m_psSetDataDetail; // offset 0x3C, size 0x4
    u32 m_u32Attr;                       // offset 0x40, size 0x4
    enmRet m_enClipRet;                  // offset 0x44, size 0x4
    u32 m_u32State;                      // offset 0x48, size 0x4
    u8 m_u8PortalNo;                     // offset 0x4C, size 0x1
    u8 m_u8DrawFlg;                      // offset 0x4D, size 0x1
    u8 m_bEffective;                     // offset 0x4E, size 0x1

    virtual enmType getObjectType() const { return TYPE_GIMMICK; }
    virtual void setData() {}
    virtual void createData() {}
    virtual void destroyData() {}
    virtual u32 GetDrawNodeStatus() { return 0; }
    virtual nspPackId::enm getPackId() const
    {
        return static_cast<nspPackId::enm>(m_psSetDataDetail->u16Type);
    }
    virtual u32 getMultiDrawNum() const { return 1; }
    virtual void drawCollision();

    void setAttribute(u32 ou32Attr);
    void setSetData();
    void setSetData(const stcSetDataDetail& orsSetDataDetailI);
    stcSetDataDetail* getSetDataDetail() const { return m_psSetDataDetail; }
    void setPortalNo(u8 ou8PortalNo) { m_u8PortalNo = ou8PortalNo; }
    NNS_VECTORFAST& getPositionRef() const { return const_cast<NNS_VECTORFAST&>(m_sPosVecFast); }
    NNS_QUATERNION& getRotQuatRef() const { return const_cast<NNS_QUATERNION&>(m_sRotQuat); }
    u32 getAttribute() const { return m_u32Attr; }
    NNS_VECTOR& getScaleRef() const { return const_cast<NNS_VECTOR&>(m_sScaleVec); }
    u8 getPortalNo() const { return m_u8PortalNo; }
    u8 getEffective() { return m_bEffective; }
    void clearDrawFlg(u32 u32ViewNo) { m_u8DrawFlg &= ~u32ViewNo; }
    void setPosition(f32 of32xI, f32 of32yI, f32 of32zI)
    {
        nnSetUpVectorFast(&m_sPosVecFast, of32xI, of32yI, of32zI);
    }
    void setPosition(const NNS_VECTORFAST& orsVecFastI) {}
    void setRotate(f32 of32xI, f32 of32yI, f32 of32zI)
    {
        NNS_MATRIX sMtx;
        NNS_MATRIX sMtxWork;
        const s32 s32RotX = static_cast<s32>(of32xI * 182.04444f);
        s32 s32RotY;
        s32 s32RotZ;
        s32RotZ = static_cast<s32>(of32zI * 182.04444f);
        s32RotY = static_cast<s32>(of32yI * 182.04444f);
        nnMakeRotateXMatrix(&sMtx, s32RotX);
        nnRotateZMatrix(&sMtxWork, &sMtx, s32RotZ);
        nnRotateYMatrix(&sMtx, &sMtxWork, s32RotY);
        nnMakeRotateMatrixQuaternion(&m_sRotQuat, &sMtx);
    }
    void setRotate(const NNS_QUATERNION& orsQuat) { m_sRotQuat = orsQuat; }
    u32 checkClip(u32 u32ViewNo,
                  const NNS_OBJECT* psObject,
                  const NNS_MATRIX* psMtx,
                  f32 f32ClipDistx2,
                  f32* pf32CamDist)
    {
        return m_enClipRet;
    }
};

#endif // GIMMICKOBJ_HPP
