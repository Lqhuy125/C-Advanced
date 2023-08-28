//Sau dau '.' viet In Hoa,
//Tim kiem doan van vd; "leaning out on" -> co, "Hello" -> khong co
//Tim va thay the: vd: "leaning out on" -> "hello world"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char str[] = "    i heard a man scream when he saw the little girl leaning out on the ledge. the little girl kept leaning more and more and climbed over the ledge, she held on only with two arms and her legs were in the air. day la dong test 1. day la dong test 2";

/* 
 *      @brief Cắt khoảng trắng đầu mỗi câu  
 */
void trim_SpaceOfStr(char *str) {
    int len = strlen(str);
    int i = 0;

    while (i < len) {
        if (isspace(str[i])) {
            i++;
        } else {
            break;
        }
    }
    //str,str+3, 6
    memmove(str, str + i, len - i + 1); //
}

/* 
 *      @brief Viết hoa chữ cái đầu sau mỗi dấu chấm câu
 */
void VietHoaChuCaiDau(char *arr){
    arr[0] = toupper(arr[0]);
    for(int i = 0; arr[i]!='\0'; i++){
        if(arr[i] == '.'){
            arr[i+2] = toupper(arr[i+2]);
            i+=2;
        }
    }
    
}
/* 
 *      @brief Tìm kiếm một đoạn trong str
 */
int find_arr(char *new_str, char *str){

    bool find = false;
    for(int i = 0; i < strlen(str) - strlen(new_str); i++){ //vd: chuỗi dài 10, chuỗi con dài 3 thì sẽ phải ktra từ vị trí 0 -> 7
        if(str[i] == new_str[0]){
            find = true;
            int j;
            for( j = 1; j < strlen(new_str)-1; j++){
                if(str[i+j] != new_str[j]){
                    find = false;
                    break;
                }
            }
            if(find==true){
                break;
            }
        }
    }
    if(find == true) return 1;
    else return 0;
}
/* 
 *      @brief Thay thế chuỗi con
 */
void find_and_change_str( char *str, char *oldSubstr, char *newSubstr){
    
    //Tao mot chuoi luu du lieu
    char result[1000];
    int i=0, j = 0, k = 0;
    //duyệt chuỗi gốc
    while(i < strlen(str)){
        int match = 1;

        //tìm kiếm vị trí của chuỗi con muốn thay đổi
        //Nếu k gắp thì sẽ coppy hết những đoạn mà không phải là chuỗi con vào chuỗi Result
        for(j = 0; j < strlen(oldSubstr); j++){
            if(str[i+j] != oldSubstr[j]){
                match = 0;
                break;
            }
        }
        //coppy vào Result những ký tự giống đang tìm để thay
        if(match){
            for(j = 0; j < strlen(newSubstr); j++){
                result[k++] = newSubstr[j];
            }
            //Sau khi ghi xong vào Result những ký tự giống, vị trí i trong Result sẽ nhảy lên Độ dài của chuỗi cũ
            i += strlen(oldSubstr);
        }
        //coppy vào Result những ký tự khác chuỗi đang tìm
        else{
            result[k++] = str[i++];
        }
        
    }
    for(i = 0; i <= k; i++){
        str[i] = result[i];
    }
}

int main(int argc, char const *argv[])
{
    //Cắt khoảng trống đầu câu
    trim_SpaceOfStr(str);

    //Viết hoa chữ cái đầu
    VietHoaChuCaiDau(str);
    printf("%s\n", str);

    //Tìm kiếm 1 đoạn
    if(find_arr("leaning out on", str) == 1) printf("Co\n");
    else printf("Khong co\n"); 

    //Tìm và thay thế 1 đoạn
    find_and_change_str(str, "leaning out on", "hello world");
    printf("%s\n", str);



    return 0;
}
