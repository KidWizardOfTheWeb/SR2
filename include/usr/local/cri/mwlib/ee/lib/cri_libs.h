#ifndef CRI_LIBS_H
#define CRI_LIBS_H

// CRI ADX library types — PS2 streaming job and file system layer.
// These are third-party C library types; raw C types are used intentionally.

// UUID type (from CRI/ADX library)
struct _UUID {
    unsigned int Data1;   // offset 0x0, size 0x4
    unsigned short Data2; // offset 0x4, size 0x2
    unsigned short Data3; // offset 0x6, size 0x2
    signed char Data4[8]; // offset 0x8, size 0x8
}; // total size: 0x10

// Streaming job chunk
struct SJCK {
    signed char* data; // offset 0x0, size 0x4
    signed int len;    // offset 0x4, size 0x4
}; // total size: 0x8

// Streaming job vtable
struct _sj_vtbl {
    void (*QueryInterface)();                                                      // offset 0x0
    void (*AddRef)();                                                              // offset 0x4
    void (*Release)();                                                             // offset 0x8
    void (*Destroy)(struct SJ_OBJ*);                                               // offset 0xC
    struct _UUID* (*GetUuid)(struct SJ_OBJ*);                                      // offset 0x10
    void (*Reset)(struct SJ_OBJ*);                                                 // offset 0x14
    void (*GetChunk)(struct SJ_OBJ*, signed int, signed int, struct SJCK*);        // offset 0x18
    void (*UngetChunk)(struct SJ_OBJ*, signed int, struct SJCK*);                  // offset 0x1C
    void (*PutChunk)(struct SJ_OBJ*, signed int, struct SJCK*);                    // offset 0x20
    signed int (*GetNumData)(struct SJ_OBJ*, signed int);                          // offset 0x24
    signed int (*IsGetChunk)(struct SJ_OBJ*, signed int, signed int, signed int*); // offset 0x28
    void (*EntryErrFunc)(struct SJ_OBJ*, void (*)(void*, signed int), void*);      // offset 0x2C
}; // total size: 0x30

// Streaming job object
struct SJ_OBJ {
    struct _sj_vtbl* vtbl; // offset 0x0, size 0x4
}; // total size: 0x4

// ADX file system object
struct _adx_fs {
    signed char used;       // offset 0x0, size 0x1
    signed char stat;       // offset 0x1, size 0x1
    signed char sjflag;     // offset 0x2, size 0x1
    signed char stopnw_flg; // offset 0x3, size 0x1
    void* stm;              // offset 0x4, size 0x4
    struct SJ_OBJ* sj;      // offset 0x8, size 0x4
    signed int fnsct;       // offset 0xC, size 0x4
    signed int skpos;       // offset 0x10, size 0x4
    signed int rdstpos;     // offset 0x14, size 0x4
    signed int rqsct;       // offset 0x18, size 0x4
    signed int rdsct;       // offset 0x1C, size 0x4
    signed char* buf;       // offset 0x20, size 0x4
    signed int bsize;       // offset 0x24, size 0x4
    signed int rqrdsct;     // offset 0x28, size 0x4
    signed int ofst;        // offset 0x2C, size 0x4
    void* dir;              // offset 0x30, size 0x4
}; // total size: 0x34

enum MwsfdStat {
    MWSFD_STAT_STOP = 0,
    MWSFD_STAT_PREP = 1,
    MWSFD_STAT_PLAYING = 2,
    MWSFD_STAT_PLAYEND = 3,
    MWSFD_STAT_ERROR = 4,
    MWE_PLY_STAT_STOP = 0,
    MWE_PLY_STAT_PREP = 1,
    MWE_PLY_STAT_PLAYING = 2,
    MWE_PLY_STAT_PLAYEND = 3,
    MWE_PLY_STAT_ERROR = 4,
    MWSFD_STAT_END = 5,
    MWSFD_STAT_ENUM_BE_SINT32 = 2147483647,
};

enum MwsfdVideoCodec {
    MWSFD_VIDEOCODEC_UNKNOWN = 0,
    MWSFD_VIDEOCODEC_M1V = 1,
    MWSFD_VIDEOCODEC_M2V = 2,
    MWSFD_VIDEOCODEC_M4V = 3,
    MWSFD_VIDEOCODEC_H264 = 4,
    MWSFD_VIDEOCODEC_END = 5,
    MWSFD_VIDEOCODEC_ENUM_BE_SINT32 = 2147483647,
};

