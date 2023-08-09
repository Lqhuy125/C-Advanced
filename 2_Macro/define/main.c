#include <stdio.h>

#define SIZE 5

#define SUM(a, b) (a + b)

#define TEST this is test

/*  */
#define CREATE_FUNC1(name, cmd)         \
    void name(){                        \
        printf("%s", (char*)cmd);       \
    }   

/* 
    Co the su dung ` # `. Sau ` # ` se la chuoi nen se khong can ` "" ` 
 */
#define CREATE_FUNC2(name, cmd)         \
    void name(){                        \
        printf("%s", (char*)#cmd);      \
    } 

#define CREATE_VARIABLE(name)           \
int     int__##name;                    \
double  double__##name;                 \
char    char__##name                    

#define VAR(...) __VA_ARGS__

CREATE_FUNC1(test1, "This is test 1\n");

CREATE_FUNC1(test2, "This is test 2\n");

CREATE_FUNC2(test3, This is test 1\n); 

CREATE_FUNC2(test4, This is test 2\n);


int main(int argc, char const *argv[])
{
    printf("Size: %d\n", SIZE);
    
    printf("Sum = %d\n", SUM(1, 2));

    test1();

    test2();

    test3();

    test4();

    CREATE_VARIABLE(var1);

    VAR(hello world)
    
    return 0;
}
