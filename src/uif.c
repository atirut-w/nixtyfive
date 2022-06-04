#include "uif.h"
#include "peekpoke.h"
#include <string.h>

void uif_reset(volatile char* portaddr) {
    // Read and write a single byte to a port, then keep reading until overflow flag is set(BVS/BVC)
    asm volatile (
        "lda 0x242\n"
        "sta 0x242\n"
    "loop:\n"
        "clv\n"
        "lda 0x242\n"
        "bvc loop\n"
        : : "m"(portaddr)
    );
}

char uif_read_byte(volatile char* portaddr) {
    return PEEK(portaddr);
}

void uif_write_tag(volatile char* portaddr, short tag) {
    POKE(portaddr, tag >> 8);
    POKE(portaddr, tag & 0xff);
}

void uif_write_uuid(volatile char* portaddr, char *uuid) {
    char i;
    for (i = 0; i < 16; i++) {
        POKE(portaddr, uuid[i]);
    }
}

void uif_write_string(volatile char* portaddr, char *str) {
    char i;
    short len;

    len = strlen(str);

    uif_write_tag(portaddr, len & 0x3fff);

    for (i = 0; i < len; i++) {
        POKE(portaddr, str[i]);
    }
}

void uif_read_string(volatile char* portaddr, char *buff) {
    char i;
    short len = uif_read_byte(portaddr);

    for (i = 0; i < len; i++) {
        buff[i] = uif_read_byte(portaddr);
    }
    buff[i] = '\0';
}
