#ifndef ST08ROADCONTAINER_HPP
#define ST08ROADCONTAINER_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsRoadTrailer_Obj;

// total size: 0x100
class clsRoadContainer_Obj : public clsBaseGravityLinkObject {
public:
    // Note: enmMode collision with Game.hpp — nested here for disambiguation
    enum enmMode {
        MODE_NONE = 0,
        MODE_CRASH = 1,
        MODE_BREAK = 2,
    };

    virtual ~clsRoadContainer_Obj() {}
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST08_ROAD_CONTAINER_18041; }
    virtual void reset();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContactPoint);
    virtual void requestDrawBreakEffect();
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const { return &t_osCollisionHalfSizeVec; }

    void draw(clsModelType_OB_TX& rcObj,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);
    void setMove();
    void setStop();

    static NNS_VECTORFAST t_sOffsetVecFast;
    static f32 m_tof32ClipSqDist;
    static NNS_VECTOR t_osCollisionHalfSizeVec;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    enmMode m_eMode;                    // offset 0xE0, size 0x4
    clsRoadTrailer_Obj* m_pcTrailerObj; // offset 0xE4, size 0x4
    clsSe3DControl* m_pcSe3DControl;    // offset 0xE8, size 0x4
    stcSetDataDetail* m_psSetData;      // offset 0xEC, size 0x4
    f32 m_f32WaitFrame;                 // offset 0xF0, size 0x4
};

#endif // ST08ROADCONTAINER_HPP
