#include <stdio.h>
#include <stdbool.h>
/* 
    Những trường hợp lặp sử dụng các vòng for lồng sử dụng thì sử dụn goto để thoát
    K cần sử dụng các biến check
    goto chỉ được sử dụng trong 1 hàm( local)
 */
int main(int argc, char const *argv[])
{
    printf("-----------------------------Cach 1: \n");
    int check = false;
    while (1)
    {
        for(int i = 0 ; i < 10; i++){
            for (int j = i + 1; j < 10; j++)
            {
                printf("i = %d j = %d\n", i, j);
                if(i == 3 && j == 5){
                    printf("i == 3 && j == 5\n");
                    check = true;
                    break;
                }
            }
            if (check == true)
            {
                break;
            }
        }
        if (check == true)
        {
            break;
        }
    }
    
    printf("-----------------------------Cach 2: \n");
    //Thay vì sử dụng nhiều biến check thì ta có thể sử dụng goto để làm đơn giản hoá
    while (1)
    {
        for(int i = 0 ; i < 10; i++){
            for (int j = i + 1; j < 10; j++)
            {
                printf("i = %d j = %d\n", i, j);
                if(i == 3 && j == 5){
                    printf("i == 3 && j == 5\n");
                    goto bottom;
                    break;
                }
            }
        }
    }
    bottom:

    return 0;
}
