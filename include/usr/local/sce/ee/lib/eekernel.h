#ifndef EEKERNEL_H
#define EEKERNEL_H

#ifdef __cplusplus
extern "C" {
#endif
int EIntr(void); /* System used */
int DIntr(void); /* System used */
#ifdef __cplusplus
}
#endif

#define EI EIntr
#define DI DIntr

#ifndef EI
#define EI() __asm__ volatile("ei")
#endif
#ifndef DI
#define DI()                                                                                       \
    {                                                                                              \
        unsigned int stat;                                                                         \
        do {                                                                                       \
            __asm__ volatile(".p2align 3");                                                        \
            __asm__ volatile("di");                                                                \
            __asm__ volatile("sync.p");                                                            \
            __asm__ volatile("mfc0	%0, $12" : "=r"(stat) :);                                      \
        } while (stat & 0x00010000);                                                               \
    }
#endif

#define ExitHandler() __asm__ volatile("sync.l; ei")
#ifdef __cplusplus
extern "C" {
    #endif
extern int DisableIntc(int);
extern int RemoveIntcHandler(int, int);
#ifdef __cplusplus
}
#endif
#define REG_GIF_MODE (*(volatile int*)0x10003010)

#endif /* _EEKERNEL_H_ */
