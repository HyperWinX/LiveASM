#include <stdint.h>
#include <string.h>
#include <stdio.h>

regs_t regs = {0};

enum InstructionType
	UNKNOWN_INSTR,
	MOV
};

union Registers{
	uint64_t rax;
        struct {
		uint32_t eax;
		uint16_t ax;
		uint8_t al;                                       uint8_t ah;
        };
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

void CommandExecute(char* command){
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
