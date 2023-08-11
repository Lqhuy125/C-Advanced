#include <stdio.h>

void tong(int a, int b){
    printf("%d + %d = %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("%d - %d = %d\n", a, b, a-b);
}

int Tich(int a, int b){
    return a*b;
}

void TinhToan(int a, int b, void (*ptr)(int a, int b)){
    printf("Ham tinh toan:\n");
    ptr(a, b);
}

int main(int argc, char const *argv[])
{
     void (*ptr)(int, int);

    ptr = &tong;

    ptr(9,7);

    ptr = &hieu;

    ptr(9,7);

    int (*ptrTich)(int, int) = &Tich;

    printf("%d\n", ptrTich(5, 5)); 

    TinhToan(1, 2, &tong);

    TinhToan(3, 2, &hieu);

    void (*ptrTinhtoan)(int, int, void(*));
    ptrTinhtoan = &TinhToan;
    ptrTinhtoan(2, 4, tong);

    printf("Tich: %d\n", ((int (*)(int, int))Tich)(3, 6));

    ((void (*)(int, int, void(*)))TinhToan)(2, 4, tong);
    return 0;
}
