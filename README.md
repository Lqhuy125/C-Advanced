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
 <ul>
	 
  **Quá trình biên dịch:**
  
![alt text](https://media.geeksforgeeks.org/wp-content/uploads/20230404112946/Compilation-Process-in-C.png)
 	
   Bắt đầu từ file ` *.c/ *.h ` ( được gọi là ***Source file***). Ex: main.c
   
   Sau khi qua quá trình tiền xử lý(***Preprocessor***), file ` *.c/ *.h ` chuyển thành file ` *.i ` ( được gọi là ***Preprocessed Sources***). Ex: main.i
   ```c
gcc -E main.c -o main.i
 ```
   Sau đó chuyển sang quá trình ***Compiler*** sẽ biến file `*.i` thành file `*.s` ( được gọi là ***Assemply Code*** ). Ex: main.s
   ```c
gcc main.i -S -o main.s
 ```
   Tiếp đến là quá trình ***Assembler*** sẽ biến file `*.s` thành file `*.o` (được gọi là ***Object files***). Ex. main.o
   ```c
gcc -c main.s -o main.o
 ```
   
   Cuối cùng là quá trình ***Linker*** sẽ kết hợp file `*.o` và các Libraries lại với nhau tạo thành file `*.exe` (được gọi là ***Executable***). Ex. main.exe
   ```c
gcc main.o -o main
 ```
How to run file `main.exe` using cmd: ` ./main.exe ` or ` ./main `
</details>

<details>
<summary><h3>2. Macro <h3></summary>
 <ul>
<details>
<summary><h4> 2.1 #define <h4></summary>
<ul>
<details>
<summary><h4> 2.1.1 Expression <h4></summary>
	
**Example**:	
```c
#define SUM(a, b) (a + b)
```
</details>
<details>
<summary><h4> 2.1.2 CREATE FUNCTION <h4></summary>
	
**Example**:	
```c
#define CREATE_FUNC1(name, cmd)         \
    void name(){                        \
        printf("%s", (char*)cmd);       \
    } 
/* 
    Co the su dung ` # `. Sau ` # ` se la chuoi nen se khong can ` "" ` 
 */
#define CREATE_FUNC2(name, cmd)         \
    void name(){                        \
        printf("%s", (char*)#cmd);      \
    } 

CREATE_FUNC1(test1, "This is test 1\n");
CREATE_FUNC1(test2, "This is test 2\n");
CREATE_FUNC2(test3, This is test 1\n); 
CREATE_FUNC2(test4, This is test 2\n);

int main(){
    test1();
    test2();
    test3();
    test4();
}
```

</details>
<details>
<summary><h4> 2.1.3 CREATE VARIABLE <h4></summary>

**Example**:	
```c
    #define CREATE_VARIABLE(name)           \
    int     int__##name;                    \
    double  double__##name;                 \
    char    char__##name 

    CREATE_VARIABLE(var1);
```
Biến sẽ được khởi tạo thành: 
```c
int int__var1; double double__var1; char char__var1;
```

</details>
<details>
<summary><h4> 2.1.4 Variadic in C <h4></summary>
Reference Documents: https://www.geeksforgeeks.org/variadic-functions-in-c/	

**Example:**
```c
#define VAR(...) __VAR_ARGS__
int main(){
	VAR(hello world)
	VAR(int a, int b, int c);
}
```
Output:
``` 
hello world
int a, int b, int c;
```

</details>
</details>	

<details>	
<summary><h4> 2.2 #ifndef ... #endif <h4></summary>
ifndef: if not define
	
Thường được sử dụng để tránh việc define một tên nhiều lần

**Example:**
```c
#ifndef SIZE
/* 
    Neu SIZE chua duoc dinh nghia thi doan nay se duoc su dung 
 */
#define SIZE 5  

#endif
```
</details>

<details>
<summary><h4> 2.3 #if ... #elif... #else... #endif <h4></summary>

**Example:**
```c
#define SIZE 22

#if SIZE > 20
    void display(){
        printf("Size > 20\n");
    }
    
#elif SIZE == 20
    void display(){
        printf("Size = 20\n");
    }
#else SIZE < 20
    void display(){
        printf("Size < 20\n");
    }
#endif
```
</details>
  
 </details>

 

