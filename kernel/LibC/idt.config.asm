[BITS 64]
section .idt ;Sessao da Idt
global __idt_start__
__idt_start__:;alocar Idt no Asm
    times 256 * 16 db 0

section .text ; sessao do texto
global load_IDT

ALIGN 8

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