#include "Develop/Projects/SR2/pgm/src/Script/Script2D.hpp"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnFontSystem.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/IonMist/IonMist.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalMessage/SurvivalMessageSet.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Mission/Mission2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalBattle/SurvivalBattleParts2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/WinLose2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreSet.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/PathData.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/GlobalData.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/MissionRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/BaseStage.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/DivStage.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage07.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11FogNearManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11Fade.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/MapBurnLight.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/BaseSky.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Sky09.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Sound/SetSe_3D.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Sound/SetSe_2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Ring.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Spring.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/StartGate.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/GoalLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Type.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PT_Door.hpp"

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PT_Door2.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PT_Only.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutMatMotGObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj2.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutParallaxObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PutGravityObj3.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutArrowObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutMotionObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/WallObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Turbulence.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/Catapult.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PathGravityObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/GravityRing.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/HideKicker.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/WallGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PlayAroundSe.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/AdjustGravityAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PlayLoopSe.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/AutoGCtrlThrough.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/MagBarrier.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/RailWay.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/SpeedDown.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PathCar.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutCar.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GLinkTrain/GLinkTrainTask.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/PathTrain/PathTrainManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/ProductionRobo/ProductionRoboManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/Taxi.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/Chair.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/ChairB.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GarbageBox.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/BulletinBoard.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/St01Cone.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GCtrTrain/GCtrTrainManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Ivy.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Bee.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02GLinkKuki.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Plant.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Plant2.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Sida.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02PathBee.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Butterfly.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02RunBee.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03Cogwheel.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03Press.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03ExtraLamp.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03PutRobo.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03GLinkContainer.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03SecurityGate.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03PowerBreak.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03Macross.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage03/St03PathRobo.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04AutoRunCanoe.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04GLinkWaterSphere.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04Fountain.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04StraightFountain.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04PathCanoe.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04PutCanoe.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage04/St04SmallWaterSphere.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotGround.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotFall/St05RotFallTask.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05Fire.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05Spain.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05Domino.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05RotFallGLink/St05RotFallGLinkTask.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05Detention.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage05/St05BreakRailing.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage06/St06SurveillanceCamera.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage06/St06BlockadeObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage06/St06Laser.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage06/St06GLinkElevator.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage06/St06Elevator.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorSmall.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorBig.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorSwitch.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorChange.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorKicker.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/SvlBtlMapPartsFloorGravity.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorGravity.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsFloorGLink.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsJointSmall.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsJointCurve.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsJointBig.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsJointSharp.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsGuardRailSmall.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsGuardRailCurve.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsGimmickWallSmall.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsGimmickWallBig.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07Gate.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07WallThroughCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07PowerBreak.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07Solar.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08Road.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadSignal.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadCar.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadGlinkBus.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08RoadTrailer/St08RoadTrailer.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08UfoCatcher.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage08/St08FZoneEnemy/St08FZoneEnemy.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage10/St10SnowBall.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage10/St10FallSnowBall.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage10/St10GLinkSnowman.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage10/St10Lift.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11EnergyCylinder.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11FSecurityGate.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/st11SecurityRoboManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11Fan.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11Crane.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/GlinkCylinder/St11GlinkCylinder.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage11/St11LineObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage12/St12GLinkBridge.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage12/St12PutCanoeMotion.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage12/St12PathCanoeMotion.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage12/St12MotionObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13bunki.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13Catapult.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13Colossus.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13GLinkColossus.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13Bridge.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13Gate.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13Pillar.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13PT_Obj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13Hikari.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13SignBoard.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13SignBoard_B.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage13/St13PT_Wall.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14GPFan.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14ObjCrane.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14Laser.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14GLinkBigFan.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage14/St14SteelFrame.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15CoreBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15FusionMachine.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15GLinkFloorBoard.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15BreakFloor.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15FloatingMeteorite.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15FloatingMeteoriteTirgger.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage15/St15SafeTrampoline.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage16/St16Helicopter/St16Helicopter.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage16/St16GLinkSignBoard.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage16/St16BreakSignBoard.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage16/St16AutoRunHeli.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionPathTarget.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionTimeGate.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionMark.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionPathRobo.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionFixedLink.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Mission/MissionGLinkColossus.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalPointRing.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalBall.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalPole.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalStart.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBall/SurvivalPutObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalRelay/SurvivalWalkRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/Missile/SvlBtlMissileTask.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/Bomb/SvlBtlBombTask.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/SvlBtlBlock.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/SvlBtlPaul.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/SvlBtlBarrier.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalBattle/SvlBtlExplosion.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/SunLenz.hpp"
#include "Develop/Projects/SR2/pgm/src/Camera/SetCamColli.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutFixedMatObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutFixedMotObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutFixedMotMatObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutFixedBurnObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutFixedObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/BaseRace.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/Game.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/SurvivalRelayPlayer.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOStl.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOFlag.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOTaskManager.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Heap.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleData.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleLayer.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Score2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil_PS2.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GameData.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GearData.hpp"
#include "usr/local/sce/ee/lib/libkernl/kprintf2.h"
#include "macros.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Keyboard2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalBall/SurvivalBall2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/SurvivalBattle/SurvivalBattleMap2D.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/BackRibbon/BackRibbon.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/DisElectric.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/MiniWave/MiniWave.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/TimeAttack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/DashPanel.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/DashRing.hpp"
#include "Develop/Projects/SR2/pgm/src/Advertise/AdvertiseMgr.hpp"
#include "Develop/Projects/SR2/pgm/src/System/IO/SR2_MemoryCardFile.hpp"

#include "Develop/Projects/SR2/pgm/src/Stage/Stage00.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage01.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage02.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage03.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage04.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage05.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage06.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage08.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage09.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage10.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage11.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage12.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage13.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage14.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage15.hpp"
#include "Develop/Projects/SR2/pgm/src/Stage/Stage16.hpp"

#include "Develop/Projects/SR2/pgm/src/Game/TutorialRace.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreMap2D.hpp"

#include "Develop/Projects/SR2/pgm/src/Effect/LockOn/LockOnFixed3D.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/LockOn/LockOnAppoint3D.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBomb.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Ghost.hpp"

#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/CharaData.hpp"

#include "Develop/Projects/SR2/pgm/src/System/SrFontSystem.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/PS2_ShadowVolume.hpp"

#include "Develop/Projects/SR2/pgm/src/Script/Script.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptCamera.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptModelManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptWaitString.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptShadow.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptMotion.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptEffect.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptLight.hpp"

#include "usr/local/sce/ee/gcc/ee/lib/libc/memcpy.h"

namespace nspFly {
static const f32 FLYACTION_MIN_PITCH = 5461.0f;
static const f32 FLYACTION_MAX_PITCH = 5461.0f;
static const f32 FLYACTION_LEFT_RIGHT_ROT = 127.0f;
static const f32 FLYACTION_UP_DOWN_ROT = 127.0f;
static const f32 FLYACTION_DESCENT_PITCH_GRAVITY = 127.0f;
static const f32 FLYACTION_FALL_PITCH_GRAVITY = 9.0f;
static const f32 FLYACTION_DEFAULT_PITCH_GRAVITY = 25.0f;
} // namespace nspFly

namespace nspNnModelType {
static u32 BIT_DIV_MAP = 0x40;
static u32 BIT_OBJECT = 0x1;
static u32 BIT_TEXTURE = 0x2;
static u32 BIT_MOTION = 0x4;
static u32 BIT_MATMOTOBJ = 0x8;
static u32 BIT_MORPHOBJ = 0x10;
static u32 BIT_MORPHTARGETLIST = 0x20;
} // namespace nspNnModelType

