#include <keyboard.h>





uint8_t inb(uint16_t porta ){
    uint8_t variavel;
    __asm__ __volatile__("inb %1, %0" : "=a"(variavel) : "Nd"(porta));
    return variavel;
}


extern void irq1() {
    uint8_t tecla = inb(0x60);
    int tamanho = sizeof(TeclaEspecial) / sizeof(TeclaEspecial[0]);

    for (int i = 0; i < tamanho; i++) {
       
        if (TeclaEspecial[i] == tecla && TeclaEspecial[i] != UNKNOWN) {
            TeclaEspecialMomento = true;
            if(TeclaEspecialMomento == true){
                if(tecla){
                if(tecla == ENTER){

                }
                if(tecla == LSHFT || tecla == RSHFT){

                }
                if(tecla == BACKSPACE){
                    
                }
            } 
            }
            
        }
    }
    if(TeclaEspecialMomento == false){
        uint32_t x = CaixaMomento[tecla];
        vga_uint32(x);
    
    }
    
}
