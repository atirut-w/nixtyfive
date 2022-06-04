#include "peekpoke.h"
#include "terminal.h"
#include "uif.h"
// #include <stdlib.h>

int main() {
    print("\7"); // Beep
    
    print("Resetting UIF component port... ");
    uif_reset_port2();
    print("done.\r");

    print("\rOk!\r");
    return 0;
}
