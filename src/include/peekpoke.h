#ifndef PEEKPOKE_H_INCLUDED
#define PEEKPOKE_H_INCLUDED

#define PEEK(addr) (*(unsigned char *)(addr))
#define POKE(addr, data) (*(unsigned char *)(addr) = (data))

#endif
