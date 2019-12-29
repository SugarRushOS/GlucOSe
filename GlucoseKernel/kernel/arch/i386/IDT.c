#include <arch/i386/IDT.h>

u64 IDT[256];
u64 IDTptr = 0;

u64 createIDTDescriptor(u32 offset, u16 selector, u8 flags)
{
    u64 ret = 0;
    ret |= offset          & 0xFFFF0000;
    ret |= (flags << 8)    & 0x0000FF00;

    ret <<= 32;
    
    ret |= selector << 16;
    ret |= offset           & 0x0000FFFF;
    return ret;
}

void defaultIDTSetup()
{
    memset(&IDT,0,sizeof(u64)*256);

    IDT[0]  = createIDTDescriptor((u32)ISR0, 0x8, DEFAULTFLAGS);
    IDT[1]  = createIDTDescriptor((u32)ISR1, 0x8, DEFAULTFLAGS);
    IDT[2]  = createIDTDescriptor((u32)ISR2, 0x8, DEFAULTFLAGS);
    IDT[3]  = createIDTDescriptor((u32)ISR3, 0x8, DEFAULTFLAGS);
    IDT[4]  = createIDTDescriptor((u32)ISR4, 0x8, DEFAULTFLAGS);
    IDT[5]  = createIDTDescriptor((u32)ISR5, 0x8, DEFAULTFLAGS);
    IDT[6]  = createIDTDescriptor((u32)ISR6, 0x8, DEFAULTFLAGS);
    IDT[7]  = createIDTDescriptor((u32)ISR7, 0x8, DEFAULTFLAGS);
    IDT[8]  = createIDTDescriptor((u32)ISR8, 0x8, DEFAULTFLAGS);
    IDT[9]  = createIDTDescriptor((u32)ISR9, 0x8, DEFAULTFLAGS);
    IDT[10] = createIDTDescriptor((u32)ISR10, 0x8, DEFAULTFLAGS);
    IDT[11] = createIDTDescriptor((u32)ISR11, 0x8, DEFAULTFLAGS);
    IDT[12] = createIDTDescriptor((u32)ISR12, 0x8, DEFAULTFLAGS);
    IDT[13] = createIDTDescriptor((u32)ISR13, 0x8, DEFAULTFLAGS);
    IDT[14] = createIDTDescriptor((u32)ISR14, 0x8, DEFAULTFLAGS);
    IDT[15] = createIDTDescriptor((u32)ISR15, 0x8, DEFAULTFLAGS);
    IDT[16] = createIDTDescriptor((u32)ISR16, 0x8, DEFAULTFLAGS);
    IDT[17] = createIDTDescriptor((u32)ISR17, 0x8, DEFAULTFLAGS);
    IDT[18] = createIDTDescriptor((u32)ISR18, 0x8, DEFAULTFLAGS);
    IDT[19] = createIDTDescriptor((u32)ISR19, 0x8, DEFAULTFLAGS);
    IDT[20] = createIDTDescriptor((u32)ISR20, 0x8, DEFAULTFLAGS);
    IDT[21] = createIDTDescriptor((u32)ISR21, 0x8, DEFAULTFLAGS);
    IDT[22] = createIDTDescriptor((u32)ISR22, 0x8, DEFAULTFLAGS);
    IDT[23] = createIDTDescriptor((u32)ISR23, 0x8, DEFAULTFLAGS);
    IDT[24] = createIDTDescriptor((u32)ISR24, 0x8, DEFAULTFLAGS);
    IDT[25] = createIDTDescriptor((u32)ISR25, 0x8, DEFAULTFLAGS);
    IDT[26] = createIDTDescriptor((u32)ISR26, 0x8, DEFAULTFLAGS);
    IDT[27] = createIDTDescriptor((u32)ISR27, 0x8, DEFAULTFLAGS);
    IDT[28] = createIDTDescriptor((u32)ISR28, 0x8, DEFAULTFLAGS);
    IDT[29] = createIDTDescriptor((u32)ISR29, 0x8, DEFAULTFLAGS);
    IDT[30] = createIDTDescriptor((u32)ISR30, 0x8, DEFAULTFLAGS);
    IDT[31] = createIDTDescriptor((u32)ISR31, 0x8, DEFAULTFLAGS);

    IDTptr = (u32)IDT;
    IDTptr <<=16;
    IDTptr |= sizeof(u64)*256-1;

    loadIDT((void*)&IDTptr);
}
void ISRHandler(regs_t registers)
{
    printf("Recived interrupt: %u\n", registers.interruptnum);

}