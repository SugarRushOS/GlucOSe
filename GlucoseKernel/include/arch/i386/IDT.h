#ifndef IDT_H
#define IDT_H

#include <typedef.h>
#include <string.h>
#include <stdlib.h>

#define PRESENT            0x80                                                         //Descriptor is in use
#define SEG_PRIVILS        0x00                                                         //Descriptor is for supervisor, ring 0
#define SEG_PRIVILU        0x60                                                         //Descriptor is for usermode, ring 3
#define TASKINTGATE        0x10                                                         //Task/Interrupt gate
#define TASKGATE32         0x05                                                         //TSS Descriptor in GDT32 bit ISR
#define INTERRUP16         0x06                                                         //16 bit ISR
#define TRAPGATE16         0x07                                                         //16 bit Trap
#define INTERRUP32         0x0E                                                         //32 bit ISR
#define TRAPGATE32         0x0F                                                         //32 bit Trap

#define DEFAULTFLAGS PRESENT | INTERRUP32                                               //Present 32 bit interrupt

extern void ISR0();
extern void ISR1();
extern void ISR2();
extern void ISR3();
extern void ISR4();
extern void ISR5();
extern void ISR6();
extern void ISR7();
extern void ISR8();
extern void ISR9();
extern void ISR10();
extern void ISR11();
extern void ISR12();
extern void ISR13();
extern void ISR14();
extern void ISR15();
extern void ISR16();
extern void ISR17();
extern void ISR18();
extern void ISR19();
extern void ISR20();
extern void ISR21();
extern void ISR22();
extern void ISR23();
extern void ISR24();
extern void ISR25();
extern void ISR26();
extern void ISR27();
extern void ISR28();
extern void ISR29();
extern void ISR30();
extern void ISR31();
extern void loadIDT(void* ptr);

u64 createIDTDescriptor(u32 offset, u16 selector, u8 flags);
void defaultIDTSetup();
void ISRHandler(regs_t registers);
#endif