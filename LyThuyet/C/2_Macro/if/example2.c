#include <stdio.h>

#define SIZE 22

#if SIZE > 20
    void display(){
        printf("Size > 20\n");
    }
    
#elif SIZE == 20
    void display(){
        printf("Size = 20\n");
    }
#else SIZE < 20
    void display(){
        printf("Size < 20\n");
    }
#endif


int main(int argc, char const *argv[])
{
    display();
    return 0;
}
