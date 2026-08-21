//Func Principal do Kernel
#include "kernel.h"



void kernel_main(void)
{
    vga_set_color(VGA_LIGHT_GREEN, VGA_BLACK);
    vga_print(">");

    // vga_print(itoa((unsigned long)ptr)); //MOSTRA VALOR onde kernel termina
    vga_set_color(VGA_LIGHT_RED,VGA_BLACK);
    
    while(1){
        
    }
    
}
 