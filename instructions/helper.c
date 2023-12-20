#include <stdint.h>
#include <ctypes.h>
#include <string.h>
#include "define.h"

int32_t IsString(char* str){
	uint32_t len = strlen(str);
	uint32_t offset = 0;
	while(isdigit(*str++)) offset++;
	if (offset + 1 != len) return 1;
	return 0;
}
void InitPointer(struct Pointer* ptr){
	ptr->mode = 0;
	ptr->instantv = 0;
}

uint32_t GetPointer(struct CPU* cpu, char* operand, struct Pointer* ptr){
	InitPointer(ptr);
	int16_t mode = DefineSingleMode(operand);
	switch(mode){
		case EAX:
			ptr->ptr = &(cpu->eax);
			ptr->mode = BITS32;
			break;
		case EBX:
			ptr->ptr = &(cpu->ebx);
			ptr->mode = BITS32;
			break;
		case ECX:
			ptr->ptr = &(cpu->ecx);
			ptr->mode = BITS32;
			break;
		case EDX:
			ptr->ptr = &(cpu->edx);
			ptr->mode = BITS32;
			break;
		case ESP:
			ptr->ptr = &(cpu->esp);
			ptr->mode = BITS32;
			break;
		case EBP:
			ptr->ptr = &(cpu->ebp);
			ptr->mode = BITS32;
			break;
		case ESI:
			ptr->ptr = &(cpu->esi);
                        ptr->mode = BITS32;
                        break;
		case EDI:
			ptr->ptr = &(cpu->edi);
                        ptr->mode = BITS32;
                        break;
		case AX:
			ptr->ptr = cpu->ax;
			ptr->mode = BITS16;
			break;
		case BX:
                        ptr->ptr = cpu->bx;
                        ptr->mode = BITS16;
                        break;
		case CX:
                        ptr->ptr = cpu->cx;
                        ptr->mode = BITS16;
                        break;
		case DX:
                        ptr->ptr = cpu->dx;
                        ptr->mode = BITS16;
                        break;
		case AH:
			ptr->ptr = cpu->ah;
			ptr->mode = BITS8;
			break;
		case BH:                                                  ptr->ptr = cpu->bh;
                        ptr->mode = BITS8;
                        break;
		case CH:                                                  ptr->ptr = cpu->ch;
                        ptr->mode = BITS8;
                        break;
		case DH:                                                  ptr->ptr = cpu->dh;
                        ptr->mode = BITS8;
                        break;
		case AL:                                                  ptr->ptr = cpu->al;
                        ptr->mode = BITS8;
                        break;
		case BL:                                                  ptr->ptr = cpu->bl;
                        ptr->mode = BITS8;
                        break;
		case CL:                                                  ptr->ptr = cpu->cl;
                        ptr->mode = BITS8;
                        break;
		case DL:                                                  ptr->ptr = cpu->dl;
                        ptr->mode = BITS8;
                        break;
		case INT:
			if (IsString(++operand)) return 0;
			ptr->instantv = atoi(operand);
                        ptr->mode = INT;
                        break;
		case MEMVAL:
			operand += 2;
			if (IsString(operand)) return 0;
			ptr->instantv = atoi(operand);
			ptr->mode = MEMVAL;
			break;
		case MEMADDR:
			operand += 2;
			if (IsString(++operand)) return 0;
			ptr->instantv = atoi(operand);
			ptr->mode = MEMADDR;
			break;
		default:
			return 0;
	}
	return 1;
}

int32_t AreInvalid(struct Pointer *ptr1, struct Pointer *ptr2){
	if (ptr1->mode == BITS16 && ptr2->mode == INT && ptr2->instantv > 65535) return OUTOFRANGE;
	if (ptr1->mode == BITS8 && ptr2->mode == INT && ptr2->instantv > 127) return OUTOFRANGE;
	if (ptr1->mode == BITS16 || ptr1->mode == BITS8 && ptr2->mode == MEMADDR) return NOTCOMPARABLESIZES;
	if (ptr->mode == INT || ptr1->mode == MEMVAL && ptr2->mode == MEMADDR) return NOTTARGETABLECONSTANT;
	return 0;
}
