#ifndef APIC_H
#define APIC_H
#include <utypes.h>

#include <idt.h>
#include <stdbool.h>
#include <stdlib.h>
#define PIC1 0x20
#define PIC2 0xA0
#define PIC1_COMMAND PIC1
#define PIC1_DATA (PIC1 + 1)
#define PIC2_COMMAND PIC2
#define PIC2_DATA (PIC2 + 1)
void pic_disable(void);
void Geral_apic(void);


#endif
