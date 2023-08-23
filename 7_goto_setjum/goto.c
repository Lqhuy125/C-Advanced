#include <stdio.h>

/* 

 */
int main(int argc, char const *argv[])
{
    int key = 0;
    top:
    do
    {
        printf("Chuong trinh test\n");
        printf("Case 1: Content 1\n");
        printf("Case 2: Content 2\n");
        scanf("%d", &key);
    } while (key!=1 || key!=2);
    
    
    switch (key)
    {
        case 1:
            printf("Chuong trinh 1\n");
            goto top;
            break;
        case 2:
            printf("Chuong trinh 2\n");
            goto top;
            break;
        default:
            break;
    }
    return 0;
}
