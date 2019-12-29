section .text
global loadIDT:function (loadIDT.exit - loadIDT)
loadIDT:
    mov eax, [esp+4]
    lidt[eax]
    jmp .exit
.exit:
    ret

%macro ISR 1
global ISR%1:function (ISR%1.exit - ISR%1)
    ISR%1:
    cli
    push byte 0
    push byte %1
    jmp ISRCommon
.exit:
%endmacro

%macro ISRE 1
global ISR%1:function (ISR%1.exit - ISR%1)
    ISR%1:
    cli
    push byte %1
    jmp ISRCommon
.exit:
%endmacro

ISR  0
ISR  1
ISR  2
ISR  3
ISR  4
ISR  5
ISR  6
ISR  7
ISRE 8
ISR  9
ISRE 10
ISRE 11
ISRE 12
ISRE 13
ISRE 14
ISR  15
ISR  16
ISR  17
ISR  18
ISR  19
ISR  20
ISR  21
ISR  22
ISR  23
ISR  24
ISR  25
ISR  26
ISR  27
ISR  28
ISR  29
ISR  30
ISR  31

global ISRCommon:function (ISRCommon.exit - ISRCommon)
ISRCommon:
    pusha
    mov ax, ds
    
    push eax
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    extern ISRHandler
    call ISRHandler

    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    popa
    add esp, 8

    sti
    iret
.exit: