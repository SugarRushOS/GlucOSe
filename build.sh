#Kernel assembly
nasm -felf32 GlucoseKernel/boot/boot.asm -o obj/GlucoseKernel/boot/boot.o
nasm -felf32 GlucoseKernel/kernel/string.asm -o obj/GlucoseKernel/kernel/astring.o

#Kernel C
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/stdio.c -o obj/GlucoseKernel/kernel/stdio.o
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/stdlib.c -o obj/GlucoseKernel/kernel/stdlib.o
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/string.c -o obj/GlucoseKernel/kernel/cstring.o
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/assert.c -o obj/GlucoseKernel/kernel/assert.o
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/math.c -o obj/GlucoseKernel/kernel/math.o
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/locale.c -o obj/GlucoseKernel/kernel/locale.o
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/kernel.c -o obj/GlucoseKernel/kernel/kernel.o

#architecture i386 assembly
nasm -felf32 GlucoseKernel/kernel/arch/i386/GDT.asm -o obj/GlucoseKernel/kernel/arch/i386/GDTa.o
nasm -felf32 GlucoseKernel/kernel/arch/i386/IDT.asm -o obj/GlucoseKernel/kernel/arch/i386/IDTa.o

#Architecture i386 assembly
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/arch/i386/GDT.c -o obj/GlucoseKernel/kernel/arch/i386/GDTc.o
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/arch/i386/IDT.c -o obj/GlucoseKernel/kernel/arch/i386/IDTc.o
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/arch/i386/serial.c -o obj/GlucoseKernel/kernel/arch/i386/serial.o
gcc -m32 -I GlucoseKernel/include/ -std=gnu99 -nostdlib -ffreestanding -O2 -Wall -Wextra -c GlucoseKernel/kernel/arch/i386/APIC.c -o obj/GlucoseKernel/kernel/arch/i386/APIC.o


#linker
gcc -m32 -T linker.ld -o Glucose.bin -ffreestanding -O2 -nostdlib \
obj/GlucoseKernel/boot/boot.o                                     \
obj/GlucoseKernel/kernel/astring.o                                \
obj/GlucoseKernel/kernel/cstring.o                                \
obj/GlucoseKernel/kernel/stdio.o                                  \
obj/GlucoseKernel/kernel/assert.o                                 \
obj/GlucoseKernel/kernel/stdlib.o                                 \
obj/GlucoseKernel/kernel/locale.o                                 \
obj/GlucoseKernel/kernel/math.o                                   \
obj/GlucoseKernel/kernel/arch/i386/GDTa.o                         \
obj/GlucoseKernel/kernel/arch/i386/GDTc.o                         \
obj/GlucoseKernel/kernel/arch/i386/IDTa.o                         \
obj/GlucoseKernel/kernel/arch/i386/IDTc.o                         \
obj/GlucoseKernel/kernel/arch/i386/serial.o                       \
obj/GlucoseKernel/kernel/arch/i386/APIC.o                         \
obj/GlucoseKernel/kernel/kernel.o

cp Glucose.bin iso/boot/Glucose.bin

grub-mkrescue -o Glucose.iso iso
#export PATH=$PATH:/mnt/c/Program\ Files\ \(x86\)/Bochs-2.6.10
#bochsdbg.exe -q -f Glucose.bxrc
export PATH=$PATH:/mnt/c/Program\ Files/qemu
qemu-system-x86_64.exe -cdrom Glucose.iso -monitor stdio
objdump -d Glucose.bin > Glucose.dis
clear