[BITS 64]
ALIGN 8

extern __idt_start__

global load_IDT
global set_idt_entry

KERNEL_CS equ 0x08

; void load_IDT(void);
load_IDT:
    lidt [rel idtr]
    sti
    ret

idtr:
    dw 256 * 16 - 1
    dq __idt_start__

section .note.GNU-stack noalloc noexec nowrite progbits