#include <stdio.h>

const int x = 10;           // x DUOC LUU PHAN VUNG TEXT TRONG RAM

int main(int argc, char const *argv[])
{
    x=10;                    //Error: - x la hang so nen k the thay doi
    printf("%d", x);         //       - PHAN VUNG TEXT CHI CO THE READ
    return 0;
}
