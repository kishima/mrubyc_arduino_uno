#ifndef MRBC_SRC_HAL_H_
#define MRBC_SRC_HAL_H_

#define SERIAL_FOR_STDIO_BAUDRATE 9600

void hal_init();
void hal_delay(int msec);
int hal_write(int fd, const void *buf, int nbytes);
inline static int hal_flush(int fd) { return 0; }
void hal_write_string(char* text);

#endif // ifndef MRBC_HAL_H_