c8* clsPack::getFileName(nspPackId::enm eTypeIdI, s32 s32No0I, s32 s32No1I, s32 s32No2I)
{
    u32 u32MotNo;
    static c8 tac8Name[64];

    switch (eTypeIdI) {
    case nspPackId::MAP_100:
        s32No1I += (s32No1I == 3);
        sceSnprintf(tac8Name, 64, "%02d_%01dV.p", s32No0I, s32No1I);
        break;

    case nspPackId::MAP_MISSION_101:
        sceSnprintf(tac8Name, 64, "VOL2:M%02d_%02d.p", s32No0I, s32No1I);
        break;

    case nspPackId::MAP_SURVIVALBALL_102:
        s32No1I += (s32No1I == 3);
        sceSnprintf(tac8Name, 64, "VOL2:SB%02d_%01dV.p", s32No0I, s32No1I);
        break;

    case nspPackId::MAP_TUTORIAL_103:
        sceSnprintf(tac8Name, 64, "T%02d.p", s32No0I);
        break;

    case nspPackId::MAP_SURVIVALBATTLE_104:
        s32No1I += (s32No1I == 3);
        sceSnprintf(tac8Name, 64, "VOL2:BA%02d_%01dV.p", s32No0I, s32No1I);
        break;

    case nspPackId::MAP_SURVIVALRELAY_105:
        sceSnprintf(tac8Name, 64, "VOL2:SR%02d_%01dU.p", s32No0I, s32No1I);
        break;

    case nspPackId::CHARA_0: {
        static c8* pu8CharaName[20] = {
            "CS", "CT", "CK", "CA", "CJ", "CO", "CW", "CE", "CC", "CR",
            "CD", "CB", "CI", "CN", "CG", "CY", "CP", "CH", "CU", "C2",
        };
        static c8* pu8ModelTypeName[6] = {"DEF", "ADS", "CVS", "RLL", "SNB", "WTD"};

        if (clsGameMgr::GS()->getGameMode() == clsGameMgr::GAME_MODE___STORY && s32No0I == 3) {
            s32No0I = 19;
        }
        sceSnprintf(tac8Name, 64, "%s%s_1v.p", pu8CharaName[s32No0I], pu8ModelTypeName[s32No1I]);
        break;
    }

    case nspPackId::ENTRY_CHARA_1: {
        static c8* pu8CharaName[19] = {
            "CS", "CT", "CK", "CA", "CJ", "CO", "CW", "CE", "CC", "CR",
            "CD", "CB", "CI", "CN", "CG", "CY", "CP", "CH", "CU",
        };
        static c8* pu8ModelTypeName[6] = {"DEF", "ADS", "CVS", "RLL", "SNB", "WTD"};

        sceSnprintf(tac8Name, 64, "E%s%s_1v.p", pu8CharaName[s32No0I], pu8ModelTypeName[s32No1I]);
        break;
    }

    case nspPackId::GEAR_10:
        sceSnprintf(tac8Name, 64, "%s", nspGear::getGearCtrlBinName(s32No0I));
        break;

    case nspPackId::ENTRY_GEAR_11:
        sceSnprintf(tac8Name, 64, "E%s", nspGear::getGearCtrlBinName(s32No0I));
        break;

    case nspPackId::NETRANKING_2D_1031:
        sceSnprintf(tac8Name,
                    64,
                    "NRNK_%c.p",
                    clsOOSystem::m_toac8LanguagePreFix[clsPfSystem::GS()->getMessageLanguage()]);
        break;

    case nspPackId::TIMEATTACK_2D_1033:
        sceSnprintf(tac8Name,
                    64,
                    "TATKT_%c.p",
                    clsOOSystem::m_toac8LanguagePreFix[clsPfSystem::GS()->getMessageLanguage()]);
        break;

    case nspPackId::SCRIPT_FONT_DATA_37520:
        sceSnprintf(tac8Name,
                    64,
                    "E%dL%c",
                    s32No0I,
                    clsOOSystem::m_toac8LanguagePreFix[clsPfSystem::GS()->getMessageLanguage()]);
        break;

    case nspPackId::TITLE_SELECT_50000:
        sceSnprintf(tac8Name, 64, "TS%cA.p", clsOOSystem::m_toac8LanguagePreFix[s32No0I]);
        break;

    case nspPackId::FONT_DATA_50010:
        sceSnprintf(tac8Name,
                    64,
                    "FNT%c%d.p",
                    clsOOSystem::m_toac8LanguagePreFix[clsPfSystem::GS()->getMessageLanguage()],
                    s32No0I);
        break;

    case nspPackId::FONT_MISSION_DATA_50020:
        sceSnprintf(tac8Name,
                    64,
                    "FNT_M%c.p",
                    clsOOSystem::m_toac8LanguagePreFix[clsPfSystem::GS()->getMessageLanguage()]);
        break;

    case nspPackId::FONT_MENUDATA_50030:
        sceSnprintf(tac8Name, 64, "FNT%cMN.p", clsOOSystem::m_toac8LanguagePreFix[s32No0I]);
        break;

    case nspPackId::FONT_USERNAME_DATA_50040:
        sceSnprintf(tac8Name, 64, "FNTENM.p");
        break;

    case nspPackId::FONT_BTN_DATA_50050:
        sceSnprintf(tac8Name, 64, "BTNTEX.p");
        break;

    case nspPackId::FONT__DATA_PECULIAR_50060:
        sceSnprintf(tac8Name,
                    64,
                    "FNTPEC%c.p",
                    clsOOSystem::m_toac8LanguagePreFix[clsPfSystem::GS()->getMessageLanguage()]);
        break;

    case nspPackId::TITLE_FLASH_52045:
        sceSnprintf(tac8Name, 64, "TS%c.p", clsOOSystem::m_toac8LanguagePreFix[s32No0I]);
        break;

    case nspPackId::ADVERTISE_FLASH_DATA_52005:
        sceSnprintf(tac8Name, 64, "MMU.p");
        break;

    case nspPackId::CHARACTER_SELECT_FLASH_52025:
        sceSnprintf(tac8Name, 64, "PE%c.p", clsOOSystem::m_toac8LanguagePreFix[s32No0I]);
        break;

    case nspPackId::MAIN_MENU_SELECT_FLASHTEX_52030:
        sceSnprintf(tac8Name, 64, "MMS%cA.p", clsOOSystem::m_toac8LanguagePreFix[s32No0I]);
        break;

    case nspPackId::MAIN_MENU_SELECT_FLASH_52035:
        sceSnprintf(tac8Name, 64, "MMS%c.p", clsOOSystem::m_toac8LanguagePreFix[s32No0I]);
        break;

    case nspPackId::TITLE_LOGO_52100:
        sceSnprintf(tac8Name, 64, "LGUS.p");
        break;

    case nspPackId::EXTRA_MENU_SELECT_FLASHTEX_52080:
        sceSnprintf(tac8Name, 64, "EXM%cA.p", clsOOSystem::m_toac8LanguagePreFix[s32No0I]);
        break;

    case nspPackId::EXTRA_MENU_SELECT_FLASH_52085:
        sceSnprintf(tac8Name, 64, "EXM%c.p", clsOOSystem::m_toac8LanguagePreFix[s32No0I]);
        break;

    case nspPackId::EXTRA_MENU_UNION_FLASH_52086:
        sceSnprintf(tac8Name, 64, "EXU.p");
        break;

    case nspPackId::OPTION_MENU_SELECT_FLASHTEX_52090:
        sceSnprintf(tac8Name, 64, "OPM.p");
        break;

    case nspPackId::OPTION_MENU_BACK_FLASH_52098:
        sceSnprintf(tac8Name, 64, "OPU.p");
        break;

    case nspPackId::OPTION_MENU_SELECT_FLASH_52099:
        sceSnprintf(tac8Name, 64, "OPUL.p");
        break;

    case nspPackId::SAVEDATA_52110:
    case nspPackId::SAVEDATA_52111:
    case nspPackId::SAVEDATA_52112:
    case nspPackId::SAVEDATA_52113:
    case nspPackId::SAVEDATA_52114:
    case nspPackId::SAVEDATA_52115:
        s32No0I = eTypeIdI - nspPackId::SAVEDATA_52110;
        sceSnprintf(tac8Name, 64, "SAVE2D%c.p", clsOOSystem::m_toac8LanguagePreFix[s32No0I]);
        break;

    case nspPackId::SHOPDATA_52120:
        sceSnprintf(tac8Name,
                    64,
                    "SHOP%c.p",
                    clsOOSystem::m_toac8LanguagePreFix[clsPfSystem::GS()->getMessageLanguage()]);
        break;

    case nspPackId::GEARGALLERY_52150:
        sceSnprintf(tac8Name,
                    64,
                    "EXGRY%c.p",
                    clsOOSystem::m_toac8LanguagePreFix[clsPfSystem::GS()->getMessageLanguage()]);
        break;

    case nspPackId::KEYBOARD_2D_53000:
        sceSnprintf(tac8Name,
                    64,
                    "KBD_%c.p",
                    clsOOSystem::m_toac8LanguagePreFix[clsPfSystem::GS()->getMessageLanguage()]);
        break;

    case nspPackId::SAVE_DATA_FILE_53100:
        sceSnprintf(tac8Name, 64, "MC_D.p");
        break;

    case nspPackId::SAVE_DATA_FILE_53101:
        sceSnprintf(tac8Name, 64, "MC_DG%d.p", s32No0I);
        break;

    case nspPackId::___DUMMY__MOTION:
        u32MotNo = static_cast<u32>(s32No0I) & 0xffff;
        if (static_cast<u32>(s32No0I) >> 16) {
            sceSnprintf(tac8Name,
                        64,
                        "VOL2:%s%s.tbl",
                        nspGear::oasMotionGearNameCode2[u32MotNo],
                        reinterpret_cast<c8*>(s32No1I));
        } else {
            sceSnprintf(tac8Name,
                        64,
                        "VOL2:%s%sC.tbl",
                        nspGear::oasMotionGearNameCode2[u32MotNo],
                        reinterpret_cast<c8*>(s32No1I));
        }
        break;

    default:
        break;
    }

    return tac8Name;
}

void clsPack::loadGearModels(u32 u32DataIdx, stcBinInfo& rsBinInfo)
{
    u32* pu32BinOffsets;
    _GearModels& rsModels = nspGame::sGearModelInfo.sGearModels[u32DataIdx];
    u32 u32BinNum = rsBinInfo.s32RestBinNum;
    u8 u8GearDataNum = u32BinNum >> 1;
    pu32BinOffsets = rsBinInfo.opu32OffsetNo;
    u8* pu8BinTopAddr = rsBinInfo.opu8BinTopAddr;

    if (rsModels.u16LoadedNum != 0) {
        SUPER_ASSERT(0x32157845, "Pack.cpp", 885, "すでにロード済み？？\n");
    }

    if (u32BinNum == 0 || (u32BinNum & 1) != 0 || (u32BinNum >> 1) > 9) {
        SUPER_ASSERT(0x32652587, "Pack.cpp", 887, "バイナリ数が異常です。\n");
    }

    u32 u32j = 0;
    do {
        clsModelType_OB_TX& rsModel = rsModels.asModels[rsModels.u16LoadedNum];

        if (rsModels.u16LoadedNum >= 9) {
            SUPER_ASSERT(0x36520124,
                         "Pack.cpp",
                         914,
                         "ギアレベル数をオーバーして読み込もうとしています。\n");
        }

        nspNnUtil::BinSetUpObject(&rsModel.m_psObject, NULL, pu8BinTopAddr + pu32BinOffsets[0]);

        if (pu32BinOffsets[1] != 0) {
            nspNnUtil::BinSetUpTexList_Texture(
                &rsModel.m_psTexList, NULL, pu8BinTopAddr + pu32BinOffsets[1]);
        }

        if (static_cast<u32>(nspNnUtil::ts32MtxPalNum) <
            static_cast<u32>(rsModel.m_psObject->nMtxPal))
        {
            nspNnUtil::ts32MtxPalNum = rsModel.m_psObject->nMtxPal;
        }
        if (static_cast<u32>(nspNnUtil::ts32MtxListNum) <
            static_cast<u32>(rsModel.m_psObject->nNode))
        {
            nspNnUtil::ts32MtxListNum = rsModel.m_psObject->nNode;
        }
        if (static_cast<u32>(nspNnUtil::ts32NodeStatusNum) <
            static_cast<u32>(rsModel.m_psObject->nNode))
        {
            nspNnUtil::ts32NodeStatusNum = rsModel.m_psObject->nNode;
        }
        if (static_cast<u32>(nspNnUtil::ts32TrsNum) < static_cast<u32>(rsModel.m_psObject->nNode)) {
            nspNnUtil::ts32TrsNum = rsModel.m_psObject->nNode;
        }

        pu32BinOffsets += 2;
        ++rsModels.u16LoadedNum;
        ++u32j;
    } while (u32j < u8GearDataNum);
}

inline void clsPack::setPlayerPositionOther(
    oostd::clsOOVector<stcSetDataDetail*, oostd::clsOOStlAllocator<stcSetDataDetail*> >&
        rvctStarPos)

{
    u32 u32PlayerNum = nspGlobal::sTask.pcBaseRace->getPlayerNum();
    u32 u32EntryNum = 0;
    clsPlayerTask** apcPlayer = nspGlobal::sTask.apcPlayer;
    u32 u32GameMode = clsGameMgr::GS()->getGameMode();

    for (;;) {
        switch (u32GameMode) {
        case clsGameMgr::GAME_MODE___SURVIVAL_RELAY:
            apcPlayer[u32EntryNum] = new clsSurvivalRelayPlayerTask(*rvctStarPos.at(u32EntryNum));
            break;
        default:
            apcPlayer[u32EntryNum] = new clsPlayerTask(*rvctStarPos.at(u32EntryNum));
            break;
        }
        ++u32EntryNum;

        if (u32EntryNum >= u32PlayerNum) {
            break;
        }
    }
}

// RECONSTRUCTED: helper name.
inline void clsPack::setPlayerPositionStartGate(
    oostd::clsOOVector<stcSetDataDetail*, oostd::clsOOStlAllocator<stcSetDataDetail*> >&
        rvctStarPos)
{
    // RECONSTRUCTED: local names.
    NNS_VECTOR asStartOffset[12] = {{-2.0f, 0.0f, -50.0f},
                                    {2.0f, 0.0f, -50.0f},
                                    {-6.0f, 0.0f, -50.0f},
                                    {6.0f, 0.0f, -50.0f},
                                    {0.0f, 0.0f, -56.0f},
                                    {4.0f, 0.0f, -56.0f},
                                    {-4.0f, 0.0f, -56.0f},
                                    {-8.0f, 0.0f, -56.0f},
                                    {-2.0f, 0.0f, -50.0f},
                                    {1.0f, 0.0f, -50.0f},
                                    {-5.0f, 0.0f, -50.0f},
                                    {4.0f, 0.0f, -50.0f}};
    clsBaseRace_Task* pcBaseRace = nspGlobal::sTask.pcBaseRace;
    u32 u32PlayerNum = pcBaseRace->getPlayerNum();
    clsPlayerTask** apcPlayer = nspGlobal::sTask.apcPlayer;
    if (clsStartGate_Task::GS() != NULL) {
        stcSetDataDetail sSetData = {
            0, {4}, 0x3f, 0, 0, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 0};
        const stcSetDataDetail* psGateData =
            clsStartGate_Task::GS()->getObject(0)->getSetDataDetail();
        NNS_MATRIX sGateMtx;
        NNS_MATRIX sInverseMtx;
        NNS_VECTOR sLocalPos;
        nspNnUtil::MakeRotateYZXMatrix(&sGateMtx,
                                       static_cast<s32>(182.04444f * psGateData->sRotVec.x),
                                       static_cast<s32>(182.04444f * psGateData->sRotVec.y),
                                       static_cast<s32>(182.04444f * psGateData->sRotVec.z));
        nnCopyVectorMatrixTranslation(&sGateMtx, &psGateData->sPosVec);
        nnInvertMatrix(&sInverseMtx, &sGateMtx);
        nnTransformVector(&sLocalPos, &sInverseMtx, &rvctStarPos.at(0)->sPosVec);
        f32 f32Height = sLocalPos.y;
        memcpy(&sSetData.sRotVec, &psGateData->sRotVec, sizeof(NNS_VECTOR));
        u32 u32EntryNum = 0;
        u32 u32EndNum = 0;
        s32 s32UserNum = pcBaseRace->getUserNum();
        switch (s32UserNum) {
        case 1 ... 2:
            u32EndNum = u32PlayerNum;
            u32EntryNum = 0;
            break;
        case 3 ... 4:
            u32EndNum = u32PlayerNum + 8;
            u32EntryNum = 8;
            break;
        default:
            break;
        }
        do {
            nnTransformVector(&sSetData.sPosVec, &sGateMtx, &asStartOffset[u32EntryNum]);
            sSetData.sPosVec.y += f32Height;
            *apcPlayer = new clsPlayerTask(sSetData);
            ++apcPlayer;
            ++u32EntryNum;
        } while (u32EntryNum < u32EndNum);
    } else {
        setPlayerPositionOther(rvctStarPos);
    }
}

