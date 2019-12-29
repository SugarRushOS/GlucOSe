#ifndef STDIO_H
#define STDIO_H

#include <typedef.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#define vidmem      0xB8000
#define columns     80
#define rows        25
#define bytesperent 2

enum VGA16Palette {
    Black         = 0x0,
    Blue          = 0x1,
    Green         = 0x2,
    Cyan          = 0x3,
    Red           = 0x4,
    Magenta       = 0x5,
    Brown         = 0x6,
    Gray          = 0x7,
    Graydark      = 0x8,
    BlueBright    = 0x9,
    GreenBright   = 0xA,
    CyanBright    = 0xB,
    RedBright     = 0xC,
    MagentaBright = 0xD,
    Yellow        = 0xE,
    White         = 0xF
};

u8   make16palettecolor(u8 fg, u8 bg);         //✔️
u16  make16palletentry(char c, u8 color);      //✔️
void putchar(char c);                          //✔️
void puts(const char* s);                      //✔️
void clrscr();                                 //✔️
int printf(const char* restrict format, ...);  //➖
#endif