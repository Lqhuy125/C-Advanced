#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

char string[] = "nam hoang bao, nam hoang hoang, bao bao yen, anh bao yen";

typedef struct{
    char *ptr;
    uint8_t length;
    uint8_t quality;        //Đếm số lượng xuất hiện của các phần tử trong mảng
    bool status;            //Lưu trạng thái của các biến đếm. Nếu giống nhau thì status=0 khác status =1 để hiển thị k bị trùng

}words;

words* splitstring( char *str, uint8_t size);
void mirrorName(words *string, int size);
int sizeString(char *str);
void findName(words *array, int size);
void printName(words *array, int size);
bool compare(const char *str1, const char *str2);
void sortAlphabet(words *array, int size);
 
int main() {
    char string[] = "nam hoang bao, nam hoang hoang, bao bao yen, anh bao yen";

    uint8_t size = sizeString(string);
    words *a = splitstring(string, size);

    // findName(a, 12);

    // printName(a, 12);
    
    //mirrorName(a, sizeStrg);

    sortAlphabet(a, size);
    
    free(a);
    return 0;
}

/* 
        @brief Đếm trong chuỗi có bao nhiêu từ
 */
int sizeString(char *str){
    uint8_t size = 1;
    while (*str!='\0')
    {
        if(*str == ' ') size++;
        str++;
    }
    return size;
}
/* 
        @brief Tách chuỗi thành các từ đơn và lưu vào mảng array = {words, words, ...} có kiểu dữ liệu là words
 */
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
        //Nếu chưa kết thúc chữ nào đấy thì con trỏ vẫn ++ lên và độ dài chữ đó vẫn được đếm lên
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

/* 
        @brief Đếm số lần xuất hiện của từng từ trong chuỗi

        Sử dụng biến status để đánh dấu những tên đã xuất hiện

        Hàm này cần phải gọi trước hàm printName() nếu muốn in số lần xuất hiện
 */
void findName(words *array, int size) {
    
    for(uint8_t i=0; i<size;i++){
        uint8_t count=0;
        for (uint8_t j = 0; j < size; j++)
        {
            uint8_t i_ptr=0;
            while(array[i].ptr[i_ptr] == array[j].ptr[i_ptr]){
                i_ptr++;
                
                if(array[i].length == i_ptr && array[j].length == i_ptr){
                    count++;
                    if (count>=2) array[j].status = false;
                    else array[j].status = true;
                    break;
                }
            }
        }
        array[i].quality = count;
    }
}

/* 
        @brief In ra danh sách các từ xuất hiện bao nhiêu lần sau khi đã lọc những từ trùng
 */
void printName(words *array, int size){
    for(uint8_t i=0; i<size; i++){
        if (array[i].status == true)
        {
            for (uint8_t j = 0; j < array[i].length; j++)
            {
                printf("%c", array[i].ptr[j]);
            }
            printf(": %d\n", array[i].quality);
        }
        
    }
}

/* 
        @brief Đảo ngược các từ trong chuỗi
*/
void mirrorName(words *string, int size){
    uint8_t i=size;
    while (--i)
    {
        for (uint8_t j = 0; j < string[i].length; j++)
        {
            printf("%c", string[i].ptr[j]);
        }
        printf(" ");

        if(i==1) printf("%.*s", string[0].length, string[0].ptr);
    }
}

/* 
    @brief Hàm so sánh giữa hai từ trong chuỗi
 */
bool compare(const char *str1, const char *str2){
    while (*str1 != ' ' && *str1 != ',')
    {
        if(*str1 > *str2) return true;
        else if(*str1 < *str2) return false;

        str1++;
        str2++;
    }
    return false;
}
/* 
    @brief Sắp xếp các từ trong chuỗi theo thứ tự bảng chữ cái
 */
void sortAlphabet(words *array, int size){
    for (uint8_t i = 0; i < size-1; i++)
    {
        words temp = array[i];
        uint8_t index = i;
        for (uint8_t j = i+1; j < size; j++)
        {
            if (compare(temp.ptr, array[j].ptr))
            {
                temp = array[j]; //vd temp = a[7]
                index = j;
            }
        }
        //swap
        array[index] = array[i];  //vd a[7] = a[0]
        array[i] = temp;          // vd a[0] = a[7]
    }

    for (uint8_t i = 0; i < size; i++)
    {
        for (uint8_t j = 0; j < array[i].length; j++)
        {
            printf("%c", array[i].ptr[j]);
        }
        printf(" ");
    }
    
    
}