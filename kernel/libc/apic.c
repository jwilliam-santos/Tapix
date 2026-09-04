/*
 *Apic code
 *
 * */
#include <apic.h>

static inline void outb(unsigned short port, unsigned char val) {
  __asm__ __volatile__("outb %0, %1" : : "a"(val), "Nd"(port));
}

void pic_disable(void) {
  /*
   *Master Pic 0x0020
   *Slave Pic 0x0021
   *
   * do func outb to do outb in master and slave pin  (MasterPIC,0xff),
   * (SlavePic,0xff)
   * */
  outb(PIC1_DATA, 0xff);
  outb(PIC2_DATA, 0xff);
}

void Mask_pic(uint8_t IRQline){
  uint16_t port;
    uint8_t value;

    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) | (1 << IRQline);
    outb(port, value); 

}



void Geral_apic(void){
  /*Apic Geral Code*/
  pic_disable();
  Mask_pic(1);
  asm("sti");
}