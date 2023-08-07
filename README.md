## PROGRAMMING C

<details>
<summary><h3>0. C basic<h3></summary>
 <ul>
 <details>
	 
<summary><h4> 0.1 Data Type <h4></summary>

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
  
</details>
<details>
<summary><h4> 0.2 Typedef <h4></summary>

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
</details>

<details>
<summary><h4> 0.3 C Control Statements <h4></summary>

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
  </details>
</details>

<details>
<summary><h3>1. Compiler<h3></summary>

  **Quá trình biên dịch:**

   Bắt đầu từ file ` *.c/ *.h ` ( được gọi là ***Source file***). Ex: main.c
   
   Sau khi qua quá trình tiền xử lý(***Preprocessor***), file ` *.c/ *.h ` chuyển thành file ` *.i ` ( được gọi là ***Preprocessed Sources***). Ex: main.i
   
   Sau đó chuyển sang quá trình ***Compiler*** sẽ biến file `*.i` thành file `*.s` ( được gọi là ***Assemply Code*** ). Ex: main.s
   
   Tiếp đến là quá trình ***Assembler*** sẽ biến file `*.s` thành file `*.o` (được gọi là ***Object files***). Ex. main.o
   
   Cuối cùng là quá trình ***Linker*** sẽ kết hợp file `*.o` và các Libraries lại với nhau tạo thành file `*.exe` (được gọi là ***Executable***). Ex. main.exe
   
**Note:**

* Trong quá trình ***Preprocessor*** để chuyển sang file `*.i`:
   - Những thư viện/ source con ` #include <*.c/ *.h>` sẽ được thay thế bằng các đoạn code đó vào file ` main `.
   - Các biến được sử dụng `#define` sẽ được thay vào đúng vị trí được sử dụng.
   - Các `Comment` sẽ được loại bỏ
   
 
</details>

 

