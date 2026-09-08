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
    mov ecx,edi
    
    rdmsr
    shl edx,cl
    
    ret
Readgister:
    


write_reg:    