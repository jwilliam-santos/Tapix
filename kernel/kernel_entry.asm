section .multiboot
align 8
    dd 0xE85250D6
    dd 0
    dd 24
    dd -(0xE85250D6 + 0 + 24)
    dw 0
    dw 0
    dd 8

section .text
bits 32
global kernel_entry

kernel_entry:
    cli
    mov esp, stack_top

    ; 1. habilita PAE no CR4
    mov eax, cr4
    or eax, (1 << 5)
    mov cr4, eax

    ; 2. monta page tables (identity mapping primeiros 2MB)
    mov edi, 0x1000
    mov cr3, edi
    xor eax, eax
    mov ecx, 4096
    rep stosd
    mov edi, cr3

    mov dword [edi],        0x2003  ; PML4[0] → PDPT
    add edi, 0x1000
    mov dword [edi],        0x3003  ; PDPT[0] → PD
    add edi, 0x1000
    mov dword [edi],        0x83    ; PD[0] → 2MB page

    ; 3. habilita Long Mode no EFER
    mov ecx, 0xC0000080
    rdmsr
    or eax, (1 << 8)
    wrmsr

    ; 4. habilita paginacao e entra em Long Mode
    mov eax, cr0
    or eax, (1 << 31) | (1 << 0)
    mov cr0, eax

    ; 5. far jump pro GDT 64-bit
    lgdt [gdt64.pointer]
    jmp 0x08:long_mode_entry

bits 64
long_mode_entry:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    extern kernel_main
    call kernel_main

.halt:
    hlt
    jmp .halt

; GDT 64-bit
section .rodata
gdt64:
    dq 0                        ; null
.code: equ $ - gdt64
    dq (1 << 43) | (1 << 44) | (1 << 47) | (1 << 53)  ; code 64-bit
.data: equ $ - gdt64
    dq (1 << 44) | (1 << 47) | (1 << 41)               ; data
.pointer:
    dw $ - gdt64 - 1
    dq gdt64

section .bss
align 16
stack_bottom:
    resb 16384
stack_top: