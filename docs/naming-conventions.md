# SR2 Naming Conventions

Sonic Riders: Zero Gravity uses Hungarian-style names throughout the game code. Names usually encode ownership, constness, indirection, and the underlying type. The notation is not perfectly mechanical, especially around SDK types, but these rules cover the common patterns seen in `Develop/Projects/SR2/pgm`.

## Core Type Codes

| Code | Meaning | Example |
| :--- | :--- | :--- |
| `u8`, `u16`, `u32` | unsigned integer width | `m_u32TexMainBufSize` |
| `s8`, `s16`, `s32` | signed integer width | `m_s32SubTitleDataPos` |
| `f32`, `f64` | floating point width | `m_f32DrawX` |
| `c8` | character byte | `opc8FileNameI` |
| `b` | boolean or byte flag | `m_bDolbyDigital_Old_PS2` |
| `e` | enum value | `m_eLoop`, `eAllocateI` |
| `c` | class value | `m_cPfCreateTexture` |
| `s` | struct or SDK value | `m_sFrameObj`, `m_sCamera` |
| `pv` | `void*` | `m_pvAc3Work_Heap` |
| `fn` | function pointer or callback | `m_fnDiscError` |

## Declaration Prefixes

| Prefix | Meaning | Example |
| :--- | :--- | :--- |
| `cls` | C++ class | `clsCriMovie`, `clsTask` |
| `stc` | game data struct | `stcData`, `stcTexUV` |
| `enm` | enum type, often nested | `enmAllocate`, `enmLoopFlag` |
| `nsp` | namespace | `nspNnUtil`, `nspMemoryCardFile` |

SDK and middleware types normally keep their vendor names instead of game prefixes, for example `NNS_VECTORFAST`, `PXS_CONTEXT`, `sceCdCLOCK`, `MwsfdFrmObj`, and `ADXM_TPRM`.

## Shape Prefixes

Shape prefixes are composed before the type code. Read them left to right as qualifiers on the named value.

| Prefix | Meaning | Example |
| :--- | :--- | :--- |
| `p` | pointer | `pcAllocatorI`, `psFrameObj` |
| `pp` | pointer to pointer | `oppu8IgnoreResidencePortalData` |
| `r` | reference | `rsBinInfoI`, `rcWorkHeap` |
| `o` | const/read-only | `opc8FileNameI`, `orsDataI`, `opsViewMtxI` |
| `a` | array or array-like collection | `m_as16Volume_Bgm`, `m_au8Ac3Work_Bgm` |
| `ap` | array of pointers, or pointer used as an array | `m_apcModels`, `m_apsBaseCam` |
| `pa` | pointer to an array | `tpsNnMtxList`, `opaNnViewMtx` |

Examples:

```cpp
const c8* opc8FileNameI;      // o + p + c8: const/read-only char pointer
const stcData& orsDataI;      // o + r + s: const/read-only struct reference
const NNS_VECTORFAST* opsPos; // o + p + s: const/read-only SDK struct pointer
u8** ppu8Data;                // p + p + u8: pointer to pointer to bytes
f32 (*psMtxPal)[4][4];        // p + s/a by convention: pointer to matrix array data
```

## Member And Static Storage

| Prefix | Meaning | Example |
| :--- | :--- | :--- |
| `m_` | instance member | `m_u32CancelActiveKey` |
| `m_t` | static member or shared class storage | `m_tapcTask`, `m_ts32MotionNum` |
| `t_` | file-scope or class-scope table/static data | `t_ocGravityGimmickParam` |

Static names still carry the normal type and shape notation after the static prefix:

```cpp
clsSrFontRead_Task* clsSrFontRead_Task::m_tapcTask[21];
s32 clsScriptMotion::m_ts32MotionNum;
u8* clsScriptMotion::m_tapu8MotionData[256];
clsGravityGimmickParam clsPathSecurityRobo_Obj::t_ocGravityGimmickParam;
```

## Parameter Suffixes

Many parameters end with a direction or role suffix.

| Suffix | Common Meaning | Example |
| :--- | :--- | :--- |
| `I` | input parameter | `s32DrawXI`, `u32AdxMaxChNum_BgmI` |
| `O` | output parameter, when present | `rsDstX`, `rsDstY` also appear for outputs |
| `Src` | source value | `s32SrcX`, `s32SrcY` |
| `Dst` | destination value | `rsDstX`, `rsDstY` |

The suffix is descriptive, not part of the type code.

## Common Compositions

| Name | Reading |
| :--- | :--- |
| `m_pcMixer` | instance member pointer to class |
| `m_psObject` | instance member pointer to struct/SDK object |
| `m_sCamera` | instance member struct value |
| `m_cCamDebug` | instance member class value |
| `m_af32Buf` | instance member array of `f32` |
| `m_apsBaseCam` | instance member array of pointers to structs/SDK objects |
| `m_orsData` | instance member const/read-only reference to struct |
| `m_tpvOldLoadDataBuff` | static member `void*` |
| `m_tapu8MotionData` | static member array of `u8*` data pointers |
