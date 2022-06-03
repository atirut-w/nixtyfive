#include "peekpoke.h"
#include "terminal.h"
#include "uif.h"
#include <string.h>

extern char boot_uuid[16];
char strbuffer[32];

void main() {
    print("Hello, world!\r");

    print("\rOk!\r");
}
