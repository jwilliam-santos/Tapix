#ifndef STDLIB_H
#define STDLIB_H
typedef unsigned long long size_t;
#define NULL ((void*)0)
void* calloc(size_t nmemb, size_t size);
void  free(void* ptr);
void* malloc(size_t size);
void* realloc(void* ptr, size_t size);//feito posteriomente
char* itoa(unsigned long num);
int abs(int j);

#endif