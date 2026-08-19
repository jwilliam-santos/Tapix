#ifndef IDT_H
#define IDT_H

#include <utypes.h>
#include <vga.h>
#include <stdbool.h>

extern void load_IDT();
extern void set_idt_entry(void *isr, uint8_t flags, uint8_t index);

extern void ir0();

// Exceções da CPU
void isr0(void);   // #DE  Division Error
void isr1(void);   // #DB  Debug
void isr2(void);   // NMI  Non-Maskable Interrupt
void isr3(void);   // #BP  Breakpoint
void isr4(void);   // #OF  Overflow
void isr5(void);   // #BR  Bound Range Exceeded
void isr6(void);   // #UD  Invalid Opcode
void isr7(void);   // #NM  Device Not Available
void isr8(void);   // #DF  Double Fault
void isr9(void);   // Coprocessor Segment Overrun (obsoleto)
void isr10(void);  // #TS  Invalid TSS
void isr11(void);  // #NP  Segment Not Present
void isr12(void);  // #SS  Stack-Segment Fault
void isr13(void);  // #GP  General Protection Fault
void isr14(void);  // #PF  Page Fault
void isr15(void);  // Reserved
void isr16(void);  // #MF  x87 FP Exception
void isr17(void);  // #AC  Alignment Check
void isr18(void);  // #MC  Machine Check
void isr19(void);  // #XM  SIMD FP Exception
void isr20(void);  // #VE  Virtualization Exception
void isr21(void);  // #CP  Control Protection Exception

// IRQs (vetor = IRQ + 32)
void irq0(void);   // Timer
void irq1(uint32_t tecla);   // Teclado
void irq2(void);   // Cascade
void irq3(void);   // COM2
void irq4(void);   // COM1
void irq5(void);   // LPT2 / Sound
void irq6(void);   // Floppy
void irq7(void);   // LPT1 / Spurious
void irq8(void);   // RTC
void irq9(void);   // ACPI
void irq10(void);  // Livre
void irq11(void);  // Livre
void irq12(void);  // Mouse PS/2
void irq13(void);  // FPU
void irq14(void);  // ATA Primário
void irq15(void);  // ATA Secundário


#endif