#include <stdio.h>

int global_var = 10;

static int y = 100;
void fun(){

    static int x = 5;               //vd: x co dia chi 0x01

}

int main()
{
    printf("%d\n", global_var);         
    global_var = 9;                 // both Read/Write

    fun();                          // x -> 0x01

    //Sau khi ket thuc chuong trinh thi dia chi 0x01 tra lai cho RAM  
    return 0;
}
