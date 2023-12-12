#include <stdio.h>
#include <stdlib.h>

#define STANDARD_MEMSIZE 65536

int main(int argc, char* argv[]){
	FILE* fd = fopen(".liveasm", "r");
	if (!fd){
		printf("[WARNING]: cannot open config file, continuing with default settings");
	}
	else parse_config(fd);
}
