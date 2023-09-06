#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

char string[] = "nam hoang bao, nam hoang hoang, bao bao yen, anh bao yen";

typedef struct{
    char *ptr;
    uint8_t length;
    uint8_t quality;
    bool status;

}words;

words* splitstring( char *str, uint8_t size){

    words *array = (words *)malloc(sizeof(words)*size);

    uint8_t index = 0;
    uint8_t count = 0;

    array[index].ptr = str;

    //Check chuỗi xem rỗng hay không
    while ( *str != '\0')
    {
        //Nếu vị trí con trỏ ở khoảng trắng ( kết thúc một chữ nào đấy)
        if(*str == ' '){
            //Nếu trước dấu cách là dấu phẩy thì số lượng ký tự của 1 từ phải trừ đi 1
            if(*(str-1) == ',') count--;

            //Sau khi kết thúc 1 chữ thì lưu độ dài của chuỗi đấy
            array[index].length = count;

            //Reset count để lưu độ dài của chữ tiếp theo
            count = 0;
            //Con trỏ sẽ di chuyển đến vị trí đầu tiên của chữ tiếp theo
            str++;
            //Vị trí của mảng array sẽ lên là 1 ( word thứ 0, 1, 2, ...)
            index++;
            //Lưu ký tự đầu tiên của chữ tiếp theo
            array[index].ptr = str;

        }   
        //Nếu chưa kết thúc chữ nào đấy thì con trỏ vẫn ++ lên
        else{
            str++;
            count++;
        }
    }
    //Lưu độ dài của chữ cuối cùng.
    //Vì sau khi gặp ký tự '\0' sẽ bị thoát while và chưa kịp lưu độ dài lần cuối cùng
    array[index].length = count;

    return array;
} 
int str_len(char *str){
    uint8_t count = 0;
    while (*str!='\0')
    {
        count++;
        str++;
    }
    return count;
}
int countName(words *wordsArray, int size, char *targetName) {
    int count = 0;
    int targetLength = str_len(targetName);
    
    for (int i = 0; i < size; i++) {
        if (wordsArray[i].length == targetLength && *(wordsArray[i].length,wordsArray[i].ptr)==*targetName) {
            count++;
        }
    }
    return count;
}

int main() {
    char string[] = "nam hoang bao, nam hoang hoang, bao bao yen, anh bao yen";
    words *a = splitstring(string, 12);

    char *targetName = "hoang"; // Tên bạn muốn đếm
    
    int nameCount = countName(a, 12, targetName);

    printf("%s %d\n", targetName, nameCount);
    
    free(a);
    return 0;
}
