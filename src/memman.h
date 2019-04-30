#ifndef __MEMMAN_H
#define __MEMMAN_H

// 16 * 64 = 1024byte
#define MM_BLOCK 128
#define MM_N_MEM 16

void memman_init();
void* memman_malloc(int size);
void* memman_realloc(void* p, int size);
void memman_free(void* p);

#endif
