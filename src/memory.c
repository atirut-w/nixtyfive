#include "memory.h"
#include "peekpoke.h"

short get_highest_bank() {
    return PEEK(0x200) + (PEEK(0x210) << 8);
}
