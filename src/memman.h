#ifndef __MEMMAN_H
#define __MEMMAN_H

// 16 * 64 = 1024byte
#define MM_BLOCK 16
#define MM_N_MEM 64

void memman_init();
void* malloc(int size);
void* realloc(void* p, int size);
void free(void* p);

#endif
