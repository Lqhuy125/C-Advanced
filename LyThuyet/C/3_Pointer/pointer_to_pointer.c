#include <stdio.h>

int main()
{
    int a = 10;
    int *ptr = &a;
    int **ptp = &ptr;

    printf("Addr of a: %p\n", &a);
    printf("Addr_ptr: %p Val_ptr: %p Val_var_ptr: %d\n", &ptr, ptr, *ptr);

    printf("Addr_ptr: %p Val_ptr: %p Val_var_ptr: %d", &ptp, ptp, **ptp);
    return 0;
}
