#include <stdio.h>

int main(int argc, char const *argv[])
{
    //Khi chua sd nen khoi tao la NULL
    int *ptr = NULL;
    //OR Sau khi sd va k con dung den nua cung nen gan lai bang NULL 
    printf("Dia chi: %p", ptr);


    return 0;
}
