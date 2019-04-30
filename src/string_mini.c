#include "typedef.h"

int strlen(const char* s) {
	int n = 0;
	while (*s++)
		n++;
	return n;
}
void strcpy(char* buf, const char* src) {
	while (*buf++ = *src++);
}
int strcmp(const char* buf1, const char* buf2) {
	for (;;) {
		int n = *buf1++;
	    int c = n - *buf2++;
	    if (c)
	      return c;
		if (!n)
			return 0;
	}
}
int strspn(const char* s1, const char *s2) {
	for (int i = 0;; i++) {
		if (s1[i] != s2[i])
			return i;
	}
}
char* strcat(char* s1, const char* s2) {
	char* s = s1;
	while (*s++);
	while (*s++ = *s2++);
	return s1;
}
int atol(const char* s) {
	int flg = 0;
	if (*s == '-') {
		flg = 1;
		s++;
	}
	int n = 0;
	for (;;) {
		int c = *s++;
		if (c < '0' || c > '9') {
			break;
		}
		n = n * 10 + (c - '0');
	}
	return flg ? -n : n;
}

int memcmp(const uint8_t* buf1, const uint8_t* buf2, int len) {
  for (int i = 0; i < len; i++) {
    int c = buf1[i] - buf2[i];
    if (c)
      return c;
  }
  return 0;
}
void memmove(void* buf1, const void* buf2, int len) {
	for (int i = 0; i < len; i++) {
		*(char*)buf1++ = *(char*)buf2++;
	}
}
void memset(void* p, uint8_t ch, int len) {
	for (int i = len; i > 0; i--)
		*(char*)p++ = ch;
}
