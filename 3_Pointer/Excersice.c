#include <stdio.h>

void tong(int a, int b){
    printf("Sum = %d\n", a+b);
}
void fun(int a)
{
    printf("Value of a is %d\n", a);
}
int main()
{

    int a = 10;
    
    double b = 12.2;

    void *array[] = {&a, &b, &tong};

    printf("%d\n", *(int *)array[0]);
    
    printf("%f\n", *(double *)array[1]);

    ((void (*)(int, int))array[2])(a,(int)b);

    ((void (*)(int))fun)(10);
    
    return 0;
}
