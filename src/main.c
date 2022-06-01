#include "peekpoke.h"
#include "terminal.h"
#include "uif.h"
#include <string.h>

extern char boot_uuid[16];

void main() {
    uif_reset(UIF_PORT1);
    print("UIF port 1 reset\r");

    print("Send `getLabel()` to \r");
    printuuid(boot_uuid);
    print("\r");
    uif_write_tag(UIF_PORT1, UIFTAG_UUID);
    uif_write_uuid(UIF_PORT1, boot_uuid);
    uif_write_string(UIF_PORT1, "getLabel");

    print("Response tag: ");
    printbyte(uif_read_byte(UIF_PORT1));

    print("\rOk!\r");
}
