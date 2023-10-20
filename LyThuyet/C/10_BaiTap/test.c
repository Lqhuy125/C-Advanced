#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
char str[] = "out on the hello im kencan";
char res[] = "";
void func(char *str, char *tex1, char  *text2){

    uint8_t j=0, i=0;

    //Tim vi tri dau tien va vi tri cuoi cung cua chuoi con cu
    while(str[0] != '\0'){
        if ( str[j] == tex1[i])
        {
            i++;
            if(tex1[i] == '\0') break;
        }
        else i=0;

        j++;
        
    }
    if(tex1[i] != '\0') printf("Khong co\n");

    uint8_t location_final = j;
    uint8_t location_first = j - i + 1;
    //printf("%d\n", location_final);
    uint8_t length_string = strlen(str);
    uint8_t length_update = length_string - strlen(tex1) + strlen(text2);

    //TH text 2 > text 1
    if(length_string < length_update){
        


    }
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
int main(int argc, char const *argv[])
{
    func(str, "on the", "and");
    printf("%s", str);
}
