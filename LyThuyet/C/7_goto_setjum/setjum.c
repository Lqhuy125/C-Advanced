#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

/* void test1(){
    int key;
    do
    {
        printf("CT test1");
        printf("Nhan 1 de quay lai\n");
        scanf("%d", &key);
    } while (key!=1);
} */

int main(int argc, char const *argv[])
{
    int val;
    jmp_buf buffer;

    val = setjmp(buffer);       //return val = 0

    if(val != 0){
        printf("val != 0\n");
        exit(0);
    }

    printf("Test\n");
    longjmp(buffer, 1);         //gan gia tri 1 vao buffer
    // sau khi goi func nay con tro
    // chuong trinh se tro nguoc ve setjum
}
/* 
    Ứng dụng: sử dụng toàn cục
 */