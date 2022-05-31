#include "peekpoke.h"

void print(const char *str) {
    while (*str) {
        POKE(0x2ff, *str++);
    }
}

void main() {
    print("Hello, world!\n");
    // __asm__("brk");
}
