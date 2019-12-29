#include <arch/i386/GDT.h>

u64 GDT[5] = {
    0,
    0,
    0,
    0,
    0
};

u64 GDTptr = 0;

u64 createGDTDescriptor(u32 base, u32 limit, u8 accessbyte, u8 flags)
{
    u64 ret = 0;
    ret |= base            & 0xFF000000;
    ret |= (flags << 20)   & 0x00F00000;
    ret |= limit           & 0x000F0000;
    ret |= (accessbyte<<8) & 0x0000FF00;
    ret |= (base >> 16)    & 0x000000FF;

    ret <<= 32;
    
    ret |= base << 16;
    ret |= limit           & 0x0000FFFF;
    return ret;
}
 
void defaultGDTSetup()
{
    GDT[0] = createGDTDescriptor(0x00000000, 0x00000000, 0x0 , 0x0);
    GDT[1] = createGDTDescriptor(0x00000000, 0xFFFFFFFF, GDT_CODE_SPVR, 0xC);
    GDT[2] = createGDTDescriptor(0x00000000, 0xFFFFFFFF, GDT_DATA_SPVR, 0xC);
    GDT[3] = createGDTDescriptor(0x00000000, 0xFFFFFFFF, GDT_CODE_USER, 0xC);
    GDT[4] = createGDTDescriptor(0x00000000, 0xFFFFFFFF, GDT_DATA_USER, 0xC);

    GDTptr = (u32)GDT;
    GDTptr <<=16;
    GDTptr |= sizeof(u64)*5-1;
    loadGDT((void*)&GDTptr);
}