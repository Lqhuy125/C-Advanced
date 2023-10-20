#include <stdio.h>
#include <stdarg.h>

void sum(int count, ...)
{
    int res_int = 0;
    double res_db = 0.0;

    va_list ptr_int,ptr_db;

    va_start(ptr_int, count);
    va_start(ptr_db, count);

    int val_int = 0;
    double val_db = 0.0;

    //chua xu ly duoc phan nay
    for (int i = 0; i < count; i++)
    {
        val_int = va_arg(ptr_int, int);
        printf("%d\t", val_int);
        //if(val_int<500000000 || val_int>-5000000000)
            res_int += val_int;
    }

    printf("\n----------------\n");
    //All value type int = 0
    for (int i = 0; i < count; i++)
    {
        val_db = va_arg(ptr_db, double);
        printf("%f\t", val_db);
        res_db += val_db;
    }

    va_end(ptr_int);
    va_end(ptr_db);
    printf("\n%f", res_db);
    printf("\n%d", res_int);
    double res = res_db + (double)res_int;
    printf("\n%f", res);
}
int main(){
    sum(3, 1, 2, 3.2);
}
