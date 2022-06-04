#include "uif.h"
#include "peekpoke.h"
#include <string.h>

void uif_reset_port1() {
    asm volatile (
        "lda $240\n"
        "sta $240\n"
    "loop:\n"
        "clv\n"
        "lda $240\n"
        "bvc loop\n"
    );
}

void uif_reset_port2() {
    asm volatile (
        "lda $242\n"
        "sta $242\n"
    "loop:\n"
        "clv\n"
        "lda $242\n"
        "bvc loop\n"
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
