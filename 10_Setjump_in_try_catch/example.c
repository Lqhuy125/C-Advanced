#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;
int check;

double div(int a, int b){
    if(b==0){
        longjmp(buffer, 1);
    }
    return (double)a/b;

}

void string(char arr[], int length){
    if(length<=0){
        longjmp(buffer, 2);
    }
}

int main(int argc, char const *argv[])
{
    
    char arr[] = "hello";
    check = setjmp(buffer);

    if(check == 0){
        printf("%.2f\n", div(1,0));
        string(arr, 0);
    }
     if(check == 1){
        printf("Error 1\n");
    }
     if (check == 2)
    {
        printf("Error 2\n");
    }
    
    
    return 0;
}
