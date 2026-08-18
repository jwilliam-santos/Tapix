#include "vga.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static volatile uint16_t* const vga = (uint16_t*)0xB8000;
static uint8_t current_color = (VGA_RED | (VGA_BLACK << 4));

static uint16_t cursor;

void vga_set_color(uint8_t fg, uint8_t bg) {
    current_color = fg | (bg << 4);
}

void vga_putchar(char c) {
    vga[cursor++] = (current_color << 8) | c;

    if (cursor >= VGA_WIDTH * VGA_HEIGHT) {
        cursor = 0; 
    }
}

void vga_print(const char* s) {
    for (int i = 0; s[i]; i++) {
        vga_putchar(s[i]);
    }
}
void vga_input(uint32_t tecla){
    
    uint16_t caractere_vga = ((current_color & 0xFF) << 8) | (tecla & 0xFF);
    
    vga[cursor++] = caractere_vga;

    if (cursor >= VGA_WIDTH * VGA_HEIGHT) {
        cursor = 0; 
    }
}