#ifndef GDT_H
#define GDT_H

#include <typedef.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define SEG_PRESENT        0x80                                                         //Descriptor is present and therefor valid
#define SEG_PRIVILS        0x00                                                         //Descriptor is for supervisor, ring 0
#define SEG_PRIVILU        0x60                                                         //Descriptor is for usermode, ring 3
#define SEG_CODEDATA       0x10                                                         //Descriptor is for code or data
#define SEG_SYSTEM         0x00                                                         //Descriptor is for TSS
#define SEG_ACCESSED       0x01                                                         //Set by the CPU, ignore
#define SEG_READWRITE      0x02                                                         //Descriptor is readable or writable, otherwise read only
#define SEG_EXPANDDOWN     0x04                                                         //Descriptor is expand down
#define SEG_EXECONLY       0x08                                                         //Descriptor is executable

#define SEG_DATA_RD                                                                 0x0 //                           
#define SEG_DATA_RDA                                                       SEG_ACCESSED //                                      Accessed
#define SEG_DATA_RDWR                                      SEG_READWRITE                //                           Read Write
#define SEG_DATA_RDWRA                                     SEG_READWRITE | SEG_ACCESSED //                           Read Write Accessed
#define SEG_DATA_RDEXPD                   SEG_EXPANDDOWN                                //            Expanding Down
#define SEG_DATA_RDEXPDA                  SEG_EXPANDDOWN |                 SEG_ACCESSED //            Expanding Down            Accessed
#define SEG_DATA_RDWREXPD                 SEG_EXPANDDOWN | SEG_READWRITE                //            Expanding Down Read Write 
#define SEG_DATA_RDWREXPDA                SEG_EXPANDDOWN | SEG_READWRITE | SEG_ACCESSED //            Expanding Down Read Write Accessed
#define SEG_CODE_EX        SEG_EXECONLY                                                 // Executable                
#define SEG_CODE_EXA       SEG_EXECONLY |                                  SEG_ACCESSED // Executable                           Accessed
#define SEG_CODE_EXRD      SEG_EXECONLY |                  SEG_READWRITE                // Executable                Read Write
#define SEG_CODE_EXRDA     SEG_EXECONLY |                  SEG_READWRITE | SEG_ACCESSED // Executable                Read Write Accessed
#define SEG_CODE_EXC       SEG_EXECONLY | SEG_EXPANDDOWN                                // Executable Expanding Down
#define SEG_CODE_EXCA      SEG_EXECONLY | SEG_EXPANDDOWN |                 SEG_ACCESSED // Executable Expanding Down            Accessed
#define SEG_CODE_EXRDC     SEG_EXECONLY | SEG_EXPANDDOWN | SEG_READWRITE                // Executable Expanding Down Read Write 
#define SEG_CODE_EXRDCA    SEG_EXECONLY | SEG_EXPANDDOWN | SEG_READWRITE | SEG_ACCESSED // Executable Expanding Down Read Write Accessed

#define GDT_CODE_SPVR      SEG_PRESENT | SEG_PRIVILS | SEG_CODEDATA | SEG_CODE_EXRD     // Descriptor for code supervisor
#define GDT_DATA_SPVR      SEG_PRESENT | SEG_PRIVILS | SEG_CODEDATA | SEG_DATA_RDWR     // Descriptor for data supervisor
#define GDT_CODE_USER      SEG_PRESENT | SEG_PRIVILU | SEG_CODEDATA | SEG_CODE_EXRD     // Descriptor for code user
#define GDT_DATA_USER      SEG_PRESENT | SEG_PRIVILU | SEG_CODEDATA | SEG_DATA_RDWR     // Descriptor for data user

extern void loadGDT(void* ptr);                                                         //✔️
u64 createGDTDescriptor(u32 base, u32 limit, u8 accessbyte, u8 flags);                  //✔️
void defaultGDTSetup();                                                                 //✔️

#endif