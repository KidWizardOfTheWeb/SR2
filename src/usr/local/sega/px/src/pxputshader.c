#include "usr/local/sega/px/src/px.h"
#include "usr/local/sega/px/src/pxpushbuffer.h"
#include "usr/local/sega/px/src/pxputshader.h"
#include "usr/local/sega/px/src/pxvutable.h"
#include "usr/local/sega/px/src/pxvutable2.h"

void PXPutShader(unsigned int type) {
    unsigned int type_masked; //not in the dwarf dump.
    void* shader;
    type_masked = type & 0xFFF; 
    if ((type & 0x80000000) != 0) {
        if (type & 0x100000) {
            shader = pxgShaderTableSpecialFast[type_masked];
        } else {
            shader = pxgShaderTableSpecial[type_masked];
        }
    } else {
        switch (type & 0xF0000) {
        default:
            if ((type & 0xF000) == 0x1000) {
            } else if (type & 0x100000) {
                shader = pxgShaderTablePNTDirFast[type_masked];
                break;
            } else {
                shader = pxgShaderTablePNTDir[type_masked];
                break;
            }
            shader = pxgShaderTablePNTDirSpecular[type_masked];
            break;
        case 0x10000:
            if (type & 0x100000) {
                shader = pxgShaderTablePCTFast[type_masked];
            } else {
                shader = pxgShaderTablePCT[type_masked];
            }
            break;
        case 0x40000:
            if ((type & 0xF000) == 0x1000) {
            } else if (type & 0x100000) {
                shader = pxgShaderTableRPNTDirFast[type_masked];
                break;
            } else {
                shader = pxgShaderTableRPNTDir[type_masked];
                break;
            }
            shader = pxgShaderTableRPNTDirSpecular[type_masked];
            break;
        case 0x50000:
            if (type & 0x100000) {
                shader = pxgShaderTableRPCTFast[type_masked];
            } else {
                shader = pxgShaderTableRPCT[type_masked];
            }
            break;
        }
    }
    PXPutShaderPB(pxgCurrentPB, shader);
}
