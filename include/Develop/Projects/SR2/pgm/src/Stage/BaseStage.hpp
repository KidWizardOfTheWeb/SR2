#ifndef BASESTAGE_HPP
#define BASESTAGE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Portal.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path/PathCourse.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path/PathCom.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path/PathPoint.hpp"

struct stcBinDataDetail;
class clsRainDrops_Task;
class clsColorDrops_Task;
class clsLap;

// total size: 0x2C4
struct stcEtcBinaryStageData {
    u8 u8Bg___r_Top;                    // offset 0x0, size 0x1
    u8 u8Bg___g;                        // offset 0x1, size 0x1
    u8 u8Bg___b;                        // offset 0x2, size 0x1
    u8 u8Bg___a;                        // offset 0x3, size 0x1
    f32 f32Clip___Near_1View_Top;       // offset 0x4, size 0x4
    f32 f32Clip___Far__1View;           // offset 0x8, size 0x4
    f32 f32Clip___Near_2View;           // offset 0xC, size 0x4
    f32 f32Clip___Far__2View;           // offset 0x10, size 0x4
    f32 f32Clip___Near_3View;           // offset 0x14, size 0x4
    f32 f32Clip___Far__3View;           // offset 0x18, size 0x4
    f32 f32Clip___Near_4View;           // offset 0x1C, size 0x4
    f32 f32Clip___Far__4View;           // offset 0x20, size 0x4
    f32 f32Fog___Near0_Top;             // offset 0x24, size 0x4
    f32 f32Fog___Far0;                  // offset 0x28, size 0x4
    f32 f32Fog___r0;                    // offset 0x2C, size 0x4
    f32 f32Fog___g0;                    // offset 0x30, size 0x4
    f32 f32Fog___b0;                    // offset 0x34, size 0x4
    f32 f32Fog___InertiaK0;             // offset 0x38, size 0x4
    f32 f32Fog___Near1;                 // offset 0x3C, size 0x4
    f32 f32Fog___Far1;                  // offset 0x40, size 0x4
    f32 f32Fog___r1;                    // offset 0x44, size 0x4
    f32 f32Fog___g1;                    // offset 0x48, size 0x4
    f32 f32Fog___b1;                    // offset 0x4C, size 0x4
    f32 f32Fog___InertiaK1;             // offset 0x50, size 0x4
    f32 f32Fog___Near2;                 // offset 0x54, size 0x4
    f32 f32Fog___Far2;                  // offset 0x58, size 0x4
    f32 f32Fog___r2;                    // offset 0x5C, size 0x4
    f32 f32Fog___g2;                    // offset 0x60, size 0x4
    f32 f32Fog___b2;                    // offset 0x64, size 0x4
    f32 f32Fog___InertiaK2;             // offset 0x68, size 0x4
    f32 f32Fog___Near3;                 // offset 0x6C, size 0x4
    f32 f32Fog___Far3;                  // offset 0x70, size 0x4
    f32 f32Fog___r3;                    // offset 0x74, size 0x4
    f32 f32Fog___g3;                    // offset 0x78, size 0x4
    f32 f32Fog___b3;                    // offset 0x7C, size 0x4
    f32 f32Fog___InertiaK3;             // offset 0x80, size 0x4
    f32 f32Fog___Near4;                 // offset 0x84, size 0x4
    f32 f32Fog___Far4;                  // offset 0x88, size 0x4
    f32 f32Fog___r4;                    // offset 0x8C, size 0x4
    f32 f32Fog___g4;                    // offset 0x90, size 0x4
    f32 f32Fog___b4;                    // offset 0x94, size 0x4
    f32 f32Fog___InertiaK4;             // offset 0x98, size 0x4
    f32 f32Fog___Near5;                 // offset 0x9C, size 0x4
    f32 f32Fog___Far5;                  // offset 0xA0, size 0x4
    f32 f32Fog___r5;                    // offset 0xA4, size 0x4
    f32 f32Fog___g5;                    // offset 0xA8, size 0x4
    f32 f32Fog___b5;                    // offset 0xAC, size 0x4
    f32 f32Fog___InertiaK5;             // offset 0xB0, size 0x4
    f32 f32Fog___Near6;                 // offset 0xB4, size 0x4
    f32 f32Fog___Far6;                  // offset 0xB8, size 0x4
    f32 f32Fog___r6;                    // offset 0xBC, size 0x4
    f32 f32Fog___g6;                    // offset 0xC0, size 0x4
    f32 f32Fog___b6;                    // offset 0xC4, size 0x4
    f32 f32Fog___InertiaK6;             // offset 0xC8, size 0x4
    f32 f32Sky___RotNode1_Top;          // offset 0xCC, size 0x4
    f32 f32Sky___RotNode2;              // offset 0xD0, size 0x4
    f32 f32Sky___RotNode3;              // offset 0xD4, size 0x4
    f32 f32Lit___AmbientR0_Top;         // offset 0xD8, size 0x4
    f32 f32Lit___AmbientG0;             // offset 0xDC, size 0x4
    f32 f32Lit___AmbientB0;             // offset 0xE0, size 0x4
    f32 f32Lit___ParallelR0;            // offset 0xE4, size 0x4
    f32 f32Lit___ParallelG0;            // offset 0xE8, size 0x4
    f32 f32Lit___ParallelB0;            // offset 0xEC, size 0x4
    f32 f32Lit___ParallelA0;            // offset 0xF0, size 0x4
    f32 f32Lit___ParallelInten0;        // offset 0xF4, size 0x4
    f32 f32Lit___ParallelDirX0;         // offset 0xF8, size 0x4
    f32 f32Lit___ParallelDirY0;         // offset 0xFC, size 0x4
    f32 f32Lit___ParallelDirZ0;         // offset 0x100, size 0x4
    f32 f32Lit___ParallelPosX0;         // offset 0x104, size 0x4
    f32 f32Lit___ParallelPosY0;         // offset 0x108, size 0x4
    f32 f32Lit___ParallelPosZ0;         // offset 0x10C, size 0x4
    f32 f32Lit___SpecularR0;            // offset 0x110, size 0x4
    f32 f32Lit___SpecularG0;            // offset 0x114, size 0x4
    f32 f32Lit___SpecularB0;            // offset 0x118, size 0x4
    f32 f32Lit___SpecularA0;            // offset 0x11C, size 0x4
    f32 f32Lit___SpecularDirX0;         // offset 0x120, size 0x4
    f32 f32Lit___SpecularDirY0;         // offset 0x124, size 0x4
    f32 f32Lit___SpecularDirZ0;         // offset 0x128, size 0x4
    f32 f32Lit___AmbientR1;             // offset 0x12C, size 0x4
    f32 f32Lit___AmbientG1;             // offset 0x130, size 0x4
    f32 f32Lit___AmbientB1;             // offset 0x134, size 0x4
    f32 f32Lit___ParallelR1;            // offset 0x138, size 0x4
    f32 f32Lit___ParallelG1;            // offset 0x13C, size 0x4
    f32 f32Lit___ParallelB1;            // offset 0x140, size 0x4
    f32 f32Lit___ParallelA1;            // offset 0x144, size 0x4
    f32 f32Lit___ParallelInten1;        // offset 0x148, size 0x4
    f32 f32Lit___ParallelDirX1;         // offset 0x14C, size 0x4
    f32 f32Lit___ParallelDirY1;         // offset 0x150, size 0x4
    f32 f32Lit___ParallelDirZ1;         // offset 0x154, size 0x4
    f32 f32Lit___ParallelPosX1;         // offset 0x158, size 0x4
    f32 f32Lit___ParallelPosY1;         // offset 0x15C, size 0x4
    f32 f32Lit___ParallelPosZ1;         // offset 0x160, size 0x4
    f32 f32Lit___SpecularR1;            // offset 0x164, size 0x4
    f32 f32Lit___SpecularG1;            // offset 0x168, size 0x4
    f32 f32Lit___SpecularB1;            // offset 0x16C, size 0x4
    f32 f32Lit___SpecularA1;            // offset 0x170, size 0x4
    f32 f32Lit___SpecularDirX1;         // offset 0x174, size 0x4
    f32 f32Lit___SpecularDirY1;         // offset 0x178, size 0x4
    f32 f32Lit___SpecularDirZ1;         // offset 0x17C, size 0x4
    f32 f32Lit___AmbientR2;             // offset 0x180, size 0x4
    f32 f32Lit___AmbientG2;             // offset 0x184, size 0x4
    f32 f32Lit___AmbientB2;             // offset 0x188, size 0x4
    f32 f32Lit___ParallelR2;            // offset 0x18C, size 0x4
    f32 f32Lit___ParallelG2;            // offset 0x190, size 0x4
    f32 f32Lit___ParallelB2;            // offset 0x194, size 0x4
    f32 f32Lit___ParallelA2;            // offset 0x198, size 0x4
    f32 f32Lit___ParallelInten2;        // offset 0x19C, size 0x4
    f32 f32Lit___ParallelDirX2;         // offset 0x1A0, size 0x4
    f32 f32Lit___ParallelDirY2;         // offset 0x1A4, size 0x4
    f32 f32Lit___ParallelDirZ2;         // offset 0x1A8, size 0x4
    f32 f32Lit___ParallelPosX2;         // offset 0x1AC, size 0x4
    f32 f32Lit___ParallelPosY2;         // offset 0x1B0, size 0x4
    f32 f32Lit___ParallelPosZ2;         // offset 0x1B4, size 0x4
    f32 f32Lit___SpecularR2;            // offset 0x1B8, size 0x4
    f32 f32Lit___SpecularG2;            // offset 0x1BC, size 0x4
    f32 f32Lit___SpecularB2;            // offset 0x1C0, size 0x4
    f32 f32Lit___SpecularA2;            // offset 0x1C4, size 0x4
    f32 f32Lit___SpecularDirX2;         // offset 0x1C8, size 0x4
    f32 f32Lit___SpecularDirY2;         // offset 0x1CC, size 0x4
    f32 f32Lit___SpecularDirZ2;         // offset 0x1D0, size 0x4
    f32 f32Lit___AmbientR3;             // offset 0x1D4, size 0x4
    f32 f32Lit___AmbientG3;             // offset 0x1D8, size 0x4
    f32 f32Lit___AmbientB3;             // offset 0x1DC, size 0x4
    f32 f32Lit___ParallelR3;            // offset 0x1E0, size 0x4
    f32 f32Lit___ParallelG3;            // offset 0x1E4, size 0x4
    f32 f32Lit___ParallelB3;            // offset 0x1E8, size 0x4
    f32 f32Lit___ParallelA3;            // offset 0x1EC, size 0x4
    f32 f32Lit___ParallelInten3;        // offset 0x1F0, size 0x4
    f32 f32Lit___ParallelDirX3;         // offset 0x1F4, size 0x4
    f32 f32Lit___ParallelDirY3;         // offset 0x1F8, size 0x4
    f32 f32Lit___ParallelDirZ3;         // offset 0x1FC, size 0x4
    f32 f32Lit___ParallelPosX3;         // offset 0x200, size 0x4
    f32 f32Lit___ParallelPosY3;         // offset 0x204, size 0x4
    f32 f32Lit___ParallelPosZ3;         // offset 0x208, size 0x4
    f32 f32Lit___SpecularR3;            // offset 0x20C, size 0x4
    f32 f32Lit___SpecularG3;            // offset 0x210, size 0x4
    f32 f32Lit___SpecularB3;            // offset 0x214, size 0x4
    f32 f32Lit___SpecularA3;            // offset 0x218, size 0x4
    f32 f32Lit___SpecularDirX3;         // offset 0x21C, size 0x4
    f32 f32Lit___SpecularDirY3;         // offset 0x220, size 0x4
    f32 f32Lit___SpecularDirZ3;         // offset 0x224, size 0x4
    f32 f32Lit___AmbientR4;             // offset 0x228, size 0x4
    f32 f32Lit___AmbientG4;             // offset 0x22C, size 0x4
    f32 f32Lit___AmbientB4;             // offset 0x230, size 0x4
    f32 f32Lit___ParallelR4;            // offset 0x234, size 0x4
    f32 f32Lit___ParallelG4;            // offset 0x238, size 0x4
    f32 f32Lit___ParallelB4;            // offset 0x23C, size 0x4
    f32 f32Lit___ParallelA4;            // offset 0x240, size 0x4
    f32 f32Lit___ParallelInten4;        // offset 0x244, size 0x4
    f32 f32Lit___ParallelDirX4;         // offset 0x248, size 0x4
    f32 f32Lit___ParallelDirY4;         // offset 0x24C, size 0x4
    f32 f32Lit___ParallelDirZ4;         // offset 0x250, size 0x4
    f32 f32Lit___ParallelPosX4;         // offset 0x254, size 0x4
    f32 f32Lit___ParallelPosY4;         // offset 0x258, size 0x4
    f32 f32Lit___ParallelPosZ4;         // offset 0x25C, size 0x4
    f32 f32Lit___SpecularR4;            // offset 0x260, size 0x4
    f32 f32Lit___SpecularG4;            // offset 0x264, size 0x4
    f32 f32Lit___SpecularB4;            // offset 0x268, size 0x4
    f32 f32Lit___SpecularA4;            // offset 0x26C, size 0x4
    f32 f32Lit___SpecularDirX4;         // offset 0x270, size 0x4
    f32 f32Lit___SpecularDirY4;         // offset 0x274, size 0x4
    f32 f32Lit___SpecularDirZ4;         // offset 0x278, size 0x4
    s8 c8IgnoreResidencePortal_0_0_Top; // offset 0x27C, size 0x1
    s8 c8IgnoreResidencePortal_0_1;     // offset 0x27D, size 0x1
    s8 c8IgnoreResidencePortal_0_2;     // offset 0x27E, size 0x1
    s8 c8IgnoreResidencePortal_0_3;     // offset 0x27F, size 0x1
    s8 c8IgnoreResidencePortal_0_4;     // offset 0x280, size 0x1
    s8 c8IgnoreResidencePortal_0_5;     // offset 0x281, size 0x1
    s8 c8IgnoreResidencePortal_0_6;     // offset 0x282, size 0x1
    s8 c8IgnoreResidencePortal_0_7;     // offset 0x283, size 0x1
    s8 c8IgnoreResidencePortal_0_8;     // offset 0x284, size 0x1
    s8 c8IgnoreResidencePortal_0_9;     // offset 0x285, size 0x1
    s8 c8IgnoreResidencePortal_0_10;    // offset 0x286, size 0x1
    s8 c8IgnoreResidencePortal_0_11;    // offset 0x287, size 0x1
    s8 c8IgnoreResidencePortal_0_12;    // offset 0x288, size 0x1
    s8 c8IgnoreResidencePortal_0_13;    // offset 0x289, size 0x1
    s8 c8IgnoreResidencePortal_0_14;    // offset 0x28A, size 0x1
    s8 c8IgnoreResidencePortal_0_15;    // offset 0x28B, size 0x1
    s8 c8IgnoreResidencePortal_0_16;    // offset 0x28C, size 0x1
    s8 c8IgnoreResidencePortal_0_17;    // offset 0x28D, size 0x1
    s8 c8IgnoreResidencePortal_1_0;     // offset 0x28E, size 0x1
    s8 c8IgnoreResidencePortal_1_1;     // offset 0x28F, size 0x1
    s8 c8IgnoreResidencePortal_1_2;     // offset 0x290, size 0x1
    s8 c8IgnoreResidencePortal_1_3;     // offset 0x291, size 0x1
    s8 c8IgnoreResidencePortal_1_4;     // offset 0x292, size 0x1
    s8 c8IgnoreResidencePortal_1_5;     // offset 0x293, size 0x1
    s8 c8IgnoreResidencePortal_1_6;     // offset 0x294, size 0x1
    s8 c8IgnoreResidencePortal_1_7;     // offset 0x295, size 0x1
    s8 c8IgnoreResidencePortal_1_8;     // offset 0x296, size 0x1
    s8 c8IgnoreResidencePortal_1_9;     // offset 0x297, size 0x1
    s8 c8IgnoreResidencePortal_1_10;    // offset 0x298, size 0x1
    s8 c8IgnoreResidencePortal_1_11;    // offset 0x299, size 0x1
    s8 c8IgnoreResidencePortal_1_12;    // offset 0x29A, size 0x1
    s8 c8IgnoreResidencePortal_1_13;    // offset 0x29B, size 0x1
    s8 c8IgnoreResidencePortal_1_14;    // offset 0x29C, size 0x1
    s8 c8IgnoreResidencePortal_1_15;    // offset 0x29D, size 0x1
    s8 c8IgnoreResidencePortal_1_16;    // offset 0x29E, size 0x1
    s8 c8IgnoreResidencePortal_1_17;    // offset 0x29F, size 0x1
    s8 c8IgnoreResidencePortal_2_0;     // offset 0x2A0, size 0x1
    s8 c8IgnoreResidencePortal_2_1;     // offset 0x2A1, size 0x1
    s8 c8IgnoreResidencePortal_2_2;     // offset 0x2A2, size 0x1
    s8 c8IgnoreResidencePortal_2_3;     // offset 0x2A3, size 0x1
    s8 c8IgnoreResidencePortal_2_4;     // offset 0x2A4, size 0x1
    s8 c8IgnoreResidencePortal_2_5;     // offset 0x2A5, size 0x1
    s8 c8IgnoreResidencePortal_2_6;     // offset 0x2A6, size 0x1
    s8 c8IgnoreResidencePortal_2_7;     // offset 0x2A7, size 0x1
    s8 c8IgnoreResidencePortal_2_8;     // offset 0x2A8, size 0x1
    s8 c8IgnoreResidencePortal_2_9;     // offset 0x2A9, size 0x1
    s8 c8IgnoreResidencePortal_2_10;    // offset 0x2AA, size 0x1
    s8 c8IgnoreResidencePortal_2_11;    // offset 0x2AB, size 0x1
    s8 c8IgnoreResidencePortal_2_12;    // offset 0x2AC, size 0x1
    s8 c8IgnoreResidencePortal_2_13;    // offset 0x2AD, size 0x1
    s8 c8IgnoreResidencePortal_2_14;    // offset 0x2AE, size 0x1
    s8 c8IgnoreResidencePortal_2_15;    // offset 0x2AF, size 0x1
    s8 c8IgnoreResidencePortal_2_16;    // offset 0x2B0, size 0x1
    s8 c8IgnoreResidencePortal_2_17;    // offset 0x2B1, size 0x1
    s8 c8IgnoreResidencePortal_3_0;     // offset 0x2B2, size 0x1
    s8 c8IgnoreResidencePortal_3_1;     // offset 0x2B3, size 0x1
    s8 c8IgnoreResidencePortal_3_2;     // offset 0x2B4, size 0x1
    s8 c8IgnoreResidencePortal_3_3;     // offset 0x2B5, size 0x1
    s8 c8IgnoreResidencePortal_3_4;     // offset 0x2B6, size 0x1
    s8 c8IgnoreResidencePortal_3_5;     // offset 0x2B7, size 0x1
    s8 c8IgnoreResidencePortal_3_6;     // offset 0x2B8, size 0x1
    s8 c8IgnoreResidencePortal_3_7;     // offset 0x2B9, size 0x1
    s8 c8IgnoreResidencePortal_3_8;     // offset 0x2BA, size 0x1
    s8 c8IgnoreResidencePortal_3_9;     // offset 0x2BB, size 0x1
    s8 c8IgnoreResidencePortal_3_10;    // offset 0x2BC, size 0x1
    s8 c8IgnoreResidencePortal_3_11;    // offset 0x2BD, size 0x1
    s8 c8IgnoreResidencePortal_3_12;    // offset 0x2BE, size 0x1
    s8 c8IgnoreResidencePortal_3_13;    // offset 0x2BF, size 0x1
    s8 c8IgnoreResidencePortal_3_14;    // offset 0x2C0, size 0x1
    s8 c8IgnoreResidencePortal_3_15;    // offset 0x2C1, size 0x1
    s8 c8IgnoreResidencePortal_3_16;    // offset 0x2C2, size 0x1
    s8 c8IgnoreResidencePortal_3_17;    // offset 0x2C3, size 0x1
};

