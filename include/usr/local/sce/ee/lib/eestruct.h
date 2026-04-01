#ifndef _EESTRUCT_H_
#define _EESTRUCT_H_

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
	((unsigned long)(nloop) | ((unsigned long)(eop)<<15) | ((unsigned long)(pre) << 46) | \
	((unsigned long)(prim)<<47) | ((unsigned long)(flg)<<58) | ((unsigned long)(nreg)<<60))

#define SCE_VIF1_SET_UNPACK(vuaddr, num, cmd, irq) ((unsigned int)(vuaddr) | ((unsigned int)(num) << 16) | ((unsigned int)(0x60 | (cmd)) << 24) | ((unsigned int)(irq) << 31))


#endif /* _EESTRUCT_H_ */
