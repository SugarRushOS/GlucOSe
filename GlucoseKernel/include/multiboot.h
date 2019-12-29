#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include <typedef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct multibootHeader_s
{
    u32 magic;
    u32 flags;
    u32 checksum;
    u32 header_addr;
    u32 load_addr;
    u32 load_end_addr;
    u32 bss_end_addr;
    u32 entry_addr;
    u32 mode_type;
    u32 width;
    u32 height;
    u32 depth;
};
typedef struct multibootHeader_s multibootHeader_t;

extern multibootHeader_t multiheader;

struct multibootInformation_s
{
    u32 flags;

    u32 mem_lower;
    u32 mem_upper;

    u32 boot_device;

    u32 cmdline;

    u32 mods_count;
    u32 mods_addr;

    u32 syms1;
    u32 syms2;
    u32 syms3;

    u32 mmap_length;
    u32 mmap_addr;

    u32 drives_length;
    u32 drives_addr;

    u32 config_table;

    u32 boot_loader_name;

    u32 apm_table;

    u32 vbe_control_info;
    u32 vbe_mode_info;
    u16 vbe_mode;
    u16 vbe_interface_seg;
    u16 vbe_interface_off;
    u16 vbe_interface_len;

    u64 framebuffer_addr;
    u32 framebuffer_pitch;
    u32 framebuffer_width;
    u32 framebuffer_height;
    u8 framebuffer_bpp;
    u8 framebuffer_type;

    u8 framebuffer_red_field_position;
    u8 framebuffer_red_mask_size;
    u8 framebuffer_green_field_position;
    u8 framebuffer_green_mask_size;
    u8 framebuffer_blue_field_position;
    u8 framebuffer_blue_mask_size;
};
typedef struct multibootInformation_s multibootInformation_t;

struct mmap_s
{
    u64 base;
    u64 length;
    u32 type;
};
typedef struct mmap_s mmap_t;

void mbdiag(multibootInformation_t* h); //➖


#endif