// total size: 0x140
class clsBaseStage_Task : public clsTask {
public:
    clsBaseStage_Task(stcBinInfo& rsBinInfoI);
    virtual ~clsBaseStage_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();
    virtual s32 getDivNum() const { return 0; }
    virtual void init();
    virtual clsLap* createLap() { return 0; }
    virtual void initMain();
    virtual clsPathCourse* createCoursePath() { return 0; }

    void calcCamCoursePoint(u32 u32v, clsRetPath* pcRetCoursePath);
    void setObjPortalBin(stcBinInfo& rsBinInfoI);
    void setEtcParam(stcBinInfo& rsBinInfoI);

    bool checkObjPortal(u32 u32v, u8 u8v) { return false; }
    clsPathCourse* getCoursePathPtr() { return m_pcCoursePath; }
    void deleteColorViewDetail(u8 u8v) {}
    void addColorDropsEffect(u32 u32a, u32 u32b, u32 u32c, f32 f32v, u32 u32d) {}
    bool getCurrentObjPortal(u32 u32v) const { return false; }
    void addRainDropsEffect(u32 u32a, u32 u32b, u32 u32c, f32 f32v) {}
    clsPathCom& getComPathRef() { return m_cComPath; }
    u8* getShimmerEffect_p() { return m_abShimmer; }

    clsModelType_OB_TX_MO_MA m_cModel;              // offset 0x54, size 0x20
    clsPortal m_cObjPortal_Camera;                  // offset 0x74, size 0x50
    clsPortal m_cObjPortal_Player;                  // offset 0xC4, size 0x50
    clsPathCourse* m_pcCoursePath;                  // offset 0x114, size 0x4
    clsPathCom m_cComPath;                          // offset 0x118, size 0x14
    stcBinDataDetail* m_opsBinDataDetail_Fog;       // offset 0x12C, size 0x4
    clsRainDrops_Task* m_pcRainDrops_Task;          // offset 0x130, size 0x4
    clsColorDrops_Task* m_pcColorDrops_Task;        // offset 0x134, size 0x4
    u8 m_abShimmer[4];                              // offset 0x138, size 0x4
    stcEtcBinaryStageData* m_opsEtcBinaryStageData; // offset 0x13C, size 0x4
};

#endif // BASESTAGE_HPP
