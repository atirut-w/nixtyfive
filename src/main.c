#include "peekpoke.h"
#include "terminal.h"
#include "component.h"

extern char boot_uuid[16];
component_data_t components[16];

void main() {
    char i;

    print("Listing components...\r");

    reset_component_list_cursor();
    for (i = 0; i < 16; i++) {
        read_component(&components[i]);
        next_component();
    }

    print("Slot UUID                              Name\r");
    print("-------------------------------------------\r");

    for (i = 0; components[i].name[0] != 0xff; i++) {
        printbyte(i);
        print("   ");
        printuuid(components[i].uuid);
        print("  ");
        print(components[i].name);
        print("\r");
    }

    print("\rBooted from ");
    printuuid(boot_uuid);
    print("\r");

    print("\rOk!\r");
}
