#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

// Information about a block of memory.
typedef struct {
    short size; // Size of the block including this header.
    char used;  // Whether the block is in use.
} memory_block_t;

void *kmalloc(short size); // Allocate a block of memory.
void kfree(void *ptr); // Free a block of memory.

#endif
