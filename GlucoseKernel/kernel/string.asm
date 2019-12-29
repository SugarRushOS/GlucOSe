section .text
global memmov:function (memmov.exit - memmov)
memmov:
    mov edi, [esp+4]
    mov esi, [esp+8]
    mov ecx, [esp+12]
    
    .mmloop:
        mov al, byte [esi]
        mov byte[edi], al
        inc esi
        inc edi
        dec ecx
        jecxz .exit
        jmp .mmloop


    .exit:
        ret

global memset:function (memset.exit - memset)
memset:
    mov edi, [esp+4]
    mov eax, [esp+8]
    mov ecx, [esp+12]
    .msloop:
        mov byte[edi], al
        dec ecx
        inc edi
        jecxz .exit
        jmp .msloop


    .exit:
        ret
        
global memcpy:function (memcpy.exit - memcpy)
memcpy:
    mov edi, [esp+4]
    mov esi, [esp+8]
    mov ecx, [esp+12]
    .mcloop:
        mov al, byte [esi]
        mov byte [edi], al
        dec ecx
        inc edi
        inc esi
        jecxz .exit
        jmp .mcloop


    .exit:
        ret

global memchr:function (memchr.exit - memchr)
memchr:
    mov esi, [esp+4]
    mov ebx, [esp+8]
    mov ecx, [esp+12]
    .mhloop:
        mov al, byte [esi]
        inc esi
        cmp al, bl
        je .exit
        dec ecx
        jecxz .exit
        jmp .mhloop

    .exit:
        mov eax, esi
        ret
