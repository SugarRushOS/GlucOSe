#include <stdio.h>

static u16 x = 0;
static u16 y = 0;
static u8 defaultColor = 0x0F;
u8 make16palettecolor(u8 fg, u8 bg)
{
    return fg | bg << 4;
}

u16 make16palletentry(char c, u8 color)
{
    return c | color << 8;
}

void putchar(char c)
{
    if(c=='\n')
    {
        x=0;
        if(++y> rows)
        {
            memmov((void*)vidmem+(columns*bytesperent),(void*)vidmem, (columns*rows*bytesperent)-(columns*bytesperent));
            memset((void*)vidmem+(columns*rows*bytesperent)-(columns*bytesperent), 0, columns*bytesperent);
            return;
        }
        return;
    }
    u16* vm = (u16*) vidmem;
    vm[y*80+x] = make16palletentry(c, defaultColor);
    if(++x > columns)
    {
        x=0;
        if(++y > rows)
        {
            memmov((void*)vidmem+(columns*bytesperent),(void*)vidmem, (columns*rows*bytesperent)-(columns*bytesperent));
            memset((void*)vidmem+(columns*rows*bytesperent)-(columns*bytesperent), 0, columns*bytesperent);
        }
    }
    
}

void puts(const char* s)
{
    while(*s)
    {
        putchar(*s);
        s++;
    }
}

void clrscr()
{
    memset((void*)vidmem,0,rows*columns*bytesperent);
}

int printf(const char* restrict format, ...)
{
    va_list parameters;
    va_start(parameters, format);
    while(*format)
    {
        if(*format == '%')
        {
            format++;
            if(*format == 'c')
            {
                //char
                format++;
                char c = (char) va_arg(parameters, int);
                putchar(c);
            }else if(*format == 'd' || *format == 'i')
            {
                //signed decimal int
                format++;
                int i = va_arg(parameters, int);
                if(i == 0)
                {
                    printf("0");
                    continue;
                }
                if(i>>31)
                {
                    printf("-");
                    i = abs(i);
                }
                char buffer[32] = "";
                printf("%s",itoa(i, buffer, 10));
            }else if(*format == 'e')
            {
                //Scientific notation (Mantissa/Exponent) using e
                format++;
            }else if(*format == 'E')
            {
                //Scientific notation (Mantissa/Exponent) using E
                format++;
            }else if(*format == 'f')
            {
                //Decimal floating point
                format++;
            }else if(*format == 'g')
            {
                //Uses the shorter of %e or %f
                format++;
            }else if(*format == 'G')
            {
                //Uses the shorter of %E or %f
                format++;
            }else if(*format == 'o')
            {
                //Signed octal
                format++;
                int i = va_arg(parameters, int);
                if(i == 0)
                {
                    printf("0");
                    continue;
                }
                if(i>>31)
                {
                    printf("-");
                    i = abs(i);
                }
                char buffer[32] = "";
                printf("%s",itoa(i, buffer, 8));
            }else if(*format == 's')
            {
                format++;
                const char* s = (const char*) va_arg(parameters, const char*);
                puts(s);
            }else if(*format == 'u')
            {
                //Unsigned decimal
                format++;
                unsigned int i = va_arg(parameters,unsigned int);
                if(i == 0)
                {
                    printf("0");
                    continue;
                }
                char buffer[32] = "";
                itoa(i, buffer, 10);
                printf("%s", buffer);
            }else if(*format == 'x')
            {
                //Unsigned hex
                format++;
                unsigned int i = va_arg(parameters, unsigned int);
                if(i == 0)
                {
                    printf("0");
                    continue;
                }
                char buffer[32] = "";
                printf("%s",itoa(i, buffer, 16));
            }else if(*format == 'X')
            {
                //Unsigned hex capital
                format++;
            }else if(*format == 'p')
            {
                //pointer
                format++;
            }else if(*format == 'n')
            {
                //Nothing printed
                format++;
            }else if(*format == '%')
            {
                //% character
                format++;
                putchar('%');
            }
        }else
        {
            putchar(*format);
            format++;
        }
    }
    return 0;
}