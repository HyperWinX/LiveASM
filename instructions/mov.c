#include <stdint.h>
#include "define.h"

struct Pointer{
	void* ptr;
	int16_t mode;
}

void* SetPointer(struct CPU* cpu, char* operand){
	switch
}

int ExecuteMOV(struct CPU* cpu, char* operand1, char* operand2){
	switch (DefineMode(operand1, operand2)){
		
	}
}
