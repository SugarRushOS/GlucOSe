#include <multiboot.h>

void mbdiag(multibootInformation_t* h)
{
    multibootInformation_t i = *h;
    if(i.flags & 1 << 0)
    {
        printf("Lower memory.......: %uKB\n", i.mem_lower);
        printf("Upper memory.......: %iKB\n", i.mem_upper);
    }
    if(i.flags & 1 << 1)
    {
        printf("Booted from........: 0x%x\n", i.boot_device >> 24);
    }
    if(i.flags & 1 << 2)
    {
        printf("Command line.......: \"%s\"\n", i.cmdline);
    }
    if(i.flags & 1 << 3)
    {
        printf("Module count.......: %i\n", i.mods_count);
        if(i.mods_count)
        {
            //TODO
        }
    }
    if((i.flags & 1 << 4) ^ (i.flags & 1 << 4))
    {
        //TODO
    }
    if(i.flags & 1 << 6)
    {
        printf("MMAP length........: %u\n", i.mmap_length);
        printf("MMAP address.......: 0x%x\n", i.mmap_addr);
    }
    if(i.flags & 1 << 7)
    {
        printf("Disk...............: P");
    }
    if(i.flags & 1 << 8)
    {

    }
    if(i.flags & 1 << 9)
    {
        if(i.boot_loader_name)
            printf("Bootloadername.: %s\n", i.boot_loader_name);
    }
    if(i.flags & 1 << 10)
    {

    }
    if(i.flags & 1 << 11)
    {
        printf("VBECotrolInfo......: 0x%x\n",i.vbe_control_info);
        printf("VBEModeInfo........: 0x%x\n",i.vbe_mode_info);
        printf("VBEMode............: 0x%x\n",i.vbe_mode);
        printf("VBEInterfaceSeg....: 0x%x\n",i.vbe_interface_seg);
        printf("VBEInterfaceOffset.: 0x%x\n",i.vbe_interface_off);
        printf("VBEInterfaceLength.: 0x%x\n",i.vbe_interface_len);
    }
    if(i.flags & 1 << 12)
    {
        printf("FramebufferAddr....: 0x%x\n",i.framebuffer_addr);
        printf("FramebufferPitch...: %u\n",i.framebuffer_pitch);
        printf("FramebufferWidth...: %u\n",i.framebuffer_width);
        printf("FramebufferHeight..: %u\n",i.framebuffer_height);
        printf("FramebufferBPP.....: %u\n",i.framebuffer_bpp);
        printf("FramebufferType....: %u\n",i.framebuffer_type);
        printf("RFP %u, RMS %u, GFP %u, GMS %u, BFP %u, BMS %u\n", i.framebuffer_red_field_position, i.framebuffer_red_mask_size, i.framebuffer_green_field_position, i.framebuffer_green_mask_size, i.framebuffer_blue_field_position, i.framebuffer_blue_mask_size);
    }
}