#include <typedef.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <multiboot.h>

#include <arch/i386/GDT.h>
#include <arch/i386/IDT.h>
#include <arch/i386/serial.h>
#include <arch/i386/APIC.h>

int kernel_main(/*multibootInformation_t* multiInfo*/);

void kernel_early_main(/*multibootInformation_t* multiInfo*/)
{
    clrscr();
    setlocale(LC_ALL, "C");
    defaultGDTSetup();
    defaultIDTSetup();
    initCOM1();
    kernel_main(/*multiInfo*/);
}

int kernel_main(/*multibootInformation_t* multiInfo*/)
{
    printf("Glucose Kernel\n");
    printf("Set Locale\n");
    printf("Set GDT\n");
    printf("Set IDT\n");
    printf("Initialized COM1\n");
    findSDS("TEPH")
    return 0;
}