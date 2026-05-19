#include "Develop/Projects/SR2/pgm/src/Debug/ModelViewer.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleLayer.hpp"

class clsModelViewerCamera;
class clsModelViewerLight;

f32 g_f32LayerCountModelViewer;
u32 m_tu32TypeFlag;
u32 m_tu32DrawFlag;
f32 m_tf32MotionFrame;
s16 m_ts16Hide1NodeNo;
s16 m_ts16Draw1NodeNo;
s16 m_ts16RotY;
s16 m_ts16RotAddY;
s8 m_ts8FixNode;
s8 m_ts8HideNodeCnt;
u32 m_tu32Alpha;
clsModelViewerCamera* m_pcCamera;
clsModelViewerLight* m_apcLight[8];
static c8* oc8TypeName[6];
