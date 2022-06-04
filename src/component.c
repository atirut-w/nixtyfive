#include "component.h"
#include "peekpoke.h"

void reset_component_list_cursor() {
    POKE(0x246, 0xff);
}

void read_component(component_data_t *data) {
    for (int i = 0; i < 16; i++) {
        data->name[i] = PEEK(0x246);
        if (data->name[i] == 0) {
            break;
        } else if (data->name[i] == 0xff) {
            return;
        }
    }

    for (int i = 0; i < 16; i++) {
        data->uuid[i] = PEEK(0x246);
    }
}

void next_component() {
    POKE(0x246, 0);
}
