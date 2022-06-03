#ifndef PEEKPOKE_H_INCLUDED
#define PEEKPOKE_H_INCLUDED

#define PEEK(addr) (*(volatile unsigned char *)(addr))
#define POKE(addr, data) (*(volatile unsigned char *)(addr) = (data))

#endif
