#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main()
{
    //malloc return void* => ep kieu
    uint16_t *ptr = (uint16_t*)malloc(sizeof(uint16_t)*5);
    // ---------------------------------^ = 10

    for (int i = 0; i < 5; i++)
    {
        ptr[i] = 2*i;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", ptr[i]);
    }

    //mang nay co the thay doi dc so luong cua mang
    // tang tu 5 len 6 o nho
    ptr = (uint16_t*)realloc(ptr, sizeof(uint16_t)*7);

    for (int i = 0; i < 7; i++)
    {
        ptr[i] = 3*i;
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d\n", ptr[i]);
    }
    return 0;
}
