#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct date
{
    uint8_t day;
    uint8_t month;
    uint16_t year;
} Date;

typedef enum dayofweek{
    T2 = 0,
    T3 = 1,
    T4 = 2,
    T5 = 3,
    T6 = 4,
    T7 = 5,
    CN = 6

} DayofWeek;

Date date = {3, 1, 2000}; // Thứ 2
Date dateCurrent = {6, 9, 2023};

int isLeapYear(uint16_t year);
int DayinMonth(uint8_t month, uint16_t year);

int main(int argc, char const *argv[])
{
    uint16_t count=0;
    while(date.day != dateCurrent.day || date.month != dateCurrent.month || date.year != dateCurrent.year){
        count++;
        date.day++;

        if(date.day > DayinMonth(date.month, date.year)){
            date.day = 1;
            date.month++;
            if(date.month > 12){
                date.month=1;
                date.year++;
            }
        }
    }
    char *dayName[] = {"T2", "T3", "T4", "T5", "T6", "T7", "CN"};
    printf("%d: %s", count, dayName[count%7]);
    return 0;
}
/* 
 *      @brief Ngày trong tháng 
 */
int DayinMonth(uint8_t month, uint16_t year){

    uint8_t DayinMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if(isLeapYear(year)==true && month == 2) return 29;

    return DayinMonth[month];
}
/* 
 *      @brief Check Leap Year 
 */
int isLeapYear(uint16_t year){
    if(year % 400 == 0) return true;
    if(year % 4 == 0 && year % 100 != 0) return true;

    return false;
}
