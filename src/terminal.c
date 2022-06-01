#include "terminal.h"
#include "peekpoke.h"

char hexlookup[] = "0123456789abcdef";

void print(const char *str) {
    while (*str) {
        POKE(0x2ff, *str++);
    }
}

void printbyte(const char val) {
    POKE(0x2ff, hexlookup[(val >> 4) & 0xf]);
    POKE(0x2ff, hexlookup[val & 0xf]);
}

void printshort(const short val) {
    printbyte((val >> 8) & 0xff);
    printbyte(val & 0xff);
}

void printuuid(const char *uuid) {
    char i;
    for (i = 0; i < 16; i++) {
        POKE(0x2ff, hexlookup[(uuid[i] >> 4) & 0xf]);
        POKE(0x2ff, hexlookup[uuid[i] & 0xf]);
    }
}
