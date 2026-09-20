#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdbool.h>
#include <stdint.h>
#include <vga.h>
void keyboard( uint8_t scancode);
extern void irq1asm(void);


#endif