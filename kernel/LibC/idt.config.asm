[BITS 64]

section .text
global load_IDT
extern idt


global load_IDT

ALIGN 8

KERNEL_CS equ 0x08

; void load_IDT(void);
load_IDT:
    lidt [rel idtr]
    sti
    ret
idtr:
    dw 256*16 -1
    dq idt 


section .note.GNU-stack noalloc noexec nowrite progbits