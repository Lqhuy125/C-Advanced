#include <stdio.h>

int main(int argc, char const *argv[])
{
    register int x = 10;

    printf("%p", &x);
    return 0;
}
