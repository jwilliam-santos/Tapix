#include <idt.h>



/*Estrutura do Descritor 64bits 
* De "https://wiki.osdev.org/Interrupt_Descriptor_Table#Structure_on_x86-64"
*/
typedef struct {
    uint16_t offset_1;
    uint16_t selector;
    uint8_t  ist;
    uint8_t  type_attributes;
    uint16_t offset_2;
    uint32_t offset_3;
    uint32_t zero;
} __attribute__((packed)) idt_entry_t;
idt_entry_t idt[256];

void set_idt(int vector, void *isr_handler, uint16_t selector, uint8_t flags, uint8_t ist) // Creditos da func  á "doraibu"
{
    uint64_t handler_addr = (uint64_t)isr_handler;
    
    idt[vector].offset_1 = (uint16_t)(handler_addr & 0xFFFF);
    idt[vector].selector = selector;
    idt[vector].ist = ist & 0x07;
    idt[vector].type_attributes = flags;
    idt[vector].offset_2 = (uint16_t)((handler_addr >> 16) & 0xFFFF);
    idt[vector].offset_3 = (uint32_t)(handler_addr >> 32);
    idt[vector].zero = 0;
}






extern void isr0(void)  { vga_print("Division Error");                  asm("hlt"); asm("cli"); }
extern void isr1(void)  { vga_print("Debug");                           asm("hlt"); asm("cli"); }
extern void isr2(void)  { vga_print("NMI");                             asm("hlt"); asm("cli"); }
extern void isr3(void)  { vga_print("Breakpoint");                      asm("hlt"); asm("cli"); }
extern void isr4(void)  { vga_print("Overflow");                        asm("hlt"); asm("cli"); }
extern void isr5(void)  { vga_print("Bound Range Exceeded");            asm("hlt"); asm("cli"); }
extern void isr6(void)  { vga_print("Invalid Opcode");                  asm("hlt"); asm("cli"); }
extern void isr7(void)  { vga_print("Device Not Available");            asm("hlt"); asm("cli"); }
extern void isr8(void)  { vga_print("Double Fault");                    asm("hlt"); asm("cli"); }
extern void isr9(void)  { vga_print("Coprocessor Segment Overrun");     asm("hlt"); asm("cli"); }
extern void isr10(void) { vga_print("Invalid TSS");                     asm("hlt"); asm("cli"); }
extern void isr11(void) { vga_print("Segment Not Present");             asm("hlt"); asm("cli"); }
extern void isr12(void) { vga_print("Stack-Segment Fault");             asm("hlt"); asm("cli"); } /*Corrigir erro nessa Isr*/
extern void isr13(void) { vga_print("General Protection Fault");        asm("hlt"); asm("cli"); }
extern void isr14(void) { vga_print("Page Fault");                      asm("hlt"); asm("cli"); }
extern void isr15(void) { vga_print("Reserved");                        asm("hlt"); asm("cli"); }
extern void isr16(void) { vga_print("x87 FP Exception");                asm("hlt"); asm("cli"); }
extern void isr17(void) { vga_print("Alignment Check");                 asm("hlt"); asm("cli"); }
extern void isr18(void) { vga_print("Machine Check");                   asm("hlt"); asm("cli"); }
extern void isr19(void) { vga_print("SIMD FP Exception");               asm("hlt"); asm("cli"); }
extern void isr20(void) { vga_print("Virtualization Exception");        asm("hlt"); asm("cli"); }
extern void isr21(void) { vga_print("Control Protection Exception");    asm("hlt"); asm("cli"); }

//IRQS
extern void irq0(void)  { vga_print("IRQ0: Timer");        asm("hlt"); asm("cli"); }

/*IRQ 1 em keyboard.c*/
extern void irq2(void)  { vga_print("IRQ2: Cascade");      asm("hlt"); asm("cli"); }
extern void irq3(void)  { vga_print("IRQ3: COM2");         asm("hlt"); asm("cli"); }
extern void irq4(void)  { vga_print("IRQ4: COM1");         asm("hlt"); asm("cli"); }
extern void irq5(void)  { vga_print("IRQ5: LPT2/Sound");   asm("hlt"); asm("cli"); }
extern void irq6(void)  { vga_print("IRQ6: Floppy");       asm("hlt"); asm("cli"); }
extern void irq7(void)  { vga_print("IRQ7: LPT1/Spurious");asm("hlt"); asm("cli"); }
extern void irq8(void)  { vga_print("IRQ8: RTC");          asm("hlt"); asm("cli"); }
extern void irq9(void)  { vga_print("IRQ9: ACPI");         asm("hlt"); asm("cli"); }
extern void irq10(void) { vga_print("IRQ10: Livre");       asm("hlt"); asm("cli"); }
extern void irq11(void) { vga_print("IRQ11: Livre");       asm("hlt"); asm("cli"); }
extern void irq12(void) { vga_print("IRQ12: Mouse PS/2");  asm("hlt"); asm("cli"); }
extern void irq13(void) { vga_print("IRQ13: FPU");         asm("hlt"); asm("cli"); }
extern void irq14(void) { vga_print("IRQ14: ATA Primario");asm("hlt"); asm("cli"); }
extern void irq15(void) { vga_print("IRQ15: ATA Secundario");asm("hlt"); asm("cli");}