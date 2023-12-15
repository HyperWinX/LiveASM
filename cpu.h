#include <stdint.h>

struct CPU{
	uint32_t eax;
	uint16_t* ax;
	uint8_t* al;
	uint8_t* ah;

	uint32_t ebx;
        uint16_t* bx;
	uint8_t* bl;
        uint8_t* bh;

	uint32_t ecx;
        uint16_t* cx;
	uint8_t* cl;
        uint8_t* ch;

	uint32_t edx;
        uint16_t* dx;
	uint8_t* dl;
	uint8_t* dh;

	uint32_t esp;
	uint32_t ebp;
	uint32_t esi;
	uint32_t edi;
};
