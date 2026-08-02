#ifndef LIBGRAPH_H
#define LIBGRAPH_H

#if defined(__LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
extern "C" {
#endif

unsigned long sceGsPutIMR(unsigned long imr);
unsigned long sceGsGetIMR(void);
unsigned long isceGsPutIMR(unsigned long imr);
unsigned long isceGsGetIMR(void);

#if defined(__LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
}
#endif

#endif /* _LIBGRAPH_H_ */
