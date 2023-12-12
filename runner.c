#include <stdint.h>

enum ConsumeMode{
	INSTRUCTION,
	OPERAND1,
	OPERAND2
};

void TokenizeInstruction(char* input, char* instruction, char* operand1, char* operand2) {
    char* token = strtok(input, " ,");

    if (token != NULL) {
        strcpy(instruction, token);

        token = strtok(NULL, " ,");
        if (token != NULL) {
            strcpy(operand1, token);

            token = strtok(NULL, " ,");
            if (token != NULL) {
                strcpy(operand2, token);
            } else {
                operand2[0] = '\0';                           }
        } else {
            operand1[0] = '\0';
        }
    }
}

void CommandExecute(char* command){
	char instruction[8] = {0};
	char operand1[24] = {0};
	char operand1[256] = {0};
	TokenizeInstruction(command, instruction, operand1, operand2);
	if (strlen(instruction) == 0) ExitInvalidSyntax();
}
