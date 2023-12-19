#include <stdint.h>
#include "define.h"

struct Pointer{
	void* ptr;
	int16_t mode;
}

void InitPointer(struct Pointer* ptr){
	ptr->mode = 0;
}

void GetPointer(struct CPU* cpu, char* operand, struct Pointer* ptr){
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
	}
}

int ExecuteMOV(struct CPU* cpu, char* operand1, char* operand2){
	struct Pointer ptr;
	GetPointer
	switch (DefineMode(operand1, operand2)){
		
	}
}
