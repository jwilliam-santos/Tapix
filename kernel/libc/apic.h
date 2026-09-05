#ifndef APIC_H
#define APIC_H
#include <utypes.h>
#define IA32_APIC_BASE_MSR 0x1B
#define IA32_APIC_BASE_MSR_BSP 0x100 // Processor is a BSP
#define IA32_APIC_BASE_MSR_ENABLE 0x800
#include <idt.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#define PIC1 0x20
#define PIC2 0xA0
#define PIC1_COMMAND PIC1
#define PIC1_DATA (PIC1 + 1)
#define PIC2_COMMAND PIC2
#define PIC2_DATA (PIC2 + 1)
void pic_disable(void);
void Geral_apic(void);
void Mask_pic(uint8_t IRQline);

#endif
