#ifndef GRAVITYACTIONMANAGER_HPP
#define GRAVITYACTIONMANAGER_HPP
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/BaseGravityAction.hpp"

class clsPlayerTask;
class clsAdjustGravityAction_Object;
template <class T>
class clsFlag;

// total size: 0x50
class clsGravityActionManager {
public:
    static f32 t_of32InvalidGCtrlFrame;

    enum enmAction {
        ACTION_NULL = 0,
        ACTION_DIVE = 1,
        ACTION_CTRL = 2,
        MAX_ACTION_NUM = 3,
    };

    enum enmType {
        TYPE_FRONT = 0,
        TYPE_BACK = 1,
    };

    enum enmSoundStatus {
        SOUND_STATUS_NULL = 0,
        SOUND_STATUS_START = 1,
        SOUND_STATUS_CANCEL = 2,
        SOUND_STATUS_MOVE = 3,
        SOUND_STATUS_END = 4,
    };

    enum enmActionStatus {
        ACTION_STATUS_NULL = 0,
        ACTION_STATUS_INIT = 1,
        ACTION_STATUS_READY = 2,
        ACTION_STATUS_START = 3,
        ACTION_STATUS_MOVE = 4,
        ACTION_STATUS_FALL = 5,
    };

    enum enmFlag {};

    clsPlayerTask* m_pcPlayer;                              // offset 0x0, size 0x4
    hkSimpleShapePhantom* m_pcPhantom;                      // offset 0x4, size 0x4
    clsBaseGravityAction* m_pcActions[3];                   // offset 0x8, size 0xC
    clsAdjustGravityAction_Object* m_pcAdjustGravityAction; // offset 0x14, size 0x4
    enmAction m_eAction;                                    // offset 0x18, size 0x4
    enmType m_eType;                                        // offset 0x1C, size 0x4
    enmSoundStatus m_eSoundStatus;                          // offset 0x20, size 0x4
    enmActionStatus m_eActionStatus;                        // offset 0x24, size 0x4
    s32 m_cFlag;                                            // offset 0x28, size 0x4
    f32 m_f32Point;                                         // offset 0x2C, size 0x4
    f32 m_f32LinkBonusPoint;                                // offset 0x30, size 0x4
    f32 m_f32DrawPoint;                                     // offset 0x34, size 0x4
    s32 m_s32LinkNum;                                       // offset 0x38, size 0x4
    s32 m_s32BreakNum;                                      // offset 0x3C, size 0x4
    f32 m_f32Radius;                                        // offset 0x40, size 0x4
    f32 m_f32CtrlFrame;                                     // offset 0x44, size 0x4
    f32 m_f32InvalidGCtrlFrame;                             // offset 0x48, size 0x4
    f32 m_f32DefaultInvalidGCtrlFrame;                      // offset 0x4C, size 0x4

    clsGravityActionManager() {}
    clsGravityActionManager(clsPlayerTask* pcPlayer) : m_pcPlayer(pcPlayer) {}
    void setType(enmType eType);
    void update();
    void reset();
    void startSearch(f32 f32Radius);
    void endSearch();
    void updateSearch();
    f32 getTakePoint(f32 f32Point) const;
    void checkLimitPoint();
    void draw();
    void addPoint(f32 f32Param1) { m_f32Point += f32Param1; }
    f32 getPoint() const { return m_f32Point; }
    enmActionStatus getStatus() const { return m_eActionStatus; }
    void setActionStatus(enmActionStatus eParam1) { m_eActionStatus = eParam1; }
    clsFlag<enmFlag>* getFlagRef() { return reinterpret_cast<clsFlag<enmFlag>*>(&m_cFlag); }
    clsPlayerTask* getPlayerTaskPtr() { return m_pcPlayer; }
    void cancel() { m_eActionStatus = ACTION_STATUS_NULL; }
    void setSoundStatus(enmSoundStatus eParam1) { m_eSoundStatus = eParam1; }
    clsBaseGravityAction* getActiveAction() { return m_pcActions[m_eAction]; }
    clsBaseGravityAction* getAction(enmAction eParam1) { return m_pcActions[eParam1]; }
    enmAction getActionType() const { return m_eAction; }
};

#endif // GRAVITYACTIONMANAGER_HPP
