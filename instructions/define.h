#include <stdint.h>



int32_t DefineMode(char* operand1, char* operand2){
	int32_t mode = 0;
	if (strcmp(operand1, "eax") == 0) mode = 0x0001;
	else if (strcmp(operand1, "ebx") == 0) mode = 0x0002;
	else if (strcmp(operand1, "ecx") == 0) mode = 0x0003;
	else if (strcmp(operand1, "edx") == 0) mode = 0x0004;
	else if (strcmp(operand1, "esp") == 0) mode = 0x0005;
	else if (strcmp(operand1, "ebp") == 0) mode = 0x0006;
	else if (strcmp(operand1, "esi") == 0) mode = 0x0007;
	else if (strcmp(operand1, "edi") == 0) mode = 0x0008;
	else if (strcmp(operand1, "ax") == 0) mode = 0x0009;
	else if (strcmp(operand1, "bx") == 0) mode = 0x000A;
	else if (strcmp(operand1, "cx") == 0) mode = 0x000B;
}
