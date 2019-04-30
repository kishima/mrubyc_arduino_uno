#ifndef __STRING_MINI_H_
#define __STRING_MINI_H_

#ifndef USE_STDLIB

#include "typedef.h"

#define strlen __strlen
#define strcpy __strcpy
#define strcmp __strcmp
#define strspn __strspn
#define strcat __strcat
#define atol __atol

#define memcmp __memcmp
#define memset __memset
#define memmove __memmove

int strlen(const char* s);
void strcpy(char* buf, const char* src);
int strcmp(const char* buf1, const char* buf2);
int strspn(const char* s1, const char *s2);
char* strcat(char* s1, const char* s2);
int atol(const char* s);

int memcmp(const uint8_t* buf1, const uint8_t* buf2, int n);
void memset(void* p, uint8_t ch, int len);
void memmove(void* buf1, const void* buf2, int len);
#define memcpy memmove

#endif

#endif
