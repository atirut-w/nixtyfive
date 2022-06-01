#include "uif.h"
#include "peekpoke.h"
#include <string.h>

char uif_read_byte(short portaddr) {
    return PEEK(portaddr);
}

void uif_write_tag(short portaddr, short tag) {
    POKE(portaddr, tag >> 8);
    POKE(portaddr, tag & 0xff);
}

void uif_write_uuid(short portaddr, char *uuid) {
    char i;
    for (i = 0; i < 16; i++) {
        POKE(portaddr, uuid[i]);
    }
}

void uif_write_string(short portaddr, char *str) {
    char i;
    short len;

    len = strlen(str);

    uif_write_tag(portaddr, len & 0x3fff);

    for (i = 0; i < len; i++) {
        POKE(portaddr, str[i]);
    }
}
