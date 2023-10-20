
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct inversion_of_words_in_string
{
    char *ptr;
    uint8_t length;      
} words;

words* splitString( char *str, int size);
int sizeString(char *str);

int main(int argc, char const *argv[])
{
    char string[] = "nam hoang bao, nam hoang hoang, bao bao yen, anh bao yen";

    int size = sizeString(string);
    words *a = splitString(string, size);

    while (--size)
    {
        for (uint8_t j = 0; j < a[size].length; j++)
        {
            printf("%c", a[size].ptr[j]);
        }
        printf(" ");

        if(size==1) printf("%.*s", a[0].length, a[0].ptr);
    }
    
    return 0;
}
/* 
        @brief Xác định trong chuỗi có bao nhiêu từ
 */
int sizeString(char *str){
    int size = 1;
    while (*str != '\0') 
    {
       if(*str == ' ') size++;
       str++;
    }
    return size;
}
/* 
 *      @brief Cắt chuỗi thành các từ thành một array[] = {words, words, words, ...}
 */
words* splitString( char *str, int size){

    words *array = (words*)malloc(sizeof(words)*size);
    //malloc cấp phát bộ nhớ ở phân vùng nhớ heap sẽ k bị thu hồi

    uint8_t index=0;
    uint8_t count=0;

    array[index].ptr = str;

    while (*str != '\0')
    {
        if(*str == ' '){
            if(*(str-1) == ',' || *(str-1) == '.' ) count--;

            array[index].length = count;

            count = 0;

            str++;

            index++;

            array[index].ptr = str;
        }
        else{
            str++;
            count++;
        }
    }
    array[index].length = count;

    return array;
}