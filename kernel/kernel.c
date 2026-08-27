//Func Principal do Kernel
#include "kernel.h"

void ISRs(void){


    set_idt(0,isr0,0x08,0x8E,0);
    set_idt(1,isr1,0x08,0x8E,0);
    set_idt(2,isr2,0x08,0x8E,0);
    set_idt(3,isr3,0x08,0x8E,0);
    set_idt(4,isr4,0x08,0x8E,0);
    set_idt(5,isr5,0x08,0x8E,0);
    set_idt(6,isr6,0x08,0x8E,0);
    set_idt(7,isr7,0x08,0x8E,0);
    set_idt(8,isr8,0x08,0x8E,1);
    set_idt(9,isr9,0x08,0x8E,0);
    set_idt(10,isr10,0x08,0x8e,0);
    set_idt(11,isr11,0x08,0x8e,0);
    set_idt(12,isr12,0x08,0x8e,0);
    set_idt(13,isr13,0x08,0x8e,0);
    set_idt(14,isr14,0x08,0x8e,0);
    set_idt(15,isr15,0x08,0x8e,0);
    set_idt(16,isr16,0x08,0x8e,0);
    set_idt(17,isr17,0x08,0x8e,0);
    set_idt(18,isr18,0x08,0x8e,0);
    set_idt(19,isr19,0x08,0x8e,0);
    set_idt(20,isr20,0x08,0x8e,0);
    set_idt(21,isr21,0x08,0x8e,0);
}


void kernel_main(void)
{
    vga_set_color(VGA_LIGHT_GREEN, VGA_BLACK);
    vga_print(">");
   

    // vga_print(itoa((unsigned long)ptr)); MOSTRA VALOR onde kernel termina
    vga_set_color(VGA_LIGHT_RED,VGA_BLACK);

    /*ISRs 1 -> 21*/


    load_IDT();
    // volatile int a = 10;
    // volatile int b = 0;
    // int c = a/b;
    while(1){
      
    }
    
}
 