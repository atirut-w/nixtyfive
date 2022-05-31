#include "terminal.h"
#include "peekpoke.h"

void print(const char *str) {
    while (*str) {
        POKE(0x2ff, *str++);
    }
}

void printbyte(const char val) {
    char lookup[] = "0123456789abcdef";
    POKE(0x2ff, lookup[(val >> 4) & 0xf]);
    POKE(0x2ff, lookup[val & 0xf]);
}

void printshort(const short val) {
    printbyte((val >> 8) & 0xff);
    printbyte(val & 0xff);
}
