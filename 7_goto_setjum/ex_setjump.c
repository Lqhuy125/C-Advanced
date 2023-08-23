/* 
    Hiển thị lên màn hình: (1)Chương trình Test
                           Nhấn 1: Test 1
                           Nhấn 2: Test 2
    Khi nhấn 1, chạy vào hàm con test1 để hiển thị 'this is test 1 
                                                    Nhan 1 de thoat'.
                            Sau khi thoát thì quay về màn hình (1) như trên
    Khi nhấn 2, hiển thị tương tự
 */

#include <stdio.h>
#include <setjmp.h>

int val;
jmp_buf buffer;

void test1(){
    int key=0;
    do
    {
        printf("Chuong trinh Test\n");
        printf("Nhan 1 de thoat\n");
        scanf("%d", &key);
    } while (key != 1);
    longjmp(buffer,1);
}

void test2(){
    int key=0;
    do
    {
        printf("Chuong trinh Test\n");
        printf("Nhan 2 de thoat\n");
        scanf("%d", &key);
    } while (key != 2);
    longjmp(buffer,1);
}
int main(int argc, char const *argv[])
{
    setjmp(buffer);
    int key=0;
    do
    {
        printf("Chuong trinh Test\n");
        printf("Nhan 1: Test 1\nNhan 2: Test 2\n");
        scanf("%d", &key);
    } while (key != 1 && key != 2); //true => loop      false =>exit
    
    switch (key)
    {
    case 1:
        test1();
        break;
    
    default:
        test2();
        break;
    }
    return 0;
}
