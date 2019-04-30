#include "typedef.h"
#include "memman.h"

char mm_mem[MM_BLOCK * MM_N_MEM];
char mm_use[MM_N_MEM];

void memman_init() {
  for (int i = 0; i < MM_N_MEM; i++)
    mm_use[i] = 0;
}

void* memman_malloc(int size) {
  if (size <= MM_BLOCK) {
    for (int i = 0; i < MM_N_MEM; i++) {
      if (!mm_use[i]) {
        mm_use[i] = 1;
        return mm_mem + i * MM_BLOCK;
      }
    }
  }
  // out of memory
  return NULL;
}

void* memman_realloc(void* p, int size) {
  if (size > MM_BLOCK) {
    return NULL; // out of memory
  }
  return p;
}

void memman_free(void* p) {
  mm_use[((char*)p - mm_mem) / MM_BLOCK] = 0;
}
