section .multiboot
align 8
    dd 0xE85250D6         ; magic number multiboot2
    dd 0                  ; arquitetura: x86 protected mode
    dd 24                 ; tamanho do header
    dd -(0xE85250D6 + 0 + 24) ; checksum

    ; tag de fim — obrigatória
    dw 0                  ; tipo 0 = end tag
    dw 0                  ; flags
    dd 8                  ; tamanho

section .text
global kernel_entry
kernel_entry:
    ; desabilita interrupcoes
    cli

    ; configura a stack
    mov esp, stack_top

    ; chama o kernel em C
    extern kernel_main
    call kernel_main

    ; se kernel_main retornar, trava aqui
.halt:
    hlt
    jmp .halt

section .bss
align 16
stack_bottom:
    resb 16384            ; 16KB de stack
stack_top: