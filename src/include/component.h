#pragma once

// Information about a component
typedef struct {
    char name[16]; // The name of the component
    char uuid[16]; // The uuid of the component
} component_data_t;

// Reset the cursor of the component list port.
void reset_component_list_cursor();
// Read component data from the component list port.
void read_component(component_data_t *data);
// Go to the next component in the component list port.
void next_component();
