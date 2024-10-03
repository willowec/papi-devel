#include "testcode.h"

/* Execute n stores */
int execute_stores(int n) {

#if defined(__aarch64__)

	__asm(  ".data\n"
            "stvar: .word 1 /* stvar in memory */\n"
            ".text\n"
            "   ldr x2, =stvar\n"
            "   mov x1, #0\n"
            "str_loop:"
		    "   str x1, [x2]\n"
            "   add x1, x1, #1\n"
            "   cmp x1, [n]\n"
            "   bne str_loop\n"
		    :
		    : [n] "r" (n)
		    : "cc" /* clobbered */
	);

	return 0;

#endif
	return CODE_UNIMPLEMENTED;

}

/* Execute n loads */
int execute_loads(int n) {

#if defined(__aarch64__)

	__asm(  ".data\n"
            "ldvar: .word 1 /* ldvar in memory */\n"
            ".text\n"
            "   ldr x2, =ldvar\n"
            "   mov x1, #0\n"
            "ldr_loop:"
		    "   ldr x3, [x2]\n"
            "   add x1, x1, x3\n"
            "   cmp x1, [n]\n"
            "   bne ldr_loop\n"
		    :
		    : [n] "r" (n)
		    : "cc" /* clobbered */
	);

	return 0;

#endif
	return CODE_UNIMPLEMENTED;

}