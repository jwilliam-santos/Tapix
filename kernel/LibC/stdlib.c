#include "stdlib.h"
#include "stdbool.h"
struct header {
    size_t size;
    bool livre;
};

extern char kernel_end;
char* itoa(unsigned long num){
    char it[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    static char buffer[17];
    int i = 15;
    buffer[16] = '\0';
    
    while(num > 0){
        buffer[i] = it[num % 16];
        num = num / 16;
        i--;
    }
    
    return &buffer[i + 1];
}

static char* heap = (char*)&kernel_end;
void* malloc(size_t size){
    void* endereco = heap;
    heap += sizeof(struct header) + size;
    return endereco;
}
void* calloc(size_t nmemb, size_t size){
    if(size == 0) return NULL;
    void* endereco = heap;
    heap += nmemb * size;
    char* bytes = (char*)endereco;
    for(size_t i=0;i < nmemb*size; i++){
        bytes[i] = 0;
    } 
    return endereco;
}
void free(void* ptr){
    if (ptr == NULL) {
        return;
    }
    struct header* h = (struct header*)ptr - 1;
    h->livre = 1;
}
// void* realloc(void* ptr, size_t size){
//     if(ptr == NULL){
//         return malloc(size);
//     }
//     if(ptr == 0){
//         free(ptr);
//         return NULL;
//     }
    
// }