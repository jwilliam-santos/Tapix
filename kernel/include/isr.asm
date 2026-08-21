;extern
extern isr0
extern isr1
extern isr2
extern isr3
extern isr4
extern isr5
extern isr6
extern isr7
extern isr8
extern isr9
extern isr10
extern isr11
extern isr12
extern isr13
extern isr14
extern isr15
extern isr16
extern isr17
extern isr18
extern isr19
extern isr20
extern isr21
extern irq0
extern irq1
extern irq2
extern irq3
extern irq4
extern irq5
extern irq6
extern irq7
extern irq8
extern irq9
extern irq10
extern irq11
extern irq12
extern irq13
extern irq14
extern irq15
global ir0

%macro  pushad 0 ;macro func pushad em 64bits
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push rbp
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15
%endmacro

%macro popad 0 ; macro func popad 64bits
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rbp
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
%endmacro
isr0asm:
    pushad
    call isr0
    popad
    iret
isr1asm:
    pushad 
    call isr1
    popad
    iret
isr2asm:
    pushad
    call isr2
    popad
    iret
isr3asm:
    pushad
    call isr3
    popad
    iret
isr4asm:
    pushad
    call isr4
    popad
    iret
isr5asm:
    pushad
    call isr5
    popad
    iret
isr6asm:
    pushad
    call isr6
    popad
    iret
isr7asm:
    pushad
    call isr7
    popad
    iret
isr8asm:
    pushad
    call isr8
    popad
    iret
isr9asm:
    pushad
    call isr9
    popad
    iret
isr10asm:
    pushad
    call isr10
    popad
    iret
isr11asm:
    pushad
    call isr11
    popad
    iret
isr12asm:
    pushad
    call isr12
    popad
    iret
isr13asm:
    pushad
    call isr13
    popad
    iret
isr14asm:
    pushad
    call isr14
    popad
    iret 
isr15asm:
    pushad
    call isr15
    popad
    iret
isr16asm:
    pushad
    call isr16
    popad
    iret
isr17asm:
    pushad
    call isr17
    popad
    iret    
isr18asm:
    pushad
    call isr18
    popad
    iret
isr19asm:
    pushad
    call isr19
    popad
    iret
isr20asm:
    pushad
    call isr20
    popad
    iret
isr21asm:
    pushad
    call isr21
    popad
    iret
irq1asm:;func teclado
    pushad ; salva register
    in al, 0x60

    movzx eax, al       
    push rax

    mov al, 0x20
    call irq1
    add rsp, 8  ;limpa pilha
    out 0x20, al ;Eoi Pic
    popad ;pusha resister
    iret

    ;Irq a Fazer    
    ;irq2
    ;irq3
    ;irq4
    ;irq5
    ;irq6
    ;irq7
    ;irq8
    ;irq9
    ;irq10
    ;irq11
    ;irq12
    ;irq13
    ;irq14
    ;irq15


    
