#ifndef __TYPEDEF_H_
#define __TYPEDEF_H_

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;

#ifndef NULL

#ifndef USE_STDIO
typedef uint32_t uintptr_t;
#endif

#define NULL 0

#endif

#ifndef NO_VA

typedef char* va_list;
#define __va_size(x)  ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap,last) (ap = (va_list)((char *)(&last) + __va_size(last)))
#define va_arg(ap, type) (*(type *)((ap += __va_size(type)) - (__va_size(type))))
#define va_end(ap) ((void)0)

#endif

#define assert

#endif
