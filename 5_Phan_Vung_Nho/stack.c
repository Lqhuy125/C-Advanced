#include <stdio.h>

void func(int a, int b){
    int c = a + b;
    printf("%d\n", c);

    //Note
    const int i = 10;           // SE DUOC LUU TAI PHAN VUNG STACK 
                                // VI LA BIEN CUC BO MAC DU LA HANG SO  

}

int main(int argc, char const *argv[])
{
    func(1, 2);                 //a = 1(0x01) b=2(0x08)
                                //c = 3(0x12)

    //Dia chi se duoc giai phong 

    //goi thu ham func() lan 2
    func(2, 3);                 // co the a b c se k con la dia chi nhu goi func() lan 1               
    return 0;
}
