#include <stdio.h>
#include "string_mini.h"
//#include <string.h>

void t(int no, int b) {
	printf("test %3d : %s\n", no, b ? "ok" : "NG!!!");
}

int main() {
	char buf1[] = "abc";
	char buf2[] = "abc";
	char buf3[] = "abcd";
	char buf4[] = "ABC";
	char buf5[] = "abcABC";
	char dest1[100];

	//int strcmp(const char* buf1, const char* buf2);
	t(1, strcmp(buf1, buf2) == 0);
	t(2, strcmp(buf1, buf3) < 0);
	t(3, strcmp(buf3, buf1) > 0);

	//int memcmp(const uint8_t* buf1, const uint8_t* buf2, int n);
	t(4, memcmp(buf1, buf2, 3) == 0);
	t(5, memcmp(buf1, buf3, 4) != 0);

	// void strcpy(char* buf, const char* src);
	strcpy(dest1, buf1);
	t(6, strcmp(dest1, buf1) == 0);

	//char* strcat(char* s1, const char* s2);
	strcat(dest1, buf4);
	t(7, strcmp(dest1, buf5) == 0);

	//void memset(void* p, uint8_t ch, int len);
	memset(dest1, 'a', 4);
	t(8, memcmp(dest1, "aaaa", 4) == 0);

	//int strlen(const char* s);
	t(9, strlen(buf1) == 3);
	dest1[0] = 0;
	t(10, strlen(dest1) == 0);

	// int strspn(const char* s1, const char *s2);
	t(11, strspn(buf3, buf1) == 3);
	t(12, strspn(buf4, buf1) == 0);

	//void memmove(void* buf1, const void* buf2, int len);
	strcpy(dest1, "0123456");
	memmove(dest1, dest1 + 3, 3);
	t(13, strcmp(dest1, "3453456") == 0);

	//int atol(const char* s);
	t(14, atol("30") == 30);
	t(15, atol("-1") == -1);
	t(16, atol("a") == 0);
	t(17, atol("") == 0);
	t(18, atol("40404040") == 40404040);
	t(19, atol("+5") == 5);

	return 0;
}

