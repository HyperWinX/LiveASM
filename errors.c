#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include "instructions/define.h"

void ExitInvalidSyntax(void){
	fprintf(stderr, ANSI_COLOR_RED "Invalid syntax! Tokenizer failed." ANSI_COLOR_RESET);
	exit(1);
}
void ExitIllegalInstruction(void){
	fprintf(stderr, ANSI_COLOR_RED "Illegal instruction! Execution terminated." ANSI_COLOR_RESET);
	exit(1);
}

void HandleError(int code){
	
}
