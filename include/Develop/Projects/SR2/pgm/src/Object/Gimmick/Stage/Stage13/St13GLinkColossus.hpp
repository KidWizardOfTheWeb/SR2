#ifndef ST13GLINKCOLOSSUS_HPP
#define ST13GLINKCOLOSSUS_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSe3DControl;
class clsPlayerTask;

// total size: 0xF0
class clsGLinkColossus_Object : public clsBaseGravityLinkObject {
public:
    inline clsGLinkColossus_Object() : clsBaseGravityLinkObject() {}
    virtual ~clsGLinkColossus_Object() {}

    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    u8 m_eMode;                      // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam[2];

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual u8 draw(NNS_OBJECT* psObject,
                    f32 (*psMtxPal)[4][4],
                    u32* psNodeStat,
                    const f32 (*opaNnViewMtx)[4][4],
                    f32 (*psMtxWork)[4][4],
                    u32 u32ViewNo);
    virtual void countEffect();
    virtual void requestDrawBreakEffect();
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const;
    virtual nspPackId::enm getPackId() const;
};

// total size: 0x98
class clsGLinkColossus_Task : public clsSingleModelGimmick_Task<clsGLinkColossus_Task,
                                                                clsGLinkColossus_Object,
                                                                clsModelType_OB_TX> {
public:
    clsGLinkColossus_Task(u32 u32ObjectAreaNum);
    virtual ~clsGLinkColossus_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkShape* m_pcPartsShape; // offset 0x94, size 0x4
};

#endif // ST13GLINKCOLOSSUS_HPP
