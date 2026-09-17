global cpuSetMSR
global ReadRegister
global write_reg
global cpuGetMSR

cpuSetMSR:
    ;parametro 1 chega em rdi
    ;parametro 2 chega em rsi
    ;parametro 3 chega em rdx
    mov ecx,edi
    mov eax,esi
    wrmsr
    ret
cpuGetMSR:
    mov ecx, edi    
    rdmsr         
    
    shl rdx, 32     
    or  rax, rdx    
    ret          
    
ReadRegister:
    mov ecx, edi        
    rdmsr            
    shl rdx, 32        
    or  rax, rdx        
    ret
write_reg:    
    mov ecx, edi        
    mov rax, rsi      
    mov rdx, rsi     
    shr rdx, 32       
              
    wrmsr               
    ret

section .note.GNU-stack noalloc noexec nowrite progbits