//Func Principal do Kernel
#include "include/vga.h"
void kernel_main(void)
{
    vga_print("Hello World!");
    while(1);
}