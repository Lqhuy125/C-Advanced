#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum{
    TRAM,
    CHUC,
    DONVI
} UNIT;
typedef enum{
    TY,
    TRIEU,
    NGHIN
} loai;
typedef enum{
    KHONG = '0',
    MOT = '1',
    HAI = '2',
    BA = '3',
    BON = '4',
    NAM = '5',
    SAU = '6',
    BAY = '7',
    TAM = '8',
    CHIN = '9',
} NUM;

uint8_t strlen(char *str);
void print_Number(char *number, char num, uint8_t i, uint8_t unit);
UNIT unit_for_index(uint8_t index);

int main()
{
    char number[] = "1000000100"; 

    uint8_t length = strlen(number);
    uint8_t count=0;
    
    for (uint8_t i = 0; i < length; i++)
    {
        if(number[length-i-1] == '0' && number[length-i-1]==number[length-(i+1)-1])
            count++;
        else break;
    }

    for (uint8_t i = 0; i < length; i++)
    {
        //TH tram ty
        if((count == 10 || count == 9 || count ==  8) && length%3==0 ){
            print_Number(number, number[i], i, unit_for_index(length - i - 1));
            if(i==2) break;
        }
        else if((count == 7 || count ==  6 || count == 5) && length%3==0 ){
            print_Number(number, number[i], i, unit_for_index(length - i - 1));
            if(i==5) break;
        }
        else if((count == 4 || count ==  3 || count == 2) && length%3==0 ){
            print_Number(number, number[i], i, unit_for_index(length - i - 1));
            if(i==8) break;
        }
        //TH chuc ty
        else if((count == 9 || count == 8) && length%3==2 ){
            print_Number(number, number[i], i, unit_for_index(length - i - 1));
            if(i==1) break;
        }
        else if((count == 7 || count == 6 || count == 5) && length%3==2 ){
            print_Number(number, number[i], i, unit_for_index(length - i - 1));
            if(i==4) break;
        }
        else if((count == 4 || count == 3 || count == 2) && length%3==2 ){
            print_Number(number, number[i], i, unit_for_index(length - i - 1));
            if(i==7) break;
        }
        //TH ty
        else if(count == 8 && length%3==1 ){
            print_Number(number, number[i], i, unit_for_index(length - i - 1));
            if(i==0) break;
        }
        else if((count == 7 || count == 6 || count == 5) && length%3==1 ){
            print_Number(number, number[i], i, unit_for_index(length - i - 1));
            if(i==3) break;
        }
        else if((count == 4 || count == 3 || count == 2) && length%3==1 ){
            print_Number(number, number[i], i, unit_for_index(length - i - 1));
            if(i==6) break;
        }
        else
            print_Number(number, number[i], i, unit_for_index(length - i - 1));

        //Chua xu ly duoc
        // while (number[i] != '0' || number[i+1] != '0' || number[i+2] != '0' )
        // {
        //     check = true;
        //     for(uint8_t j=i; j<i+3; j++){
        //         print_Number(number, number[j], j, unit_for_index(length - j - 1));
        //     }
        //     i+=3;
        //     if(i==12) break;
        // }
        // if (check==true)
        // {
        //     while (i)
        //     {
        //             print_Number(number, number[i], i, unit_for_index(length - i - 1));
        //         i++;
        //         if(i==12) break;
        //     }
        // }
    }
    printf("dong\n"); 
}
/* 
    @brief Xác định trăm chục dơn vị
 */
UNIT unit_for_index(uint8_t index){
    if(index % 3 == 2) return TRAM;
    else if(index % 3 == 1) return CHUC;
    else return DONVI;
}
/* 
    @brief Độ dài chuỗi
 */
uint8_t strlen(char *str){
    uint8_t length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
/* 
    @brief Đếm
*/
void print_Number(char *number, char num, uint8_t i, uint8_t unit){
    uint8_t location = strlen(number);
    switch (num)
    {
        case KHONG:
            if(unit == TRAM) printf("Khong ");
            else if(unit == CHUC && number[i+1] != '0') printf("le ");
            break;
        case MOT:
            if(unit == CHUC) printf("Muoif "); //Mười
            else if(unit == DONVI && number[i-1] != '1' && number[i-1] != '0' && ( number[i-1]==('2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'))) 
                printf("Mot' "); //Mốt
            else 
                printf("Mot. "); //Một
            break;
        case HAI:
            printf("Hai ");
            break;
        case BA:
            printf("Ba ");  
            break;
        case BON:
            if(unit == DONVI && number[i-1] != '1' && number[i-1] != '0') printf("Tu ");
            else printf("Bon ");  
            break; 
        case NAM:
            if(unit == DONVI && number[i-1] != '0') printf("Lam "); //Lăm
            else printf("Nam "); //Năm
            break;
        case SAU:
            printf("Sau ");
            break;
        case BAY:
            printf("Bay ");
            break;
        case TAM:
            printf("Tam ");
            break;
        case CHIN:
            printf("Chin ");
            break;  
        default:
            break;
    }

    if (unit == TRAM && num != '0')
        printf("tram ");

    if(unit == TRAM && num == '0' && number[i+1] != 0) 
        printf("tram ");

    if(unit == CHUC && num != '1' && num != '0') 
        printf("muoi ");

    if (unit == DONVI)
    {
        if(location - 1 - i == 3) printf("Nghin ");
        if(location - 1 - i == 6) printf("Trieu ");
        if(location - 1 - i == 9) printf("Ty ");
    }
}

