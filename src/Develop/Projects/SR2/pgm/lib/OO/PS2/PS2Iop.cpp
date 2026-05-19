#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Iop.hpp"

static stcIrxLoadInfo toasIrxLoadInfo[9] = {
    {(c8*)"cdrom0:\\I\\SIO2MAN.IRX;1", 0, 0},
    {(c8*)"cdrom0:\\I\\MTAPMAN.IRX;1", 0, 0},
    {(c8*)"cdrom0:\\I\\PADMAN.IRX;1", 0, 0},
    {(c8*)"cdrom0:\\I\\LIBSD.IRX;1", 0, 0},
    {(c8*)"cdrom0:\\I\\SDRDRV.IRX;1", 0, 0},
    {(c8*)"cdrom0:\\I\\CRI_ADXI.IRX;1", (c8*)"spucore=1", 19},
    {(c8*)"cdrom0:\\I\\SNDFI.IRX;1", 0, 0},
    {(c8*)"cdrom0:\\I\\MCMAN.IRX;1", 0, 0},
    {(c8*)"cdrom0:\\I\\MCSERV.IRX;1", 0, 0},
};

clsPfIop::clsPfIop()
{
}
