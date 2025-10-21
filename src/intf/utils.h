#pragma once

#include <stdint.h>
#include <stddef.h>

extern size_t UPDATE_DELAY;

void delay(unsigned int count);
void outb(uint16_t port, uint8_t val);
uint8_t inb(uint16_t port);
void disable_cursor(void);