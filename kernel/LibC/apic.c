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
   *
   * */
  outb(PIC1_DATA, 0xff);
  outb(PIC2_DATA, 0xff);


}




void Geral_apic(void){
  /*Apic Code*/
  pic_disable();
  asm("sti");
}