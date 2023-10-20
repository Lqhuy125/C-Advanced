#include <stdio.h>

void func(){
    int y = 10;
    static int x = 10;
    printf("%d %d\n", y, x);
    x+=10;
}

int main(int argc, char const *argv[])
{
    func();
    func();
    func();
    return 0;
}
