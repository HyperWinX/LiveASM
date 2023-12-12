#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void ExitInvalidSyntax(){
	fprintf(stderr, ANSI_COLOR_RED "Invalid syntax! Tokenizer failed." ANSI_COLOR_RESET);
	exit(1);
}
