#ifndef APIC_H
#define APIC_H
#include <utypes.h>

#include <idt.h>
#include <stdbool.h>
#include <stdlib.h>
#define PIC1 0x20
#define PIC2 0xA0

void pic_disable(void);
void Geral_apic(void);


#endif
