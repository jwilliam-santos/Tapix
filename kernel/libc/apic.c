/*
 *Apic code
 *
 * */
#include <apic.h>


/*Enum CPUID*/
enum {
    CPUID_FEAT_EBX_BRAND_INDEX        = 0xFF << 0,
    CPUID_FEAT_EBX_CLFLUSH_LINE_SIZE  = 0xFF << 8,
    CPUID_FEAT_EBX_APIC_ID_SPACE      = 0xFF << 16,
    CPUID_FEAT_EBX_INITIAL_APIC_ID    = 0xFF << 24,
    
    CPUID_FEAT_ECX_SSE3               = 1 << 0,
    CPUID_FEAT_ECX_PCLMUL             = 1 << 1,
    CPUID_FEAT_ECX_DTES64             = 1 << 2,
    CPUID_FEAT_ECX_MONITOR            = 1 << 3,
    CPUID_FEAT_ECX_DS_CPL             = 1 << 4,
    CPUID_FEAT_ECX_VMX                = 1 << 5,
    CPUID_FEAT_ECX_SMX                = 1 << 6,
    CPUID_FEAT_ECX_EST                = 1 << 7,
    CPUID_FEAT_ECX_TM2                = 1 << 8,
    CPUID_FEAT_ECX_SSSE3              = 1 << 9,
    CPUID_FEAT_ECX_CID                = 1 << 10,
    CPUID_FEAT_ECX_SDBG               = 1 << 11,
    CPUID_FEAT_ECX_FMA                = 1 << 12,
    CPUID_FEAT_ECX_CX16               = 1 << 13,
    CPUID_FEAT_ECX_XTPR               = 1 << 14,
    CPUID_FEAT_ECX_PDCM               = 1 << 15,
    CPUID_FEAT_ECX_PCID               = 1 << 17,
    CPUID_FEAT_ECX_DCA                = 1 << 18,
    CPUID_FEAT_ECX_SSE4_1             = 1 << 19,
    CPUID_FEAT_ECX_SSE4_2             = 1 << 20,
    CPUID_FEAT_ECX_X2APIC             = 1 << 21,
    CPUID_FEAT_ECX_MOVBE              = 1 << 22,
    CPUID_FEAT_ECX_POPCNT             = 1 << 23,
    CPUID_FEAT_ECX_TSC                = 1 << 24,
    CPUID_FEAT_ECX_AES                = 1 << 25,
    CPUID_FEAT_ECX_XSAVE              = 1 << 26,
    CPUID_FEAT_ECX_OSXSAVE            = 1 << 27,
    CPUID_FEAT_ECX_AVX                = 1 << 28,
    CPUID_FEAT_ECX_F16C               = 1 << 29,
    CPUID_FEAT_ECX_RDRAND             = 1 << 30,
    CPUID_FEAT_ECX_HYPERVISOR         = 1 << 31,

    CPUID_FEAT_EDX_FPU                = 1 << 0,
    CPUID_FEAT_EDX_VME                = 1 << 1,
    CPUID_FEAT_EDX_DE                 = 1 << 2,
    CPUID_FEAT_EDX_PSE                = 1 << 3,
    CPUID_FEAT_EDX_TSC                = 1 << 4,
    CPUID_FEAT_EDX_MSR                = 1 << 5,
    CPUID_FEAT_EDX_PAE                = 1 << 6,
    CPUID_FEAT_EDX_MCE                = 1 << 7,
    CPUID_FEAT_EDX_CX8                = 1 << 8,
    CPUID_FEAT_EDX_APIC               = 1 << 9,
    CPUID_FEAT_EDX_SEP                = 1 << 11,
    CPUID_FEAT_EDX_MTRR               = 1 << 12,
    CPUID_FEAT_EDX_PGE                = 1 << 13,
    CPUID_FEAT_EDX_MCA                = 1 << 14,
    CPUID_FEAT_EDX_CMOV               = 1 << 15,
    CPUID_FEAT_EDX_PAT                = 1 << 16,
    CPUID_FEAT_EDX_PSE36              = 1 << 17,
    CPUID_FEAT_EDX_PSN                = 1 << 18,
    CPUID_FEAT_EDX_CLFLUSH            = 1 << 19,
    CPUID_FEAT_EDX_DS                 = 1 << 21,
    CPUID_FEAT_EDX_ACPI               = 1 << 22,
    CPUID_FEAT_EDX_MMX                = 1 << 23,
    CPUID_FEAT_EDX_FXSR               = 1 << 24,
    CPUID_FEAT_EDX_SSE                = 1 << 25,
    CPUID_FEAT_EDX_SSE2               = 1 << 26,
    CPUID_FEAT_EDX_SS                 = 1 << 27,
    CPUID_FEAT_EDX_HTT                = 1 << 28,
    CPUID_FEAT_EDX_TM                 = 1 << 29,
    CPUID_FEAT_EDX_IA64               = 1 << 30,
    CPUID_FEAT_EDX_PBE                = 1 << 31
};

static inline void cpuid(int code, uint32_t *a, uint32_t *d) {
  asm volatile("cpuid":"=a"(*a),"=d"(*d):"a"(code):"ecx","ebx");
}

static int check_apic(void)
{
  uint32_t eax, edx;
   cpuid(1, &eax, &edx);
   return edx & CPUID_FEAT_EDX_APIC;;
}
static inline void outb(unsigned short port, unsigned char val) {
  __asm__ __volatile__("outb %0, %1" : : "a"(val), "Nd"(port));
}

void pic_disable(void) {
  /*
   *Master Pic 0x0020
   *Slave Pic 0x0021
   *
   * do func outb to do outb in master and slave pin  (MasterPIC,0xff),
   * (SlavePic,0xff)
   * */
  outb(PIC1_DATA, 0xff);
  outb(PIC2_DATA, 0xff);
}

void Mask_pic(uint8_t IRQline){
  uint16_t port;
    uint8_t value;

    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) | (1 << IRQline);
    outb(port, value); 

}



void Geral_apic(void){
  /*Apic Geral Code*/
  pic_disable();
  Mask_pic(1);
  asm("sti");
}