inline void clsPack::setPlayerPosition(
    oostd::clsOOVector<stcSetDataDetail*, oostd::clsOOStlAllocator<stcSetDataDetail*> >&
        rvctStarPos)
{
    switch (clsGameMgr::GS()->getGameMode()) {
    case clsGameMgr::GAME_MODE___TIME_ATTACK:
    case clsGameMgr::GAME_MODE___MISSION... clsGameMgr::GAME_MODE___TUTORIAL:
    case clsGameMgr::GAME_MODE___SURVIVAL_RELAY... clsGameMgr::GAME_MODE___SURVIVAL_BATTLE:
        setPlayerPositionOther(rvctStarPos);
        break;
    default:
        setPlayerPositionStartGate(rvctStarPos);
        break;
    }
}

// RECONSTRUCTED: helper name and signature.
static inline void PackDecodeNnBins(stcBinInfo& sBinInfo,
                                    u32* pu32OffsetNo,
                                    u16 u16AddBinNum,
                                    s32 s32MaxSize,
                                    nspPackId::enm ePackId,
                                    u8 u8NnModelType)
{
    const u32 u32NnModelType = u8NnModelType;
    u32* pu32Offset = pu32OffsetNo + u16AddBinNum;
    sBinInfo.ePackId = ePackId;
    sBinInfo.opu32OffsetNo = pu32Offset;
    memset(sBinInfo.opu8Bin, 0, sizeof(sBinInfo.opu8Bin));
    if (!OOCheckBit(u32NnModelType, nspNnModelType::BIT_DIV_MAP)) {
        {
            bool bHasBin = OOCheckBitsEq(u32NnModelType, nspNnModelType::BIT_OBJECT);
            sBinInfo.opu8Bin[0] = reinterpret_cast<const u8*>(
                bHasBin * reinterpret_cast<u32>(sBinInfo.opu8BinTopAddr + *pu32Offset));
            pu32Offset += bHasBin;
        }
        {
            bool bHasBin = OOCheckBitsEq(u32NnModelType, nspNnModelType::BIT_TEXTURE);
            sBinInfo.opu8Bin[1] = reinterpret_cast<const u8*>(
                bHasBin * reinterpret_cast<u32>(sBinInfo.opu8BinTopAddr + *pu32Offset));
            pu32Offset += bHasBin;
        }
        if (ePackId != nspPackId::CHARA_0) {
            {
                bool bHasBin = OOCheckBitsEq(u32NnModelType, nspNnModelType::BIT_MOTION);
                sBinInfo.opu8Bin[2] = reinterpret_cast<const u8*>(
                    bHasBin * reinterpret_cast<u32>(sBinInfo.opu8BinTopAddr + *pu32Offset));
                pu32Offset += bHasBin;
            }
            {
                bool bHasBin = OOCheckBitsEq(u32NnModelType, nspNnModelType::BIT_MATMOTOBJ);
                sBinInfo.opu8Bin[3] = reinterpret_cast<const u8*>(
                    bHasBin * reinterpret_cast<u32>(sBinInfo.opu8BinTopAddr + *pu32Offset));
                pu32Offset += bHasBin;
            }
            {
                bool bHasBin = OOCheckBitsEq(u32NnModelType, nspNnModelType::BIT_MORPHOBJ);
                sBinInfo.opu8Bin[4] = reinterpret_cast<const u8*>(
                    bHasBin * reinterpret_cast<u32>(sBinInfo.opu8BinTopAddr + *pu32Offset));
                pu32Offset += bHasBin;
            }
            {
                bool bHasBin = OOCheckBitsEq(u32NnModelType, nspNnModelType::BIT_MORPHTARGETLIST);
                sBinInfo.opu8Bin[5] = reinterpret_cast<const u8*>(
                    bHasBin * reinterpret_cast<u32>(sBinInfo.opu8BinTopAddr + *pu32Offset));
                pu32Offset += bHasBin;
            }
        }
    } else {
        sBinInfo.opu8Bin[0] = NULL;
    }
    s32 s32DatNum = pu32Offset - sBinInfo.opu32OffsetNo;
    sBinInfo.s32RestBinNum = s32MaxSize - s32DatNum;
    if (sBinInfo.s32RestBinNum > 0) {
        sBinInfo.opu32OffsetNo += s32DatNum;
    }
}

// RECONSTRUCTED: helper name and signature.
static inline void PackSetGravityModel2(clsResidenceEffect& rcEffect, clsPack::stcBinInfo& sBinInfo)
{
    rcEffect.copyMorphMotObj(&rcEffect.m_acGravity_Model2[1], &sBinInfo);
    rcEffect.copyMorphMotObj(&rcEffect.m_acGravity_Model2[2], &sBinInfo);
    rcEffect.copyMorphMotObj(&rcEffect.m_acGravity_Model2[3], &sBinInfo);
    nspNnUtil::BinSetUp_Model(
        reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(rcEffect.m_acGravity_Model2[0]),
        sBinInfo.opu8Bin);
    nspNnUtil::CalcUnionNnMtxBuffer_withTRS(rcEffect.m_acGravity_Model2[0]);
    for (u32 u32i = 1; u32i < 4; ++u32i) {
        rcEffect.m_acGravity_Model2[u32i].m_psTexList = rcEffect.m_acGravity_Model2[0].m_psTexList;
        rcEffect.m_acGravity_Model2[u32i].m_f32MotionFrame =
            rcEffect.m_acGravity_Model2[0].m_f32MotionFrame;
        rcEffect.m_acGravity_Model2[u32i].m_f32MatMotionFrame =
            rcEffect.m_acGravity_Model2[0].m_f32MatMotionFrame;
        rcEffect.m_acGravity_Model2[u32i].m_f32MorphMotionFrame =
            rcEffect.m_acGravity_Model2[0].m_f32MorphMotionFrame;
        nspNnUtil::CalcUnionNnMtxBuffer_withTRS(rcEffect.m_acGravity_Model2[u32i]);
    }
}

// RECONSTRUCTED: helper name and signature.
static inline void PackSetGravityModel3(clsResidenceEffect& rcEffect, clsPack::stcBinInfo& sBinInfo)
{
    rcEffect.copyMorphMotObj(&rcEffect.m_acGravity_Model3[1], &sBinInfo);
    rcEffect.copyMorphMotObj(&rcEffect.m_acGravity_Model3[2], &sBinInfo);
    rcEffect.copyMorphMotObj(&rcEffect.m_acGravity_Model3[3], &sBinInfo);
    nspNnUtil::BinSetUp_Model(
        reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(rcEffect.m_acGravity_Model3[0]),
        sBinInfo.opu8Bin);
    nspNnUtil::CalcUnionNnMtxBuffer_withTRS(rcEffect.m_acGravity_Model3[0]);
    for (u32 u32i = 1; u32i < 4; ++u32i) {
        rcEffect.m_acGravity_Model3[u32i].m_psTexList = rcEffect.m_acGravity_Model3[0].m_psTexList;
        rcEffect.m_acGravity_Model3[u32i].m_f32MotionFrame =
            rcEffect.m_acGravity_Model3[0].m_f32MotionFrame;
        rcEffect.m_acGravity_Model3[u32i].m_f32MatMotionFrame =
            rcEffect.m_acGravity_Model3[0].m_f32MatMotionFrame;
        rcEffect.m_acGravity_Model3[u32i].m_f32MorphMotionFrame =
            rcEffect.m_acGravity_Model3[0].m_f32MorphMotionFrame;
        nspNnUtil::CalcUnionNnMtxBuffer_withTRS(rcEffect.m_acGravity_Model3[u32i]);
    }
}
// RECONSTRUCTED: inline helper.
static inline void PackAddScriptLightMotion(void* pvAddrI,
                                            u32* pu32OffsetNo,
                                            u16 u16AddBinNum,
                                            u32 u32BinNum)
{
    u32 u32i = 0;
    clsScriptLight* pcLight = nspGlobal::sTask.pcBaseScript->m_pcLight;
    do {
        pcLight->m_pavLightData[pcLight->m_s32DataNum + u32i] =
            static_cast<u8*>(pvAddrI) + pu32OffsetNo[u16AddBinNum + u32i];
    } while (++u32i < u32BinNum);
    pcLight->m_s32DataNum += u32BinNum;
}

