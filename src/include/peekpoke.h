#pragma once

#define PEEK(addr) (*(volatile unsigned char *)(addr))
#define POKE(addr, data) (*(volatile unsigned char *)(addr) = (data))
