#include "peekpoke.h"
#include "terminal.h"
#include "uif.h"
#include "component.h"
#include <string.h>
// #include <stdlib.h>

int main() {
    print("\7"); // Beep
    uif_reset_port2();
    print("UIF component port reset\r");

    component_data_t data;
    complist_start();
    read_component(&data);

    for (int i = 0; i < 16; i++) {
        if (memcmp("eeprom", data.name, 6) == 0) {
            print("Found eeprom component\r");

            uif_write_tag(UIF_PORT2, UIFTAG_UUID);
            uif_write_uuid(UIF_PORT2, data.uuid);
            uif_write_string(UIF_PORT2, "getChecksum");
            uif_write_tag(UIF_PORT2, UIFTAG_END);

            print("Response status: ");
            printbyte(*UIF_PORT2);
            print("\rResponse tag: ");
            printshort(uif_read_tag(UIF_PORT2));

            char buffer[32];
            uif_read_string(UIF_PORT2, buffer);
            print("\rChecksum: ");
            print(buffer);

            break;
        }
    }

    print("\rOk!\r");
    return 0;
}
