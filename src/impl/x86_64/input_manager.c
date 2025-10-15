#include "input_manager.h"
#include <stdint.h>

#define PS2_DATA    0x60

static inline uint8_t inb(uint16_t port) {
    uint8_t value;
    __asm__ volatile ("inb %1, %0" : "=a"(value) : "Nd"(port));
    return value;
}

uint8_t read_scancode(void) {
    return inb(PS2_DATA);
}

char detect_char(void) {
    uint8_t sc = read_scancode();

    if (sc & 0x80)
        return '\0';

    char c = scancode_table[sc];
    if (c)
        return c;

    //backup
    return '\0';
}