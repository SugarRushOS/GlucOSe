multialign equ 0x01
meminfo    equ 0x02
gfx        equ 0x04
multiflags equ multialign ;| gfx
magic equ 0x1BADB002
checksum equ -(magic + multiflags)

section .multiboot
global multiheader
align 4
                   dd magic
                   dd multiflags
                   dd checksum
     header_addr   dd 0
     load_addr     dd 0
     load_end_addr dd 0
     bss_end_addr  dd 0
     entry_addr    dd 0
     mode_type     dd 0
     width         dd 80
     height        dd 43
     depth         dd 8
section .bss
align 16
stackbottom:
resb 32768
stacktop:

section .text
global _start:function (_start.end - _start)
_start:
    mov esp, stacktop
    extern kernel_early_main
    push ebx
    call   kernel_early_main

    cli
.hang:
    hlt
    jmp .hang
.end:
