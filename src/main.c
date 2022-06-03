#include "peekpoke.h"
#include "terminal.h"
#include "uif.h"
#include <string.h>

extern char boot_uuid[16];
char strbuffer[32];

void main() {
    uif_reset(UIF_PORT2);
    print("UIF port 2 reset\r");

    print("Send `getLabel()` to ");
    printuuid(boot_uuid);
    print("\r");

    uif_write_tag(UIF_PORT2, UIFTAG_UUID);
    uif_write_uuid(UIF_PORT2, boot_uuid);
    uif_write_string(UIF_PORT2, "getLabel");
    uif_write_tag(UIF_PORT2, UIFTAG_END);

    print("Response tag: ");
    printbyte(uif_read_byte(UIF_PORT2));
    print("\rResponse: ");
    uif_read_string(UIF_PORT2, strbuffer);
    print(strbuffer);
    print("\r");

    print("\rOk!\r");
}
