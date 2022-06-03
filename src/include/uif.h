#ifndef UIF_H_INCLUDED
#define UIF_H_INCLUDED

#define UIF_PORT1 0x240
#define UIF_PORT2 0x242

#define UIFSTAT_CMD_ACK 0x00
#define UIFSTAT_UNK_ERR 0x01
#define UIFSTAT_UNR_CMD 0x02

#define UIFSTAT_INV_MSG 0x7e
#define UIFSTAT_MSG_TOO_LONG 0x7f
#define UIFSTAT_CMD_NOACK 0xff

#define UIFTAG_UUID 0xfff8
#define UIFTAG_END 0xffff

// Reset a UIF port
void uif_reset(short portaddr);
// Read a byte from a UIF port
char uif_read_byte(short portaddr);
// Swap endianness of a UIF tag and write it to a UIF port
void uif_write_tag(short portaddr, short tag);
// Write a UUID to a UIF port
void uif_write_uuid(short portaddr, char *uuid);
// Write a string to a UIF port
void uif_write_string(short portaddr, char *str);

// Read a string from a UIF port
void uif_read_string(short portaddr, char *buff);

#endif
