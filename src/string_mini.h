#ifndef __STRING_MINI_H_
#define __STRING_MINI_H_

#include "typedef.h"

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
