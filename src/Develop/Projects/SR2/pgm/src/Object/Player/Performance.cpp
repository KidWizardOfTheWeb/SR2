#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.hpp"

stcData* clsPrfm::getDataPtr() {
    if (this->m_pcGearCtrl->m_eCtrlMode != CTRL_MODE_WALK) {
        return &this->m_sData;
    }
    return &this->m_sWalk;
}

void clsPrfm::setMaxAgp(float f32MaxAGP) {
    (this->m_sWalk).f32MaxAgp = f32MaxAGP;
    (this->m_sBase).f32MaxAgp = f32MaxAGP;
    return;
}

void clsPrfm::setRingCapacity(signed short s16Ring) {
    (this->m_sWalk).s16RingCapacity = s16Ring;
    (this->m_sBase).s16RingCapacity = s16Ring;
    return;
}

// Range: 0x1E17F0 -> 0x1E1C0C
// this: r18
/*
void clsPrfm::updateData()
{
  clsGearCtrl *pcVar1;
  clsPlayerTask *pcVar2;
  enmBaseType eVar3;
  uint uVar4;
  enmFlag eVar5;
  clsPlayerPhysic *pcVar6;
  int iVar7;
  long lVar8;
  enmFlag eVar9;
  float fVar10;

  pcVar1 = this->m_pcGearCtrl;
  pcVar2 = pcVar1->m_pcPlayer;
  eVar3 = pcVar2->m_pcCharacter->m_eBaseType;
  (this->m_sData).f32Speed[0] =
       this->m_f32AdjustSpeedRate *
       ((pcVar1->m_sAddPrfmData).f32MaxSpeedRate * (this->m_sBase).f32Speed[0] +
       (pcVar1->m_sAddPrfmData).af32MaxSpeed[0] + 0.0);
  fVar10 = toaf32GpUsedRate[eVar3];
  (this->m_sData).f32Accele[0] =
       this->m_f32AdjustAcceleRate *
       ((this->m_sBase).f32Accele[0] * (pcVar1->m_sAddPrfmData).f32AcceleRate +
       (pcVar1->m_sAddPrfmData).af32Accele[0] + 0.0);
  (this->m_sData).f32Speed[1] =
       this->m_f32AdjustSpeedRate *
       ((pcVar1->m_sAddPrfmData).f32MaxSpeedRate * (this->m_sBase).f32Speed[1] +
       (pcVar1->m_sAddPrfmData).af32MaxSpeed[1] + 0.0);
  (this->m_sData).f32Accele[1] =
       this->m_f32AdjustAcceleRate *
       ((this->m_sBase).f32Accele[1] * (pcVar1->m_sAddPrfmData).f32AcceleRate +
       (pcVar1->m_sAddPrfmData).af32Accele[1] + 0.0);
  (this->m_sData).f32Speed[2] =
       this->m_f32AdjustSpeedRate *
       ((pcVar1->m_sAddPrfmData).f32MaxSpeedRate * (this->m_sBase).f32Speed[2] +
       (pcVar1->m_sAddPrfmData).af32MaxSpeed[2] + 0.0);
  (this->m_sData).f32Accele[2] =
       this->m_f32AdjustAcceleRate *
       ((this->m_sBase).f32Accele[2] * (pcVar1->m_sAddPrfmData).f32AcceleRate +
       (pcVar1->m_sAddPrfmData).af32Accele[2] + 0.0);
  (this->m_sData).f32RotateSpeed =
       (this->m_sBase).f32RotateSpeed * (pcVar1->m_sAddPrfmData).f32RotateSpeedRate +
       (pcVar1->m_sAddPrfmData).f32RotateSpeed + 0.0;
  (this->m_sData).f32RotateAccele =
       (this->m_sBase).f32RotateAccele * (pcVar1->m_sAddPrfmData).f32RotateAcceleRate +
       (pcVar1->m_sAddPrfmData).f32RotateAccele + 0.0;
  (this->m_sData).f32Grip =
       (this->m_sBase).f32Grip * (pcVar1->m_sAddPrfmData).f32GripRate +
       (pcVar1->m_sAddPrfmData).f32Grip + 0.0;
  (this->m_sData).f32JumpSpeed = (this->m_sBase).f32JumpSpeed;
  (this->m_sData).f32JumpAccele = (this->m_sWalk).f32JumpAccele;
  (this->m_sData).f32Durability =
       (this->m_sBase).f32Durability * (pcVar1->m_sAddPrfmData).f32DurabilityRate +
       (pcVar1->m_sAddPrfmData).f32GCtrlDischargeSpeed + 0.0;
  (this->m_sData).f32MaxAgp = (this->m_sBase).f32MaxAgp + (pcVar1->m_sAddPrfmData).f32GPTakeRate;
  (this->m_sData).u32Ability =
       (this->m_sBase).u32Ability | (uint)(pcVar1->m_sAddPrfmData).f32GDiveSpeedRate;
  (this->m_sData).f32GCtrlDischargeSpeed =
       (this->m_sBase).f32GCtrlDischargeSpeed + (pcVar1->m_sAddPrfmData).f32GCtrlGpUseRate;
  (this->m_sData).f32GDiveSpeedRate =
       (this->m_sBase).f32GDiveSpeedRate * (pcVar1->m_sAddPrfmData).f32GDiveGpUseRate;
  (this->m_sData).f32GPTakeRate =
       (this->m_sBase).f32GPTakeRate + (float)(pcVar1->m_sAddPrfmData).s32AttackEnableFrame;
  (this->m_sData).f32GCtrlGpUseRate =
       (this->m_sBase).f32GCtrlGpUseRate * fVar10 +
       *(float *)&(pcVar1->m_sAddPrfmData).s16RingCapacity + 0.0;
  (this->m_sData).f32GDiveGpUseRate =
       (this->m_sBase).f32GDiveGpUseRate * fVar10 + *(float *)&pcVar1->field_0xbc + 0.0;
  (this->m_sData).s32AttackEnableFrame =
       (this->m_sBase).s32AttackEnableFrame + *(int *)&pcVar1->field_0xc0;
  (this->m_sData).s16RingCapacity = (this->m_sBase).s16RingCapacity + *(short *)&pcVar1->field_0xc4;
  (this->m_sData).s8TrickRank = (this->m_sBase).s8TrickRank + pcVar1->field_0xc6;
  (this->m_sData).s8ItemRank = (this->m_sBase).s8ItemRank + pcVar1->field_0xc7;
  (this->m_sWalk).s16RingCapacity = (this->m_sBase).s16RingCapacity + *(short *)&pcVar1->field_0xc4;
  (this->m_sWalk).f32MaxAgp = (this->m_sBase).f32MaxAgp + (pcVar1->m_sAddPrfmData).f32GPTakeRate;
  if ((pcVar2->m_eStatus & STATUS_LINK_ONE) != STATUS_NULL) {
    (this->m_sData).u32Ability = 0;
  }
  lVar8 = (**(code **)(*(int *)&(pcVar2->__base).__base + 0x58))(pcVar2);
  if (lVar8 == 1) {
    uVar4 = (this->m_sData).u32Ability;
  }
  else {
    if (((this->m_sData).u32Ability & 0x20) == 0) {
      pcVar2->m_pcCharacter->m_f32DrawAlpha = 1.0;
      pcVar6 = pcVar2->m_pcPhysic;
      (pcVar6->m_cMaskColFilter).m_tData = ~FLAG_DEFAULT;
      uVar4 = (pcVar6->m_pcPhantom->__base).__base.__base.m_collidable.__base.m_broadPhaseHandle.
              m_collisionFilterInfo;
      iVar7 = getShapePhantom__16hkCharacterProxyFv(pcVar6->m_pcProxy);
      *(uint *)(iVar7 + 0x2c) = uVar4;
      updateCollisionFilterOnPhantom__7hkWorldFP9hkPhantom28hkUpdateCollectionFilterMode
                (*(undefined4 *)(_m_tpcSingleton__23clsSingleton<8clsHavok> + 4),pcVar6->m_pcPhantom
                 ,0);
    }
    else {
      pcVar2->m_pcCharacter->m_f32DrawAlpha = 0.3;
      pcVar6 = pcVar2->m_pcPhysic;
      eVar9 = (pcVar6->m_cMaskColFilter).m_tData & 0xfffbfffb;
      (pcVar6->m_cMaskColFilter).m_tData = eVar9;
      eVar5 = (pcVar6->m_pcPhantom->__base).__base.__base.m_collidable.__base.m_broadPhaseHandle.
              m_collisionFilterInfo;
      iVar7 = getShapePhantom__16hkCharacterProxyFv(pcVar6->m_pcProxy);
      *(enmFlag *)(iVar7 + 0x2c) = eVar5 & eVar9;
      updateCollisionFilterOnPhantom__7hkWorldFP9hkPhantom28hkUpdateCollectionFilterMode
                (*(undefined4 *)(_m_tpcSingleton__23clsSingleton<8clsHavok> + 4),pcVar6->m_pcPhantom
                 ,0);
    }
    uVar4 = (this->m_sData).u32Ability;
  }
  if (((uVar4 & 8) == 0) || (((this->m_sBase).u32Ability & 8) != 0)) {
    this->m_f32InfiniGpFrame = -10.0;
    if (this->m_pcGearCtrl->m_eCtrlNo == CTRL_MAG) {
      clsGearCtrl::setUnuseGearLevel(this->m_pcGearCtrl,LV_03);
    }
  }
  else if (this->m_f32InfiniGpFrame == -10.0) {
    this->m_f32InfiniGpFrame = 1500.0;
    (pcVar2->m_cGravityActionManager).m_f32Point = (this->m_sData).f32MaxAgp;
    clsGravityActionManager::checkLimitPoint(&pcVar2->m_cGravityActionManager);
  }
  else if (this->m_f32InfiniGpFrame == -1.0) {
    (this->m_sData).u32Ability = uVar4 & 0xfffffff7;
  }
  if (*(int *)(_m_tpcSingleton__26clsSingleton<10clsGameMgr> + 0x80) == 0xb) {
    fVar10 = (this->m_sData).f32Speed[2];
  }
  else {
    Limit(&this->m_sBase);
    fVar10 = (this->m_sData).f32Speed[2];
  }
  pcVar2->m_f32MaxSpeed = fVar10;
  return;
}
*/


