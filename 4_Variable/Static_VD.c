#include <stdio.h>
#include <stdbool.h>

void init(){
    //this is function init
}
void start(){
    // this is Start Function after Init MCU
}
void func(){ // used to call Init func only once
    static bool i = true;

    if(i == true){
        init();
        i = false;
    }
    else start();
}

int main(int argc, char const *argv[])
{
    func();
    func();
    func();
    return 0;
}
