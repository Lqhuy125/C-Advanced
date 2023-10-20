#include <stdio.h>
#include <stdarg.h>

/* 
    Ứng dụng: Khi không biết được đầu vào cụ thể
 */
int Sum(int num, ...){
    int sum = 0;
    va_list va;         //B1: Khoi tao 1 bien kieu va_list 
                        // va: la 1 con tro
                        //va_list chua thong tin ma va_start, va_stop,.... can 
    va_start(va, num);  //

    for(int i=0; i<num; i++){
        sum += va_arg(va, int); //va_arg() khi duoc goi se doc vi tri dau tien tai chỗ (...)
                                // Moi lan đọc hàm này nó sẽ di chuyển nhhư con trỏ
    }
    va_end(va);         //Giải phóng vùng nhớ của va

    return sum;
}

int main(int argc, char const *argv[])
{

    printf("sum = %d\n", Sum(2,1.1,2,3,4,5));

    return 0;
}