/*
void clsPrfm::setup(class clsCharacter * pcChara, class clsGearCtrl * pcGearCtrl) {
  enmWalkType eVar1;
  stcData *psVar2;
  stcCtrlData *psVar3;
  enmBaseType eVar4;
  uint uVar5;
  char cVar6;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int iVar7;

  eVar1 = pcChara->m_eWalkType;
  psVar2 = pcChara->m_posData;
  psVar3 = pcGearCtrl->m_posData;
  eVar4 = pcChara->m_eBaseType;
  this->m_pcGearCtrl = pcGearCtrl;
  fVar8 = osWalkPrfm[eVar1].f32Accele[0];
  fVar9 = osWalkPrfm[eVar1].f32Speed[1];
  (this->m_sWalk).f32Speed[0] = osWalkPrfm[eVar1].f32Speed[0];
  (this->m_sWalk).f32Accele[0] = fVar8;
  (this->m_sWalk).f32Speed[1] = fVar9;
  fVar8 = osWalkPrfm[eVar1].f32Speed[2];
  fVar9 = osWalkPrfm[eVar1].f32Accele[2];
  (this->m_sWalk).f32Accele[1] = osWalkPrfm[eVar1].f32Accele[1];
  (this->m_sWalk).f32Speed[2] = fVar8;
  (this->m_sWalk).f32Accele[2] = fVar9;
  fVar8 = osWalkPrfm[eVar1].f32RotateAccele;
  fVar9 = osWalkPrfm[eVar1].f32Grip;
  (this->m_sWalk).f32RotateSpeed = osWalkPrfm[eVar1].f32RotateSpeed;
  (this->m_sWalk).f32RotateAccele = fVar8;
  (this->m_sWalk).f32Grip = fVar9;
  (this->m_sWalk).f32JumpSpeed = 0.31578946;
  fVar8 = osWalkPrfm[eVar1].f32Durability;
  (this->m_sWalk).f32JumpAccele = 0.01754386;
  (this->m_sWalk).f32MaxAgp = 100.0;
  (this->m_sWalk).f32Durability = fVar8;
  (this->m_sWalk).s16RingCapacity = 100;
  (this->m_sWalk).s8TrickRank = '\0';
  (this->m_sWalk).s8ItemRank = '\0';
  (this->m_sWalk).f32GPTakeRate = 1.0;
  (this->m_sWalk).f32GCtrlGpUseRate = 1.0;
  (this->m_sWalk).f32GDiveGpUseRate = 1.0;
  (this->m_sWalk).u32Ability = 0;
  if (*(int *)(m_tpcSingleton->m_eMode) != 0xb) {
    Limit(&this->m_sBase);
  }
  fVar8 = psVar2->f32Accele[2] + psVar3->f32Weight;
  uVar5 = oasBasePrfm[eVar4].u32Ability;
  fVar12 = fVar8 + 1.0;
  fVar10 = 1.0 - fVar8;
  this->m_f32WeightRate = fVar8;
  fVar8 = oasBasePrfm[eVar4].f32Accele[0];
  fVar9 = oasBasePrfm[eVar4].f32Speed[1];
  (this->m_sBase).f32Speed[0] = fVar12 * oasBasePrfm[eVar4].f32Speed[0];
  (this->m_sBase).f32Accele[0] = fVar10 * fVar8;
  fVar11 = oasBasePrfm[eVar4].f32Accele[1];
  (this->m_sBase).f32Speed[1] = fVar12 * fVar9;
  fVar8 = oasBasePrfm[eVar4].f32Speed[2];
  fVar9 = oasBasePrfm[eVar4].f32Accele[2];
  (this->m_sBase).f32Accele[1] = fVar10 * fVar11;
  (this->m_sBase).f32Speed[2] = fVar12 * fVar8;
  fVar11 = oasBasePrfm[eVar4].f32RotateSpeed;
  (this->m_sBase).f32Accele[2] = fVar10 * fVar9;
  fVar8 = oasBasePrfm[eVar4].f32RotateAccele;
  fVar9 = oasBasePrfm[eVar4].f32Grip;
  (this->m_sBase).f32RotateSpeed = fVar10 * fVar11;
  (this->m_sBase).f32RotateAccele = fVar10 * fVar8;
  (this->m_sBase).f32Grip = fVar10 * fVar9;
  fVar8 = oasBasePrfm[eVar4].f32Durability;
  (this->m_sBase).f32JumpSpeed = 0.31578946;
  (this->m_sBase).f32JumpAccele = 0.01754386;
  (this->m_sBase).f32MaxAgp = 100.0;
  (this->m_sBase).f32Durability = fVar12 * fVar8;
  (this->m_sBase).s16RingCapacity = 100;
  (this->m_sBase).s8TrickRank = '\0';
  (this->m_sBase).s8ItemRank = '\0';
  (this->m_sBase).f32GPTakeRate = 1.0;
  (this->m_sBase).f32GCtrlGpUseRate = 1.0;
  (this->m_sBase).f32GDiveGpUseRate = 1.0;
  (this->m_sBase).u32Ability = uVar5;
  (this->m_sBase).f32GCtrlDischargeSpeed = fRam00b163e4;
  (this->m_sBase).f32GDiveSpeedRate = 1.0;
  iVar7 = *(int *)(m_tpcSingleton->m_eMode);
  if ((iVar7 == 3) || (iVar7 == 9)) {
    if (iVar7 == 3) {
      iVar7 = getFreeAgp_Option();
      cVar6 = (char)iVar7;
    }
    else {
      iVar7 = getRelayAgp_Option();
      cVar6 = (char)iVar7;
    }
    if (cVar6 == '\x02') {
      (this->m_sBase).f32GPTakeRate = (this->m_sBase).f32GPTakeRate * 1.5;
    }
    else if ((cVar6 != '\x01') && (cVar6 == '\0')) {
      (this->m_sBase).f32GPTakeRate = (this->m_sBase).f32GPTakeRate * 0.5;
    }
  }
  if (*(int *)(m_tpcSingleton->m_eMode) != 0xb) {
    Limit(&this->m_sBase);
  }
  clsPrfm::updateData(this);
  return;
}
*/



