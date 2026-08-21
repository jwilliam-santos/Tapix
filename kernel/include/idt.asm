;Arquivo para a Irq1 (e posteriores)
global irq1asm
extern irq1
irq1asm:
    pusha ; salva register
    in al 0x60
    out 0x60 al
    movzx eax, al       
    push eax
    call irq1
    add esp, 4 ;limpa pilha
    mov al, 0x20
    out 0x20, al ;Eoi Pic
    popa ;pusha resister
    iret
    