enum MwsfdPtype {
    MWSFD_PTYPE_I = 1,
    MWSFD_PTYPE_P = 2,
    MWSFD_PTYPE_B = 3,
    MWSFD_PTYPE_D = 4,
    MWE_PLY_PTYPE_I = 1,
    MWE_PLY_PTYPE_P = 2,
    MWE_PLY_PTYPE_B = 3,
    MWE_PLY_PTYPE_D = 4,
    MWSFD_PTYPE_END = 5,
    MWSFD_PTYPE_ENUM_BE_SINT32 = 2147483647,
};

enum MwsfdFrmType {
    MWSFD_FRMTYPE_UNKNOWN = 0,
    MWSFD_FRMTYPE_PROGRESSIVE = 1,
    MWSFD_FRMTYPE_INTERLACE = 2,
    MWSFD_FRMTYPE_END = 3,
    MWSFD_FRMTYPE_ENUM_BE_SINT32 = 2147483647,
};

enum MwsfdYuvMode {
    MWSFD_YUVMODE_UNKNOWN = 0,
    MWSFD_YUVMODE_ITU_R_BT_601 = 1,
    MWSFD_YUVMODE_CSC = 2,
    MWSFD_YUVMODE_BASIC_YCBCR = 3,
    MWSFD_YUVMODE_HIGH_CONTRAST = 4,
    MWSFD_YUVMODE_RAW_YUV = 5,
    MWSFD_YUVMODE_END = 6,
    MWSFD_YUVMODE_ENUM_BE_SINT32 = 2147483647,
};

enum MwsfdBufFmt {
    MWSFD_BUFFMT_DEFAULT = 0,
    MWSFD_BUFFMT_MB_YCC420 = 1,
    MWSFD_BUFFMT_MB_ARGB8888 = 2,
    MWSFD_BUFFMT_PLN_YCC420 = 3,
    MWSFD_BUFFMT_END = 4,
};

enum MwsfdDecSvr {
    MWSFD_DEC_SVR_IDLE = 0,
    MWSFD_DEC_SVR_MAIN = 1,
    MWSFD_DEC_SVR_END = 2,
    MWSFD_DEC_SVR_ENUM_BE_SINT32 = 2147483647,
};

// total size: 0x3C
struct MwsfdCrePrm {
    signed int ftype;                  // offset 0x0, size 0x4
    signed int max_bps;                // offset 0x4, size 0x4
    signed int max_width;              // offset 0x8, size 0x4
    signed int max_height;             // offset 0xC, size 0x4
    signed int nfrm_pool_wk;           // offset 0x10, size 0x4
    signed int max_stm;                // offset 0x14, size 0x4
    signed char* work;                 // offset 0x18, size 0x4
    signed int wksize;                 // offset 0x1C, size 0x4
    signed int compo_mode;             // offset 0x20, size 0x4
    enum MwsfdBufFmt buffmt;           // offset 0x24, size 0x4
    signed int outer_frmpool_num;      // offset 0x28, size 0x4
    signed int outer_frmpool_size;     // offset 0x2C, size 0x4
    unsigned char** outer_frmpool_ptr; // offset 0x30, size 0x4
    signed int rsv[2];                 // offset 0x34, size 0x8
};

// total size: 0x20
struct MwsfdInitPrm {
    float vhz;                // offset 0x0, size 0x4
    signed int disp_cycle;    // offset 0x4, size 0x4
    signed int disp_latency;  // offset 0x8, size 0x4
    enum MwsfdDecSvr dec_svr; // offset 0xC, size 0x4
    signed int rsv[4];        // offset 0x10, size 0x10
};

