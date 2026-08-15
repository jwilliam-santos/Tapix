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

; void set_idt_entry(void *isr, uint8_t flags, uint8_t index);
; SysV AMD64: rdi = isr, rsi = flags, rdx = index
; Cada gate em long mode tem 16 bytes.
set_idt_entry:
    mov rax, rdi              ; endereço do handler
    mov rcx, rdx              ; índice
    mov rbx, rsi              ; flags (type/attr)

    mov rdi, __idt_start__
    shl rcx, 4                ; index * 16
    add rdi, rcx

    mov word [rdi + 0], ax    ; offset 15:0
    shr rax, 16
    mov word [rdi + 2], KERNEL_CS
    mov byte [rdi + 4], 0     ; IST
    mov byte [rdi + 5], bl    ; type / attributes
    mov word [rdi + 6], ax    ; offset 31:16
    shr rax, 16
    mov dword [rdi + 8], eax  ; offset 63:32
    mov dword [rdi + 12], 0   ; reserved
    ret

idtr:
    dw 256 * 16 - 1
    dq __idt_start__

section .note.GNU-stack noalloc noexec nowrite progbits