#include <arch/i386/APIC.h>

void* findRSDT()
{
    void* ret = (void*)0xE0000;
    char* a = "RSD PTR ";
    while(ret < (void*) 0xFFFFF)
        if(!strncmp((const char*)ret, a, 8))
            break;
        else
            ret+=0x10;
    
    RSDPDescriptor_t* ptr = (RSDPDescriptor_t*) ret;
    void* r0 = (void*)ptr->RSDTAddress;
    return r0;
}

void* findSDS(char* name)
{
    if(strlen(name) > 4)
    {
        printf("Name too big\n");
        return 0;
    }
    RSDT_t* rsdt = (RSDT_t*) findRSDT();
    int e = (rsdt->h.Length - sizeof(rsdt->h))/4;
    for(int i = 0; i < e; i++)
    {
        SDTHeader_t* h = (SDTHeader_t*) rsdt->SDTs[i];
        printf("0x%x\n",h);
        if(!strncmp(h->Signature,name, 4))
            return  (void*) h;
    }
    return NULL;
}


void RSDTPDiag(){
    RSDPDescriptor_t* r = findRSDT();
    printf("Checksum: %u\n",(u32)r->Checksum);
    printf("Revision: %u\n",(u32)r->Revision);
    printf("RSDTAddr: 0x%x\n",(u32)r->RSDTAddress);
    printf("Length..: %u\n",(u32)r->Length);
    printf("XSDTAddr: 0x%x\n",(u32)(r->XSDTAddress));
    printf("XChecksm: %u\n",(u32)r->Extendedchecksum);
}