// total size: 0x30
struct MwsfdFrmM2v {
    signed int pts;                             // offset 0x0, size 0x4
    signed int picture_structure;               // offset 0x8, size 0x4
    signed int chroma_format;                   // offset 0xC, size 0x4
    signed int bit_rate;                        // offset 0x10, size 0x4
    signed int vbv_buffer_size;                 // offset 0x14, size 0x4
    signed short display_horizontal_size;       // offset 0x18, size 0x2
    signed short display_vertical_size;         // offset 0x1A, size 0x2
    signed char progressive_frame;              // offset 0x1C, size 0x1
    signed char top_field_first;                // offset 0x1D, size 0x1
    signed char repeat_first_field;             // offset 0x1E, size 0x1
    signed char aspect_ratio_information;       // offset 0x1F, size 0x1
    signed char constrained_parameters_flag;    // offset 0x20, size 0x1
    signed char frame_rate_extension_n;         // offset 0x21, size 0x1
    signed char frame_rate_extension_d;         // offset 0x22, size 0x1
    unsigned char profile_and_level_indication; // offset 0x23, size 0x1
    signed char progressive_sequence;           // offset 0x24, size 0x1
    signed char low_delay;                      // offset 0x25, size 0x1
    signed char video_format;                   // offset 0x26, size 0x1
    signed char colour_description;             // offset 0x27, size 0x1
    unsigned char colour_primaries;             // offset 0x28, size 0x1
    unsigned char transfer_characteristics;     // offset 0x29, size 0x1
    unsigned char matrix_coefficients;          // offset 0x2A, size 0x1
    signed short num_slices;                    // offset 0x2C, size 0x2
};

// total size: 0x38
struct MwsfdFrmCodec {
    enum MwsfdVideoCodec videocodec; // offset 0x0, size 0x4
    struct {
        struct MwsfdFrmM2v frmm2v; // offset 0x0, size 0x30
    } u;                           // offset 0x8, size 0x30
};

// total size: 0xA0
struct MwsfdFrmObj {
    unsigned char* bufadr;         // offset 0x0, size 0x4
    signed int frmid;              // offset 0x4, size 0x4
    enum MwsfdBufFmt buffmt;       // offset 0x8, size 0x4
    signed int width;              // offset 0xC, size 0x4
    signed int height;             // offset 0x10, size 0x4
    signed int x_mb;               // offset 0x14, size 0x4
    signed int y_mb;               // offset 0x18, size 0x4
    enum MwsfdPtype ptype;         // offset 0x1C, size 0x4
    signed int fps;                // offset 0x20, size 0x4
    signed int fno;                // offset 0x24, size 0x4
    signed int time;               // offset 0x28, size 0x4
    signed int tunit;              // offset 0x2C, size 0x4
    signed int concat_cnt;         // offset 0x30, size 0x4
    signed int fno_per_file;       // offset 0x34, size 0x4
    signed int time_per_file;      // offset 0x38, size 0x4
    signed int errcnt;             // offset 0x3C, size 0x4
    signed int rcvcnt;             // offset 0x40, size 0x4
    void* usrdatptr;               // offset 0x44, size 0x4
    signed int usrdatsize;         // offset 0x48, size 0x4
    enum MwsfdFrmType frmtype;     // offset 0x4C, size 0x4
    enum MwsfdYuvMode yuvmode;     // offset 0x50, size 0x4
    unsigned int zmin;             // offset 0x54, size 0x4
    unsigned int zmax;             // offset 0x58, size 0x4
    struct MwsfdFrmCodec frmcodec; // offset 0x60, size 0x38
    void* sud_ptr;                 // offset 0x98, size 0x4
    signed int sud_size;           // offset 0x9C, size 0x4
};

// total size: 0x18
struct ADXM_TPRM {
    signed int prio_lock;   // offset 0x0, size 0x4
    signed int prio_safe;   // offset 0x4, size 0x4
    signed int prio_vsync;  // offset 0x8, size 0x4
    signed int prio_fs;     // offset 0xC, size 0x4
    signed int prio_main;   // offset 0x10, size 0x4
    signed int prio_mwidle; // offset 0x14, size 0x4
};

// total size: 0x30
struct ADXM_TPRM_EX {
    signed int prio_lock;        // offset 0x0, size 0x4
    signed int prio_safe;        // offset 0x4, size 0x4
    signed int prio_usrvsync;    // offset 0x8, size 0x4
    signed int prio_vsync;       // offset 0xC, size 0x4
    signed int prio_fs;          // offset 0x10, size 0x4
    signed int prio_main;        // offset 0x14, size 0x4
    signed int prio_mwidle;      // offset 0x18, size 0x4
    signed int prio_usridle;     // offset 0x1C, size 0x4
    void* stkptr_usrvsync;       // offset 0x20, size 0x4
    signed int stksize_usrvsync; // offset 0x24, size 0x4
    void* stkptr_usridle;        // offset 0x28, size 0x4
    signed int stksize_usridle;  // offset 0x2C, size 0x4
};

#endif // CRI_LIBS_H
