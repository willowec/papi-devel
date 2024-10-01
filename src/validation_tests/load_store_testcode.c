#include "testcode.h"

/* Execute 786,433 stores.                                  */
/* The number is chosen for backwards compatibility with    */
/* naive_matrix_multiply_estimated_stores()                 */
int execute_stores() {

	int *dummy = malloc(sizeof(int));

#if defined(__arm__)

	__asm(  "mov x2, #1\n"
		    "str x2, [%0]\n"
		    : "=r" (dummy)
		    :
		    : "cc" /* clobbered */
	);

	printf("%d\n", *dummy);

    free(dummy);
	return 0;

#endif
    free(dummy);
	return CODE_UNIMPLEMENTED;

}