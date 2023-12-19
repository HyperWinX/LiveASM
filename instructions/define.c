#include <stdint.h>
#include "define.h"

int16_t DefineSingleMode(char* operand){
	if (strcmp(operand, "eax") == 0) return 0x0001;
	else if (strcmp(operand, "ebx") == 0) return 0x0002;
	else if (strcmp(operand, "ecx") == 0) return 0x0003;
	else if (strcmp(operand, "edx") == 0) return 0x0004;
	else if (strcmp(operand, "esp") == 0) return 0x0005;
	else if (strcmp(operand, "ebp") == 0) return 0x0006;
	else if (strcmp(operand, "esi") == 0) return 0x0007;
	else if (strcmp(operand, "edi") == 0) return 0x0008;
	else if (strcmp(operand, "ax") == 0) return 0x0009;
	else if (strcmp(operand, "bx") == 0) return 0x000A;
	else if (strcmp(operand, "cx") == 0) return 0x000B;
	else if (strcmp(operand, "dx") == 0) return 0x000C;
	else if (strcmp(operand, "ah") == 0) return 0x000D;
        else if (strcmp(operand, "bh") == 0) return 0x000E;
	else if (strcmp(operand, "ch") == 0) return 0x000F;
	else if (strcmp(operand, "dh") == 0) return 0x0010;
	else if (strcmp(operand, "al") == 0) return 0x0011;
	else if (strcmp(operand, "bl") == 0) return 0x0012;
	else if (strcmp(operand, "cl") == 0) return 0x0013;
	else if (strcmp(operand, "dl") == 0) return 0x0014;
	else if (operand[0] == '#') return 0x0015;
	else if (operand[0] == '$') return 0x0016;
	else if (operand[0] == '%' &&
		 operand[1] == '#') return 0x0017;
	else if (operand[0] == '%' &&
		 operand[1] == '$') return 0x0018;
	else return 0xFFFF;
}

int32_t DefineMode(char* operand1, char* operand2){
	int32_t ret = 0;
	int16_t fmode =  Define(operand1), smode = Define(operand2);
	if (fmode == INVALID) return fmode;
	else if (smode == INVALID) return smode;
	ret = fmode;
	ret = (ret << 16) | smode;
	return ret;
}
