#include <stdint.h>
#include <stdlib.h>

struct config{
	uint64_t memsize;
}

struct config* parse_config(FILE* fd){
	int key_inprocess = 1, key_offset = 0;
	int val_inprocess = 0, val_offset = 0;
	fseek(fd, 0L, SEEK_END);
	uint64_t fsize = ftell(fd);
	rewind(fd);
	char buff[fsize];
	fread(&buff, sizeof(char), fsize, fd);
	char key[32];
	memset(&key, (char)0, sizeof(key));
	for (uint64_t i = 0; i < fsize; i++){
		if (buff[i] != '=' && key_inprocess = 1)
			key[key_offset++] = buff[i];
	}
}
