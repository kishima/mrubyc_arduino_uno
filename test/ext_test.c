#include <stdio.h>
#include <unistd.h>
// ext dummy for mmruby

void ext_led(int n) {
	printf("led %d\n", n);
}
void ext_wait(int n) {
	printf("wait %d\n", n);
	usleep(n * 1000000 / 60);
}
int ext_btn() {
	return 0;
}
void ext_out(int n, int m) {
	printf("out %d, %d\n", n, m);
}
//
void ext_init() {
}
