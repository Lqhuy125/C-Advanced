#include <stdio.h>
#include <stdarg.h>

int findMin(int num, ...){
    int tmp = 0, min;

    va_list va;                     //va_list is a type to hold information about variable argument
    
    va_start(va, num);              //va_start must be called before accessing variable argument list

    min = va_arg(va, int);          //Now arguments can be accessed one by one
                                    //Here, va_arg is accessed first argument in list


    for (int i = 1; i < num; i++)               //do something with va_arg()
        if( (tmp = va_arg(va, int)) < min)
            min = tmp;
    
    va_end(va);                     //va_end should be executed before the function returns

    return min;

}

int main(int argc, char const *argv[])
{
    printf("Min in list: %d\n", findMin(5, 4, 67, 6, 7, 1));
    return 0;
}
