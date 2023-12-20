#include <stdint.h>

int32_t IsString(char* str);

struct Pointer{
	void* ptr;
	int16_t mode;
	int32_t instantv;
};