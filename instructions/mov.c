#include <stdint.h>
#include "define.h"
#include "helper.h"
#include "../errors.h"

int ExecuteMOV(struct CPU* cpu, char* operand1, char* operand2){
	struct Pointer op1ptr, op2ptr;
	if (GetPointer(cpu, operand1, &op1ptr) ||
	    GetPointer(cpu, operand2, &op2ptr) return POINTERCREATIONFAILURE;
	int retcode = 0;
	if ((retcode = AreInvalid(&op1ptr, &op2ptr)) != 0) HandleError(retcode);
	
}
