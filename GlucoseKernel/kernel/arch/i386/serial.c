#include <arch/i386/serial.h>

u16 detectserial()
{
    u16 ret = *(u16*) 0x400;
    return ret;
}

void initCOM1()
{
    outb(COM1_INTENABLEMSBDIVI, 0x00);
    outb(COM1_LINECONTROLREG, 0x80);
    outb(COM1, 0x03);
    outb(COM1_INTENABLEMSBDIVI, 0x00);
    outb(COM1_LINECONTROLREG, 0x3);
    outb(COM1_INTIDFIFOCTRLREG, 0xC7);
    outb(COM1_MODEMCONTROLREG, 0x0B);
}

int isTransmitEmpty()
{
    return inb(COM1_LINESTATUSREG) & 0x20;
}

void writecharSerial(char c)
{
    while(isTransmitEmpty()==0);
    outb(COM1, c);
}

void writestringSerial(const char* str)
{
    for(size_t i = 0; i < strlen(str); i++)
        writecharSerial(str[i]);
}

void COM1printf(const char* restrict format, ...)
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
                writecharSerial(c);
            }else if(*format == 'd' || *format == 'i')
            {
                //signed decimal int
                format++;
                int i = va_arg(parameters, int);
                if(i == 0)
                {
                    COM1printf("0");
                    continue;
                }
                if(i>>31)
                {
                    COM1printf("-");
                    i = abs(i);
                }
                char buffer[32] = "";
                COM1printf("%s",itoa(i, buffer, 10));
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
                    COM1printf("0");
                    continue;
                }
                if(i>>31)
                {
                    COM1printf("-");
                    i = abs(i);
                }
                char buffer[32] = "";
                COM1printf("%s",itoa(i, buffer, 8));
            }else if(*format == 's')
            {
                format++;
                const char* s = (const char*) va_arg(parameters, const char*);
                writestringSerial(s);
            }else if(*format == 'u')
            {
                //Unsigned decimal
                format++;
                unsigned int i = va_arg(parameters,unsigned int);
                if(i == 0)
                {
                    COM1printf("0");
                    continue;
                }
                char buffer[32] = "";
                itoa(i, buffer, 10);
                COM1printf("%s", buffer);
            }else if(*format == 'x')
            {
                //Unsigned hex
                format++;
                unsigned int i = va_arg(parameters, unsigned int);
                if(i == 0)
                {
                    COM1printf("0");
                    continue;
                }
                char buffer[32] = "";
                COM1printf("%s",itoa(i, buffer, 16));
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
                writecharSerial('%');
            }
        }else
        {
            writecharSerial(*format);
            format++;
        }
    }   
}