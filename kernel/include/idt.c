#include "idt.h"


bool capsOn;
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

const uint32_t CaixaAlta[128] = {
    UNKNOWN,ESC,'!','@','#','$','%','^','&','*','(',')','_','+','\b','\t','Q','W','E','R',
'T','Y','U','I','O','P','{','}','\n',CTRL,'A','S','D','F','G','H','J','K','L',':','"','~',LSHFT,'|','Z','X','C',
'V','B','N','M','<','>','?',RSHFT,'*',ALT,' ',CAPS,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,NUMLCK,SCRLCK,HOME,UP,PGUP,'-',
LEFT,UNKNOWN,RIGHT,'+',END,DOWN,PGDOWN,INS,DEL,UNKNOWN,UNKNOWN,UNKNOWN,F11,F12,
};
void isr0(void)  { vga_print("Division Error");                  asm("hlt"); asm("cli"); }
void isr1(void)  { vga_print("Debug");                           asm("hlt"); asm("cli"); }
void isr2(void)  { vga_print("NMI");                             asm("hlt"); asm("cli"); }
void isr3(void)  { vga_print("Breakpoint");                      asm("hlt"); asm("cli"); }
void isr4(void)  { vga_print("Overflow");                        asm("hlt"); asm("cli"); }
void isr5(void)  { vga_print("Bound Range Exceeded");            asm("hlt"); asm("cli"); }
void isr6(void)  { vga_print("Invalid Opcode");                  asm("hlt"); asm("cli"); }
void isr7(void)  { vga_print("Device Not Available");            asm("hlt"); asm("cli"); }
void isr8(void)  { vga_print("Double Fault");                    asm("hlt"); asm("cli"); }
void isr9(void)  { vga_print("Coprocessor Segment Overrun");     asm("hlt"); asm("cli"); }
void isr10(void) { vga_print("Invalid TSS");                     asm("hlt"); asm("cli"); }
void isr11(void) { vga_print("Segment Not Present");             asm("hlt"); asm("cli"); }
void isr12(void) { vga_print("Stack-Segment Fault");             asm("hlt"); asm("cli"); }
void isr13(void) { vga_print("General Protection Fault");        asm("hlt"); asm("cli"); }
void isr14(void) { vga_print("Page Fault");                      asm("hlt"); asm("cli"); }
void isr15(void) { vga_print("Reserved");                        asm("hlt"); asm("cli"); }
void isr16(void) { vga_print("x87 FP Exception");                asm("hlt"); asm("cli"); }
void isr17(void) { vga_print("Alignment Check");                 asm("hlt"); asm("cli"); }
void isr18(void) { vga_print("Machine Check");                   asm("hlt"); asm("cli"); }
void isr19(void) { vga_print("SIMD FP Exception");               asm("hlt"); asm("cli"); }
void isr20(void) { vga_print("Virtualization Exception");        asm("hlt"); asm("cli"); }
void isr21(void) { vga_print("Control Protection Exception");    asm("hlt"); asm("cli"); }

void irq0(void)  { vga_print("IRQ0: Timer");        asm("hlt"); asm("cli"); }




int irq1(uint32_t tecla) {
    
    int tamanho = sizeof(TeclaEspecial) / sizeof(TeclaEspecial[0]);

    for (int i = 0; i < tamanho; i++) {
       
        if (TeclaEspecial[i] == tecla && TeclaEspecial[i] != UNKNOWN) {
            return 0;
            if(irq1(tecla)){
                if(tecla == ENTER){

                }
                if(tecla == LSHFT || tecla == RSHFT){

                }
                if(tecla == BACKSPACE){
                    
                }
            } 
        }
    }
    return 1; 
    if(irq1(tecla) == 1){
        vga_input(tecla);
    }
}




void irq2(void)  { vga_print("IRQ2: Cascade");      asm("hlt"); asm("cli"); }
void irq3(void)  { vga_print("IRQ3: COM2");         asm("hlt"); asm("cli"); }
void irq4(void)  { vga_print("IRQ4: COM1");         asm("hlt"); asm("cli"); }
void irq5(void)  { vga_print("IRQ5: LPT2/Sound");   asm("hlt"); asm("cli"); }
void irq6(void)  { vga_print("IRQ6: Floppy");       asm("hlt"); asm("cli"); }
void irq7(void)  { vga_print("IRQ7: LPT1/Spurious");asm("hlt"); asm("cli"); }
void irq8(void)  { vga_print("IRQ8: RTC");          asm("hlt"); asm("cli"); }
void irq9(void)  { vga_print("IRQ9: ACPI");         asm("hlt"); asm("cli"); }
void irq10(void) { vga_print("IRQ10: Livre");       asm("hlt"); asm("cli"); }
void irq11(void) { vga_print("IRQ11: Livre");       asm("hlt"); asm("cli"); }
void irq12(void) { vga_print("IRQ12: Mouse PS/2");  asm("hlt"); asm("cli"); }
void irq13(void) { vga_print("IRQ13: FPU");         asm("hlt"); asm("cli"); }
void irq14(void) { vga_print("IRQ14: ATA Primario");asm("hlt"); asm("cli"); }
void irq15(void) { vga_print("IRQ15: ATA Secundario");asm("hlt"); asm("cli"); }