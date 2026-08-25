ENTRY(kernel_entry)

SECTIONS
{
    . = 1M;

    .text :
    {
        *(.multiboot)
        *(.text)
    }
    .idt :
{
    __idt_start__ = .;
    KEEP(*(.idt))
    . += 256 * 16;
}
    .rodata :
    {
        *(.rodata)
    }

    .data :
    {
        *(.data)
    }

    .bss :
    {
        *(COMMON)
        *(.bss)
    }
    kernel_end = .;
    
}