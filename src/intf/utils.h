#pragma once

#include <stdint.h>
#include <stddef.h>

const static size_t UPDATE_DELAY = 500;

void delay(unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        for (unsigned int i = 0; i < 10000; ++i)
        {
            __asm__ volatile("nop");
        }
    }
}

//duplicated function but it's fine who tf cares
static inline void outb(uint16_t port, uint8_t val)
{
    __asm__ volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline void disable_cursor(void)
{
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
}