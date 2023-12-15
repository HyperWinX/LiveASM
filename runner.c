#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "cpu.h"

uint8_t cpuInit = 0;
struct CPU* cpu;

enum InstructionType
	UNKNOWN_INSTR,
	MOV
};

void TokenizeInstruction(char* input, char* instruction, char* operand1, char* operand2) {
    char* token = strtok(input, " ,");
    if (token != NULL) {
        sprintf(instruction, 8, "%s", token);
        token = strtok(NULL, " ,");
        if (token != NULL) {
            snprintf(operand1, 24, "%s", token);
            token = strtok(NULL, " ,");
            if (token != NULL)
                snprintf(operand2, 256, "%s", token);
            else operand2[0] = '\0';           
        } else operand1[0] = '\0';
    }
}

enum InstructionType DefineInstruction(char* instruction){
	if (!strcmp(instruction, "mov"))
		return MOV;
	else
		return UNKNOWN_INSTR;
}

void ExecuteInstruction(enum InstructionType instructiontp, char* operand1, char* operand2){
	switch(instructiontp){
		case MOV:
			
			break;
		default:
			ExitIllegalInstr();
	}
}

void CommandExecute(char* command)
	if (!cpuInit) CPUInit();
	char instruction[8] = {0};
	char operand1[24] = {0};
	char operand1[256] = {0};
	TokenizeInstruction(command, instruction, operand1, operand2);
	if (strlen(instruction) == 0) ExitInvalidSyntax();
	enum InstructionType instructiontp;
	if ((instructiontp = DefineInstruction(instruction)) == UNKNOWN_INSTR)
		ExitIllegalInstr();
	ExecuteInstruction(instructiontp, operand1, operand2);

}

void CPUInit(void){
	cpu = (struct CPU*)calloc(sizeof(struct CPU), 1);
	if (!cpu)
		ExitCPUInitFailure();
	cpuInit = 1;
	cpu->ax = &cpu->eax;
	cpu->al = &cpu->eax;
	cpu->ah = cpu->al + 1;

	cpu->bx = &cpu->ebx;
	cpu->bl = &cpu->ebx;
	cpu->bh = cpu->bl + 1;

	cpu->cx = &cpu->ecx;
	cpu->cl = &cpu->ecx;
	cpu->ch = cpu->cl + 1;

	cpu->dx = &cpu->edx;
	cpu->dl = &cpu->edx;
	cpu->dh = cpu->dl + 1;
}
