MEMORY {
    /* ram (w) : ORIGIN = 0x3000, LENGTH = 0xd000
    rom (r) : ORIGIN = 0xf000, LENGTH = 0x0ffc */
    code (r) : ORIGIN = 0x1000, LENGTH = 0x1000
    ram (w) : ORIGIN = 0x2000, LENGTH = 0x1000
}

SECTIONS {
    INCLUDE c.ld
}

__rc0 = 0x05;
INCLUDE imag-regs.ld
__stack = 0x2fff;

OUTPUT_FORMAT {
    TRIM(code)
    SHORT(_start)
}
