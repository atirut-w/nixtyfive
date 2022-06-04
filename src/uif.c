#include "uif.h"
#include "peekpoke.h"
#include <string.h>

void uif_reset_port1() {
    asm volatile (
        "lda $240\n"
        "sta $240\n"
    "p1l:\n"
        "clv\n"
        "lda $240\n"
        "bvc p1l\n"
    );
}

void uif_reset_port2() {
    asm volatile (
        "lda $242\n"
        "sta $242\n"
    "p2l:\n"
        "clv\n"
        "lda $242\n"
        "bvc p2l\n"
    );
}

void uif_write_tag(volatile char* portaddr, short tag) {
    *portaddr = (char)(tag >> 8);
    *portaddr = (char)(tag & 0xff);
}

void uif_write_uuid(volatile char* portaddr, char *uuid) {
    for (int i = 0; i < 16; i++) {
        *portaddr = uuid[i];
    }
}

void uif_write_string(volatile char* portaddr, char *str) {
    int len = strlen(str);

    uif_write_tag(portaddr, len & 0x3fff);

    for (int i = 0; i < len; i++) {
        *portaddr = str[i];
    }
}

short uif_read_tag(volatile char* portaddr) {
    short tag = (*portaddr << 8);
    tag |= *portaddr;
    return tag;
}

void uif_read_string(volatile char* portaddr, char *buff) {
    int len = *portaddr;
    int i;

    for (int i = 0; i < len; i++) {
        buff[i] = *portaddr;
        buff[i+1] = '\0';
    }
    buff[i] = '\0';
}
