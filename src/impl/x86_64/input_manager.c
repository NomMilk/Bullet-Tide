#include "input_manager.h"
#include "utils.h"
#include <stdint.h>

//god bless that one guy at ibm who decided to make a port just for the keyboard
#define PS2_DATA    0x60

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