//Sau dau '.' viet In Hoa,
//Tim kiem doan van vd; "leaning out on" -> co, "Hello" -> khong co
//Tim va thay the: vd: "leaning out on" -> "hello world"

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

char str[] = "a I heard a man scream when he saw the little girl leaning out on the ledge. the little girl kept leaning more and more and climbed over the ledge, she held on only with two arms and her legs were in the air. test 1. test 2";

int str_len(char *str);
void VietHoaChuCaiDau(char *arr);
int find_arr_C1(char *new_str, char *str);
int find_arr_c2(char *string, char *text);
void find_and_change_str( char *str, char *oldSubstr, char *newSubstr);

int main(int argc, char const *argv[])
{

    //Viết hoa chữ cái đầu
    // VietHoaChuCaiDau(str);
    // printf("%s\n", str);

    // printf("%d\n", str_len(str));

    //Tìm kiếm 1 đoạn
    printf("---------------------------------\n");
    char test1[] = "scream";
    // if(find_arr_c1(str, test1) == 1) printf("Co\n");
    // else printf("Khong co\n"); 
    //find_arr_c2(str, test1);

    //Tìm và thay thế 1 đoạn
    printf("---------------------------------\n");
    //find_and_change_str(str, "man scream", "how can i help you");
    find_and_replace_str_c2(str, "I heard", "the new words");


    return 0;
}
/* 
 *      @brief Tính độ dài chuỗi
 */
int str_len(char *str){
    uint8_t count = 0;
    while (*str!='\0')
    {
        count++;
        str++;
    }
    return count;
}
/* 
 *      @brief Cắt khoảng trắng đầu mỗi câu  
 */
// void trim_SpaceOfStr(char *str) {
//     int len = strlen(str);
//     int i = 0;

//     while (i < len) {
//         if (isspace(str[i])) {
//             i++;
//         } else {
//             break;
//         }
//     }
//     //str,str+3, 6
//     memmove(str, str + i, len - i + 1); //
// }

/* 
 *      @brief Viết hoa chữ cái đầu sau mỗi dấu chấm câu
 */
void VietHoaChuCaiDau(char *arr){
    // arr[0] = arr[0] - 32;
    // for(int i = 0; arr[i]!='\0'; i++){
    //     if(arr[i] == '.'){
    //         if(arr[i+1] == ' '){
    //             arr[i+2] = arr[i+2] - 32;
    //             i+=2;
    //         }
    //     }
    // }

    *arr = *arr - 32;
    while (*arr != '\0')
    {
        if(*arr == '.'){

            arr++;

            if (*arr == ' ') arr++;
            
            *arr = *arr - 32;
            
        }
        arr++;
    }
    
}
/* 
 *      @brief Tìm kiếm một đoạn trong str
 */
int find_arr_C1(char *str, char *new_str){

    /* 
     *   @brief  Using array
     */
    // bool find = false;
    // for(int i = 0; i < str_len(str) - str_len(new_str); i++){ //vd: chuỗi dài 10, chuỗi con dài 3 thì sẽ phải ktra từ vị trí 0 -> 7
    //     if(str[i] == new_str[0]){
    //         find = true;
    //         int j;
    //         for( j = 1; j < str_len(new_str)-1; j++){
    //             if(str[i+j] != new_str[j]){
    //                 find = false;
    //                 break;
    //             }
    //         }
    //         if(find==true){
    //             break;
    //         }
    //     }
    // }
    // if(find == true) return 1;
    // else return 0;

    /* 
     *   @brief  Using pointer 
     */
    bool find = false;
    uint8_t len_str = str_len(str);
    uint8_t len_new_str = str_len(new_str);
    for(uint8_t i = 0; i < len_str - len_new_str; i++ ){
        if(*str == *new_str){
            find = true;
            int count = 0;
            for (int j = 1; j < len_new_str; j++)
            {
                str++;
                new_str++;
                count++;
                if(*str != *new_str){
                    find = false;
                    new_str -= count;
                    break;
                }
            }
            if(find==true){
                break;
            } 
        }
        else str++;
    }

    if(find) return 1;
    else return 0;
}
int find_arr_c2(char *string, char *text){

    printf("Text: %s \n KetQua: ", text);

    uint8_t i = 0;
    uint8_t count = 0;

    while (*string != '\0')
    {
        if(*string == *text){
            text++;
            i++; //vi tri dau tien cua chuoi con trong chuoi bo
            if(*text == '\0'){
                uint8_t location = count - i + 1;
                printf("Co\nVi tri: %d\n", location);
                return; // kết thúc hàm luôn, break thì sẽ chỉ thoát ra vòng lặp
            }
        }
        else
            i = 0;

        string++;
        count++;
    }
    printf("Khong co");
}
/* 
 *      @brief Thay thế chuỗi con
 *      Sử dụng mảng khác lưu kết quả nên sẽ bị tốn bộ nhớ 
 */
void find_and_change_str(char *str, char *oldSubstr, char *newSubstr){
    
    //Tao mot chuoi luu du lieu
    char result[1000];
    int i=0, j = 0, k = 0;
    //duyệt chuỗi gốc
    while(i < str_len(str)){
        int match = 1;

        //Tìm kiếm vị trí của chuỗi con muốn thay đổi
        //Nếu k gặp thì sẽ coppy hết những đoạn mà không phải 
        //là chuỗi con vào chuỗi Result (1)
        for(j = 0; j < str_len(oldSubstr); j++){
            if(str[i+j] != oldSubstr[j]){
                match = 0;
                break;
            }
        }
        //coppy vào Result những ký tự giống đang tìm để thay
        if(match){
            for(j = 0; j < str_len(newSubstr); j++){
                result[k++] = newSubstr[j];
            }
            //Sau khi ghi xong vào Result những ký tự giống
            //vị trí i trong Result sẽ nhảy lên Độ dài = độ dài chuỗi cũ
            //Rồi sau đó tiếp tục lưu những đoạn còn lại vào Result tiếp
            i += str_len(oldSubstr);
        }
        // (1)coppy vào Result những ký tự khác chuỗi đang tìm
        else{
            result[k++] = str[i++];
        }
    }
    //Hiển thị chuỗi con mới
    for(i = 0; i <= k; i++){
        str[i] = result[i];
    }
}
void find_and_replace_str_c2(char *str, char *text1, char *text2){

    uint8_t j=0, i=0;

    //Tim vi tri dau tien va vi tri cuoi cung cua chuoi con cu
    while(str[0] != '\0'){
        if ( str[j] == text1[i])
        {
            i++;
            if(text1[i] == '\0') break;
        }
        else i=0;

        j++;
        
    }
    if(text1[i] != '\0') printf("Khong co\n");

    //Bắt đầu thay thế
    uint8_t location_final = j;
    uint8_t location_first = j - i + 1;
    uint8_t length_string = str_len(str);
    uint8_t length_update = length_string - str_len(text1) + str_len(text2);

    //TH text 2 > text 1
    if(length_string < length_update){

    }
    //Text2 < Text1
    else{
        while (*text2 != '\0')
        {
            str[location_first] = *text2;
            //printf("%c\n", str[location_first]);
            location_first++;
            text2++;
        }
        location_final++;
        while(location_first < length_update){
            str[location_first] = str[location_final];
            //printf("\n%c\n", str[location_first]);
            location_first++;
            location_final++;
        }
        str[length_update ] = '\0';
    }
}