// RECONSTRUCTED: helper name and signature.
static inline void PackSetStageData(
    clsPack* pcPack,
    stcSetData* psStageObjTop,
    std::map<u16, stcBinInfo, std::less<u16>, std::allocator<std::pair<const u16, stcBinInfo> > >&
        sBinInfo_stl)
{
    stcSetDataDetail* psSetData = psStageObjTop->oasSetDataDetail;
    clsTaskManager::GS();
    oostd::clsOOMap<
        nspPackId::enm,
        clsBaseGimmickHead*,
        std::less<nspPackId::enm>,
        oostd::clsOOStlAllocator<std::pair<const nspPackId::enm, clsBaseGimmickHead*> > >
        mapGimmick(clsPfMainHeap::RS());
    oostd::clsOOMap<nspPackId::enm,
                    s32,
                    std::less<nspPackId::enm>,
                    oostd::clsOOStlAllocator<std::pair<const nspPackId::enm, s32> > >
        mapObjectNum(clsPfMainHeap::RS());
    oostd::clsOOVector<stcSetDataDetail*, oostd::clsOOStlAllocator<stcSetDataDetail*> > vctStartPos(
        clsPfMainHeap::RS());
    vctStartPos.reserve(20);
    u32 u32ObjectNum, u32i = 0;
    clsBaseGimmickHead* pcGimmick;
    nspPackId::enm eType;
    do {
        eType = static_cast<nspPackId::enm>(psSetData->u16Type);
        if (clsPfSystem::GS()->getViewportNum() > psSetData->uniu8ViewportNum) {
            if (psSetData->u32GroupNum != 0) {
                mapObjectNum.insert(std::pair<nspPackId::enm, s32>(
                    eType, static_cast<s32>(psSetData->u32GroupNum - 1)));
            }
        } else {
            pcGimmick = NULL;
            do {
                if (eType >= nspPackId::START_GIMMICK && eType < nspPackId::END_GIMMICK) {
                    oostd::clsOOMap<nspPackId::enm,
                                    clsBaseGimmickHead*,
                                    std::less<nspPackId::enm>,
                                    oostd::clsOOStlAllocator<
                                        std::pair<const nspPackId::enm, clsBaseGimmickHead*> > >::
                        iterator itGimmick = mapGimmick.find(eType);
                    if (itGimmick != mapGimmick.end()) {
                        itGimmick->second->setSetData(*psSetData);
                        if (eType == nspPackId::ST04_PATH_CANOE_14040) {
                            mapGimmick.find(nspPackId::ST04_WATER_TURBULENCE_14050)
                                ->second->setSetData(*psSetData);
                        }
                        break;
                    }
                }
                {
                    if (psSetData->u32GroupNum != 0)
                        u32ObjectNum = psSetData->u32GroupNum;
                    else
                        u32ObjectNum = mapObjectNum.find(eType)->second;
                    switch (eType) {
                    case nspPackId::CHARA_0:
                        vctStartPos.push_back(psSetData);
                        break;
                    case nspPackId::SET_SE_3D_1900:
                        new clsSetSe_3D_Task(*psSetData);
                        break;
                    case nspPackId::SET_SE_2D_1901:
                        new clsSetSe_2D_Task(*psSetData);
                        break;
                    case nspPackId::RING_2000:
                        pcGimmick = new clsRing_Task(u32ObjectNum);
                        break;
                    case nspPackId::ITEM_BOX_2010:
                    case nspPackId::ITEM_BOX_AIR_2011:
                        pcGimmick = new clsItemBox_Task(u32ObjectNum, 101001);
                        break;
                    case nspPackId::DASH_PANEL_2020:
                        pcGimmick = new clsDashPanel_Task(u32ObjectNum);
                        break;
                    case nspPackId::SPRING_2030:
                        pcGimmick = new clsSpring_Task(u32ObjectNum);
                        break;
                    case nspPackId::DASH_RING_2040:
                        pcGimmick = new clsDashRing_Task(u32ObjectNum);
                        break;
                    case nspPackId::START_GATE_2050:
                        pcGimmick = new clsStartGate_Task;
                        clsScore2D_Task::setStartPos(
                            psSetData->sPosVec.x, psSetData->sPosVec.y, psSetData->sPosVec.z);
                        clsScore2D_Task::setStartRot(
                            psSetData->sRotVec.x, psSetData->sRotVec.y, psSetData->sRotVec.z);
                        break;
                    case nspPackId::GOAL_LINE_2060:
                        pcGimmick = new clsGoalLine_Task();
                        break;
                    case nspPackId::TYPE_2070:
                        pcGimmick = new clsType_Task(u32ObjectNum);
                        break;
                    case nspPackId::PT_DOOR_2080:
                        pcGimmick = new clsPT_Door_Task(u32ObjectNum);
                        break;
                    case nspPackId::PT_DOOR_2081:
                        pcGimmick = new clsPT_Door2_Task(u32ObjectNum);
                        break;
                    case nspPackId::PT_ONLY_2082:
                        pcGimmick = new clsPT_Only_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_FIXEDOBJECT_2090:
                        pcGimmick = new clsPutFixedObject_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_FIXEDMOTOBJ_2091:
                        pcGimmick = new clsPutFixedMotObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_FIXEDMOTMATOBJ_2092:
                        pcGimmick = new clsPutFixedMotMatObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_FIXEDBURNOBJ_2093:
                        pcGimmick = new clsPutFixedBurnObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_FIXEDMATOBJ_2094:
                        pcGimmick = new clsPutFixedMatObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_GRAVITYOBJ_2100:
                        pcGimmick = new clsPutGravityObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_MATMOTGOBJ_2101:
                        pcGimmick = new clsPutMatMotGObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_GRAVITYOBJ2_2102:
                        pcGimmick = new clsPutGravityObj2_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_PARALLAX_2103:
                        pcGimmick = new clsPutParallax_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_GRAVITYOBJ3_2104:
                        pcGimmick = new clsPutGravityObj3_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_ARROW_2105:
                        pcGimmick = new clsPutArrow_Task(u32ObjectNum);
                        break;
                    case nspPackId::PUT_MOTIONOBJ_2110:
                        pcGimmick = new clsPutMotionObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::WALL_OBJ_2120:
                        pcGimmick = new clsWallObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_TURB_COL_11210:
                        pcGimmick = new clsTurbulence_Task(u32ObjectNum);
                        break;
                    case nspPackId::CATAPULT_2130:
                        pcGimmick = new clsCatapult_Task(u32ObjectNum);
                        break;
                    case nspPackId::PATH_GARVITYOBJ_2140:
                        pcGimmick = new clsPathGravityObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::GRAVITY_RING_2150:
                        pcGimmick = new clsGravityRing_Task(u32ObjectNum);
                        break;
                    case nspPackId::HIDE_KICKER_2160:
                        pcGimmick = new clsHideKicker_Task(u32ObjectNum);
                        break;
                    case nspPackId::WALL_GIMMICK_2170:
                        pcGimmick = new clsWallGimmick_Task(u32ObjectNum);
                        break;
                    case nspPackId::PLAY_AROUND_SE_2180:
                        pcGimmick = new clsPlayAroundSe_Task(u32ObjectNum);
                        break;
                    case nspPackId::ADJUST_GCTRL_2190:
                        pcGimmick = new clsAdjustGravityAction_Task(u32ObjectNum);
                        break;
                    case nspPackId::PLAY_LOOP_SE_2200:
                        pcGimmick = new clsPlayLoopSe_Task(u32ObjectNum);
                        break;
                    case nspPackId::AUTO_WALLRUN_2210:
                        pcGimmick = new clsAutoGCtrlThrough_Task(u32ObjectNum);
                        break;
                    case nspPackId::MAG_BARRIRER_2220:
                        pcGimmick = new clsMagBarrier_Task(*psSetData);
                        break;
                    case nspPackId::RAIL_WAY_START_2230:
                        pcGimmick = new clsRailWayStart_Task(u32ObjectNum);
                        break;
                    case nspPackId::RAIL_WAY_END_2231:
                        pcGimmick = new clsRailWayEnd_Task(u32ObjectNum);
                        break;
                    case nspPackId::SPEED_DOWN_2240:
                        pcGimmick = new clsSpeedDown_Task(*psSetData);
                        break;
                    case nspPackId::ST01_PATH_CAR_11000:
                        pcGimmick = new clsPathCar_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_PUT_CAR_11010:
                        pcGimmick = new clsPutCar_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_GLINK_TRAIN_11200:
                        pcGimmick = new clsGLinkTrain_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_PATH_TRAIN_11040:
                        pcGimmick = new clsPathTrain_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_PRODUCTION_ROBO_11050:
                        pcGimmick = new clsProductionRobo_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_TAXI_11080:
                        pcGimmick = new clsTaxi_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_CHAIR_A_11190:
                        pcGimmick = new clsChairA_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_CHAIR_B_11191:
                        pcGimmick = new clsChairB_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_GARBAGE_BOX_11192:
                        pcGimmick = new clsGarbageBox_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_GUIDE_BOARD_11193:
                        pcGimmick = new clsBulletinBoard_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_CONE_11194:
                        pcGimmick = new clsCone_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST01_GCTRL_TRAIN_11220:
                        pcGimmick = new clsGCtrlTrain_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST02_IVY_12000:
                        pcGimmick = new clsIvy_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST02_BEE_ROBO_12010:
                        pcGimmick = new clsBeeRobo_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST02_KUKI_12020:
                        pcGimmick = new clsGLinkKuki_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST02_PLANT_12030:
                        pcGimmick = new clsPlant_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST02_PLANT_12031:
                        pcGimmick = new clsPlant2_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST02_SIDA_12040:
                        pcGimmick = new clsSida_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST02_PATH_BEE_12050:
                        pcGimmick = new clsPathBee_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST02_BUTTERFLY_12060:
                        pcGimmick = new clsButterfly_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST02_RUN_BEE_12070:
                        pcGimmick = new clsRunBee_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST03_COGWHEEL_13000:
                        pcGimmick = new clsCogwheel_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST03_PRESS_13010:
                        pcGimmick = new clsPress_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST03_EXTRALAMP_13020:
                        pcGimmick = new clsExtraLamp_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST03_PUT_ROBO_13030:
                        pcGimmick = new clsPutRobo_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST03_PUT_CONTAINER_13040:
                        pcGimmick = new clsGLinkContainer_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST03_SECURITY_GATE_13050:
                        pcGimmick = new clsSecurityGate_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST03_POWER_BREAK_13060:
                        pcGimmick = new clsPowerBreak_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST03_MACROSS_13070:
                        pcGimmick = new clsMacross_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST03_PATH_ROBO_13090:
                        pcGimmick = new clsPathRobo_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST04_AUTORUN_CANOE_14000:
                        pcGimmick = new clsAutoRunCanoe_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST04_GLINK_WATERSPHERE_14010:
                        pcGimmick = new clsGLinkWaterSphere_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST04_FOUNTAIN_14020:
                        pcGimmick = new clsFountain_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST04_STRAIGHT_FOUNTAIN_14030:
                        pcGimmick = new clsStraightFountain_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST04_PATH_CANOE_14040:
                        pcGimmick = new clsPathCanoe_Task(u32ObjectNum);
                        if (mapGimmick.find(nspPackId::ST04_WATER_TURBULENCE_14050) ==
                            mapGimmick.end())
                        {
                            clsBaseGimmickHead* pcTurbulence =
                                new clsPutTurbulence_Task(u32ObjectNum);
                            mapGimmick.insert(std::pair<nspPackId::enm, clsBaseGimmickHead*>(
                                nspPackId::ST04_WATER_TURBULENCE_14050, pcTurbulence));
                            pcTurbulence->setSetData(*psSetData);
                        }
                        break;
                    case nspPackId::ST04_PUT_CANOE_14060:
                        pcGimmick = new clsPutCanoe_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST04_SMALL_WATERSPHERE_14070:
                        pcGimmick = new clsSmallWaterSphere_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST05_ROT_GROUND_15000:
                        pcGimmick = new clsRotGround_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST05_ROT_FALL_MANAGER_15010:
                        pcGimmick = new clsRotFall_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST05_FIRE_15020:
                        pcGimmick = new clsFire_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST05_SPAIN_15030:
                        pcGimmick = new clsSpain_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST05_DOMINO_15040:
                        pcGimmick = new clsDomino_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST05_ROT_FALL_GLINK_MANAGER_15050:
                        pcGimmick = new clsRotFallGLink_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST05_DETENTION_15060:
                        pcGimmick = new clsDetention_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST05_BREAK_RAILING_15070:
                        pcGimmick = new clsBreakRailing_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST06_SURVEILLANCE_CAMERA_16000:
                        pcGimmick = new clsSurveillanceCamera_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST06_BLOCKADEOBJ_16010:
                        pcGimmick = new clsBlockadeObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST06_LASER_16020:
                        pcGimmick = new clsLaser_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST06_GLINK_ELEVATOR_16030:
                        pcGimmick = new clsGLinkElevator_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST06_ELEVATOR_16040:
                        pcGimmick = new clsElevator_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_FLOOR_S_17000:
                        pcGimmick = new clsMapPartsFloorSmall_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_FLOOR_B_17001:
                        pcGimmick = new clsMapPartsFloorBig_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_FLOOR_SWITCH_17002:
                        pcGimmick = new clsMapPartsFloorSwitch_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_FLOOR_CHANGE_17003:
                        pcGimmick = new clsMapPartsFloorChange_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_FLOOR_KICKER_17004:
                        pcGimmick = new clsMapPartsFloorKicker_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_FLOOR_GRAVITY_17005:
                        switch (clsGameMgr::GS()->getGameMode()) {
                        case clsGameMgr::GAME_MODE___SURVIVAL_BATTLE:
                            pcGimmick = new clsSvlBtlMapPartsFloorGravity_Task(u32ObjectNum);
                            break;
                        default:
                            pcGimmick = new clsMapPartsFloorGravity_Task(u32ObjectNum);
                            break;
                        }
                        break;
                    case nspPackId::ST07_FLOOR_GLINK_17006:
                        pcGimmick = new clsMapPartsFloorGLink_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_JOINT00_17010:
                        pcGimmick = new clsMapPartsJointSmall_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_JOINT01_17011:
                        pcGimmick = new clsMapPartsJointCurve_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_JOINT02_17012:
                        pcGimmick = new clsMapPartsJointBig_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_JOINT03_17013:
                        pcGimmick = new clsMapPartsJointSharp_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_GUARDRAIL00_17020:
                        pcGimmick = new clsMapPartsGuardRailSmall_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_GUARDRAIL01_17021:
                        pcGimmick = new clsMapPartsGuardRailCurve_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_GIMMICKWALL00_17030:
                        pcGimmick = new clsMapPartsGimmickWallSmall_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_GIMMICKWALL01_17031:
                        pcGimmick = new clsMapPartsGimmickWallBig_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_GATE_17050:
                        pcGimmick = new clsSt07Gate_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_WALL_THROUGH_17060:
                        pcGimmick = new clsWallThroughCollision_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_POWER_BREAK_17070:
                        pcGimmick = new clsSt07PowerBreak_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST07_SOLAR_17080:
                        pcGimmick = new clsSolar_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST08_ROAD_18000:
                        pcGimmick = new clsRoad_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST08_ROAD_SIGNAL_18010:
                        pcGimmick = new clsRoadSignal_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST08_ROAD_CAR_18020:
                        pcGimmick = new clsRoadCar_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST08_ROAD_GLINK_BUS_18030:
                        pcGimmick = new clsRoadGlinkBus_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST08_ROAD_TRAILER_18040:
                        pcGimmick = new clsRoadTrailer_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST08_UFOCATCHER_18050:
                        pcGimmick = new clsUfoCatcher_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST08_FZONE_ENEMY_18060:
                        pcGimmick = new clsFZoneEnemy_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST10_SNOWBALL_20010:
                        pcGimmick = new clsSnowBall_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST10_FALL_SNOWBALL_20020:
                        pcGimmick = new clsFallSnowBall_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST10_SNOWMAN_20030:
                        pcGimmick = new clsGLinkSnowman_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST10_LIFT_20040:
                        pcGimmick = new clsLift_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST11_ENERGY_CYLINDER_21000:
                        pcGimmick = new clsEnergyCylinder_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST11_FSECURITY_GATE_21010:
                        pcGimmick = new clsFSecurityGate_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST11_PATH_SECURITY_ROBO_21020:
                        pcGimmick = new clsSecurityRoboManager_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST11_FAN_21030:
                        pcGimmick = new clsFan_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST11_CRANE_21040:
                        pcGimmick = new clsCrane_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST11_GLINK_CYLINDER_21050:
                        pcGimmick = new clsGlinkCylinder_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST11_LINE_OBJ_21060:
                        pcGimmick = new clsLineObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST12_GLINK_BRIDGE_22010:
                        pcGimmick = new clsGLinkBridge_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST12_PUT_CANOE_22020:
                        pcGimmick = new clsPutCanoeMotion_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST12_PATH_CANOE_22030:
                        pcGimmick = new clsPathCanoeMotion_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST12_MOTIONOBJ_22040:
                        pcGimmick = new clsSt12MotionObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_BUNKI_23010:
                        pcGimmick = new clsBunki_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_CATAPULT_23020:
                        pcGimmick = new clsSt13Catapult_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_COLOSSUS_23030:
                        pcGimmick = new clsColossus_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_GLINK_COLOSSUS_23040:
                        pcGimmick = new clsGLinkColossus_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_BRIDGE_23050:
                        pcGimmick = new clsBridge_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_GATE_23060:
                        pcGimmick = new clsGate_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_PILLAR_23070:
                        pcGimmick = new clsPillar_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_PT_OBJ_23080:
                        pcGimmick = new clsSt13PTObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_HIKARI_23090:
                        pcGimmick = new clsSt13Hikari_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_SIGNBOARD_23100:
                        pcGimmick = new clsSignBoard_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_SIGNBOARD_B_23110:
                        pcGimmick = new clsSignBoardB_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST13_PT_WALL_23120:
                        pcGimmick = new clsPT_Wall_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST14_FAN_24000:
                        pcGimmick = new clsGPFan_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST14_OBJ_CRANE_24010:
                        pcGimmick = new clsObjCrane_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST14_LASER_24020:
                        pcGimmick = new clsSt14Laser_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST14_BIG_FAN_24030:
                        pcGimmick = new clsGLinkFan_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST14_STEEL_FRAME_24040:
                        pcGimmick = new clsSteelFrame_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST15_CORE_BASE_25000:
                        pcGimmick = new clsCoreBase_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST15_FUSION_MACHINE_25010:
                        pcGimmick = new clsFusionMachine_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST15_GLINK_FLOOR_BOARD_25060:
                        pcGimmick = new clsGLinkFloorBoard_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST15_BREAK_FLOOR_25070:
                        pcGimmick = new clsBreakFloor_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST15_FLOATING_METEORITE_25080:
                        pcGimmick = new clsFloatingMeteorite_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST15_FLOATING_METEO_TRIG_25090:
                        pcGimmick = new clsFloatingMeteoTrig_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST15_SAFE_TRAMPOLINE_25100:
                        pcGimmick = new clsSafeTrampoline_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST16_HELICOPTER_26000:
                        pcGimmick = new clsHelicopter_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST16_GLINK_SIGNBOARD_26010:
                        pcGimmick = new clsGLinkSignBoard_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST16_BREAK_SIGNBOARD_26020:
                        pcGimmick = new clsBreakSignBoard_Task(u32ObjectNum);
                        break;
                    case nspPackId::ST16_AUTORUN_HELI_26030:
                        pcGimmick = new clsAutoRunHeli_Task(u32ObjectNum);
                        break;
                    case nspPackId::MISSION_PATH_TARGET_27000:
                        pcGimmick = new clsMissionPathTarget_Task(u32ObjectNum);
                        break;
                    case nspPackId::MISSION_TIME_GATE_27010:
                        pcGimmick = new clsMissionTimeGate_Task(u32ObjectNum);
                        break;
                    case nspPackId::MISSION_MARK_27011:
                        pcGimmick = new clsMissionMark_Task(u32ObjectNum);
                        break;
                    case nspPackId::MISSION_PATH_ROBO_27020:
                        pcGimmick = new clsMissionPathRobo_Task(u32ObjectNum);
                        break;
                    case nspPackId::MISSION_FIXED_LINK_27030:
                        pcGimmick = new clsMissionFixedLink_Task(u32ObjectNum);
                        break;
                    case nspPackId::MISSION_GLINK_COLOSSUS_27040:
                        pcGimmick = new clsMissionGLinkColossus_Task(u32ObjectNum);
                        break;
                    case nspPackId::SURVIVALBALL_GOALRING_28000:
                        pcGimmick = new clsSurvivalBallPointRing_Task(u32ObjectNum);
                        break;
                    case nspPackId::SURVIVALBALL_BALL_28010:
                        pcGimmick = new clsSurvivalBallBall_Task(u32ObjectNum);
                        break;
                    case nspPackId::SURVIVALBALL_POLE_28020:
                        pcGimmick = new clsSurvivalBallPole_Task(u32ObjectNum);
                        break;
                    case nspPackId::SURVIVALBALL_START_28030:
                        pcGimmick = new clsSurvivalBallStart_Task(u32ObjectNum);
                        break;
                    case nspPackId::SURVIVALBALL_PUT_OBJ_28040:
                        pcGimmick = new clsSurvivalBallPutObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::SCRIPT_SURVIVAL_DATA_START: {
                        if (clsSurvivalBallBall_Task::GS() != NULL) {
                            clsSurvivalBallBall_Task::GS()->setSetDataBall(*psSetData);
                        }
                    } break;
                    case nspPackId::SURVIVALRELAY_WALKRUN_28500:
                        pcGimmick = new clsSurvivalRelayWalkRunObj_Task(u32ObjectNum);
                        break;
                    case nspPackId::SURVIVALBATTLE_MISSILE_29000:
                        pcGimmick = new clsSvlBtlMissile_Task(*psSetData);
                        break;
                    case nspPackId::SURVIVALBATTLE_BOMB_29010:
                        pcGimmick = new clsSvlBtlBomb_Task(*psSetData);
                        break;
                    case nspPackId::SURVIVALBATTLE_BLOCK_29020:
                        pcGimmick = new clsSvlBtlBlock_Task(u32ObjectNum);
                        break;
                    case nspPackId::SURVIVALBATTLE_POLE_29030:
                        pcGimmick = new clsSvlBtlPaul_Task(u32ObjectNum);
                        break;
                    case nspPackId::SURVIVALBATTLE_BARRIER_29040:
                        pcGimmick = new clsSvlBtlBarrier_Task(*psSetData);
                        break;
                    case nspPackId::SURVIVALBATTLE_EXPLOSION_29050:
                        pcGimmick = new clsSvlBtlExplosion_Task(*psSetData);
                        break;
                    case nspPackId::PARTICLE_SET_33000... nspPackId::PARTICLE_33999: {
                        u16 u16ParticleId =
                            static_cast<u16>(psSetData->u16Type - nspPackId::PARTICLE_SET_33000 +
                                             nspParticleData::getSetDataStart());
                        nspParticleSet::registTaskObjData(
                            4,
                            u16ParticleId,
                            reinterpret_cast<const NNS_VECTORFAST*>(&psSetData->sRotVec),
                            reinterpret_cast<const NNS_VECTORFAST*>(&psSetData->sPosVec),
                            nspParticleSet::psTexList_UnionParticle,
                            4,
                            psSetData->u8PortalType);
                    } break;
                    case nspPackId::EFFECT_SUNLENZ_30030:
                        new clsSunLenz_Task(*psSetData);
                        break;
                    default:
                        break;
                    }
                    if (pcGimmick != NULL) {
                        mapGimmick.insert(
                            std::pair<nspPackId::enm, clsBaseGimmickHead*>(eType, pcGimmick));
                        pcGimmick->setSetData(*psSetData);
                    }
                }
            } while (false);
        }
        ++psSetData;
        ++u32i;
    } while (u32i < psStageObjTop->u32AllObjNum);
    pcPack->setPlayerPosition(vctStartPos);
    oostd::clsOOMap<
        nspPackId::enm,
        clsBaseGimmickHead*,
        std::less<nspPackId::enm>,
        oostd::clsOOStlAllocator<std::pair<const nspPackId::enm, clsBaseGimmickHead*> > >::iterator
        itGimmick;
    stcBinInfo sEmptyBin;
    memset(&sEmptyBin, 0, sizeof(sEmptyBin));
    itGimmick = mapGimmick.begin();
    while (itGimmick != mapGimmick.end()) {
        eType = itGimmick->first;
        std::map<u16,
                 stcBinInfo,
                 std::less<u16>,
                 std::allocator<std::pair<const u16, stcBinInfo> > >::iterator itBin =
            sBinInfo_stl.find(static_cast<u16>(eType));
        if (itBin != sBinInfo_stl.end()) {
            itGimmick->second->loadBinary(itBin->second);
        } else {
            itGimmick->second->loadBinary(sEmptyBin);
        }
        ++itGimmick;
    }
    if (clsGameMgr::GS()->getGameMode() != clsGameMgr::GAME_MODE___SURVIVAL_BATTLE) {
        new clsSetCamColli_Task;
    }
}
// RECONSTRUCTED: inline helper.
template <class T_MODEL>
static inline void PackCreateModel(T_MODEL*& rpcModel, clsPack::stcBinInfo& sBinInfo)
{
    if (rpcModel == NULL) {
        rpcModel = new T_MODEL;
        nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(*rpcModel),
                                  sBinInfo.opu8Bin);
        nspNnUtil::CalcUnionNnMtxBuffer_withTRS(*rpcModel);
    }
}

