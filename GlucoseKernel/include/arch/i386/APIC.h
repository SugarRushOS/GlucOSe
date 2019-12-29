#ifndef APIC_H
#define APIC_H

#include <typedef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <arch/i386/CPUID.h>
#include <stdbool.h>

struct RSDPDescriptor_s
{
    char Signature[8];
    u8   Checksum;
    char OEMID[6];
    u8   Revision;
    u32  RSDTAddress;
    u32  Length;
    u64  XSDTAddress;
    u8   Extendedchecksum;
    u8   Rsvd[3];
};
typedef struct RSDPDescriptor_s RSDPDescriptor_t;

struct SDTHeader_s
{
    char Signature[4];
    u32 Length;
    u8 Revision;
    u8 Checksum;
    char OEMID[6];
    char OEMTableID[8];
    u32 OEMRevision;
    u32 CreatorID;
    u32 CreatorRevision;
};
typedef struct SDTHeader_s SDTHeader_t;

struct RSDT_s
{
    SDTHeader_t h;
    u32* SDTs;
};
typedef struct RSDT_s RSDT_t;

struct GenericAddressStructure_s
{
  u8 AddressSpace;
  u8 BitWidth;
  u8 BitOffset;
  u8 AccessSize;
  u64 Address;
};
typedef struct GenericAddressStructure_s GenericAddressStructure_t;

struct FADT_s
{
    SDTHeader_t header;
    u32 FirmwareCtrl;
    u32 DSDT;

    u8  PreferredPowerManagementProfile;
    u16 SCI_Interrupt;
    u32 SMI_CommandPort;
    u8  AcpiEnable;
    u8  AcpiDisable;
    u8  S4BIOS_REQ;
    u8  PSTATE_Control;
    u32 PM1aEventBlock;
    u32 PM1bEventBlock;
    u32 PM1aControlBlock;
    u32 PM1bControlBlock;
    u32 PM2ControlBlock;
    u32 PMTimerBlock;
    u32 GPE0Block;
    u32 GPE1Block;
    u8  PM1EventLength;
    u8  PM1ControlLength;
    u8  PM2ControlLength;
    u8  PMTimerLength;
    u8  GPE0Length;
    u8  GPE1Length;
    u8  GPE1Base;
    u8  CStateControl;
    u16 WorstC2Latency;
    u16 WorstC3Latency;
    u16 FlushSize;
    u16 FlushStride;
    u8  DutyOffset;
    u8  DutyWidth;
    u8  DayAlarm;
    u8  MonthAlarm;
    u8  Century;

    // reserved in ACPI 1.0; used since ACPI 2.0+
    u16 BootArchitectureFlags;

    u8  Reserved2;
    u32 Flags;

    // 12 byte structure; see below for details
    GenericAddressStructure_t ResetReg;

    u8  ResetValue;
    u8  Reserved3[3];

    // 64bit pointers - Available on ACPI 2.0+
    u64                X_FirmwareControl;
    u64                X_Dsdt;

    GenericAddressStructure_t X_PM1aEventBlock;
    GenericAddressStructure_t X_PM1bEventBlock;
    GenericAddressStructure_t X_PM1aControlBlock;
    GenericAddressStructure_t X_PM1bControlBlock;
    GenericAddressStructure_t X_PM2ControlBlock;
    GenericAddressStructure_t X_PMTimerBlock;
    GenericAddressStructure_t X_GPE0Block;
    GenericAddressStructure_t X_GPE1Block;
};
typedef struct FADT_s FADT_t;


void* findRSDT();
void* findSDS(char* name);
void RSDTPDiag();
#endif