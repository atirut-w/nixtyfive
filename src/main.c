#define POKE(addr, val) *(volatile unsigned char *)(addr) = (val)

void print(const char *str) {
    while (*str) {
        POKE(0x02ff, *str++);
    }
}

void main() {
    print("Hello, world!\n");
    // __asm__("brk");
}