#pragma push
// MATCHING_WORKAROUND: original inline budget is unknown.
#pragma inline_max_total_size(8000)
void clsPack::Pack2Set(void* pvAddrI, u32 u32Context, clsTask* pcTaskI)
{
    clsDebug& rcDebug = *clsDebug::GS();
    std::map<u16, stcBinInfo, std::less<u16>, std::allocator<std::pair<const u16, stcBinInfo> > >
        sBinInfo_stl;
    u8* pu8BinTopAddr = static_cast<u8*>(pvAddrI) + sizeof(stcPackBinHead);
    stcPackBinHead sPackBinHead = *static_cast<stcPackBinHead*>(pvAddrI);
    u32 u32GroupNum = sPackBinHead.u16AllGroupNum;
    u8* pu8BinNum = pu8BinTopAddr;
    u8* pu8NnModelType = pu8BinNum + u32GroupNum;
    u16* pu16AddBinNum =
        reinterpret_cast<u16*>((reinterpret_cast<u32>(pu8NnModelType + u32GroupNum) + 3) & ~3U);
    u16* pu16Type = pu16AddBinNum + u32GroupNum;
    u32* pu32OffsetNo = reinterpret_cast<u32*>(pu16Type + u32GroupNum);
    stcBinInfo sBinInfo;
    sBinInfo.opu8BinTopAddr = static_cast<u8*>(pvAddrI);
    u8* sBinInfoTmp;
    u8* sBinInfoTmp2;
    u8* sBinInfoTmp3;
    clsBaseRace_Task& rcBaseRace_Task = *nspGlobal::sTask.pcBaseRace;
    clsScript_Task& rcBaseScript_Task = *nspGlobal::sTask.pcBaseScript;
    stcSetData* psStageObjTop = NULL;
    clsAdvertiseMgr_Task* pcAdvertiseMgr_Task;
    std::pair<std::map<u16,
                       stcBinInfo,
                       std::less<u16>,
                       std::allocator<std::pair<const u16, stcBinInfo> > >::iterator,
              bool>
        iRet = sBinInfo_stl.insert(std::pair<u16, stcBinInfo>(nspPackId::DUMMY_DATA, sBinInfo));
    clsPathData* pcPathData = clsPathData::GS();
    clsBaseStage_Task* pcStage = NULL;
    bool bPartcleInit = false;
    clsGameMgr* pcGameMgr = clsGameMgr::GS();
    u32 u32g = 0;
    do {
        nspPackId::enm ePackId = static_cast<nspPackId::enm>(pu16Type[u32g]);
        if (ePackId != nspPackId::GEAR_10) {
            s32 s32MaxSize = pu8BinNum[u32g];
            PackDecodeNnBins(sBinInfo,
                             pu32OffsetNo,
                             pu16AddBinNum[u32g],
                             s32MaxSize,
                             ePackId,
                             pu8NnModelType[u32g]);
        }
        switch (pu16Type[u32g]) {
        case nspPackId::CHARA_0: {
            s32 s32MaxSize = 0;
            s32 s32i = 0;
            do {
                if (static_cast<u32>(s32MaxSize) < sBinInfo.opu32OffsetNo[s32i]) {
                    s32MaxSize = sBinInfo.opu32OffsetNo[s32i];
                }
                ++s32i;
            } while (s32i < pu8BinNum[u32g] + 1);
            rcDebug.m_sDataSize.s32PlayerData += s32MaxSize;
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          nspGame::acChara[u32Context >> 16][u32Context & 0xffff]),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                nspGame::acChara[u32Context >> 16][u32Context & 0xffff]);
            nspChara::afloadAdditionalFuncs[u32Context & 0xffff](sBinInfo);
            if ((u32Context & 0xffff) == nspChara::CHARA_CREAM) {
                if ((u32Context >> 16) == 0) {
                    for (u32 u32i = 0; u32i < 6; ++u32i) {
                        nspNnUtil::BinSetUpMotion(&nspGame::sChaoMotion.psMotion[u32i],
                                                  sBinInfo.opu8BinTopAddr +
                                                      sBinInfo.opu32OffsetNo[0]);
                        ++sBinInfo.opu32OffsetNo;
                    }
                } else {
                    nspNnUtil::BinSetUpMotion(&nspGame::sChaoMotion.psMotion[3],
                                              sBinInfo.opu8BinTopAddr + sBinInfo.opu32OffsetNo[0]);
                }
            }
        } break;
        case nspPackId::CHARA_SUPER_SONIC_MODEL_3: {
            s32 s32MaxSize = 0;
            s32 s32i = 0;
            do {
                if (static_cast<u32>(s32MaxSize) < sBinInfo.opu32OffsetNo[s32i]) {
                    s32MaxSize = sBinInfo.opu32OffsetNo[s32i];
                }
                ++s32i;
            } while (s32i < pu8BinNum[u32g] + 1);
            rcDebug.m_sDataSize.s32PlayerData += s32MaxSize;
            clsModelType_OB_TX& rcModel = nspGame::cSuperSonicModel;
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(rcModel),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(rcModel);
        } break;
        case nspPackId::GEAR_10: {
            sBinInfo.opu32OffsetNo = pu32OffsetNo + pu16AddBinNum[u32g];
            sBinInfo.s32RestBinNum = pu8BinNum[u32g];
            s32 s32MaxSize = 0;
            s32 s32i = 0;
            do {
                if (static_cast<u32>(s32MaxSize) < sBinInfo.opu32OffsetNo[s32i]) {
                    s32MaxSize = sBinInfo.opu32OffsetNo[s32i];
                }
                ++s32i;
            } while (s32i < pu8BinNum[u32g] + 1);
            rcDebug.m_sDataSize.s32GearData += s32MaxSize;
            loadGearModels(u32Context, sBinInfo);
        } break;
        case nspPackId::MAP_100:
        case nspPackId::MAP_MISSION_101:
        case nspPackId::MAP_TUTORIAL_103:
        case nspPackId::MAP_SURVIVALRELAY_105: {
            s32 s32i = 0;
            do {
                if (static_cast<u32>(rcDebug.m_sDataSize.s32MapAll) < sBinInfo.opu32OffsetNo[s32i])
                {
                    rcDebug.m_sDataSize.s32MapAll = sBinInfo.opu32OffsetNo[s32i];
                }
                ++s32i;
            } while (s32i < pu8BinNum[u32g] + 1);
        }
            switch (nspGlobal::sTask.pcBaseRace->getStageNo()) {
            default:
                pcStage = new clsStage00_Task(sBinInfo);
                break;
            case 1:
                pcStage = new clsStage01_Task(sBinInfo);
                break;
            case 2:
                pcStage = new clsStage02_Task(sBinInfo);
                break;
            case 3:
                pcStage = new clsStage03_Task(sBinInfo);
                break;
            case 4:
                pcStage = new clsStage04_Task(sBinInfo);
                break;
            case 5:
                pcStage = new clsStage05_Task(sBinInfo);
                break;
            case 6:
                pcStage = new clsStage06_Task(sBinInfo);
                break;
            case 7:
                pcStage = new clsStage07_Task(sBinInfo);
                break;
            case 8:
                pcStage = new clsStage08_Task(sBinInfo);
                break;
            case 9:
                pcStage = new clsStage09_Task(sBinInfo);
                break;
            case 10:
                pcStage = new clsStage10_Task(sBinInfo);
                break;
            case 11:
                pcStage = new clsStage11_Task(sBinInfo);
                break;
            case 12:
                pcStage = new clsStage12_Task(sBinInfo);
                break;
            case 13:
                pcStage = new clsStage13_Task(sBinInfo);
                break;
            case 14:
                pcStage = new clsStage14_Task(sBinInfo);
                break;
            case 15:
                pcStage = new clsStage15_Task(sBinInfo);
                break;
            case 16:
                pcStage = new clsStage16_Task(sBinInfo);
                break;
            }
            pcStage->init();
            nspGlobal::sTask.pcBaseStage = pcStage;
            break;
        case nspPackId::MAP_SURVIVALBALL_102: {
            s32 s32i = 0;
            do {
                if (static_cast<u32>(rcDebug.m_sDataSize.s32MapAll) < sBinInfo.opu32OffsetNo[s32i])
                {
                    rcDebug.m_sDataSize.s32MapAll = sBinInfo.opu32OffsetNo[s32i];
                }
                ++s32i;
            } while (s32i < pu8BinNum[u32g] + 1);
        }
            pcStage = new clsBaseStage_Task(sBinInfo);
            pcStage->init();
            nspGlobal::sTask.pcBaseStage = pcStage;
            break;
        case nspPackId::MAP_SURVIVALBATTLE_104: {
            s32 s32i = 0;
            do {
                if (static_cast<u32>(rcDebug.m_sDataSize.s32MapAll) < sBinInfo.opu32OffsetNo[s32i])
                {
                    rcDebug.m_sDataSize.s32MapAll = sBinInfo.opu32OffsetNo[s32i];
                }
                ++s32i;
            } while (s32i < pu8BinNum[u32g] + 1);
        }
            pcStage = new clsBaseStage_Task(sBinInfo);
            pcStage->init();
            nspGlobal::sTask.pcBaseStage = pcStage;
            break;
        case nspPackId::REFLECT_MAP_110:
        case nspPackId::REFLECT_DIVMAP_111:
            break;
        case nspPackId::MAP_BURN_LIGHT_150:
            new clsMapBurnLight_Task(sBinInfo);
            break;
        case nspPackId::SKY_200:
            new clsBaseSky_Task(sBinInfo);
            break;
        case nspPackId::SKY_THUNDER_250:
            new clsSky09_Task(sBinInfo);
            break;
        case nspPackId::START_CAMERA_MOTION_300: {
            if (pcGameMgr->getGameMode() == clsGameMgr::GAME_MODE___STORY &&
                nspGlobal::sTask.pcBaseRace->getStageNo() == 1)
            {
                break;
            }
            NNS_CAMERAPTR* psDataPtr;
            NNS_MOTION* psMotion;
            u32 u32NoCnt = 0;
            do {
                nspNnUtil::BinSetUpCameraMotion(&psDataPtr,
                                                &psMotion,
                                                static_cast<u8*>(pvAddrI) +
                                                    pu32OffsetNo[pu16AddBinNum[u32g] + u32NoCnt]);
                rcBaseRace_Task.setStartCamMotionData(
                    static_cast<clsBaseRace_Task::enmCamMotionNo>(u32NoCnt), psDataPtr, psMotion);
                ++u32NoCnt;
            } while (u32NoCnt < pu8BinNum[u32g]);
        } break;
        case nspPackId::START_CAMERA_MOTION_301:
            if (pcGameMgr->getGameMode() == clsGameMgr::GAME_MODE___STORY) {
                NNS_CAMERAPTR* psDataPtr;
                NNS_MOTION* psMotion;
                u32 u32NoCnt = 0;
                do {
                    nspNnUtil::BinSetUpCameraMotion(
                        &psDataPtr,
                        &psMotion,
                        static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + u32NoCnt]);
                    rcBaseRace_Task.setStartCamMotionData(
                        static_cast<clsBaseRace_Task::enmCamMotionNo>(u32NoCnt),
                        psDataPtr,
                        psMotion);
                    ++u32NoCnt;
                } while (u32NoCnt < pu8BinNum[u32g]);
            }
            break;
        case nspPackId::SET_DATA_1000:
            psStageObjTop = reinterpret_cast<stcSetData*>(static_cast<u8*>(pvAddrI) +
                                                          pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::ETC_BINARY_STAGE_DATA_1050:
            pcStage->setEtcParam(sBinInfo);
            break;
        case nspPackId::MISSION_DATA_1010:
            static_cast<clsMissionRace_Task&>(rcBaseRace_Task)
                .setMissionParam(static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::TUTORIAL_DATA_1011:
            static_cast<clsMissionRace_Task&>(rcBaseRace_Task)
                .setMissionParam(static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::GAME_2D_1020:
            nspScoreSet::setGameTextureList(static_cast<u8*>(pvAddrI) +
                                            pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::GAME_2D_1025:
            nspScoreSet::setStageTextureList(static_cast<u8*>(pvAddrI) +
                                             pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::GAME_2D_1026:
            nspNnUtil::BinSetUpObject(&clsScoreMap2D::m_tpsMapObject,
                                      NULL,
                                      static_cast<u8*>(pvAddrI) +
                                          pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::GAME_2D_1027:
            nspNnUtil::BinSetUpTexList_Texture(&nspWinLose2D::psTexList_WinLose2D,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::MISSION_2D_1028:
            nspNnUtil::BinSetUpTexList_Texture(&nspMission2D::psTexList_Mission2D,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::SUVIVALBALL_2D_1029:
            nspNnUtil::BinSetUpTexList_Texture(&nspSurvivalBall2D::psTexList_SurvivalBall2D,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::TUTORIAL_2D_1030: {
            nspNnUtil::BinSetUpTexList_Texture(
                &static_cast<clsTutorialRace_Task&>(rcBaseRace_Task).m_psTexList_TutorialUnion2D,
                NULL,
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            nspNnUtil::BinSetUpTexList_Texture(
                &static_cast<clsTutorialRace_Task&>(rcBaseRace_Task).m_psTexList_TutorialMine2D,
                NULL,
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 1]);
        } break;
        case nspPackId::SUVIVALBATTLE_2D_1032:
            nspNnUtil::BinSetUpTexList_Texture(&nspSurvivalBattle2D::psTexList_SurvivalBattle2D,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::TIMEATTACK_2D_1033:
            nspNnUtil::BinSetUpTexList_Texture(&nspTimeAttack2D::psTexList_TimeAttack2D,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::SURVIVALMESSAGE_2D_1034:
            nspNnUtil::BinSetUpTexList_Texture(&nspSurvivalMessageSet::psTexList_SurvivalMessage2D,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::SUVIVALBATTLE_MAP2D_1035:
            nspNnUtil::BinSetUpTexList_Texture(
                &nspSurvivalBattleMap2D::psTexList_SurvivalBattleMap2D,
                NULL,
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::MISSION_STAGE_2D_1036:
            nspNnUtil::BinSetUpTexList_Texture(&nspMission2D::psTexList_MissionSta2D,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::OBJ_PORTAL_1090:
            pcStage->setObjPortalBin(sBinInfo);
            break;
        case nspPackId::PATH__PLAYER_1100:
            pcPathData->setBinData(0,
                                   static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::PATH__GIMMICK_1101:
            pcPathData->setBinData(1,
                                   static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::PATH__RAIL_1102:
            pcPathData->setBinData(2,
                                   static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::PATH__TRICK_1103:
            pcPathData->setBinData(3,
                                   static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::PATH__GRAVITY_1104:
            pcPathData->setBinData(4,
                                   static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::PATH__RANK_1105:
            pcPathData->setBinData(5,
                                   static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::PATH__DIVE_1106:
            pcPathData->setBinData(6,
                                   static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::PATH__COURSE_1110:
            pcStage->m_pcCoursePath->loadBinaryData(
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]],
                pcStage,
                sBinInfo.opu32OffsetNo[1] - sBinInfo.opu32OffsetNo[0]);
            break;
        case nspPackId::PATH__COM_1111:
            pcStage->m_cComPath.loadBinaryData(
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]],
                pcStage,
                sBinInfo.opu32OffsetNo[1] - sBinInfo.opu32OffsetNo[0]);
            break;
        case nspPackId::TUTORIAL_GHOST_1200: {
            static_cast<clsTutorialRace_Task&>(rcBaseRace_Task)
                .m_pcGhostTask->setGhostData(
                    static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]], false, NULL);
            static_cast<clsTutorialRace_Task&>(rcBaseRace_Task).m_psGhostLoadData =
                clsGhost::getGhostLoadData(
                    static_cast<clsTutorialRace_Task&>(rcBaseRace_Task).getStageNo());
        } break;
        case nspPackId::START_GIMMICK... nspPackId::END_GIMMICK:
            iRet = sBinInfo_stl.insert(std::pair<u16, stcBinInfo>(pu16Type[u32g], sBinInfo));
            if (nspGlobal::sTask.pcBaseRace->getStageNo() == 10) {
                if (pu16Type[u32g] == nspPackId::ST10_SNOWBALL_20010) {
                    sBinInfoTmp = static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 2];
                }
                if (pu16Type[u32g] == nspPackId::ST10_FALL_SNOWBALL_20020) {
                    sBinInfoTmp2 =
                        static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 2];
                }
                if (pu16Type[u32g] == nspPackId::ST10_SNOWMAN_20030) {
                    sBinInfoTmp3 =
                        static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 2];
                }
            }
            break;
        case nspPackId::EFFECT_30000:
            nspNnUtil::BinSetUpTexList_Texture(
                &rcBaseRace_Task.cResidenceEffect.m_psResidence_TexList,
                NULL,
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::EFFECT_GRAVITY_30010:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGravity_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGravity_Model);
            break;
        case nspPackId::EFFECT_GRAVITY_30020:
            PackSetGravityModel2(rcBaseRace_Task.cResidenceEffect, sBinInfo);
            break;
        case nspPackId::EFFECT_GRAVITY2_30021:
            PackSetGravityModel3(rcBaseRace_Task.cResidenceEffect, sBinInfo);
            break;
        case nspPackId::EFFECT_LANDING_30040:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cLandig_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cLandig_Model);
            break;
        case nspPackId::EFFECT_CURVEAIR_30050:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cCurve_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cCurve_Model);
            break;
        case nspPackId::EFFECT_CRASH_30060:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cCrash_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cCrash_Model);
            break;
        case nspPackId::EFFECT_DASH_30070:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cDash_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(rcBaseRace_Task.cResidenceEffect.m_cDash_Model);
            break;
        case nspPackId::EFFECT_GETAGP_30080:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGetAGP_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGetAGP_Model);
            break;
        case nspPackId::EFFECT_FLLWLINE_30090:
            nspNnUtil::BinSetUpTexList_Texture(&nspFollowLine::psTexList_Union,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::EFFECT_CRASHC_30100:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cCrashCrara_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cCrashCrara_Model);
            break;
        case nspPackId::EFFECT_BADTRK_30110:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cBadTrack_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cBadTrack_Model);
            break;
        case nspPackId::EFFECT_GEARCH01_30120:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGearChenge01_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGearChenge01_Model);
            break;
        case nspPackId::EFFECT_GEARCH02_30130:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGearChenge02_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGearChenge02_Model);
            break;
        case nspPackId::EFFECT_GEARCH03_30140:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGearChenge03_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGearChenge03_Model);
            break;
        case nspPackId::EFFECT_GEARCHRT_30150:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGearChengeRt_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGearChengeRt_Model);
            break;
        case nspPackId::EFFECT_FALSESTART00_30170:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cFalseStart00_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cFalseStart00_Model);
            break;
        case nspPackId::EFFECT_FALSESTART01_30180:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cFalseStart01_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cFalseStart01_Model);
            break;
        case nspPackId::EFFECT_GCTRL_00_30190:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGravityCtrl00_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGravityCtrl00_Model);
            break;
        case nspPackId::EFFECT_GCTRL_01_30200:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGravityCtrl01_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGravityCtrl01_Model);
            break;
        case nspPackId::EFFECT_GCTRL_02_30210:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGravityCtrl02_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGravityCtrl02_Model);
            break;
        case nspPackId::EFFECT_MIST_30230:
            nspNnUtil::BinSetUpTexList_Texture(&clsIonMist_Task::m_psTex,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::EFFECT_ST02_SIDARIDE_30240:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cSidaRide_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cSidaRide_Model);
            break;
        case nspPackId::EFFECT_ST01_ROBOCURV_30250:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cRoboCurv_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cRoboCurv_Model);
            break;
        case nspPackId::EFFECT_MINIWAVE_30260:
            nspNnUtil::BinSetUpTexList_Texture(&nspMiniWave::psTexList_MiniWave,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::EFFECT_BACKRIBBON_30270:
            nspNnUtil::BinSetUpTexList_Texture(&nspBackRibbon::psTexList_BackRibbon,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::EFFECT_GIMICKLINE_30280:
            nspNnUtil::BinSetUpTexList_Texture(&nspFollowLine::psTexList_Gimick,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::EFFECT_LANDINGWATERTRICK_30290:
            nspNnUtil::BinSetUp_Model(
                reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                    rcBaseRace_Task.cResidenceEffect.m_cLandingWaterTrick_Model),
                sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cLandingWaterTrick_Model);
            break;
        case nspPackId::EFFECT_LANDINGWATERTRICK_30300:
            nspNnUtil::BinSetUp_Model(
                reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                    rcBaseRace_Task.cResidenceEffect.m_cLandingWaterJump_Model),
                sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cLandingWaterJump_Model);
            break;
        case nspPackId::EFFECT_WAVYTEXTURE_30310:
            break;
        case nspPackId::EFFECT_ST11_DISELECTRIC_30320:
            nspNnUtil::BinSetUpTexList_Texture(&clsDisElectric_Task::m_tpsTexList,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::EFFECT_REFRECT_PLANE_START_30330... nspPackId::
            EFFECT_REFRECT_PLANE_END_30339:
            break;
        case nspPackId::EFFECT_ST15_METEOFALL_30340:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cMeteoriteFall_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cMeteoriteFall_Model);
            break;
        case nspPackId::EFFECT_ST15_DIVEEFFECT_30350:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cDiveEffect_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cDiveEffect_Model);
            break;
        case nspPackId::EFFECT_ST15_METEO_EXPLODE_30360:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cMeteoExplode_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cMeteoExplode_Model);
            break;
        case nspPackId::EFFECT_ST15_BOSS_CRUSH_30370:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cBossCrush_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cBossCrush_Model);
            break;
        case nspPackId::EFFECT_ST15_BOSS_CRUSH2_30371:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cBossCrush2_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cBossCrush2_Model);
            break;
        case nspPackId::EFFECT_POWER_HIT_30380:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cPowerHit_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cPowerHit_Model);
            break;
        case nspPackId::EFFECT_ST15_BOSS_APPEAR_30390:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cBossAppear_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cBossAppear_Model);
            break;
        case nspPackId::EFFECT_TRICK_X_FLASHLINE_30400:
            nspNnUtil::BinSetUp_Model(
                reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                    rcBaseRace_Task.cResidenceEffect.m_cTrickXFlashLine_Model),
                sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cTrickXFlashLine_Model);
            break;
        case nspPackId::EFFECT_TRICK_X_RING_30410:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cTrickXRing_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cTrickXRing_Model);
            break;
        case nspPackId::EFFECT_ST07_BORN_RING_30420:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cBornRing_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cBornRing_Model);
            break;
        case nspPackId::EFFECT_ST07_PTOBJ_30430:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cSt07PTObj_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cSt07PTObj_Model);
            break;
        case nspPackId::EFFECT_ST07_FLOOR_30440:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cSt07Floor_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cSt07Floor_Model);
            break;
        case nspPackId::EFFECT_ST07_FLOOR_G_30450:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cSt07FloorG_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cSt07FloorG_Model);
            break;
        case nspPackId::EFFECT_ST07_BORN_SPRING_30460:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cBornSpring_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cBornSpring_Model);
            break;
        case nspPackId::EFFECT_ST14_FAN_L_EFFECT_30470:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cSt14FanL_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cSt14FanL_Model);
            break;
        case nspPackId::EFFECT_ST14_FAN_S_EFFECT_30480:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cSt14FanS_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cSt14FanS_Model);
            break;
        case nspPackId::EFFECT_ST07_BORN_ITEMBOX_30490:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cBornItemBox_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cBornItemBox_Model);
            break;
        case nspPackId::EFFECT_ST07_BORN_DPANEL_30500:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cBornDPanel_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cBornDPanel_Model);
            break;
        case nspPackId::EFFECT_GC_EMPTY_EFFECT_30510:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGravityEmpty_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGravityEmpty_Model);
            break;
        case nspPackId::EFFECT_ST07_FLOOR_HOLE_30520:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cSt07FloorHole_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cSt07FloorHole_Model);
            break;
        case nspPackId::EFFECT_GRAVITY_LO_30540:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGravityLocal_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGravityLocal_Model);
            break;
        case nspPackId::EFFECT_ATTACK_BOOST_30610:
            nspNnUtil::BinSetUp_Model(
                reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(nspGame::asAttackData[19].sModel1),
                sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(nspGame::asAttackData[19].sModel1);
            break;
        case nspPackId::EFFECT_LOCKON_MOT:
            clsLockOnFixed3D_Task::registModel(sBinInfo);
            break;
        case nspPackId::EFFECT_LOCKON_MATMOT:
            clsLockOnAppoint3D_Task::registModel(sBinInfo);
            break;
        case nspPackId::EFFECT_GEARCH_TYPE_30620:
            nspNnUtil::BinSetUp_Model(reinterpret_cast<clsModelType_OB_TX_MO_MA_MF&>(
                                          rcBaseRace_Task.cResidenceEffect.m_cGearTypeChange_Model),
                                      sBinInfo.opu8Bin);
            nspNnUtil::CalcUnionNnMtxBuffer_withTRS(
                rcBaseRace_Task.cResidenceEffect.m_cGearTypeChange_Model);
            break;
        case nspPackId::PARTICLE_32000:
            nspNnUtil::BinSetUpTexList_Texture(&nspParticleSet::psTexList_UnionParticle,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::PARTICLE_32100:
            if (!bPartcleInit) {
                nspParticleData::initData();
                bPartcleInit = true;
            }
            nspParticleData::setUnionData(
                static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
            break;
        case nspPackId::PARTICLE_GAME_32500:
            if (!bPartcleInit) {
                nspParticleData::initData();
                bPartcleInit = true;
            }
            nspParticleData::setGameData(
                static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
            break;
        case nspPackId::PARTICLE_MODE_32550:
            if (!bPartcleInit) {
                nspParticleData::initData();
                bPartcleInit = true;
            }
            nspParticleData::setModeData(
                static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
            break;
        case nspPackId::PARTICLE_SET_33000:
            if (!bPartcleInit) {
                nspParticleData::initData();
                bPartcleInit = true;
            }
            nspParticleData::setSetData(
                static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
            break;
        case nspPackId::SCRIPT_BINARY_START... nspPackId::SCRIPT_BINARY_END: {
            switch (pu16Type[u32g]) {
            case nspPackId::SCRIPT_BINARY_35000:
                clsScript_Task::setBinaryData(static_cast<u8*>(pvAddrI) +
                                              pu32OffsetNo[pu16AddBinNum[u32g]]);
                clsScriptCamera::initData();
                clsScriptModelManager::initData();
                clsScriptMotion::initData();
                clsScriptWaitString_Task::initData();
                clsScript2D_Task::initData();
                clsScriptEffect_Task::initData();
                clsScriptShadowObj::initData();
                nspGlobal::sTask.pcBaseScript->m_pcLight->initData();
                nspNnUtil::InitUnionNnData();
                break;
            default:
                break;
            }
        } break;
        case nspPackId::SCRIPT_MODEL_START... nspPackId::SCRIPT_MODEL_END: {
            switch (pu16Type[u32g]) {
            case nspPackId::SCRIPT_MODEL_35050:
                clsScriptModelManager::addData_Ob_Tx(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_MODEL_MOT_35060:
                clsScriptModelManager::addData_Ob_Tx_Mo(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_MODEL_MAT_35070:
                clsScriptModelManager::addData_Ob_Tx_Ma(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_MODEL_MOT_MAT_35080:
                clsScriptModelManager::addData_Ob_Tx_Mo_Ma(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_MODEL_MAT_MOF_35090:
                clsScriptModelManager::addData_Ob_Tx_Ma_Mfo(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_MODEL_MOT_MAT_MOF_35100:
                clsScriptModelManager::addData_Ob_Tx_Mo_Ma_Mfo(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_MODEL_MOF_35110:
                clsScriptModelManager::addData_Ob_Tx_Mfo(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_MODEL_FRAMETEX_35120:
                clsScriptModelManager::addData_Ob(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_MODEL_MOTIONDATA_35130:
                clsScriptMotion::setMotionData(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_MODEL_MATMOTIONDATA_35140:
                clsScriptMotion::setMatMotionData(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_MODEL_MORFMOTIONDATA_35150:
                clsScriptMotion::setMorfMotionData(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_NT_MODEL_35160:
                clsScriptModelManager::addData_Ob(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_NT_MODEL_MOT_35170:
                clsScriptModelManager::addData_Ob_Mo(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_NT_MODEL_MAT_35180:
                clsScriptModelManager::addData_Ob_Ma(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_NT_MODEL_MOT_MAT_35190:
                clsScriptModelManager::addData_Ob_Mo_Ma(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            default:
                break;
            }
        } break;
        case nspPackId::SCRIPT_CAMERA_START... nspPackId::SCRIPT_CAMERA_END: {
            switch (pu16Type[u32g]) {
            case nspPackId::SCRIPT_CAMERAMOTIOM_35250:
                clsScriptCamera::addData(
                    static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            case nspPackId::SCRIPT_LIGHTMOTIOM_35270:
                PackAddScriptLightMotion(
                    pvAddrI, pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
                break;
            default:
                break;
            }
        } break;
        case nspPackId::SCRIPT_EFFECT_START... nspPackId::SCRIPT_EFFECT_END: {
            switch (pu16Type[u32g]) {
            case nspPackId::SCRIPT_DATA_EFFECT_35300:
            case nspPackId::SCRIPT_DATA_EFFECT_MAT_35310:
                clsScriptEffect_Task::addData(sBinInfo.opu8Bin);
                break;
            case nspPackId::SCRIPT_SHADOW_35320:
                clsScriptShadowObj::setShadowData(0, sBinInfo);
                break;
            case nspPackId::SCRIPT_SHADOW_35321:
                clsScriptShadowObj::setShadowData(1, sBinInfo);
                break;
            case nspPackId::SCRIPT_EFFECT_GRAVITY_35330:
                PackSetGravityModel2(rcBaseScript_Task.cResidenceEffect, sBinInfo);
                break;
            case nspPackId::SCRIPT_DATA_SUNLENZ_35340:
                nspNnUtil::BinSetUpTexList_Texture(
                    &rcBaseScript_Task.cResidenceEffect.m_psResidence_TexList,
                    NULL,
                    static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
                break;
            default:
                break;
            }
        } break;
        case nspPackId::SCRIPT_ETC_START... nspPackId::SCRIPT_ETC_END: {
            switch (pu16Type[u32g]) {
            case nspPackId::SCRIPT_2D_37510:
                nspNnUtil::BinSetUpTexList_Texture(&clsScript2D_Task::m_tpsTexList,
                                                   NULL,
                                                   static_cast<u8*>(pvAddrI) +
                                                       pu32OffsetNo[pu16AddBinNum[u32g]]);
                break;
            case nspPackId::SCRIPT_FONT_DATA_37520:
                clsSrFontSystem::GS()->setFontDataFromFile(
                    nspSrFontSystem::FONT_NO_EVENT,
                    static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]],
                    static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 1],
                    static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 2],
                    -2);
                break;
            default:
                break;
            }
        } break;
        case nspPackId::ITEMTRAP_BOMB_38001:
            clsItemBomb_Task::registModel(sBinInfo);
            break;
        case nspPackId::STORY_LOADING_45000:
            nspNnUtil::BinSetUpTexList_Texture(
                &clsGameMgr::GS()->getStoryMgr()->m_psTexList_Loading,
                NULL,
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::STORY_2D_45001:
            nspNnUtil::BinSetUpTexList_Texture(&nspMission2D::psTexList_Mission2D,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::TITLE_SELECT_50000:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setPackData(sBinInfo);
            break;
        case nspPackId::FONT_DATA_50010:
        case nspPackId::FONT_USERNAME_DATA_50040:
            clsSrFontSystem::GS()->setFontDataFromFile(
                static_cast<nspSrFontSystem::enmFontNo>(u32Context),
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]],
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 1],
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 2],
                -2);
            break;
        case nspPackId::FONT_MISSION_DATA_50020:
            clsSrFontSystem::GS()->setFontDataFromFile(
                nspSrFontSystem::FONT_NO_MISSION,
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]],
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 1],
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 2],
                -2);
            break;
        case nspPackId::FONT_MENUDATA_50030:
            clsSrFontSystem::GS()->setFontDataFromFile(
                static_cast<nspSrFontSystem::enmFontNo>(u32Context + 4),
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]],
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 1],
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 2],
                -2);
            break;
        case nspPackId::FONT_BTN_DATA_50050:
            clsSrFontSystem::GS()->setBtnDataFromFile(
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g]],
                true,
                static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 1]);
            break;
        case nspPackId::ADVERTISE_FLASH_TEXTURE_52000:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(1, sBinInfo);
            break;
        case nspPackId::ADVERTISE_FLASH_DATA_52005:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashData(1, sBinInfo);
            break;
        case nspPackId::ADVERTISE_BG_MODEL_52006:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setBGModel(sBinInfo);
            break;
        case nspPackId::ADVERTISE_CS_GEARPARTS_52010:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setGearPartsTexture(sBinInfo);
            break;
        case nspPackId::CHARACTER_SELECT_FLASHTEX_52020:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(3, sBinInfo);
            break;
        case nspPackId::CHARACTER_SELECT_FLASH_52025:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashData(3, sBinInfo);
            break;
        case nspPackId::MAIN_MENU_SELECT_FLASHTEX_52030:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(2, sBinInfo);
            break;
        case nspPackId::MAIN_MENU_SELECT_FLASH_52035:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashData(2, sBinInfo);
            break;
        case nspPackId::TITLE_FLASHTEX_52040:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(0, sBinInfo);
            break;
        case nspPackId::TITLE_FLASH_52045:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashData(0, sBinInfo);
            break;
        case nspPackId::ENTRY_MODEL_UNI_MOT_52050:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setEntryMotion(
                0, static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
            break;
        case nspPackId::ENTRY_MODEL_EGG_MOT_52060:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setEntryMotion(
                1, static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
            break;
        case nspPackId::ENTRY_MODEL_ROBO_MOT_52070:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setEntryMotion(
                2, static_cast<u8*>(pvAddrI), pu32OffsetNo, pu16AddBinNum[u32g], pu8BinNum[u32g]);
            break;
        case nspPackId::EXTRA_MENU_SELECT_FLASHTEX_52080:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(10, sBinInfo);
            break;
        case nspPackId::EXTRA_MENU_SELECT_FLASH_52085:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashData(10, sBinInfo);
            break;
        case nspPackId::OPTION_MENU_SELECT_FLASHTEX_52090:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(4, sBinInfo);
            break;
        case nspPackId::OPTION_MENU_SELECT_FLASHTEX_52091:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(5, sBinInfo);
            break;
        case nspPackId::OPTION_MENU_SELECT_FLASHTEX_52092:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(6, sBinInfo);
            break;
        case nspPackId::OPTION_MENU_SELECT_FLASHTEX_52093:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(7, sBinInfo);
            break;
        case nspPackId::OPTION_MENU_SELECT_FLASHTEX_52094:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(8, sBinInfo);
            break;
        case nspPackId::OPTION_MENU_SELECT_FLASHTEX_52095:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashTexture(9, sBinInfo);
            break;
        case nspPackId::OPTION_MENU_SELECT_FLASH_52099:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setFlashData(4, sBinInfo);
            break;
        case nspPackId::TITLE_LOGO_52100:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setPackDataSub(0, sBinInfo);
            break;
        case nspPackId::SAVEDATA_52110:
        case nspPackId::SAVEDATA_52111:
        case nspPackId::SAVEDATA_52112:
        case nspPackId::SAVEDATA_52113:
        case nspPackId::SAVEDATA_52114:
        case nspPackId::SAVEDATA_52115:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setPackDataSub(pu16Type[u32g] - 52106,
                                                                        sBinInfo);
            break;
        case nspPackId::SHOPDATA_52120:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setPackDataSub(1, sBinInfo);
            break;
        case nspPackId::SHOPCHAO_52130: {
            pcAdvertiseMgr_Task = static_cast<clsAdvertiseMgr_Task*>(pcTaskI);
            PackCreateModel(pcAdvertiseMgr_Task->m_pcShopChao_Model, sBinInfo);
        } break;
        case nspPackId::SHOPOBJ_52140: {
            pcAdvertiseMgr_Task = static_cast<clsAdvertiseMgr_Task*>(pcTaskI);
            PackCreateModel(pcAdvertiseMgr_Task->m_pcShopObj_Model, sBinInfo);
        } break;
        case nspPackId::GEARGALLERY_52150:
            static_cast<clsAdvertiseMgr_Task*>(pcTaskI)->setPackDataSub(2, sBinInfo);
            break;
        case nspPackId::KEYBOARD_2D_53000:
            nspNnUtil::BinSetUpTexList_Texture(&nspKeyboard2D::psTexList_Keyboard2D,
                                               NULL,
                                               static_cast<u8*>(pvAddrI) +
                                                   pu32OffsetNo[pu16AddBinNum[u32g]]);
            break;
        case nspPackId::SAVE_DATA_FILE_53100:
        case nspPackId::SAVE_DATA_FILE_53101:
            nspMemoryCardFile::SetIconImage(
                0, static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 0]);
            nspMemoryCardFile::SetIconImage(
                1, static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 1]);
            nspMemoryCardFile::SetIconImage(
                2, static_cast<u8*>(pvAddrI) + pu32OffsetNo[pu16AddBinNum[u32g] + 2]);
            break;
        case nspPackId::SHADOW_TEST_60010:
            new clsShadowVolume_Task(sBinInfo);
            break;
        }
        ++u32g;
    } while (u32g < u32GroupNum);
    if (psStageObjTop != NULL) {
        PackSetStageData(this, psStageObjTop, sBinInfo_stl);
        if (nspGlobal::sTask.pcBaseRace->getStageNo() == 10) {
            if (clsSnowBall_Task::GS() != NULL) {
                clsSnowBall_Task::GS()->setShadowModel(sBinInfoTmp);
            }
            if (clsFallSnowBall_Task::GS() != NULL) {
                clsFallSnowBall_Task::GS()->setShadowModel(sBinInfoTmp2);
            }
            if (clsGLinkSnowman_Task::GS() != NULL) {
                clsGLinkSnowman_Task::GS()->setShadowModel(sBinInfoTmp3);
            }
        }
    }
}
#pragma pop
