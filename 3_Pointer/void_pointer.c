#include <stdio.h>

int tong(int a, int b){
    return a+b;
}

int main(int argc, char const *argv[])
{
    void *ptr;

    int i = 10;

    double d = 1.1;

    char c = 'c';
    
    ptr = &i;
    printf("Dia chi: %p, Gia tri: %d\n", ptr, *(int *)ptr);

    ptr = &d;
    printf("Dia chi: %p, Gia tri: %f\n", ptr, *(double *)ptr);

    ptr = &c;
    printf("Dia chi: %p, Gia tri: %c\n", ptr, *(char *)ptr);

    ptr = &tong;

    printf("Dia chi: %p\n", ptr);
    printf("Gia tri: %d\n", ((int (*)(int, int))ptr)(1,2));

    return 0;
}
