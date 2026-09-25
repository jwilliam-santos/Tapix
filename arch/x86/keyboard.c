#include <keyboard.h>
#include <stdint.h>

bool Caps;
extern volatile char last_key;
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

const uint32_t ENTER = 0x1C;  /*\n*/
const uint32_t BACKSPACE = 0x0E; /*\b*/ 
const uint32_t SPACE   = 0x39; 
const uint32_t TAB = 0x0D; /*\t*/

#define TECLADO_SIZE 128
// Teclas do Teclado espanhol
#define CH_ENE_MIN  0xA4  /* 'n' */
#define CH_ENE_MAI  0xA5  /* 'N' */
#define CH_EXCL_INV 0xAD  /* i */
#define CH_INTR_INV 0xA8  /* ? */
const uint32_t TeclasEspeciais[256] = {
    UNKNOWN,ESC,CTRL,LSHFT,RSHFT,ALT,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,
    SCRLCK,HOME,UP,LEFT,RIGHT,DOWN,PGUP,PGDOWN,END,INS,DEL,CAPS,NONE,ALTGR,
    NUMLCK,ENTER,BACKSPACE,TAB
};
uint8_t inb(uint16_t porta ){
    uint8_t variavel;
    __asm__ __volatile__("inb %1, %0" : "=a"(variavel) : "Nd"(porta));
    return variavel;
}
static inline void outb(unsigned short port, unsigned char val) {
  __asm__ __volatile__("outb %0, %1" : : "a"(val), "Nd"(port));
}
const char LowKeyboard[128] = {
    //  0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F
        0,   27,  '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  '0',  '-',  '=',    8,    9, // 0x00
      'q',  'w',  'e',  'r',  't',  'y',  'u',  'i',  'o',  'p',  '[',  ']',   13,    0,  'a',  's', // 0x10
      'd',  'f',  'g',  'h',  'j',  'k',  'l',  ';', '\'',  '`',    0, '\\',  'z',  'x',  'c',  'v', // 0x20
      'b',  'n',  'm',  ',',  '.',  '/',    0,  '*',    0,  ' ',    0,    0,    0,    0,    0,    0, // 0x30
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, // 0x40
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, // 0x50
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, // 0x60
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, // 0x70
};
uint8_t *tecladomomento = LowKeyboard;
void keyboard(uint8_t scancode) {
    if (scancode < 250) {
        char c = tecladomomento[scancode];
        if (c != 0 && !(scancode & 0x80)) { // ignora key release (bit 7)
            last_key = c;
        }
    }
}
