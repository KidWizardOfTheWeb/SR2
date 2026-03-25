#ifndef _EEREGS_H_
#define _EEREGS_H_

#define D2_CHCR         ((volatile unsigned int *)(0x1000a000))
#define DGET_D2_CHCR()          (*D2_CHCR)
#define DPUT_D2_CHCR(x)         (*D2_CHCR = (x))
#define D2_QWC          ((volatile unsigned int *)(0x1000a020))
#define DPUT_D2_QWC(x)          (*D2_QWC = (x))
#define D2_TADR         ((volatile unsigned int *)(0x1000a030))
#define DPUT_D2_TADR(x)         (*D2_TADR = (x))
#define D_STAT          ((volatile unsigned int *)(0x1000e010))
#define DPUT_D_STAT(x)          (*D_STAT = (x))


#endif /* _EEREGS_H_ */
