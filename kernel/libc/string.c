#include <string.h>
void* memset(void* dest, int val, size_t count) {

}

void* memcpy(void* dest, const void* src, size_t count) {

}

void* memmove(void* dest, const void* src, size_t count){

}

int memcmp(const void* a, const void* b, size_t count) {

}

size_t strlen(const char* s) {

}

int  strcmp(const char* a, const char* b) {

}
int    strncmp(const char* a, const char* b, size_t n) {

}

char* strcpy(char* dest, const char* src) {
	/*
	Get an array and copy this array to dest 
	*/
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

char* strncpy(char* dest, const char* src, size_t n) {

}

char* strcat(char* dest, const char* src) {

}



