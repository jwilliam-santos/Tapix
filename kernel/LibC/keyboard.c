#include <keyboard.h>


bool capsOn;
bool TeclaEspecialMomento = false;
bool capsLock;
//Codigo Teclas Especiais em hexadecimal
const uint32_t UNKNOWN = 0x00;       
const uint32_t ESC     = 0x01;       
const uint32_t CTRL    = 0x1D;       
const uint32_t LSHFT   = 0x2A;       
const uint32_t RSHFT   = 0x36;        
const uint32_t ALT     = 0x38;        
const uint32_t F1 = 0x3B;
const uint32_t F2 = 0x3C;
const uint32_t F3 = 0x3D;
const uint32_t F4 = 0x3E;
const uint32_t F5  = 0x3F;
const uint32_t F6  = 0x40;
const uint32_t F7  = 0x41;
const uint32_t F8  = 0x42;
const uint32_t F9  = 0x43;
const uint32_t F10 = 0x44;
const uint32_t F11  = 0x57;        
const uint32_t F12  = 0x58;
const uint32_t SCRLCK = 0x46;       


const uint32_t HOME  = 0x47;
const uint32_t UP   = 0x48;
const uint32_t LEFT  = 0x4B;
const uint32_t RIGHT = 0x4D;
const uint32_t DOWN  = 0x50;
const uint32_t PGUP  = 0x49;
const uint32_t PGDOWN = 0x51;
const uint32_t END = 0x4F;
const uint32_t INS = 0x52;
const uint32_t DEL = 0x53;

const uint32_t CAPS  = 0x3A;       
const uint32_t NONE = 0x00;      
const uint32_t ALTGR = 0x38;        
const uint32_t NUMLCK = 0x45;       

const uint32_t ENTER = 0x1C;        
const uint32_t BACKSPACE = 0x0E;
const uint32_t SPACE   = 0x39;
const uint32_t TAB = 0x0D;

const uint32_t CaixaBaixa[128] = {
UNKNOWN,ESC,'1','2','3','4','5','6','7','8',
'9','0','-','=','\b','\t','q','w','e','r',
't','y','u','i','o','p','[',']','\n',CTRL,
'a','s','d','f','g','h','j','k','l',';',
'\'','`',LSHFT,'\\','z','x','c','v','b','n','m',',',
'.','/',RSHFT,'*',ALT,' ',CAPS,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,NUMLCK,SCRLCK,HOME,UP,PGUP,'-',LEFT,UNKNOWN,RIGHT,
'+',END,DOWN,PGDOWN,INS,DEL,UNKNOWN,UNKNOWN,UNKNOWN,F11,F12,UNKNOWN
};

uint32_t CaixaMomento[128] = {
UNKNOWN,ESC,'1','2','3','4','5','6','7','8',
'9','0','-','=','\b','\t','q','w','e','r',
't','y','u','i','o','p','[',']','\n',CTRL,
'a','s','d','f','g','h','j','k','l',';',
'\'','`',LSHFT,'\\','z','x','c','v','b','n','m',',',
'.','/',RSHFT,'*',ALT,' ',CAPS,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,NUMLCK,SCRLCK,HOME,UP,PGUP,'-',LEFT,UNKNOWN,RIGHT,
'+',END,DOWN,PGDOWN,INS,DEL,UNKNOWN,UNKNOWN,UNKNOWN,F11,F12,UNKNOWN
};
uint32_t TeclaEspecial[128]= {
    UNKNOWN, ESC, CTRL, LSHFT, RSHFT, ALT, 
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, 
    SCRLCK, HOME, UP, LEFT, RIGHT, DOWN, PGUP, PGDOWN, END, INS, DEL, 
    CAPS, NONE, ALTGR, NUMLCK, 
    ENTER, BACKSPACE, SPACE, TAB

};

 uint32_t CaixaAlta[128] = {
    UNKNOWN,ESC,'!','@','#','$','%','^','&','*','(',')','_','+','\b','\t','Q','W','E','R',
'T','Y','U','I','O','P','{','}','\n',CTRL,'A','S','D','F','G','H','J','K','L',':','"','~',LSHFT,'|','Z','X','C',
'V','B','N','M','<','>','?',RSHFT,'*',ALT,' ',CAPS,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,NUMLCK,SCRLCK,HOME,UP,PGUP,'-',
LEFT,UNKNOWN,RIGHT,'+',END,DOWN,PGDOWN,INS,DEL,UNKNOWN,UNKNOWN,UNKNOWN,F11,F12,
};





uint8_t inb(uint16_t porta ){
    uint8_t variavel;
    __asm__ __volatile__("inb %1, %0" : "=a"(variavel) : "Nd"(porta));
    return variavel;
}


extern void keyboard() {
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
