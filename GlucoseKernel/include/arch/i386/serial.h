#ifndef SERIAL_H
#define SERIAL_H

#include <typedef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define COM1 0x3F8

#define COM1_INTENABLEMSBDIVI COM1 + 0x1
#define COM1_INTIDFIFOCTRLREG COM1 + 0x2
#define COM1_LINECONTROLREG   COM1 + 0x3
#define COM1_MODEMCONTROLREG  COM1 + 0x4
#define COM1_LINESTATUSREG    COM1 + 0x5
#define COM1_MODEMSTATUSREG   COM1 + 0x6
#define COM1_SCRATCHREG       COM1 + 0x7


#define DATAREADY	         1<<0 //Set if there is data that can be read
#define OVERRUNERROR 	     1<<1 //Set if there has been data lost
#define PARITYERROR 	     1<<2 //Set if there was an error in the transmission as detected by parity
#define FRAMINGERROR 	     1<<3 //Set if a stop bit was missing
#define BREAKINDICATOR 	     1<<4 //Set if there is a break in data input
#define TRANSMITHOLDREGEMPTY 1<<5 //Set if the transmission buffer is empty (i.e. data can be sent)
#define TRANSMITEMPTY 	     1<<6 //Set if the transmitter is not doing anything
#define IMPENDINGERROR       1<<7 //Set if there is an error with a word in the input buffer

static inline void outb(u16 port, u8 val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline u8 inb(u16 port)
{
    u8 ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}
u16 detectserial();                                //✔️
void initCOM1();                                   //✔️
int isTransmitEmpty();                             //✔️
void writecharSerial(char c);                      //✔️
void writestringSerial(const char* str);           //✔️
void COM1printf(const char* restrict format, ...); //✔️

#endif