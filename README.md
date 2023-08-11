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
## Example:
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
// # to inform that "#cmd" is a string 

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

    // \ used for Line break and the last one don't use
    // ## to connect two string 

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
#define VAR(...) __VA_ARGS__   //__VA_ARGS__ will be replaced by anything in (...)
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

<details>
<summary><h3>3. Pointer<h3></summary>
<ul>

***Pointer*** can be used to store memory address of variable, function and other pointer
<details>
<summary><h4>3.1 Pointer<h4></summary>
<ul>
	
**Syntax:**
```c
datatype * ptr;
```

**Example:**
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;

    int * ptr = &a;

    printf("Address of a: %p\n", &a); 			//Address of a: 000000b66e5ff6dc

    printf("Address of pointer: %p\n", &ptr); 		//Address of pointer: 000000b66e5ff6d0
    printf("Value of pointer: %p\n", ptr);		//Value of pointer: 000000b66e5ff6dc
    printf("Value of variable pointer: %d\n", *ptr);	//Value of variable pointer: 10

    return 0;
}
``` 
</details>

<details>
<summary><h4>3.2 NULL Pointer<h4></summary>
<ul>

- Khi khai báo một biến con trỏ cần gán cho nó một địa chỉ. Nếu chưa sử dụng thì nên gán địa chỉ NULL
- Khi sử dụng xong 1 biến con trỏ cũng nên gán trả lại NULL
  
=> Tránh việc con trỏ trỏ tới một địa chỉ ngẫu nhiên mà chương trình đang sử dụng gây sai lệnh or nhầm lẫn

**Syntax:**
```c
data_type *pointer_name = NULL;
        or
pointer_name = NULL
```
</details>
	
<details>
<summary><h4>3.3 Function Pointer<h4></summary>
<ul>
	
 **Syntax:**
```c
((func_data_type (*)(func_para_type_1, func_para_type_2, ...))name_func)(value_input, ...)
```
**Example:**
```c
#include <stdio.h>
void tong(int a, int b){
    printf("%d + %d = %d\n", a, b, a+b);
}
void hieu(int a, int b){
    printf("%d - %d = %d\n", a, b, a-b);
}
int Tich(int a, int b){
    return a*b;
}
void TinhToan(int a, int b, void (*ptr)(int a, int b)){
    printf("Ham tinh toan:\n");
    ptr(a, b);
}
int main(int argc, char const *argv[])
{
    /* void (*ptr)(int, int);
    ptr = &tong;
    ptr(9,7);
    ptr = &hieu;
    ptr(9,7);
    int (*ptrTich)(int, int) = &Tich;
    printf("%d\n", ptrTich(5, 5)); */
    TinhToan(1, 2, &tong);
    TinhToan(3, 2, &hieu);
    return 0;
}
```
</details>

<details>
<summary><h4>3.4 Void Pointer<h4></summary>
<ul>

 **Syntax:**
```c
void * pointer_name;
```
**Example:**
```c
#include <stdio.h>

int tong(int a, int b){
    return a+b;
}

int main(int argc, char const *argv[])
{
    void *ptr;
    int i = 10;
    double d = 1.1;
    char c = 'c';
    
    ptr = &i;
    printf("Dia chi: %p, Gia tri: %d\n", ptr, *(int *)ptr);

    ptr = &d;
    printf("Dia chi: %p, Gia tri: %f\n", ptr, *(double *)ptr);

    ptr = &c;
    printf("Dia chi: %p, Gia tri: %c\n", ptr, *(char *)ptr);

    ptr = &tong;
    printf("Dia chi: %p\n", ptr);
    printf("Gia tri: %d\n", ((int (*)(int, int))ptr)(1,2));
}
```
**Output:**
```
Dia chi: 000000ede39ffa64, Gia tri: 10
Dia chi: 000000ede39ffa58, Gia tri: 1.100000
Dia chi: 000000ede39ffa57, Gia tri: c
Dia chi: 00007ff6f4311591
Gia tri: 3
```

</details>

<details>
<summary><h4>3.5 Pointer to Pointer<h4></summary>
<ul>

**Example:**
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *ptr = &a;
    int **ptp = &ptr;

    printf("Addr of a: %p\n", &a);
    printf("Addr_ptr: %p Val_ptr: %p Val_var_ptr: %d\n", &ptr, ptr, *ptr);

    printf("Addr_ptr: %p Val_ptr: %p Val_var_ptr: %d", &ptp, ptp, **ptp);
    return 0;
}
```
**Output:**
```c
Addr of a: 000000b82e5ff66c
Addr_ptr: 000000b82e5ff660 Val_ptr: 000000b82e5ff66c Val_var_ptr: 10
Addr_ptp: 000000b82e5ff658 Val_ptp: 000000b82e5ff660 Val_var_ptp: 10
```
</details>
 
</details>
 

