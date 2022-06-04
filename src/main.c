#include "peekpoke.h"
#include "terminal.h"
#include "component.h"
// #include <stdlib.h>

int main() {
    POKE(0x2ff, 7);
    print("Hello, world!\r");

    print("Slot UUID\r");
    print("---------------------------\r");

    component_data_t component;
    reset_component_list_cursor();
    read_component(&component);

    for (int i = 0; component.name[0] != 0xff; i++) {
        print("$");
        printbyte(i);
        print("  ");
        printuuid(component.uuid);
        print(" ");
        print(component.name);

        print("\r");
        next_component();
        read_component(&component);
    }

    print("\rOk!\r");
    return 0;
}
