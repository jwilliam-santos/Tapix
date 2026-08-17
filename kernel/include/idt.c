#include "idt.h"

void isr0(void)  { vga_print("Division Error");                  asm("hlt"); asm("cli"); }
void isr1(void)  { vga_print("Debug");                           asm("hlt"); asm("cli"); }
void isr2(void)  { vga_print("NMI");                             asm("hlt"); asm("cli"); }
void isr3(void)  { vga_print("Breakpoint");                      asm("hlt"); asm("cli"); }
void isr4(void)  { vga_print("Overflow");                        asm("hlt"); asm("cli"); }
void isr5(void)  { vga_print("Bound Range Exceeded");            asm("hlt"); asm("cli"); }
void isr6(void)  { vga_print("Invalid Opcode");                  asm("hlt"); asm("cli"); }
void isr7(void)  { vga_print("Device Not Available");            asm("hlt"); asm("cli"); }
void isr8(void)  { vga_print("Double Fault");                    asm("hlt"); asm("cli"); }
void isr9(void)  { vga_print("Coprocessor Segment Overrun");     asm("hlt"); asm("cli"); }
void isr10(void) { vga_print("Invalid TSS");                     asm("hlt"); asm("cli"); }
void isr11(void) { vga_print("Segment Not Present");             asm("hlt"); asm("cli"); }
void isr12(void) { vga_print("Stack-Segment Fault");             asm("hlt"); asm("cli"); }
void isr13(void) { vga_print("General Protection Fault");        asm("hlt"); asm("cli"); }
void isr14(void) { vga_print("Page Fault");                      asm("hlt"); asm("cli"); }
void isr15(void) { vga_print("Reserved");                        asm("hlt"); asm("cli"); }
void isr16(void) { vga_print("x87 FP Exception");                asm("hlt"); asm("cli"); }
void isr17(void) { vga_print("Alignment Check");                 asm("hlt"); asm("cli"); }
void isr18(void) { vga_print("Machine Check");                   asm("hlt"); asm("cli"); }
void isr19(void) { vga_print("SIMD FP Exception");               asm("hlt"); asm("cli"); }
void isr20(void) { vga_print("Virtualization Exception");        asm("hlt"); asm("cli"); }
void isr21(void) { vga_print("Control Protection Exception");    asm("hlt"); asm("cli"); }

void irq0(void)  { vga_print("IRQ0: Timer");        asm("hlt"); asm("cli"); }




void irq1(void)
{
    //==========================================
    //          TECLADO INPUT (IRQ1)
    //==========================================
}




void irq2(void)  { vga_print("IRQ2: Cascade");      asm("hlt"); asm("cli"); }
void irq3(void)  { vga_print("IRQ3: COM2");         asm("hlt"); asm("cli"); }
void irq4(void)  { vga_print("IRQ4: COM1");         asm("hlt"); asm("cli"); }
void irq5(void)  { vga_print("IRQ5: LPT2/Sound");   asm("hlt"); asm("cli"); }
void irq6(void)  { vga_print("IRQ6: Floppy");       asm("hlt"); asm("cli"); }
void irq7(void)  { vga_print("IRQ7: LPT1/Spurious");asm("hlt"); asm("cli"); }
void irq8(void)  { vga_print("IRQ8: RTC");          asm("hlt"); asm("cli"); }
void irq9(void)  { vga_print("IRQ9: ACPI");         asm("hlt"); asm("cli"); }
void irq10(void) { vga_print("IRQ10: Livre");       asm("hlt"); asm("cli"); }
void irq11(void) { vga_print("IRQ11: Livre");       asm("hlt"); asm("cli"); }
void irq12(void) { vga_print("IRQ12: Mouse PS/2");  asm("hlt"); asm("cli"); }
void irq13(void) { vga_print("IRQ13: FPU");         asm("hlt"); asm("cli"); }
void irq14(void) { vga_print("IRQ14: ATA Primario");asm("hlt"); asm("cli"); }
void irq15(void) { vga_print("IRQ15: ATA Secundario");asm("hlt"); asm("cli"); }