#pragma once

#define UIF_PORT1 (volatile char*)0x240
#define UIF_PORT2 (volatile char*)0x242

#define UIFSTAT_CMD_ACK 0x00
#define UIFSTAT_UNK_ERR 0x01
#define UIFSTAT_UNR_CMD 0x02

#define UIFSTAT_INV_MSG 0x7e
#define UIFSTAT_MSG_TOO_LONG 0x7f
#define UIFSTAT_CMD_NOACK 0xff

#define UIFTAG_UUID 0xfff8
#define UIFTAG_END 0xffff

void uif_reset_port1();
void uif_reset_port2();

// Swap endianness of a UIF tag and write it to a UIF port
void uif_write_tag(volatile char* portaddr, short tag);
// Write a UUID to a UIF port
void uif_write_uuid(volatile char* portaddr, char *uuid);
// Write a string to a UIF port
void uif_write_string(volatile char* portaddr, char *str);

// Swap endianness of a UIF tag and read it from a UIF port
short uif_read_tag(volatile char* portaddr);
// Read a string from a UIF port
void uif_read_string(volatile char* portaddr, char *buff);
