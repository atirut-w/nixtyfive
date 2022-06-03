MEMORY {
    /* ram (w) : ORIGIN = 0x3000, LENGTH = 0xd000
    rom (r) : ORIGIN = 0xf000, LENGTH = 0x0ffc */
    ram (rw) : ORIGIN = 0x1000, LENGTH = 0xe000
}

SECTIONS {
    INCLUDE c.ld
}

__rc0 = 0x05;
INCLUDE imag-regs.ld
__stack = 0x2fff;

OUTPUT_FORMAT {
    TRIM(ram)
    SHORT(_start)
}
