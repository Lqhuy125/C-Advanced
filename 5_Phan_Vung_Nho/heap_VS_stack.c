#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//luu tai Stack
void test1(){
    int array[5];
    printf("Address of test1: %p\n", array);
}

//Luu tai head
void test2(){
    char *array = (char*)malloc(sizeof(char)*5);
    printf("Address of test2: %p\n", array);
}
int main(int argc, char const *argv[])
{
    test1(); //Sau khi ket thuc ham thi se tu dong thu hoi vung nho
    test1(); //van se co the duoc su dung vung nho o tren
    printf("----------\n");
    test2(); // van se giu nguyen vung nho dang duoc su dung
    test2(); // neu goi lai se su dung vung nho khac
    // De thu hoi: su dung free(array);
    return 0;
}
