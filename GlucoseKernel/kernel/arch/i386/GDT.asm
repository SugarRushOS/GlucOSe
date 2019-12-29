section .text
global loadGDT:function (loadGDT.exit - loadGDT)
loadGDT:
    mov eax, [esp+4]
    lgdt[eax]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:.exit
.exit:
    ret