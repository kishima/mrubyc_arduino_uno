gcc -DSHOW_OPCODE -DCHECK_MEM_USAGE -DUSE_STDIO -DMMRUBY_DEBUG_ENABLE -I ../src/ mmruby_test.c  ../src/alloc.c ../src/c_object.c ../src/debug.c ../src/hal.c ../src/value.c ../src/avr_access.c ../src/c_string.c ../src/vm.c ../src/c_common.c ../src/class.c ../src/c_fixnum.c ../src/console.c ../src/global.c ../src/symbol.c ../src/memman.c ../src/string_mini.c ext_test.c -DNO_VA -o mmruby_test
if [ $? -ne 0 ]; then
	exit 1
fi
./mmruby_test

