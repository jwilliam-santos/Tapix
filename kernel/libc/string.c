#include <string.h>

/*credits to https://github.com/ignatmatei/mini-libc/blob/master/src/string/string.c */
char* strcpy(char* destination, const char* source)
{
	/* TODO: Implement strcpy(). */
	while (*source)
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = *source;
	return destination;
}

char* strncpy(char* destination, const char* source, size_t len)
{
	/* TODO: Implement strncpy(). */
	const char* p = source;
	unsigned int i = 0, j = 0;
	while (i < len) {
		*(destination + i) = *(p + j);
		i++;
		if (*(p + j))
			j++;
	}
	return destination;
}

char* strcat(char* destination, const char* source)
{
	/* TODO: Implement strcat(). */
	int length = strlen(destination);
	strcpy((destination + length), source);
	return destination;
}

char* strncat(char* destination, const char* source, size_t len)
{
	/* TODO: Implement strncat(). */
	int length = strlen(destination);
	strncpy((destination + length), source, len);
	return destination;
}

int strcmp(const char* str1, const char* str2)
{
	/* TODO: Implement strcmp(). */
	int i = 0;
	while (*(str1 + i) || *(str2 + i)) {
		if (*(str1 + i) != *(str2 + i))
			return(*(str1 + i) - *(str2)+i);
		i++;
	}
	if (!(str1 + i) && (str2 + i))
		return -1;
	if ((str1 + i) && !(str2 + i))
		return 1;
	return 0;
}

int strncmp(const char* str1, const char* str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	unsigned int i = 0;
	while (*(str1 + i) && *(str2 + i) && i < len) {
		if (*(str1 + i) != *(str2 + i))
			return(*(str1 + i) - *(str2)+i);
		i++;
	}
	return 0;
}

size_t strlen(const char* str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;
	return i;
}

char* strchr(const char* str, int c)
{
	/* TODO: Implement strchr(). */
	for (unsigned int i = 0; i < strlen(str); i++)
		if (*(str + i) == c)
			return str + i;
	return NULL;
}

char* strrchr(const char* str, int c)
{
	/* TODO: Implement strrchr(). */
	int poz = 0;
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (*(str + i) == c)
			poz = i;
	}
	if (poz)
		return str + poz;
	return NULL;
}

char* strstr(const char* haystack, const char* needle)
{
	/* TODO: Implement strstr(). */
	//credit : ChatGPT
	while (*haystack) {
		const char* h = haystack;
		const char* n = needle;

		while (*haystack && *n && *haystack == *n) {
			haystack++;
			n++;
		}

		if (!*n) {
			return (char*)h;  // Found a match, return a pointer to the start of the match.
		}

		haystack = h + 1;  // No match, increment the haystack pointer.
	}

	return NULL;
}

char* strrstr(const char* haystack, const char* needle)
{
	/* TODO: Implement strrstr(). */
	int haystack_len = strlen(haystack);
	int needle_len = strlen(needle);

	if (needle_len == 0) {
		return (char*)(haystack + haystack_len);
	}

	for (int i = haystack_len - needle_len; i >= 0; i--) {
		if (strncmp(haystack + i, needle, needle_len) == 0) {
			return (char*)(haystack + i);
		}
	}

	return NULL;
}

void* memcpy(void* destination, const void* source, size_t num)
{
	/* TODO: Implement memcpy(). */
	unsigned char* d = (unsigned char*)destination;
	const unsigned char* s = (const unsigned char*)source;

	for (size_t i = 0; i < num; i++) {
		d[i] = s[i];
	}
	return destination;
}

void* memmove(void* destination, const void* source, size_t num)
{
	/* TODO: Implement memmove(). */
	unsigned char* d = (unsigned char*)destination;
	const unsigned char* s = (const unsigned char*)source;
	if (s < d && s + num > d) {
		// Source and destination overlap, copy from end to start
		for (size_t i = num; i > 0; i--) {
			d[i - 1] = s[i - 1];
		}
	}
	else {
		// Source and destination don't overlap, copy from start to end
		for (size_t i = 0; i < num; i++) {
			d[i] = s[i];
		}
	}
	return destination;
}

int memcmp(const void* ptr1, const void* ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char* p1 = ptr1;
	const unsigned char* p2 = ptr2;

	for (size_t i = 0; i < num; i++) {
		if (p1[i] < p2[i]) {
			return -1;
		}
		else if (p1[i] > p2[i]) {
			return 1;
		}
	}

	return 0;
}

void* memset(void* source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char* s = source;
	for (; num; num--, s++) *s = value;
	return source;
}



