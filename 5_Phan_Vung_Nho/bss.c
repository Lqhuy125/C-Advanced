#include <stdio.h>

int glo_x = 0; //bien toan cuc khoi tao = 0

static int y1 = 0; //bien static toan cuc khoi tao bang 0

static int y2; //bien static toan cuc khong duoc khoi tao

void func(){
    static int y3 = 0; //bien static cuc bo khoi tao bang 0

    static int y4; //bien static cuc bo khong duoc khoi tao

}

int main(int argc, char const *argv[])
{
    printf("%d\n", glo_x);         
    glo_x = 9;                     // both Read/Write

    fun(); // y3 -> 0x01
    //Sau khi ket thuc chuong trinh thi dia chi 0x01 tra lai cho RAM  
    
    return 0;
}
