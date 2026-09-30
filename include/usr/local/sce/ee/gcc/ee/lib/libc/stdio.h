#ifndef LIBC_STDIO_H
#define LIBC_STDIO_H

// RECONSTRUCTED: shared type placement.
struct _reent;
struct _Bigint;

struct __sbuf {
    unsigned char* _base;
    int _size;
};

struct __sFILE {
    unsigned char* _p;
    int _r;
    int _w;
    short _flags;
    short _file;
    struct __sbuf _bf;
    int _lbfsize;
    void* _cookie;
    int (*_read)(void*, char*, int);
    int (*_write)(void*, char*, int);
    long (*_seek)(void*, long, int);
    int (*_close)(void*);
    struct __sbuf _ub;
    unsigned char* _up;
    int _ur;
    unsigned char _ubuf[3];
    unsigned char _nbuf[1];
    struct __sbuf _lb;
    int _blksize;
    int _offset;
    struct _reent* _data;
};

typedef struct __sFILE FILE;

struct __tm {
    int __tm_sec;
    int __tm_min;
    int __tm_hour;
    int __tm_mday;
    int __tm_mon;
    int __tm_year;
    int __tm_wday;
    int __tm_yday;
    int __tm_isdst;
};

struct _rand48 {
    unsigned short _seed[3];
    unsigned short _mult[3];
    unsigned short _add;
};

struct _atexit {
    struct _atexit* _next;
    int _ind;
    void (*_fns[32])(void);
};

struct _glue {
    struct _glue* _next;
    int _niobs;
    FILE* _iobs;
};

struct _reent {
    int _errno;
    FILE* _stdin;
    FILE* _stdout;
    FILE* _stderr;
    int _inc;
    char _emergency[25];
    int _current_category;
    char* _current_locale;
    int __sdidinit;
    void (*__cleanup)(struct _reent*);
    struct _Bigint* _result;
    int _result_k;
    struct _Bigint* _p5s;
    struct _Bigint** _freelist;
    int _cvtlen;
    char* _cvtbuf;
    union {
        struct {
            unsigned int _unused_rand;
            char* _strtok_last;
            char _asctime_buf[26];
            struct __tm _localtime_buf;
            int _gamma_signgam;
            unsigned long long _rand_next;
            struct _rand48 _r48;
            int _mblen_state;
            int _mbtowc_state;
            int _wctomb_state;
        } _reent;
        struct {
            unsigned char* _nextf[30];
            unsigned int _nmalloc[30];
        } _unused;
    } _new;
    struct _atexit* _atexit;
    struct _atexit _atexit0;
    void (**_sig_func)(int);
    struct _glue __sglue;
    FILE __sf[3];
};

#ifdef __cplusplus
extern "C" {
#endif

extern struct _reent* _impure_ptr;

#ifdef __cplusplus
}
#endif

#define stdin (_impure_ptr->_stdin)
#define stdout (_impure_ptr->_stdout)
#define stderr (_impure_ptr->_stderr)

#endif // LIBC_STDIO_H
