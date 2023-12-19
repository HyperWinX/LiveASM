#ifndef DEFINE_H
#define DEFINE_H
#include <stdint.h>

#define EAX 0x0001                                #define EBX 0x0002
#define ECX 0x0003
#define EDX 0x0004
#define ESP 0x0005
#define EBP 0x0006
#define ESI 0x0007
#define EDI 0x0008
#define AX 0x0009
#define BX 0x000A
#define CX 0x000B
#define DX 0x000C
#define AH 0x000D
#define BH 0x000E
#define CH 0x000F
#define DH 0x0010
#define AL 0x0011
#define BL 0x0012
#define CL 0x0013
#define DL 0x0014
#define INT 0x0015
#define HEX 0x0016
#define MEMADDR 0x0017
#define MEMVAL 0x0018
#define INVALID 0xFFFF

int32_t DefineMode(char* operand1, char* operand2);
#endif
