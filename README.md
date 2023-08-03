## PROGRAMMING C

<details>

<summary>1. C basic</summary>

### 1.1 Data Type
- Some common data types(in library **stdint.h**):

	| Data Type  | Size (bytes) | Range | 
  	|:-------:|:--------:|:--------:|
  	|int8|1 byte |-128 to 127|
	|uint8_t |1 byte |0 to 255|
	|int16_t |2 bytes |-32768 to 32767|
    |uint16_t|2 byte |0 to 65535|
    |int32_t |2 byte |-2147483648 to 2147483647|
    |uint32_t|4 bytes |0 to 4294967295|
    |int64_t |8 bytes |-9223372036854775808 to 9223372036854775807|
    |uint64_t|8 bytes |0 to 18446744073709551615|

### 1.2 Typedef
- Typedef được sử dụng để đặt tên mới cho kiểu dữ liệu.
#### Example:
```c
#include <stdio.h>
typedef int typeInt; //typeInt can be used in place of int
int main()
{
    typeInt a = 10;
    printf("%d ", a);
    return 0;
}
```
### 1.3 C Control Statements
- C if...else Statement
- Switch Statement in C
- C for Loop
- While and do...while loop in C
- Switch case (combine Enum)

  <details>
	<summary>Example</summary>

    ```c
    #include <stdio.h>
    typedef enum{
        THANG_MOT,
        THANG_HAI,
        THANG_BA,
        THANG_BON,
        
    } thang_t;
    
    int main(){
        thang_t thang;
        switch (thang)
        {
            case THANG_MOT:
            case THANG_BA:
                /* code */
                break;
            case THANG_HAI:
                /* code */
                break;
            case THANG_BON:
                /* code */
                break;
            default:
                printf("Error\n")
                break;
        }
    }
    ```
- Continue
- Break
###
