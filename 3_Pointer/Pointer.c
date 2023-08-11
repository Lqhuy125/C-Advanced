#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;

    int * ptr = &a;

    printf("Address of a: %p\n", &a);

    printf("Address of pointer: %p\n", &ptr);
    printf("Value of pointer: %p\n", ptr);
    printf("Value of variable pointer: %d\n", *ptr);

    return 0;
}
