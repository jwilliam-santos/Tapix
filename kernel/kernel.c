//Func Principal do Kernel
#include "include/vga.h"
#include "LibC/stdlib.h"
void kernel_main(void)
{
    vga_set_color(VGA_LIGHT_GREEN, VGA_BLACK);
    int* ptr = calloc(54 , sizeof(int));
    // vga_print("Hello World,Tapix!");
    vga_print(itoa((unsigned long)ptr)); //MOSTRA VALOR onde kernel termina
    while(1);
}
