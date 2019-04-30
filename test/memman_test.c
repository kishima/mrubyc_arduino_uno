#include <stdio.h>
#include "memman.h"

void t(int no, int b) {
	printf("test %3d : %s\n", no, b ? "ok" : "NG!!!");
}

/*
#define MM_BLOCK 16
#define MM_N_MEM 64
*/

int main() {
	memman_init();

	char* p[MM_N_MEM];
	for (int i = 0; i < MM_N_MEM; i++) {
		p[i] = memman_malloc(10);
		t(i, p[i] != NULL);
		p[i][0] = i;
	}
	t(90, memman_malloc(10) == NULL);
	for (int i = 0; i < MM_N_MEM; i++) {
		t(i + 100, p[i][0] == i);
	}
	memman_free(p[3]);
	memman_free(p[10]);
	p[10] = memman_malloc(12);
	t(91, p[10] != NULL);
	p[3] = memman_malloc(16);
	t(92, p[3] != NULL);

	t(93, memman_realloc(p[0], MM_BLOCK * 2) == NULL);
	p[0] = memman_realloc(p[0], MM_BLOCK);
	t(94, p[0] != NULL);

	for (int i = 0; i < MM_N_MEM; i++) {
		memman_free(p[i]);
	}



	return 0;
}

