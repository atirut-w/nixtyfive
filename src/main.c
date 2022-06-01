#include "peekpoke.h"
#include "terminal.h"
#include "component.h"

void main() {
    component_data_t data;
    char i;

    print("Hello, world!\r\r");

    reset_component_list_cursor();
    read_component(&data);
    for (i = 0; data.name[0] != 0xff; i++) {
        print("Component ");
        printbyte(i);
        print(": ");
        print(data.name);
        print("\r");

        next_component();
        read_component(&data);
    }

    print("\rOk!\r");
}
